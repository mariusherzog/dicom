#ifndef VMTYPE_HPP
#define VMTYPE_HPP


#include <functional>
#include <type_traits>
#include <vector>
#include <string>
#include <exception>
#include <algorithm>
#include <iterator>

#include <boost/algorithm/string.hpp>

#include "../attribute/tag.hpp"



namespace dicom
{

namespace data
{

namespace dataset
{
   /**
    * forward declaration of the dataset defined in the dataset namespace. This
    * circular dependency is intrinsic to the DICOM dataset, as an attribute
    * may be defined as another - nested - set.
    */
   struct dataset_type;
}

}

}



namespace dicom
{

namespace data
{

namespace attribute
{

inline bool rule_n(std::size_t multiplier, std::size_t current, std::size_t new_elements)
{
   return (current + new_elements) % multiplier == 0;
}

inline bool rule_less(std::size_t size, std::size_t current, std::size_t new_elements)
{
   return current + new_elements <= size;
}

inline bool rule_more(std::size_t size, std::size_t current, std::size_t new_elements)
{
   return current + new_elements >= size;
}

inline bool rule_equals(std::size_t size, std::size_t current, std::size_t new_elements)
{
   return current + new_elements == size;
}

/**
 * @brief The multiplicity_data struct contains structured data about the
 *        multiplicity of the value field
 */
struct multiplicity_data
{
      std::string multiplicity = "1";

   public:
      multiplicity_data(std::string mult):
         multiplicity(mult)
      {

      }
};




template <typename T>
class vmtype;

template <typename T>
std::size_t byte_length(const vmtype<T>& value_field)
{
   return value_field.byte_size();
}

std::size_t byte_length(std::vector<unsigned char> value_field);

std::size_t byte_length(const std::string& value_field);

std::size_t byte_length(unsigned char);

std::size_t byte_length(unsigned short);

std::size_t byte_length(short);

std::size_t byte_length(unsigned int);

std::size_t byte_length(long);

std::size_t byte_length(float);

std::size_t byte_length(double);

std::size_t byte_length(tag_type);

std::size_t byte_length(std::vector<dataset::dataset_type>);


/**
 * The vmtype class represents the value field of an attribute. It holds the
 * value(s) of type T and asserts the consistency of the appropriate value
 * multiplicity with the value count.
 * @tparam T type of the underlying data
 */
template <typename T>
class vmtype
{
   public:
      using base_type = T;

      /**
       * @brief vmtype initializes the field with the given multiplicity, no
       *        data.
       * @param mult multiplicity
       */
      vmtype(multiplicity_data mult):
         multiplicity {mult.multiplicity}
      {
         populate_mult_rules();
      }

      /**
       * @brief vmtype constructs a multivalued field with one entry
       * @param value value to be added
       */
      vmtype(T value)
      {
         const T* value_addr = &value;
         insert(value_addr, value_addr+1);
      }

      vmtype()
      {
      }

      /**
       * @brief vmtype stores a set of values in the field
       * @param multiplicity multiplicity of the field
       * @param values values to be stored
       */
      vmtype(multiplicity_data multiplicity, std::initializer_list<T> values):
         vmtype(multiplicity)
      {
         insert(values);
      }

      /**
       * @brief vmtype constructs a multi-valued field with values given by
       *        the iterators
       * @param multiplicity multiplicity of the field
       * @param begin start pointer of the values
       * @param end end pointer of the values
       */
      template <typename Iter>
      vmtype(std::string multiplicity, Iter begin, Iter end):
         vmtype(multiplicity_data(multiplicity))
      {
         insert(begin, end);
      }

      /**
       * @brief size
       * @return the number of stored elements in the value field
       */
      std::size_t size() const
      {
         return value_sequence.size();
      }

      /**
        * @brief The iterator struct is the iterator to navigate through the
        *        value field.
        */
      struct iterator : public std::iterator<std::random_access_iterator_tag, T>
      {
         private:
            vmtype* container;
            std::size_t index;

         public:
            iterator(vmtype* container, std::size_t index = 0):
               container {container},
               index {index}
            {
            }

            iterator operator++(int)
            {
               iterator temp = *this;
               index++;
               return temp;
            }

            iterator& operator++()
            {
               index++;
               return *this;
            }

            iterator& operator+=(std::size_t s)
            {
               index += s;
               return *this;
            }

            friend iterator operator+(const iterator& a, std::size_t s)
            {
               return a += s;
            }

            friend iterator operator+(std::size_t s, const iterator& a)
            {
               return a += s;
            }

            iterator operator--(int)
            {
               iterator temp = *this;
               index--;
               return temp;
            }

            iterator& operator--()
            {
               index--;
               return *this;
            }

            iterator& operator-=(std::size_t s)
            {
               index -= s;
               return *this;
            }

            friend iterator operator-(const iterator& a, std::size_t s)
            {
               return a -= s;
            }

            friend iterator operator-(std::size_t s, const iterator& a)
            {
               return a -= s;
            }

            T& operator[](std::size_t s) const
            {
               return container->value_sequence[s];
            }

            T operator*() const
            {
               return container->value_sequence[index];
            }

            T* operator->() const
            {
               return &container->value_sequence[index];
            }

            friend bool operator==(const iterator& lhs, const iterator& rhs)
            {
               return lhs.container == rhs.container && lhs.index == rhs.index;
            }

