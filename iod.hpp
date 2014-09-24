#ifndef IOD_HPP
#define IOD_HPP

#include <set>
#include <vector>
#include <chrono>
#include <memory>

#include <boost/optional.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/local_time/local_time.hpp>

enum class VR
{
   AE, AS, AT, CS, DA, DS, DT, FL, FD, IS,
   LO, LT, OB, OF, OW, PN, SH, SL, SQ, SS,
   ST, TM, UI, UL, UN, US, UT
};


struct attribute_base
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
      attribute_base() = default;
};

template <VR>
struct attribute: attribute_base
{

};

template <>
struct attribute<VR::AE>: attribute_base
{
      std::string value_field;
};
template <>
struct attribute<VR::AS>: attribute_base
{
      std::string value_field;
};
template <>
struct attribute<VR::AT>: attribute_base
{
      attribute::tag_type value_field;
};
template <>
struct attribute<VR::CS>: attribute_base
{
      std::string value_field;
};
template <>
struct attribute<VR::DA>: attribute_base
{
      boost::gregorian::date value_field;
};
template <>
struct attribute<VR::DS>: attribute_base
{
      std::string value_field;
};
template <>
struct attribute<VR::DT>: attribute_base
{
      boost::local_time::local_date_time value_field;
};
template <>
struct attribute<VR::FL>: attribute_base
{
      float value_field;
};
template <>
struct attribute<VR::FD>: attribute_base
{
      double value_field;
};
template <>
struct attribute<VR::IS>: attribute_base
{
      std::string value_field;
};
template <>
struct attribute<VR::LO>: attribute_base
{
      std::string value_field;
};
template <>
struct attribute<VR::LT>: attribute_base
{
      std::string value_field;
};
template <>
struct attribute<VR::OB>: attribute_base
{
      std::vector<unsigned char> value_field;
};
template <>
struct attribute<VR::OF>: attribute_base
{
      std::string value_field;
};
template <>
struct attribute<VR::OW>: attribute_base
{
      std::string value_field;
};
template <>
struct attribute<VR::PN>: attribute_base
{
      std::string value_field;
};
template <>
struct attribute<VR::SH>: attribute_base
{
      std::string value_field;
};
template <>
struct attribute<VR::SL>: attribute_base
{
      long value_field;
};
template <>
struct attribute<VR::SQ>: attribute_base
{
      std::vector<std::set<attribute_base>> value_field;
};
template <>
struct attribute<VR::SS>: attribute_base
{
      short value_field;
};
template <>
struct attribute<VR::ST>: attribute_base
{
      std::string value_field;
};
template <>
struct attribute<VR::TM>: attribute_base
{
      boost::local_time::local_date_time value_field;
};
template <>
struct attribute<VR::UI>: attribute_base
{
      std::string value_field;
};
template <>
struct attribute<VR::UL>: attribute_base
{
      unsigned long value_field;
};
template <>
struct attribute<VR::UN>: attribute_base
{
      std::vector<unsigned char> value_field;
};
template <>
struct attribute<VR::US>: attribute_base
{
      unsigned short value_field;
};
template <>
struct attribute<VR::UT>: attribute_base
{
      std::string value_field;
};


bool operator<(const attribute_base& lhs, const attribute_base& rhs);

using iod = std::set<attribute_base>;


#endif // IOD_HPP
