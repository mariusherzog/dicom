#include "queryretrieve_scp.hpp"

#include <functional>
#include <utility>
#include <memory>

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

using handlermap = std::map<dicom::data::dataset::DIMSE_SERVICE_GROUP,
std::function<void(dicom::network::dimse::dimse_pm* pm, dicom::data::dataset::commandset_data cdata, std::unique_ptr<dicom::data::dataset::iod> data)>>;


class storage_scu_thread
{
   public:
      storage_scu_thread(queryretrieve_scp& qr_scp,
                         connection move_destination,
                         dicom::data::dataset::commandset_data cmove_cmd,
                         dicom::network::dimse::dimse_pm* cfind_pm,
                         std::function<boost::optional<dicom::data::dataset::iod>()> cmove_handler,
                         dicom::data::dictionary::dictionaries& dict):
         qr_scp {qr_scp},
         move_destination {move_destination},
         cmove_cmd {cmove_cmd},
         cfind_pm {cfind_pm},
         cmove_handler {cmove_handler},
         dict {dict}
      {
      }

      void operator()()
      {
         storage_scu st
         {
            move_destination, dict,
                  [this](storage_scu* st, dicom::data::dataset::commandset_data cmd, std::unique_ptr<dicom::data::dataset::iod> data)
                  {
                     auto response = cmove_handler();
                     if (response.is_initialized()) {
                        st->set_store_data(*response);
                        cfind_pm->send_response({dicom::data::dataset::DIMSE_SERVICE_GROUP::C_MOVE_RSP, cmove_cmd, boost::none, 0xff00});
                     } else {
                        st->release();
                        cfind_pm->send_response({dicom::data::dataset::DIMSE_SERVICE_GROUP::C_MOVE_RSP, cmove_cmd, boost::none, 0x0000});
                     }
                  }
         };
         st.run();
      }

   private:
      queryretrieve_scp& qr_scp;
      connection move_destination;
      dicom::data::dataset::commandset_data cmove_cmd;
      dicom::network::dimse::dimse_pm* cfind_pm;
      std::function<boost::optional<dicom::data::dataset::iod>()> cmove_handler;
      dicom::data::dictionary::dictionaries& dict;
};

queryretrieve_scp::queryretrieve_scp(connection endpoint, dicom::data::dictionary::dictionaries& dict,
                                     std::function<void(queryretrieve_scp*, dataset::commandset_data, std::shared_ptr<dataset::iod>)> handler):
   cmove_sop {{ dataset::DIMSE_SERVICE_GROUP::C_MOVE_RQ, [this](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) { this->handle_cfind(pm, command, std::move(data)); }} },
   dict {dict},
   sop_classes {
      {"1.2.840.10008.5.1.4.1.2.1.2", cmove_sop},
      {"1.2.840.10008.5.1.4.1.2.2.2", cmove_sop},
      {"1.2.840.10008.5.1.4.1.2.3.2", cmove_sop},
      {"1.2.840.10008.5.1.4.38.3", cmove_sop}
   },
   assoc_def {
      endpoint.calling_ae, endpoint.called_ae, {
         dimse::make_presentation_contexts(
                  sop_classes,
                  {"1.2.840.10008.1.2", "1.2.840.10008.1.2.1", "1.2.840.10008.1.2.2"},
                  dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE),
      }
   },
   infrstr_scp {endpoint.port, nullptr, nullptr},
   scp {infrstr_scp, dict},
   dimse_pm {scp, assoc_def, dict},
   storage_thread {nullptr},
   handler {handler}
{

}

queryretrieve_scp::~queryretrieve_scp()
{
   storage_thread->join();
}


void queryretrieve_scp::handle_cfind(dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data)
{
   filter_data = std::move(data);

   // wrapper around handler which returns data
   auto cmove_handler = std::bind(&queryretrieve_scp::handle_cmove, this, this, command, filter_data);

   if (storage_thread.get()) {
      storage_thread->join();
   }

   std::string move_dest;
   get_value_field<VR::AE>(command.at({0x0000,0x0600}), move_dest);
   move_dest.erase(std::find_if(move_dest.rbegin(), move_dest.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), move_dest.end());
   auto move_destination = move_destinations[move_dest];

   storage_operation.reset(new storage_scu_thread {*this, move_destination, command, pm, cmove_handler, dict});
   storage_thread.reset(new std::thread {*storage_operation});
}

boost::optional<dicom::data::dataset::iod> queryretrieve_scp::handle_cmove(queryretrieve_scp *scp, dataset::commandset_data command, std::shared_ptr<dataset::iod> data)
{
   handler(scp, command, data);
   return response_data;
}

void queryretrieve_scp::set_move_destination(std::string ae, connection conn)
{
   move_destinations[ae] = conn;
}

void queryretrieve_scp::run()
{
   dimse_pm.run();
}

void queryretrieve_scp::send_image(boost::optional<dataset::iod> data)
{
   response_data = data;
}

}

}

