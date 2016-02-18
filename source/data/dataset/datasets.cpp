#include "datasets.hpp"

#include <iostream>
#include <iomanip>

#include "dataset_iterator.hpp"
#include "data/dictionary/dictionary.hpp"
#include "data/dictionary/dictionary_entry.hpp"

namespace dicom
{

namespace data
{

namespace dataset
{


using namespace attribute;


std::ostream& operator<<(std::ostream& os, const dataset_type& data)
{

   int depth = 0;
   for (const auto attr : dataset_iterator_adaptor(data)) {
      if (attr.first == elementfield::tag_type {0xfffe, 0xe0dd}) {
         depth--;
      }
      if (attr.second.value_rep == VR::SQ) {
         depth++;
      }


      std::fill_n(std::ostream_iterator<char>(os), depth, '\t');
      os << attr.first << " ";
      if (attr.second.value_rep.is_initialized()) {
         os << dictionary::dictionary_entry::vr_of_string.right.at(attr.second.value_rep.get());
      } else {
         os << "NN (unknown)";
      }
      os << " " << attr.second.value_len << "\t\t";
      attr.second.value_field->print(os);
      std::cout << "\n";
   }

   return os;
}

std::size_t dataset_size(dataset_type data, bool explicitvr)
{
   return std::accumulate(data.begin(), data.end(), 0,
      [explicitvr](int acc, const std::pair<const elementfield::tag_type, elementfield>& attr) {
      return acc += attr.second.value_len + 4 + 4
            + (explicitvr ? 2 : 0);
   });
}

}

}

}
