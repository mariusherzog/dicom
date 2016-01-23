#include "attribute_field_coder.hpp"

#include <type_traits>

#include <cstdio>


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
static std::vector<unsigned char> float_to_little_endian(T data, int size)
{
   static_assert(std::is_floating_point<T>::value, "Integral type expected");
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
static void little_endian_to_float(const std::vector<unsigned char>& data
                                      , int begin, int size, T& out)
{
   static_assert(std::is_floating_point<T>::value, "Integral type expected");
   static_assert(sizeof(T) == 4 || sizeof(T) == 8, "Unexpected floating point size");
   out = 0;
//   unsigned char floatbuf[sizeof(T)];
   unsigned char floatbufout[sizeof(T)];
//   unsigned char* floatbufin = floatbuf;
//   floatbufin = reinterpret_cast<unsigned char*>(&out);
   for (int i=0; i<size; ++i) {
      floatbufout[i] |= ((data[begin+i] & 0xff));
   }
   out = *reinterpret_cast<float*>(floatbufout);
}

static std::vector<unsigned char> decode_byte_string(std::string str)
{
   std::vector<unsigned char> buf(str.size());
   for (std::size_t i=0; i<str.size(); ++i) {
      buf[i] = static_cast<unsigned char>(str[i]);
   }
   if (str.length() % 2 != 0) {
      buf.push_back('\0');
   }
   return buf;
}

static std::string encode_byte_string(const std::vector<unsigned char>& strdata, int begin, int len)
{
   std::vector<unsigned char> buf(len);
   for (int i=begin; i<begin+len; ++i) {
      buf[i-begin] = static_cast<unsigned char>(strdata[i]);
   }
   return std::string {buf.begin(), buf.end()};
}

}

/**
 * @brief decode_tag_little_endian converts the element tag into a little endian
 *        representation of 8 bytes
 * @param tag tag to be encoded
 * @return vector of bytes representing the tag in little endian
 */
std::vector<unsigned char> decode_tag_little_endian(elementfield::tag_type tag)
{
   std::vector<unsigned char> data;
   auto group_le = convhelper::integral_to_little_endian(tag.group_id, 2);
   auto elem_le = convhelper::integral_to_little_endian(tag.element_id, 2);
   data.insert(data.begin(), elem_le.begin(), elem_le.end());
   data.insert(data.begin(), group_le.begin(), group_le.end());
   return data;
}

/**
 * @brief decode_len_little_endian converts a length of a value field into
 *        a 4-byte little endian representation
 * @param len length
 * @return 4 bytes of the parameter length in little endian
 */
std::vector<unsigned char> decode_len_little_endian(std::size_t len)
{
   return convhelper::integral_to_little_endian(len, 4);
}


elementfield::tag_type encode_tag_little_endian(const std::vector<unsigned char>& data, int begin)
{
   short gid, eid;
   convhelper::little_endian_to_integral(data, begin, 2, gid);
   convhelper::little_endian_to_integral(data, begin+2, 2, eid);

   elementfield::tag_type tag;
   tag.element_id = eid;
   tag.group_id = gid;
   return tag;
}

std::size_t encode_len_little_endian(const std::vector<unsigned char>& data, int begin)
{
   std::size_t len;
   convhelper::little_endian_to_integral(data, begin, 4, len);
   return len;
}



