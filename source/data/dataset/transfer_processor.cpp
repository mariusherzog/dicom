#include "transfer_processor.hpp"

#include <stack>
#include <numeric>

#include <boost/log/trivial.hpp>

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

using namespace boost::log::trivial;
using namespace attribute;


static const std::vector<VR> specialVRs {VR::OB, VR::OW, VR::OF, VR::SQ, VR::UR, VR::UT, VR::UN, VR::NI, VR::NN};

static const std::vector<tag_type> item_attributes {Item, ItemDelimitationItem, SequenceDelimitationItem};


std::size_t dataset_bytesize(dicom::data::dataset::dataset_type data, const transfer_processor& transfer_proc)
{
   return std::accumulate(data.begin(), data.end(), 0,
      [&transfer_proc](int acc, const std::pair<const tag_type, elementfield>& attr)
      {
         return acc += transfer_proc.dataelement_length(attr.second);
      });
}


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

std::size_t transfer_processor::dataelement_length(const elementfield& ef) const
{
   if (vrtype == VR_TYPE::IMPLICIT) {
      return ef.value_len + 4 + 2 + 2;
   } else {
      std::size_t length = ef.value_len + 2 + 2;
      if (is_special_VR(*ef.value_rep)) {
         length += 2 + 2 + 4;
      } else {
         length += 2 + 2;
      }
      return length;
   }
}

