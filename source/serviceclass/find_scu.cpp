#include "find_scu.hpp"

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

find_scu::find_scu(dicom::network::connection endpoint,
                   dicom::data::dictionary::dictionaries& dict,
                   std::function<void(find_scu*, dicom::data::dataset::commandset_data, std::unique_ptr<dicom::data::dataset::iod>)> handler):
   cfind_req {{dataset::DIMSE_SERVICE_GROUP::C_FIND_RQ, [this](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) { this->send_find_request(pm, command, std::move(data)); }}},
   cfind_resp {{dataset::DIMSE_SERVICE_GROUP::C_FIND_RSP, [this](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) { this->handle_find_response(pm, command, std::move(data)); }}},
   sop_classes
   {
      {"1.2.840.10008.5.1.4.1.2.1.1", cfind_req},
      {"1.2.840.10008.5.1.4.1.2.2.1", cfind_req}
   },
   sop_classes_response
   {
      {"1.2.840.10008.5.1.4.1.2.1.1", cfind_resp},
      {"1.2.840.10008.5.1.4.1.2.2.1", cfind_resp}
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
   infr_scu {endpoint.host, std::to_string(endpoint.port)},
   scu {infr_scu, dict, initial_rq},
   dimse_pm {scu, assoc_def, dict},
   handler {handler}
{

}

void find_scu::set_request(dataset::iod request)
{
   sendrequest = request;
   scu.accept_new();
}

void find_scu::run()
{
   dimse_pm.run();
}

find_scu::~find_scu()
{

}

void find_scu::send_find_request(dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod>)
{
   pm->send_response({dataset::DIMSE_SERVICE_GROUP::C_FIND_RQ, command, sendrequest});
}

void find_scu::handle_find_response(dimse::dimse_pm*, dataset::commandset_data cs, std::unique_ptr<dataset::iod> data)
{
   handler(this, cs, std::move(data));
}


}

}

