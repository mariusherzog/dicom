#include "transfer_processor.hpp"

#include "attribute_field_coder.hpp"
#include "../attributedata/dataset_iterator.hpp"

Itransfer_processor::~Itransfer_processor()
{
}


commandset_processor::commandset_processor(dictionary_dyn& dict):
   dict {dict}
{
}

std::vector<unsigned char> commandset_processor::deserialize(commandset_data data) const
{
   std::vector<unsigned char> stream;
   for (dataset_iterator it = data.begin(); it != data.end(); ++it) {
      auto attr = *it;
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
      VR repr;
      try {
         repr = dict.lookup(tag.group_id, tag.element_id).vr;
      } catch (...) {
         repr = VR::SQ;
      }

      if (repr == VR::SQ) {
         if (value_len == 0xffff) {

         } else {
            commandset_data nested = serialize({data.begin()+pos, data.begin()+pos+value_len});
            cmd.insert(make_elementfield<VR::SQ>(tag.group_id, tag.element_id, value_len, nested));
         }
      }

      elementfield e = encode_little_endian(data, tag, value_len, repr, pos);
      pos += value_len;
      cmd.insert(e);
   }
   return cmd;
}
