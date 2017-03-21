#include "dimse_pm.hpp"

#include <memory>
#include <string>
#include <initializer_list>
#include <functional>
#include <iostream>
#include <numeric>

#include "network/upperlayer/upperlayer_properties.hpp"
#include "network/upperlayer/upperlayer.hpp"

#include "data/dataset/datasets.hpp"
#include "data/dataset/dataset_iterator.hpp"

#include "data/attribute/constants.hpp"


namespace dicom
{

namespace network
{

namespace dimse
{

using namespace data::attribute;
using namespace data::dictionary;
using namespace data::dataset;

dimse_pm_manager::dimse_pm_manager(upperlayer::Iupperlayer_connection_handlers& conn,
                                   association_definition operations,
                                   dictionary& dict):
   operations {operations},
   dict {dict}
{
   conn.new_connection([&](upperlayer::Iupperlayer_comm_ops* scx) {this->create_dimse(scx);});
   conn.end_connection([&](upperlayer::Iupperlayer_comm_ops* scx) {this->remove_dimse(scx);});
}

void dimse_pm_manager::create_dimse(upperlayer::Iupperlayer_comm_ops* scx)
{
   protocol_machines[scx] =
         (std::unique_ptr<dimse_pm> {new dimse_pm {*scx, operations, dict} });
}

void dimse_pm_manager::remove_dimse(upperlayer::Iupperlayer_comm_ops* scx)
{
   protocol_machines.erase(scx);
}


dimse_pm::dimse_pm(upperlayer::Iupperlayer_comm_ops& sc,
                   association_definition operations,
                   dictionary& dict):
   upperlayer_impl(sc),
   state {CONN_STATE::IDLE},
   connection_request {boost::none},
   connection_properties {boost::none},
   operations {operations},
   max_remote_msg_length {0},
   assemble_response { {DIMSE_SERVICE_GROUP::C_ECHO_RQ,   &dimse_pm::assemble_cecho_rq},
                       {DIMSE_SERVICE_GROUP::C_ECHO_RSP,  &dimse_pm::assemble_cecho_rsp},
                       {DIMSE_SERVICE_GROUP::C_FIND_RQ,   &dimse_pm::assemble_cfind_rq},
                       {DIMSE_SERVICE_GROUP::C_FIND_RSP,  &dimse_pm::assemble_cfind_rsp},
                       {DIMSE_SERVICE_GROUP::C_STORE_RQ,  &dimse_pm::assemble_cstore_rq},
                       {DIMSE_SERVICE_GROUP::C_STORE_RSP, &dimse_pm::assemble_cstore_rsp},
                       {DIMSE_SERVICE_GROUP::C_MOVE_RQ,   &dimse_pm::assemble_cmove_rq},
                       {DIMSE_SERVICE_GROUP::C_MOVE_RSP,  &dimse_pm::assemble_cmove_rsp},
                       {DIMSE_SERVICE_GROUP::C_GET_RQ,    &dimse_pm::assemble_cget_rq},
                       {DIMSE_SERVICE_GROUP::C_GET_RSP,   &dimse_pm::assemble_cget_rsp},
                       {DIMSE_SERVICE_GROUP::N_EVENT_REPORT_RQ,    &dimse_pm::assemble_neventreport_rq},
                       {DIMSE_SERVICE_GROUP::N_EVENT_REPORT_RSP,   &dimse_pm::assemble_neventreport_rsp},
                       {DIMSE_SERVICE_GROUP::N_GET_RQ,    &dimse_pm::assemble_nget_rq},
                       {DIMSE_SERVICE_GROUP::N_GET_RSP,   &dimse_pm::assemble_nget_rsp},
                       {DIMSE_SERVICE_GROUP::N_SET_RQ,    &dimse_pm::assemble_nset_rq},
                       {DIMSE_SERVICE_GROUP::N_SET_RSP,   &dimse_pm::assemble_nset_rsp},
                       {DIMSE_SERVICE_GROUP::N_ACTION_RQ,    &dimse_pm::assemble_naction_rq},
                       {DIMSE_SERVICE_GROUP::N_ACTION_RSP,   &dimse_pm::assemble_naction_rsp},
                       {DIMSE_SERVICE_GROUP::N_CREATE_RQ,    &dimse_pm::assemble_ncreate_rq},
                       {DIMSE_SERVICE_GROUP::N_CREATE_RSP,   &dimse_pm::assemble_ncreate_rsp},
                       {DIMSE_SERVICE_GROUP::N_DELETE_RQ,    &dimse_pm::assemble_ndelete_rq},
                       {DIMSE_SERVICE_GROUP::N_DELETE_RSP,   &dimse_pm::assemble_ndelete_rsp}
                     },
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
   sc.inject(upperlayer::TYPE::A_ABORT,
             std::bind(&dimse_pm::abort_handler, this, _1, _2));


