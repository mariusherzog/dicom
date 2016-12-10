#include "attribute.hpp"

#include <iomanip>
#include <algorithm>
#include <iterator>

#include "constants.hpp"

namespace dicom
{

namespace data
{

namespace attribute
{

elementfield_base::~elementfield_base()
{
}



bool operator<(const tag_type& lhs, const tag_type& rhs)
{
   // Item tag should be placed first in a (nested) set
   if (lhs == Item) return true;
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

elementfield::elementfield(const elementfield& other):
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

void swap(elementfield& lhs, elementfield& rhs) noexcept
{
   using std::swap;
   swap(lhs.value_len, rhs.value_len);
   swap(lhs.value_rep, rhs.value_rep);
   swap(lhs.value_field, rhs.value_field);
}

bool operator!=(const tag_type& lhs, const tag_type& rhs)
{
   return !(lhs == rhs);
}


std::ostream& operator<<(std::ostream& os, const dicom::data::attribute::type_of<VR::OB>::type data)
{
   std::copy(data.begin(), data.end(), std::ostream_iterator<char>(os, " "));
   return os;
}

std::ostream& operator<<(std::ostream& os, const dicom::data::attribute::type_of<VR::NN>::type)
{
   return os;
}

std::ostream& operator<<(std::ostream& os, typename type_of<VR::SQ>::type const)
{
   return os << "";
}


}

}

}
