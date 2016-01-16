#include <iostream>

#include "dimse/dimse_pm.hpp"
#include "upperlayer/upperlayer.hpp"

#include "dictionary/dictionary_dyn.hpp"
#include "dictionary/datadictionary.hpp"




int main()
{
   dictionary_dyn d {"/media/STORAGE/_files/Studium/Sem 5/Studienprojekt/dicom/dicom/datadictionary.csv", dictionary_dyn::MODE::FROMFILE};
   std::cout << d.lookup(0x4008, 0x0101).retired << std::flush;
   datadictionary<0x4008, 0x0101> dat;
   std::cout << dat.retired << std::flush;

   try
   {
      upperlayer::scp sc(11112);
      dimse_pm dpm(sc);
      sc.run();
   } catch (std::exception& ec) {
      std::cout << ec.what();
   }
}
