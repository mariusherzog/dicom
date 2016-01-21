#include "dataset_iterator.hpp"

#include <stack>

dictionary_dyn dataset_iterator::commanddic =
{"/media/STORAGE/_files/Studium/Sem 5/Studienprojekt/dicom/dicom/commanddictionary.txt"};
dictionary_dyn dataset_iterator::datadic =
{"/media/STORAGE/_files/Studium/Sem 5/Studienprojekt/dicom/dicom/commanddictionary.txt"};

dataset_iterator::dataset_iterator(typename std::set<elementfield>::iterator it):
   cit {it},
   curr_nestedset_size {0},
   curr_nestedset_max {0}
{
}

dataset_iterator dataset_iterator::operator++()
{
   if ((cit->tag.group_id == (0xfffe) && cit->tag.element_id == (0xe0dd))
       || (is_in_nested() && curr_nestedset_size >= curr_nestedset_max)) {
      //sequence delimination item encountered
      return (cit = step_outof_nested());
   }

   if (cit->value_rep.is_initialized()) {
      if (cit->value_rep == VR::SQ) {
         cit = step_into_nested(cit);
         return cit;
      }
   } else {
      if (commanddic.lookup(cit->tag.group_id, cit->tag.element_id).vr == VR::SQ ||
          datadic.lookup(cit->tag.group_id, cit->tag.element_id).vr == VR::SQ) {
         cit = step_into_nested(cit);
         return cit;
      }
   }

   if (curr_nestedset_max != 0xffff) {
      curr_nestedset_size += cit->value_len + 4 + 4;
   }

   return ++cit;
}

std::set<elementfield>::iterator dataset_iterator::step_into_nested(std::set<elementfield>::iterator curr)
{
   parent_its.push(curr); // save current position of the iterator
   curr_nestedset_max = curr->value_len;
   curr_nestedset_size = 0;
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
   curr_nestedset_max = curr_nestedset_size = 0;
   return ++last;
}

bool dataset_iterator::is_in_nested() const
{
   return parent_its.size() > 0;
}


