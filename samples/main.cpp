#include <iostream>
#include <chrono>
#include <tuple>

#include "libdicompp/all.hpp"

// todo remove
#include "../source/pixeldata/frame_extractors/uncompressed_ow.hpp"
#include "../source/pixeldata/frame_extractors/encapsulated_jpeg_lossy.hpp"
#include "../source/pixeldata/frame_extractors/encapsulated_jpeg2000.hpp"

#include <boost/variant.hpp>



int main()
{
   dicom::util::log::init_log();

   using namespace dicom::data;
   using namespace dicom::data::attribute;
   using namespace dicom::data::dictionary;
   using namespace dicom::network;
   using namespace dicom::serviceclass;

   dicom::data::dictionary::dictionaries& dict = get_default_dictionaries();

//   {
//      {
//         dataset::iod dicm;
//         dicm[{0x0008, 0x0016}] = make_elementfield<VR::CS>("1.2.840.10008.5.1.4.1.1.7");
//         dicm[{0x0008, 0x0018}] = make_elementfield<VR::CS>("1.2.840.10008.25.25.25.1");
//         dicm[{0x0010, 0x0010}] = make_elementfield<VR::PN>("test^test");
//         dicom::filesystem::dicomfile file(dicm, dict);
//         std::fstream outfile("outfile.dcm", std::ios::out | std::ios::binary);
//         outfile << file;
//         outfile.flush();
//      }
//      {
         dataset::iod dicm;
         dicom::filesystem::dicomfile file(dicm, dict);
         std::fstream outfile("RG2_J2KR", std::ios::in | std::ios::binary);
         outfile >> file;
         std::cout << file.dataset() << std::flush;

         encapsulated_jpeg2000 frames(file.dataset());
         auto data = frames[0];
         auto& set = file.dataset();
         std::cout << set[{0x0020, 0x000e}].value<VR::UI>() << std::flush;
//         set[{0x0080, 0x0080}] = make_elementfield<VR::OB>({1, 9, 2, 65});

         std::fstream os("framedata.gray",  std::ios::out | std::ios::binary);
         std::ostreambuf_iterator<char> out {os};
         std::copy((char*)(&data[0]), ((char*)(&data[0]))+data.size()*2, out);
         //std::copy((char*)(&data[0]), ((char*)(&data[0]))+data.size(), out);

         std::fstream outfile2("outfile.dcm", std::ios::out | std::ios::binary);
         outfile2 << file;
         outfile2.flush();
         return EXIT_SUCCESS;
//      }
//   }


   dimse::SOP_class findrsp {"1.2.840.10008.5.1.4.31",
   { { dataset::DIMSE_SERVICE_GROUP::C_FIND_RQ,
      [](dimse::dimse_pm* pm, dataset::commandset_data command, std::unique_ptr<dataset::iod> data) {
         assert(data != nullptr);
         std::cout << "Received C_ECHO_RSP\n";
//         std::cout << *data;

         (*data)[{0x0008,0x4000}] = dicom::data::attribute::make_elementfield<VR::LT>("h\x12qej\x13");
         (*data)[{0x0018,0x1150}] = dicom::data::attribute::make_elementfield<VR::IS>("292w9292");

         pm->send_response({dataset::DIMSE_SERVICE_GROUP::C_FIND_RSP, command, *data, 0xff00});
         pm->send_response({dataset::DIMSE_SERVICE_GROUP::C_FIND_RSP, command, boost::none, 0x0000});
//         pm->release_association();
      }}}
   };




   try
   {

//      int n = 0;
//      queryretrieve_scp qr({"QRSCP", "QRSCU", "", 1113}, dict,
//                           [&n](queryretrieve_scp* st, dicom::data::dataset::commandset_data cmd, std::shared_ptr<dicom::data::dataset::iod> data) {
//         dataset::iod seq;
//         seq[{0x0010,0x0010}] = dicom::data::attribute::make_elementfield<VR::PN>("test");
//         ++n;
//         if (n < 15)
//            st->send_image(*data);
//         else
//            st->send_image(boost::none);

//      });
//      qr.set_move_destination("MOVESCU", {"QRSCP", "QRSCU", "localhost", 1114});
//      qr.run();

      storage_scp store({"STORAGESCU", "STORAGESCP", "", 1113}, dict, [&dict](storage_scp* st, dicom::data::dataset::commandset_data cmd, std::unique_ptr<dicom::data::dataset::iod> data)
      {
//         std::ofstream out("out", std::ios::binary);
//    std::cout << *data;
//         std::vector<unsigned short> imdata;
//         auto value_field = (*data)[{0x7fe0,0x0010}];
//         get_value_field<VR::OW>(value_field, imdata);
//         out.write((char*)imdata.data(), imdata.size()*sizeof(unsigned short));
//         out.flush();
         std::string sop_uid;
         get_value_field<VR::UI>(cmd[{0x0000, 0x1000}], sop_uid);

     dicom::filesystem::dicomfile file(*data, dict);
     file.set_transfer_syntax("1.2.840.10008.1.2.4.70");
     std::fstream outfile(sop_uid + ".dcm", std::ios::out | std::ios::binary);
     outfile << file;
     outfile.flush();
      });
      store.run();

//      int n = 0;
//      storage_scu store({"STORAGESCP", "STORAGESCU", "localhost", 1113}, dict,
//                        [&dict, &n](storage_scu* sc, dicom::data::dataset::commandset_data cmd, std::unique_ptr<dicom::data::dataset::iod> data)
//      {
//            if (n == 0) {
//               ++n;
//            }
//            else
//            sc->release();
//      });
//      store.set_store_data(file.dataset());
//      store.run();
   } catch (std::exception& ec) {
      std::cout << ec.what();
   }
}
