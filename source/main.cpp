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
   using namespace dicom::network;

   dicom::data::dictionary::dictionary dict {"commanddictionary.csv"};

   dimse::SOP_class echo {"1.2.840.10008.1.1",
   { { dataset::DIMSE_SERVICE_GROUP::C_ECHO_RSP,
      [](dimse::dimse_pm* pm, std::unique_ptr<dataset::iod> data) {
         assert(data == nullptr);
         std::cout << "Received C_ECHO_RSP\n";
         pm->release_association();
         return dimse::response {dataset::DIMSE_SERVICE_GROUP::C_ECHO_RSP};
      }}}
   };

   dimse::SOP_class_request echorq {"1.2.840.10008.1.1", dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ,
      [](std::unique_ptr<dataset::iod> data) {
         assert(data == nullptr);
         std::cout << "Send C_ECHO_RQ\n";
         return dimse::response {dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ};
      }
   };

   dicom::network::upperlayer::a_associate_rq request;
   request.application_context = "1.2.840.10008.3.1.1.1";
   request.called_ae = "STORESCP        ";
   request.calling_ae = "ANY-SCU         ";
   request.max_message_length = 0xFFFE;
   dicom::network::upperlayer::a_associate_rq::presentation_context p;
   p.id = 1;
   p.abstract_syntax = "1.2.840.10008.1.1";
   p.transfer_syntaxes = {"1.2.840.10008.1.2"};
   request.pres_contexts = {p};


   try
   {
      dicom::network::upperlayer::scu sc("192.168.2.103", "11112", request);
      //dicom::network::upperlayer::scp sc(11112);
      dicom::network::dimse::dimse_pm dpm(sc,
         {{echo, {"1.2.840.10008.1.2"}}},
         {echorq, "1.2.840.10008.1.2"},
         dict
      );
      sc.run();
   } catch (std::exception& ec) {
      std::cout << ec.what();
   }
}
