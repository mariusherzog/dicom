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

using handlermap = std::map<dicom::data::dataset::DIMSE_SERVICE_GROUP,
std::function<void(dicom::network::dimse::dimse_pm* pm, dicom::data::dataset::commandset_data cdata, std::unique_ptr<dicom::data::dataset::iod> data)>>;

class storage_scu_thread
{
   public:
      storage_scu_thread(queryretrieve_scp& qr_scp,
                         dicom::data::dataset::commandset_data cmove_cmd,
                         dicom::network::dimse::dimse_pm* cfind_pm,
                         dicom::data::dictionary::dictionary& dict):
         qr_scp {qr_scp},
         cmove_cmd {cmove_cmd},
         cfind_pm {cfind_pm},
         dict {dict}
      {
         n = 0;
      }

      int n;

      void operator()()
      {
         storage_scu st
         {
            "QRSCP", "QRSCU", 4096, dict,
                  [this](storage_scu* st, dicom::data::dataset::commandset_data cmd, std::unique_ptr<dicom::data::dataset::iod> data)
                  {
                     cfind_pm->send_response({dicom::data::dataset::DIMSE_SERVICE_GROUP::C_MOVE_RSP, cmove_cmd, boost::none, 0xff00});
                     if (n >= 20)
                     {
                        st->release();
                        cfind_pm->send_response({dicom::data::dataset::DIMSE_SERVICE_GROUP::C_MOVE_RSP, cmove_cmd, boost::none, 0x0000});
                     }
                     ++n;
                  }
         };
         st.run();
      }

   private:
      queryretrieve_scp& qr_scp;
      dicom::data::dataset::commandset_data cmove_cmd;
      dicom::network::dimse::dimse_pm* cfind_pm;
      dicom::data::dictionary::dictionary& dict;
};

queryretrieve_scp::queryretrieve_scp(std::string calling_ae, std::string called_ae,
                                     int max_message_len, dicom::data::dictionary::dictionary& dict,
                                     std::function<void(queryretrieve_scp*, dicom::data::dataset::commandset_data, std::unique_ptr<dicom::data::dataset::iod>)> handler):
   dict {dict},
   sop_class { "1.2.840.10008.5.1.4.1.2.1.2", handlermap {
{dataset::DIMSE_SERVICE_GROUP::C_MOVE_RQ, [this](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) { this->handle_cfind(pm, command, std::move(data)); }}
               }  },
   assoc_def
   {
      calling_ae, called_ae, {
         {sop_class, {"1.2.840.10008.1.2"}, dimse::association_definition::DIMSE_MSG_TYPE::RESPONSE}
      }, max_message_len
   },
   scp {dict, 1113},
   dimse_pm {scp, assoc_def, dict},
   storage_thread {nullptr},
   handler {handler}
{

}

queryretrieve_scp::~queryretrieve_scp()
{
   storage_thread->join();
}

void queryretrieve_scp::cstore_callback(storage_scu* st, dicom::data::dataset::commandset_data cmd, std::unique_ptr<dicom::data::dataset::iod> data)
{
   std::cout << "##sent##\n";
}

void queryretrieve_scp::handle_cfind(dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data)
{
   handler(this, command, std::move(data));


   // loop through result set
   dicom::data::dataset::iod resp;
   //resp[{0x0008,0x0005}] = attribute::make_elementfield<VR::CS>("ISO_IR 6");
   //resp[{0x0010,0x0010}] = attribute::make_elementfield<VR::PN>("meow");

   if (storage_thread.get()) {
      storage_thread->join();
   }

   storage_operation.reset(new storage_scu_thread {*this, command, pm, dict});
   storage_thread.reset(new std::thread {*storage_operation});
}

dicom::network::upperlayer::scp& queryretrieve_scp::get_scp()
{
   return scp;
}

void queryretrieve_scp::run()
{
   dimse_pm.run();
}

void queryretrieve_scp::send_image(dataset::iod data)
{

}
