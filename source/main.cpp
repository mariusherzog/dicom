#include <iostream>

#include "dimse/dimse_pm.hpp"
#include "upperlayer/upperlayer.hpp"

#include "dimse/dictionary_dyn.hpp"




int main()
{
   dictionary_dyn d {"/media/STORAGE/_files/Studium/Sem 5/Studienprojekt/dicom/dicom/datadictionary.csv", dictionary_dyn::MODE::FROMFILE};
   std::cout << d.lookup(0x0024, 0x0077).message_field << std::flush;

   try
   {
      upperlayer::scp sc(11112);
      dimse_pm dpm(sc);
      sc.run();
   } catch (std::exception& ec) {
      std::cout << ec.what();
   }
}
