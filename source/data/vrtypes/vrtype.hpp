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

bool rule_zero(std::size_t current, std::size_t new_elements)
{
    return current == 0 && new_elements == 0;
}

bool rule_one(std::size_t current, std::size_t new_elements)
{
    return current + new_elements <= 1;
}

bool rule_n(std::size_t multiplier, std::size_t current, std::size_t new_elements)
{
    return (current + new_elements) % multiplier == 0;
}

bool rule_s(std::size_t size, std::size_t current, std::size_t new_elements)
{
    return current + new_elements <= size;
}



template <char>
struct multiplicity_rule
{
        std::string name;
        std::function<bool(std::size_t, std::size_t)> rule;
};

template <>
struct multiplicity_rule<'0'>
{
        const std::function<bool(std::size_t, std::size_t)> rule = rule_zero;
};

template <>
struct multiplicity_rule<'1'>
{
        const std::function<bool(std::size_t, std::size_t)> rule = rule_one;
};

template <>
struct multiplicity_rule<'n'>
{
        const std::function<bool(std::size_t, std::size_t)> rule;

    public:
        multiplicity_rule(std::size_t multiplier = 1):
            rule { [=](std::size_t a, std::size_t b) { return rule_n(multiplier, a, b);} }
        {

        }
};

template <>
struct multiplicity_rule<'s'>
{
        const std::function<bool(std::size_t, std::size_t)> rule;

    public:
        multiplicity_rule(std::size_t size):
            rule { [=](std::size_t a, std::size_t b) { return rule_n(size, a, b);} }
        {

        }
};



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
            return std::any_of(multiplicity_rules.begin()
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

            for (const std::string c : components)
            {
                if (c == "0") {
                    multiplicity_rules.push_back(multiplicity_rule<'0'>{});
                } else if (c == "1") {
                    multiplicity_rules.push_back(multiplicity_rule<'1'>{});
                } else if (c.find('n') != std::string::npos) {
                    std::string multiplier {c.begin(), c.find_last_of('n')};
                    multiplicity_rules.push_back(multiplicity_rule<'n'>{std::stoul(multiplier)});
                } else if (std::all_of(c.begin(), c.end(), ::isdigit)) {
                    std::size_t size {std::stoul(c)};
                    multiplicity_rules.push_back(multiplicity_rule<'s'>{std::stoul(size)});
                } else {
                    throw new std::runtime_error("invalid multiplier specification");
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
