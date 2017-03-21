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



queryretrieve_scp::queryretrieve_scp(std::string calling_ae, std::string called_ae,
                                     int max_message_len, dicom::data::dictionary::dictionary& dict,
                                     std::function<void(queryretrieve_scp*, dicom::data::dataset::commandset_data, std::unique_ptr<dicom::data::dataset::iod>)> handler):
   /*cstore {"QRSCP", "QRSCU", max_message_len, dict, [this](storage_scu* st, dicom::data::dataset::commandset_data cmd, std::unique_ptr<dicom::data::dataset::iod> data) { this->cstore_callback(st, cmd, std::move(data)); } },*/
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
   handler {handler}
{

}

void queryretrieve_scp::cstore_callback(storage_scu* st, dicom::data::dataset::commandset_data cmd, std::unique_ptr<dicom::data::dataset::iod> data)
{
   std::cout << "##sent##\n";
}

void queryretrieve_scp::handle_cfind(dimse::dimse_pm *pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data)
{
   handler(this, command, std::move(data));

//   if (do_release) {
//      pm->release_association();
//   }

   //cstore.get_scu().run();


   // loop through result set
   dicom::data::dataset::iod resp;
   //resp[{0x0008,0x0005}] = attribute::make_elementfield<VR::CS>("ISO_IR 6");
   resp[{0x0010,0x0010}] = attribute::make_elementfield<VR::PN>("meow");

   storage_scu st {"QRSCP", "QRSCU", 4096, dict, [this, command, pm](storage_scu* st, dicom::data::dataset::commandset_data cmd, std::unique_ptr<dicom::data::dataset::iod> data) {
         std::cout << "#sent#" << std::flush;
         pm->send_response({dicom::data::dataset::DIMSE_SERVICE_GROUP::C_MOVE_RSP, command, boost::none, 0xff00});
      }
                  };

//   st.send_next_request(resp);


      st.get_scu().run();


      pm->send_response({dicom::data::dataset::DIMSE_SERVICE_GROUP::C_MOVE_RSP, command, boost::none, 0x00ff});
      pm->send_response({dicom::data::dataset::DIMSE_SERVICE_GROUP::C_MOVE_RSP, command, boost::none, 0x0000});
}

dicom::network::upperlayer::scp& queryretrieve_scp::get_scp()
{
   return scp;
}

void queryretrieve_scp::send_image(dataset::iod data)
{

}
