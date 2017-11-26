#include "catch.hpp"

#include <string>
#include <exception>
#include <vector>

#include "../source/data/dataset/datasets.hpp"
#include "../source/data/attribute/tag.hpp"
#include "../source/data/attribute/attribute.hpp"
#include "../source/data/dataset/transfer_processor.hpp"
#include "../source/data/dictionary/dictionary.hpp"

using namespace dicom::data::attribute;
using namespace dicom::data;
using namespace dicom::data::dataset;


SCENARIO("Serialization of a dataset with little-endian implicit transfer syntax", "[dataset][transfer_processor]")
{
   auto& dictionaries = dicom::data::dictionary::get_default_dictionaries(); // use dictionary stub
   little_endian_implicit lei_tp {dictionaries};

   REQUIRE(lei_tp.get_transfer_syntax() == "1.2.840.10008.1.2");

   GIVEN("A dataset containing a single attribute")
   {
      std::vector<unsigned char> expected =
      {/*tag*/ 0x08, 0x00, 0x18, 0x00,
       /*length*/ 0x04, 0x00, 0x00, 0x00,
       /*data*/ '1', '.', '2', '0'};

      iod dataset;
      dataset[{0x0008, 0x0018}] = make_elementfield<VR::UI>(4, "1.20");
      WHEN("The dataset is deserialized")
      {
         std::vector<unsigned char> bytes = lei_tp.serialize(dataset);
         THEN("The attribute is deserialized as expected")
         {
            REQUIRE(bytes == expected);
         }
      }
      AND_WHEN("The length of a complete attribute is queried")
      {
         auto length = lei_tp.dataelement_length(dataset[{0x0008, 0x0018}]);
         THEN("The byte length of the attribute is returned")
         {
            REQUIRE(length == expected.size());
         }
      }
   }
}

SCENARIO("Serialization of a dataset with little-endian explicit transfer syntax", "[dataset][transfer_processor]")
{
   auto& dictionaries = dicom::data::dictionary::get_default_dictionaries(); // use dictionary stub
   little_endian_explicit lee_tp {dictionaries};

   REQUIRE(lee_tp.get_transfer_syntax() == "1.2.840.10008.1.2.1");

   GIVEN("A dataset containing a single attribute with 'short' length")
   {
      std::vector<unsigned char> expected =
      {/*tag*/ 0x28, 0x00, 0x10, 0x00,
       /*vr*/ 'U', 'S',
       /*length*/ 0x02, 0x00,
       /*data*/ 10, 0x00};

      iod dataset;
      dataset[{0x0028, 0x0010}] = make_elementfield<VR::US>(10);
      WHEN("The dataset is deserialized")
      {
         std::vector<unsigned char> bytes = lee_tp.serialize(dataset);
         THEN("The attribute is deserialized as expected")
         {
            REQUIRE(bytes == expected);
         }
      }
      AND_WHEN("The length of a complete attribute is queried")
      {
         auto length = lee_tp.dataelement_length(dataset[{0x0028, 0x0010}]);
         THEN("The byte length of the attribute is returned")
         {
            REQUIRE(length == expected.size());
         }
      }
   }

   GIVEN("A dataset containing a single attribute with 'long' length")
   {
      std::vector<unsigned char> expected =
      {/*tag*/ 0xe0, 0x7f, 0x10, 0x00,
       /*vr*/'O', 'B',
       /*padding*/ 0x00, 0x00,
       /*length*/ 0x04, 0x00, 0x00, 0x00,
       /*data*/ 0xc4, 0x0e, 0x71, 0x33};

      iod dataset;
      dataset[{0x7fe0, 0x0010}] = make_elementfield<VR::OB>(4, {0xc4, 0x0e, 0x71, 0x33});
      WHEN("The attribute is deserialized")
      {
         std::vector<unsigned char> bytes = lee_tp.serialize(dataset);
         THEN("The attribute is deserialized as expected")
         {
            REQUIRE(bytes == expected);
         }
      }
      AND_WHEN("The length of a complete attribute is queried")
      {
         auto length = lee_tp.dataelement_length(dataset[{0x7fe0, 0x0010}]);
         THEN("The byte length of the attribute is returned")
         {
            REQUIRE(length == expected.size());
         }
      }
   }
}
