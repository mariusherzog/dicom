#include "dicomfile.hpp"

#include <iterator>

using namespace dicom::data::dataset;

namespace dicom
{

namespace filesystem
{

dicomfile::dicomfile(iod dataset, data::dictionary::dictionaries& dict):
   dataset_ {dataset},
   preamble {0},
   prefix {'D', 'I', 'C', 'M'},
   dict {dict},
   transfer_proc {new little_endian_explicit(dict)}
{

}

std::ostream& dicomfile::write_dataset(std::ostream &os)
{
   std::ostreambuf_iterator<char> out {os};
   std::copy(std::begin(preamble), std::end(preamble), out);
   std::copy(std::begin(prefix), std::end(prefix), out);

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


}

}
