#include <iostream>
#include <chrono>
#include <tuple>

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
   using namespace dicom::network;

   dicom::data::dictionary::dictionary dict {"commanddictionary.csv"};

   dimse::SOP_class echo {"1.2.840.10008.1.1",
   { { dataset::DIMSE_SERVICE_GROUP::C_ECHO_RSP,
      [](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) {
         assert(data == nullptr);
         std::cout << "Received C_ECHO_RSP\n";
//         pm->send_response({dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ, command});
         pm->release_association();
      }}}
   };

   dimse::SOP_class echorsp {"1.2.840.10008.1.1",
   { { dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ,
      [](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) {
         assert(data == nullptr);
         std::cout << "Received C_ECHO_RQ\n";
         pm->send_response({dataset::DIMSE_SERVICE_GROUP::C_ECHO_RSP, command});
      }}}
   };

   dimse::SOP_class echorq {"1.2.840.10008.1.1",
   { { dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ,
      [](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) {
         assert(data == nullptr);
         std::cout << "Send C_ECHO_RQ\n";
         pm->send_response({dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ, command});
      }}}
   };

   dimse::association_definition ascdef {"STORESCP", "ANY-SCU",
      {
          {echorq, {"1.2.840.10008.1.2", "1.2.840.10008.1.2.1"}, dimse::association_definition::DIMSE_MSG_TYPE::INITIATOR},
          {echo, {"1.2.840.10008.1.2", "1.2.840.10008.1.2.1"}, dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE},
          {echorsp, {"1.2.840.10008.1.2", "1.2.840.10008.1.2.1"}, dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE}
      }
   };


   try
   {
      auto request_property = ascdef.get_initial_request();
      dicom::network::upperlayer::scu sc("192.168.2.103", "11112", request_property);
//      dicom::network::upperlayer::scp sc(11112);
      dicom::network::dimse::dimse_pm dpm(sc,
         ascdef,
         dict
      );
      sc.run();
   } catch (std::exception& ec) {
      std::cout << ec.what();
   }
}
