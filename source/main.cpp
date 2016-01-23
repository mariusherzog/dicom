#include <iostream>
#include <chrono>

#include "dimse/dimse_pm.hpp"
#include "upperlayer/upperlayer.hpp"

#include "dictionary/dictionary_dyn.hpp"
#include "dictionary/datadictionary.hpp"
#include "attributedata/dataset_iterator.hpp"




int main()
{
   commandset_data dat;
   dat.insert(make_elementfield<VR::UI>(0x0000, 0x0002, 18, "1.2.840.10008.1.1"));
   dat.insert(make_elementfield<VR::US>(0x0000, 0x0120, 2, 2));
   dat.insert(make_elementfield<VR::US>(0x0000, 0x0800, 2, 0x0101));
   dat.insert(make_elementfield<VR::US>(0x0000, 0x0900, 2, 0));

   commandset_data dat2;
   dat2.insert(make_elementfield<VR::UI>(0x0000, 0x0002, 18, "1.2.840.10008.1.1"));
   dat2.insert(make_elementfield<VR::US>(0x0000, 0x0800, 2, 0xf0f0));
   dat2.insert(make_elementfield<VR::DT>(0xfffe, 0xe0dd, 2, "0xf0f0"));
   dat.insert(make_elementfield<VR::SQ>(0x0008, 0x0006, 0xffff, dat2));
   dat.insert(make_elementfield<VR::US>(0x0009, 0x0900, 2, 0x1234));

   dataset_iterator it = dat.begin();
   for (; it != dat.end();) {
      std::cout << it->tag.element_id << " ";
      ++it;
   }
   std::cout << "\n";
   for (; it != dat.begin();) {
      std::cout << it->tag.element_id << " ";
      --it;
   }

   elementfield e = *it;
   std::cout << e.tag.element_id << " " << std::flush;


   try
   {
      upperlayer::scp sc(11112);
      dimse_pm dpm(sc);
      sc.run();
   } catch (std::exception& ec) {
      std::cout << ec.what();
   }
}
