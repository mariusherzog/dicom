#include "catch.hpp"

#include <string>
#include <exception>

#include "../source/data/attribute/attribute.hpp"
#include "../source/data/attribute/vmtype.hpp"

using namespace dicom::data;
using namespace dicom::data::attribute;

SCENARIO("Validation of attributes")
{
   GIVEN("An attribute value field of VR AE")
   {
      vmtype<std::string> field;
      constexpr VR repr = VR::AE;

      WHEN("The attribute value is odd")
      {
         field.insert({"test1"});
         REQUIRE(field.byte_size() % 2 == 1);

         THEN("The field is padded with a space")
         {
            auto len = validate<repr>(field);
            REQUIRE(len % 2 == 0);
            REQUIRE(field.byte_size() % 2 == 0);
            REQUIRE(field.back()[len-1] == ' ');
         }
      }
      AND_WHEN("The attribute value is even")
      {
         field.insert({"test"});
         REQUIRE(field.byte_size() % 2 == 0);

         THEN("The field i kept as-is")
         {
            auto len = validate<repr>(field);
            REQUIRE(len % 2 == 0);
            REQUIRE(field.byte_size() % 2 == 0);
            REQUIRE("test" == *field.begin());
         }
      }
      AND_WHEN("The attribute value exceeds 16 characters")
      {
         std::string str = "testonetwothreefoursixseveneight";
         field.insert({str});
         REQUIRE(field.byte_size() > 16);

         THEN("Only the first 16 characters are taken")
         {
            validate<repr>(field);
            REQUIRE(field.byte_size() == 16);
            REQUIRE(str.substr(0, 16) == *field.begin());
         }
      }
      AND_WHEN("The string contains disallowed characters")
      {
         std::vector<char> str {'h', 'e', 0x0a, 0x0c, 'l', 0x0d, 'l', 'o', 0x1b, 0x00};
         field.insert({str.data()});

         THEN("Disallowed characters are stripped")
         {
            validate<repr>(field);
            REQUIRE(field.byte_size() % 2 == 0);
            REQUIRE(*field.begin() == "hello ");
         }
      }
   }

   GIVEN("An attribute value field of VR AT")
   {
      vmtype<tag_type> field;
      constexpr VR repr = VR::AT;

      field.insert({tag_type {0x0010, 0x0010}});

      THEN("The value length is equal to 4")
      {
         auto len = validate<repr>(field);
         REQUIRE(len == 4);
      }
   }

   GIVEN("An attribute value field of VR UI")
   {
      vmtype<std::string> field;
      constexpr VR repr = VR::UI;

      WHEN("The attribute value is odd")
      {
         field.insert({"1.1.1"});
         REQUIRE(field.byte_size() % 2 == 1);

         THEN("The field is padded with null \\0")
         {
            auto len = validate<repr>(field);
            REQUIRE(len % 2 == 0);
            REQUIRE(field.byte_size() % 2 == 0);
            REQUIRE(field.back()[len-1] == 0);
         }
      }
      AND_WHEN("The attribute value is even")
      {
         field.insert({"3.1.22"});
         REQUIRE(field.byte_size() % 2 == 0);

         THEN("The field is not padded")
         {
            auto len = validate<repr>(field);
            REQUIRE(len % 2 == 0);
            REQUIRE(field.byte_size() % 2 == 0);
            REQUIRE(field.back()[len-1] == '2');
         }
      }
      AND_WHEN("The attribute value exceeds 64 characters")
      {
         std::string str = "";
         for (int i=0; i<80; ++i) str += std::to_string(i);

         field.insert({str});
         REQUIRE(field.byte_size() > 64);

         THEN("Only the first 64 characters are taken")
         {
            validate<repr>(field);
            REQUIRE(field.byte_size() == 64);
            REQUIRE(str.substr(0, 64) == *field.begin());
         }
      }
      AND_WHEN("The string contains disallowed characters")
      {
         std::string str = "1.test2.3.p34";
         field.insert({str.data()});

         THEN("Disallowed characters are stripped")
         {
            validate<repr>(field);
            REQUIRE(field.byte_size() % 2 == 0);
            REQUIRE(*field.begin() == "1.2.3.34");
         }
      }
   }
}
