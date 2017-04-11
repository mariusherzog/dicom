#include "attribute_field_coder.hpp"

#include <type_traits>

#include <cstdio>

namespace dicom
{

namespace data
{

namespace attribute
{

namespace convhelper
{
template <typename T>
static std::vector<unsigned char> integral_to_little_endian(T data, int size)
{
   static_assert(std::is_integral<T>::value, "Integral type expected");
   std::vector<unsigned char> buf(size);
   for (int i=0; i<size; ++i) {
      buf[i] = ((data >> 8*i) & 0xff);
   }
   return buf;
}

template <typename T>
static std::vector<unsigned char> integral_to_big_endian(T data, int size)
{
   static_assert(std::is_integral<T>::value, "Integral type expected");
   std::vector<unsigned char> buf(size);
   for (int i=0; i<size; ++i) {
      buf[i] = (data >> (8*(size-1-i)) & 0xff);
   }
   return buf;
}

template <typename T>
static void little_endian_to_integral(const std::vector<unsigned char>& data
                                      , int begin, int size, T& out)
{
   static_assert(std::is_integral<T>::value, "Integral type expected");
   out = 0;
   for (int i=0; i<size; ++i) {
      out |= ((data[begin+i] & 0xff) << 8*i);
   }
}

template <typename T>
static void big_endian_to_integral(const std::vector<unsigned char>& data
                                      , int begin, int size, T& out)
{
   static_assert(std::is_integral<T>::value, "Integral type expected");
   out = 0;
   for (int i=0; i<size; ++i) {
      out |= ((data[begin+i] & 0xff) << 8*(size-1-i));
   }
}

template <typename T>
static std::vector<unsigned char> float_to_little_endian(T data, int size)
{
   static_assert(std::is_floating_point<T>::value, "Floating type expected");
   static_assert(sizeof(T) == 4 || sizeof(T) == 8, "Unexpected floating point size");
   std::vector<unsigned char> buf(size);
   unsigned char floatbuf[sizeof(T)];
   unsigned char* floatbufin = floatbuf;
   floatbufin = reinterpret_cast<unsigned char*>(&data);
   for (int i=0; i<size; ++i) {
      buf[i] = floatbufin[i];
   }
   return buf;
}

template <typename T>
static std::vector<unsigned char> float_to_big_endian(T data, int size)
{
   static_assert(std::is_floating_point<T>::value, "Floating type expected");
   static_assert(sizeof(T) == 4 || sizeof(T) == 8, "Unexpected floating point size");
   std::vector<unsigned char> buf(size);
   unsigned char floatbuf[sizeof(T)];
   unsigned char* floatbufin = floatbuf;
   floatbufin = reinterpret_cast<unsigned char*>(&data);
   for (int i=size-1; i>=0; --i) {
      buf[i] = floatbufin[i];
   }
   return buf;
}

template <typename T>
static void little_endian_to_float(const std::vector<unsigned char>& data
                                      , int begin, int size, T& out)
{
   static_assert(std::is_floating_point<T>::value, "Floating type expected");
   static_assert(sizeof(T) == 4 || sizeof(T) == 8, "Unexpected floating point size");
   out = 0;
   unsigned char floatbufout[sizeof(T)] = {0};
   for (int i=0; i<size; ++i) {
      floatbufout[i] |= ((data[begin+i] & 0xff));
   }
   out = *reinterpret_cast<T*>(floatbufout);
}

template <typename T>
static void big_endian_to_float(const std::vector<unsigned char>& data
                                      , int begin, int size, T& out)
{
   static_assert(std::is_floating_point<T>::value, "Floating type expected");
   static_assert(sizeof(T) == 4 || sizeof(T) == 8, "Unexpected floating point size");
   out = 0;
   unsigned char floatbufout[sizeof(T)] = {0};
   for (int i=0; i<size; ++i) {
      floatbufout[i] |= ((data[begin+size-1-i] & 0xff));
   }
   out = *reinterpret_cast<T*>(floatbufout);
}

static std::vector<unsigned char> encode_byte_string(attribute::vmtype<std::string> str)
{
   std::vector<unsigned char> buf;
   int offset = 0;
   for (auto it = str.begin(); it != str.end(); ++it)
   {
      std::string value = *it;
      if (it != str.begin()) { //beginning from the 2nd element, start preceding
                               //with the separator backslash
         buf.push_back(0x5c);
         offset = buf.size();
      }

      buf.resize(buf.size() + value.size());
      for (std::size_t i=0; i<value.size(); ++i) {
         buf[offset + i] = static_cast<unsigned char>(value[i]);
      }
   }
   if (buf.size() % 2 != 0) {
      buf.push_back('\0');
   }
   return buf;
}

static std::vector<unsigned char> encode_byte_array(const std::vector<unsigned char>& strdata)
{
   return std::vector<unsigned char> {strdata};
}

static std::vector<unsigned char> encode_word_array_le(const std::vector<unsigned char>& strdata)
{
   // encoding a stream in little endian does not require byte swapping as it
   // matches the local machine's layout
   return std::vector<unsigned char> {strdata};
}

static attribute::vmtype<std::string> decode_byte_string(const std::vector<unsigned char>& strdata, std::string vm, int begin, int len)
{
   std::vector<std::string> strings;

   //std::vector<unsigned char> buf(len);
   std::vector<unsigned char> buf;
   int size_segments = 0;
   for (int i=begin; i<begin+len; ++i) {
      if (strdata[i] == 0x5c) {
         strings.emplace_back(buf.begin(), buf.end());
         buf.clear();
         ++i; //skip delimiter
         //buf.resize(i-begin-size_segments);
         size_segments = i-begin;
      }

      //buf[i-begin-size_segments] = static_cast<unsigned char>(strdata[i]);
      buf.push_back(static_cast<unsigned char>(strdata[i]));
   }
   strings.emplace_back(buf.begin(), buf.end());
   return attribute::vmtype<std::string>(vm, strings.begin(), strings.end()); ///todo: change to correct VM
}

static std::vector<unsigned char> decode_byte_array(const std::vector<unsigned char>& strdata, int begin, int len)
{
   std::vector<unsigned char> str {strdata.begin()+begin, strdata.begin()+begin+len};
   if (len % 2 != 0) {
      str.push_back(0x00);
   }
   assert(len % 2 == 0);
   return str;
}

static std::vector<unsigned char> decode_word_array_le(const std::vector<unsigned char>& strdata, int begin, int len)
{
   // decoding a stream in little endian does not require byte swapping as it
   // matches the local machine's layout
   std::vector<unsigned char> str {strdata.begin()+begin, strdata.begin()+begin+len};
   if (len % 2 != 0) {
      str.push_back(0x00);
   }
   assert(len % 2 == 0);
   return str;
}

}



/**
 * @brief encode_tag_little_endian converts the element tag into a little endian
 *        representation of 8 bytes
 * @param tag tag to be encoded
 * @return vector of bytes representing the tag in little endian
 */
std::vector<unsigned char> encode_tag_little_endian(tag_type tag)
{
   std::vector<unsigned char> data;
   auto group_le = convhelper::integral_to_little_endian(tag.group_id, 2);
   auto elem_le = convhelper::integral_to_little_endian(tag.element_id, 2);
   data.insert(data.begin(), elem_le.begin(), elem_le.end());
   data.insert(data.begin(), group_le.begin(), group_le.end());
   return data;
}

/**
 * @brief encode_tag_big_endian converts the element tag into a big endian
 *        representation of 8 bytes
 * @param tag tag to be encoded
 * @return vector of bytes representing the tag in big endian
 */
std::vector<unsigned char> encode_tag_big_endian(tag_type tag)
{
   std::vector<unsigned char> data;
   auto group_le = convhelper::integral_to_big_endian(tag.group_id, 2);
   auto elem_le = convhelper::integral_to_big_endian(tag.element_id, 2);
   data.insert(data.begin(), elem_le.begin(), elem_le.end());
   data.insert(data.begin(), group_le.begin(), group_le.end());
   return data;
}

/**
 * @brief encode_len_little_endian converts a length of a value field into
 *        a 4-byte little endian representation.
 * @param len length
 * @return 4 bytes of the parameter length in little endian
 */
std::vector<unsigned char> encode_len_little_endian(std::size_t lenbytes, std::size_t len)
{
   return convhelper::integral_to_little_endian(len, lenbytes);
}

/**
 * @brief encode_len_big_endian converts a length of a value field into
 *        a 4-byte big endian representation.
 * @param len length
 * @return 4 bytes of the parameter length in big endian
 */
std::vector<unsigned char> encode_len_big_endian(std::size_t lenbytes, std::size_t len)
{
   return convhelper::integral_to_big_endian(len, lenbytes);
}

/**
 * @brief decode_tag_little_endian transforms the serialized tag data into a
 *        structured form.
 * @param data serialized stream data
 * @param begin beginning, as in absolute position from the data stream start,
 *        of the value field
 * @return instance of tag_type with the tag elements
 */
tag_type decode_tag_little_endian(const std::vector<unsigned char>& data, int begin)
{
   unsigned short gid, eid;
   convhelper::little_endian_to_integral(data, begin, 2, gid);
   convhelper::little_endian_to_integral(data, begin+2, 2, eid);

   tag_type tag {gid, eid};
   return tag;
}

/**
 * @brief decode_tag_big_endian transforms the serialized tag data into a
 *        structured form.
 * @param data serialized stream data
 * @param begin beginning, as in absolute position from the data stream start,
 *        of the value field
 * @return instance of tag_type with the tag elements
 */
tag_type decode_tag_big_endian(const std::vector<unsigned char>& data, int begin)
{
   unsigned short gid, eid;
   convhelper::big_endian_to_integral(data, begin, 2, gid);
   convhelper::big_endian_to_integral(data, begin+2, 2, eid);

   tag_type tag {gid, eid};
   return tag;
}

/**
 * @brief decode_len_little_endian transforms the serialized length data into a
 *        structured form.
 * @param data serialized stream data
 * @param lenbytes size in bytes of the length field
 * @param begin beginning, as in absolute position from the data stream start,
 *        of the value field
 * @return length specified in the serialized stream data
 */
std::size_t decode_len_little_endian(const std::vector<unsigned char>& data, std::size_t lenbytes, int begin)
{
   std::size_t len;
      convhelper::little_endian_to_integral(data, begin, lenbytes, len);
   return len;
}

/**
 * @brief decode_len_big_endian transforms the serialized length data into a
 *        structured form.
 * @param data serialized stream data
 * @param begin beginning, as in absolute position from the data stream start,
 *        of the value field
 * @return length specified in the serialized stream data
 */
std::size_t decode_len_big_endian(const std::vector<unsigned char>& data, std::size_t lenbytes, int begin)
{
   std::size_t len;
      convhelper::big_endian_to_integral(data, begin, lenbytes, len);
   return len;
}



std::vector<unsigned char> encode_value_field(elementfield attr, ENDIANNESS endianness, const VR vr)
{
   std::vector<unsigned char> data;
   switch (vr) {
      case VR::AE: {
         attribute::vmtype<std::string> ae;
         get_value_field<VR::AE>(attr, ae);
         data = convhelper::encode_byte_string(ae);
         break;
      }
      case VR::AS: {
         attribute::vmtype<std::string> as;
         get_value_field<VR::AS>(attr, as);
         data = convhelper::encode_byte_string(as);
         break;
      }
      case VR::AT: {
         tag_type tag;
         get_value_field<VR::AT>(attr, tag);
         std::vector<unsigned char> group_le, elem_le;
         if (endianness == ENDIANNESS::LITTLE) {
            group_le = convhelper::integral_to_little_endian(tag.group_id, 2);
            elem_le = convhelper::integral_to_little_endian(tag.element_id, 2);
         } else {
            group_le = convhelper::integral_to_big_endian(tag.group_id, 2);
            elem_le = convhelper::integral_to_big_endian(tag.element_id, 2);
         }
         data.insert(data.begin(), elem_le.begin(), elem_le.end());
         data.insert(data.begin(), group_le.begin(), group_le.end());
         break;
      }
      case VR::CS: {
         attribute::vmtype<std::string> cs;
         get_value_field<VR::CS>(attr, cs);
         data = convhelper::encode_byte_string(cs);
         break;
      }
      case VR::DA: {
         attribute::vmtype<std::string> da;
         get_value_field<VR::DA>(attr, da);
         data = convhelper::encode_byte_string(da);
         break;
      }
      case VR::DS: {
         attribute::vmtype<std::string> ds;
         get_value_field<VR::DS>(attr, ds);
         data = convhelper::encode_byte_string(ds);
         break;
      }
      case VR::DT: {
         attribute::vmtype<std::string> dt;
         get_value_field<VR::DT>(attr, dt);
         data = convhelper::encode_byte_string(dt);
         break;
      }
      case VR::FL: {
         float field;
         get_value_field<VR::FL>(attr, field);
         if (endianness == ENDIANNESS::LITTLE) {
            data = convhelper::float_to_little_endian(field, 4);
         } else {
            data = convhelper::float_to_big_endian(field, 4);
         }
         break;
      }
      case VR::FD: {
         double field;
         get_value_field<VR::FD>(attr, field);
         if (endianness == ENDIANNESS::LITTLE) {
            data = convhelper::float_to_little_endian(field, 8);
         } else {
            data = convhelper::float_to_big_endian(field, 8);
         }
         break;
      }
      case VR::IS: {
         attribute::vmtype<std::string> is;
         get_value_field<VR::IS>(attr, is);
         data = convhelper::encode_byte_string(is);
         break;
      }
      case VR::LO: {
         attribute::vmtype<std::string> lo;
         get_value_field<VR::LO>(attr, lo);
         data = convhelper::encode_byte_string(lo);
         break;
      }
      case VR::LT: {
         std::string lt;
         get_value_field<VR::LT>(attr, lt);
         data = convhelper::encode_byte_string(lt);
         break;
      }
      case VR::OB: {
         std::vector<unsigned char> ob;
         get_value_field<VR::OB>(attr, ob);
         data = convhelper::encode_byte_array(ob);
         break;
      }
      case VR::OD: {
         attribute::vmtype<std::string> od;
         get_value_field<VR::OD>(attr, od);
         data = convhelper::encode_byte_string(od);
         break;
      }
      case VR::OF: {
         attribute::vmtype<std::string> of;
         get_value_field<VR::OF>(attr, of);
         data = convhelper::encode_byte_string(of);
         break;
      }
      case VR::OW: {
         std::vector<unsigned char> ow;
         get_value_field<VR::OW>(attr, ow);
         data = convhelper::encode_word_array_le(ow);
         break;
      }
      case VR::PN: {
         attribute::vmtype<std::string> pn;
         get_value_field<VR::PN>(attr, pn);
         data = convhelper::encode_byte_string(pn);
         break;
      }
      case VR::SH: {
         attribute::vmtype<std::string> sh;
         get_value_field<VR::SH>(attr, sh);
         data = convhelper::encode_byte_string(sh);
         break;
      }
      case VR::SL: {
         long field;
         get_value_field<VR::SL>(attr, field);
         if (endianness == ENDIANNESS::LITTLE) {
            data = convhelper::integral_to_little_endian(field, 4);
         } else {
            data = convhelper::integral_to_big_endian(field, 4);
         }
         break;
      }
      case VR::SQ: {
         // do nothing, value field consists of nested attributes which will be
         // encoded in the next iteration
         break;
      }
      case VR::SS: {
         short field;
         get_value_field<VR::SS>(attr, field);
         if (endianness == ENDIANNESS::LITTLE) {
            data = convhelper::integral_to_little_endian(field, 2);
         } else {
            data = convhelper::integral_to_big_endian(field, 2);
         }
         break;
      }
      case VR::ST: {
         std::string st;
         get_value_field<VR::ST>(attr, st);
         data = convhelper::encode_byte_string(st);
         break;
      }
      case VR::TM: {
         attribute::vmtype<std::string> tm;
         get_value_field<VR::TM>(attr, tm);
         data = convhelper::encode_byte_string(tm);
         break;
      }
      case VR::UI: {
         attribute::vmtype<std::string> ui;
         get_value_field<VR::UI>(attr, ui);
         data = convhelper::encode_byte_string(ui);
         break;
      }
      case VR::UL: {
         unsigned int field;
         get_value_field<VR::UL>(attr, field);
         if (endianness == ENDIANNESS::LITTLE) {
            data = convhelper::integral_to_little_endian(field, 4);
         } else {
            data = convhelper::integral_to_big_endian(field, 4);
         }
         break;
      }
      case VR::UN: { /** @todo */
         break;
      }
      case VR::UR: {
         attribute::vmtype<std::string> ur;
         get_value_field<VR::UR>(attr, ur);
         data = convhelper::encode_byte_string(ur);
         break;
      }
      case VR::US: {
         unsigned short field;
         get_value_field<VR::US>(attr, field);
         if (endianness == ENDIANNESS::LITTLE) {
            data = convhelper::integral_to_little_endian(field, 2);
         } else {
            data = convhelper::integral_to_big_endian(field, 2);
         }
         break;
      }
      case VR::UT: {
         std::string ut;
         get_value_field<VR::UT>(attr, ut);
         data = convhelper::encode_byte_string(ut);
         break;
      }
      default:
         break;
   }

   return data;
}




elementfield decode_value_field(const std::vector<unsigned char>& data, ENDIANNESS endianness,
                                  std::size_t len, VR vr, std::string vm, int begin)
{
   switch (vr) {
      case VR::AE: {
         auto ae = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::AE>(len, ae);
      }
      case VR::AS: {
         auto as = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::AS>(len, as);
      }
      case VR::AT: {
         short gid, eid;
         if (endianness == ENDIANNESS::LITTLE) {
            convhelper::little_endian_to_integral(data, begin, 2, gid);
            convhelper::little_endian_to_integral(data, begin, 2, eid);
         } else {
            convhelper::big_endian_to_integral(data, begin, 2, gid);
            convhelper::big_endian_to_integral(data, begin, 2, eid);
         }
         tag_type tag;
         tag.element_id = eid;
         tag.group_id = gid;
         return make_elementfield<VR::AT>(len, tag);
         break;
      }
      case VR::CS: {
         auto cs = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::CS>(len, cs);
         break;
      }
      case VR::DA: {
         auto da = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::DA>(len, da);
         break;
      }
      case VR::DS: {
         auto ds = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::DS>(len, ds);
         break;
      }
      case VR::DT: {
         auto dt = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::DT>(len, dt);
         break;
      }
      case VR::FL: {
         float fl;
         if (endianness == ENDIANNESS::LITTLE) {
            convhelper::little_endian_to_float(data, begin, len, fl);
         } else {
            convhelper::big_endian_to_float(data, begin, len, fl);
         }
         return make_elementfield<VR::FL>(len, fl);
         break;
      }
      case VR::FD: {
         double fd;
         if (endianness == ENDIANNESS::LITTLE) {
            convhelper::little_endian_to_float(data, begin, len, fd);
         } else {
            convhelper::big_endian_to_float(data, begin, len, fd);
         }
         return make_elementfield<VR::FD>(len, fd);
         break;
      }
      case VR::IS: {
         auto is = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::IS>(len, is);
         break;
      }
      case VR::LO: {
         auto lo = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::LO>(len, lo);
         break;
      }
      case VR::LT: {
         auto lt = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::LT>(len, lt);
      }
      case VR::OB: {
         std::vector<unsigned char> ob;
         ob = convhelper::decode_byte_array(data, begin, len);
         return make_elementfield<VR::OB>(len, ob);
         break;
      }
      case VR::OD: {
         auto od = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::OD>(len, od);
      }
      case VR::OF: {
         auto of = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::OF>(len, of);
      }
      case VR::OW: {
         auto ow = convhelper::decode_word_array_le(data, begin, len);
         return make_elementfield<VR::OW>(len, ow);
         break;
      }
      case VR::PN: {
         auto pn = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::PN>(len, pn);
      }
      case VR::SH: {
         auto sh = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::SH>(len, sh);
      }
      case VR::SL: {
         long val;
         if (endianness == ENDIANNESS::LITTLE) {
            convhelper::little_endian_to_integral(data, begin, 4, val);
         } else {
            convhelper::big_endian_to_integral(data, begin, 4, val);
         }
         return make_elementfield<VR::SL>(len, val);
      }
      case VR::SQ: {

      }
      case VR::SS: {
         short val;
         if (endianness == ENDIANNESS::LITTLE) {
            convhelper::little_endian_to_integral(data, begin, 2, val);
         } else {
            convhelper::big_endian_to_integral(data, begin, 2, val);
         }
         return make_elementfield<VR::SS>(len, val);
      }
      case VR::ST: {
         auto st = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::ST>(len, st);
      }
      case VR::TM: {
         auto tm = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::TM>(len, tm);
      }
      case VR::UL: {
         unsigned long val;
         if (endianness == ENDIANNESS::LITTLE) {
            convhelper::little_endian_to_integral(data, begin, 4, val);
         } else {
            convhelper::big_endian_to_integral(data, begin, 4, val);
         }
         return make_elementfield<VR::UL>(len, val);
      }
      case VR::UI: {
         auto ui = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::UI>(len, ui);
      }
      case VR::UR: {
         auto ur = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::UR>(len, ur);
      }
      case VR::US: {
         unsigned short val;
         if (endianness == ENDIANNESS::LITTLE) {
            convhelper::little_endian_to_integral(data, begin, 2, val);
         } else {
            convhelper::big_endian_to_integral(data, begin, 2, val);
         }
         return make_elementfield<VR::US>(len, val);
      }
      case VR::UT: {
         auto ut = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::UT>(len, ut);
      }
      default:
         assert(false);
         break;
   }
   assert(false);
}

std::vector<unsigned char> encode_tag(tag_type tag, ENDIANNESS endianness)
{
   if (endianness == ENDIANNESS::LITTLE) {
      return encode_tag_little_endian(tag);
   } else {
      return encode_tag_big_endian(tag);
   }
}

std::vector<unsigned char> encode_len(std::size_t lenbytes, std::size_t len, ENDIANNESS endianness)
{
   if (endianness == ENDIANNESS::LITTLE) {
      return encode_len_little_endian(lenbytes, len);
   } else {
      return encode_len_big_endian(lenbytes, len);
   }
}

tag_type decode_tag(const std::vector<unsigned char>& data, int begin, ENDIANNESS endianness)
{
   if (endianness == ENDIANNESS::LITTLE) {
      return decode_tag_little_endian(data, begin);
   } else {
      return decode_tag_big_endian(data, begin);
   }
}

std::size_t decode_len(const std::vector<unsigned char>& data, ENDIANNESS endianness, std::size_t lenbytes, int begin)
{
   if (endianness == ENDIANNESS::LITTLE) {
      return decode_len_little_endian(data, lenbytes, begin);
   } else {
      return decode_len_big_endian(data, lenbytes, begin);
   }
}

}

}

}
