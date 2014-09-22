#include <iostream>

#include "dimse_pm.hpp"
#include "upperlayer.hpp"


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
