#include "dataset_iterator.hpp"

#include <stack>

#include "data/attribute/constants.hpp"

namespace dicom
{

namespace data
{

namespace dataset
{

using namespace attribute;

dictionary::dictionary_dyn dataset_iterator::commanddic =
{"/media/STORAGE/_files/Studium/Sem 5/Studienprojekt/dicom/dicom/commanddictionary.txt"};
dictionary::dictionary_dyn dataset_iterator::datadic =
{"/media/STORAGE/_files/Studium/Sem 5/Studienprojekt/dicom/dicom/commanddictionary.txt"};

dataset_iterator::dataset_iterator(typename std::map<attribute::elementfield::tag_type, attribute::elementfield>::iterator it):
   cit {it}
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


std::pair<attribute::elementfield::tag_type, attribute::elementfield>
dataset_iterator::operator*() const
{
   return *cit;
}


std::pair<const attribute::elementfield::tag_type, attribute::elementfield> const*
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

std::map<attribute::elementfield::tag_type, attribute::elementfield>::iterator
dataset_iterator::step_into_nested(std::map<attribute::elementfield::tag_type, attribute::elementfield>::iterator curr)
{
   parent_its.push(curr); // save current position of the iterator
   nested_set_sizes.push({0, curr->second.value_len});
   dataset_type nested_set;
   get_value_field<VR::SQ>(curr->second, nested_set);
   nested_sets.push(nested_set);
   curr = nested_sets.top().begin();
   return curr;
}

std::map<attribute::elementfield::tag_type, attribute::elementfield>::iterator dataset_iterator::step_outof_nested()
{
   auto last = parent_its.top();
   parent_its.pop();
   nested_sets.pop();
   nested_set_sizes.pop();
   return ++last;
}

std::map<attribute::elementfield::tag_type, attribute::elementfield>::iterator
dataset_iterator::step_backw_into_nested(std::map<attribute::elementfield::tag_type, attribute::elementfield>::iterator prev)
{
   bool explicitlength = true;
   parent_its.push(prev);
   nested_set_sizes.push({prev->second.value_len, prev->second.value_len});
   if (nested_set_sizes.top().curr_nestedset_max != 0xffff) {
      nested_set_sizes.top().curr_nestedset_size = nested_set_sizes.top().curr_nestedset_max;
   } else {
      explicitlength = false;
   }
   dataset_type nested_set;
   get_value_field<VR::SQ>(prev->second, nested_set);
   nested_sets.push(nested_set);
   auto curr = --nested_sets.top().end();
   return explicitlength ? curr : --curr;
}

std::map<attribute::elementfield::tag_type, attribute::elementfield>::iterator dataset_iterator::step_backw_outof_nested()
{
   auto last = parent_its.top();
   parent_its.pop();
   nested_sets.pop();
   nested_set_sizes.pop();
   return last;
}

std::map<attribute::elementfield::tag_type, attribute::elementfield>::iterator dataset_iterator::next()
{
   // accumulate the size of the nested set's elements if a sequence size was
   // explicitly specified
   if (nested_set_sizes.top().curr_nestedset_max != 0xffff) {
      nested_set_sizes.top().curr_nestedset_size += cit->second.value_len + 4 + 4;
   }

   if (cit->first == SequenceDelimitationItem
       || (is_in_nested() && nested_set_sizes.top().curr_nestedset_size >= nested_set_sizes.top().curr_nestedset_max)) {
      //sequence delimination item encountered
      return (cit = step_outof_nested());
   } else if (cit->second.value_rep.is_initialized()) {
      if (cit->second.value_rep == VR::SQ) {
         cit = step_into_nested(cit);
         return cit;
      }
   } else if (commanddic.lookup(cit->first).vr == VR::SQ ||
              datadic.lookup(cit->first).vr == VR::SQ) {
      cit = step_into_nested(cit);
      return cit;
   }

   return ++cit;
}

std::map<attribute::elementfield::tag_type, attribute::elementfield>::iterator dataset_iterator::previous()
{
   auto curr = cit;
   --cit;
   if (is_in_nested() && (curr == nested_sets.top().begin() )) {
      return (cit = step_backw_outof_nested());
   } else if ((cit->second.value_rep.is_initialized() && cit->second.value_rep == VR::SQ) ||
              commanddic.lookup(cit->first).vr == VR::SQ ||
               datadic.lookup(cit->first).vr == VR::SQ) {
      return (cit = step_backw_into_nested(cit));
   }

   if (nested_set_sizes.top().curr_nestedset_max != 0xffff) {
      nested_set_sizes.top().curr_nestedset_size -= cit->second.value_len - (4 + 4);
   }

   return cit;
}

bool dataset_iterator::is_in_nested() const
{
   return parent_its.size() > 0;
}

dataset_iterator_adaptor::dataset_iterator_adaptor(std::map<elementfield::tag_type, elementfield> ds):
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

