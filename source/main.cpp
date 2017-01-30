#include <iostream>
#include <chrono>
#include <tuple>

#include "network/dimse/dimse_pm.hpp"
#include "network/upperlayer/upperlayer.hpp"

#include "data/dataset/dataset_iterator.hpp"
#include "data/dictionary/dictionary_dyn.hpp"
#include "data/dictionary/datadictionary.hpp"
#include "data/dictionary/dictionary.hpp"
#include "data/attribute/constants.hpp"

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
         pm->send_response({dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ, command});
//         pm->release_association();
      }}}
   };

   dimse::SOP_class findrsp {"1.2.840.10008.5.1.4.31",
   { { dataset::DIMSE_SERVICE_GROUP::C_FIND_RQ,
      [](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) {
         assert(data != nullptr);
         std::cout << "Received C_ECHO_RSP\n";
         std::cout << *data;

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

   dimse::SOP_class findrq {"1.2.840.10008.5.1.4.31",
   { { dataset::DIMSE_SERVICE_GROUP::C_FIND_RQ,
      [](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) {
         assert(data == nullptr);
         std::cout << "Send C_FIND_RQ\n";
         dataset::dataset_type dat, dat2, dat3;
         dataset::iod seq;
         dat[dicom::data::attribute::Item] = dicom::data::attribute::make_elementfield<VR::NI>(0xffffffff);
         dat[{0x0008, 0x0104}] = dicom::data::attribute::make_elementfield<VR::LO>(4, "meo");
         dat[{0xfffe, 0xe00d}] = dicom::data::attribute::make_elementfield<VR::NI>();
         dat2[dicom::data::attribute::Item] = dicom::data::attribute::make_elementfield<VR::NI>(0xffffffff);
         dat2[{0x0008, 0x0104}] = dicom::data::attribute::make_elementfield<VR::LO>(4, "mwo");
         dat2[{0xfffe, 0xe00d}] = dicom::data::attribute::make_elementfield<VR::NI>();
         dat3[dicom::data::attribute::SequenceDelimitationItem] = dicom::data::attribute::make_elementfield<VR::NI>();
         seq[{0x0032, 0x1064}] = dicom::data::attribute::make_elementfield<VR::SQ>(0xffffffff, {dat, dat2, dat3});
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
//          {echorq, {"1.2.840.10008.1.2.2"}, dimse::association_definition::DIMSE_MSG_TYPE::INITIATOR},
          {findrq, {"1.2.840.10008.1.2"}, dimse::association_definition::DIMSE_MSG_TYPE::INITIATOR},
          {echo, {"1.2.840.10008.1.2"}, dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE},
          {echorsp, {"1.2.840.10008.1.2"}, dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE},
          {findrsp, {"1.2.840.10008.1.2"}, dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE},
          {findrsp2, {"1.2.840.10008.1.2"}, dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE}
      },
      4096
   };


   try
   {
      auto request_property = ascdef.get_initial_request();
      //dicom::network::upperlayer::scu sc(dict, "localhost", "11113", request_property);
      dicom::network::upperlayer::scp sc(dict, 11113);
//      dicom::network::dimse::dimse_pm dpm(sc,
//                                          ascdef,
//         dict
//      );

      std::vector<dicom::network::dimse::dimse_pm*> dimses;

      auto new_conn = [&](dicom::network::upperlayer::Iupperlayer_comm_ops* new_conn) {
         dimses.push_back(new dicom::network::dimse::dimse_pm {*new_conn, ascdef, dict});
      };

//      sc.new_connection2 = [&](dicom::network::upperlayer::scp_connection* new_conn) {
//         dimses.push_back(new dicom::network::dimse::dimse_pm {*new_conn, ascdef, dict});
//      };
      sc.new_connection(new_conn);

      sc.run();
   } catch (std::exception& ec) {
      std::cout << ec.what();
   }
}
