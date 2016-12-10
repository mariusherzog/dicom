#include "tag.hpp"

#include <iostream>
#include <iomanip>

namespace dicom
{

namespace data
{

namespace attribute
{

tag_type::tag_type(unsigned short gid, unsigned short eid):
    group_id {gid},
    element_id {eid}
{
}

std::ostream& operator<<(std::ostream& os, tag_type tag)
{
   std::ios state(nullptr);
   state.copyfmt(os);

   os << "(" << std::hex << std::setw(4) << std::setfill('0') << tag.group_id
      << "," << std::hex << std::setw(4) << std::setfill('0') << tag.element_id
      << ")";

   os.copyfmt(state);
   return os;
}

}

}

}
