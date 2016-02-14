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
                   association_definition operations,
                   dictionary& dict):
   upperlayer_impl(sc),
   state {CONN_STATE::IDLE},
   connection_request {boost::none},
   connection_properties {boost::none},
   operations {operations},
   dict(dict),
   transfer_processors {  },
   logger {"dimse pm"}
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

   transfer_processors["1.2.840.10008.1.2"]
         = std::unique_ptr<transfer_processor> {new little_endian_implicit(dict)};
}

dimse_pm::~dimse_pm()
{
}

void dimse_pm::send_response(response r)
{
   using namespace upperlayer;
   using namespace util::log;
   BOOST_LOG_SEV(logger, info) << "User requested response";

   std::string sop_uid;
   for (auto e : dataset_iterator_adaptor(r.get_command())) {
      if (e.tag == elementfield::tag_type {0x0000, 0x0002}) {
         get_value_field<VR::UI>(e, sop_uid);
      }
   }

   BOOST_LOG_SEV(logger, debug) << "SOP UID: \t" << sop_uid << "\n" << r;

   auto pres_contexts = connection_request.get().pres_contexts;
   auto pres_context = std::find_if(pres_contexts.begin(), pres_contexts.end(),
                                    [sop_uid](upperlayer::a_associate_rq::presentation_context p) {
         return p.abstract_syntax == std::string {sop_uid.c_str()};
   });
   /** @todo check if presentation context was rejected */

   if (pres_context == pres_contexts.end()) {
      std::string errormsg {"No presentation context id found corresponding "
                            "to abstract syntax / SOP uid: " + sop_uid};
      BOOST_LOG_SEV(logger, warning) << errormsg;
      throw std::runtime_error(errormsg);
   }


   auto accepted = std::find_if(connection_properties.get().pres_contexts.begin(),
                connection_properties.get().pres_contexts.end(),
                [pres_context](upperlayer::a_associate_ac::presentation_context p) {
         return p.id == pres_context->id;
   });
   if (!(accepted->result_ == upperlayer::a_associate_ac::presentation_context::RESULT::ACCEPTANCE)) {
      std::string errormsg {"Sending data on rejected Presentation Context "
                            "with id" + std::to_string(accepted->id)};
      BOOST_LOG_SEV(logger, warning) << errormsg;
      throw std::runtime_error(errormsg);
   }

   auto data = assemble_response[r.get_response_type()](r, pres_context->id, dict);
   upperlayer_impl.queue_for_write(std::unique_ptr<property>(new p_data_tf {data}));
}

void dimse_pm::abort_association()
{
   using namespace upperlayer;
   using namespace util::log;
   BOOST_LOG_SEV(logger, info) << "User requested association abortion";
   upperlayer_impl.queue_for_write(std::unique_ptr<property>(new a_abort {}));
}

void dimse_pm::release_association()
{
   using namespace upperlayer;
   using namespace util::log;
   BOOST_LOG_SEV(logger, info) << "User requested association release";
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

   if (operations.get_initial_request().application_context != arq->application_context) {
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

      if (!operations.get_SOP_class(pc.abstract_syntax).empty()) {

         bool have_common_ts = false;
         auto pres_cont = operations.get_SOP_class(pc.abstract_syntax)[0];
         auto transfer_syntaxes = pres_cont.transfer_syntaxes;
         for (const auto ts : transfer_syntaxes) {
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
   connection_request = *arq;
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

//         operations.erase(rej_abstract_syntax);
      }
   }

   connection_properties = *asc;
   state = CONN_STATE::CONNECTED;


   for (auto sop : operations.get_all_SOP()) {
      if (sop.msg_type == dimse::association_definition::DIMSE_MSG_TYPE::INITIATOR) {
         auto request = sop.sop_class;
         for (auto sg : request.get_service_groups()) {
            commandset_data header;
            header.insert(make_elementfield<VR::UI>(0x0000, 0x0002, 18, request.get_SOP_class_UID()));
            header.insert(make_elementfield<VR::US>(0x0000, 0x0120, 2, next_message_id()));
            request(this, sg, header, nullptr);
         }
      }
   }
}

void dimse_pm::data_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> da)
{
   using namespace upperlayer;
   using namespace dicom::util::log;
   using namespace dicom::data::dataset;
   p_data_tf* d = dynamic_cast<p_data_tf*>(da.get());
   assert(d != nullptr); // d == nullptr would imply that this function is bound
                         // to the wrong message type.

   BOOST_LOG_SEV(logger, info) << "Received response from remote";

   commandset_processor proc {dict};
   commandset_data b = proc.deserialize(d->command_set);

   iod dataset;
   if (!d->data_set.empty()) {
      auto& tfproc = find_transfer_processor();
      dataset = tfproc.deserialize(d->data_set);
   }

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
      } else if (e.tag == elementfield::tag_type {0x0000, 0x0120}) {
         get_value_field<VR::US>(e, message_id);
      }
   }

   BOOST_LOG_SEV(logger, debug) << "SOP UID: \t" << SOP_UID << "\n"
                                << "Service Group: \t" << dsg << "\n"
                                << "Message ID: \t" << std::to_string(message_id) << "\n";

   auto pcontexts = operations.get_SOP_class(SOP_UID);
   for (auto pc : pcontexts) {
      if (pc.msg_type == association_definition::DIMSE_MSG_TYPE::RESPONSE) {
         auto request = pc.sop_class;
         auto sop_service_groups = request.get_service_groups();
         if (sop_service_groups.find(dsg) != sop_service_groups.end()) {
            request(this, dsg, std::move(b),
                    d->data_set.empty()
                    ? nullptr
                    : std::unique_ptr<iod> {new iod {std::move(dataset)}});
         }
      }
   }
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