std::vector<unsigned char> decode_little_endian(elementfield attr, const VR vr)
{
   std::vector<unsigned char> data;
   switch (vr) {
      case VR::AE: {
         std::string ae;
         get_value_field<VR::AE>(attr, ae);
         data = convhelper::decode_byte_string(ae);
         break;
      }
      case VR::AS: {
         std::string as;
         get_value_field<VR::AS>(attr, as);
         data = convhelper::decode_byte_string(as);
         break;
      }
      case VR::AT: {
         elementfield::tag_type tag;
         get_value_field<VR::AT>(attr, tag);
         auto group_le = convhelper::integral_to_little_endian(tag.group_id, 2);
         auto elem_le = convhelper::integral_to_little_endian(tag.element_id, 2);
         data.insert(data.begin(), elem_le.begin(), elem_le.end());
         data.insert(data.begin(), group_le.begin(), group_le.end());
         break;
      }
      case VR::CS: {
         std::string cs;
         get_value_field<VR::CS>(attr, cs);
         data = convhelper::decode_byte_string(cs);
         break;
      }
      case VR::DA: {
         std::string da;
         get_value_field<VR::DA>(attr, da);
         data = convhelper::decode_byte_string(da);
         break;
      }
      case VR::DS: {
         std::string ds;
         get_value_field<VR::DS>(attr, ds);
         data = convhelper::decode_byte_string(ds);
         break;
      }
      case VR::DT: {
         std::string dt;
         get_value_field<VR::DT>(attr, dt);
         data = convhelper::decode_byte_string(dt);
      }
      case VR::FL: {
         float field;
         get_value_field<VR::FL>(attr, field);
         data = convhelper::float_to_little_endian(field, 4);
         break;
      }
      case VR::FD: {
         double field;
         get_value_field<VR::FD>(attr, field);
         data = convhelper::float_to_little_endian(field, 8);
         break;
      }
      case VR::IS: {
         std::string is;
         get_value_field<VR::IS>(attr, is);
         data = convhelper::decode_byte_string(is);
         break;
      }
      case VR::LO: {
         std::string lo;
         get_value_field<VR::LO>(attr, lo);
         data = convhelper::decode_byte_string(lo);
         break;
      }
      case VR::LT: {
         std::string lt;
         get_value_field<VR::LT>(attr, lt);
         data = convhelper::decode_byte_string(lt);
         break;
      }
      case VR::OB: { /** @todo */
         break;
      }
      case VR::OD: {
         std::string od;
         get_value_field<VR::OD>(attr, od);
         data = convhelper::decode_byte_string(od);
         break;
      }
      case VR::OF: {
         std::string of;
         get_value_field<VR::OF>(attr, of);
         data = convhelper::decode_byte_string(of);
         break;
      }
      case VR::OW: { /** @todo */
         break;
      }
      case VR::PN: {
         std::string pn;
         get_value_field<VR::PN>(attr, pn);
         data = convhelper::decode_byte_string(pn);
         break;
      }
      case VR::SH: {
         std::string sh;
         get_value_field<VR::SH>(attr, sh);
         data = convhelper::decode_byte_string(sh);
         break;
      }
      case VR::SL: {
         long field;
         get_value_field<VR::SL>(attr, field);
         data = convhelper::integral_to_little_endian(field, 4);
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
         data = convhelper::integral_to_little_endian(field, 2);
         break;
      }
      case VR::ST: {
         std::string st;
         get_value_field<VR::ST>(attr, st);
         data = convhelper::decode_byte_string(st);
         break;
      }
      case VR::TM: {
         std::string tm;
         get_value_field<VR::TM>(attr, tm);
         data = convhelper::decode_byte_string(tm);
         break;
      }
      case VR::UI: {
         std::string ui;
         get_value_field<VR::UI>(attr, ui);
         data = convhelper::decode_byte_string(ui);
         break;
      }
      case VR::UL: {
         unsigned int field;
         get_value_field<VR::UL>(attr, field);
         data = convhelper::integral_to_little_endian(field, 4);
         break;
      }
      case VR::UN: { /** @todo */
         break;
      }
      case VR::UR: {
         std::string ur;
         get_value_field<VR::UR>(attr, ur);
         data = convhelper::decode_byte_string(ur);
         break;
      }
      case VR::US: {
         unsigned short field;
         get_value_field<VR::US>(attr, field);
         data = convhelper::integral_to_little_endian(field, 2);
         break;
      }
      case VR::UT: {
         std::string ut;
         get_value_field<VR::UT>(attr, ut);
         data = convhelper::decode_byte_string(ut);
         break;
      }
      default:
         break;
   }

   return data;
}




