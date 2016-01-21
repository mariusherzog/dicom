#include "dataset_iterator.hpp"

#include <stack>

dictionary_dyn dataset_iterator::commanddic =
{"/media/STORAGE/_files/Studium/Sem 5/Studienprojekt/dicom/dicom/commanddictionary.txt"};
dictionary_dyn dataset_iterator::datadic =
{"/media/STORAGE/_files/Studium/Sem 5/Studienprojekt/dicom/dicom/commanddictionary.txt"};

dataset_iterator::dataset_iterator(typename std::set<elementfield>::iterator it):
   cit {it}
{
}

dataset_iterator dataset_iterator::operator++()
{
   //auto cur = *cit;
   if (cit->value_rep.is_initialized()) {
      if (cit->value_rep == VR::SQ) {
         parent_its.push(cit); // save current position of the iterator
         std::set<elementfield> nested_set;
         get_value_field<VR::SQ>(*cit, nested_set);
         nested_sets.push(nested_set);
         cit = nested_sets.top().begin();
         return cit;
      }
   } else {
      if (commanddic.lookup(cit->tag.group_id, cit->tag.element_id).vr == VR::SQ ||
          datadic.lookup(cit->tag.group_id, cit->tag.element_id).vr == VR::SQ) {
         parent_its.push(cit); // save current position of the iterator
         std::set<elementfield> nested_set;
         get_value_field<VR::SQ>(*cit, nested_set);
         cit = nested_set.begin();
         return cit;
      }
   }
   return ++cit;
}




