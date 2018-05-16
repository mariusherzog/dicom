#ifndef WINDOWLEVEL_HPP
#define WINDOWLEVEL_HPP

#include <vector>
#include <type_traits>
#include <iostream>
#include <limits>

#include <boost/variant.hpp>

#include "libdicompp/dicomdata.hpp"
#include "pixeltype.hpp"
#include "rgb.hpp"

class windowlevel : public boost::static_visitor<pixeltype>
{
    private:
        dicom::data::dataset::dataset_type set;

        bool have_window_level()
        {
           return set.find({0x0028, 0x1050}) != set.end() &&
                 set.find({0x0028, 0x1051}) != set.end();
        }

        void window_level_from_set(double& window, double& level)
        {
           std::string str_level  = set[{0x0028, 0x1050}].value<dicom::data::attribute::VR::DS>();
           std::string str_window = set[{0x0028, 0x1051}].value<dicom::data::attribute::VR::DS>();
           level = std::stod(str_level);
           window = std::stod(str_window);
        }

        bool is_sigmoid_function()
        {
           if (set.find({0x0028, 0x1056}) != set.end()) {
              std::string function = set[{0x0028, 0x1056}].value<dicom::data::attribute::VR::CS>();
              return function == "SIGMOID ";
           } else {
              return false;
           }
        }

    public:
        windowlevel(dicom::data::dataset::dataset_type set):
            set {set}
        {
        }

        template <typename T, typename V = typename T::value_type>
        typename std::enable_if<std::is_integral<V>::value, pixeltype>::type operator()(T data)
        {
           double level;
           double window;
           if (have_window_level()) {
              window_level_from_set(window, level);
           } else {
              // todo estimate
              window = 1000;
              level = 300;
           }

           //constexpr std::size_t offset = std::is_signed<V>::value ? std::numeric_limits<V>::max() : 0;

           auto offset = 0;

           if (!is_sigmoid_function()) {
              for (auto& v : data) {
                 double norm;
                 if (v <= level-0.5-window/2.0) {
                    //norm = offset;
                    norm = 0.0;
                 } else if (v > level-0.5+window/2.0) {
                    //norm = offset+255;
                    norm = 1.0;
                 } else {
                    norm = ((v-level-0.5) / (window-1.0)) + 0.5;
                 }
                 //v = 255.0*norm - offset;
                 v = 255 * norm - offset;
              }
           } else {
              for (auto& v : data) {
                 v = 255.0 / (1+ std::exp(-4*(v-level)/window ));
              }
           }

           return data;
        }

        template <typename T, typename V = typename T::value_type, typename Q = typename V::base_type>
        typename std::enable_if<std::is_same<V, rgb<Q>>::value, pixeltype>::type operator()(T data)
        {
           return data;
        }
};


#endif // WINDOWLEVEL_HPP
