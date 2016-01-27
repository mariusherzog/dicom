#include "dimse_pm.hpp"

#include <memory>
#include <string>
#include <initializer_list>
#include <functional>
#include <iostream>

#include "network/upperlayer/upperlayer_properties.hpp"
#include "network/upperlayer/upperlayer.hpp"

#include "data/dataset/dataset_iterator.hpp"


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
   operations {},
   application_contexts {"1.2.840.10008.3.1.1.1"}
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
   using namespace dicom::data::dataset;
   p_data_tf* d = dynamic_cast<p_data_tf*>(da.get());
   assert(d != nullptr); // d == nullptr would imply that this function is bound
                         // to the wrong message type.

   for (const auto& c : d->command_set) {
      std::cout << c << std::flush;
   }

   dictionary_dyn dic {"/media/STORAGE/_files/Studium/Sem 5/Studienprojekt/dicom/dicom/commanddictionary.csv"};
   commandset_processor proc{dic};
   commandset_data b = proc.deserialize(d->command_set);
   /** @todo dataset deserialization */

   std::string SOP_UID;
   DIMSE_SERVICE_GROUP dsg;
   unsigned short message_id;
   for (auto e : dataset_iterator_adaptor(b)) {
      if (e.tag == elementfield::tag_type {0x0000, 0x0002}) {
         get_value_field<VR::UI>(e, SOP_UID);
      } else if (e.tag == elementfield::tag_type {0x0000, 0x0100}) {
         short unsigned dsgint;
         get_value_field<VR::US>(e, dsgint);
         dsg = static_cast<DIMSE_SERVICE_GROUP>(dsgint);
      } else if (e.tag == elementfield::tag_type {0x0000, 0x0110}) {
         get_value_field<VR::US>(e, message_id);
      }
   }

   response resp = this->operations.at(SOP_UID.c_str()).first(dsg, nullptr);

   auto data = assemble_response[resp.get_response_type()](resp, message_id);
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


static upperlayer::p_data_tf assemble_cecho_rsp(response r, int message_id)
{
   using namespace upperlayer;
   commandset_data cresp;
   cresp.insert(make_elementfield<VR::UL>(0x0000, 0x0000, 4, 62));
   cresp.insert(make_elementfield<VR::UI>(0x0000, 0x0002, 18, "1.2.840.10008.1.1"));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0100, 2, static_cast<unsigned short>(r.get_response_type())));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0120, 2, message_id));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0800, 2, 0x0101));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0900, 2, r.get_status()));


   dictionary_dyn dic {"/media/STORAGE/_files/Studium/Sem 5/Studienprojekt/dicom/dicom/commanddictionary.csv"};
   commandset_processor proc{dic};
   auto serdata = proc.serialize(cresp);


   p_data_tf presp;
   presp.command_set = serdata;
   presp.message_id = message_id;

   return presp;
}


std::map<data::dataset::DIMSE_SERVICE_GROUP
   , std::function<upperlayer::p_data_tf(response r, int m_id)>> dimse_pm::assemble_response
{
   {DIMSE_SERVICE_GROUP::C_ECHO_RSP, assemble_cecho_rsp}
};


}

}

}
