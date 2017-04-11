#include "attribute.hpp"

#include <iomanip>
#include <algorithm>
#include <iterator>

namespace dicom
{

namespace data
{

namespace attribute
{

elementfield_base::~elementfield_base()
{
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


template <>
std::size_t validate<VR::UI>(typename type_of<VR::UI>::type& value_field)
{
   auto max_len = type_of<VR::UI>::max_len;
   for (auto it = value_field.begin(); it != value_field.end(); ++it) {
      auto& uid = *it;
      if (uid.length() > max_len) {
         uid.resize(max_len);
      }
      if (uid.length() % 2 != 0) {
         uid.resize(uid.length()+1);
      }
   }
   auto size = byte_length(value_field);
   return size;
}

template <>
std::size_t validate<VR::UT>(typename type_of<VR::UT>::type& value_field)
{
   auto size = byte_length(value_field);
   if (size > type_of<VR::UT>::max_len) {
      value_field.resize(type_of<VR::UT>::max_len);
   }
   if (value_field.length() % 2 != 0) {
      value_field.resize(value_field.length()+1);
   }
   return byte_length(value_field);
}

template <>
std::size_t validate<VR::ST>(typename type_of<VR::ST>::type& value_field)
{
   auto size = byte_length(value_field);
   if (size > type_of<VR::ST>::max_len) {
      value_field.resize(type_of<VR::ST>::max_len);
   }
   if (value_field.length() % 2 != 0) {
      value_field.resize(value_field.length()+1);
   }
   return byte_length(value_field);
}

template <>
std::size_t validate<VR::PN>(typename type_of<VR::PN>::type& value_field)
{
   // todo: complete this
   auto max_len = type_of<VR::PN>::max_len;
   for (auto it = value_field.begin(); it != value_field.end(); ++it) {
      auto& uid = *it;
      if (uid.length() > max_len) {
         uid.resize(max_len);
      }
      if (uid.length() % 2 != 0) {
         uid.resize(uid.length()+1);
      }
   }
   auto size = byte_length(value_field);
   return size;
}

template <>
inline std::size_t validate<VR::IS>(typename type_of<VR::IS>::type& value_field)
{
   auto max_len = type_of<VR::IS>::max_len;
   for (auto it = value_field.begin(); it != value_field.end(); ++it) {
      auto& uid = *it;
      if (uid.length() > max_len) {
         uid.resize(max_len);
      }
      if (uid.length() % 2 != 0) {
         uid.resize(uid.length()+1);
      }
      // todo: any_of for all chars not supported?
   }
   auto size = byte_length(value_field);
   return size;
}

template <>
std::size_t validate<VR::LO>(typename type_of<VR::LO>::type& value_field)
{
   auto max_len = type_of<VR::LO>::max_len;
   for (auto it = value_field.begin(); it != value_field.end(); ++it) {
      auto& uid = *it;
      if (uid.length() > max_len) {
         uid.resize(max_len);
      }
      if (uid.length() % 2 != 0) {
         uid.resize(uid.length()+1);
      }
   }
   auto size = byte_length(value_field);
   return size;
}

template <>
std::size_t validate<VR::LT>(typename type_of<VR::LT>::type& value_field)
{
   auto size = byte_length(value_field);
   if (size > type_of<VR::LT>::max_len) {
      value_field.resize(type_of<VR::ST>::max_len);
   }
   if (value_field.length() % 2 != 0) {
      value_field.resize(value_field.length()+1);
   }
   return byte_length(value_field);
}

template <>
std::size_t validate<VR::DS>(typename type_of<VR::DS>::type& value_field)
{
   auto max_len = type_of<VR::DS>::max_len;
   for (auto it = value_field.begin(); it != value_field.end(); ++it) {
      auto& uid = *it;
      if (uid.length() > max_len) {
         uid.resize(max_len);
      }
      if (uid.length() % 2 != 0) {
         uid.resize(uid.length()+1);
      }
      // todo: any_of for all chars not supported?
   }
   auto size = byte_length(value_field);
   return size;
}

template <>
std::size_t validate<VR::CS>(typename type_of<VR::CS>::type& value_field)
{
   auto max_len = type_of<VR::CS>::max_len;
   for (auto it = value_field.begin(); it != value_field.end(); ++it) {
      auto& uid = *it;
      if (uid.length() > max_len) {
         uid.resize(max_len);
      }
      if (uid.length() % 2 != 0) {
         uid.resize(uid.length()+1);
      }
      // todo: any_of for all chars not supported?
      // todo: ?trim?
   }
   auto size = byte_length(value_field);
   return size;
}

template <>
std::size_t validate<VR::AS>(typename type_of<VR::AS>::type& value_field)
{
   auto max_len = type_of<VR::AS>::len;
   for (auto it = value_field.begin(); it != value_field.end(); ++it) {
      auto& uid = *it;
      if (uid.length() > max_len) {
         uid.resize(max_len);
      }
      if (uid.length() % 2 != 0) {
         uid.resize(uid.length()+1);
      }
      // todo: any_of for all chars not supported?
   }
   auto size = byte_length(value_field);
   return size;
}

template <>
std::size_t validate<VR::AE>(typename type_of<VR::AE>::type& value_field)
{
   auto max_len = type_of<VR::AE>::max_len;
   for (auto it = value_field.begin(); it != value_field.end(); ++it) {
      auto& uid = *it;
      if (uid.length() > max_len) {
         uid.resize(max_len);
      }
      if (uid.length() % 2 != 0) {
         uid.resize(uid.length()+1);
      }
   }
   auto size = byte_length(value_field);
   return size;
}


}

}

}
