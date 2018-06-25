#ifndef TOBYTE_HPP
#define TOBYTE_HPP

#include <vector>
#include <type_traits>
#include <iostream>
#include <limits>
#include <string>

#include <boost/variant.hpp>

#include "libdicompp/dicomdata.hpp"
#include "pixeltype.hpp"
#include "rgb.hpp"


template <typename O, std::size_t RNG = sizeof(O)>
class presentation : public boost::static_visitor<std::vector<O>>
{
   private:
      dicom::data::dataset::dataset_type set;

      bool is_inverse_lut_shape() const
      {
         using namespace dicom::data::attribute;
         if (contains_tag(set, {0x2050, 0x0020})) {
            std::string lut_shape = set.at({0x2050, 0x0020}).value<VR::CS>();
            return lut_shape == "INVERSE ";
         }
         return false;
      }

      bool is_monochrome1() const
      {
         using namespace dicom::data::attribute;
         if (contains_tag(set, {0x0028, 0x0004})) {
            std::string photo_interpretation = set.at({0x0028, 0x0004}).value<VR::CS>();
            return photo_interpretation == "MONOCHROME1 ";
         }
         return false;
      }

      bool needs_inversion() const
      {
         return is_monochrome1() ^ is_inverse_lut_shape();
      }

   public:
      presentation(dicom::data::dataset::dataset_type set):
         set {set}
      {
      }


      template <typename T, typename V = typename T::value_type>
      typename std::enable_if<std::is_signed<V>::value, std::vector<unsigned char>>::type operator()(const T& data) const
      {
         std::vector<O> resized_data;
         resized_data.resize(data.size());
         for (int i=0; i<data.size(); ++i) {
            resized_data[i] = RNG*(data[i]/(RNG*1.0));
            if (needs_inversion()) {
               resized_data[i] = RNG - resized_data[i];
            }
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
            if (needs_inversion()) {
               resized_data[i] = RNG - resized_data[i];
            }
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
