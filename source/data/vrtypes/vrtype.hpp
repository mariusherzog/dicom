#ifndef VRTYPE_HPP
#define VRTYPE_HPP

#include <vector>
#include <string>
#include <exception>
#include <algorithm>
#include <functional>

#include <boost/algorithm/string.hpp>

namespace dicom
{

namespace data
{

namespace vrtype
{

bool rule_n(std::size_t multiplier, std::size_t current, std::size_t new_elements)
{
    return (current + new_elements) % multiplier == 0;
}

bool rule_less(std::size_t size, std::size_t current, std::size_t new_elements)
{
    return current + new_elements <= size;
}

bool rule_more(std::size_t size, std::size_t current, std::size_t new_elements)
{
    return current + new_elements >= size;
}

bool rule_equals(std::size_t size, std::size_t current, std::size_t new_elements)
{
    return current + new_elements == size;
}



template <typename T>
class vrtype
{
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

            if (components.size() > 1) {
                if (std::all_of(components[0].begin(), components[0].end(), ::isdigit)) {
                    std::size_t lower = std::stoull(components[0]);
                    if (std::all_of(components[1].begin(), components[1].end(), ::isdigit)) {
                        std::size_t upper = std::stoull(components[1]);
                        multiplicity_rules.push_back(std::bind1st(rule_more, lower));
                        multiplicity_rules.push_back(std::bind1st(rule_less, upper));
                    } else if (components[1].find('n') != std::string::npos) {
                        std::string multiplier {components[1].begin(), components[1].find_last_of('n')};
                        multiplicity_rules.push_back(std::bind1st(rule_n, std::stoul(multiplier)));
                        multiplicity_rules.push_back(std::bind1st(rule_more, lower));
                    }
                }
            } else {
                if (std::all_of(components[0].begin(), components[0].end(), ::isdigit)) {
                    std::size_t value = std::stoull(components[0]);
                    multiplicity_rules.push_back(std::bind1st(rule_equals, value));
                } else if (components[0].find('n') != std::string::npos) {
                    std::string multiplier {components[0].begin(), components[0].find_last_of('n')};
                    multiplicity_rules.push_back(std::bind1st(rule_n, std::stoul(multiplier)));
                    multiplicity_rules.push_back(std::bind1st(rule_more, 1));
                }
            }
        }


   protected:
        vrtype(std::string multiplicity):
          multiplicity {multiplicity}
      {
          populate_mult_rules();
      }

      vrtype(std::string multiplicity, std::initializer_list<T> values):
          vrtype(multiplicity)
      {
          add(values);
      }


    public:
      virtual ~vrtype() = 0;

      /**
       * @brief is_sequence checks if the attribute can hold more than one value.
       * @return
       */
      bool is_sequence() const
      {
          return !multiplicity == "0" &&
                 !multiplicity == "1";
      }

      /**
       * @brief add adds all specified values to the attribute, if doing so
       *        does not break multiplicity conditions.
       * @param values list of values to be added.
       */
      void add(std::initializer_list<T> values)
      {
          if (!is_sequence()) {
              throw new std::runtime_error("can't add to a non-sequence!");
          }
          if (!validate_multiplicity(values.size())) {
              throw new std::runtime_error("addition of " + values.size() +  " elements would violate the multiplicity rule: " + multiplicity);
          }
          std::copy(values.begin(), values.end(), std::back_inserter(value_sequence));
          value_sequence.push_back(element);
      }
};

template <typename T>
vrtype<T>::~vrtype()
{
}

}

}

}

#endif // VRTYPE_HPP
