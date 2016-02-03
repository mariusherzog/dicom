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

dimse_pm::dimse_pm(upperlayer::Iupperlayer_comm_ops& sc,
                   std::vector<std::pair<SOP_class, std::vector<std::string>>> operations_,
                   std::pair<SOP_class_request, std::string> request,
                   dictionary& dict):
   upperlayer_impl(sc),
   initial_request {request},
   state {CONN_STATE::IDLE},
   connection_request {boost::none},
   connection_properties {boost::none},
   operations {},
   application_contexts {"1.2.840.10008.3.1.1.1"},
   dict(dict)
{
   using namespace std::placeholders;
   sc.inject(upperlayer::TYPE::A_ASSOCIATE_AC,
             std::bind(&dimse_pm::association_ac_handler, this, _1, _2));
   sc.inject(upperlayer::TYPE::A_ASSOCIATE_RQ,
             std::bind(&dimse_pm::association_rq_handler, this, _1, _2));
   sc.inject(upperlayer::TYPE::P_DATA_TF,
             std::bind(&dimse_pm::data_handler, this, _1, _2));
   sc.inject(upperlayer::TYPE::A_RELEASE_RQ,
             std::bind(&dimse_pm::release_rq_handler, this, _1, _2));
   sc.inject(upperlayer::TYPE::A_RELEASE_RP,
             std::bind(&dimse_pm::release_rp_handler, this, _1, _2));

   sc.inject_conf(upperlayer::TYPE::A_ASSOCIATE_RQ,
             std::bind(&dimse_pm::sent_release_rq, this, _1, _2));

   for (const auto op_and_ts : operations_) {
      this->operations.insert({op_and_ts.first.get_SOP_class_UID(), op_and_ts});
   }
}

dimse_pm::~dimse_pm()
{
}

void dimse_pm::send_response(response r)
{
   using namespace upperlayer;

   unsigned short message_id;
   for (auto e : dataset_iterator_adaptor(r.get_command())) {
      if (e.tag == elementfield::tag_type {0x0000, 0x0110}) {
         get_value_field<VR::US>(e, message_id);
      }
   }

   auto data = assemble_response[r.get_response_type()](r, message_id, dict);
   upperlayer_impl.queue_for_write(std::unique_ptr<property>(new p_data_tf {data}));
}

void dimse_pm::send_request(response r)
{
   using namespace upperlayer;

   unsigned short message_id;
   for (auto e : dataset_iterator_adaptor(r.get_command())) {
      if (e.tag == elementfield::tag_type {0x0000, 0x0120}) {
         get_value_field<VR::US>(e, message_id);
      }
   }

   auto data = assemble_response[r.get_response_type()](r, message_id, dict);
   upperlayer_impl.queue_for_write(std::unique_ptr<property>(new p_data_tf {data}));
}

void dimse_pm::abort_association()
{
   using namespace upperlayer;
   upperlayer_impl.queue_for_write(std::unique_ptr<property>(new a_abort {}));
}

void dimse_pm::release_association()
{
   using namespace upperlayer;
   upperlayer_impl.queue_for_write(std::unique_ptr<property>(new a_release_rq {}));
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

void dimse_pm::association_ac_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> ac)
{
   using namespace upperlayer;
   a_associate_ac* asc = dynamic_cast<a_associate_ac*>(ac.get());
   assert(asc);
   assert(connection_request.is_initialized());


   a_associate_rq& crq = connection_request.get();
   for (const a_associate_ac::presentation_context pc : asc->pres_contexts) {
      if (pc.result_ != a_associate_ac::presentation_context::RESULT::ACCEPTANCE) {
         auto rqit = crq.pres_contexts.begin();
         for (; rqit->id != pc.id; rqit++) ;
         std::string rej_abstract_syntax = rqit->abstract_syntax;

         operations.erase(rej_abstract_syntax);
      }
   }

   connection_properties = *asc;

   /** @todo dataset */

//   auto resp = this->operations.at(initial_request.first.get_SOP_class_UID())
//         .first(initial_request.first.SOP_class, nullptr);
   auto resp = initial_request.first();

   auto data = assemble_response[resp.get_response_type()](resp, next_message_id(), dict);
   sc->queue_for_write(std::unique_ptr<property>(new p_data_tf {data}));
}

void dimse_pm::data_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> da)
{
   using namespace upperlayer;
   using namespace dicom::data::dataset;
   p_data_tf* d = dynamic_cast<p_data_tf*>(da.get());
   assert(d != nullptr); // d == nullptr would imply that this function is bound
                         // to the wrong message type.


   commandset_processor proc {dict.get_dyn_commanddic()};
   commandset_data b = proc.deserialize(d->command_set);
   /** @todo dataset deserialization (use first accepted ts) */

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

   this->operations.at(SOP_UID.c_str()).first(this, dsg, std::move(b), nullptr);
}

void dimse_pm::release_rq_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property>)
{
   sc->queue_for_write(std::unique_ptr<upperlayer::property>(new upperlayer::a_release_rp));
   state = CONN_STATE::IDLE;
   connection_properties = boost::none;
}

void dimse_pm::release_rp_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> r)
{
}

void dimse_pm::abort_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> r)
{
}

void dimse_pm::sent_release_rq(upperlayer::scx* sc, upperlayer::property* r)
{
   upperlayer::a_associate_rq* rq = dynamic_cast<upperlayer::a_associate_rq*>(r);
   assert(rq != nullptr);
   connection_request = *rq;
}

int dimse_pm::next_message_id()
{
   static int mid = 1;
   return mid++;
}


static upperlayer::p_data_tf assemble_cecho_rsp(response r, int message_id, dictionary& dict)
{
   using namespace upperlayer;
   commandset_data cresp;
   cresp.insert(make_elementfield<VR::UL>(0x0000, 0x0000, 4, 62));
   cresp.insert(make_elementfield<VR::UI>(0x0000, 0x0002, 18, "1.2.840.10008.1.1"));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0100, 2, static_cast<unsigned short>(r.get_response_type())));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0120, 2, message_id));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0800, 2, 0x0101));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0900, 2, r.get_status()));

   commandset_processor proc{dict.get_dyn_commanddic()};
   auto serdata = proc.serialize(cresp);


   p_data_tf presp;
   presp.command_set = serdata;
   presp.message_id = message_id;

   return presp;
}

static upperlayer::p_data_tf assemble_cecho_rq(response r, int message_id, dictionary& dict)
{
   using namespace upperlayer;
   commandset_data cresp;
   cresp.insert(make_elementfield<VR::UL>(0x0000, 0x0000, 4, 62));
   cresp.insert(make_elementfield<VR::UI>(0x0000, 0x0002, 18, "1.2.840.10008.1.1"));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0100, 2, static_cast<unsigned short>(r.get_response_type())));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0110, 2, message_id));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0800, 2, 0x0101));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0900, 2, r.get_status()));

   commandset_processor proc{dict.get_dyn_commanddic()};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.message_id = message_id;

   return presp;
}


std::map<data::dataset::DIMSE_SERVICE_GROUP
   , std::function<upperlayer::p_data_tf(response r, int message_id, dictionary&)>> dimse_pm::assemble_response
{
   {DIMSE_SERVICE_GROUP::C_ECHO_RQ, assemble_cecho_rq},
   {DIMSE_SERVICE_GROUP::C_ECHO_RSP, assemble_cecho_rsp}
};


}

}

}
