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
   for (auto it = str.begin(); it != str.end(); ++it) {
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

static std::vector<unsigned char> encode_word_array_le(const std::vector<unsigned short>& strdata)
{
   std::vector<unsigned char> buf;
   buf.reserve(strdata.size() * 2);
   for (const auto v : strdata) {
      buf.push_back((v & 0xff));
      buf.push_back((v & 0xff00) >> 8);
   }
   return buf;
}

static std::vector<unsigned char> encode_word_array_be(const std::vector<unsigned short>& strdata)
{
   std::vector<unsigned char> buf;
   buf.reserve(strdata.size() * 2);
   for (const auto v : strdata) {
      buf.push_back((v & 0xff) >> 8);
      buf.push_back((v & 0xff00));
   }
   return buf;
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

static std::vector<unsigned short> decode_word_array_le(const std::vector<unsigned char>& strdata, int begin, int len)
{
   std::vector<unsigned short> str;
   str.reserve(len/2);

   for (int i=begin; i<begin+len; i+=2) {
      unsigned short value = 0;
      value |= (strdata[i]);
      value |= (strdata[i + 1] << 8);
      str.push_back(value);
   }

   if (len % 2 != 0) {
      str.push_back(0x00);
   }
   assert(len % 2 == 0);
   return str;
}

static std::vector<unsigned short> decode_word_array_be(const std::vector<unsigned char>& strdata, int begin, int len)
{
   std::vector<unsigned short> str;
   str.reserve(len/2);

   for (int i=begin; i<begin+len; i+=2) {
      unsigned short value = 0;
      value |= (strdata[i + 1]);
      value |= (strdata[i] << 8);
      str.push_back(value);
   }

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


template <typename T, typename Fn>
std::vector<unsigned char> serialize_vmtype(const vmtype<T>& vmdata, Fn&& function, const std::size_t size)
{
   auto fn = std::move(function);
   std::vector<unsigned char> data;
   data.reserve(size*data.size());
   for (auto it = vmdata.cbegin(); it != vmdata.cend(); ++it) {
      const auto& value = *it;
      auto serdata = fn(value, size);
      data.insert(data.end(), serdata.begin(), serdata.end());
   }
   return data;
}

template <typename T, typename Fn>
void deserialize_vmtype(const std::vector<unsigned char>& data, Fn&& function,
                        const std::size_t begin, const std::size_t len,
                        const std::size_t size,
                        vmtype<T>& values)
{
   auto fn = std::move(function);
   std::vector<T> vals;
   vals.reserve(len/sizeof(T));
   for (int i=0; i<len; i+=size)
   {
      T out;
      fn(data, begin + i, size, out);
      vals.emplace_back(std::move(out));
   }
   values.insert(vals.begin(), vals.end());
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
         attribute::vmtype<float> fl;
         get_value_field<VR::FL>(attr, fl);
         if (endianness == ENDIANNESS::LITTLE) {
            data = serialize_vmtype(fl, convhelper::float_to_little_endian<float>, 4);
         } else {
            data = serialize_vmtype(fl, convhelper::float_to_big_endian<float>, 4);
         }
         break;
      }
      case VR::FD: {
         attribute::vmtype<double> fd;
         get_value_field<VR::FD>(attr, fd);
         if (endianness == ENDIANNESS::LITTLE) {
            data = serialize_vmtype(fd, convhelper::float_to_little_endian<double>, 8);
         } else {
            data = serialize_vmtype(fd, convhelper::float_to_big_endian<double>, 8);
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
         std::vector<unsigned short> ow;
         get_value_field<VR::OW>(attr, ow);
         if (endianness == ENDIANNESS::LITTLE) {
             data = convhelper::encode_word_array_le(ow);
         } else {
             data = convhelper::encode_word_array_be(ow);
         }
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
         attribute::vmtype<long> sl;
         get_value_field<VR::SL>(attr, sl);
         if (endianness == ENDIANNESS::LITTLE) {
            data = serialize_vmtype(sl, convhelper::integral_to_little_endian<long>, 4);
         } else {
            data = serialize_vmtype(sl, convhelper::integral_to_big_endian<long>, 4);
         }
         break;
      }
      case VR::SQ: {
         // do nothing, value field consists of nested attributes which will be
         // encoded in the next iteration
         break;
      }
      case VR::SS: {
         attribute::vmtype<short> ss;
         get_value_field<VR::SS>(attr, ss);
         if (endianness == ENDIANNESS::LITTLE) {
            data = serialize_vmtype(ss, convhelper::integral_to_little_endian<short>, 2);
         } else {
            data = serialize_vmtype(ss, convhelper::integral_to_big_endian<short>, 2);
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
         attribute::vmtype<unsigned int> ul;
         get_value_field<VR::UL>(attr, ul);
         if (endianness == ENDIANNESS::LITTLE) {
            data = serialize_vmtype(ul, convhelper::integral_to_little_endian<unsigned int>, 4);
         } else {
            data = serialize_vmtype(ul, convhelper::integral_to_big_endian<unsigned int>, 4);
         }
         break;
      }
      case VR::UN: {
         std::vector<unsigned char> un;
         get_value_field<VR::UN>(attr, un);
         data = convhelper::encode_byte_array(un);
         break;
      }
      case VR::UR: {
         attribute::vmtype<std::string> ur;
         get_value_field<VR::UR>(attr, ur);
         data = convhelper::encode_byte_string(ur);
         break;
      }
      case VR::US: {
         attribute::vmtype<unsigned short> us;
         get_value_field<VR::US>(attr, us);
         if (endianness == ENDIANNESS::LITTLE) {
            data = serialize_vmtype(us, convhelper::integral_to_little_endian<unsigned short>, 2);
         } else {
            data = serialize_vmtype(us, convhelper::integral_to_big_endian<unsigned short>, 2);
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
         vmtype<float> fl;
         if (endianness == ENDIANNESS::LITTLE) {
            deserialize_vmtype(data, convhelper::little_endian_to_float<float>, begin, len, 4, fl);
         } else {
            deserialize_vmtype(data, convhelper::big_endian_to_float<float>, begin, len, 4, fl);
         }
         return make_elementfield<VR::FL>(len, fl);
         break;
      }
      case VR::FD: {
         vmtype<double> fd;
         if (endianness == ENDIANNESS::LITTLE) {
            deserialize_vmtype(data, convhelper::little_endian_to_float<double>, begin, len, 8, fd);
         } else {
            deserialize_vmtype(data, convhelper::big_endian_to_float<double>, begin, len, 8, fd);
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
         std::vector<unsigned short> ow;
         if (endianness == ENDIANNESS::LITTLE) {
             ow = convhelper::decode_word_array_le(data, begin, len);
         } else {
             ow = convhelper::decode_word_array_be(data, begin, len);
         }
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
         vmtype<long> sl;
         if (endianness == ENDIANNESS::LITTLE) {
            deserialize_vmtype(data, convhelper::little_endian_to_integral<long>, begin, len, 4, sl);
         } else {
            deserialize_vmtype(data, convhelper::big_endian_to_integral<long>, begin, len, 4, sl);
         }
         return make_elementfield<VR::SL>(len, sl);
      }
      case VR::SQ: {

      }
      case VR::SS: {
         vmtype<short> ss;
         if (endianness == ENDIANNESS::LITTLE) {
            deserialize_vmtype(data, convhelper::little_endian_to_integral<short>, begin, len, 2, ss);
         } else {
            deserialize_vmtype(data, convhelper::big_endian_to_integral<short>, begin, len, 2, ss);
         }
         return make_elementfield<VR::SS>(len, ss);
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
         vmtype<unsigned long> ul;
         if (endianness == ENDIANNESS::LITTLE) {
            deserialize_vmtype(data, convhelper::little_endian_to_integral<unsigned long>, begin, len, 4, ul);
         } else {
            deserialize_vmtype(data, convhelper::big_endian_to_integral<unsigned long>, begin, len, 4, ul);
         }
         return make_elementfield<VR::UL>(len, ul);
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
         vmtype<unsigned short> us;
         if (endianness == ENDIANNESS::LITTLE) {
            deserialize_vmtype(data, convhelper::little_endian_to_integral<unsigned short>, begin, len, 2, us);
         } else {
            deserialize_vmtype(data, convhelper::big_endian_to_integral<unsigned short>, begin, len, 2, us);
         }
         return make_elementfield<VR::US>(len, us);
      }
      case VR::UT: {
         auto ut = convhelper::decode_byte_string(data, vm, begin, len);
         return make_elementfield<VR::UT>(len, ut);
      }
      case VR::UN: {
         std::vector<unsigned char> un;
         un = convhelper::decode_byte_array(data, begin, len);
         return make_elementfield<VR::UN>(len, un);
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
