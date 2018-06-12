#ifndef TOBYTE_HPP
#define TOBYTE_HPP

#include <vector>
#include <type_traits>
#include <iostream>
#include <limits>

#include <boost/variant.hpp>

#include "libdicompp/dicomdata.hpp"
#include "pixeltype.hpp"
#include "rgb.hpp"


template <typename O, std::size_t RNG = sizeof(O)>
class presentation : public boost::static_visitor<std::vector<O>>
{
   private:
      dicom::data::dataset::dataset_type set;

   public:
      presentation(dicom::data::dataset::dataset_type set):
         set {set}
      {
         // for now assume Presentation LUT Shape (2050,0020) is always LINEAR
      }


      template <typename T, typename V = typename T::value_type>
      typename std::enable_if<std::is_signed<V>::value, std::vector<unsigned char>>::type operator()(const T& data) const
      {
         std::vector<O> resized_data;
         resized_data.resize(data.size());
         for (int i=0; i<data.size(); ++i) {
            resized_data[i] = RNG*(data[i]/(RNG*1.0));
         }
         return resized_data;
      }

      template <typename T, typename V = typename T::value_type>
      typename std::enable_if<std::is_unsigned<V>::value, std::vector<unsigned char>>::type operator()(const T& data) const
      {
         std::vector<O> resized_data;
         resized_data.resize(data.size());
         for (int i=0; i<data.size(); ++i) {
            resized_data[i] = RNG*(data[i]/(RNG*1.0));
         }
         return resized_data;
      }

      template <typename T, typename V = typename T::value_type, typename Q = typename V::base_type>
      typename std::enable_if<std::is_same<V, rgb<Q>>::value, std::vector<unsigned char>>::type operator()(T data)
      {
         /// @todo palette color lut transformation

         std::vector<O> resized_data;
         resized_data.resize(data.size()*3);
         std::size_t j = 0;
         for (int i=0; i<data.size(); ++i) {
            resized_data[j++] = RNG*(data[i].r/(RNG*1.0));
            resized_data[j++] = RNG*(data[i].g/(RNG*1.0));
            resized_data[j++] = RNG*(data[i].b/(RNG*1.0));
         }
         return resized_data;
      }
};

#endif // TOBYTE_HPP
