#include "transfer_processor.hpp"

#include "attribute_field_coder.hpp"

Itransfer_processor::~Itransfer_processor()
{
}


commandset_processor::commandset_processor(dictionary_dyn& dict):
   dict {dict}
{
}

std::vector<unsigned char> commandset_processor::deserialize(commandset_data data) const
{
   /** @todo nested attributes */
   std::vector<unsigned char> stream;
   for (elementfield attr : data) {
      VR repr;
      if (attr.value_rep.is_initialized()) {
         repr = attr.value_rep.get();
      } else {
         repr = dict.lookup(attr.tag.group_id, attr.tag.element_id).vr;
      }
      auto data = decode_little_endian(attr, repr);
      auto tag = decode_tag_little_endian(attr.tag);
      auto len = decode_len_little_endian(attr.value_len);
      stream.insert(stream.end(), tag.begin(), tag.end());
      stream.insert(stream.end(), len.begin(), len.end());
      stream.insert(stream.end(), data.begin(), data.end());
   }
   return stream;
}

commandset_data commandset_processor::serialize(std::vector<unsigned char> data) const
{
   /** @todo nested attributes */
   commandset_data cmd;

   std::size_t pos = 0;
   while (pos < data.size()) {
      elementfield::tag_type tag = encode_tag_little_endian(data, pos);
      pos += 4;
      std::size_t value_len = encode_len_little_endian(data, pos);
      pos += 4;
      VR repr = dict.lookup(tag.group_id, tag.element_id).vr;
      elementfield e = encode_little_endian(data, tag, value_len, repr, pos);
      pos += value_len;
      cmd.insert(e);
   }
   return cmd;
}
