#ifndef ATTRIBUTE_HPP
#define ATTRIBUTE_HPP

#include <set>
#include <vector>
#include <chrono>
#include <memory>

#include <boost/optional.hpp>

namespace dicom
{

/**
 * The data namespace contains all functionality related to DICOM datasets.
 */
namespace data
{

/**
 * The attribute namespace contains functionality to create and modify DICOM
 * dataset attributes.
 */
namespace attribute
{


/**
 * @brief The VR enum defines the value representations of an attribute
 * a Value Representation can be described as a data type.
 */
enum class VR
{
   AE, AS, AT, CS, DA, DS, DT, FL, FD, IS,
   LO, LT, OB, OD, OF, OW, PN, SH, SL, SQ,
   SS, ST, TM, UI, UL, UN, US, UT
};


struct elementfield_base;

template <VR vr>
struct element_field;



/**
 * @brief The attribute_visitor class is the base class for the visitors that
 *        operate on the VR dependent types.
 */
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

/**
 * @brief The elementfield_base struct is the base type for the element fields
 *        with their different types.
 * This struct may not be dependent on any template parameters, as it is used
 * by the elementfield struct which holds a "type-dependency-free" pointer to
 * it.
 */
struct elementfield_base
{
      /**
       * @brief accept
       * @param op
       */
      template <VR vr>
      void accept(attribute_visitor<vr>& op) {
         element_field<vr>* ef = dynamic_cast<element_field<vr>*>(this);
         assert(ef); // this class is abstract; the dynamic type of this must be
                     // a pointer to a subclass, therefore ef cannot be nullptr.
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
      std::unique_ptr<elementfield_base> value_field;
};


/**
 * construct a type mapping VR -> T using specialized templates
 */
template<VR>
struct type_of {};

template<>
struct type_of<VR::AE>
{
      using type = std::string;
      static const std::size_t max_len = 16;
};
template<>
struct type_of<VR::AS>
{
      using type = std::string;
      static const std::size_t len = 4;
};
template<>
struct type_of<VR::AT>
{
      using type = elementfield::tag_type;
      static const std::size_t len = 4;
};
template<>
struct type_of<VR::CS>
{
      using type = std::string;
      static const std::size_t max_len = 16;
};
template<>
struct type_of<VR::DA>
{
      using type = std::string;
      static const std::size_t len = 8;
};
template<>
struct type_of<VR::DS>
{
      using type = std::string;
      static const std::size_t max_len = 16;
};
template<>
struct type_of<VR::DT>
{
      using type = std::string;
      static const std::size_t max_len = 26;
};
template<>
struct type_of<VR::FL>
{
      using type = float;
      static const std::size_t len = 4;
};
template<>
struct type_of<VR::FD>
{
      using type = double;
      static const std::size_t len = 8;
};
template<>
struct type_of<VR::IS>
{
      using type = std::string;
      static const std::size_t max_len = 12;
};
template<>
struct type_of<VR::LO>
{
      using type = std::string;
      static const std::size_t max_len = 64;
};
template<>
struct type_of<VR::LT>
{
      using type = std::string;
      static const std::size_t max_len = 10240;
};
template<>
struct type_of<VR::OB> { using type = std::vector<unsigned char>; };
template<>
struct type_of<VR::OD>
{
      using type = std::vector<unsigned char>;
      static const std::size_t max_len = 4294967288; //2^32-8
};
template<>
struct type_of<VR::OF>
{
      using type = std::string;
      static const std::size_t max_len = 4294967292; //2^32-4
};
template<>
struct type_of<VR::OW> { using type = std::string; };
template<>
struct type_of<VR::PN>
{
      using type = std::string;
      static const std::size_t max_len = 64;
};
template<>
struct type_of<VR::SH>
{
      using type = std::string;
      static const std::size_t max_len = 16;
};
template<>
struct type_of<VR::SL>
{
      using type = long;
      static const std::size_t len = 4;
};
template<>
struct type_of<VR::SQ> { using type = std::vector<std::set<elementfield_base>>; };
template<>
struct type_of<VR::SS>
{
      using type = short;
      static const std::size_t len = 2;
};
template<>
struct type_of<VR::ST>
{
      using type = std::string;
      static const std::size_t max_len = 1024;
};
template<>
struct type_of<VR::TM>
{
      using type = std::string;
      static const std::size_t max_len = 16;
};
template<>
struct type_of<VR::UI>
{
      using type = std::string;
      static const std::size_t max_len = 16;
};
template<>
struct type_of<VR::UN> { using type = std::vector<unsigned char>; };
template<>
struct type_of<VR::US>
{
      using type = unsigned short;
      static const std::size_t len = 2;
};
template<>
struct type_of<VR::UT>
{
      using type = std::string;
      static const std::size_t max_len = 4294967294; //2^32-2
};



/**
 * @brief The element_field struct contains the type-specific data and methods
 *        for setting / receiving those
 */
template <VR vr>
struct element_field: elementfield_base
{
      using vrtype = typename type_of<vr>::type;
      vrtype value_field;

      virtual ~element_field() {}
};


/**
 * @brief The get_visitor class is used to retrieve the value of the value field
 *        of an attribute.
 */
template <VR vr>
class get_visitor : public attribute_visitor<vr>
{
   private:
      typename type_of<vr>::type& getdata;

   public:
      get_visitor(typename type_of<vr>::type& data): getdata(data) {
      }

      virtual void apply(element_field<vr>* ef) override {
         getdata = ef->value_field;
      }
};

/**
 * @brief get_value_field is used to retrieve the value of the value field
 *        of an attribute.
 * @param e element field / attribute operated upon
 * @param out_data reference where the value will be stored
 */
template <VR vr>
void get_value_field(elementfield& e, typename type_of<vr>::type& out_data)
{
   get_visitor<vr> getter(out_data);
   e.value_field->accept<vr>(getter);
}


/**
 * @brief The set_visitor class is used to set a specified value into the
 *        value field.
 */
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
         ef->value_field = setdata;
      }
};


/**
 * @brief make_elementfield is a factory function to return a prepared attribute
 *        / element field.
 * @param gid group id
 * @param eid element id
 * @param data data for the value field
 * @return prepared instance of elementfield
 */
template <VR vr>
elementfield make_elementfield(short gid, short eid, std::size_t data_len, typename type_of<vr>::type data)
{
   elementfield el;
   el.tag.group_id = gid; el.tag.element_id = eid;
   el.value_rep = vr;
   el.value_len = data_len;
   el.value_field = std::unique_ptr<elementfield_base> {new element_field<vr>};

   set_visitor<vr> setter(data);
   el.value_field->accept<vr>(setter);
   return el;
}

bool operator<(const elementfield::tag_type& lhs, const elementfield::tag_type& rhs);

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


}

}

}


#endif // IOD_HPP
