#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <boost/asio.hpp>

#include "upperlayer.hpp"
#include "upperlayer_properties.hpp"

int main()
{

   scp scp(11112);

   std::unique_ptr<property> p = scp.receive();
   a_associate_rq* arq = dynamic_cast<a_associate_rq*>(p.get());

   std::string accepted_as = "1.2.840.10008.1.1";
   a_associate_ac ac;
   if (arq) {
      for (auto pc : arq->pres_contexts) {
         if (pc.abstract_syntax == accepted_as) {
            ac.pres_contexts.push_back(a_associate_ac::presentation_context {pc.id, a_associate_ac::presentation_context::RESULT::ACCEPTANCE, pc.transfer_syntaxes[0]});
         } else {
            ac.pres_contexts.push_back(a_associate_ac::presentation_context {pc.id, a_associate_ac::presentation_context::RESULT::TRANFS_SYNT_NOT_SUPP, pc.transfer_syntaxes[0]});
         }
      }
      ac.application_context = arq->application_context;
      ac.called_ae = arq->called_ae;
      ac.calling_ae = arq->calling_ae;
      ac.max_message_length = 0xFFFF;
   }

   scp.send(&ac);

   std::unique_ptr<property> r = scp.receive();
   int x = 2;
   x*= 2;
}
