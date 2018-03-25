#ifndef ATTRIBUTE_HPP
#define ATTRIBUTE_HPP

#include <map>
#include <vector>
#include <chrono>
#include <memory>
#include <type_traits>
#include <ostream>

#include <boost/optional.hpp>
#include <boost/variant.hpp>

#include "base_types.hpp"
#include "vmtype.hpp"
#include "encapsulated.hpp"
#include "tag.hpp"

namespace dicom
{

namespace data
{

namespace dataset
{
   /**
    * forward declaration of the dataset defined in the dataset namespace. This
    * circular dependency is intrinsic to the DICOM dataset, as an attribute
    * may be defined as another - nested - set.
    */
   struct dataset_type;
}

}

}


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
 * @brief The ENDIANNESS enum defines the endianness of the data in a serialized
 *        representation
 */
enum class ENDIANNESS
{
   BIG, LITTLE
};




/**
 * @brief The VR enum defines the value representations of an attribute
 * a Value Representation can be described as a data type.
 */
enum class VR
{
   AE, AS, AT, CS, DA, DS, DT, FL, FD, IS,
   LO, LT, OB, OD, OF, OW, PN, SH, SL, SQ,
   SS, ST, TM, UI, UL, UN, UR, US, UT,
   NN,
   NI
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
      void accept(attribute_visitor<vr>& op)  {
         element_field<vr>* ef = dynamic_cast<element_field<vr>*>(this);
         assert(ef); // this class is abstract; the dynamic type of this must be
                     // a pointer to a subclass, therefore ef cannot be nullptr.
         op.accept(ef);
      }

      virtual std::unique_ptr<elementfield_base> deep_copy() = 0;

      virtual std::size_t byte_size() = 0;

      virtual std::ostream& print(std::ostream& os) = 0;

      virtual ~elementfield_base() = 0;
};



/**
 * construct a type mapping VR -> T using specialized templates
 */
template<VR>
struct type_of {};

template<>
struct type_of<VR::AE>
{
      using type = attribute::vmtype<std::string>;
      static const std::size_t max_len = 16;
};
template<>
struct type_of<VR::AS>
{
      using type = attribute::vmtype<std::string>;
      static const std::size_t len = 4;
};
template<>
struct type_of<VR::AT>
{
      using type = attribute::vmtype<tag_type>;
      static const std::size_t len = 4;
};
template<>
struct type_of<VR::CS>
{
      using type = attribute::vmtype<std::string>;
      static const std::size_t max_len = 16;
};
template<>
struct type_of<VR::DA>
{
      using type = attribute::vmtype<std::string>;
      static const std::size_t len = 8;
};
template<>
struct type_of<VR::DS>
{
      using type = attribute::vmtype<std::string>;
      static const std::size_t max_len = 16;
};
template<>
struct type_of<VR::DT>
{
      using type = attribute::vmtype<std::string>;
      static const std::size_t max_len = 26;
};
template<>
struct type_of<VR::FL>
{
      using type = attribute::vmtype<float>;
      static const std::size_t len = 4;
};
template<>
struct type_of<VR::FD>
{
      using type = attribute::vmtype<double>;
      static const std::size_t len = 8;
};
template<>
struct type_of<VR::IS>
{
      using type = attribute::vmtype<std::string>;
      static const std::size_t max_len = 12;
};
template<>
struct type_of<VR::LO>
{
      using type = attribute::vmtype<std::string>;
      static const std::size_t max_len = 64;
};
template<>
struct type_of<VR::LT>
{
      using type = std::string;
      static const std::size_t max_len = 10240;
};
template<>
struct type_of<VR::OB>
{
      using type = ob_type;
      using base_type = std::vector<unsigned char>;
};
template<>
struct type_of<VR::OD>
{
      using type = std::vector<double>;
      static const std::size_t max_len = 4294967288; //2^32-8
};
template<>
struct type_of<VR::OF>
{
      using type = std::vector<float>;
      static const std::size_t max_len = 4294967292; //2^32-4
};
template<>
struct type_of<VR::OW> { using type = std::vector<unsigned short>; };
template<>
struct type_of<VR::PN>
{
      using type = attribute::vmtype<std::string>;
      static const std::size_t max_len = 64;
};
template<>
struct type_of<VR::SH>
{
      using type = attribute::vmtype<std::string>;
      static const std::size_t max_len = 16;
};
template<>
struct type_of<VR::SL>
{
      using type = attribute::vmtype<long>;
      static const std::size_t len = 4;
};
template<>
struct type_of<VR::SQ> { using type = std::vector<dataset::dataset_type>; };
template<>
struct type_of<VR::SS>
{
      using type = attribute::vmtype<short>;
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
      using type = attribute::vmtype<std::string>;
      static const std::size_t max_len = 16;
};
template<>
struct type_of<VR::UI>
{
      using type = attribute::vmtype<std::string>;
      static const std::size_t max_len = 64;
};
template<>
struct type_of<VR::UN>
{
      using type = std::vector<unsigned char>;
      static const std::size_t max_len = 4294967294; //2^32-2
      // size only demilited by size of value length field (4 bytes)
};
template<>
struct type_of<VR::UR>
{
      using type = attribute::vmtype<std::string>;
      static const std::size_t max_len = 4294967294; //2^32-2
};
template<>
struct type_of<VR::US>
{
      using type = attribute::vmtype<unsigned short>;
      static const std::size_t len = 2;
};
template<>
struct type_of<VR::UL>
{
      using type = attribute::vmtype<unsigned int>;
      static const std::size_t len = 4;
};
template<>
struct type_of<VR::UT>
{
      using type = std::string;
      static const std::size_t max_len = 4294967294; //2^32-2
};
template<>
struct type_of<VR::NN>
{
      using type = empty_t;
};
template<>
struct type_of<VR::NI>
{
      using type = empty_t;
};

