#include "catch.hpp"

#include <string>
#include <exception>
#include <vector>

#include "../source/data/attribute/attribute.hpp"
#include "../source/data/attribute/vmtype.hpp"
#include "../source/data/attribute/attribute_field_coder.hpp"

using namespace dicom::data;
using namespace dicom::data::attribute;

SCENARIO("Serialization of an individual attribute", "[attributes][transfer_processor]")
{
   GIVEN("A dicom tag instance")
   {
      tag_type tag {0x7fe0, 0x0010};

      WHEN("The tag is serialized in little-endian")
      {
         auto data = encode_tag(tag, ENDIANNESS::LITTLE);
         THEN("The data is correctly serialized")
         {
            auto expected = std::vector<unsigned char> {0xe0, 0x7f, 0x10, 0x00};
            REQUIRE(data == expected);
         }
      }
      AND_WHEN("The tag is serialized in big-endian")
      {
         auto data = encode_tag(tag, ENDIANNESS::BIG);
         THEN("The data is correctly serialized")
         {
            auto expected = std::vector<unsigned char> {0x7f, 0xe0, 0x00, 0x10};
            REQUIRE(data == expected);
         }
      }
   }

   GIVEN("A dicom length field")
   {
      std::size_t length = 0x23c13f0a;

      WHEN("The length is serialized in little-endian")
      {
         auto length_data = encode_len(4, length, ENDIANNESS::LITTLE);
         THEN("The length is correctly serialized")
         {
            auto expected = std::vector<unsigned char> {0x0a, 0x3f, 0xc1, 0x23};
            REQUIRE(length_data == expected);
         }
      }
      AND_WHEN("The length is serialized in big-endian")
      {
         auto length_data = encode_len(4, length, ENDIANNESS::BIG);
         THEN("The length is correctly serialized")
         {
            auto expected = std::vector<unsigned char> {0x23, 0xc1, 0x3f, 0x0a};
            REQUIRE(length_data == expected);
         }
      }
   }

   // covers everything string related
   GIVEN("A dicom value field of VR CS")
   {
      auto value = make_elementfield<VR::CS>("ST_SCP");

      WHEN("The value is serialized in little-endian")
      {
         auto value_data = encode_value_field(value, ENDIANNESS::LITTLE, VR::CS);
         THEN("The value is correctly serialized")
         {
            auto expected = std::vector<unsigned char> {'S', 'T', '_', 'S', 'C', 'P'};
            REQUIRE(value_data == expected);
         }
      }
      AND_WHEN("The value is serialized in big-endian")
      {
         auto value_data = encode_value_field(value, ENDIANNESS::BIG, VR::CS);
         THEN("The value is correctly serialized")
         {
            auto expected = std::vector<unsigned char> {'S', 'T', '_', 'S', 'C', 'P'};
            REQUIRE(value_data == expected);
         }
      }
   }

   GIVEN("A dicom value field of VR IS")
   {
      vmtype<std::string> intvalues {{"*"}, {"2", "4711"}};
      auto value = make_elementfield<VR::IS>(intvalues);
      std::vector<unsigned char> expected {'2', '\\', '4', '7', '1', '1'};

      WHEN("The value is serialized in little-endian")
      {
         auto value_data = encode_value_field(value, ENDIANNESS::LITTLE, VR::IS);
         THEN("The value is correctly serialized")
         {
           REQUIRE(value_data == expected);
         }
      }
      AND_WHEN("The value is serialized in big-endian")
      {
         auto value_data = encode_value_field(value, ENDIANNESS::BIG, VR::IS);
         THEN("The value is correctly serialized")
         {
           REQUIRE(value_data == expected);
         }
      }
   }

   // covers all (de)serialization for floating points
   GIVEN("A dicom value field of VR FL")
   {
      vmtype<float> floatvalues {{"*"}, {1.0, 0.125}};
      auto value = make_elementfield<VR::FL>(floatvalues);

      WHEN("The value is serialized in little-endian")
      {
         auto value_data = encode_value_field(value, ENDIANNESS::LITTLE, VR::FL);
         THEN("The value is correctly serialized")
         {
           std::vector<unsigned char> expected {0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x3e};
           REQUIRE(value_data == expected);
         }
         AND_THEN("The size of the serialized data is count * sizeof(type)")
         {
            auto size = floatvalues.size() * 4;
            REQUIRE(size == value_data.size());
         }
      }
      AND_WHEN("The value is serialized in big-endian")
      {
         auto value_data = encode_value_field(value, ENDIANNESS::BIG, VR::FL);
         THEN("The value is correctly serialized")
         {
           std::vector<unsigned char> expected {0x3f, 0x80, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00};
           REQUIRE(value_data == expected);
         }
         AND_THEN("The size of the serialized data is count * sizeof(type)")
         {
            auto size = floatvalues.size() * 4;
            REQUIRE(size == value_data.size());
         }
      }
   }

   // covers (de)serialization of word sequence requiring byte swapping
   GIVEN("A dicom value field of VR OW")
   {
      auto value = make_elementfield<VR::OW>({0xffa0, 0x217c, 0xc143});

      WHEN("The value is serialized in little-endian")
      {
         auto value_data = encode_value_field(value, ENDIANNESS::LITTLE, VR::OW);
         THEN("The value is correctly serialized")
         {
            std::vector<unsigned char> expected {0xa0, 0xff, 0x7c, 0x21, 0x43, 0xc1};
            REQUIRE(value_data == expected);
         }
      }
      AND_WHEN("The value is serialized in big-endian")
      {
         auto value_data = encode_value_field(value, ENDIANNESS::BIG, VR::OW);
         THEN("The value is correctly serialized")
         {
            std::vector<unsigned char> expected {0xff, 0xa0, 0x21, 0x7c, 0xc1, 0x43};
            REQUIRE(value_data == expected);
         }
      }
   }

   GIVEN("A dicom value field of VR OF")
   {
      auto value = make_elementfield<VR::OF>({2.0, -10});

      WHEN("The value is serialized in little-endian")
      {
         auto value_data = encode_value_field(value, ENDIANNESS::LITTLE, VR::OF);
         THEN("The value is correctly serialized")
         {
            std::vector<unsigned char> expected {0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x20, 0xc1};
            REQUIRE(value_data == expected);
         }
      }
      AND_WHEN("The value is serialized in big-endian")
      {
         auto value_data = encode_value_field(value, ENDIANNESS::BIG, VR::OF);
         THEN("The value is correctly serialized")
         {
            std::vector<unsigned char> expected {0x40, 0x00, 0x00, 0x00, 0xc1, 0x20, 0x00, 0x00};
            REQUIRE(value_data == expected);
         }
      }
   }
}