elementfield encode_little_endian(const std::vector<unsigned char>& data
                                  , elementfield::tag_type tag, std::size_t len, VR vr
                                  , int begin)
{
   switch (vr) {
      case VR::AE: {
         std::string ae;
         ae = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::AE>(tag.group_id, tag.element_id, len, ae);
      }
      case VR::AS: {
         std::string as;
         as = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::AS>(tag.group_id, tag.element_id, len, as);
      }
      case VR::AT: {
         short gid, eid;
         convhelper::little_endian_to_integral(data, begin, 2, gid);
         convhelper::little_endian_to_integral(data, begin, 2, eid);
         elementfield::tag_type tag;
         tag.element_id = eid;
         tag.group_id = gid;
         return make_elementfield<VR::AT>(tag.group_id, tag.element_id, len, tag);
         break;
      }
      case VR::CS: {
         std::string cs;
         cs = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::CS>(tag.group_id, tag.element_id, len, cs);
         break;
      }
      case VR::DA: {
         std::string da;
         da = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::DA>(tag.group_id, tag.element_id, len, da);
         break;
      }
      case VR::DS: {
         std::string ds;
         ds = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::DS>(tag.group_id, tag.element_id, len, ds);
         break;
      }
      case VR::DT: {
         std::string dt;
         dt = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::DT>(tag.group_id, tag.element_id, len, dt);
         break;
      }
      case VR::FL: {
         float fl;
         convhelper::little_endian_to_float(data, begin, len, fl);
         return make_elementfield<VR::FL>(tag.group_id, tag.element_id, len, fl);
         break;
      }
      case VR::FD: {
         double fd;
         convhelper::little_endian_to_float(data, begin, len, fd);
         return make_elementfield<VR::FD>(tag.group_id, tag.element_id, len, fd);
         break;
      }
      case VR::IS: {
         std::string is;
         is = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::IS>(tag.group_id, tag.element_id, len, is);
         break;
      }
      case VR::LO: {
         std::string lo;
         lo = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::LO>(tag.group_id, tag.element_id, len, lo);
         break;
      }
      case VR::LT: {
         std::string lt;
         lt = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::LT>(tag.group_id, tag.element_id, len, lt);
      }
      case VR::OB: { /** @todo: */
         break;
      }
      case VR::OD: {
         std::string od;
         od = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::OD>(tag.group_id, tag.element_id, len, od);
      }
      case VR::OF: {
         std::string of;
         of = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::OF>(tag.group_id, tag.element_id, len, of);
      }
      case VR::OW: { /** @todo: */
         break;
      }
      case VR::PN: {
         std::string pn;
         pn = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::OF>(tag.group_id, tag.element_id, len, pn);
      }
      case VR::SH: {
         std::string sh;
         sh = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::OF>(tag.group_id, tag.element_id, len, sh);
      }
      case VR::SL: {
         long val;
         convhelper::little_endian_to_integral(data, begin, 4, val);
         return make_elementfield<VR::SL>(tag.group_id, tag.element_id, len, val);
      }
      case VR::SQ: {
//         std::set<elementfield> nestedset;
//         convhelper::little_endian_to_integral(data, begin, 2, val);
//         return make_elementfield<VR::SL>(tag.group_id, tag.element_id, len, val);
      }
      case VR::SS: {
         short val;
         convhelper::little_endian_to_integral(data, begin, 2, val);
         return make_elementfield<VR::SS>(tag.group_id, tag.element_id, len, val);
      }
      case VR::ST: {
         std::string st;
         st = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::ST>(tag.group_id, tag.element_id, len, st);
      }
      case VR::TM: {
         std::string tm;
         tm = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::TM>(tag.group_id, tag.element_id, len, tm);
      }
      case VR::UL: {
         unsigned long val;
         convhelper::little_endian_to_integral(data, begin, 4, val);
         return make_elementfield<VR::UL>(tag.group_id, tag.element_id, len, val);
      }
      case VR::UI: {
         std::string ui;
         ui = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::UI>(tag.group_id, tag.element_id, len, ui);
      }
      case VR::UR: {
         std::string ur;
         ur = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::UR>(tag.group_id, tag.element_id, len, ur);
      }
      case VR::US: {
         unsigned short val;
         convhelper::little_endian_to_integral(data, begin, 2, val);
         return make_elementfield<VR::US>(tag.group_id, tag.element_id, len, val);
      }
      case VR::UT: {
         std::string ut;
         ut = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::UT>(tag.group_id, tag.element_id, len, ut);
      }
      default:
         assert(false);
         break;
   }

}
