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

struct elementfield_base;

template <VR vr>
struct element_field;

template <VR vr>
class attribute_visitor
{
   public:
      virtual void accept(element_field<vr>* ef)
      {
        this->apply(ef);
      }

      virtual void apply(element_field<vr>*) { assert(false); }
};


struct elementfield_base
{
      template <VR vr>
      void accept(attribute_visitor<vr>& op) {
         element_field<vr>* ef = dynamic_cast<element_field<vr>*>(this);
         op.accept(ef);
      }

      virtual ~elementfield_base() = 0;
};


/**
 * @brief The elementfield_base struct defines all information contained in an
 *        attribute of an iod
 * @see DICOM standard 3.5, chapter 7
 */
struct elementfield
{
      struct tag_type
      {
            short group_id;
            short element_id;
      };
      tag_type tag;
      boost::optional<VR> value_rep;
      std::size_t value_len;
      elementfield_base* value_field;
};

/**
 * construct a type mapping VR -> T using specialized templates
 */
template<VR>
struct type_of {};

template<>
struct type_of<VR::AE> { using type = std::string; };
template<>
struct type_of<VR::AS> { using type = std::string; };
template<>
struct type_of<VR::AT> { using type = elementfield::tag_type; };
template<>
struct type_of<VR::CS> { using type = std::string; };
template<>
struct type_of<VR::DA> { using type = boost::gregorian::date; };
template<>
struct type_of<VR::DS> { using type = std::string; };
template<>
struct type_of<VR::DT> { using type = boost::local_time::local_date_time; };
template<>
struct type_of<VR::FL> { using type = float; };
template<>
struct type_of<VR::FD> { using type = double; };
template<>
struct type_of<VR::IS> { using type = std::string; };
template<>
struct type_of<VR::LO> { using type = std::string; };
template<>
struct type_of<VR::LT> { using type = std::string; };
template<>
struct type_of<VR::OB> { using type = std::vector<unsigned char>; };
template<>
struct type_of<VR::OF> { using type = std::string; };
template<>
struct type_of<VR::OW> { using type = std::string; };
template<>
struct type_of<VR::PN> { using type = std::string; };
template<>
struct type_of<VR::SH> { using type = std::string; };
template<>
struct type_of<VR::SL> { using type = long; };
template<>
struct type_of<VR::SQ> { using type = std::vector<std::set<elementfield_base>>; };
template<>
struct type_of<VR::SS> { using type = short; };
template<>
struct type_of<VR::ST> { using type = std::string; };
template<>
struct type_of<VR::TM> { using type = boost::local_time::local_date_time; };
template<>
struct type_of<VR::UI> { using type = std::string; };
template<>
struct type_of<VR::UN> { using type = std::vector<unsigned char>; };
template<>
struct type_of<VR::US> { using type = unsigned short; };
template<>
struct type_of<VR::UT> { using type = std::string; };


template <VR vr>
struct element_field: elementfield_base
{
      using vrtype = typename type_of<vr>::type;
      vrtype value_field;

      void set(vrtype data) {
         value_field = data;
      }
};


template <VR vr>
class set_visitor : public attribute_visitor<vr>
{
   private:
      typename type_of<vr>::type setdata;

   public:
      set_visitor(typename type_of<vr>::type data) {
         setdata = data;
      }

      virtual void apply(element_field<vr>* ef) override {
         ef->set(setdata);
      }
};


template <VR vr>
elementfield make_elementfield(short gid, short eid, typename type_of<vr>::type data)
{
   elementfield el;
   el.tag.group_id = gid, el.tag.element_id = eid;
   el.value_rep = vr;
   el.value_field = new element_field<vr> {};

   set_visitor<vr> setter(data);
   el.value_field->accept<vr>(setter);
   return el;
}


/**
 * @brief operator < is necessary for the storage in the set
 * @param lhs
 * @param rhs
 * @return
 * The order is defined by the attribute group and element ids. a < b is true
 * iff the group id of a is lesser than b, or if they are equal, iff the
 * element id of a is lesser than b.
 */
bool operator<(const elementfield& lhs, const elementfield& rhs);


using iod = std::set<elementfield>;


#endif // IOD_HPP
