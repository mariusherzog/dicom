#include "dicomfile.hpp"

#include <iterator>

#include "data/attribute/constants.hpp"

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

dicomfile::dicomfile(iod dataset, data::dictionary::dictionaries& dict):
   dataset_ {dataset},
   preamble {0},
   prefix {'D', 'I', 'C', 'M'},
   dict {dict},
   transfer_proc {new dicom::data::dataset::encapsulated(dict)}
{
   create_filemetaheader();
}

std::ostream& dicomfile::write_dataset(std::ostream &os)
{
   std::ostreambuf_iterator<char> out {os};
   std::copy(std::begin(preamble), std::end(preamble), out);
   std::copy(std::begin(prefix), std::end(prefix), out);

   auto headerbytes = transfer_proc->serialize(filemetaheader);
   std::copy(std::begin(headerbytes), std::end(headerbytes), out);

   auto bytes = transfer_proc->serialize(dataset_);
   std::copy(std::begin(bytes), std::end(bytes), out);

   return os;
}

std::istream& dicomfile::read_dataset(std::istream &is)
{
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

   this->filemetaheader = transfer_proc->deserialize(metaheader_bytes);

   std::string transfer_syntax;
   get_value_field<VR::UI>(filemetaheader[{0x0002, 0x0010}], transfer_syntax);

   if (transfer_syntax == "1.2.840.10008.1.2.4.70") {
      transfer_proc = std::unique_ptr<transfer_processor>(new data::dataset::encapsulated{dict});
   }

   std::vector<unsigned char> bytes(in, std::istreambuf_iterator<char>());
   dataset_ = transfer_proc->deserialize(bytes);
   return is;
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
   filemetaheader[{0x0002, 0x0001}] = make_elementfield<VR::OB>({0x00, 0x01});
   filemetaheader[{0x0002, 0x0002}] = make_elementfield<VR::UI>("1.1.1.1");
   filemetaheader[{0x0002, 0x0003}] = make_elementfield<VR::UI>("1.1.1.1");
   filemetaheader[{0x0002, 0x0010}] = make_elementfield<VR::UI>(transfer_proc->get_transfer_syntax());
   filemetaheader[{0x0002, 0x0012}] = make_elementfield<VR::UI>("1.1.1.1");

   //auto metaheader_size = dataset_size(filemetaheader, true);
   auto headerbytes = transfer_proc->serialize(filemetaheader);
   filemetaheader[{0x0002, 0x0000}] = make_elementfield<VR::UL>(headerbytes.size());
}


}

}