            friend bool operator!=(const iterator& lhs, const iterator& rhs)
            {
               return !(lhs == rhs);
            }

            friend bool operator<(const iterator& lhs, const iterator& rhs)
            {
               return lhs.index < rhs.index;
            }

            friend bool operator>(const iterator& lhs, const iterator& rhs)
            {
               return !(lhs < rhs || lhs == rhs);
            }

            friend bool operator<=(const iterator& lhs, const iterator& rhs)
            {
               return lhs < rhs || lhs == rhs;
            }

            friend bool operator>=(const iterator& lhs, const iterator& rhs)
            {
               return lhs > rhs || lhs == rhs;
            }
      };

      iterator begin()
      {
         return iterator {this};
      }

      iterator end()
      {
         return iterator {this, value_sequence.size()};
      }

      std::size_t byte_size() const
      {
         return std::accumulate(value_sequence.begin(), value_sequence.end(), 0, [](std::size_t accu, const T& val) { return accu + byte_length(val) + 1; }) - 1;
      }

   private:
      std::vector<T> value_sequence;
      std::string multiplicity;

      std::vector<std::function<bool(std::size_t, std::size_t)>> multiplicity_rules;

      /**
         * @brief validate_multiplicity verifies that the respective attribute's
         *        multiplicity definitions are satisfied.
         * @param num_new_elements number of new elements to be added
         * @pre multiplicity rule must be satisfied for the current number of
         *      elements.
         * @return
         */
      bool validate_multiplicity(std::size_t num_new_elements) const
      {
         return std::all_of(multiplicity_rules.begin()
                            , multiplicity_rules.end()
                            , [=](std::function<bool(std::size_t, std::size_t)> rule)
         { return rule(value_sequence.size(), num_new_elements); } );
      }

      /**
         * @brief populate_mult_rules parses the multiplicity definiton and adds
         *        all necessary rules.
         */
      void populate_mult_rules()
      {
         auto it = std::remove_if(multiplicity.begin(), multiplicity.end(), ::isspace);
         multiplicity.erase(it, multiplicity.end());

         std::vector<std::string> components;
         boost::split(components, multiplicity, boost::is_any_of("-"));

         using namespace std::placeholders;
         if (components.size() > 1) {
            if (components[1] == "") components[1] = "n";
            if (std::all_of(components[0].begin(), components[0].end(), ::isdigit)) {
               std::size_t lower = std::stoull(components[0]);
               if (std::all_of(components[1].begin(), components[1].end(), ::isdigit)) {
                  std::size_t upper = std::stoull(components[1]);
                  multiplicity_rules.push_back(std::bind(rule_more, lower, _1, _2));
                  multiplicity_rules.push_back(std::bind(rule_less, upper, _1, _2));
               } else if (components[1].find('n') != std::string::npos) {
                  std::string multiplier {components[1].begin(), components[1].begin() + components[1].find_last_of('n')};
                  if (multiplier == "") multiplier = "1";
                  multiplicity_rules.push_back(std::bind(rule_n, std::stoul(multiplier), _1, _2));
                  multiplicity_rules.push_back(std::bind(rule_more, lower, _1, _2));
               }
            }
         } else {
            if (std::all_of(components[0].begin(), components[0].end(), ::isdigit)) {
               std::size_t value = std::stoull(components[0]);
               multiplicity_rules.push_back(std::bind(rule_equals, value, _1, _2));
            } else if (components[0].find('n') != std::string::npos) {
               std::string multiplier {components[0].begin(), components[0].begin() + components[0].find_last_of('n')};
               if (multiplier == "") multiplier = "1";
               multiplicity_rules.push_back(std::bind(rule_n, std::stoul(multiplier), _1, _2));
               multiplicity_rules.push_back(std::bind(rule_more, 1, _1, _2));
            }
         }
      }

   public:
      virtual ~vmtype();

        operator T()
        {
            return value_sequence[0];
        }

      /**
       * @brief add adds all specified values to the attribute, if doing so
       *        does not break multiplicity conditions.
       * @param values list of values to be added.
       */
      void insert(std::initializer_list<T> values)
      {
         insert(values.begin(), values.end());
      }


      /**
       * @brief insert inserts all values in the range specified by the
       *        iterators.
       * @param begin iterator pointing to the beginning of the range
       * @param end iterator pointing to the end of the range
       */
      template <typename Iter>
      void insert(Iter begin, Iter end)
      {
         auto size = end-begin;
         if (!validate_multiplicity(size)) {
            throw new std::runtime_error("addition of " + std::to_string(size) +  " elements would violate the multiplicity rule: " + multiplicity);
         }
         std::copy(begin, end, std::back_inserter(value_sequence));
      }
};

template <typename T>
vmtype<T>::~vmtype()
{
}




std::ostream& operator<<(std::ostream& os, vmtype<std::string> data);

std::ostream& operator<<(std::ostream& os, const vmtype<attribute::tag_type> tag);

template <typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
std::ostream& operator<<(std::ostream& os, vmtype<T> data)
{
   for (T num : data)
   {
      os << num << " ";
   }
   return os;
}

template <typename T, typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr>
std::ostream& operator<<(std::ostream& os, vmtype<T> data)
{
   for (T num : data)
   {
      os << num << " ";
   }
   return os;
}

}

}

}

#endif // vmtype_HPP
