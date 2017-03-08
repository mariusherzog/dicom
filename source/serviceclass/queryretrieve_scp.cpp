#include "queryretrieve_scp.hpp"

#include "data/dataset/dataset_iterator.hpp"
#include "data/dictionary/dictionary_dyn.hpp"
#include "data/dictionary/datadictionary.hpp"
#include "data/dictionary/dictionary.hpp"
#include "data/attribute/constants.hpp"

using namespace dicom;
using namespace dicom::network;
using namespace dicom::data;

dimse::SOP_class findrq {"1.2.840.10008.5.1.4.31",
{ { dataset::DIMSE_SERVICE_GROUP::C_MOVE_RQ,
   [](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) {

      std::cout << "We have a C-MOVE Request\n";
      dataset::dataset_type dat, dat2, dat3;
      dataset::iod seq;
//      dat[dicom::data::attribute::Item] = dicom::data::attribute::make_elementfield<VR::NI>(0xffffffff);
//      dat[{0x0008, 0x0104}] = dicom::data::attribute::make_elementfield<VR::LO>(4, "meo");
//      dat[{0xfffe, 0xe00d}] = dicom::data::attribute::make_elementfield<VR::NI>();
//      dat2[dicom::data::attribute::Item] = dicom::data::attribute::make_elementfield<VR::NI>(0xffffffff);
//      dat2[{0x0008, 0x0104}] = dicom::data::attribute::make_elementfield<VR::LO>(4, "mwo");
//      dat2[{0xfffe, 0xe00d}] = dicom::data::attribute::make_elementfield<VR::NI>();
//      dat3[dicom::data::attribute::SequenceDelimitationItem] = dicom::data::attribute::make_elementfield<VR::NI>();
//      seq[{0x0032, 0x1064}] = dicom::data::attribute::make_elementfield<VR::SQ>(0xffffffff, {dat, dat2, dat3});



//      while () {
//         // C-Store
//         auto request_property = ascdef.get_initial_request();
//         dicom::network::upperlayer::scu sc(dict, "localhost", "11113", request_property);
//         dicom::network::dimse::dimse_pm_manager dpm(sc, ascdef, dict);
//         sc.run();
//         // end c store

//         pm->send_response({dataset::DIMSE_SERVICE_GROUP::C_MOVE_RSP, command, boost::none, });
//      }
   }}}
};



//queryretrieve_scp::queryretrieve_scp(std::string calling_ae, std::string called_ae, std::size_t max_message_len):
//   sop_class { {calling_ae, called_ae }  }
//{

//}
