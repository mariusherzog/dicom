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
//            const char* bytedata = reinterpret_cast<const char*>(data.data());
//            return std::vector<unsigned char>(bytedata, bytedata+data.size()*sizeof(V));
            std::vector<unsigned char> resized_data;
            resized_data.resize(data.size());
            for (int i=0; i<data.size(); ++i) {
               resized_data[i] = 127 + 255.0*(data[i]/255.0);
            }
            return resized_data;
        }

        template <typename T, typename V = typename T::value_type>
        typename std::enable_if<std::is_unsigned<V>::value, std::vector<unsigned char>>::type operator()(const T& data) const
//         typename std::enable_if<std::is_same<V, unsigned char>::value, std::vector<unsigned char>>::type operator()(const T& data) const
        {
            std::cout << "is_unsigned" << std::flush;
            std::vector<unsigned char> resized_data;
            resized_data.resize(data.size());
            for (int i=0; i<data.size(); ++i) {
               resized_data[i] = 255.0*(data[i]/255.0);
            }
            return resized_data;
        }
};

#endif // TOBYTE_HPP
