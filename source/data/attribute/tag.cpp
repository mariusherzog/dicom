#include "tag.hpp"

#include <iostream>
#include <iomanip>

#include "constants.hpp"

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

std::ostream& operator<<(std::ostream& os, const tag_type tag)
{
   std::ios state(nullptr);
   state.copyfmt(os);

   os << "(" << std::hex << std::setw(4) << std::setfill('0') << tag.group_id
      << "," << std::hex << std::setw(4) << std::setfill('0') << tag.element_id
      << ")";

   os.copyfmt(state);
   return os;
}

bool operator<(const tag_type& lhs, const tag_type& rhs)
{
   // Item tag should be placed first in a (nested) set
   // but prevent that index operator for map inserts
   // dupe Items
   //if (lhs == Item && rhs == Item) return false;
   if (lhs == Item && rhs != Item) return true;
   if (rhs == Item && lhs != Item) return false;
   return lhs.group_id == rhs.group_id ?
          lhs.element_id < rhs.element_id :
          lhs.group_id < rhs.group_id;
}

bool operator==(const tag_type& lhs, const tag_type& rhs)
{
   return lhs.group_id == rhs.group_id &&
         rhs.element_id == lhs.element_id;
}

bool operator!=(const tag_type& lhs, const tag_type& rhs)
{
   return !(lhs == rhs);
}

}

}

}
