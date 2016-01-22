#include "dataset_iterator.hpp"

#include <stack>

dictionary_dyn dataset_iterator::commanddic =
{"/media/STORAGE/_files/Studium/Sem 5/Studienprojekt/dicom/dicom/commanddictionary.txt"};
dictionary_dyn dataset_iterator::datadic =
{"/media/STORAGE/_files/Studium/Sem 5/Studienprojekt/dicom/dicom/commanddictionary.txt"};

dataset_iterator::dataset_iterator(typename std::set<elementfield>::iterator it):
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


elementfield dataset_iterator::operator*() const
{
   return *cit;
}


const elementfield* dataset_iterator::operator->() const
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

std::set<elementfield>::iterator dataset_iterator::step_into_nested(std::set<elementfield>::iterator curr)
{
   parent_its.push(curr); // save current position of the iterator
   nested_set_sizes.push({0, curr->value_len});
   std::set<elementfield> nested_set;
   get_value_field<VR::SQ>(*curr, nested_set);
   nested_sets.push(nested_set);
   curr = nested_sets.top().begin();
   return curr;
}

std::set<elementfield>::iterator dataset_iterator::step_outof_nested()
{
   auto last = parent_its.top();
   parent_its.pop();
   nested_sets.pop();
   nested_set_sizes.pop();
   return ++last;
}

std::set<elementfield>::iterator dataset_iterator::step_backw_into_nested(std::set<elementfield>::iterator prev)
{
   bool explicitlength = true;
   parent_its.push(prev);
   nested_set_sizes.push({prev->value_len, prev->value_len});
   if (nested_set_sizes.top().curr_nestedset_max != 0xffff) {
      nested_set_sizes.top().curr_nestedset_size = nested_set_sizes.top().curr_nestedset_max;
   } else {
      auto pprev =--prev;
      assert(pprev->tag.group_id == (0xfffe) && pprev->tag.element_id == (0xe0dd));
      explicitlength = false;
   }
   std::set<elementfield> nested_set;
   get_value_field<VR::SQ>(*prev, nested_set);
   nested_sets.push(nested_set);
   auto curr = --nested_sets.top().end();
   return explicitlength ? curr : --curr;
}

std::set<elementfield>::iterator dataset_iterator::step_backw_outof_nested()
{
   auto last = parent_its.top();
   parent_its.pop();
   nested_sets.pop();
   nested_set_sizes.pop();
   return --last;
}

std::set<elementfield>::iterator dataset_iterator::next()
{
   if ((cit->tag.group_id == (0xfffe) && cit->tag.element_id == (0xe0dd))
       || (is_in_nested() && nested_set_sizes.top().curr_nestedset_size >= nested_set_sizes.top().curr_nestedset_max)) {
      //sequence delimination item encountered
      return (cit = step_outof_nested());
   } else if (cit->value_rep.is_initialized()) {
      if (cit->value_rep == VR::SQ) {
         cit = step_into_nested(cit);
         return cit;
      }
   } else if (commanddic.lookup(cit->tag.group_id, cit->tag.element_id).vr == VR::SQ ||
              datadic.lookup(cit->tag.group_id, cit->tag.element_id).vr == VR::SQ) {
      cit = step_into_nested(cit);
      return cit;
   }

   // accumulate the size of the nested set's elements if a sequence size was
   // explicitly specified
   if (nested_set_sizes.top().curr_nestedset_max != 0xffff) {
      nested_set_sizes.top().curr_nestedset_size += cit->value_len + 4 + 4;
   }

   return ++cit;
}

std::set<elementfield>::iterator dataset_iterator::previous()
{
   auto curr = cit;
   --cit;
   if (is_in_nested() && (curr == nested_sets.top().begin() )) {
      return (cit = step_backw_outof_nested());
   } else if ((cit->value_rep.is_initialized() && cit->value_rep == VR::SQ) ||
              commanddic.lookup(cit->tag.group_id, cit->tag.element_id).vr == VR::SQ ||
               datadic.lookup(cit->tag.group_id, cit->tag.element_id).vr == VR::SQ) {
      return (cit = step_backw_into_nested(cit));
   }

   if (nested_set_sizes.top().curr_nestedset_max != 0xffff) {
      nested_set_sizes.top().curr_nestedset_size -= cit->value_len - (4 + 4);
   }

   return cit;
}

bool dataset_iterator::is_in_nested() const
{
   return parent_its.size() > 0;
}


