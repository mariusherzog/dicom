#ifndef VRTYPE_HPP
#define VRTYPE_HPP


#include <functional>

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

namespace vrtype
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

struct multiplicity_data
{
        std::string multiplicity = "1";

    public:
        multiplicity_data(std::string mult):
            multiplicity(mult)
        {

        }
};


/**
 * The vrtype class represents the value field of an attribute. It holds the
 * value(s) of type T and asserts the consistency of the appropriate value
 * multiplicity with the value count.
 * @tparam T type of the underlying data
 */
template <typename T>
class vrtype
{
    public:
        using base_type = T;

        vrtype(multiplicity_data mult):
            multiplicity {mult.multiplicity}
        {
            populate_mult_rules();
        }

        vrtype(T value)
        {
            const T* value_addr = &value;
            insert(value_addr, value_addr+1);
        }

        vrtype()
        {

        }

        vrtype(std::string multiplicity, std::initializer_list<T> values):
            vrtype(multiplicity)
        {
            insert(values);
        }

        template <typename Iter>
        vrtype(std::string multiplicity, Iter begin, Iter end):
            vrtype(multiplicity_data(multiplicity))
        {
            insert(begin, end);
        }

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
                vrtype* container;
                std::size_t index;

            public:
                iterator(vrtype* container, std::size_t index = 0):
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
        virtual ~vrtype();

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
vrtype<T>::~vrtype()
{
}


std::ostream& operator<<(std::ostream& os, vrtype<std::string> data);

std::ostream& operator<<(std::ostream& os, vrtype<attribute::tag_type> tag);

}

}

}

#endif // VRTYPE_HPP
