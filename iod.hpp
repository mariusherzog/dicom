#ifndef IOD_HPP
#define IOD_HPP

#include <set>
#include <vector>
#include <chrono>
#include <memory>

#include <boost/optional.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/local_time/local_time.hpp>

/**
 * @brief The VR enum defines the value representations of an attribute
 * a Value Representation can be described as a data type.
 */
enum class VR
{
   AE, AS, AT, CS, DA, DS, DT, FL, FD, IS,
   LO, LT, OB, OF, OW, PN, SH, SL, SQ, SS,
   ST, TM, UI, UL, UN, US, UT
};


/**
 * @brief The elementfield_base struct defines all information contained in an
 *        attribute of an iod
 * @see DICOM standard 3.5, chapter 7
 */
struct elementfield_base
{
      struct tag_type
      {
            short group_id;
            short element_id;
      };
      tag_type tag;
      boost::optional<VR> value_rep;
      std::size_t value_len;
      int value_field; //subclasses will shadow this field

   protected:
      elementfield_base() = default;
};

template <VR>
struct element_field: elementfield_base
{

};

template <>
struct element_field<VR::AE>: elementfield_base
{
      std::string value_field;
};
template <>
struct element_field<VR::AS>: elementfield_base
{
      std::string value_field;
};
template <>
struct element_field<VR::AT>: elementfield_base
{
      element_field::tag_type value_field;
};
template <>
struct element_field<VR::CS>: elementfield_base
{
      std::string value_field;
};
template <>
struct element_field<VR::DA>: elementfield_base
{
      boost::gregorian::date value_field;
};
template <>
struct element_field<VR::DS>: elementfield_base
{
      std::string value_field;
};
template <>
struct element_field<VR::DT>: elementfield_base
{
      boost::local_time::local_date_time value_field;
};
template <>
struct element_field<VR::FL>: elementfield_base
{
      float value_field;
};
template <>
struct element_field<VR::FD>: elementfield_base
{
      double value_field;
};
template <>
struct element_field<VR::IS>: elementfield_base
{
      std::string value_field;
};
template <>
struct element_field<VR::LO>: elementfield_base
{
      std::string value_field;
};
template <>
struct element_field<VR::LT>: elementfield_base
{
      std::string value_field;
};
template <>
struct element_field<VR::OB>: elementfield_base
{
      std::vector<unsigned char> value_field;
};
template <>
struct element_field<VR::OF>: elementfield_base
{
      std::string value_field;
};
template <>
struct element_field<VR::OW>: elementfield_base
{
      std::string value_field;
};
template <>
struct element_field<VR::PN>: elementfield_base
{
      std::string value_field;
};
template <>
struct element_field<VR::SH>: elementfield_base
{
      std::string value_field;
};
template <>
struct element_field<VR::SL>: elementfield_base
{
      long value_field;
};
template <>
struct element_field<VR::SQ>: elementfield_base
{
      std::vector<std::set<elementfield_base>> value_field;
};
template <>
struct element_field<VR::SS>: elementfield_base
{
      short value_field;
};
template <>
struct element_field<VR::ST>: elementfield_base
{
      std::string value_field;
};
template <>
struct element_field<VR::TM>: elementfield_base
{
      boost::local_time::local_date_time value_field;
};
template <>
struct element_field<VR::UI>: elementfield_base
{
      std::string value_field;
};
template <>
struct element_field<VR::UL>: elementfield_base
{
      unsigned long value_field;
};
template <>
struct element_field<VR::UN>: elementfield_base
{
      std::vector<unsigned char> value_field;
};
template <>
struct element_field<VR::US>: elementfield_base
{
      unsigned short value_field;
};
template <>
struct element_field<VR::UT>: elementfield_base
{
      std::string value_field;
};

/**
 * @brief operator < is necessary for the storage in the set
 * @param lhs
 * @param rhs
 * @return
 * The order is defined by the attribute group and element ids. a < b is true
 * iff the group id of a is lesser than b, or if they are equal, iff the
 * element id of a is lesser than b.
 */
bool operator<(const elementfield_base& lhs, const elementfield_base& rhs);

using iod = std::set<elementfield_base>;


#endif // IOD_HPP
