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

elementfield::elementfield(const elementfield& other):
   tag { tag_type {other.tag.group_id, other.tag.element_id} },
   value_rep {other.value_rep},
   value_len {other.value_len},
   value_field {other.value_field.get()->deep_copy()}
{
}

elementfield& elementfield::operator=(elementfield other)
{
   swap(*this, other);
   return *this;
}

elementfield::tag_type::tag_type(unsigned short gid, unsigned short eid):
   group_id {gid},
   element_id {eid}
{
}

void swap(elementfield& lhs, elementfield& rhs) noexcept
{
   using std::swap;
   swap(lhs.tag, rhs.tag);
   swap(lhs.value_len, rhs.value_len);
   swap(lhs.value_rep, rhs.value_rep);
   swap(lhs.value_field, rhs.value_field);
}

bool operator!=(const elementfield::tag_type& lhs, const elementfield::tag_type& rhs)
{
   return !(lhs == rhs);
}

}

}

}
