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

namespace dicom
{

namespace serviceclass
{

storage_scu::storage_scu(connection endpoint,
                         dicom::data::dictionary::dictionaries& dict,
                         std::function<void(storage_scu*, dataset::commandset_data, std::unique_ptr<dataset::iod>)> handler):
   cstore_req {{dataset::DIMSE_SERVICE_GROUP::C_STORE_RQ, [this](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) { this->send_store_request(pm, command, std::move(data)); }}},
   cstore_resp {{dataset::DIMSE_SERVICE_GROUP::C_STORE_RSP, [this](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) { this->send_store_request(pm, command, std::move(data)); }}},
   sop_classes
   {
      {"1.2.840.10008.5.1.4.1.1.1", cstore_req}
   },
   sop_classes_response
   {
      {"1.2.840.10008.5.1.4.1.1.1", cstore_resp}
   },
   assoc_def
   {
      endpoint.calling_ae, endpoint.called_ae,
      dimse::make_presentation_contexts(
         sop_classes_response,
         {"1.2.840.10008.1.2", "1.2.840.10008.1.2.1", "1.2.840.10008.1.2.2"},
         dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE)
            + // concatenate
      dimse::make_presentation_contexts(
         sop_classes,
         {"1.2.840.10008.1.2", "1.2.840.10008.1.2.1", "1.2.840.10008.1.2.2"},
         dimse::association_definition::DIMSE_MSG_TYPE::INITIATOR)
   },
   initial_rq {assoc_def.get_initial_request()},
   infr_scu {endpoint.host, std::to_string(endpoint.port), nullptr, nullptr},
   scu {infr_scu, dict, initial_rq},
   dimse_pm {scu, assoc_def, dict},
   senddata {},
   handler {handler},
   do_release {false}
{

}

storage_scu::~storage_scu()
{
   // close
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

void storage_scu::run()
{
   dimse_pm.run();
}

void storage_scu::send_store_request(dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data)
{
   assert(data == nullptr);

   std::cout << "Send C_STORE_RQ\n";
   dataset::dataset_type dat, dat2, dat3;
   dataset::iod seq;


   command[AffectedSOPInstanceUID] = dicom::data::attribute::make_elementfield<VR::UI>("111111");
   command[MoveOriginatorApplicationEntityTitle] = dicom::data::attribute::make_elementfield<VR::AE>("move22");
   command[MoveOriginatorMessageID] = dicom::data::attribute::make_elementfield<VR::US>(1);

   handler(this, command, std::move(data));

   // handler requested release
   if (do_release) {
      pm->release_association();
      return;
   } else {
      pm->send_response({dataset::DIMSE_SERVICE_GROUP::C_STORE_RQ, command, senddata});
   }
}


}

}
