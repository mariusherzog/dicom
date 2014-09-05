#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <boost/asio.hpp>
#include <set>

//#include "dimse_pm.hpp"
#include "upperlayer.hpp"

void print(std::vector<unsigned char> c, std::vector<unsigned char> d)
{
   std::cout << "Command set: \n";
   for (const auto e : c) {
      std::cout << e;
   }

   std::cout << "Data set: \n";
   for (const auto e : d) {
      std::cout << e;
   }
}


//example function for a_associate_rq
void request_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> rq)
{
   std::set<std::string> transfer_syntaxes {"1.2.840.10008.1.2"};
   std::set<std::string> abstract_syntaxes {"1.2.840.10008.1.1"};
   std::set<std::string> application_contexts {"1.2.840.10008.3.1.1.1"};

   using namespace upperlayer;
   using RESULT = upperlayer::a_associate_ac::presentation_context::RESULT;

   a_associate_rq* arq = dynamic_cast<a_associate_rq*>(rq.get());
   a_associate_ac ac;

   ac.called_ae = arq->called_ae;
   ac.calling_ae = arq->calling_ae;

   ac.application_context = arq->application_context;

   if (application_contexts.find(arq->application_context) == application_contexts.end()) {
      a_associate_rj rj;
      rj.reason_ = a_associate_rj::REASON::APPL_CONT_NOT_SUPP;
      sc->send(&rj);
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

   sc->send(&ac);
}

// example function for p_data_tf
void printall(upperlayer::scx*, std::unique_ptr<upperlayer::property> rq)
{
   using namespace upperlayer;
   p_data_tf* d = dynamic_cast<p_data_tf*>(rq.get());

   for (const auto& c : d->command_set) {
      std::cout << c;
   }
}


int main()
{
//   dimse_pm dpm;
//   dpm.inject(1, print);
//   dpm.receive();
   upperlayer::scp sc(11112, { {upperlayer::TYPE::A_ASSOCIATE_RQ, request_handler},
                               {upperlayer::TYPE::P_DATA_TF, printall} });
//   sc.receive(); // receive a_associate_rq
//   sc.receive(); // receive data
   sc.run();
}