std::ostream& operator<<(std::ostream& os, typename type_of<VR::SQ>::type const data);

template <VR vr>
std::size_t validate(typename type_of<vr>::type& value_field)
{
   auto size = byte_length(value_field);
   return size;
}

template <>
std::size_t validate<VR::UI>(typename type_of<VR::UI>::type& value_field);

template <>
std::size_t validate<VR::UT>(typename type_of<VR::UT>::type& value_field);

template <>
std::size_t validate<VR::ST>(typename type_of<VR::ST>::type& value_field);

template <>
std::size_t validate<VR::PN>(typename type_of<VR::PN>::type& value_field);

template <>
std::size_t validate<VR::IS>(typename type_of<VR::IS>::type& value_field);

template <>
std::size_t validate<VR::LO>(typename type_of<VR::LO>::type& value_field);

template <>
std::size_t validate<VR::LT>(typename type_of<VR::LT>::type& value_field);

template <>
std::size_t validate<VR::DS>(typename type_of<VR::DS>::type& value_field);

template <>
std::size_t validate<VR::CS>(typename type_of<VR::CS>::type& value_field);

template <>
std::size_t validate<VR::AS>(typename type_of<VR::AS>::type& value_field);

template <>
std::size_t validate<VR::AE>(typename type_of<VR::AE>::type& value_field);


template <VR vr>
struct value
{
   private:
      typename type_of<vr>::type value_;

   public:
      constexpr value(typename type_of<vr>::type val): value_(val) {}


      template <typename BT = decltype(value_),
                typename = typename std::enable_if<
                   is_vmtype<BT>::value
                   >::type>
      constexpr value(std::initializer_list<typename BT::base_type> values): value_(values) {}


      constexpr operator decltype(value_)() const
      {
         return value_;
      }

      constexpr decltype(value_) get() const
      {
         return value_;
      }

      decltype(value_)& get()
      {
         return value_;
      }
};

//template <VR vr>
//struct value_ref
//{
//   private:
//      typename type_of<vr>::type& value_;

//   public:
//      value_ref(typename type_of<vr>::type& val): value_(val) {}

//      typename type_of<vr>::type& value()
//      {
//         return value_;
//      }

//      operator decltype(value_)() const
//      {
//         return value_;
//      }
//};


struct elementfield;

template <VR vr>
static elementfield make_elementfield(value<vr> val);

template <VR vr>
void get_value_field(const elementfield& e, typename type_of<vr>::type& data);

template <VR vr>
static typename type_of<vr>::type* get_value_field_pointer(const elementfield& e);

