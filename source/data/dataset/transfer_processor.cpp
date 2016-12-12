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


static const std::vector<VR> specialVRs {VR::OB, VR::OW, VR::OF, VR::SQ, VR::UR, VR::UT, VR::UN, VR::NI, VR::NN};

static const std::vector<tag_type> item_attributes {Item, ItemDelimitationItem, SequenceDelimitationItem};



/**
 * @brief is_specialVR checks if the given VR needs special handling in explicit
 *        transfer syntaxes
 * @param vr VR to be checked
 * @return true if VR is "special", false otherwise
 * @see DICOM standard part 3.5, chapter 7.1.2
 */
static bool is_special_VR(VR vr)
{
   return std::find(specialVRs.begin(), specialVRs.end(), vr)
         != specialVRs.end();
}


/**
 * @brief is_item_attribute checks if the passed tag is of an item type, ie.
 *        Item, ItemDelimitationItem or SequenceDelimitationItem
 * @param tag tag to be checked
 * @return true if tag corresponds to an "item type", false otherwise
 */
static bool is_item_attribute(tag_type tag)
{
   return std::find(item_attributes.begin(), item_attributes.end(), tag)
         != item_attributes.end();
}



transfer_processor::~transfer_processor()
{
}


std::size_t transfer_processor::find_enclosing(std::vector<unsigned char> data, std::size_t beg) const
{
   std::size_t pos = beg;
   int nested_sets = 0;

   std::stack<std::size_t> beginnings;
   beginnings.push(pos);

   while (!beginnings.empty() && pos < data.size()) {
      pos = beginnings.top();
      tag_type tag = decode_tag(data, pos, endianness);
      if (tag == SequenceDelimitationItem) {
         pos += 8;
         beginnings.pop();
         std::size_t oldpos = beginnings.top();
         beginnings.top() += pos-oldpos;
         continue;
      }
      pos += 4;

      VR repr = deserialize_VR(data, tag, pos);
      std::size_t value_len = deserialize_length(data, tag, repr, pos);

      if (repr == VR::SQ) {
         nested_sets++;
      }

      if ((value_len & 0xffffffff) == 0xffffffff) {
         beginnings.push(pos);
      } else {
         pos += value_len;
      }

   }
   return beginnings.top()-beg;
}



commandset_processor::commandset_processor(dictionary::dictionary& dict):
   transfer_processor {boost::optional<dictionary::dictionary&> {dict}, "", VR_TYPE::IMPLICIT, ENDIANNESS::LITTLE}
{
}


