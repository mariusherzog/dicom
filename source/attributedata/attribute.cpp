#include "attribute.hpp"


elementfield_base::~elementfield_base()
{
}


bool operator<(const elementfield& lhs, const elementfield& rhs)
{
   return lhs.tag < rhs.tag;
}

bool operator<(const elementfield::tag_type& lhs
               , const elementfield::tag_type& rhs)
{
   return lhs.group_id == rhs.group_id ?
          lhs.element_id < rhs.element_id :
          lhs.group_id < rhs.group_id;
}