transfer_processor& dimse_pm::find_transfer_processor()
{
   using kvpair = std::pair<const std::string, std::unique_ptr<data::dataset::transfer_processor>>;
   return *(std::find_if(transfer_processors.begin(), transfer_processors.end(),
                       [this](kvpair& kv) {
      auto pres_contexts = connection_properties.get().pres_contexts;
      std::string transfer_syntax = kv.first;
      return std::find_if(pres_contexts.begin(), pres_contexts.end(),
                          [transfer_syntax](upperlayer::a_associate_ac::presentation_context pc)
      {
         return pc.result_
               == upperlayer::a_associate_ac::presentation_context::RESULT::ACCEPTANCE
               && pc.transfer_syntax
               == transfer_syntax;
      }) != pres_contexts.end();
   })->second);
}


static upperlayer::p_data_tf assemble_cecho_rsp(response r, int pres_context_id, dictionary& dict)
{
   using namespace upperlayer;
   commandset_data cresp;
   cresp.insert(make_elementfield<VR::UL>(0x0000, 0x0000, 4, 62));

   std::string SOP_uid;
   unsigned short message_id;
   for (const elementfield e : dataset_iterator_adaptor(r.get_command())) {
      if (e.tag.element_id == 0x0002 && e.tag.group_id == 0x0000) {
         get_value_field<VR::UI>(e, SOP_uid);
      } else if (e.tag.element_id == 0x0110 && e.tag.group_id == 0x0000) {
         get_value_field<VR::US>(e, message_id);
      }
   }
   cresp.insert(make_elementfield<VR::UI>(0x0000, 0x0002, 18, SOP_uid));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0100, 2, static_cast<unsigned short>(r.get_response_type())));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0120, 2, message_id));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0800, 2, 0x0101));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0900, 2, r.get_status()));

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;

   return presp;
}

static upperlayer::p_data_tf assemble_cecho_rq(response r, int pres_context_id, dictionary& dict)
{
   using namespace upperlayer;
   commandset_data cresp;

   std::string SOP_uid;
   unsigned short message_id;
   for (const elementfield e : dataset_iterator_adaptor(r.get_command())) {
      if (e.tag.group_id == 0x0000 && e.tag.element_id == 0x0002) {
         get_value_field<VR::UI>(e, SOP_uid);
      } else if (e.tag.element_id == 0x0120 && e.tag.group_id == 0x0000) {
         get_value_field<VR::US>(e, message_id);
      }
   }
   cresp.insert(make_elementfield<VR::UL>(0x0000, 0x0000, 4, 62));
   cresp.insert(make_elementfield<VR::UI>(0x0000, 0x0002, 18, SOP_uid));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0100, 2, static_cast<unsigned short>(r.get_response_type())));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0110, 2, message_id));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0800, 2, 0x0101));
   cresp.insert(make_elementfield<VR::US>(0x0000, 0x0900, 2, r.get_status()));

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;

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
