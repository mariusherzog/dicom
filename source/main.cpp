#include <iostream>

#include "dimse/dimse_pm.hpp"
#include "upperlayer/upperlayer.hpp"

#include "datadictionary.hpp"


int main()
{
   iod dat;
   elementfield el = make_elementfield<VR::US>(28, 10, 2, 1243);
   dat.insert(el);
   short unsigned n;
   get_value_field<VR::US>(el, n);
   std::cout << n << std::flush;

   datadictionary<0x4010, 0x1017> dic;
   std::cout << dic.keyword;



   try
   {
      upperlayer::scp sc(11112);
      dimse_pm dpm(sc);
      sc.run();
   } catch (std::exception& ec) {
      std::cout << ec.what();
   }
}
