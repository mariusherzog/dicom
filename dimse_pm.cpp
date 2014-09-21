#include "dimse_pm.hpp"

#include <memory>
#include <string>
#include <functional>

#include "upperlayer_properties.hpp"
#include "upperlayer.hpp"

using namespace upperlayer;

//const std::map<dimse_pm::service, std::string> dimse_pm::service_uid {
//   {dimse_pm::service::C_ECHO, "1.2.840.10008.3.1.1.1"},
//};

dimse_pm::dimse_pm(upperlayer::Iupperlayer_comm_ops& sc):
   state {CONN_STATE::IDLE},
   transfer_syntaxes {"1.2.840.10008.1.2"},
   abstract_syntaxes {"1.2.840.10008.1.1", "1.2.840.10008.5.1.4.1.1.9.1.3"},
   application_contexts {"1.2.840.10008.3.1.1.1"}/*,
   ul {sc}*/
{
   using namespace std::placeholders;
   sc.inject(upperlayer::TYPE::A_ASSOCIATE_RQ,
             std::bind(&dimse_pm::associate, this, _1, _2));
   sc.inject(upperlayer::TYPE::P_DATA_TF,
             std::bind(&dimse_pm::data_handler, this, _1, _2));
   sc.inject(upperlayer::TYPE::A_RELEASE_RQ,
             std::bind(&dimse_pm::release_resp, this, _1, _2));
}

dimse_pm::~dimse_pm()
{
}

void dimse_pm::associate(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> rq)
{
   a_associate_rq* arq = dynamic_cast<a_associate_rq*>(rq.get());
   assert(arq);

   using RESULT = a_associate_ac::presentation_context::RESULT;
   a_associate_ac ac;

   ac.called_ae = arq->called_ae;
   ac.calling_ae = arq->calling_ae;

   ac.application_context = arq->application_context;

   if (application_contexts.find(arq->application_context) == application_contexts.end()) {
      a_associate_rj rj;
      rj.reason_ = a_associate_rj::REASON::APPL_CONT_NOT_SUPP;
      sc->queue_for_write(std::unique_ptr<property>(new a_associate_rj {rj}));
      state = CONN_STATE::IDLE;
   }

   // check the support of each presentation context and populate own a_associate_ac
   // accordingly
   for (const auto pc : arq->pres_contexts) {
      if (abstract_syntaxes.find(pc.abstract_syntax) != abstract_syntaxes.end()) {

         bool have_common_ts = false;
         for (const auto ts : pc.transfer_syntaxes) {
            if (transfer_syntaxes.find(ts) != transfer_syntaxes.end()) {
               ac.pres_contexts.push_back({pc.id, RESULT::ACCEPTANCE, ts});
               have_common_ts = true;
               break;
            }
         }
         if (!have_common_ts) {
            ac.pres_contexts.push_back({pc.id, RESULT::TRANSF_SYNT_NOT_SUPP, pc.abstract_syntax});
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

void dimse_pm::data_handler(scx* sc, std::unique_ptr<property> da)
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

   p_data_tf data;
   data.from_pdu(echo_rsp);
   data.make_pdu();

   sc->queue_for_write(std::unique_ptr<property>(new p_data_tf {data}));
}

void dimse_pm::release_resp(upperlayer::scx* sc, std::unique_ptr<upperlayer::property>)
{
   sc->queue_for_write(std::unique_ptr<upperlayer::property>(new upperlayer::a_release_rp));
   state = CONN_STATE::CONNECTED;
}


void dimse_pm::inject(unsigned char id, std::function<void(std::vector<unsigned char>, std::vector<unsigned char>)> fn)
{
   procs[id] = fn;
}

