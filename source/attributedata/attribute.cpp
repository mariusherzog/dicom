#include "attribute.hpp"


elementfield_base::~elementfield_base()
{
}


bool operator<(const elementfield& lhs, const elementfield& rhs)
{
   return lhs.tag.group_id == rhs.tag.group_id ?
            lhs.tag.element_id < rhs.tag.element_id :
            lhs.tag.group_id < rhs.tag.group_id;
}


