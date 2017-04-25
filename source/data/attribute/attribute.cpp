#include "attribute.hpp"

#include <iomanip>
#include <algorithm>
#include <iterator>
#include <functional>

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

/**
 * @brief validate_internal_texts ensures that the content of the value_field
 *        is standard conformant for the VRs LT, ST and UT.
 * @param value_field string containing value field data
 * @return length of the corrected value field
 */
template <VR vr>
std::size_t validate_internal_texts(std::string& value_field)
{
   static_assert((vr == VR::LT || vr == VR::ST || vr == VR::UT), "");

   auto not_allowed_char = [](const char c)
   {
      return std::iscntrl(c) && static_cast<unsigned char>(c) != 0x0d &&
            static_cast<unsigned char>(c) != 0x0c &&
            static_cast<unsigned char>(c) != 0x0a &&
            static_cast<unsigned char>(c) != 0x1b;

   };
   value_field.erase(std::remove_if(value_field.begin(), value_field.end(), not_allowed_char), value_field.end());

   auto size = byte_length(value_field);
   if (size > type_of<vr>::max_len) {
      value_field.resize(type_of<vr>::max_len);
   }
   if (value_field.length() % 2 != 0) {
      value_field.push_back(' ');
   }

   return byte_length(value_field);
}

/**
 * @brief validate_internal_multitext ensures that content of the value_field
 *        is standard conformant to the VRs AE and LO which represent text
 *        with multiple values allowed
 * @param value_field value_field containing data
 * @param not_allowed set of characters not allowed
 * @return byte length of the potentially corrected value field
 */
template <VR vr>
std::size_t validate_internal_multitext(vmtype<std::string>& value_field, std::vector<char> not_allowed)
{
   static_assert((vr == VR::LO || vr == VR::AE), "");

   auto max_len = type_of<vr>::max_len;
   for (auto it = value_field.begin(); it != value_field.end(); ++it) {
      auto& val = *it;

      auto not_allowed_char = [not_allowed](const char c)
      {
         return std::find(not_allowed.begin(), not_allowed.end(), c) == not_allowed.end();

      };
      val.erase(std::remove_if(val.begin(), val.end(), not_allowed_char), val.end());

      if (val.length() > max_len) {
         val.resize(max_len);
      }
      if (val.length() % 2 != 0) {
         val.push_back(' ');
      }
   }
   auto size = byte_length(value_field);
   return size;
}


/**
 * @brief validate_internal_numstrings ensures that the VRs IS and DS, which
 *        represent a number in a string, are conforming to the standard.
 * @param value_field value field containing data
 * @param allowed set of allowed characters, like +, -, ., e, etc.
 * @return byte length of the potentially corrected value field
 */
template <VR vr>
std::size_t validate_internal_numstrings(vmtype<std::string>& value_field, std::vector<char> allowed)
{
   static_assert((vr == VR::IS || vr == VR::DS), "");

   auto max_len = type_of<vr>::max_len;
   for (auto it = value_field.begin(); it != value_field.end(); ++it) {
      auto& val = *it;

      auto is_allowed_char = [allowed](const char c)
      {
         return !std::isdigit(c) && (std::find(allowed.begin(), allowed.end(), c) == allowed.end());

      };
      val.erase(std::remove_if(val.begin(), val.end(), is_allowed_char), val.end());

      if (val.length() > max_len) {
         val.resize(max_len);
      }
      if (val.length() % 2 != 0) {
         val.push_back(' ');
      }
   }
   auto size = byte_length(value_field);
   return size;
}


template <>
std::size_t validate<VR::UI>(typename type_of<VR::UI>::type& value_field)
{
   auto max_len = type_of<VR::UI>::max_len;
   for (auto it = value_field.begin(); it != value_field.end(); ++it) {
      auto& uid = *it;

      auto not_allowed_char = [](const char c)
      {
         return !std::isdigit(c) && c != '.';

      };
      uid.erase(std::remove_if(uid.begin(), uid.end(), not_allowed_char), uid.end());

      if (uid.length() > max_len) {
         uid.resize(max_len);
      }
   }
   auto size = byte_length(value_field);
   if (size % 2 != 0)
   {
      value_field.back().resize(size+1);
      return size+1;
   }
   return size;
}

template <>
std::size_t validate<VR::UT>(typename type_of<VR::UT>::type& value_field)
{
   return validate_internal_texts<VR::UT>(value_field);
}

template <>
std::size_t validate<VR::ST>(typename type_of<VR::ST>::type& value_field)
{
   return validate_internal_texts<VR::ST>(value_field);
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
         uid.push_back(' ');
      }
   }
   auto size = byte_length(value_field);
   return size;
}

template <>
std::size_t validate<VR::IS>(typename type_of<VR::IS>::type& value_field)
{
   return validate_internal_numstrings<VR::IS>(value_field, {'+', '-', 0x20});
}

template <>
std::size_t validate<VR::LO>(typename type_of<VR::LO>::type& value_field)
{
   return validate_internal_multitext<VR::LO>(value_field, {});
}

template <>
std::size_t validate<VR::LT>(typename type_of<VR::LT>::type& value_field)
{
   return validate_internal_texts<VR::LT>(value_field);
}

template <>
std::size_t validate<VR::DS>(typename type_of<VR::DS>::type& value_field)
{
   return validate_internal_numstrings<VR::DS>(value_field, {'+', '-', 0x20, '.', 'e', 'E'});
}

template <>
std::size_t validate<VR::CS>(typename type_of<VR::CS>::type& value_field)
{
   auto max_len = type_of<VR::CS>::max_len;
   for (auto it = value_field.begin(); it != value_field.end(); ++it) {
      auto& uid = *it;

      std::transform(uid.begin(), uid.end(), uid.begin(), ::toupper);
      auto not_allowed_char = [](const char c)
      {
         return !std::isdigit(c) && c != '_' && c != '_';

      };
      uid.erase(std::remove_if(uid.begin(), uid.end(), not_allowed_char), uid.end());

      if (uid.length() > max_len) {
         uid.resize(max_len);
      }
      if (uid.length() % 2 != 0) {
         uid.push_back(' ');
      }
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
   }
   auto size = byte_length(value_field);
   return size;
}

template <>
std::size_t validate<VR::AE>(typename type_of<VR::AE>::type& value_field)
{
   return validate_internal_multitext<VR::AE>(value_field, {0x0a, 0x0c, 0x0d, 0x1b});
}


}

}

}
