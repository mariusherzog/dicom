#ifndef PIXELTYPE_HPP
#define PIXELTYPE_HPP

#include <vector>

#include <boost/variant.hpp>

#include "rgb.hpp"

using pixeltype = boost::variant<
    std::vector<unsigned char>,
    std::vector<signed char>,
    std::vector<char>,
    std::vector<unsigned short>,
    std::vector<short>,
    std::vector<unsigned int>,
    std::vector<int>,

    std::vector<rgb<unsigned char>>,
    std::vector<rgb<unsigned short>>,
    std::vector<rgb<unsigned>>
>;

#endif // PIXELTYPE_HPP