/**
 * @brief The elementfield_base struct defines all information contained in an
 *        attribute of an iod
 * @see DICOM standard 3.5, chapter 7
 */
struct elementfield
{
      boost::optional<VR> value_rep;
      std::size_t value_len;
      std::unique_ptr<elementfield_base> value_field;

      elementfield() = default;
      elementfield(const elementfield& other);
      elementfield& operator=(const elementfield other);

      template <VR vr>
      elementfield& operator=(value<vr> val)
      {
         *this = make_elementfield<vr>(val);
         return *this;
      }

      template <VR vr>
      operator value<vr>() const
      {
         typename type_of<vr>::type data;
         get_value_field<vr>(*this, data);
         return data;
      }

      template <VR vr>
      typename type_of<vr>::type value() const
      {
         typename type_of<vr>::type data;
         get_value_field<vr>(*this, data);
         return data;
      }

//      template <VR vr>
//      operator value_ref<vr>()
//      {
//         return value_ref<vr> {*(get_value_field_pointer<vr>(*this))};
//      }

      friend void swap(elementfield& lhs, elementfield& rhs) noexcept;
};

void swap(elementfield& lhs, elementfield& rhs) noexcept;

/**
 * @brief The element_field struct contains the type-specific data and methods
 *        for setting / receiving those
 */
template <VR vr>
struct element_field: elementfield_base
{
      using vrtype = typename type_of<vr>::type;
      vrtype value_field;

      std::unique_ptr<elementfield_base> deep_copy() override
      {
         element_field<vr>* ef = new element_field<vr> {};
         ef->value_field = value_field;
         return std::unique_ptr<elementfield_base> {ef};
      }

      std::size_t byte_size() override
      {
         return byte_length(value_field);
      }

      std::ostream& print(std::ostream& os) override
      {
            return os << value_field;
      }

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
      get_visitor(typename type_of<vr>::type& data): getdata(data)
      {
      }

      virtual void apply(element_field<vr>* ef) override
      {
         getdata = ef->value_field;
      }
};


/**
 * @brief >_field is used to retrieve the value of the value field
 *        of an attribute.
 * @param e element field / attribute operated upon
 * @param out_data reference where the value will be stored
 */
template <VR vr>
void get_value_field(const elementfield& e, typename type_of<vr>::type& out_data)
{
   get_visitor<vr> getter(out_data);
   e.value_field->accept<vr>(getter);
}

// for VR OB
template <VR vr>
void get_value_field(const elementfield& e, typename type_of<vr>::base_type& out_data)
{
   typename type_of<VR::OB>::type wrapped_data;

   get_visitor<vr> getter(wrapped_data);
   e.value_field->accept<vr>(getter);

   out_data = boost::get<std::vector<unsigned char>>(wrapped_data);
}

template <VR vr>
void get_value_field(const elementfield& e, typename type_of<vr>::type::base_type& out_data)
{
   typename type_of<vr>::type wrapper;

   get_visitor<vr> getter(wrapper);
   e.value_field->accept<vr>(getter);
   out_data = *wrapper.begin();
}

template <VR vr>
class get_ptr_visitor : public attribute_visitor<vr>
{
   private:
      typename type_of<vr>::type* dataptr;

   public:
      get_ptr_visitor() = default;

      virtual void apply(element_field<vr>* ef) override
      {
         dataptr = &ef->value_field;
      }

      decltype(dataptr) pointer() const
      {
         return dataptr;
      }
};


template <VR vr>
static typename type_of<vr>::type* get_value_field_pointer(const elementfield& e)
{
   get_ptr_visitor<vr> getpointer;
   e.value_field->accept<vr>(getpointer);
   return getpointer.pointer();
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
      set_visitor(typename type_of<vr>::type data)
      {
         setdata = data;
      }

      virtual void apply(element_field<vr>* ef) override
      {
         ef->value_field = setdata;
      }
};

template <VR vr>
void set_value_field(const elementfield& e, typename type_of<vr>::type& indata)
{
   set_visitor<vr> setter(indata);
   e.value_field->accept<vr>(setter);
}


/**
 * @brief make_elementfield is a factory function to return a prepared attribute
 *        / element field.
 * @param data data for the value field
 * @return prepared instance of elementfield
 */
