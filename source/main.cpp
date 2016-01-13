#include <iostream>

#include "dimse/dimse_pm.hpp"
#include "upperlayer/upperlayer.hpp"



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
