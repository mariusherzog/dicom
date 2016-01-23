#include <iostream>
#include <chrono>

#include "network/dimse/dimse_pm.hpp"
#include "network/upperlayer/upperlayer.hpp"

#include "data/dictionary/dictionary_dyn.hpp"
#include "data/dictionary/datadictionary.hpp"




int main()
{
   try
   {
      upperlayer::scp sc(11112);
      dimse_pm dpm(sc);
      sc.run();
   } catch (std::exception& ec) {
      std::cout << ec.what();
   }
}
