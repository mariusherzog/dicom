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

   GIVEN("A dataset containing a sequence with two items")
   {
      iod dataset, seq1, seq2, seqdel;
      seq1[{0xfffe, 0xe000}] = make_elementfield<VR::NI>();
      seq1[{0x0010, 0x0010}] = make_elementfield<VR::PN>("q^test");
      seq1[{0xfffe, 0xe00d}] = make_elementfield<VR::NI>(); // currently needed, remove later
      seq2[{0xfffe, 0xe000}] = make_elementfield<VR::NI>();
      seq2[{0x0010, 0x0010}] = make_elementfield<VR::PN>("r^test");
      seq2[{0xfffe, 0xe00d}] = make_elementfield<VR::NI>();
      seqdel[{0xfffe, 0xe0dd}] = make_elementfield<VR::NI>();
      dataset[{0x0040, 0x0275}] = make_elementfield<VR::SQ>(0, {seq1, seq2, seqdel});

      WHEN("The dataset is serialized")
      {
         auto data = lei_tp.serialize(dataset);

         THEN("The data is serialized as expected")
         {
            REQUIRE(data.size() == 52);

            std::vector<unsigned char> expected
            {
                0x40,0x00,0x75,0x02,0x2c,0x00,0x00,0x00,0xfe,0xff,0x00,0xe0,0x0e,0x00,0x00,0x00
               ,0x10,0x00,0x10,0x00,0x06,0x00,0x00,0x00,0x71,0x5e,0x74,0x65,0x73,0x74,0xfe,0xff
               ,0x00,0xe0,0x0e,0x00,0x00,0x00,0x10,0x00,0x10,0x00,0x06,0x00,0x00,0x00,0x72,0x5e
               ,0x74,0x65,0x73,0x74
            };

            REQUIRE(data == expected);
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
      WHEN("The dataset is serialized")
      {
         std::vector<unsigned char> bytes = lee_tp.serialize(dataset);
         THEN("The attribute is serialized as expected")
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
      WHEN("The attribute is serialized")
      {
         std::vector<unsigned char> bytes = lee_tp.serialize(dataset);
         THEN("The attribute is serialized as expected")
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

   GIVEN("A dataset containing a sequence with two items")
   {
      iod dataset, seq1, seq2, seqdel;
      seq1[{0xfffe, 0xe000}] = make_elementfield<VR::NI>();
      seq1[{0x0010, 0x0010}] = make_elementfield<VR::PN>("q^test");
      seq1[{0xfffe, 0xe00d}] = make_elementfield<VR::NI>(); // currently needed, remove later
      seq2[{0xfffe, 0xe000}] = make_elementfield<VR::NI>();
      seq2[{0x0010, 0x0010}] = make_elementfield<VR::PN>("r^test");
      seq2[{0xfffe, 0xe00d}] = make_elementfield<VR::NI>();
      seqdel[{0xfffe, 0xe0dd}] = make_elementfield<VR::NI>();
      dataset[{0x0040, 0x0275}] = make_elementfield<VR::SQ>(0, {seq1, seq2, seqdel});

      WHEN("The dataset is serialized")
      {
         auto data = lee_tp.serialize(dataset);

         THEN("The data is deserialized as expected")
         {
            REQUIRE(data.size() == 56);

            std::vector<unsigned char> expected
            {
                0x40,0x00,0x75,0x02,'S','Q',0x00, 0x00,0x2c,0x00,0x00,0x00,0xfe,0xff,0x00,0xe0,0x0e,0x00,0x00,0x00
               ,0x10,0x00,0x10,0x00,'P','N',0x06,0x00,0x71,0x5e,0x74,0x65,0x73,0x74,0xfe,0xff
               ,0x00,0xe0,0x0e,0x00,0x00,0x00,0x10,0x00,0x10,0x00,'P','N',0x06,0x00,0x72,0x5e
               ,0x74,0x65,0x73,0x74
            };

            REQUIRE(data == expected);
         }
      }
   }
}

SCENARIO("Serialization of a dataset with big-endian explicit transfer syntax", "[dataset][transfer_processor]")
{
   auto& dictionaries = dicom::data::dictionary::get_default_dictionaries(); // use dictionary stub
   big_endian_explicit bee_tp {dictionaries};

   REQUIRE(bee_tp.get_transfer_syntax() == "1.2.840.10008.1.2.2");

   GIVEN("A dataset containing a single attribute with 'short' length")
   {
      std::vector<unsigned char> expected =
      {/*tag*/ 0x00, 0x28, 0x00, 0x10,
       /*vr*/ 'U', 'S',
       /*length*/ 0x00, 0x02,
       /*data*/ 0x00, 10};

      iod dataset;
      dataset[{0x0028, 0x0010}] = make_elementfield<VR::US>(10);
      WHEN("The dataset is serialized")
      {
         std::vector<unsigned char> bytes = bee_tp.serialize(dataset);
         THEN("The attribute is serialized as expected")
         {
            REQUIRE(bytes == expected);
         }
      }
      AND_WHEN("The length of a complete attribute is queried")
      {
         auto length = bee_tp.dataelement_length(dataset[{0x0028, 0x0010}]);
         THEN("The byte length of the attribute is returned")
         {
            REQUIRE(length == expected.size());
         }
      }
   }

   GIVEN("A dataset containing a single attribute with 'long' length")
   {
      std::vector<unsigned char> expected =
      {/*tag*/ 0x7f, 0xe0, 0x00, 0x10,
       /*vr*/'O', 'B',
       /*padding*/ 0x00, 0x00,
       /*length*/ 0x00, 0x00, 0x00, 0x04,
       /*data*/ 0xc4, 0x0e, 0x71, 0x33};

      iod dataset;
      dataset[{0x7fe0, 0x0010}] = make_elementfield<VR::OB>(4, {0xc4, 0x0e, 0x71, 0x33});
      WHEN("The attribute is serialized")
      {
         std::vector<unsigned char> bytes = bee_tp.serialize(dataset);
         THEN("The attribute is serialized as expected")
         {
            REQUIRE(bytes == expected);
         }
      }
      AND_WHEN("The length of a complete attribute is queried")
      {
         auto length = bee_tp.dataelement_length(dataset[{0x7fe0, 0x0010}]);
         THEN("The byte length of the attribute is returned")
         {
            REQUIRE(length == expected.size());
         }
      }
   }

   GIVEN("A dataset containing a sequence with two items")
   {
      iod dataset, seq1, seq2, seqdel;
      seq1[{0xfffe, 0xe000}] = make_elementfield<VR::NI>();
      seq1[{0x0010, 0x0010}] = make_elementfield<VR::PN>("q^test");
      seq1[{0xfffe, 0xe00d}] = make_elementfield<VR::NI>(); // currently needed, remove later
      seq2[{0xfffe, 0xe000}] = make_elementfield<VR::NI>();
      seq2[{0x0010, 0x0010}] = make_elementfield<VR::PN>("r^test");
      seq2[{0xfffe, 0xe00d}] = make_elementfield<VR::NI>();
      seqdel[{0xfffe, 0xe0dd}] = make_elementfield<VR::NI>();
      dataset[{0x0040, 0x0275}] = make_elementfield<VR::SQ>(0, {seq1, seq2, seqdel});

      WHEN("The dataset is serialized")
      {
         auto data = bee_tp.serialize(dataset);

         THEN("The data is serialized as expected")
         {
            REQUIRE(data.size() == 56);

            std::vector<unsigned char> expected
            {
                0x00,0x40,0x02,0x75,'S','Q',0x00, 0x00,0x00,0x00,0x00,0x2c,0xff,0xfe,0xe0,0x00,0x00,0x00,0x00,0x0e
               ,0x00,0x10,0x00,0x10,'P','N',0x00,0x06,0x71,0x5e,0x74,0x65,0x73,0x74,0xff,0xfe
               ,0xe0,0x00,0x00,0x00,0x00,0x0e,0x00,0x10,0x00,0x10,'P','N',0x00,0x06,0x72,0x5e
               ,0x74,0x65,0x73,0x74
            };

            REQUIRE(data == expected);
         }
      }
   }
}

SCENARIO("Deserialization of a dataset with little-endian implicit transfer syntax", "[dataset][transfer_processor]")
{
   auto& dictionaries = dicom::data::dictionary::get_default_dictionaries(); // use dictionary stub
   little_endian_implicit lei_tp {dictionaries};

   REQUIRE(lei_tp.get_transfer_syntax() == "1.2.840.10008.1.2");

   GIVEN("A single serialized attribute")
   {
      std::vector<unsigned char> data =
      {/*tag*/ 0x10, 0x00, 0x10, 0x00,
       /*length*/ 0x04, 0x00, 0x00, 0x00,
       /*data*/ 't', 'e', 's', 't'};

      WHEN("The dataset is deserialized")
      {
         auto set = lei_tp.deserialize(data);
         THEN("The set contains one element")
         {
            REQUIRE(set.size() == 1);
         }
         AND_THEN("The value is as expected")
         {
            std::string expected;
            get_value_field<VR::PN>(set[{0x0010, 0x0010}], expected);
            REQUIRE(expected == "test");
         }
      }
   }

   GIVEN("A serialized sequence with two items")
   {
//      iod dataset, seq1, seq2;
//      seq1[{0xfffe, 0xe000}] = make_elementfield<VR::NI>();
//      seq1[{0x0010, 0x0010}] = make_elementfield<VR::PN>("q^test");
//      seq1[{0xfffe, 0xe00d}] = make_elementfield<VR::NI>(); // currently needed, remove later
//      seq2[{0xfffe, 0xe000}] = make_elementfield<VR::NI>();
//      seq2[{0x0010, 0x0010}] = make_elementfield<VR::PN>("r^test");
//      seq2[{0xfffe, 0xe00d}] = make_elementfield<VR::NI>();
//      dataset[{0x0040, 0x0275}] = make_elementfield<VR::SQ>(0, {seq1, seq2});

      std::vector<unsigned char> data
      {
          0x40,0x00,0x75,0x02,0x2c,0x00,0x00,0x00,0xfe,0xff,0x00,0xe0,0x0e,0x00,0x00,0x00
         ,0x10,0x00,0x10,0x00,0x06,0x00,0x00,0x00,0x71,0x5e,0x74,0x65,0x73,0x74,0xfe,0xff
         ,0x00,0xe0,0x0e,0x00,0x00,0x00,0x10,0x00,0x10,0x00,0x06,0x00,0x00,0x00,0x72,0x5e
         ,0x74,0x65,0x73,0x74
      };

      WHEN("The dataset is serialized")
      {
         auto set = lei_tp.deserialize(data);

         THEN("The set contain one element")
         {
            REQUIRE(set.size() == 1);
         }
         AND_THEN("The element is the sequence with two items")
         {
            std::vector<dataset_type> seqset;
            get_value_field<VR::SQ>(set[{0x0040, 0x0275}], seqset);
            REQUIRE(seqset.size() == 2);
         }
      }
   }

}

SCENARIO("Deserialization of a dataset with little-endian explicit transfer syntax", "[dataset][transfer_processor]")
{
   auto& dictionaries = dicom::data::dictionary::get_default_dictionaries(); // use dictionary stub
   little_endian_explicit lee_tp {dictionaries};

   REQUIRE(lee_tp.get_transfer_syntax() == "1.2.840.10008.1.2.1");

   GIVEN("A serialized dataset containing a single attribute with 'short' length")
   {
      std::vector<unsigned char> data =
      {/*tag*/ 0x28, 0x00, 0x10, 0x00,
       /*vr*/ 'S', 'S',
       /*length*/ 0x02, 0x00,
       /*data*/ 0xfe, 0xff};
      WHEN("The dataset is deserialized")
      {
         auto set = lee_tp.deserialize(data);
         THEN("The set contains one element")
         {
            REQUIRE(set.size() == 1);
         }
         AND_THEN("The value is as expected")
         {
            short value;
            get_value_field<VR::SS>(set[{0x0028, 0x0010}], value);
            REQUIRE(value == -2);
         }
      }
   }

   GIVEN("A serialized dataset containing a single attribute with 'long' length")
   {
      std::vector<unsigned char> data =
      {/*tag*/ 0xe0, 0x7f, 0x10, 0x00,
       /*vr*/'O', 'B',
       /*padding*/ 0x00, 0x00,
       /*length*/ 0x04, 0x00, 0x00, 0x00,
       /*data*/ 0xc4, 0x0e, 0x71, 0x33};

      WHEN("The attribute is deserialized")
      {
         std::vector<unsigned char> expected {0xc4, 0x0e, 0x71, 0x33};

         auto set = lee_tp.deserialize(data);
         THEN("The set contains one element")
         {
            REQUIRE(set.size() == 1);
         }
         AND_THEN("The value is as expected")
         {
            std::vector<unsigned char> value;
            get_value_field<VR::OB>(set[{0x7fe0, 0x0010}], value);
            REQUIRE(value == expected);
         }
      }
   }

   GIVEN("A serialized dataset containing a sequence with two items")
   {
      std::vector<unsigned char> data
      {
          0x40,0x00,0x75,0x02,'S','Q',0x00, 0x00,0x2c,0x00,0x00,0x00,0xfe,0xff,0x00,0xe0,0x0e,0x00,0x00,0x00
         ,0x10,0x00,0x10,0x00,'P','N',0x06,0x00,0x71,0x5e,0x74,0x65,0x73,0x74,0xfe,0xff
         ,0x00,0xe0,0x0e,0x00,0x00,0x00,0x10,0x00,0x10,0x00,'P','N',0x06,0x00,0x72,0x5e
         ,0x74,0x65,0x73,0x74
      };

      WHEN("The dataset is deserialized")
      {
         auto set = lee_tp.deserialize(data);

         THEN("The set contains one element, the sequence")
         {
            REQUIRE(set.size() == 1);
         }
         AND_THEN("The element is the sequence with two items")
         {
            std::vector<dataset_type> seqset;
            get_value_field<VR::SQ>(set[{0x0040, 0x0275}], seqset);
            REQUIRE(seqset.size() == 2);
         }
      }
   }
}

SCENARIO("Deserialization of a dataset with big-endian explicit transfer syntax", "[dataset][transfer_processor]")
{
   auto& dictionaries = dicom::data::dictionary::get_default_dictionaries(); // use dictionary stub
   big_endian_explicit bee_tp {dictionaries};

   REQUIRE(bee_tp.get_transfer_syntax() == "1.2.840.10008.1.2.2");

   GIVEN("A dataset containing a single attribute with 'short' length")
   {
      std::vector<unsigned char> data =
      {/*tag*/ 0x00, 0x28, 0x00, 0x10,
       /*vr*/ 'S', 'S',
       /*length*/ 0x00, 0x02,
       /*data*/ 0xff, 0xfe};

      WHEN("The dataset is deserialized")
      {
         auto set = bee_tp.deserialize(data);

         THEN("The set contains one element")
         {
            REQUIRE(set.size() == 1);
         }
         AND_THEN("The value is as expected")
         {
            short value;
            get_value_field<VR::SS>(set[{0x0028, 0x0010}], value);
            REQUIRE(value == -2);
         }
      }
   }

   GIVEN("A dataset containing a single attribute with 'long' length")
   {
      std::vector<unsigned char> data =
      {/*tag*/ 0x7f, 0xe0, 0x00, 0x10,
       /*vr*/'O', 'B',
       /*padding*/ 0x00, 0x00,
       /*length*/ 0x00, 0x00, 0x00, 0x04,
       /*data*/ 0xc4, 0x0e, 0x71, 0x33};

      WHEN("The attribute is deserialized")
      {
         std::vector<unsigned char> expected {0xc4, 0x0e, 0x71, 0x33};

         auto set = bee_tp.deserialize(data);
         THEN("The set contains one element")
         {
            REQUIRE(set.size() == 1);
         }
         AND_THEN("The value is as expected")
         {
            std::vector<unsigned char> value;
            get_value_field<VR::OB>(set[{0x7fe0, 0x0010}], value);
            REQUIRE(value == expected);
         }
      }
   }

   GIVEN("A dataset containing a sequence with two items")
   {
      std::vector<unsigned char> data
      {
          0x00,0x40,0x02,0x75,'S','Q',0x00, 0x00,0x00,0x00,0x00,0x2c,0xff,0xfe,0xe0,0x00,0x00,0x00,0x00,0x0e
         ,0x00,0x10,0x00,0x10,'P','N',0x00,0x06,0x71,0x5e,0x74,0x65,0x73,0x74,0xff,0xfe
         ,0xe0,0x00,0x00,0x00,0x00,0x0e,0x00,0x10,0x00,0x10,'P','N',0x00,0x06,0x72,0x5e
         ,0x74,0x65,0x73,0x74
      };

      WHEN("The dataset is serialized")
      {
         auto set = bee_tp.deserialize(data);

         THEN("The set contains one element, the sequence")
         {
            REQUIRE(set.size() == 1);
         }
         AND_THEN("The element is the sequence with two items")
         {
            std::vector<dataset_type> seqset;
            get_value_field<VR::SQ>(set[{0x0040, 0x0275}], seqset);
            REQUIRE(seqset.size() == 2);
         }
      }
   }
}

SCENARIO("Creation of transfer processors")
{
   auto& dictionaries = dicom::data::dictionary::get_default_dictionaries();

   WHEN("A little endian implicit transfer processor is requested")
   {
      auto lei_tp = make_transfer_processor("1.2.840.10008.1.2", dictionaries);

      THEN("The correct instance is created")
      {
         REQUIRE(lei_tp->get_transfer_syntax() == "1.2.840.10008.1.2");
      }
   }
   AND_WHEN("A little endian explicit transfer processor is requested")
   {
      auto lee_tp = make_transfer_processor("1.2.840.10008.1.2.1", dictionaries);

      THEN("The correct instance is created")
      {
         REQUIRE(lee_tp->get_transfer_syntax() == "1.2.840.10008.1.2.1");
      }
   }
   AND_WHEN("A big endian explicit transfer processor is requested")
   {
      auto bee_tp = make_transfer_processor("1.2.840.10008.1.2.2", dictionaries);

      THEN("The correct instance is created")
      {
         REQUIRE(bee_tp->get_transfer_syntax() == "1.2.840.10008.1.2.2");
      }
   }
   AND_WHEN("A unknown transfer processor is requested")
   {
      std::string unsupported = "1.1.1.1";
      THEN("An exception is thrown")
      {
         REQUIRE_THROWS(make_transfer_processor(unsupported, dictionaries));
      }
   }
}

