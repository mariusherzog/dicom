#include "storage_scp.hpp"

#include "data/dataset/dataset_iterator.hpp"
#include "data/dictionary/dictionary_dyn.hpp"
#include "data/dictionary/datadictionary.hpp"
#include "data/dictionary/dictionary.hpp"
#include "data/attribute/constants.hpp"

#include "infrastructure/asio_tcp_connection_manager.hpp"

using namespace dicom::data;
using namespace dicom::data::attribute;
using namespace dicom::data::dictionary;
using namespace dicom::network;

namespace dicom
{

namespace serviceclass
{

storage_scp::storage_scp(connection endpoint,
                         dicom::data::dictionary::dictionary& dict,
                         std::function<void(storage_scp*, dicom::data::dataset::commandset_data, std::unique_ptr<dicom::data::dataset::iod>)> handler):
   cstore_sop {{dataset::DIMSE_SERVICE_GROUP::C_STORE_RQ, [this](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) { this->handle_cstore(pm, command, std::move(data)); }}},
   dict {dict},
   sop_classes
   {
      {"1.2.840.10008.5.1.4.1.1.1", cstore_sop},
      {"1.2.840.10008.5.1.4.1.1.7", cstore_sop},
      {"1.2.840.10008.5.1.4.1.1.1.2", cstore_sop},
      {"1.2.840.10008.5.1.4.1.1.2", cstore_sop},
      {"1.2.840.10008.5.1.4.1.1.4", cstore_sop}
   },
   assoc_def
   {
      endpoint.calling_ae, endpoint.called_ae,
      dimse::make_presentation_contexts(
               sop_classes,
               {"1.2.840.10008.1.2", "1.2.840.10008.1.2.1", "1.2.840.10008.1.2.2"},
               dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE),
   },
   infrstr_scp {endpoint.port, nullptr, nullptr},
   scp {infrstr_scp, dict},
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

}

}
