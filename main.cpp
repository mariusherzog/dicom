#include <iostream>

#include "dimse_pm.hpp"
#include "upperlayer.hpp"


int main()
{
   iod dat;
   elementfield el = make_elementfield<VR::US>(28, 10, 1243);
   dat.insert(el);


   try
   {
      upperlayer::scp sc(11112);
      dimse_pm dpm(sc);
      sc.run();
   } catch (std::exception& ec) {
      std::cout << ec.what();
   }
}
