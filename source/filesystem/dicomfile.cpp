#include "dicomfile.hpp"

#include <iterator>

#include "data/attribute/constants.hpp"
#include "util/uid.hpp"

using namespace dicom::data::dataset;

namespace
{

std::size_t le_char_to_16b(unsigned char* bs)
{
   std::size_t sz = 0;
   sz |= (static_cast<std::size_t>(bs[3]) << 24);
   sz |= (static_cast<std::size_t>(bs[2]) << 16);
   sz |= (static_cast<std::size_t>(bs[1]) << 8);
   sz |= (static_cast<std::size_t>(bs[0]));
   return sz;
}

}

namespace dicom
{

namespace filesystem
{

using namespace dicom::data::attribute;
using namespace util::log;

dicomfile::dicomfile(iod& dataset, data::dictionary::dictionaries& dict):
   dataset_ {dataset},
   preamble {0},
   prefix {'D', 'I', 'C', 'M'},
   dict {dict},
   metaheader_proc {new little_endian_explicit(dict)},
   transfer_proc {new little_endian_explicit(dict)},
   logger {"dicomfile"}
{
}

std::ostream& dicomfile::write_dataset(std::ostream &os)
{
   BOOST_LOG_SEV(logger, trace) << "Starting to write to stream";

   std::ostreambuf_iterator<char> out {os};
   std::copy(std::begin(preamble), std::end(preamble), out);
   std::copy(std::begin(prefix), std::end(prefix), out);

   create_filemetaheader();

   auto headerbytes = metaheader_proc->serialize(filemetaheader);
   std::copy(std::begin(headerbytes), std::end(headerbytes), out);

   BOOST_LOG_SEV(logger, trace) << "Finished writing file meta header";

   BOOST_LOG_SEV(logger, info) << "Starting to write dataset with transfer syntax: "
                               << transfer_proc->get_transfer_syntax();

   auto bytes = transfer_proc->serialize(dataset_);
   std::copy(std::begin(bytes), std::end(bytes), out);

   BOOST_LOG_SEV(logger, trace) << "Finished writing dataset";

   return os;
}

std::istream& dicomfile::read_dataset(std::istream &is)
{   
   BOOST_LOG_SEV(logger, trace) << "Starting to read from stream";

   using namespace dicom::data::attribute;
   std::istreambuf_iterator<char> in(is);
   std::copy_n(in, 128, std::begin(preamble));
   std::advance(in, 1);
   std::copy_n(in, 4, &prefix[0]);
   std::advance(in, 1);

   unsigned char tag[4];
   std::copy_n(in, 4, std::begin(tag));
   std::advance(in, 1);
   unsigned char vr[2];
   std::copy_n(in, 2, std::begin(vr));
   std::advance(in, 1);
   unsigned char length[2];
   std::copy_n(in, 2, std::begin(length));
   std::advance(in, 1);

   unsigned char value[4];
   std::copy_n(in, 4, std::begin(value));
   std::advance(in, 1);

   size_t metaheader_length = le_char_to_16b(value);

   std::vector<unsigned char> metaheader_bytes;
   std::copy(std::begin(tag), std::end(tag), std::back_inserter(metaheader_bytes));
   std::copy(std::begin(vr), std::end(vr), std::back_inserter(metaheader_bytes));
   std::copy(std::begin(length), std::end(length), std::back_inserter(metaheader_bytes));
   std::copy(std::begin(value), std::end(value), std::back_inserter(metaheader_bytes));
   std::copy_n(in, metaheader_length, std::back_inserter(metaheader_bytes));
   std::advance(in, 1);

   this->filemetaheader = metaheader_proc->deserialize(metaheader_bytes);


   BOOST_LOG_SEV(logger, trace) << "Deserialized meta header\n"
                                << filemetaheader;

   std::string transfer_syntax = "";
   try {
      get_value_field<VR::UI>(filemetaheader[{0x0002, 0x0010}], transfer_syntax);
      BOOST_LOG_SEV(logger, info) << "Transfer syntax of dataset is " << transfer_syntax;
      transfer_proc = make_transfer_processor(transfer_syntax, dict);
   } catch (std::exception& err) {
      BOOST_LOG_SEV(logger, error) << "Error creating the transfer processor for transfer syntax: "
                                   << transfer_syntax << "\n"
                                   << err.what();
      throw;
   }

   auto current_pos = is.tellg();
   is.seekg(0, std::ios::end);
   std::vector<unsigned char> bytes;
   std::size_t rest = is.tellg()-current_pos;
   bytes.resize(rest);
   is.seekg(current_pos, std::ios::beg);
   is.read((char*)&bytes[0], rest);

   dataset_ = transfer_proc->deserialize(bytes);

   BOOST_LOG_SEV(logger, trace) << "Finished reading dataset";

   return is;
}

void dicomfile::set_transfer_syntax(std::string transfer_syntax)
{
   transfer_proc = make_transfer_processor(transfer_syntax, dict);
   filemetaheader[{0x0002, 0x0010}] = make_elementfield<VR::UI>(transfer_proc->get_transfer_syntax());
}

iod& dicomfile::dataset()
{
   return dataset_;
}


std::ostream& operator<<(std::ostream& os, dicomfile& dicom)
{
   return dicom.write_dataset(os);
}

std::istream& operator>>(std::istream& is, dicomfile& dicom)
{
   return dicom.read_dataset(is);
}

void dicomfile::create_filemetaheader()
{
   dicom::util::uid uids;
   filemetaheader[{0x0002, 0x0001}] = make_elementfield<VR::OB>({0x00, 0x01});
   filemetaheader[{0x0002, 0x0003}] = make_elementfield<VR::UI>(uids.generate_uid());
   filemetaheader[{0x0002, 0x0010}] = make_elementfield<VR::UI>(transfer_proc->get_transfer_syntax());
   filemetaheader[{0x0002, 0x0012}] = make_elementfield<VR::UI>(uids.generate_uid());
   filemetaheader[{0x0002, 0x0013}] = make_elementfield<VR::SH>("libdicompp");

   std::string sop_class;
   get_value_field<VR::UI>(dataset_[{0x0008, 0x0016}], sop_class);
   filemetaheader[{0x0002, 0x0002}] = make_elementfield<VR::UI>(sop_class);

   if (filemetaheader.find({0x0002, 0x0000}) != std::end(filemetaheader)) {
      filemetaheader.erase(filemetaheader.find({0x0002, 0x0000}));
   }
   //auto metaheader_size = dataset_size(filemetaheader, true);
   auto headerbytes = metaheader_proc->serialize(filemetaheader);
   filemetaheader[{0x0002, 0x0000}] = make_elementfield<VR::UL>(headerbytes.size());
}


}

}