   sc.inject_conf(upperlayer::TYPE::A_ASSOCIATE_AC,
             std::bind(&dimse_pm::sent_association_ac, this, _1, _2));
   sc.inject_conf(upperlayer::TYPE::A_ASSOCIATE_RQ,
             std::bind(&dimse_pm::sent_association_rq, this, _1, _2));
   sc.inject_conf(upperlayer::TYPE::P_DATA_TF,
             std::bind(&dimse_pm::sent_data_tf, this, _1, _2));
   sc.inject_conf(upperlayer::TYPE::A_RELEASE_RQ,
             std::bind(&dimse_pm::sent_release_rq, this, _1, _2));
   sc.inject_conf(upperlayer::TYPE::A_RELEASE_RP,
             std::bind(&dimse_pm::sent_release_rp, this, _1, _2));
   sc.inject_conf(upperlayer::TYPE::A_ABORT,
             std::bind(&dimse_pm::sent_abort, this, _1, _2));

   transfer_processors["1.2.840.10008.1.2"]
         = std::unique_ptr<transfer_processor> {new little_endian_implicit(dict)};
   transfer_processors["1.2.840.10008.1.2.1"]
         = std::unique_ptr<transfer_processor> {new little_endian_explicit(dict)};
   transfer_processors["1.2.840.10008.1.2.2"]
         = std::unique_ptr<transfer_processor> {new big_endian_explicit(dict)};
}

dimse_pm::~dimse_pm()
{
}

void dimse_pm::send_response(response r)
{
   using namespace upperlayer;
   using namespace util::log;
   BOOST_LOG_SEV(logger, info) << "User-issued request / response indication "
                                  "of type " << r.get_response_type();

   std::string sop_uid;
   for (auto e : dataset_iterator_adaptor(r.get_command())) {
      if (e.first == tag_type {0x0000, 0x0002}) {
         get_value_field<VR::UI>(e.second, sop_uid);
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

   auto data = assemble_response[r.get_response_type()](this, r, pres_context->id);

   std::vector<unsigned char> dataset;
   if (r.get_data().is_initialized()) {
      auto& tfproc = find_transfer_processor();
      dataset = tfproc.serialize(r.get_data().get());
   }
   data.data_set = dataset;
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
   using namespace dicom::util::log;
   assert(sc == &upperlayer_impl);
   BOOST_LOG_SEV(logger, debug) << "Received a_associate_rq pdu from upperlayer implementation";

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
                != transfer_syntaxes.end() /* &&
                std::find_if(transfer_processors.begin(), transfer_processors.end(),)*/) {
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
   ac.max_message_length = operations.get_initial_request().max_message_length;

   max_remote_msg_length = arq->max_message_length;

   sc->queue_for_write(std::unique_ptr<property>(new a_associate_ac {ac}));
   connection_properties = ac;
   connection_request = *arq;
   state = CONN_STATE::CONNECTED;
}

void dimse_pm::association_ac_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> ac)
{
   using namespace dicom::util::log;
   assert(sc == &upperlayer_impl);
   BOOST_LOG_SEV(logger, debug) << "Received a_associate_ac pdu from upperlayer implementation";

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

   max_remote_msg_length = asc->max_message_length;

   for (auto sop : operations.get_all_SOP()) {
      if (sop.msg_type == dimse::association_definition::DIMSE_MSG_TYPE::INITIATOR) {
         auto request = sop.sop_class;
         for (auto sg : request.get_service_groups()) {
            commandset_data header;
            header[{0x0000, 0x0002}] = make_elementfield<VR::UI>(request.get_SOP_class_UID());
            header[{0x0000, 0x0120}] = make_elementfield<VR::US>(next_message_id());
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

   //assert(sc == &upperlayer_impl);
   BOOST_LOG_SEV(logger, debug) << "Received p_data_tf pdu from upperlayer implementation";

   p_data_tf* d = dynamic_cast<p_data_tf*>(da.get());
   assert(d != nullptr); // d == nullptr would imply that this function is bound
                         // to the wrong message type.

   commandset_processor proc {dict};
   commandset_data b = proc.deserialize(d->command_set);

   BOOST_LOG_SEV(logger, info) << "Message from peer received";

   iod dataset;
   if (!d->data_set.empty()) {
      auto& tfproc = find_transfer_processor();

      dataset = tfproc.deserialize(d->data_set);
   }

   std::string SOP_UID;
   DIMSE_SERVICE_GROUP dsg;
   unsigned short message_id;
   unsigned short dsgint;
   bool request = b.find({0x0000, 0x0110}) != b.end();
   get_value_field<VR::UI>(b.at({0x0000, 0x0002}), SOP_UID);
   get_value_field<VR::US>(request ? b.at({0x0000, 0x0110}) : b.at({0x0000, 0x0120}), message_id);
   get_value_field<VR::US>(b.at({0x0000, 0x0100}), dsgint);
   dsg = static_cast<DIMSE_SERVICE_GROUP>(dsgint);

   BOOST_LOG_SEV(logger, debug) << "SOP UID: \t" << SOP_UID << "\n"
                                << "Service Group: \t" << dsg << "\n"
                                << "Message ID: \t" << std::to_string(message_id) << "\n";

   BOOST_LOG_SEV(logger, info) << "Issuing indication primitive to user";

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
   using namespace dicom::util::log;
   //assert(sc == &upperlayer_impl);
   BOOST_LOG_SEV(logger, trace) << "Received release_rq pdu from upperlayer implementation";

   sc->queue_for_write(std::unique_ptr<upperlayer::property>(new upperlayer::a_release_rp));
   state = CONN_STATE::IDLE;
   connection_properties = boost::none;
}

void dimse_pm::release_rp_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property>)
{
   using namespace dicom::util::log;
   //assert(sc == &upperlayer_impl);
   BOOST_LOG_SEV(logger, debug) << "Received release_rp pdu from upperlayer implementation";
}

void dimse_pm::abort_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property>)
{
   using namespace dicom::util::log;
   //assert(sc == &upperlayer_impl);
   BOOST_LOG_SEV(logger, debug) << "Received a_abort pdu from upperlayer implementation";
}

void dimse_pm::sent_association_ac(upperlayer::scx* sc, upperlayer::property*)
{
   using namespace dicom::util::log;
   //assert(sc == &upperlayer_impl);
   BOOST_LOG_SEV(logger, debug) << "Received send confirmation of a_associate_ac pdu "
                                   "from upperlayer implementation";
}

void dimse_pm::sent_association_rq(upperlayer::scx* sc, upperlayer::property* r)
{
   using namespace dicom::util::log;
   //assert(sc == &upperlayer_impl);
   BOOST_LOG_SEV(logger, debug) << "Received send confirmation of a_associate_rq pdu "
                                   "from upperlayer implementation";
   upperlayer::a_associate_rq* rq = dynamic_cast<upperlayer::a_associate_rq*>(r);
   assert(rq != nullptr);
   connection_request = *rq;
}

void dimse_pm::sent_data_tf(upperlayer::scx* sc, upperlayer::property*)
{
   using namespace dicom::util::log;
   //assert(sc == &upperlayer_impl);
   BOOST_LOG_SEV(logger, debug) << "Received send confirmation of p_data_tf pdu "
                                   "from upperlayer implementation";
}

void dimse_pm::sent_release_rq(upperlayer::scx* sc, upperlayer::property*)
{
   using namespace dicom::util::log;
   //assert(sc == &upperlayer_impl);
   BOOST_LOG_SEV(logger, debug) << "Received send confirmation of release_rq pdu "
                                   "from upperlayer implementation";
}

void dimse_pm::sent_release_rp(upperlayer::scx* sc, upperlayer::property*)
{
   using namespace dicom::util::log;
   //assert(sc == &upperlayer_impl);
   BOOST_LOG_SEV(logger, debug) << "Received send confirmation of release_rp pdu "
                                   "from upperlayer implementation";
}

void dimse_pm::sent_abort(upperlayer::scx* sc, upperlayer::property*)
{
   using namespace dicom::util::log;
   //assert(sc == &upperlayer_impl);
   BOOST_LOG_SEV(logger, debug) << "Received send confirmation of a_abort pdu "
                                   "from upperlayer implementation";
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


upperlayer::p_data_tf dimse_pm::assemble_cecho_rsp(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::attribute;
   commandset_data cresp;

   std::string SOP_uid;
   unsigned short message_id;
   auto cs = r.get_command();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::US>(cs.at(MessageID), message_id);

   cresp[AffectedSOPClassUID]       = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]              = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageIDBeingRespondedTo] = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]        = make_elementfield<VR::US>(0x0101);
   cresp[Status]                    = make_elementfield<VR::US>(r.get_status());

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_cecho_rq(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid;
   unsigned short message_id;
   auto cs = r.get_command();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::US>(cs.at(MessageIDBeingRespondedTo), message_id);

   cresp[AffectedSOPClassUID] = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]        = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageID]           = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]  = make_elementfield<VR::US>(0x0101);
   cresp[Status]              = make_elementfield<VR::US>(r.get_status());

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_cfind_rq(response r,  int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid;
   unsigned short message_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::US>(cs.at(MessageIDBeingRespondedTo), message_id);

   cresp[AffectedSOPClassUID]    = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]           = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageID]              = make_elementfield<VR::US>(message_id);
   cresp[Priority]               = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_priority()));
   cresp[CommandDataSetType]     = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[Status]                 = make_elementfield<VR::US>(r.get_status());

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_cfind_rsp(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid;
   unsigned short message_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::US>(cs.at(MessageID), message_id);

   cresp[AffectedSOPClassUID]       = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]              = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageIDBeingRespondedTo] = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]        = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[Status]                    = make_elementfield<VR::US>(r.get_status());

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_cstore_rq(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid, aff_SOP_uid, move_orig_ae;
   unsigned short message_id, move_orig_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::US>(cs.at(MessageIDBeingRespondedTo), message_id);
   get_value_field<VR::UI>(cs.at(AffectedSOPInstanceUID), aff_SOP_uid);
   get_value_field<VR::AE>(cs.at(MoveOriginatorApplicationEntityTitle), move_orig_ae);
   get_value_field<VR::US>(cs.at(MoveOriginatorMessageID), move_orig_id);

   cresp[AffectedSOPClassUID]    = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]           = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageID]              = make_elementfield<VR::US>(message_id);
   cresp[Priority]               = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_priority()));
   cresp[CommandDataSetType]     = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[Status]                 = make_elementfield<VR::US>(r.get_status());
   cresp[AffectedSOPInstanceUID] = make_elementfield<VR::UI>(aff_SOP_uid.length(), aff_SOP_uid);
   cresp[MoveOriginatorApplicationEntityTitle] = make_elementfield<VR::AE>(move_orig_ae.length(), move_orig_ae);
   cresp[MoveOriginatorMessageID]              = make_elementfield<VR::US>(move_orig_id);

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_cstore_rsp(response r,  int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid, aff_SOP_uid;
   unsigned short message_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::UI>(cs.at(AffectedSOPInstanceUID), aff_SOP_uid);
   get_value_field<VR::US>(cs.at(MessageID), message_id);

   cresp[AffectedSOPClassUID]       = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]              = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageIDBeingRespondedTo] = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]        = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[Status]                    = make_elementfield<VR::US>(r.get_status());
   cresp[AffectedSOPInstanceUID]    = make_elementfield<VR::UI>(aff_SOP_uid.length(), aff_SOP_uid);

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_cget_rq(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid;
   unsigned short message_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::US>(cs.at(MessageIDBeingRespondedTo), message_id);

   cresp[AffectedSOPClassUID]    = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]           = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageID]              = make_elementfield<VR::US>(message_id);
   cresp[Priority]               = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_priority()));
   cresp[CommandDataSetType]     = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_cget_rsp(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid;
   unsigned short message_id;
   unsigned short num_remaining_sub, num_completed_sub, num_failed_sub, num_warning_sub;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::US>(cs.at(MessageID), message_id);
   get_value_field<VR::US>(cs.at(NumberOfRemainingSuboperations), num_remaining_sub);
   get_value_field<VR::US>(cs.at(NumberOfCompletedSuboperations), num_completed_sub);
   get_value_field<VR::US>(cs.at(NumberOfFailedSuboperations), num_failed_sub);
   get_value_field<VR::US>(cs.at(NumberOfWarningSuboperations), num_warning_sub);

   cresp[AffectedSOPClassUID]       = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]              = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageIDBeingRespondedTo] = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]        = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[Status]                    = make_elementfield<VR::US>(r.get_status());
   cresp[NumberOfRemainingSuboperations] = make_elementfield<VR::US>(num_remaining_sub);
   cresp[NumberOfCompletedSuboperations] = make_elementfield<VR::US>(num_completed_sub);
   cresp[NumberOfFailedSuboperations]    = make_elementfield<VR::US>(num_failed_sub);
   cresp[NumberOfWarningSuboperations]   = make_elementfield<VR::US>(num_warning_sub);

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_cmove_rq(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid;
   std::string move_destination;
   unsigned short message_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::US>(cs.at(MessageIDBeingRespondedTo), message_id);
   get_value_field<VR::AE>(cs.at(MoveDestination), move_destination);

   cresp[AffectedSOPClassUID]    = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]           = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageID]              = make_elementfield<VR::US>(message_id);
   cresp[Priority]               = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_priority()));
   cresp[CommandDataSetType]     = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[MoveDestination]        = make_elementfield<VR::AE>(move_destination);

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_cmove_rsp(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid;
   unsigned short message_id;
   unsigned short num_remaining_sub, num_completed_sub, num_failed_sub, num_warning_sub;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::US>(cs.at(MessageID), message_id);/*
   get_value_field<VR::US>(cs.at(NumberOfRemainingSuboperations), num_remaining_sub);
   get_value_field<VR::US>(cs.at(NumberOfCompletedSuboperations), num_completed_sub);
   get_value_field<VR::US>(cs.at(NumberOfFailedSuboperations), num_failed_sub);
   get_value_field<VR::US>(cs.at(NumberOfWarningSuboperations), num_warning_sub);*/

   cresp[AffectedSOPClassUID]       = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]              = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageIDBeingRespondedTo] = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]        = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[Status]                    = make_elementfield<VR::US>(r.get_status());/*
   cresp[NumberOfRemainingSuboperations] = make_elementfield<VR::US>(num_remaining_sub);
   cresp[NumberOfCompletedSuboperations] = make_elementfield<VR::US>(num_completed_sub);
   cresp[NumberOfFailedSuboperations]    = make_elementfield<VR::US>(num_failed_sub);
   cresp[NumberOfWarningSuboperations]   = make_elementfield<VR::US>(num_warning_sub);*/

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_neventreport_rq(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid, aff_SOP_uid;
   unsigned short message_id, event_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::UI>(cs.at(AffectedSOPInstanceUID), aff_SOP_uid);
   get_value_field<VR::US>(cs.at(MessageIDBeingRespondedTo), message_id);
   get_value_field<VR::US>(cs.at(EventTypeID), event_id);

   cresp[AffectedSOPClassUID]    = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]           = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageID]              = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]     = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[AffectedSOPInstanceUID] = make_elementfield<VR::UI>(aff_SOP_uid);
   cresp[EventTypeID]            = make_elementfield<VR::US>(event_id);

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc {dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_neventreport_rsp(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid, aff_SOP_uid;
   unsigned short message_id, event_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::UI>(cs.at(AffectedSOPInstanceUID), aff_SOP_uid);
   get_value_field<VR::US>(cs.at(MessageID), message_id);
   get_value_field<VR::US>(cs.at(EventTypeID), event_id);

   cresp[AffectedSOPClassUID]       = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]              = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageIDBeingRespondedTo] = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]        = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[Status]                    = make_elementfield<VR::US>(r.get_status());
   cresp[AffectedSOPInstanceUID]    = make_elementfield<VR::UI>(aff_SOP_uid);
   cresp[EventTypeID]               = make_elementfield<VR::US>(event_id);

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc {dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_nget_rq(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid, SOP_instance_uid;
   unsigned short message_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(RequestedSOPClassUID), SOP_uid);
   get_value_field<VR::UI>(cs.at(RequestedSOPInstanceUID), SOP_instance_uid);
   get_value_field<VR::US>(cs.at(MessageIDBeingRespondedTo), message_id);

   cresp[RequestedSOPClassUID]      = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]              = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageID]                 = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]        = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[RequestedSOPInstanceUID]   = make_elementfield<VR::UI>(SOP_instance_uid);

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_nget_rsp(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid, aff_SOP_uid;
   unsigned short message_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::US>(cs.at(MessageID), message_id);
   get_value_field<VR::UI>(cs.at(AffectedSOPInstanceUID), aff_SOP_uid);

   cresp[AffectedSOPClassUID]       = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]              = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageIDBeingRespondedTo] = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]        = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[Status]                    = make_elementfield<VR::US>(r.get_status());
   cresp[AffectedSOPInstanceUID]    = make_elementfield<VR::UI>(aff_SOP_uid);

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_nset_rq(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid, SOP_instance_uid;
   unsigned short message_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(RequestedSOPClassUID), SOP_uid);
   get_value_field<VR::UI>(cs.at(RequestedSOPInstanceUID), SOP_instance_uid);
   get_value_field<VR::US>(cs.at(MessageIDBeingRespondedTo), message_id);

   cresp[RequestedSOPClassUID]      = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]              = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageID]                 = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]        = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[RequestedSOPInstanceUID]   = make_elementfield<VR::UI>(SOP_instance_uid);

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_nset_rsp(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid, aff_SOP_uid;
   unsigned short message_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::US>(cs.at(MessageID), message_id);
   get_value_field<VR::UI>(cs.at(AffectedSOPInstanceUID), aff_SOP_uid);

   cresp[AffectedSOPClassUID]       = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]              = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageIDBeingRespondedTo] = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]        = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[Status]                    = make_elementfield<VR::US>(r.get_status());
   cresp[AffectedSOPInstanceUID]    = make_elementfield<VR::UI>(aff_SOP_uid);

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_naction_rq(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid, SOP_instance_uid;
   unsigned short message_id, action_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(RequestedSOPClassUID), SOP_uid);
   get_value_field<VR::UI>(cs.at(RequestedSOPInstanceUID), SOP_instance_uid);
   get_value_field<VR::US>(cs.at(MessageIDBeingRespondedTo), message_id);
   get_value_field<VR::US>(cs.at(ActionTypeID), action_id);


   cresp[RequestedSOPClassUID]      = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]              = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageID]                 = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]        = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[RequestedSOPInstanceUID]   = make_elementfield<VR::UI>(SOP_instance_uid);
   cresp[ActionTypeID]              = make_elementfield<VR::US>(action_id);

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_naction_rsp(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid, aff_SOP_uid;
   unsigned short message_id, action_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::US>(cs.at(MessageID), message_id);
   get_value_field<VR::UI>(cs.at(AffectedSOPInstanceUID), aff_SOP_uid);
   get_value_field<VR::US>(cs.at(ActionTypeID), action_id);

   cresp[AffectedSOPClassUID]       = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]              = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageIDBeingRespondedTo] = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]        = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[Status]                    = make_elementfield<VR::US>(r.get_status());
   cresp[AffectedSOPInstanceUID]    = make_elementfield<VR::UI>(aff_SOP_uid);
   cresp[ActionTypeID]              = make_elementfield<VR::US>(action_id);

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_ncreate_rq(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid, SOP_instance_uid;
   unsigned short message_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::UI>(cs.at(AffectedSOPInstanceUID), SOP_instance_uid);
   get_value_field<VR::US>(cs.at(MessageIDBeingRespondedTo), message_id);


   cresp[AffectedSOPClassUID]       = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]              = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageID]                 = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]        = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[AffectedSOPInstanceUID]    = make_elementfield<VR::UI>(SOP_instance_uid);

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_ncreate_rsp(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid, aff_SOP_uid;
   unsigned short message_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::US>(cs.at(MessageID), message_id);
   get_value_field<VR::UI>(cs.at(AffectedSOPInstanceUID), aff_SOP_uid);

   cresp[AffectedSOPClassUID]       = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]              = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageIDBeingRespondedTo] = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]        = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[Status]                    = make_elementfield<VR::US>(r.get_status());
   cresp[AffectedSOPInstanceUID]    = make_elementfield<VR::UI>(aff_SOP_uid);

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_ndelete_rq(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid, SOP_instance_uid;
   unsigned short message_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(RequestedSOPClassUID), SOP_uid);
   get_value_field<VR::UI>(cs.at(RequestedSOPInstanceUID), SOP_instance_uid);
   get_value_field<VR::US>(cs.at(MessageIDBeingRespondedTo), message_id);


   cresp[RequestedSOPClassUID]      = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]              = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageID]                 = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]        = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[RequestedSOPInstanceUID]   = make_elementfield<VR::UI>(SOP_instance_uid);

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}

