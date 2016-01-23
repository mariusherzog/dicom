#ifndef DATASET_ITERATOR_HPP
#define DATASET_ITERATOR_HPP

#include <iterator>
#include <map>
#include <stack>

#include "attribute.hpp"
#include "../dictionary/dictionary_dyn.hpp"

/**
 * @brief The dataset iterator provides an easy-to-use interface for
 *        traversing a DICOM dataset bidirectionally.
 * The dataset, which spans a tree with its nested sequences, is traversed in a
 * depth-first-order. When a sequence item is encountered, its subset is pushed
 * onto a stack. The increment and decrement operations operate on the set on
 * the top of the stack, and will pop it off if the sequence is finished to
 * continue to traverse the sequence-containing set.
 */
class dataset_iterator: public std::iterator<std::bidirectional_iterator_tag, elementfield>
{
   public:
      dataset_iterator(std::set<elementfield>::iterator it);

      dataset_iterator operator++();
      dataset_iterator operator++(int);

      dataset_iterator operator--();
      dataset_iterator operator--(int);

      elementfield operator*() const;

      elementfield const * operator->() const;

      friend bool operator==(const dataset_iterator& lhs, const dataset_iterator& rhs);

   private:
      std::set<elementfield>::iterator cit;

      std::stack<std::set<elementfield>> nested_sets;
      std::stack<std::set<elementfield>::iterator> parent_its;

      /**
       * @brief The set_size struct is a pod to hold data of the accumulated
       *        size and the maximum size of a sequence.
       */
      struct set_size
      {
            std::size_t curr_nestedset_size;
            std::size_t curr_nestedset_max;
      };

      std::stack<set_size> nested_set_sizes;

      static dictionary_dyn commanddic;
      static dictionary_dyn datadic;

      /**
       * @brief step_into_nested is called by next() if a sequence item is
       *        encountered. The subset is pushed onto the top of the set stack.
       * @param curr set-iterator pointing to the sequence item.
       * @return iterator to the first element of the nested set.
       */
      std::set<elementfield>::iterator step_into_nested(std::set<elementfield>::iterator curr);

      /**
       * @brief step_outof_nested is called when the nested set is completely
       *        traversed. The subset is popped off the stack.
       * @return iterator to the first element after the set.
       * A nested sequence is finished if either a delimitation item is
       * encountered (tag = (0xfffe, 0xe0dd)) or the accumulated size of
       * traversed items is larger than the size specified in the respective SQ
       * item.
       */
      std::set<elementfield>::iterator step_outof_nested();

      /**
       * @brief step_backw_into_nested is called if the previous item is a
       *        sequence item, which then will be pushed onto the set stack.
       * @param prev set-iterator pointing to the sequence item.
       * @return iterator to the last element of the nested set.
       */
      std::set<elementfield>::iterator step_backw_into_nested(std::set<elementfield>::iterator prev);

      /**
       * @brief step_backw_outof_nested is called when the nested set is
       *        completely traversed backwards. The subset is popped off the
       *        stack.
       * @return iterator to the element before the sequence.
       */
      std::set<elementfield>::iterator step_backw_outof_nested();

      std::set<elementfield>::iterator next();
      std::set<elementfield>::iterator previous();

      /**
       * @brief is_in_nested checks if the iterator points into a sequence item.
       * @return true if iterator points into a sequence item, false otherwise.
       */
      bool is_in_nested() const;
};

bool operator==(const dataset_iterator& lhs, const dataset_iterator& rhs);
bool operator!=(const dataset_iterator& lhs, const dataset_iterator& rhs);

#endif // DATASET_ITERATOR_HPP
