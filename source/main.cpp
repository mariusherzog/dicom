#include <iostream>
#include <chrono>

#include "network/dimse/dimse_pm.hpp"
#include "network/upperlayer/upperlayer.hpp"

#include "data/dataset/dataset_iterator.hpp"
#include "data/dictionary/dictionary_dyn.hpp"
#include "data/dictionary/datadictionary.hpp"




int main()
{
   using namespace dicom::data;
   using namespace dicom::data::attribute;

   dicom::network::dimse::SOP_class echo("1.2.840.10008.1.1",
   { { dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ,
      [](std::unique_ptr<dataset::iod> data) {
         assert(data == nullptr);
         std::cout << "Received C_ECHO_RQ\n";
      }}}
   );


   try
   {
      dicom::network::upperlayer::scp sc(11112);
      dicom::network::dimse::dimse_pm dpm(sc, {{echo, {"1.2.840.10008.1.2"}}});
      sc.run();
   } catch (std::exception& ec) {
      std::cout << ec.what();
   }
}
