#include "catch.hpp"

#include <string>
#include <exception>

#include "libdicompp/dicomdata.hpp"

using namespace dicom::data;
using namespace dicom::data::attribute;

SCENARIO("Validation of attributes", "[attributes]")
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

   GIVEN("An attribute value field of VR CS")
   {
      vmtype<std::string> field;
      constexpr VR repr = VR::CS;

      WHEN("The attribute value is odd")
      {
         field.insert({"TEST3"});
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
         field.insert({"TEST"});
         REQUIRE(field.byte_size() % 2 == 0);

         THEN("The field is not padded")
         {
            auto len = validate<repr>(field);
            REQUIRE(len % 2 == 0);
            REQUIRE(field.byte_size() % 2 == 0);
            REQUIRE(field.back()[len-1] == 'T');
         }
      }
      AND_WHEN("The value contains lowercase characters")
      {
         field.insert({"teSt"});

         THEN("All characters are transformed to uppercase")
         {
            auto len = validate<repr>(field);
            REQUIRE(len % 2 == 0);
            std::string val = field.back();
            bool all_upper = std::all_of(val.begin(), val.end(), [](char c) { return std::isupper(c); });
            REQUIRE(all_upper);
         }
      }
      AND_WHEN("The attribute value exceeds 16 bytes")
      {
         std::string str(17, 'Q');

         field.insert({str});
         REQUIRE(field.byte_size() > 16);

         THEN("Only the first 16 bytes taken")
         {
            validate<repr>(field);
            REQUIRE(field.byte_size() == 16);
            REQUIRE(str.substr(0, 16) == *field.begin());
         }
      }
      AND_WHEN("The string contains disallowed characters")
      {
         std::string str = "5_ -tE)ST$";
         field.insert({str.data()});

         THEN("Disallowed characters are stripped")
         {
            validate<repr>(field);
            REQUIRE(field.byte_size() % 2 == 0);
            REQUIRE(*field.begin() == "5_ TEST ");
         }
      }
      // TODO: leading spaces are insignificant
   }

   GIVEN("An attribute value field of VR DS")
   {
      vmtype<std::string> field;
      constexpr VR repr = VR::DS;

      WHEN("The attribute value is odd")
      {
         field.insert({"9"});
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
         field.insert({"23"});
         REQUIRE(field.byte_size() % 2 == 0);

         THEN("The field is padded with a space")
         {
            auto len = validate<repr>(field);
            REQUIRE(len % 2 == 0);
            REQUIRE(field.byte_size() % 2 == 0);
         }
      }
      AND_WHEN("The attribute value contains invalid characters")
      {
         field.insert({"q-p2.3ef9"});

         THEN("Invalid characters are stripped")
         {
            auto len = validate<repr>(field);
            REQUIRE(len % 2 == 0);
            REQUIRE(*field.begin() == "-2.3e9");
         }
      }
      AND_WHEN("The attribute value exceeds 16 characters")
      {
         std::string str(18, '8');

         field.insert({str});
         REQUIRE(field.byte_size() > 16);

         THEN("Only the first 12 characters are taken")
         {
            validate<repr>(field);
            REQUIRE(field.byte_size() == 16);
            REQUIRE(str.substr(0, 16) == *field.begin());
         }
      }
      // TODO +/- combined, leading spaces,
   }

   GIVEN("An attribute value field of VR IS")
   {
      vmtype<std::string> field;
      constexpr VR repr = VR::IS;

      WHEN("The attribute value is odd")
      {
         field.insert({"9"});
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
         field.insert({"23"});
         REQUIRE(field.byte_size() % 2 == 0);

         THEN("The field is padded with a space")
         {
            auto len = validate<repr>(field);
            REQUIRE(len % 2 == 0);
            REQUIRE(field.byte_size() % 2 == 0);
         }
      }
      AND_WHEN("The attribute value contains invalid characters")
      {
         field.insert({"-p23ef9"});

         THEN("Invalid characters are stripped")
         {
            auto len = validate<repr>(field);
            REQUIRE(len % 2 == 0);
            REQUIRE(*field.begin() == "-239");
         }
      }
      AND_WHEN("The attribute value exceeds 12 characters")
      {
         std::string str(14, '3');

         field.insert({str});
         REQUIRE(field.byte_size() > 12);

         THEN("Only the first 12 characters are taken")
         {
            validate<repr>(field);
            REQUIRE(field.byte_size() == 12);
            REQUIRE(str.substr(0, 12) == *field.begin());
         }
      }
      // TODO +/- combined, leading spaces,
   }

   GIVEN("An attribute value field of VR LO")
   {
      vmtype<std::string> field;
      constexpr VR repr = VR::LO;

      WHEN("The attribute value is odd")
      {
         field.insert({"qrt"});
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
         field.insert({"4567"});
         REQUIRE(field.byte_size() % 2 == 0);

         THEN("The field is padded with a space")
         {
            auto len = validate<repr>(field);
            REQUIRE(len % 2 == 0);
            REQUIRE(field.byte_size() % 2 == 0);
         }
      }
      AND_WHEN("The value contains a utf8 sequence")
      {
         field.insert({"!*tt43 😍test üß"});

         THEN("The value is not modified")
         {
            validate<repr>(field);
            REQUIRE(field.back() == "!*tt43 😍test üß");
         }
      }
      AND_WHEN("The attribute value contains invalid characters")
      {
         std::vector<char> bytes {'t', 't', 0x0d, 0x1b, '4', '4', '4', 'w', 0x0c, ' '};
         std::string text(bytes.begin(), bytes.end());
         field.insert({text});

         THEN("Invalid characters are stripped")
         {
            auto len = validate<repr>(field);
            REQUIRE(len % 2 == 0);
            std::vector<char> val_bytes(std::begin(field.back()), std::end(field.back()));
            std::vector<char> exp_bytes {'t', 't', 0x1b, '4', '4', '4', 'w', ' '};
            REQUIRE(val_bytes == exp_bytes);
         }
      }
      AND_WHEN("The attribute value exceeds 64 characters")
      {
         std::string str(65, 'p');

         field.insert({str});
         REQUIRE(field.byte_size() > 64);

         THEN("Only the first 64 characters are taken")
         {
            validate<repr>(field);
            REQUIRE(field.byte_size() == 64);
            REQUIRE(str.substr(0, 64) == *field.begin());
         }
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

   GIVEN("An attribute value field of VR UT")
   {
      std::string field;
      constexpr VR repr = VR::UT;

      WHEN("The attribute value is odd")
      {
         field = "testt";
         REQUIRE(field.size() % 2 == 1);

         THEN("The field is padded with a space")
         {
            auto len = validate<repr>(field);
            REQUIRE(len % 2 == 0);
            REQUIRE(field.size() % 2 == 0);
            REQUIRE(field[len-1] == ' ');
         }
      }
      AND_WHEN("The attribute value is even")
      {
         field = "testtext";
         REQUIRE(field.size() % 2 == 0);

         THEN("The field is not padded")
         {
            auto len = validate<repr>(field);
            REQUIRE(len % 2 == 0);
            REQUIRE(field.size() % 2 == 0);
            REQUIRE(field[len-1] == 't');
         }
      }
      AND_WHEN("The value contains a backslash \\")
      {
         field = "textwith\\backslash";

         THEN("The backslash is kept")
         {
            validate<repr>(field);
            REQUIRE(field == "textwith\\backslash");
         }
      }
      AND_WHEN("The value contains a utf8 sequence")
      {
         field = "*tt43 😍test üü";

         THEN("The value is not modified")
         {
            validate<repr>(field);
            REQUIRE(field == "*tt43 😍test üü ");
         }
      }
   }
}
