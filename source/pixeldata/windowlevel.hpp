#ifndef WINDOWLEVEL_HPP
#define WINDOWLEVEL_HPP

#include <vector>
#include <type_traits>
#include <iostream>

#include <boost/variant.hpp>

#include "libdicompp/dicomdata.hpp"
#include "pixeltype.hpp"

class windowlevel : public boost::static_visitor<pixeltype>
{
    private:
        dicom::data::dataset::dataset_type set;

    public:
        windowlevel(dicom::data::dataset::dataset_type set):
            set {set}
        {
        }

        template <typename T, typename V = typename T::value_type>
        typename std::enable_if<std::is_integral<V>::value, pixeltype>::type operator()(T data)
        {
            std::string str_level  = set[{0x0028, 0x1050}].value<dicom::data::attribute::VR::DS>();
            std::string str_window = set[{0x0028, 0x1051}].value<dicom::data::attribute::VR::DS>();
            double level = std::stod(str_level);
            double window = std::stod(str_window);

//            double level = 600.0;
//            double window = 960.0;

            //level += 32767;

            for (auto& v : data) {
                double norm = (v - (level-(window/2.0)))/window;
                //double norm = ((v-(level-0.5))/(window-1)+0.5);
                if (norm < 0.0) norm = 0.0;
                if (norm > 1.0) norm = 1.0;
                v = 255.0*norm - 127.0;
            }

            return data;
        }

};


#endif // WINDOWLEVEL_HPP
