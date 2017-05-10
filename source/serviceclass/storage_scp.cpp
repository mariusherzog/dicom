#include "storage_scp.hpp"

#include "data/dataset/dataset_iterator.hpp"
#include "data/dictionary/dictionary_dyn.hpp"
#include "data/dictionary/datadictionary.hpp"
#include "data/dictionary/dictionary.hpp"
#include "data/attribute/constants.hpp"

using namespace dicom::data;
using namespace dicom::data::attribute;
using namespace dicom::data::dictionary;
using namespace dicom::network;

storage_scp::storage_scp(std::string calling_ae, std::string called_ae,
                         int max_message_len, dicom::data::dictionary::dictionary& dict,
                         std::function<void(storage_scp*, dicom::data::dataset::commandset_data, std::unique_ptr<dicom::data::dataset::iod>)> handler):
   dict {dict},
   sop_class { "1.2.840.10008.5.1.4.1.1.7", handlermap {
{dataset::DIMSE_SERVICE_GROUP::C_STORE_RQ, [this](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) { this->handle_cstore(pm, command, std::move(data)); }}
               }  },
   assoc_def
   {
      calling_ae, called_ae, {
         {sop_class, {"1.2.840.10008.1.2"}, dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE}
      }, max_message_len
   },
   scp {dict, 1113},
   dimse_pm {scp, assoc_def, dict},
   handler {handler}
{

}

storage_scp::~storage_scp()
{
}

void storage_scp::run()
{
   dimse_pm.run();
}

void storage_scp::handle_cstore(dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data)
{
   handler(this, command, std::move(data));

   pm->send_response({dataset::DIMSE_SERVICE_GROUP::C_STORE_RSP, command, boost::none, 0x0000});
}