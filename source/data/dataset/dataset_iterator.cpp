#include "dataset_iterator.hpp"

#include <stack>
#include <algorithm>

#include "data/attribute/constants.hpp"

namespace dicom
{

namespace data
{

namespace dataset
{

using namespace attribute;
using namespace data::dictionary;

dataset_iterator::dataset_iterator(typename std::map<attribute::tag_type, attribute::elementfield>::iterator it):
   cit {it},
   delimiter {it},
   dictionary {get_default_dictionaries()}
{
   nested_set_sizes.push({0, 0});
}

dataset_iterator dataset_iterator::operator++()
{
   return next();
}

dataset_iterator dataset_iterator::operator++(int)
{
   dataset_iterator ret = cit;
   cit = next();
   return ret;
}

dataset_iterator dataset_iterator::operator--()
{
   return previous();
}

dataset_iterator dataset_iterator::operator--(int)
{
   dataset_iterator ret = cit;
   cit = previous();
   return ret;
}


std::pair<attribute::tag_type, attribute::elementfield>
dataset_iterator::operator*() const
{
   return *cit;
}


std::pair<const attribute::tag_type, attribute::elementfield> const*
dataset_iterator::operator->() const
{
   return &*cit;
}

bool operator==(const dataset_iterator& lhs, const dataset_iterator& rhs)
{
   return lhs.cit == rhs.cit;
}

bool operator!=(const dataset_iterator& lhs, const dataset_iterator& rhs)
{
   return !(lhs == rhs);
}

std::map<attribute::tag_type, attribute::elementfield>::iterator
dataset_iterator::step_into_nested(std::map<attribute::tag_type, attribute::elementfield>::iterator curr)
{
   parent_its.push(curr); // save current position of the iterator
   nested_set_sizes.push({0, curr->second.value_len});
   std::vector<dataset_type> nested_set;
   get_value_field<VR::SQ>(curr->second, nested_set);

   nested_set.erase(std::remove_if(nested_set.begin(), nested_set.end(),
                                   [](const dataset_type& set) { return set.empty(); }),
                    nested_set.end());

   nested_sets.push(nested_set);
   items.push({0, nested_sets.top().size()});
   if (nested_set.size() == 0 || /* empty set*/ nested_set[0].size() == 0) {
      return step_outof_nested();
   } else {
      curr = nested_sets.top().begin()->begin();
      return curr;
   }
}

std::map<attribute::tag_type, attribute::elementfield>::iterator dataset_iterator::step_outof_nested()
{
   auto last = parent_its.top();
   parent_its.pop();
   nested_sets.pop();
   items.pop();
   nested_set_sizes.pop();
   return ++last;
}

std::map<attribute::tag_type, attribute::elementfield>::iterator
dataset_iterator::step_backw_into_nested(std::map<attribute::tag_type, attribute::elementfield>::iterator prev)
{
   bool explicitlength = true;
   parent_its.push(prev);
   nested_set_sizes.push({prev->second.value_len, prev->second.value_len});
   if (nested_set_sizes.top().curr_nestedset_max != 0xffff) {
      nested_set_sizes.top().curr_nestedset_size = nested_set_sizes.top().curr_nestedset_max;
   } else {
      explicitlength = false;
   }
   std::vector<dataset_type> nested_set;
   get_value_field<VR::SQ>(prev->second, nested_set);
   nested_sets.push(nested_set);
   items.push({nested_sets.size()-1, nested_sets.size()});
   auto curr = --nested_sets.top()[items.top().nested_items_max-1].end();
   return explicitlength ? curr : --curr;
}

std::map<attribute::tag_type, attribute::elementfield>::iterator dataset_iterator::step_backw_outof_nested()
{
   auto last = parent_its.top();
   parent_its.pop();
   nested_sets.pop();
   items.pop();
   nested_set_sizes.pop();
   return last;
}

std::map<attribute::tag_type, attribute::elementfield>::iterator dataset_iterator::next()
{
   // accumulate the size of the nested set's elements if a sequence size was
   // explicitly specified
   if (nested_set_sizes.top().curr_nestedset_max != 0xffff
       && cit->first != Item
       && cit->first != ItemDelimitationItem
       && cit->first != SequenceDelimitationItem) {
      nested_set_sizes.top().curr_nestedset_size += cit->second.value_len + 4 + 4;
   }

   /// @todo check what happens when the last item in a sequence is another SQ
   /// -> maybe put else if branch outside as a "standalone" if.
   if (cit->first == SequenceDelimitationItem || cit->first == ItemDelimitationItem
//       || (is_in_nested() && (cit->second.value_rep != VR::SQ || dictionary.lookup(cit->first).vr[0] == VR::SQ) && nested_set_sizes.top().curr_nestedset_size >= nested_set_sizes.top().curr_nestedset_max)) {
      || (is_in_nested() && cit->second.value_rep != VR::SQ && nested_set_sizes.top().curr_nestedset_size >= nested_set_sizes.top().curr_nestedset_max)) {
      // sequence delimitation item encountered, check if there are more items.
      // Otherwise, step out of the current sequence.
      auto& nes_items = items.top().nested_items_curr;
      //last = cit->first;
      if (nes_items < items.top().nested_items_max-1) {
         nes_items++;
         return (cit = nested_sets.top()[nes_items].begin());
      } else if (cit->first == ItemDelimitationItem) {
         return ++cit; // we still have the sequenceDelimitationItem
      } else {
         delimiter = cit = step_outof_nested();
         return delimiter;
      }
   } else if (cit->second.value_rep.is_initialized()) {
      //last = cit->first;
      // found another sequence in the current set; step into it.
      if (cit->second.value_rep == VR::SQ) {
         cit = step_into_nested(cit);
         return cit;
      }
   } else if (dictionary.lookup(cit->first).vr[0] == VR::SQ) {
      // found another sequence in the current set; step into it.
      cit = step_into_nested(cit);
      return cit;
   }

   return ++cit;
}

std::map<attribute::tag_type, attribute::elementfield>::iterator dataset_iterator::previous()
{
   auto curr = cit;
   --cit;
   if (is_in_nested() &&
       std::any_of(nested_sets.top().begin(), nested_sets.top().end(), [curr](const dataset_type& set) { return set.begin() == curr; })) {
      // current iterator points into a sequence, at the beginning of a item
      // vector. Check if there are more previous elements in the item vector,
      // if not step backwards out of the sequence.
      if (items.top().nested_items_curr > 0) {
         items.top().nested_items_curr--;
         return (cit = (nested_sets.top()[items.top().nested_items_curr].end()--));
      } else {
         return (cit = step_backw_outof_nested());
      }
   } else if ((cit->second.value_rep.is_initialized() && cit->second.value_rep == VR::SQ) ||
              dictionary.lookup(cit->first).vr[0] == VR::SQ) {
      // previous item will be a sequence, step backwards into it.
      return (cit = step_backw_into_nested(cit));
   }

   if (nested_set_sizes.top().curr_nestedset_max != 0xffff
       && cit->first != Item
       && cit->first != ItemDelimitationItem
       && cit->first != SequenceDelimitationItem) {
      nested_set_sizes.top().curr_nestedset_size -= cit->second.value_len - (4 + 4);
   }

   return cit;
}

bool dataset_iterator::is_in_nested() const
{
   return parent_its.size() > 0;
}

dataset_iterator_adaptor::dataset_iterator_adaptor(std::map<tag_type, elementfield> ds):
   dataset {ds}
{
}

dataset_iterator dataset_iterator_adaptor::begin()
{
   return dataset.begin();
}

dataset_iterator dataset_iterator_adaptor::end()
{
   return dataset.end();
}

}

}

}

