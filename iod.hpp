#ifndef IOD_HPP
#define IOD_HPP

#include <set>

#include <boost/optional.hpp>

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
            int group_id;
            int element_id;
      };
      tag_type tag;
      boost::optional<VR> value_rep;
      std::size_t value_len;
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


bool operator<(const attribute_base& lhs, const attribute_base& rhs)
{
   return lhs.tag.group_id == rhs.tag.group_id ?
            lhs.tag.element_id < rhs.tag.element_id :
            lhs.tag.group_id < rhs.tag.group_id;
}


class iod
{
   public:


      iod()
      {
         attribute<VR::AE> a1;
         attribute<VR::AS> a2;
         a1 < a2;
      }

   private:
      std::set<attribute_base> attributes;
};

#endif // IOD_HPP
