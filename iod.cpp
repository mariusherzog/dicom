#include "iod.hpp"

bool operator<(const attribute_base& lhs, const attribute_base& rhs)
{
   return lhs.tag.group_id == rhs.tag.group_id ?
            lhs.tag.element_id < rhs.tag.element_id :
            lhs.tag.group_id < rhs.tag.group_id;
}
