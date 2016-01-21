#ifndef DATASET_ITERATOR_HPP
#define DATASET_ITERATOR_HPP

#include <iterator>
#include <map>
#include <stack>

#include "attribute.hpp"
#include "../dictionary/dictionary_dyn.hpp"

class dataset_iterator: public std::iterator<std::bidirectional_iterator_tag, elementfield>
{
   public:
      dataset_iterator(std::set<elementfield>::iterator it);

      dataset_iterator operator++();

   private:
      std::set<elementfield>::iterator cit;

      std::stack<std::set<elementfield>> nested_sets;
      std::stack<std::set<elementfield>::iterator> parent_its;
      std::size_t curr_nestedset_size;
      std::size_t curr_nestedset_max;

      static dictionary_dyn commanddic;
      static dictionary_dyn datadic;

      std::set<elementfield>::iterator step_into_nested(std::set<elementfield>::iterator curr);
      std::set<elementfield>::iterator step_outof_nested();

      bool is_in_nested() const;
};

#endif // DATASET_ITERATOR_HPP
