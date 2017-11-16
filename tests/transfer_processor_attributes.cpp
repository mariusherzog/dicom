#include "catch.hpp"

#include <string>
#include <exception>
#include <vector>

#include "../source/data/attribute/attribute.hpp"
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
      std::vector<unsigned char> length_bytes {0x0a, 0x20, 0x78, 0x7f};

      WHEN("The length is deserialized in little-endian")
      {
         auto length = decode_len(length_bytes, ENDIANNESS::LITTLE, 4, 0);
         THEN("The length is correctly deserialized")
         {
            auto expected = 0x7f78200a;
            REQUIRE(length == expected);
         }
      }
      AND_WHEN("The length is deserialized in big-endian")
      {
         auto length = decode_len(length_bytes, ENDIANNESS::BIG, 4, 0);
         THEN("The length is correctly deserialized")
         {
            auto expected = 0x0a20787f;
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
      WHEN("The value is deserialized in little-endian")
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
}


