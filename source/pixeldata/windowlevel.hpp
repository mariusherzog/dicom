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

/**
 * @brief windowlevel_linear performs a linear mapping as given by the window
 *        / level parameters. This is the default.
 * @param window window
 * @param level level
 * @param value value to which to apply the w/l function
 * @return mapped value
 */
double windowlevel_linear(double window, double level, double value);

/**
 * @brief windowlevel_sigmoid performs a sigmoidal mapping with the specified
 *        window / level parameters
 * @param window window
 * @param level level
 * @param value value to which to apply the w/l function
 * @return transformed value.
 */
double windowlevel_sigmoid(double window, double level, double value);

/**
 * @brief windowlevel_linearexact performs an exact linear mapping with the
 *        specified window / level parameters, ie. there is no special handling
 *        which result in thresholding for window = 1
 * @param window window
 * @param level level
 * @param value value to which to apply the w/l function
 * @return transformed value
 */
double windowlevel_linearexact(double window, double level, double value);


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


        std::function<double(double, double, double)>
        get_windowlevel_function_for_set()
        {
           if (set.find({0x0028, 0x1056}) != set.end()) {
              std::string function = set[{0x0028, 0x1056}].value<dicom::data::attribute::VR::CS>();
              if (function == "SIGMOID ") {
                 return windowlevel_sigmoid;
              } else if (function == "LINEAR_EXACT") {
                 return windowlevel_linearexact;
              }
           }
           return windowlevel_linear;
        }

        void get_window_level(double& window, double& level)
        {
           if (have_window_level()) {
              window_level_from_set(window, level);
           } else {
              /// @todo estimate
              window = 1000;
              level = 300;
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
           double window;
           double level;
           get_window_level(window, level);

           auto fun = get_windowlevel_function_for_set();
           for (auto& v : data) {
              v = fun(window, level, v);
           }

           return data;
        }

        template <typename T, typename V = typename T::value_type, typename Q = typename V::base_type>
        typename std::enable_if<std::is_same<V, rgb<Q>>::value, pixeltype>::type operator()(T data)
        {
           return data;
        }
};



double windowlevel_linear(double window, double level, double value)
{
   double norm;
   if (value <= level-0.5-window/2.0) {
      //norm = offset;
      norm = 0.0;
   } else if (value > level-0.5+window/2.0) {
      //norm = offset+255;
      norm = 1.0;
   } else {
      norm = ((value-level-0.5) / (window-1.0)) + 0.5;
   }
   // 255.0 * norm - offset;
   return 255 * norm;
}

double windowlevel_sigmoid(double window, double level, double value)
{
   return 255.0 / (1+ std::exp(-4*(value-level)/window));
}

double windowlevel_linearexact(double window, double level, double value)
{
   window = std::max(window, 1.0);
   double norm;
   if (value <= level-window/2.0) {
      norm = 0.0;
   } else if (value > level+window/2.0) {
      norm = 1.0;
   } else {
      norm = ((value-level) / (window));
   }
   return 255 * norm;
}


#endif // WINDOWLEVEL_HPP
