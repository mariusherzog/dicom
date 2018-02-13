#include "uid.hpp"

#include <algorithm>

namespace dicom
{

namespace util
{

uid::uid(std::string prefix):
    prefix {prefix},
    generator {boost::uuids::random_generator {}}
{
}

std::string uid::generate_uid(std::string suffix)
{
   std::string uuid = boost::uuids::to_string(generator());
   std::replace(std::begin(uuid), std::end(uuid), '-', '.');
   std::string final_uid = prefix + (prefix.size() == 0 ? "" : ".") +
         uuid + (suffix.size() == 0 ? "" : ".") +
         suffix;
   return final_uid;
}

}

}
