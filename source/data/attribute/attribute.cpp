#include "attribute.hpp"


namespace dicom
{

namespace data
{

namespace attribute
{

elementfield_base::~elementfield_base()
{
}


bool operator<(const elementfield& lhs, const elementfield& rhs)
{
   dicom::data::attribute::operator<(lhs.tag, rhs.tag);
   return lhs.tag < rhs.tag;
}

bool operator<(const elementfield::tag_type& lhs, const elementfield::tag_type& rhs)
{
   return lhs.group_id == rhs.group_id ?
          lhs.element_id < rhs.element_id :
          lhs.group_id < rhs.group_id;
}


bool operator==(const elementfield::tag_type& lhs, const elementfield::tag_type& rhs)
{
   return lhs.group_id == rhs.group_id &&
          rhs.element_id == lhs.element_id;
}

}

}

}
