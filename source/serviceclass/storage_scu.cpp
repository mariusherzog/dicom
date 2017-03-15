#include "storage_scu.hpp"

#include <map>
#include <functional>

#include "data/dataset/dataset_iterator.hpp"
#include "data/dictionary/dictionary_dyn.hpp"
#include "data/dictionary/datadictionary.hpp"
#include "data/dictionary/dictionary.hpp"
#include "data/attribute/constants.hpp"

using namespace dicom::data;
using namespace dicom::data::attribute;
using namespace dicom::data::dictionary;
using namespace dicom::network;

using handlermap = std::map<dicom::data::dataset::DIMSE_SERVICE_GROUP,
std::function<void(dicom::network::dimse::dimse_pm* pm, dicom::data::dataset::commandset_data cdata, std::unique_ptr<dicom::data::dataset::iod> data)>>;

storage_scu::storage_scu(std::string calling_ae, std::string called_ae,
                         int max_message_len, dicom::data::dictionary::dictionary& dict,
                         std::function<void(storage_scu*, dataset::commandset_data, std::unique_ptr<dataset::iod>)> handler):
   sop_class { "1.2.840.10008.5.1.4.1.1.1\0", handlermap {
{dataset::DIMSE_SERVICE_GROUP::C_STORE_RSP, [this](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) { this->send_store_request(pm, command, std::move(data)); }}
               }
             },
   assoc_def
   {
      calling_ae, called_ae, {
         {sop_class, {"1.2.840.10008.1.2"}, dimse::association_definition::DIMSE_MSG_TYPE::INITIATOR},
         {sop_class, {"1.2.840.10008.1.2"}, dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE}
      }, max_message_len
   },
   initial_rq {assoc_def.get_initial_request()},
   scu { dict, "localhost", "1113", initial_rq},
   dimse_pm {scu, assoc_def, dict},
   senddata {},
   handler {handler},
   do_release {false}
{
   senddata[{0x0010, 0x0010}] = attribute::make_elementfield<VR::PN>("test");
}

storage_scu::~storage_scu()
{
   // close
}

upperlayer::scu& storage_scu::get_scu()
{
   return scu;
}

void storage_scu::release()
{
   do_release = true;
}

void storage_scu::send_next_request(dataset::iod data)
{
   senddata = data;
   scu.accept_new();
}

void storage_scu::send_store_request(dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data)
{
   assert(data == nullptr);

   handler(this, command, std::move(data));

   if (do_release) {
      pm->release_association();
   }

   std::cout << "Send C_STORE_RQ\n";
   dataset::dataset_type dat, dat2, dat3;
   dataset::iod seq;
//   dat[dicom::data::attribute::Item] = dicom::data::attribute::make_elementfield<VR::NI>(0xffffffff);
//   dat[{0x0008, 0x0104}] = dicom::data::attribute::make_elementfield<VR::LO>(4, "meo" + cnt);
//   dat[{0xfffe, 0xe00d}] = dicom::data::attribute::make_elementfield<VR::NI>();
//   dat2[dicom::data::attribute::Item] = dicom::data::attribute::make_elementfield<VR::NI>(0xffffffff);
//   dat2[{0x0008, 0x0104}] = dicom::data::attribute::make_elementfield<VR::LO>(4, "mwo");
//   dat2[{0xfffe, 0xe00d}] = dicom::data::attribute::make_elementfield<VR::NI>();
//   dat3[dicom::data::attribute::SequenceDelimitationItem] = dicom::data::attribute::make_elementfield<VR::NI>();
//   seq[{0x0032, 0x1064}] = dicom::data::attribute::make_elementfield<VR::SQ>(0xffffffff, {dat, dat2, dat3});


   command[AffectedSOPInstanceUID] = dicom::data::attribute::make_elementfield<VR::UI>("111111");
   command[MoveOriginatorApplicationEntityTitle] = dicom::data::attribute::make_elementfield<VR::AE>("move22");
   command[MoveOriginatorMessageID] = dicom::data::attribute::make_elementfield<VR::US>(1);

   pm->send_response({dataset::DIMSE_SERVICE_GROUP::C_STORE_RQ, command, senddata});

}
