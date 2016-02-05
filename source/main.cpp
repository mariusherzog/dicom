#include <iostream>
#include <chrono>

#include "network/dimse/dimse_pm.hpp"
#include "network/dimse/initial_request.hpp" // remove
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
   using namespace dicom::network;

   dicom::data::dictionary::dictionary dict {"commanddictionary.csv"};

   dimse::SOP_class echo {"1.2.840.10008.1.1",
   { { dataset::DIMSE_SERVICE_GROUP::C_ECHO_RSP,
      [](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) {
         assert(data == nullptr);
         std::cout << "Received C_ECHO_RSP\n";
         //pm->release_association();
         pm->send_request({dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ, command});
      }}}
   };

   dimse::SOP_class echorq {"1.2.840.10008.1.1",
   { { dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ,
      [](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) {
         assert(data == nullptr);
         std::cout << "Send C_ECHO_RQ\n";
         dataset::commandset_data cmd;
         pm->send_request({dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ, command});
//         return dimse::response {dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ, cmd};
      }}}
   };

   dimse::initial_request irq {"STORESCP", "ANY-SCU",
      {
         {echorq, {"1.2.840.10008.1.2"}}
      }
   };


   try
   {
      auto request_property = irq.get_initial_request();
      dicom::network::upperlayer::scu sc("192.168.2.103", "11112", request_property);
      //dicom::network::upperlayer::scp sc(11112);
      dicom::network::dimse::dimse_pm dpm(sc,
         {{echo, {"1.2.840.10008.1.2"}}},
         irq.get_SOP_class(1),
         dict
      );
      sc.run();
   } catch (std::exception& ec) {
      std::cout << ec.what();
   }
}
