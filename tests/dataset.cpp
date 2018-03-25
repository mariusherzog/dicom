#include "catch.hpp"

#include <string>
#include <stack>
#include <vector>

#include "libdicompp/dicomdata.hpp"

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

SCENARIO("Traversal of DICOM datasets", "[dataset]")
{
   GIVEN("An empty dataset")
   {
      iod data;

      REQUIRE(data.size() == 0);

      WHEN("The set is traversed")
      {
         bool called = false;
         traverse(data, [&called](tag_type, const elementfield&) mutable
         {
            called = true;
         });

         THEN("The handler is not called")
         {
            REQUIRE(!called);
         }
      }
   }

   GIVEN("A  dataset without sequences")
   {
      iod data;

      data[{0x0010, 0x1001}] = make_elementfield<VR::PN>("Test^One^Two^^");
      data[{0x0028, 0x0002}] = make_elementfield<VR::IS>("3");

      WHEN("The set is traversed")
      {
         std::stack<tag_type> values;
         traverse(data, [&values](tag_type tag, const elementfield&) mutable
         {
            values.push(tag);
         });

         THEN("The values are traversed in order")
         {
            std::stack<tag_type> expected;
            expected.push({0x0010, 0x1001});
            expected.push({0x0028, 0x0002});

            REQUIRE(expected == values);
         }
      }
   }

   GIVEN("A  dataset with a sequence")
   {
      iod data;

      iod dataset, seq1, seq2;
      seq1[{0xfffe, 0xe000}] = make_elementfield<VR::NI>();
      seq1[{0x0010, 0x0010}] = make_elementfield<VR::PN>("q^test");
      seq1[{0xfffe, 0xe00d}] = make_elementfield<VR::NI>(); // currently needed, remove later
      seq2[{0xfffe, 0xe000}] = make_elementfield<VR::NI>();
      seq2[{0x0010, 0x0010}] = make_elementfield<VR::PN>("r^test");
      seq2[{0xfffe, 0xe00d}] = make_elementfield<VR::NI>();
      dataset[{0x0040, 0x0275}] = make_elementfield<VR::SQ>(0, {seq1, seq2});

      WHEN("The set is traversed")
      {
         std::stack<tag_type> values;
         traverse(dataset, [&values](tag_type tag, const elementfield&) mutable
         {
            values.push(tag);
         });

         THEN("The values are traversed in order, stepping into sequences")
         {
            std::stack<tag_type> expected;
            expected.push({0x0040, 0x0275});
            expected.push({0xfffe, 0xe000});
            expected.push({0x0010, 0x0010});
            expected.push({0xfffe, 0xe00d});
            expected.push({0xfffe, 0xe000});
            expected.push({0x0010, 0x0010});
            expected.push({0xfffe, 0xe00d});

            REQUIRE(expected == values);
         }
      }
   }

   GIVEN("A  dataset with a nested sequence")
   {
      iod data;

      iod dataset, seq1, seq2;
      seq1[{0xfffe, 0xe000}] = make_elementfield<VR::NI>();
      seq1[{0x0010, 0x0010}] = make_elementfield<VR::PN>("q^test");
      seq1[{0xfffe, 0xe00d}] = make_elementfield<VR::NI>(); // currently needed, remove later
      seq2[{0xfffe, 0xe000}] = make_elementfield<VR::NI>();
      seq2[{0x0040, 0x0100}] = make_elementfield<VR::SQ>(0, {seq1});
      seq2[{0x0008, 0x0018}] = make_elementfield<VR::UI>("1.2.3");
      seq2[{0xfffe, 0xe00d}] = make_elementfield<VR::NI>();
      dataset[{0x0040, 0x0275}] = make_elementfield<VR::SQ>(0, {seq2});

      WHEN("The set is traversed")
      {
         std::vector<tag_type> values;
         traverse(dataset, [&values](tag_type tag, const elementfield&) mutable
         {
            values.push_back(tag);
         });

         THEN("The values are traversed in order, stepping into sequences")
         {
            std::vector<tag_type> expected;
            expected.push_back({0x0040, 0x0275});
            expected.push_back({0xfffe, 0xe000});
            expected.push_back({0x0008, 0x0018});
            expected.push_back({0x0040, 0x0100});
            expected.push_back({0xfffe, 0xe000});
            expected.push_back({0x0010, 0x0010});
            expected.push_back({0xfffe, 0xe00d});
            expected.push_back({0xfffe, 0xe00d});

            REQUIRE(expected == values);
         }
      }
   }
}

