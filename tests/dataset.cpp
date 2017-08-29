#include "catch.hpp"

#include <string>

#include "../source/data/dataset/datasets.hpp"
#include "../source/data/attribute/attribute.hpp"

using namespace dicom::data::dataset;
using namespace dicom::data::attribute;

SCENARIO("DICOM Attributes can be added and removed from datasets", "[dataset]")
{
   GIVEN("A dicom dataset without sequences")
   {
      iod data;

      REQUIRE(data.size() == 0);

      data[{0x0010, 0x1001}] = make_elementfield<VR::PN>("Test^One^Two^^");

      WHEN("A new element is added")
      {
         auto size_previous = data.size();
         data[{0x0008, 0x0090}] = make_elementfield<VR::PN>("Dr.^boog^boog");

         THEN("the size increases by one") 
         {
            REQUIRE(size_previous + 1 == data.size());
         }
         THEN("the element's value can be retrieved")
         {
            std::string value;
            get_value_field<VR::PN>(data[{0x0008, 0x0090}], value); 

            REQUIRE("Dr.^boog^boog " == value);
         }
      }

      WHEN("A element is added with a lower group id")
      {
         data[{0x0008, 0x0016}] = make_elementfield<VR::UI>("1.1.1.1.1");

         THEN("it is placed before the other element")
         {
            auto diff = std::distance(data.find({0x0008, 0x016}), data.find({0x0010, 0x1001}));
            REQUIRE(diff == 1);
         }
      }
      AND_WHEN("the group id is same, but element id is lower")
      {
         data[{0x0010,0x0010}] = make_elementfield<VR::PN>("Test^Test");

         THEN("it is placed before the other element")
         {
            auto diff = std::distance(data.find({0x0010, 0x0010}), data.find({0x0010, 0x1001}));
            REQUIRE(diff == 1);
         }
      }

      WHEN("An element is edded with a higher group id")
      {
         data[{0x0018, 0x1098}] = make_elementfield<VR::FD>(33.33);

         THEN("it is placed after the other element")
         {
            auto diff = std::distance(data.find({0x0010, 0x1001}), data.find({0x0018, 0x1098}));
            REQUIRE(diff == 1);
         }
      }
      AND_WHEN("the group id is same, but the element id is higher")
      {
         data[{0x0010, 0x2154}] = make_elementfield<VR::SH>("123456");

         THEN("it is placed after the existing element")
         {
            auto diff = std::distance(data.find({0x0010, 0x1001}), data.find({0x0010, 0x2154}));
            REQUIRE(diff == 1);
         }
      }

      WHEN("An element with tag item is inserted")
      {
         data[{0xfffe, 0xe000}] = make_elementfield<VR::NI>(0xffffffff, VR::NI);

         THEN("is is placed in the first position")
         {
            auto diff = std::distance(data.begin(), data.find({0xfffe, 0xe000}));
            REQUIRE(diff == 0);
         }
      }
   }
}


