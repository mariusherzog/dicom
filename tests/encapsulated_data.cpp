#include "catch.hpp"

#include <string>
#include <exception>

#include "libdicompp/dicomdata.hpp"

using namespace dicom::data;
using namespace dicom::data::attribute;

SCENARIO("Adding and removing fragments and compressed frames to an encapsulated object", "[types]")
{
   GIVEN("An encapsulated object without compressed frame information")
   {
      encapsulated data(encapsulated::OFFSET_TABLE_INFO::FRAGMENTS);

      REQUIRE(!data.have_compressed_frame_info());

      auto fragment_count = data.fragment_count();
      REQUIRE(fragment_count == 0);

      WHEN("A fragment is added")
      {
         std::vector<unsigned char> fragment {0x65, 0x32, 0xf2};
         data.push_fragment(fragment);

         THEN("The fragment count increases by one")
         {
            REQUIRE(fragment_count + 1 == data.fragment_count());
         }
      }
      AND_WHEN("The fragment is retrieved")
      {
         std::vector<unsigned char> fragment {0x65, 0x32, 0xf2};
         data.push_fragment(fragment);
         auto fragment_retrieved = data.get_fragment(0);

         THEN("The fragment is equal to the pushed fragment")
         {
            REQUIRE(fragment == fragment_retrieved);
         }
      }
      WHEN("It is attempted to retrieve compressed frame info")
      {
         std::vector<unsigned char> fragment;
         data.push_fragment(fragment);

         THEN("An exception is thrown")
         {
            REQUIRE_THROWS(data.marks_frame_start(0));
         }
      }
   }

   GIVEN("An encapsulated object with compressed frame information")
   {
      encapsulated data(encapsulated::OFFSET_TABLE_INFO::COMPRESSED_FRAMES);

      REQUIRE(data.have_compressed_frame_info());

      auto fragment_count = data.fragment_count();
      REQUIRE(fragment_count == 0);

      WHEN("A fragment is added")
      {
         std::vector<unsigned char> fragment {0x65, 0x32, 0xf2};
         data.push_fragment(fragment);

         THEN("The fragment count increases by one")
         {
            REQUIRE(fragment_count + 1 == data.fragment_count());
         }
      }
      AND_WHEN("The fragment is retrieved")
      {
         std::vector<unsigned char> fragment {0x65, 0x32, 0xf2};
         data.push_fragment(fragment);
         auto fragment_retrieved = data.get_fragment(0);

         THEN("The fragment is equal to the pushed fragment")
         {
            REQUIRE(fragment == fragment_retrieved);
         }
      }
   }

   GIVEN("An encapsulated object with multiple fragments")
   {
      encapsulated data(encapsulated::OFFSET_TABLE_INFO::COMPRESSED_FRAMES);

      REQUIRE(data.have_compressed_frame_info());

      auto fragment_count = data.fragment_count();
      std::vector<unsigned char> fragment1 {0x65, 0x32, 0xf2};
      std::vector<unsigned char> fragment2 {0xc0};
      std::vector<unsigned char> fragment3 {0x65, 0x32, 0xba, 0x27, 0x99};
      std::vector<unsigned char> fragment4 {};
      data.push_fragment(fragment1);
      data.push_fragment(fragment2);
      data.push_fragment(fragment3);
      data.push_fragment(fragment4);
      REQUIRE(data.fragment_count() == 4);

      WHEN("The last fragment is marked to start a compressed frame")
      {
         data.mark_compressed_frame_start();

         THEN("The next fragment marks the start of a compressed frame")
         {
            REQUIRE(data.marks_frame_start(4));
         }
         AND_THEN("Another fragment does not mark the start of a compressed frame")
         {
            REQUIRE(!data.marks_frame_start(0));
         }
      }

   }
}
