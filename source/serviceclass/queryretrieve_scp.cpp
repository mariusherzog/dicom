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
                         dicom::data::dataset::commandset_data cmove_cmd,
                         dicom::network::dimse::dimse_pm* cfind_pm,
                         std::function<boost::optional<dicom::data::dataset::iod>()> cmove_handler,
                         dicom::data::dictionary::dictionary& dict):
         qr_scp {qr_scp},
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
            {"QRSCP", "QRSCU", "localhost", 1114}, dict,
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
      dicom::data::dataset::commandset_data cmove_cmd;
      dicom::network::dimse::dimse_pm* cfind_pm;
      std::function<boost::optional<dicom::data::dataset::iod>()> cmove_handler;
      dicom::data::dictionary::dictionary& dict;
};

queryretrieve_scp::queryretrieve_scp(connection endpoint, dicom::data::dictionary::dictionary& dict,
                                     std::function<void(queryretrieve_scp*, dataset::commandset_data, std::shared_ptr<dataset::iod>)> handler):
   dict {dict},
   sop_class { "1.2.840.10008.5.1.4.1.2.1.2", handlermap {
{dataset::DIMSE_SERVICE_GROUP::C_MOVE_RQ, [this](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) { this->handle_cfind(pm, command, std::move(data)); }}
               }  },
   assoc_def
   {
      endpoint.calling_ae, endpoint.called_ae, {
         {sop_class, {"1.2.840.10008.1.2"}, dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE}
      }
   },
   scp {dict, endpoint.port},
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

   storage_operation.reset(new storage_scu_thread {*this, command, pm, cmove_handler, dict});
   storage_thread.reset(new std::thread {*storage_operation});
}

boost::optional<dicom::data::dataset::iod> queryretrieve_scp::handle_cmove(queryretrieve_scp *scp, dataset::commandset_data command, std::shared_ptr<dataset::iod> data)
{
   handler(scp, command, data);
   return response_data;
}

dicom::network::upperlayer::scp& queryretrieve_scp::get_scp()
{
   return scp;
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

