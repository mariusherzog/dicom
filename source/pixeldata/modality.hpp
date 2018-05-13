#ifndef MODALITY_HPP
#define MODALITY_HPP

#include <vector>
#include <type_traits>
#include <iostream>

#include <boost/variant.hpp>

#include "libdicompp/dicomdata.hpp"
#include "pixeltype.hpp"
#include "rgb.hpp"

class modality : public boost::static_visitor<pixeltype>
{
    private:
        dicom::data::dataset::dataset_type set;

        bool have_slope_intercept()
        {
           return set.find({0x0028, 0x1052}) != set.end() &&
                 set.find({0x0028, 0x1053}) != set.end();
        }

        void slope_intercept_from_set(double& slope, double& intercept)
        {
           std::string str_intercept  = set[{0x0028, 0x1052}].value<dicom::data::attribute::VR::DS>();
           std::string str_slope = set[{0x0028, 0x1053}].value<dicom::data::attribute::VR::DS>();
           intercept = std::stod(str_intercept);
           slope = std::stod(str_slope);
        }

    public:
        modality(dicom::data::dataset::dataset_type set):
            set {set}
        {
        }

        template <typename T, typename V = typename T::value_type>
        typename std::enable_if<std::is_integral<V>::value, pixeltype>::type operator()(T data)
        {
           double slope;
           double intercept;
           if (have_slope_intercept()) {
              slope_intercept_from_set(slope, intercept);
           } else {
              slope = 1;
              intercept = 0;
           }

           int high_bit = set[{0x0028, 0x0102}].value<dicom::data::attribute::VR::US>();
           int bits_stored = set[{0x0028, 0x0101}].value<dicom::data::attribute::VR::US>();
           int max_possible_value = ((1 << (high_bit+1))-1) * slope + intercept;
           int max_stored_value = (1 << bits_stored)-1;
           if (max_possible_value > max_stored_value) {
              std::vector<int> newdata;
              newdata.reserve(data.size());
              for (auto v : data) {
                  auto newval = v * slope + intercept;
                  newdata.push_back(newval);
              }

              return newdata;
           } else {
              for (auto& v : data) {
                  v *= slope + intercept;
              }
              return data;
           }
        }

        template <typename T, typename V = typename T::value_type, typename Q = typename V::base_type>
        typename std::enable_if<std::is_same<V, rgb<Q>>::value, pixeltype>::type operator()(T data)
        {
           return data;
        }
};

#endif // MODALITY_HPP
