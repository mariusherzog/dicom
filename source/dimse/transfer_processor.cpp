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
      stream.insert(stream.end(), data.begin(), data.end());
   }
   return stream;
}

commandset_data commandset_processor::serialize(std::vector<unsigned char> data) const
{
}
