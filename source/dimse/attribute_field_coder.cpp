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
   for (std::size_t i=begin; i<begin+len; ++i) {
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
//         boost::gregorian::date date;
//         std::vector<char> datestr(6);
//         get_value_field<VR::DA>(attr, date);
//         std::sprintf(datestr.data(), "%d%d%d"
//                      , static_cast<short>(date.month())
//                      , static_cast<short>(date.day())
//                      , static_cast<short>(date.year()));
//         std::string datestr2(datestr.begin(), datestr.end());
//         data = convhelper::decode_byte_string(datestr2);
//         break;
      }
      case VR::DS: {
         std::string ds;
         get_value_field<VR::DS>(attr, ds);
         data = convhelper::decode_byte_string(ds);
         break;
      }
      case VR::DT: { /** @todo */
//         boost::local_time::local_date_time datetime;
//         std::vector<char> datestr(26);
//         get_value_field<VR::DT>(attr, datetime);
//         std::sprintf(datestr.data(), "%d%d%d%d%d%d."
//                      , static_cast<short>(datetime.month())
//                      , static_cast<short>(datetime.day())
//                      , static_cast<short>(datetime.year())
//                      , static_cast<short>(datetime.)
//                      );
//         std::string datestr2(datestr.begin(), datestr.end());
//         data = convhelper::decode_byte_string(datestr2);
//         break;
      }
      case VR::LO: {
         std::string lo;
         get_value_field<VR::LO>(attr, lo);
         data = convhelper::decode_byte_string(lo);
         break;
      }
      case VR::UL: {
         unsigned int field;
         get_value_field<VR::UL>(attr, field);
         data = convhelper::integral_to_little_endian(field, 4);
         break;
      }
      case VR::UI: {
         std::string ui;
         get_value_field<VR::UI>(attr, ui);
         data = convhelper::decode_byte_string(ui);
         break;
      }
      case VR::US: {
         unsigned short field;
         get_value_field<VR::US>(attr, field);
         data = convhelper::integral_to_little_endian(field, 2);
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
//         boost::gregorian::date date;
//         std::vector<char> datestr(6);
//         get_value_field<VR::DA>(attr, date);
//         std::sprintf(datestr.data(), "%d%d%d"
//                      , static_cast<short>(date.month())
//                      , static_cast<short>(date.day())
//                      , static_cast<short>(date.year()));
//         std::string datestr2(datestr.begin(), datestr.end());
//         data = convhelper::decode_byte_string(datestr2);
//         break;
      }
      case VR::DS: {
         std::string ds;
         ds = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::DS>(tag.group_id, tag.element_id, len, ds);
         break;
      }
      case VR::DT: { /** @todo */
//         boost::local_time::local_date_time datetime;
//         std::vector<char> datestr(26);
//         get_value_field<VR::DT>(attr, datetime);
//         std::sprintf(datestr.data(), "%d%d%d%d%d%d."
//                      , static_cast<short>(datetime.month())
//                      , static_cast<short>(datetime.day())
//                      , static_cast<short>(datetime.year())
//                      , static_cast<short>(datetime.)
//                      );
//         std::string datestr2(datestr.begin(), datestr.end());
//         data = convhelper::decode_byte_string(datestr2);
//         break;
      }
      case VR::LO: {
         std::string lo;
         lo = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::CS>(tag.group_id, tag.element_id, len, lo);
      }
      case VR::UL: {
         unsigned int val;
         convhelper::little_endian_to_integral(data, begin, 4, val);
         return make_elementfield<VR::UL>(tag.group_id, tag.element_id, len, val);
      }
      case VR::UI: {
         std::string ui;
         ui = convhelper::encode_byte_string(data, begin, len);
         return make_elementfield<VR::UI>(tag.group_id, tag.element_id, len, ui);
      }
      case VR::US: {
         unsigned short val;
         convhelper::little_endian_to_integral(data, begin, 2, val);
         return make_elementfield<VR::US>(tag.group_id, tag.element_id, len, val);
      }
      default:
         break;
   }

}
