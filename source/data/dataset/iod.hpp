#ifndef IOD_HPP
#define IOD_HPP

#include <map>

#include "data/attribute/attribute.hpp"

namespace dicom
{

namespace data
{

namespace dataset
{

using iod = std::map<attribute::elementfield::tag_type, attribute::elementfield>;

}

}

}

#endif // IOD_HPP
