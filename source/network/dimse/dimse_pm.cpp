#include "dimse_pm.hpp"

#include <memory>
#include <string>
#include <initializer_list>
#include <functional>
#include <iostream>

#include "network/upperlayer/upperlayer_properties.hpp"
#include "network/upperlayer/upperlayer.hpp"


namespace dicom
{

namespace network
{

namespace dimse
{

using namespace data::attribute;
using namespace data::dictionary;
using namespace data::dataset;

dimse_pm::dimse_pm(upperlayer::Iupperlayer_comm_ops& sc, std::vector<std::pair<SOP_class, std::vector<std::string>>> operations_):
   state {CONN_STATE::IDLE},
   connection_properties {boost::none},
   application_contexts {"1.2.840.10008.3.1.1.1"},
   operations {}
{
   using namespace std::placeholders;
   sc.inject(upperlayer::TYPE::A_ASSOCIATE_RQ,
             std::bind(&dimse_pm::association_rq_handler, this, _1, _2));
   sc.inject(upperlayer::TYPE::P_DATA_TF,
             std::bind(&dimse_pm::data_handler, this, _1, _2));
   sc.inject(upperlayer::TYPE::A_RELEASE_RQ,
             std::bind(&dimse_pm::release_rq_handler, this, _1, _2));

   for (const auto op_and_ts : operations_) {
      this->operations.insert({op_and_ts.first.get_SOP_class_UID(), op_and_ts});
   }
}

dimse_pm::~dimse_pm()
{
}

void dimse_pm::association_rq_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> rq)
{
   using namespace upperlayer;
   a_associate_rq* arq = dynamic_cast<a_associate_rq*>(rq.get());
   assert(arq);

   using RESULT = a_associate_ac::presentation_context::RESULT;
   a_associate_ac ac;

   ac.called_ae = arq->called_ae;
   ac.calling_ae = arq->calling_ae;

   ac.application_context = arq->application_context;

   if (std::find(application_contexts.begin(), application_contexts.end(), arq->application_context)
       == application_contexts.end()) {
      a_associate_rj rj;
      rj.reason_ = a_associate_rj::REASON::APPL_CONT_NOT_SUPP;
      sc->queue_for_write(std::unique_ptr<property>(new a_associate_rj {rj}));
      state = CONN_STATE::IDLE;
      BOOST_LOG_TRIVIAL(error) << "Could not negotiate application context!";
      return;
   }

   // check the support of each presentation context and populate own a_associate_ac
   // accordingly
   for (const auto pc : arq->pres_contexts) {

      auto as_pos = operations.end();
      if ((as_pos = operations.find(pc.abstract_syntax)) != operations.end()) {

         bool have_common_ts = false;
         auto transfer_syntaxes = as_pos->second.second;
         for (const auto ts : pc.transfer_syntaxes) {
            if (std::find(transfer_syntaxes.begin(), transfer_syntaxes.end(), ts)
                != transfer_syntaxes.end()) {
               ac.pres_contexts.push_back({pc.id, RESULT::ACCEPTANCE, ts});
               have_common_ts = true;
               break;
            }
         }
         if (!have_common_ts) {
            ac.pres_contexts.push_back({pc.id, RESULT::TRANSF_SYNT_NOT_SUPP, pc.abstract_syntax});
            BOOST_LOG_TRIVIAL(debug) << "No common transfer syntax for presentation context with id " << pc.id << "\n";
         }

      } else {
         ac.pres_contexts.push_back({pc.id, RESULT::ABSTR_CONT_NOT_SUPP, pc.abstract_syntax});
      }

   }
   ac.max_message_length = 0xFFFE;

   sc->queue_for_write(std::unique_ptr<property>(new a_associate_ac {ac}));
   connection_properties = ac;
   state = CONN_STATE::CONNECTED;
}

void dimse_pm::data_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> da)
{
   // mock
   using namespace upperlayer;
   p_data_tf* d = dynamic_cast<p_data_tf*>(da.get());

   for (const auto& c : d->command_set) {
      std::cout << c << std::flush;
   }

   std::vector<unsigned char> echo_rsp {
      0x04, 0x00, 0x00, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00, 0x50, 0x01, 0x03,
      0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00,
      0x12, 0x00, 0x00, 0x00, 0x31, 0x2E, 0x32, 0x2E, 0x38, 0x34, 0x30, 0x2E, 0x31, 0x30, 0x30, 0x30,
      0x38, 0x2E, 0x31, 0x2E, 0x31, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x30, 0x80,
      0x00, 0x00, 0x20, 0x01, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x08, 0x02, 0x00,
      0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x09, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
   };

   dictionary_dyn dic {"/media/STORAGE/_files/Studium/Sem 5/Studienprojekt/dicom/dicom/commanddictionary.txt"};
   commandset_processor proc{dic};
   commandset_data b = proc.deserialize(d->command_set);

   std::string SOP_UID;
   DIMSE_SERVICE_GROUP dsg;
   for (elementfield e : b) {
      if (e.tag == elementfield::tag_type {0x0000, 0x0002}) {
         get_value_field<VR::UI>(e, SOP_UID);
      } else if (e.tag == elementfield::tag_type {0x0000, 0x0100}) {
         short unsigned dsgint;
         get_value_field<VR::US>(e, dsgint);
         dsg = static_cast<DIMSE_SERVICE_GROUP>(dsgint);
      }
   }

   commandset_data resp;
   resp.insert(make_elementfield<VR::UL>(0x0000, 0x0000, 4, 0x38));
   resp.insert(make_elementfield<VR::UI>(0x0000, 0x0002, 18, "1.2.840.10008.1.1"));
   resp.insert(make_elementfield<VR::US>(0x0000, 0x0100, 2, static_cast<unsigned short>(DIMSE_SERVICE_GROUP::C_ECHO_RSP)));
   resp.insert(make_elementfield<VR::US>(0x0000, 0x0120, 2, d->message_id));
   resp.insert(make_elementfield<VR::US>(0x0000, 0x0800, 2, 0x0101));
   resp.insert(make_elementfield<VR::US>(0x0000, 0x0900, 2, STATUS{0x0000}));

   std::vector<unsigned char> echo_rsp_preamble {
      0x04, 0x00, 0x00, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00, 0x50, 0x01, 0x03
   };

   std::cout << "####\n";
   auto boog = proc.serialize(resp);
   boog.insert(boog.begin(), echo_rsp_preamble.begin(), echo_rsp_preamble.end());
   for (const auto e : boog) {
      std::cout << std::to_string(e) << " ";
   }

   this->operations.at(SOP_UID.c_str()).first(dsg, nullptr);

   p_data_tf data;
   data.from_pdu(boog);

   sc->queue_for_write(std::unique_ptr<property>(new p_data_tf {data}));
}

void dimse_pm::release_rq_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property>)
{
   sc->queue_for_write(std::unique_ptr<upperlayer::property>(new upperlayer::a_release_rp));
   state = CONN_STATE::IDLE;
   connection_properties = boost::none;
}

void dimse_pm::abort_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> r)
{
}

std::string dimse_pm::trans_synt_from_mid(unsigned char cid)
{
   using namespace upperlayer;
   auto ac = connection_properties.get();
   auto pos = std::find_if(ac.pres_contexts.begin(), ac.pres_contexts.end(),
      [cid](const a_associate_ac::presentation_context& pc) -> bool {
         return pc.id == cid
            && pc.result_ == a_associate_ac::presentation_context::RESULT::ACCEPTANCE;
   });
   // The context id not being found or not accepted would imply an error in the protocol
   // implementation, as that data package must not have been received in the first place.
   assert(pos != ac.pres_contexts.end());
   return pos->transfer_syntax;
}


}

}

}
