#include <iostream>
#include <chrono>
#include <tuple>

#include "network/dimse/dimse_pm.hpp"
#include "network/upperlayer/upperlayer.hpp"

#include "data/attribute/attribute.hpp"
#include "data/dataset/dataset_iterator.hpp"
#include "data/dictionary/dictionary_dyn.hpp"
#include "data/dictionary/datadictionary.hpp"
#include "data/dictionary/dictionary.hpp"
#include "data/attribute/constants.hpp"

#include "serviceclass/storage_scu.hpp"
#include "serviceclass/storage_scp.hpp"
#include "serviceclass/queryretrieve_scp.hpp"

#include "util/channel_sev_logger.hpp"

int main()
{
   dicom::util::log::init_log();

   using namespace dicom::data;
   using namespace dicom::data::attribute;
   using namespace dicom::data::dictionary;
   using namespace dicom::network;


   dicom::data::dictionary::dictionary dict {"commanddictionary.csv", "datadictionary.csv"};

   dimse::SOP_class echo {"1.2.840.10008.1.1",
   { { dataset::DIMSE_SERVICE_GROUP::C_ECHO_RSP,
      [](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) {
         assert(data == nullptr);
         std::cout << "Received C_ECHO_RSP\n";
         std::cout << command;
//         pm->send_response({dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ, command});
         pm->release_association();
      }}}
   };

   dimse::SOP_class findrsp {"1.2.840.10008.5.1.4.31",
   { { dataset::DIMSE_SERVICE_GROUP::C_FIND_RQ,
      [](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) {
         assert(data != nullptr);
         std::cout << "Received C_ECHO_RSP\n";
//         std::cout << *data;

         (*data)[{0x0008,0x4000}] = dicom::data::attribute::make_elementfield<VR::LT>("h\x12qej\x13");
         (*data)[{0x0018,0x1150}] = dicom::data::attribute::make_elementfield<VR::IS>("292w9292");

         pm->send_response({dataset::DIMSE_SERVICE_GROUP::C_FIND_RSP, command, *data, 0xff00});
         pm->send_response({dataset::DIMSE_SERVICE_GROUP::C_FIND_RSP, command, boost::none, 0x0000});
//         pm->release_association();
      }}}
   };

   dimse::SOP_class findrsp2 {"1.2.840.10008.5.1.4.31",
   { { dataset::DIMSE_SERVICE_GROUP::C_FIND_RSP,
      [](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) {
         //assert(data != nullptr);
         std::cout << "Received C_FIND_RSP\n";
         if (data) {
            std::cout << *data;
         } else {
            std::cout << "No dataset present\n";
         }
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

   dimse::SOP_class findrq {"1.2.840.10008.5.1.4.1.1.2",
   { { dataset::DIMSE_SERVICE_GROUP::C_FIND_RQ,
      [](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) {
         assert(data == nullptr);
         std::cout << "Send C_FIND_RQ\n";
         dataset::dataset_type dat, dat2, dat3;
         dataset::iod seq;
//         dat[dicom::data::attribute::Item] = dicom::data::attribute::make_elementfield<VR::NI>(0xffffffff);
//         dat[{0x0008, 0x0104}] = dicom::data::attribute::make_elementfield<VR::LO>(4, "meo");
//         dat[{0xfffe, 0xe00d}] = dicom::data::attribute::make_elementfield<VR::NI>();
//         dat2[dicom::data::attribute::Item] = dicom::data::attribute::make_elementfield<VR::NI>(0xffffffff);
//         dat2[{0x0008, 0x0104}] = dicom::data::attribute::make_elementfield<VR::LO>(4, "mwo");
//         dat2[{0xfffe, 0xe00d}] = dicom::data::attribute::make_elementfield<VR::NI>();
//         dat3[dicom::data::attribute::SequenceDelimitationItem] = dicom::data::attribute::make_elementfield<VR::NI>();
//         seq[{0x0032, 0x1064}] = dicom::data::attribute::make_elementfield<VR::SQ>(0xffffffff, {dat, dat2, dat3});
         std::vector<unsigned char> largedat(25000000, 0xff);
         seq[{0x7fe0,0x0010}] = dicom::data::attribute::make_elementfield<VR::OW>(25000000, largedat);
         pm->send_response({dataset::DIMSE_SERVICE_GROUP::C_FIND_RQ, command, seq});
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

   dimse::association_definition ascdef {"STORESCP", "OFFIS",
      {
//          {echorq, {"1.2.840.10008.1.2"}, dimse::association_definition::DIMSE_MSG_TYPE::INITIATOR},
          {findrq, {"1.2.840.10008.1.2"}, dimse::association_definition::DIMSE_MSG_TYPE::INITIATOR},
          {echo, {"1.2.840.10008.1.2"}, dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE},
          {echorsp, {"1.2.840.10008.1.2"}, dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE},
          {findrsp, {"1.2.840.10008.1.2.1"}, dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE},
          {findrsp2, {"1.2.840.10008.1.2.1"}, dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE}
      },
      4096
   };


   try
   {

      queryretrieve_scp qr("QRSCP", "QRSCU", 4096, dict,
                           [](queryretrieve_scp* st, dicom::data::dataset::commandset_data cmd, std::unique_ptr<dicom::data::dataset::iod> data) {

      });
      qr.run();
//      storage_scp store("STORAGESCU", "STORAGESCP", 4096, dict, [](storage_scp* st, dicom::data::dataset::commandset_data cmd, std::unique_ptr<dicom::data::dataset::iod> data)
//      {
//         std::ofstream out("out", std::ios::binary);
//         std::vector<unsigned char> imdata;
//         auto value_field = (*data)[{0x7fe0,0x0010}];
//         get_value_field<VR::OW>(value_field, imdata);
//         out << imdata;
//         out.flush();
//      });
//      store.run();
   } catch (std::exception& ec) {
      std::cout << ec.what();
   }
}
