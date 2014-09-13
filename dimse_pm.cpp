#include "dimse_pm.hpp"

#include <memory>
#include <string>

#include "upperlayer_properties.hpp"

using namespace upperlayer;

const std::map<dimse_pm::service, std::string> dimse_pm::service_uid {
   {dimse_pm::service::C_ECHO, "1.2.840.10008.3.1.1.1"},
};

dimse_pm::dimse_pm():
   state(CONN_STATE::IDLE),
   transfer_syntaxes {"1.2.840.10008.1.2"},
   abstract_syntaxes {"1.2.840.10008.1.1", "1.2.840.10008.5.1.4.1.1.9.1.3"},
   application_contexts {"1.2.840.10008.3.1.1.1"},
   ul(11112, { })
{
   associate();
}

dimse_pm::~dimse_pm()
{
   if (state == CONN_STATE::CONNECTED) {
      abort();
   }
}

bool dimse_pm::associate()
{
   if (state == CONN_STATE::CONNECTED)
   {
      return false;
   }

   std::unique_ptr<property> p = nullptr; // ul.receive();
   a_associate_rq* arq = dynamic_cast<a_associate_rq*>(p.get());


   using RESULT = a_associate_ac::presentation_context::RESULT;
   a_associate_ac ac;

   ac.called_ae = arq->called_ae;
   ac.calling_ae = arq->calling_ae;

   ac.application_context = arq->application_context;

   if (application_contexts.find(arq->application_context) == application_contexts.end()) {
      a_associate_rj rj;
      rj.reason_ = a_associate_rj::REASON::APPL_CONT_NOT_SUPP;
      //ul.send(&rj);
      return false;
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
   ac.max_message_length = 0xFFFF;

   //ul.send(&ac);
   connection_properties = ac;
   state = CONN_STATE::CONNECTED;
   return true;
}

void dimse_pm::receive()
{
   if (state == CONN_STATE::CONNECTED) {
      std::unique_ptr<property> d = nullptr; // ul.receive();
      p_data_tf* data = dynamic_cast<p_data_tf*>(d.get());

      //deserialize(data);

      auto x = procs[data->message_id];
      x(data->command_set, data->data_set);
   }
}

void dimse_pm::send(std::vector<attribute> a)
{
   if (state == CONN_STATE::CONNECTED) {
      upperlayer::p_data_tf d = serialize(a);
      //ul.send(&d);
   }
}

void dimse_pm::abort()
{
   if (state == CONN_STATE::CONNECTED) {
      a_abort a;
      //ul.send(&a);
      state = CONN_STATE::IDLE;
   }
}


void dimse_pm::inject(unsigned char id, std::function<void(std::vector<unsigned char>, std::vector<unsigned char>)> fn)
{
   procs[id] = fn;
}

std::vector<attribute> dimse_pm::deserialize(p_data_tf* data)
{
   // assuming little endian, value length 2 bytes
}

p_data_tf dimse_pm::serialize(std::vector<attribute> a)
{

}