std::size_t transfer_processor::calculate_item_lengths(dataset::dataset_type& dataset) const
{
   std::size_t accu = 0;

   // skip undefined length items. The accumulator for this sequence will stay at 0.
   // This is ok since it is not used for the sequence length, since when one item
   // length is undefined, the sequence length is necessarily undefined as well.
   if (dataset.count(Item) > 0 && dataset[Item].value_len == 0xffffffff) {
      return accu;
   }

   // item only contains "item type" tags, so the length is essentially zero.
   if (std::all_of(dataset.begin(), dataset.end(),
                   [](std::pair<const tag_type, elementfield> attr) {
                     return is_item_attribute(attr.first); })) {
      return accu;
   }

   for (auto& attr : dataset) {
      VR repr;
      if (vrtype == VR_TYPE::EXPLICIT) {
         repr = attr.second.value_rep.get();
      } else {
         repr = get_vr(attr.first);
      }

      if (repr != VR::SQ && !is_item_attribute(attr.first)) {
         accu += dataelement_length(attr.second);
      } else if (repr == VR::SQ) {
         // now handle all sequence items
         // sequences with undefined length need to be checked as well
         // because they may contain items with defined length
         typename type_of<VR::SQ>::type data;
         get_value_field<VR::SQ>(attr.second, data);
         std::size_t sequencesize = 0;
         for (dataset_type& itemset : data) {
            auto itemsize = calculate_item_lengths(itemset);
            if (itemsize > 0) {
               itemset[Item].value_len = itemsize;
               sequencesize += itemsize + 8;
            } else {
               sequencesize += 0;
            }
         }

         if (attr.second.value_len != 0xffffffff) {
            attr.second.value_len = sequencesize;
            set_value_field<VR::SQ>(attr.second, data);
            accu += dataelement_length(attr.second); // update the sequence length
         }
      }
   }
   return accu;
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
      //pos = beginnings.top();
      tag_type tag = decode_tag(data, pos, endianness);
      if (tag == SequenceDelimitationItem || tag == ItemDelimitationItem) {
         pos += 8;
         beginnings.pop();
//         std::size_t oldpos = beginnings.top();
//         beginnings.top() += pos-oldpos;
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
   return pos-beg;
}



commandset_processor::commandset_processor(dictionary::dictionaries& dict):
   transfer_processor {boost::optional<dictionary::dictionaries&> {dict}, "", VR_TYPE::IMPLICIT, ENDIANNESS::LITTLE}
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

      bool undefined_length_item = false;
      bool undefined_length_sequence = false;
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
               undefined_length_sequence = ((value_len & 0xffffffff) == 0xffffffff);
               value_len = ((value_len & 0xffffffff)== 0xffffffff)
                     ? find_enclosing(current_data.top(), pos)
                     : value_len;
               current_data.push({current_data.top().begin()+pos, current_data.top().begin()+pos+value_len});
               current_sequence.push({dataset_type {}});
               positions.push(0);
               lasttag.push({tag, undefined_length_sequence ? 0xffffffff : value_len});
            } else {
               //auto multiplicity = get_dictionary().lookup(tag).vm;
               elementfield e = deserialize_attribute(current_data.top(), endianness, value_len, repr, "*", pos);
               current_sequence.top().back()[tag] = e;
            }
            pos += value_len;
         } else {
            // Put Items and respective DelimitationItems into the deserialized
            // set.
            if (tag == Item) {
               // detect if an ItemDelimitationItem was missed
               if (positions.top() > 8) {
                  current_sequence.top().back()[ItemDelimitationItem]
                        = make_elementfield<VR::NN>();
                  current_sequence.top().push_back(dataset_type {});
               }
               undefined_length_item = ((value_len & 0xffffffff) == 0xffffffff);
               if (!undefined_length_item) {
                  current_sequence.top().back()[tag]
                        = make_elementfield<VR::NI>(value_len, VR::NI);
               } else {
                  current_sequence.top().back()[tag]
                        = make_elementfield<VR::NI>(0xffffffff, VR::NI);
               }

            } else if (tag == ItemDelimitationItem) {
               // ItemDelimitationItem for this item is set when the next Item
               // tag is encountered to handle possibly missing
               // ItemDelimitationItems
            } else if (tag == SequenceDelimitationItem) {
               // sequence delimitation is in a separate, the last, vector
               if (current_sequence.top().size() > 0) {
                  current_sequence.top().push_back(dataset_type {});
               }
               current_sequence.top().back()[tag] = make_elementfield<VR::NN>();
            }
         }
      }

      // add item and sequence delimination on the last item of a nested
      // sequence, leaving the outermost without.
      if (current_sequence.size() > 1) {
         auto& itemset = current_sequence.top().back();
         auto& prevset = *(current_sequence.top().end()-2);
         if (current_sequence.top().size() < 2) {
            current_sequence.top().back()[ItemDelimitationItem] = make_elementfield<VR::NN>();
         } else {
            bool have_item_delimitation = false;
            if (prevset.find(Item) != prevset.end() && prevset.find(ItemDelimitationItem) == prevset.end()) {
               prevset[ItemDelimitationItem] = make_elementfield<VR::NN>();
               have_item_delimitation = true;
            }
            if (!have_item_delimitation && itemset.find(ItemDelimitationItem) == itemset.end() &&
                !(itemset.size() == 1 && itemset.find(SequenceDelimitationItem) != itemset.end())) {
               itemset[ItemDelimitationItem] = make_elementfield<VR::NN>();
               have_item_delimitation = true;
            }
         }
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

std::vector<unsigned char> transfer_processor::serialize(iod dataset) const
{
   calculate_item_lengths(dataset);

   std::vector<unsigned char> stream;
   bool explicit_length_item = true;
   bool explicit_length_sequence = true;
   for (const auto attr : dataset_iterator_adaptor(dataset)) {
      if (attr.first == SequenceDelimitationItem) {
         if (!explicit_length_sequence) {
            auto tag = encode_tag(attr.first, endianness);
            auto len = encode_len(4, attr.second.value_len, endianness);
            stream.insert(stream.end(), tag.begin(), tag.end());
            stream.insert(stream.end(), len.begin(), len.end());
         }
         continue;
      } else if (attr.first == ItemDelimitationItem) {
         if (!explicit_length_item)  {
            auto tag = encode_tag(attr.first, endianness);
            auto len = encode_len(4, attr.second.value_len, endianness);
            stream.insert(stream.end(), tag.begin(), tag.end());
            stream.insert(stream.end(), len.begin(), len.end());
         }
         continue;
      } else if (attr.first == Item) {
         auto tag = encode_tag(attr.first, endianness);
         auto len = encode_len(4, attr.second.value_len, endianness);
         stream.insert(stream.end(), tag.begin(), tag.end());
         stream.insert(stream.end(), len.begin(), len.end());
         explicit_length_item = (attr.second.value_len != 0xffffffff);
         continue;
      }

      VR repr;
      if (vrtype == VR_TYPE::EXPLICIT) {
         repr = attr.second.value_rep.get();
      } else {
         repr = get_vr(attr.first);
      }

      std::size_t value_length = attr.second.value_len;
      auto data = serialize_attribute(attr.second, endianness, repr);
      if (data.size() != attr.second.value_len) {
         BOOST_LOG_SEV(logger, warning) << "Mismatched value lengths for tag "
                                        << attr.first << ": Expected "
                                        << attr.second.value_len << ", actual "
                                        << data.size();

         if (attr.second.value_rep.is_initialized() &&
             *attr.second.value_rep != VR::SQ &&
             *attr.second.value_rep != VR::NN &&
             *attr.second.value_rep != VR::NI) {
            value_length = data.size();
         }
      }

      auto tag = encode_tag(attr.first, endianness);
      std::vector<unsigned char> len;
      stream.insert(stream.end(), tag.begin(), tag.end());
      if (vrtype == VR_TYPE::EXPLICIT) {
         auto vr = dictionary::dictionary_entry::vr_of_string.right.at(repr);
         stream.insert(stream.end(), vr.begin(), vr.begin()+2);
         if (is_special_VR(repr)) {
            stream.push_back(0x00); stream.push_back(0x00);
            len = encode_len(4, value_length, endianness);
         } else {
            len = encode_len(2, value_length, endianness);
         }
      } else {
         len = encode_len(4, value_length, endianness);
      }
      if (repr == VR::SQ)
      {
         explicit_length_sequence = (attr.second.value_len != 0xffffffff);
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


transfer_processor::transfer_processor(boost::optional<dictionary::dictionaries&> dict,
                                       std::string tfs, VR_TYPE vrtype,
                                       ENDIANNESS endianness,
                                       std::initializer_list<vr_of_tag> tstags):
   tstags {tstags},
   dict(dict),
   transfer_syntax {tfs},
   vrtype {vrtype},
   endianness {endianness},
   logger {"transfer processor"}
{
   if (vrtype == VR_TYPE::IMPLICIT && !dict.is_initialized()) {
      throw std::runtime_error("Uninitialized dictionary with "
                               "implicit VR type specificed!");
   }
}

data::dictionary::dictionaries& transfer_processor::get_dictionary() const
{
   return *dict;
}

transfer_processor::transfer_processor(const transfer_processor& other):
   dict {other.dict},
   transfer_syntax {other.transfer_syntax},
   vrtype {other.vrtype},
   logger {"transfer processor"}
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

little_endian_implicit::little_endian_implicit(dictionary::dictionaries& dict):
   transfer_processor {boost::optional<dictionary::dictionaries&> {dict},
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

little_endian_explicit::little_endian_explicit(dictionary::dictionaries& dict):
   transfer_processor {boost::optional<dictionary::dictionaries&> {dict},
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

big_endian_explicit::big_endian_explicit(dictionary::dictionaries& dict):
   transfer_processor {boost::optional<dictionary::dictionaries&> {dict},
                       "1.2.840.10008.1.2.2",
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