upperlayer::p_data_tf dimse_pm::assemble_ndelete_rsp(response r, int pres_context_id)
{
   using namespace upperlayer;
   using namespace data::dataset;
   commandset_data cresp;

   std::string SOP_uid, aff_SOP_uid;
   unsigned short message_id;
   auto cs = r.get_command();
   bool hasdata = r.get_data().is_initialized();
   get_value_field<VR::UI>(cs.at(AffectedSOPClassUID), SOP_uid);
   get_value_field<VR::US>(cs.at(MessageID), message_id);
   get_value_field<VR::UI>(cs.at(AffectedSOPInstanceUID), aff_SOP_uid);

   cresp[AffectedSOPClassUID]       = make_elementfield<VR::UI>(SOP_uid);
   cresp[CommandField]              = make_elementfield<VR::US>(static_cast<unsigned short>(r.get_response_type()));
   cresp[MessageIDBeingRespondedTo] = make_elementfield<VR::US>(message_id);
   cresp[CommandDataSetType]        = make_elementfield<VR::US>(hasdata ? 0x0102 : 0x0101);
   cresp[Status]                    = make_elementfield<VR::US>(r.get_status());
   cresp[AffectedSOPInstanceUID]    = make_elementfield<VR::UI>(aff_SOP_uid);

   auto size = dataset_size(cresp);
   cresp[CommandGroupLength] = make_elementfield<VR::UL>(size);

   commandset_processor proc{dict};
   auto serdata = proc.serialize(cresp);

   p_data_tf presp;
   presp.command_set = serdata;
   presp.pres_context_id = pres_context_id;
   presp.msg_length = max_remote_msg_length;
   assert(max_remote_msg_length > 0);

   return presp;
}


}

}

}
