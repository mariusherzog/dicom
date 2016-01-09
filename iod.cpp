#include "iod.hpp"

bool operator<(const elementfield& lhs, const elementfield& rhs)
{
   return lhs.tag.group_id == rhs.tag.group_id ?
            lhs.tag.element_id < rhs.tag.element_id :
            lhs.tag.group_id < rhs.tag.group_id;
}


std::ostream& operator<<(std::ostream& os, elementfield& attribute)
{
   os << "(" << attribute.tag.group_id << "," << attribute.tag.element_id << ")"
      << " " << attribute.value_len << " bytes. Data: "
      << attribute.value_field << "\n";
   return os;
}