SCENARIO("Deserialization of an individual attribute", "[attributes][transfer_processor]")
{
   GIVEN("A serialized dicom tag")
   {
      std::vector<unsigned char> data {0x08, 0x00, 0x60, 0x00};

      WHEN("The tag is deserialized in little-endian")
      {
         auto tag = decode_tag(data, 0, ENDIANNESS::LITTLE);
         THEN("The data is correctly deserialized")
         {
            tag_type expected {0x0008, 0x0060};
            REQUIRE(expected == tag);
         }
      }
      AND_WHEN("The tag is deserialized in big-endian")
      {
         auto tag = decode_tag(data, 0, ENDIANNESS::BIG);
         THEN("The data is correctly deserialized")
         {
            tag_type expected {0x0800, 0x6000};
            REQUIRE(expected == tag);
         }
      }
   }

   GIVEN("A serialized length field")
   {
      std::vector<unsigned char> length_bytes {0xfa, 0x20, 0x78, 0xcf};

      WHEN("The length is deserialized in little-endian")
      {
         auto length = decode_len(length_bytes, ENDIANNESS::LITTLE, 4, 0);
         THEN("The length is correctly deserialized")
         {
            auto expected = 0xcf7820fa;
            REQUIRE(length == expected);
         }
      }
      AND_WHEN("The length is deserialized in big-endian")
      {
         auto length = decode_len(length_bytes, ENDIANNESS::BIG, 4, 0);
         THEN("The length is correctly deserialized")
         {
            auto expected = 0xfa2078cf;
            REQUIRE(length == expected);
         }
      }
   }

   GIVEN("A serialized dicom value field of VR CS")
   {
      auto value_bytes = std::vector<unsigned char> {'Q', 'R', 'S', 'C', 'U', '1'};

      WHEN("The value is deserialized in little-endian")
      {
         auto value = decode_value_field(value_bytes, ENDIANNESS::LITTLE, value_bytes.size(), VR::CS, "1", 0);
         THEN("The value is correctly deserialized")
         {
            std::string value_string;
            get_value_field<VR::CS>(value, value_string);
            REQUIRE(value_string == "QRSCU1");
         }
      }
      WHEN("The value is deserialized in big-endian")
      {
         auto value = decode_value_field(value_bytes, ENDIANNESS::BIG, value_bytes.size(), VR::CS, "1", 0);
         THEN("The value is correctly deserialized")
         {
            std::string value_string;
            get_value_field<VR::CS>(value, value_string);
            REQUIRE(value_string == "QRSCU1");
         }
      }
   }

   GIVEN("A serialized dicom value field of VR IS")
   {
      auto value_bytes = std::vector<unsigned char> {'9', '1', '\\', '8', '7', '\\', '1', ' '};

      WHEN("The value is deserialized in little-endian")
      {
         auto value = decode_value_field(value_bytes, ENDIANNESS::LITTLE, value_bytes.size(), VR::IS, "3", 0);
         THEN("The value is correctly deserialized")
         {
            vmtype<std::string> int_values;
            get_value_field<VR::IS>(value, int_values);
            REQUIRE(*int_values.begin() == "91");
            REQUIRE(*(int_values.begin()+1) == "87");
            REQUIRE(int_values.back() == "1 ");
         }
      }
      WHEN("The value is deserialized in big-endian")
      {
         auto value = decode_value_field(value_bytes, ENDIANNESS::LITTLE, value_bytes.size(), VR::IS, "3", 0);
         THEN("The value is correctly deserialized")
         {
            vmtype<std::string> int_values;
            get_value_field<VR::IS>(value, int_values);
            REQUIRE(*int_values.begin() == "91");
            REQUIRE(*(int_values.begin()+1) == "87");
            REQUIRE(int_values.back() == "1 ");
         }
      }
   }

   GIVEN("A serialized dicom value field of VR FL")
   {
      std::vector<unsigned char> float_bytes_le {0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x3e};
      std::vector<unsigned char> float_bytes_be {0x3f, 0x80, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00};

      WHEN("The value is deserialized in little-endian")
      {
         auto value = decode_value_field(float_bytes_le, ENDIANNESS::LITTLE, float_bytes_le.size(), VR::FL, "*", 0);
         THEN("The value is correctly deserialized")
         {
            vmtype<float> float_values;
            get_value_field<VR::FL>(value, float_values);
            float a = *float_values.begin();
            float b = float_values.back();
            REQUIRE(a == 1.0);
            REQUIRE(b == 0.125);
         }
      }
      AND_WHEN("The value is deserialized in big-endian")
      {
         auto value = decode_value_field(float_bytes_be, ENDIANNESS::BIG, float_bytes_be.size(), VR::FL, "*", 0);
         THEN("The value is correctly deserialized")
         {
            vmtype<float> float_values;
            get_value_field<VR::FL>(value, float_values);
            float a = *float_values.begin();
            float b = float_values.back();
            REQUIRE(a == 1.0);
            REQUIRE(b == 0.125);
         }
      }
   }

   GIVEN("A serialized dicom value field of VR OW")
   {
      std::vector<unsigned char> ow_bytes {0xa0, 0xff, 0x7c, 0x21, 0x43, 0xc1};

      WHEN("The value is deserialized in little-endian")
      {
         auto value = decode_value_field(ow_bytes, ENDIANNESS::LITTLE, ow_bytes.size(), VR::OW, "*", 0);
         std::vector<unsigned short> expected {0xffa0, 0x217c, 0xc143};

         THEN("The value is correctly deserialized")
         {
            std::vector<unsigned short> ow;
            get_value_field<VR::OW>(value, ow);
            REQUIRE(ow == expected);
         }

      }
      AND_WHEN("The value is deserialized in big-endian")
      {
         auto value = decode_value_field(ow_bytes, ENDIANNESS::BIG, ow_bytes.size(), VR::OW, "*", 0);
         std::vector<unsigned short> expected {0xa0ff, 0x7c21, 0x43c1};

         THEN("The value is correctly deserialized")
         {
            std::vector<unsigned short> ow;
            get_value_field<VR::OW>(value, ow);
            REQUIRE(ow == expected);
         }
      }
   }

   GIVEN("A serialized dicom value field of VR OF")
   {
      std::vector<unsigned char> of_bytes_le {0xcd, 0xcc, 0x4c, 0xc0, 0x00, 0x00, 0x20, 0xc1};
      std::vector<unsigned char> of_bytes_be {0xc0, 0x4c, 0xcc, 0xcd, 0xc1, 0x20, 0x00, 0x00};

      WHEN("The value is deserialized in little-endian")
      {
         //0xc04ccccd
         auto value = decode_value_field(of_bytes_le, ENDIANNESS::LITTLE, of_bytes_le.size(), VR::OF, "1", 0);
         std::vector<float> expected {-3.2, -10};

         THEN("The value is correctly deserialized")
         {
            std::vector<float> of;
            get_value_field<VR::OF>(value, of);
            REQUIRE(of == expected);
         }

      }
      AND_WHEN("The value is deserialized in big-endian")
      {
         auto value = decode_value_field(of_bytes_be, ENDIANNESS::BIG, of_bytes_be.size(), VR::OF, "1", 0);
         std::vector<float> expected {-3.2, -10};

         THEN("The value is correctly deserialized")
         {
            std::vector<float> of;
            get_value_field<VR::OF>(value, of);
            REQUIRE(of == expected);
         }
      }
   }
}


