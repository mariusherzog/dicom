#ifndef TOBYTE_HPP
#define TOBYTE_HPP

#include <vector>
#include <type_traits>
#include <iostream>
#include <limits>

#include <boost/variant.hpp>

#include "pixeltype.hpp"

class tobyte : public boost::static_visitor<std::vector<unsigned char>>
{
    public:
        template <typename T, typename V = typename T::value_type>
        typename std::enable_if<std::is_signed<V>::value, std::vector<unsigned char>>::type operator()(const T& data) const
        {
            std::cout << "is_signed" << std::flush;
            std::vector<unsigned char> resized_data;
            resized_data.resize(data.size());
            for (int i=0; i<data.size(); ++i) {
               resized_data[i] = /*127 +*/ 255.0*(data[i]/255.0);
            }
            return resized_data;
        }

        template <typename T, typename V = typename T::value_type>
        typename std::enable_if<std::is_unsigned<V>::value, std::vector<unsigned char>>::type operator()(const T& data) const
        {
            std::cout << "is_unsigned" << std::flush;
            std::vector<unsigned char> resized_data;
            resized_data.resize(data.size());
            for (int i=0; i<data.size(); ++i) {
               resized_data[i] = 255.0*(data[i]/255.0);
            }
            return resized_data;
        }

      template <typename T, typename V = typename T::value_type, typename Q = typename V::base_type>
      typename std::enable_if<std::is_same<V, rgb<Q>>::value, std::vector<unsigned char>>::type operator()(T data)
      {
         std::cout << "rgb" << std::flush;
         std::vector<unsigned char> resized_data;
         resized_data.resize(data.size()*3);
         std::size_t j = 0;
         for (int i=0; i<data.size(); ++i) {
            resized_data[j++] = 255.0*(data[i].r/255.0);
            resized_data[j++] = 255.0*(data[i].g/255.0);
            resized_data[j++] = 255.0*(data[i].b/255.0);
         }
         return resized_data;
      }
};

#endif // TOBYTE_HPP
