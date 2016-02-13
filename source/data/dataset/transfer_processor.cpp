#include "transfer_processor.hpp"

#include "data/attribute/attribute_field_coder.hpp"
#include "dataset_iterator.hpp"

namespace dicom
{

namespace data
{

namespace dataset
{

using namespace attribute;

Itransfer_processor::~Itransfer_processor()
{
}

/**
 * @brief find_enclosing is used to determine the size of the nested set if it
 *        is not explicitly specified.
 * @param data serialized dataset
 * @param beg first element
 * @param dict dictionary for the tag lookup
 * @return size of the nested set
 */
static std::size_t find_enclosing(std::vector<unsigned char> data, std::size_t beg, dictionary::dictionary_dyn& dict)
{
   std::size_t pos = beg;
   int nested_sets = 0;
   while (pos < data.size()) {
      elementfield::tag_type tag = decode_tag_little_endian(data, pos);
      if (tag == elementfield::tag_type {0xfffe, 0xe0dd}
          && nested_sets-- == 0) {
         pos += 8;
         break;
      }
      pos += 4;
      std::size_t value_len = decode_len_little_endian(data, pos);
      pos += 4;
      VR repr = dict.lookup(tag).vr;

      if (repr == VR::SQ) {
         nested_sets++;
      }

      value_len = value_len == 0xffff ? find_enclosing(data, pos, dict) : value_len;
      pos += value_len;

   }
   return pos-beg;
}

commandset_processor::commandset_processor(dictionary::dictionary_dyn& dict):
   dict(dict)
{
}

std::vector<unsigned char> commandset_processor::serialize(commandset_data data) const
{
   std::vector<unsigned char> stream;
   for (const auto attr : dataset_iterator_adaptor(data)) {
      VR repr;
      if (attr.value_rep.is_initialized()) {
         repr = attr.value_rep.get();
      } else {
         repr = dict.lookup(attr.tag).vr;
      }
      auto data = encode_little_endian(attr, repr);
      auto tag = encode_tag_little_endian(attr.tag);
      auto len = encode_len_little_endian(attr.value_len);
      stream.insert(stream.end(), tag.begin(), tag.end());
      stream.insert(stream.end(), len.begin(), len.end());
      stream.insert(stream.end(), data.begin(), data.end());
   }
   return stream;
}

commandset_data commandset_processor::deserialize(std::vector<unsigned char> data) const
{
   commandset_data cmd;

   std::size_t pos = 0;
   while (pos < data.size()) {
      elementfield::tag_type tag = decode_tag_little_endian(data, pos);
      pos += 4;
      std::size_t value_len = decode_len_little_endian(data, pos);
      pos += 4;

      if (tag != elementfield::tag_type {0xfffe, 0xe0dd}) {
         VR repr = dict.lookup(tag).vr;

         if (repr == VR::SQ) {
            value_len = value_len == 0xffff ? find_enclosing(data, pos, dict) : value_len;
            commandset_data nested = deserialize({data.begin()+pos, data.begin()+pos+value_len});
            cmd[tag] = make_elementfield<VR::SQ>(tag.group_id, tag.element_id, value_len, nested);
         }

         elementfield e = decode_little_endian(data, tag, value_len, repr, pos);
         pos += value_len;
         cmd[tag] = e;
      } else {
         pos += value_len;
         cmd[tag] = make_elementfield<VR::NN>(tag.group_id, tag.element_id);
      }
   }
   return cmd;
}

}

}

}
