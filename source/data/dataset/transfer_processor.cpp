#include "transfer_processor.hpp"

#include <stack>

#include "data/attribute/attribute_field_coder.hpp"
#include "data/attribute/constants.hpp"
#include "data/dictionary/dictionary_entry.hpp" // vr of string
#include "dataset_iterator.hpp"

namespace dicom
{

namespace data
{

namespace dataset
{

using namespace attribute;

transfer_processor::~transfer_processor()
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
static std::size_t find_enclosing(std::vector<unsigned char> data, std::size_t beg, dictionary::dictionary& dict)
{
   std::size_t pos = beg;
   int nested_sets = 0;
   while (pos < data.size()) {
      elementfield::tag_type tag = decode_tag_little_endian(data, pos);
      if (tag == SequenceDelimitationItem && nested_sets-- == 0) {
         pos += 8;
         break;
      }
      pos += 4;
      std::size_t value_len = decode_len_little_endian(data, pos);
      pos += 4;
      VR repr = dict.lookup(tag).vr[0];

      if (repr == VR::SQ) {
         nested_sets++;
      }

      value_len = value_len == 0xffff ? find_enclosing(data, pos, dict) : value_len;
      pos += value_len;

   }
   return pos-beg;
}

commandset_processor::commandset_processor(dictionary::dictionary& dict):
   transfer_processor {boost::optional<dictionary::dictionary&> {dict}, "", VR_TYPE::IMPLICIT}
{
}


dataset_type transfer_processor::deserialize(std::vector<unsigned char> data) const
{
   dataset_type dataset;
   std::vector<dataset_type> outerset {dataset};

   std::stack<std::vector<unsigned char>> current_data;
   std::stack<std::vector<dataset_type>> current_sequence;
   std::stack<std::size_t> positions;
   std::stack<std::pair<elementfield::tag_type, std::size_t>> lasttag;

   positions.push(0);
   current_sequence.push(outerset);
   current_data.push(data);
   while (current_data.size() > 0) {

      // if we are coming right out of the deserialization of a nested sequence
      // of items, add it to the last item deserialized before the nested sq.
      if (lasttag.size() > 0) {
         assert(current_sequence.size() > 1);
         auto tag = lasttag.top().first;
         auto size = lasttag.top().second;
         lasttag.pop();
         auto nested_seq = current_sequence.top();
         current_sequence.pop();
         current_sequence.top().back()[tag]
               = make_elementfield<VR::SQ>(size, nested_seq);
         positions.pop();
      }

      while (positions.top() < current_data.top().size()) {
         auto& pos = positions.top();
         assert(!current_sequence.top().empty());

         elementfield::tag_type tag = decode_tag_little_endian(current_data.top(), pos);
         pos += 4;
         std::size_t value_len;
         if (tag != SequenceDelimitationItem
             && tag != Item
             && tag != ItemDelimitationItem) {
            value_len = decode_len_little_endian(current_data.top(), pos);
         } else if (tag == Item) {
            value_len = decode_len_little_endian(current_data.top(), pos);
         } else {
            value_len = 0;
         }
         pos += 4;

         // Items and DelimitationItems do not have a VR or length field and are
         // to be treated separately.
         if (tag != SequenceDelimitationItem
             && tag != Item
             && tag != ItemDelimitationItem) {
            VR repr = dict.get().lookup(tag).vr[0];

            // if the current item is a sequence, push the nested serialized
            // data on the stack so it will be processed next. Store the current
            // state of the deserialization on appropriate stacks.
            if (repr == VR::SQ) {
               value_len = value_len == 0xffff ? find_enclosing(current_data.top(), pos, dict.get()) : value_len;
               current_data.push({current_data.top().begin()+pos, current_data.top().begin()+pos+value_len});
               current_sequence.push({dataset_type {}});
               positions.push(0);
               lasttag.push({tag, value_len});
            } else {
               elementfield e = deserialize_attribute(current_data.top(), value_len, repr, pos);
               current_sequence.top().back()[tag] = e;
            }
            pos += value_len;
         } else {
            // Put Items and respective DelimitationItems into the deserialized
            // set.
            if (tag == Item) {
               if (positions.top() > 8) {
                  current_sequence.top().back()[ItemDelimitationItem]
                        = make_elementfield<VR::NN>();
                  current_sequence.top().push_back(dataset_type {});
               }
               current_sequence.top().back()[tag]
                     = make_elementfield<VR::NI>(value_len);

            } else if (tag == ItemDelimitationItem) {
               current_sequence.top().back()[ItemDelimitationItem]
                     = make_elementfield<VR::NN>();
               current_sequence.top().push_back(dataset_type {});
            } else if (tag == SequenceDelimitationItem) {
               current_sequence.top().back()[tag] = make_elementfield<VR::NN>();
               positions.pop();
            }
         }
      }

      // add item and sequence delimination on the last item of a nested
      // sequence, leaving the outermost without.
      if (current_sequence.size() > 1) {
         current_sequence.top().back()[ItemDelimitationItem] = make_elementfield<VR::NN>();
         current_sequence.top().back()[SequenceDelimitationItem] = make_elementfield<VR::NN>();
      }
      current_data.pop();
   }

   // The size of the outermost set should be exactly one
   assert(current_sequence.top().size() == 1);
   return current_sequence.top()[0];
}


std::vector<unsigned char> commandset_processor::serialize_attribute(elementfield e, VR vr) const
{
   return encode_little_endian(e, vr);
}

std::vector<unsigned char> transfer_processor::serialize(iod data) const
{
   std::vector<unsigned char> stream;
   for (const auto attr : dataset_iterator_adaptor(data)) {
      if (attr.first == SequenceDelimitationItem
          || attr.first == ItemDelimitationItem) {
         continue;
      } else if (attr.first == Item) {
         auto tag = encode_tag_little_endian(attr.first);
         auto len = encode_len_little_endian(attr.second.value_len);
         stream.insert(stream.end(), tag.begin(), tag.end());
         stream.insert(stream.end(), len.begin(), len.end());
         continue;
      }

      VR repr;
      if (vrtype == VR_TYPE::EXPLICIT) {
         repr = attr.second.value_rep.get();
      } else {
         /** @todo handle options */
         repr = dict.get().lookup(attr.first).vr[0];
      }

      auto data = serialize_attribute(attr.second, repr);
      auto tag = encode_tag_little_endian(attr.first);
      auto len = encode_len_little_endian(attr.second.value_len);
      stream.insert(stream.end(), tag.begin(), tag.end());
      if (vrtype == VR_TYPE::EXPLICIT) {
         auto vr = dictionary::dictionary_entry::vr_of_string.right.at(repr);
         stream.insert(stream.end(), vr.begin(), vr.begin()+2);
      }
      stream.insert(stream.end(), len.begin(), len.end());
      stream.insert(stream.end(), data.begin(), data.end());
   }
   return stream;
}

std::string transfer_processor::get_transfer_syntax() const
{
   return transfer_syntax;
}

elementfield commandset_processor::deserialize_attribute(std::vector<unsigned char>& data,
                                                       std::size_t len,
                                                       VR vr,
                                                       std::size_t pos) const
{
   return decode_little_endian(data, len, vr, pos);
}


transfer_processor::transfer_processor(boost::optional<dictionary::dictionary&> dict,
                                       std::string tfs, VR_TYPE vrtype):
   dict(dict),
   transfer_syntax {tfs},
   vrtype {vrtype}
{
   if (vrtype == VR_TYPE::IMPLICIT && !dict.is_initialized()) {
      throw std::runtime_error("Uninitialized dictionary with "
                               "implicit VR type specificed!");
   }
}

transfer_processor::transfer_processor(const transfer_processor& other):
   dict(other.dict),
   transfer_syntax {other.transfer_syntax},
   vrtype (other.vrtype)
{
}

little_endian_implicit::little_endian_implicit(dictionary::dictionary& dict):
   transfer_processor {boost::optional<dictionary::dictionary&> {dict},
                       "1.2.840.10008.1.2",
                       VR_TYPE::IMPLICIT}
{
}

little_endian_implicit::little_endian_implicit(const little_endian_implicit& other):
   transfer_processor {other}
{

}

std::vector<unsigned char> little_endian_implicit::serialize_attribute(elementfield e, attribute::VR vr) const
{
   return encode_little_endian(e, vr);
}

elementfield little_endian_implicit::deserialize_attribute(std::vector<unsigned char>& data,
                                                           std::size_t len, attribute::VR vr,
                                                           std::size_t pos) const
{
   return decode_little_endian(data, len, vr, pos);
}


}

}

}
