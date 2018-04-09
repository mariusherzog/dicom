#ifndef TOBYTE_HPP
#define TOBYTE_HPP

#include <vector>
#include <type_traits>
#include <iostream>

#include <boost/variant.hpp>

#include "pixeltype.hpp"

class tobyte : public boost::static_visitor<std::vector<unsigned char>>
{
    public:
        template <typename T, typename V = typename T::value_type>
        typename std::enable_if<std::is_signed<V>::value, std::vector<unsigned char>>::type operator()(const T& data) const
//         typename std::enable_if<std::is_same<V, char>::value, std::vector<unsigned char>>::type operator()(const T& data) const
        {
            std::cout << "is_signed" << std::flush;
            return std::vector<unsigned char>();
        }

        template <typename T, typename V = typename T::value_type>
        typename std::enable_if<std::is_unsigned<V>::value, std::vector<unsigned char>>::type operator()(const T& data) const
//         typename std::enable_if<std::is_same<V, unsigned char>::value, std::vector<unsigned char>>::type operator()(const T& data) const
        {
            std::cout << "is_unsigned" << std::flush;
            return std::vector<unsigned char>();
        }
};

#endif // TOBYTE_HPP