template <VR vr>
elementfield make_elementfield(std::size_t data_len, const typename type_of<vr>::type& data)
{
   static_assert(!std::is_same<typename type_of<vr>::type, empty_t>::value, "Cannot construct value field with data for VR of NN");
   elementfield el;
   el.value_rep = vr;
   el.value_len = data_len;
   el.value_field = std::unique_ptr<elementfield_base> {new element_field<vr>};

   set_visitor<vr> setter(data);
   el.value_field->accept<vr>(setter);
   return el;
}

template <VR vr>
static elementfield make_elementfield(const typename type_of<vr>::type &data)
{
   std::size_t len = byte_length(data);
   return make_elementfield<vr>(len, data);
}

template <VR vr>
static elementfield make_elementfield(value<vr> val)
{
   return make_elementfield<vr>(val.get());
}

/**
 * @brief make_elementfield is a factory function to return a prepared attribute
 *        / element field.
 * @param data data for the value field
 * @return prepared instance of elementfield
 */
template <VR vr>
elementfield make_elementfield(std::size_t data_len, const typename type_of<vr>::type::base_type& data)
{
   static_assert(!std::is_same<typename type_of<vr>::type, empty_t>::value, "Cannot construct value field with data for VR of NN");
   elementfield el;
   el.value_rep = vr;
   el.value_len = data_len;
   el.value_field = std::unique_ptr<elementfield_base> {new element_field<vr>};

   typename type_of<vr>::type wrapper(data);
   set_visitor<vr> setter(wrapper);
   el.value_field->accept<vr>(setter);
   return el;
}



// for VR = OB
template <VR vr>
elementfield make_elementfield(std::size_t data_len, const typename type_of<vr>::base_type& data)
{
   static_assert(!std::is_same<typename type_of<vr>::type, empty_t>::value, "Cannot construct value field with data for VR of NN");
   elementfield el;
   el.value_rep = vr;
   el.value_len = data_len;
   el.value_field = std::unique_ptr<elementfield_base> {new element_field<vr>};

   typename type_of<vr>::type wrapper(data);
   set_visitor<vr> setter(wrapper);
   el.value_field->accept<vr>(setter);
   return el;
}


template <VR vr>
elementfield make_elementfield(const typename type_of<vr>::type::base_type& data)
{
   typename type_of<vr>::type wrapper(data);
   std::size_t len = validate<vr>(wrapper);
   return make_elementfield<vr>(len, wrapper);
}

template <VR vr>
elementfield make_elementfield(const typename type_of<vr>::base_type data)
{
   elementfield el;
   el.value_rep = VR::OB;
   el.value_len = byte_length(data);
   el.value_field = std::unique_ptr<elementfield_base> {new element_field<VR::OB>};

   typename type_of<VR::OB>::type wrapper(data);
   set_visitor<VR::OB> setter(wrapper);
   el.value_field->accept<VR::OB>(setter);
   return el;
}

/**
 * @brief make_elementfield overload for attributes that do not have a value
 *        field (like the sequence delimitation item)
 * @return prepared instance of elementfield
 */
template <VR vr>
elementfield make_elementfield()
{
   static_assert(std::is_same<typename type_of<vr>::type, empty_t>::value, "Expected empty_t type (VR == NN)");
   elementfield el;
   el.value_rep = vr;
   el.value_len = 0;
   el.value_field = std::unique_ptr<elementfield_base> {new element_field<vr>};
   return el;
}

/**
 * @brief make_elementfield overload for attributes that do not have a value,
 *        but a length field
 * @return prepared instance of elementfield
 * The second dummy parameter of type VR is used to prevent ambigious overloads
 * with make_elementfield that take a single value of an integral type.
 */
template <VR vr>
elementfield make_elementfield(std::size_t len, VR)
{
   static_assert(std::is_same<typename type_of<vr>::type, empty_t>::value, "Expected sequence info type (VR == NI)");
   elementfield el;
   el.value_rep = vr;
   el.value_len = len;
   el.value_field = std::unique_ptr<elementfield_base> {new element_field<vr>};
   return el;
}

}

}

}


#endif // ATTRIBUTE_HPP
