#include "catch.hpp"

#include <string>

#include <boost/optional.hpp>

#include "../source/data/dictionary/dictionary.hpp"
#include "../source/data/dictionary/dictionary_entry.hpp"

using namespace dicom::data::dictionary;

static bool valid_entry(const dictionary_entry& entry)
{
   return entry.message_field.length() > 0 &&
          entry.keyword.length() > 0 &&
          entry.vm.length() > 0;
}

SCENARIO("Retrieval of dictionary information", "[dataset]")
{
   GIVEN("A dynamic dicom dictionary for lazy lookup")
   {
      dictionary_dyn dict {"commanddictionary.csv"};

      WHEN("A lookup is performed for an existing element")
      {
         auto entry = dict.lookup({0x0000, 0x0002});

         THEN("The result contains a value")
         {
            REQUIRE(entry.is_initialized());
         }
         AND_THEN("The returned entry contains valid data")
         {
            REQUIRE(valid_entry(*entry));
         }
      }

      AND_WHEN("A lookup is performed for a non-existing element")
      {
         auto entry = dict.lookup({0x0003, 0x0005});

         THEN("The result entry contains no value")
         {
            REQUIRE(!entry.is_initialized());
         }
      }
   }

   GIVEN("A dynamic dictionary for greedy lookup")
   {
      dictionary_dyn dict {"commanddictionary.csv", dictionary_dyn::MODE::GREEDY};

      WHEN("A lookup is performed for an existing element")
      {
         auto entry = dict.lookup({0x0000, 0x0100});

         THEN("The result contains a value")
         {
            REQUIRE(entry.is_initialized());
         }
         AND_THEN("The returned entry contains valid data")
         {
            REQUIRE(valid_entry(*entry));
         }
      }

      AND_WHEN("A lookup is performed for a non-existing element")
      {
         auto entry = dict.lookup({0x0003, 0x0005});

         THEN("The result entry contains no value")
         {
            REQUIRE(!entry.is_initialized());
         }
      }
   }
}

SCENARIO("Retrieving dictionary entries for combined dictionaries")
{
   GIVEN("A dictionary aggregate")
   {
      dictionaries dicts {"commanddictionary.csv", "datadictionary.csv"};

      WHEN("A lookup is performed for an entry which is present in one dictionary")
      {
         auto entry = dicts.lookup({0x0010, 0x0010});

         THEN("The result is not the unknown element")
         {
            REQUIRE(entry.keyword != "UNKNOWN");
         }
      }

      AND_WHEN("A lookup is performed for an entry which is in neither dictionary")
      {
         auto entry = dicts.lookup({0x0031, 0x0005});

         THEN("The result entry contains no value")
         {
            REQUIRE(entry.keyword == "UNKNOWN");
         }
      }

      AND_WHEN("A static lookup is performed for the command dictionary")
      {
         dictionaries::static_eid<0x0000> cmd_gid;
         dictionaries::static_eid<0x0002> cmd_eid;
         auto entry = dicts.lookup_commanddic(cmd_gid, cmd_eid);

         THEN("The expected result is returned")
         {
            REQUIRE(entry.keyword == "AffectedSOPClassUID");
         }

         dictionaries::static_eid<0x0020> data_gid;
         dictionaries::static_eid<0x0020> data_eid;
         auto data_entry = dicts.lookup_datadic(data_gid, data_eid);

         THEN("The expected result is returned")
         {
            REQUIRE(data_entry.keyword == "PatientOrientation");
         }
      }
   }
}
