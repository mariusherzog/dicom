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

      data[{0x0010, 0x0010}] = make_elementfield<VR::PN>("Test^One^Two^^");

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
   }
}