dataset_type transfer_processor::deserialize(std::vector<unsigned char> data) const
{
   dataset_type dataset;
   std::vector<dataset_type> outerset {dataset};

   std::stack<std::vector<unsigned char>> current_data;
   std::stack<std::vector<dataset_type>> current_sequence;
   std::stack<std::size_t> positions;
   std::stack<std::pair<tag_type, std::size_t>> lasttag;

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

         tag_type tag = decode_tag(current_data.top(), pos, endianness);
         pos += 4;

         VR repr = deserialize_VR(current_data.top(), tag, pos);
         std::size_t value_len = deserialize_length(current_data.top(), tag, repr, pos);


         // Items and DelimitationItems do not have a VR or length field and are
         // to be treated separately.
         if (!is_item_attribute(tag)) {

            // if the current item is a sequence, push the nested serialized
            // data on the stack so it will be processed next. Store the current
            // state of the deserialization on appropriate stacks.
            if (repr == VR::SQ) {
               value_len = ((value_len & 0xffffffff)== 0xffffffff)
                     ? find_enclosing(current_data.top(), pos)
                     : value_len;
               current_data.push({current_data.top().begin()+pos, current_data.top().begin()+pos+value_len});
               current_sequence.push({dataset_type {}});
               positions.push(0);
               lasttag.push({tag, value_len});
            } else {
               auto multiplicity = get_dictionary().lookup(tag).vm;
               elementfield e = deserialize_attribute(current_data.top(), endianness, value_len, repr, multiplicity, pos);
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


VR transfer_processor::deserialize_VR(std::vector<unsigned char> dataset, tag_type tag, std::size_t& pos) const
{
   if (!is_item_attribute(tag)) {
      if (vrtype != VR_TYPE::IMPLICIT) {
         VR repr = dictionary::dictionary_entry::vr_of_string
               .left.at(std::string {dataset.begin()+pos, dataset.begin()+pos+2});
         if (is_special_VR(repr)) {
            pos += 4;
         } else {
            pos += 2;
         }
         return repr;
      } else {
         return get_vr(tag);
      }
   }
   return VR::NN;
}

std::size_t transfer_processor::deserialize_length(std::vector<unsigned char> dataset,
                                                   attribute::tag_type tag,
                                                   VR repr, std::size_t& pos) const
{
   const std::size_t lengthfield_size
         = (vrtype == VR_TYPE::IMPLICIT || is_special_VR(repr))
         ? 4 : 2;

   std::size_t value_len;
   if (!is_item_attribute(tag)) {
      value_len = decode_len(dataset, endianness, lengthfield_size, pos);
   } else if (tag == Item) {
      value_len = decode_len(dataset, endianness, 4, pos);
   } else {
      value_len = 0;
   }
   pos += lengthfield_size;

   return value_len;
}


std::vector<unsigned char> commandset_processor::serialize_attribute(elementfield e, ENDIANNESS end, VR vr) const
{
   return encode_value_field(e, end, vr);
}

std::vector<unsigned char> transfer_processor::serialize(iod data) const
{
   std::vector<unsigned char> stream;
   for (const auto attr : dataset_iterator_adaptor(data)) {
      if (attr.first == SequenceDelimitationItem
          || attr.first == ItemDelimitationItem) {
         auto tag = encode_tag(attr.first, endianness);
         auto len = encode_len(4, attr.second.value_len, endianness);
         stream.insert(stream.end(), tag.begin(), tag.end());
         stream.insert(stream.end(), len.begin(), len.end());
         continue;
      } else if (attr.first == Item) {
         auto tag = encode_tag(attr.first, endianness);
         auto len = encode_len(4, attr.second.value_len, endianness);
         stream.insert(stream.end(), tag.begin(), tag.end());
         stream.insert(stream.end(), len.begin(), len.end());
         continue;
      }

      VR repr;
      if (vrtype == VR_TYPE::EXPLICIT) {
         repr = attr.second.value_rep.get();
      } else {
         repr = get_vr(attr.first);
      }


      auto data = serialize_attribute(attr.second, endianness, repr);
      auto tag = encode_tag(attr.first, endianness);
      std::vector<unsigned char> len;
      stream.insert(stream.end(), tag.begin(), tag.end());
      if (vrtype == VR_TYPE::EXPLICIT) {
         auto vr = dictionary::dictionary_entry::vr_of_string.right.at(repr);
         stream.insert(stream.end(), vr.begin(), vr.begin()+2);
         if (is_special_VR(repr)) {
            stream.push_back(0x00); stream.push_back(0x00);
            len = encode_len(4, attr.second.value_len, endianness);
         } else {
            len = encode_len(2, attr.second.value_len, endianness);
         }
      } else {
         len = encode_len(4, attr.second.value_len, endianness);
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
                                                         attribute::ENDIANNESS end,
                                                       std::size_t len,
                                                       VR vr, std::string vm,
                                                       std::size_t pos) const
{
   return decode_value_field(data, end, len, vr, vm, pos);
}


transfer_processor::transfer_processor(boost::optional<dictionary::dictionary&> dict,
                                       std::string tfs, VR_TYPE vrtype,
                                       ENDIANNESS endianness,
                                       std::initializer_list<vr_of_tag> tstags):
   tstags {tstags},
   dict(dict),
   transfer_syntax {tfs},
   vrtype {vrtype},
   endianness {endianness}
{
   if (vrtype == VR_TYPE::IMPLICIT && !dict.is_initialized()) {
      throw std::runtime_error("Uninitialized dictionary with "
                               "implicit VR type specificed!");
   }
}

data::dictionary::dictionary& transfer_processor::get_dictionary() const
{
   return *dict;
}

transfer_processor::transfer_processor(const transfer_processor& other):
   dict(other.dict),
   transfer_syntax {other.transfer_syntax},
   vrtype (other.vrtype)
{
}

VR transfer_processor::get_vr(tag_type tag) const
{
   auto spectag = std::find_if(tstags.begin(), tstags.end(),
                               [tag](vr_of_tag vrt) {
         return (tag.group_id & vrt.gid_mask) == vrt.tag.group_id
             && (tag.element_id & vrt.eid_mask) == vrt.tag.element_id;
   });
   if (spectag == tstags.end()) {
      return dict.get().lookup(tag).vr[0];
   } else {
      return spectag->vr;
   }
}

little_endian_implicit::little_endian_implicit(dictionary::dictionary& dict):
   transfer_processor {boost::optional<dictionary::dictionary&> {dict},
                       "1.2.840.10008.1.2",
                       VR_TYPE::IMPLICIT,
                       ENDIANNESS::LITTLE,
                       {
                           {{0x7fe0, 0x0010}, VR::OW},
                           {{0x6000, 0x3000}, VR::OW, 0xff00, 0xffff},
                           {{0x5400, 0x1010}, VR::OW}, {{0x0028, 0x1201}, VR::OW},
                           {{0x0028, 0x1202}, VR::OW}, {{0x0028, 0x1203}, VR::OW},
                           {{0x0028, 0x1204}, VR::OW}, {{0x0028, 0x1101}, VR::SS},
                           {{0x0028, 0x1102}, VR::SS}, {{0x0028, 0x1103}, VR::SS},
                           {{0x0028, 0x1221}, VR::OW}, {{0x0028, 0x1222}, VR::OW},
                           {{0x0028, 0x1223}, VR::OW}, {{0x0028, 0x3006}, VR::US},
                           {{0x0028, 0x3002}, VR::SS}, {{0x0028, 0x1408}, VR::OW},
                           {{0x0066, 0x0025}, VR::OW}, {{0x0066, 0x0024}, VR::OW},
                           {{0x0066, 0x0023}, VR::OW}, {{0x0066, 0x0029}, VR::OW}
                       } }
{
}

little_endian_implicit::little_endian_implicit(const little_endian_implicit& other):
   transfer_processor {other}
{

}

std::vector<unsigned char> little_endian_implicit::serialize_attribute(elementfield e, ENDIANNESS end, attribute::VR vr) const
{
   return encode_value_field(e, end, vr);
}

elementfield little_endian_implicit::deserialize_attribute(std::vector<unsigned char>& data,
                                                           attribute::ENDIANNESS end,
                                                           std::size_t len, attribute::VR vr,
                                                           std::string vm,
                                                           std::size_t pos) const
{
   return decode_value_field(data, end, len, vr, vm, pos);
}

transfer_processor::vr_of_tag::vr_of_tag(tag_type tag,
                                         VR vr,
                                         unsigned eid_mask,
                                         unsigned gid_mask):
   tag {tag},
   eid_mask {eid_mask},
   gid_mask {gid_mask},
   vr {vr}
{
}

little_endian_explicit::little_endian_explicit():
   transfer_processor {boost::none,
                       "1.2.840.10008.1.2.1",
                       VR_TYPE::EXPLICIT, ENDIANNESS::LITTLE,
                       {
                           {{0x7fe0, 0x0010}, VR::OW},
                           {{0x6000, 0x3000}, VR::OW, 0xff00, 0xffff},
                           {{0x5400, 0x1010}, VR::OW}, {{0x0028, 0x1201}, VR::OW},
                           {{0x0028, 0x1202}, VR::OW}, {{0x0028, 0x1203}, VR::OW},
                           {{0x0028, 0x1204}, VR::OW}, {{0x0028, 0x1101}, VR::SS},
                           {{0x0028, 0x1102}, VR::SS}, {{0x0028, 0x1103}, VR::SS},
                           {{0x0028, 0x1221}, VR::OW}, {{0x0028, 0x1222}, VR::OW},
                           {{0x0028, 0x1223}, VR::OW}, {{0x0028, 0x3006}, VR::US},
                           {{0x0028, 0x3002}, VR::SS}, {{0x0028, 0x1408}, VR::OW},
                           {{0x0066, 0x0025}, VR::OW}, {{0x0066, 0x0024}, VR::OW},
                           {{0x0066, 0x0023}, VR::OW}, {{0x0066, 0x0029}, VR::OW}
                       } }
{

}

std::vector<unsigned char> little_endian_explicit::serialize_attribute(elementfield e, attribute::ENDIANNESS end, VR vr) const
{
   return encode_value_field(e, end, vr);
}

elementfield little_endian_explicit::deserialize_attribute(std::vector<unsigned char>& data, ENDIANNESS end,
                                                           std::size_t len, VR vr, std::string vm,
                                                           std::size_t pos) const
{
   return decode_value_field(data, end, len, vr, vm, pos);
}

big_endian_explicit::big_endian_explicit():
   transfer_processor {boost::none, "1.2.840.10008.1.2.1",
                       VR_TYPE::EXPLICIT, ENDIANNESS::BIG,
                       {
                           {{0x7fe0, 0x0010}, VR::OW},
                           {{0x6000, 0x3000}, VR::OW, 0xff00, 0xffff},
                           {{0x5400, 0x1010}, VR::OW}, {{0x0028, 0x1201}, VR::OW},
                           {{0x0028, 0x1202}, VR::OW}, {{0x0028, 0x1203}, VR::OW},
                           {{0x0028, 0x1204}, VR::OW}, {{0x0028, 0x1101}, VR::SS},
                           {{0x0028, 0x1102}, VR::SS}, {{0x0028, 0x1103}, VR::SS},
                           {{0x0028, 0x1221}, VR::OW}, {{0x0028, 0x1222}, VR::OW},
                           {{0x0028, 0x1223}, VR::OW}, {{0x0028, 0x3006}, VR::US},
                           {{0x0028, 0x3002}, VR::SS}, {{0x0028, 0x1408}, VR::OW},
                           {{0x0066, 0x0025}, VR::OW}, {{0x0066, 0x0024}, VR::OW},
                           {{0x0066, 0x0023}, VR::OW}, {{0x0066, 0x0029}, VR::OW}
                       } }
{

}

std::vector<unsigned char> big_endian_explicit::serialize_attribute(elementfield e, attribute::ENDIANNESS end, VR vr) const
{
   return encode_value_field(e, end, vr);
}

elementfield big_endian_explicit::deserialize_attribute(std::vector<unsigned char>& data, ENDIANNESS end,
                                                           std::size_t len, VR vr, std::string vm,
                                                           std::size_t pos) const
{
   return decode_value_field(data, end, len, vr, vm, pos);
}


}

}

}
