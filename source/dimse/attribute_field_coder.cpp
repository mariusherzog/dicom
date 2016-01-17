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

static std::vector<unsigned char> encode_byte_string(std::string str)
{
   std::vector<unsigned char> buf(str.size());
   for (int i=0; i<str.size(); ++i) {
      buf[i] = static_cast<unsigned char>(str[i]);
   }
   return buf;
}

}


std::vector<unsigned char> decode_little_endian(elementfield attr, const VR vr)
{
   std::vector<unsigned char> data;
   switch (vr) {
      case VR::AE: {
         std::string ae;
         get_value_field<VR::AE>(attr, ae);
         data = convhelper::encode_byte_string(ae);
         break;
      }
      case VR::AS: {
         std::string as;
         get_value_field<VR::AS>(attr, as);
         data = convhelper::encode_byte_string(as);
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
         data = convhelper::encode_byte_string(cs);
         break;
      }
      case VR::DA: {
         boost::gregorian::date date;
         std::vector<char> datestr(6);
         get_value_field<VR::DA>(attr, date);
         std::sprintf(datestr.data(), "%d%d%d"
                      , static_cast<short>(date.month())
                      , static_cast<short>(date.day())
                      , static_cast<short>(date.year()));
         std::string datestr2(datestr.begin(), datestr.end());
         data = convhelper::encode_byte_string(datestr2);
         break;
      }
      case VR::DS: {
         std::string ds;
         get_value_field<VR::DS>(attr, ds);
         data = convhelper::encode_byte_string(ds);
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
//         data = convhelper::encode_byte_string(datestr2);
//         break;
      }
      case VR::LO: {
         std::string lo;
         get_value_field<VR::LO>(attr, lo);
         data = convhelper::encode_byte_string(lo);
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
         data = convhelper::encode_byte_string(ui);
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


std::vector<unsigned char> decode_tag_little_endian(elementfield::tag_type tag)
{
   std::vector<unsigned char> data;
   auto group_le = convhelper::integral_to_little_endian(tag.group_id, 2);
   auto elem_le = convhelper::integral_to_little_endian(tag.element_id, 2);
   data.insert(data.begin(), elem_le.begin(), elem_le.end());
   data.insert(data.begin(), group_le.begin(), group_le.end());
   return data;
}


std::vector<unsigned char> decode_len_little_endian(std::size_t len)
{
   return convhelper::integral_to_little_endian(len, 2);
}
