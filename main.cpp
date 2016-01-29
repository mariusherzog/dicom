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
      //sc->send(&rj);
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

   //sc->send(&ac);
   sc->queue_for_write(std::unique_ptr<property>(new a_associate_ac {ac}));
}

// example function for p_data_tf
void printall(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> rq)
{
   using namespace upperlayer;
   p_data_tf* d = dynamic_cast<p_data_tf*>(rq.get());

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

void release_rp(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> rq)
{
   sc->queue_for_write(std::unique_ptr<upperlayer::property>(new upperlayer::a_release_rp));
}

void conf_handler(upperlayer::scx* sc, upperlayer::property* rq)
{
   using namespace upperlayer;
   const a_associate_rq* d = dynamic_cast<a_associate_rq*>(rq);
   assert(d);
   std::cout << "sent associate confirmation\n" << std::flush;
}

int main()
{

   upperlayer::a_associate_rq request;
   request.application_context = "1.2.840.10008.3.1.1.1";
   request.called_ae = "STORESCP        ";
   request.calling_ae = "ANY-SCU         ";
   request.max_message_length = 0xFFFE;
   upperlayer::a_associate_rq::presentation_context p;
   p.id = 1;
   p.abstract_syntax = "1.2.840.10008.1.1";
   p.transfer_syntaxes = {"1.2.840.10008.1.2"};
   request.pres_contexts = {p};


   try
   {
//   upperlayer::scp sc(11112, { {upperlayer::TYPE::A_ASSOCIATE_RQ, request_handler},
//                               {upperlayer::TYPE::P_DATA_TF, printall},
//                               {upperlayer::TYPE::A_RELEASE_RQ, release_rp } });
   upperlayer::scu sc("192.168.2.103", "11112", request);

   sc.inject_conf(upperlayer::TYPE::A_ASSOCIATE_RQ, conf_handler);
   sc.run();
   } catch (std::exception& ec) {
      std::cout << ec.what();
   }
}
