#include <iostream>
#include <chrono>

#include "network/dimse/dimse_pm.hpp"
#include "network/upperlayer/upperlayer.hpp"

#include "data/dataset/dataset_iterator.hpp"
#include "data/dictionary/dictionary_dyn.hpp"
#include "data/dictionary/datadictionary.hpp"
#include "data/dictionary/dictionary.hpp"




int main()
{
   using namespace dicom::data;
   using namespace dicom::data::attribute;
   using namespace dicom::data::dictionary;

   dicom::data::dictionary::dictionary dict {"commanddictionary.csv"};

   dicom::network::dimse::SOP_class echo {"1.2.840.10008.1.1",
   { { dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ,
      [](std::unique_ptr<dataset::iod> data) -> dicom::network::dimse::response {
         assert(data == nullptr);
         std::cout << "Received C_ECHO_RQ\n";
         return dicom::network::dimse::response {dataset::DIMSE_SERVICE_GROUP::C_ECHO_RSP};
      }}}
   };

   try
   {
      dicom::network::upperlayer::scp sc(11112);
      dicom::network::dimse::dimse_pm dpm(sc,
         {{echo, {"1.2.840.10008.1.2"}}},
         dict
      );
      sc.run();
   } catch (std::exception& ec) {
      std::cout << ec.what();
   }
}
