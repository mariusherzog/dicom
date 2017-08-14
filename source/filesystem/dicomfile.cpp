#include "dicomfile.hpp"

using namespace dicom::data::dataset;

namespace dicom
{

namespace filesystem
{

dicomfile::dicomfile(iod dataset, data::dictionary::dictionary& dict):
   dataset {dataset},
   preamble {0},
   prefix {'D', 'I', 'C', 'M'},
   dict {dict},
   transfer_proc {new little_endian_explicit(dict)}
{

}

std::ostream& dicomfile::write_dataset(std::ostream &os)
{
   std::ostream_iterator<unsigned char> out {os};
   std::copy(std::begin(preamble), std::end(preamble), out);
   std::copy(std::begin(prefix), std::end(prefix), out);

   auto bytes = transfer_proc->serialize(dataset);
   std::copy(std::begin(bytes), std::end(bytes), out);

   return os;
}

std::ostream& operator<<(std::ostream& os, dicomfile& dicom)
{
   return dicom.write_dataset(os);
}


}

}
