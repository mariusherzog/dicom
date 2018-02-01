#include "catch.hpp"

#include <string>
#include <exception>

#include "../source/data/attribute/vmtype.hpp"

using namespace dicom::data;
using namespace dicom::data::attribute;

SCENARIO("Usage of a type with possible multiple values", "[types]")
{
   GIVEN("An instance of vmtype with arbitrary (*) multiplicity")
   {
      dicom::data::attribute::vmtype<unsigned int> type {{"*"}, {8,7,6,5,4}};

      REQUIRE(type.size() == 5);

      WHEN("At least one element is present")
      {
         REQUIRE(type.size() > 0);

         THEN("The first value can be retrieved by implicit type conversion")
         {
            int first = type;
            REQUIRE(first == 8);
         }

         THEN("It is possible to const-iterate over the elements")
         {
            int x = 0;
            for (vmtype<unsigned int>::const_iterator it = type.cbegin(); it != type.cend(); ++it) {
               x = *it;
               REQUIRE(x > 0);
               x = 0;
            }
         }
         THEN("It is possible to iterate over the elements and mutate them")
         {
            for (auto it = type.begin(); it != type.end(); ++it) {
               int previous = *it;
               (*it)++;
               REQUIRE(previous + 1 == *it);
            }
         }
      }

      WHEN("A new element is added")
      {
         auto size_previous = type.size();
         auto bytesize_previous = type.byte_size();
         type.insert({1});

         THEN("the size increases by one")
         {
            REQUIRE(size_previous + 1 == type.size());
         }
         AND_THEN("the byte size increases by sizeof(T) plus the zero-byte delimiter")
         {
            int bytesize_diff = sizeof(int) + 0;
            REQUIRE(bytesize_previous + bytesize_diff == type.byte_size());
         }
         AND_THEN("the element's value can be retrieved from the back")
         {
            int value = type.back();

            REQUIRE(1 == value);
         }
      }

   }

   GIVEN("An instance of vmtype which does not contain any elements")
   {
      vmtype<unsigned char> type;

      WHEN("The size is requested")
      {
         auto size = type.size();

         THEN("The size is zero")
         {
            REQUIRE(size == 0);
         }
      }
      AND_WHEN("The byte size is requested")
      {
         auto bsize = type.byte_size();

         THEN("The byte size is zero")
         {
            REQUIRE(bsize == 0);
         }
      }
   }

   GIVEN("An instance of vmtype with explicit count (n) as multiplicity")
   {
      vmtype<std::string> type({"1"}, {"Hello World"});

      WHEN("A new element is added")
      {
         THEN("An exception is thrown")
         {
            REQUIRE_THROWS(type.insert({"test"}));
         }
         AND_THEN("The size does not change")
         {
            REQUIRE(1 == type.size());
         }
         AND_THEN("The value can still be retrieved")
         {
            REQUIRE("Hello World" == type.back());
         }
      }

      WHEN("An instance is initialized with mismatching number of elements")
      {
         THEN("An exception is thrown")
         {
            REQUIRE_THROWS(vmtype<unsigned int>({"3"}, {4,5,6,7}));
         }
      }
   }

   GIVEN("An instance of vmtype with a specified range (n-m) as multiplicity")
   {
      vmtype<unsigned char> type({"3-6"}, {'A', 'B', 'C', 'D'});

      WHEN("A new element is added and the element count is in range")
      {
         type.insert({'Q'});
         THEN("The element can be added")
         {
            REQUIRE(type.back() == 'Q');
         }
      }
      AND_WHEN("New elements are added which exceed the range")
      {
         THEN("An exception is thrown")
         {
            REQUIRE_THROWS(type.insert({'R', 'S', 'T'}));
         }
      }

      WHEN("An instance is initialized where the element count exceeds the range")
      {
         THEN("An exception is thrown")
         {
            REQUIRE_THROWS(vmtype<unsigned int>({"0-1"}, {1,2,3}));
         }
      }
   }

   GIVEN("An instance of vmtype with a multiplier (kn) as multiplicity")
   {
      vmtype<unsigned int> type({"2n"}, {11, 47});

      WHEN("A new element is added and the resulting size is a multiple of k")
      {
         type.insert({1,2});
         THEN("The elements are added")
         {
            REQUIRE(type.size() == 4);
         }
      }
      AND_WHEN("new elements are added and the resulting size is not a multiple of k")
      {
         THEN("An exception is thrown")
         {
            REQUIRE_THROWS(type.insert({3,4,8}));
         }
      }

      WHEN("An instance is initialized where the elements are not a multiple of k")
      {
         THEN("An exception is thrown")
         {
            REQUIRE_THROWS(vmtype<std::string>({"3n"}, {"Hello", "World"}));
         }
      }
   }

   GIVEN("An instance of vmtype with a multiplier as multiplicity and a range (k-kn)")
   {
      vmtype<unsigned int> type({"3-3n"}, {1,2,3});

      WHEN("A new element is added and the resulting size is a multiple of k")
      {
         type.insert({7,7,7});
         THEN("The elements are added")
         {
            REQUIRE(type.size() == 6);
         }
      }
      AND_WHEN("new elements are added and the resulting size is not a multiple of k")
      {
         THEN("An exception is thrown")
         {
            REQUIRE_THROWS(type.insert({3}));
         }
      }

      WHEN("An instance is initialized where the elements are not a multiple of k")
      {
         THEN("An exception is thrown")
         {
            REQUIRE_THROWS(vmtype<std::string>({"3-3n"}, {"Hello", "World"}));
         }
      }
      AND_WHEN("An instance is initialized which does not satisfy the range")
      {
         THEN("An exception is thrown")
         {
            REQUIRE_THROWS(vmtype<long>({"2-2n"}));
         }
      }
   }

   GIVEN("Multiple instances of vmtypes with the same base type")
   {
      dicom::data::attribute::vmtype<unsigned int> type1 {{"*"}, {8,7,6}};
      dicom::data::attribute::vmtype<unsigned int> type2 {{"*"}, {8,7,6}};
      dicom::data::attribute::vmtype<unsigned int> type3 {{"*"}, {51,7,6}};
      dicom::data::attribute::vmtype<unsigned int> type4 {{"*"}, {51,7,6,22}};

      WHEN("Two have the same contents and lengths")
      {
         THEN("They compare equal")
         {
            REQUIRE(type1 == type2);
         }
      }

      AND_WHEN("Two are the same length, but unequal")
      {
         THEN("They compare unequal")
         {
            REQUIRE(type1 != type3);
         }
      }

      AND_WHEN("Two have differing lengths")
      {
         REQUIRE(type3.size() != type4.size());
         THEN("They compare unequal")
         {
            REQUIRE(type3 != type4);
         }
      }
   }
}

SCENARIO("Usage of vmtype<T> iterators", "[types]")
{
   GIVEN("A vmtype with some elements and the iterator starting at begin()")
   {
      vmtype<std::string> type {{"*"}, {"test1", "test2", "test3", "test4"}};
      auto it = type.begin();

      WHEN("The iterator is dereferenced")
      {
         auto val = *it;
         THEN("The first value is retrieved")
         {
            REQUIRE("test1" == val);
         }
      }
      AND_WHEN("The value is mutated through dereferencing")
      {
         *it = "new";
         THEN("Dereferincing once more yields the new value")
         {
            REQUIRE("new" == *it);
         }
      }

      WHEN("The iterator is incremented")
      {
         ++it;
         auto val = *it;
         THEN("The second value is retrieved")
         {
            REQUIRE("test2" == val);
         }
      }

      WHEN("The iterator is post-incremented")
      {
         auto prev = it++;
         THEN("The post-incremented iterator points to the second value")
         {
            REQUIRE("test2" == *it);
         }
         AND_THEN("The returned iterator points to the first value")
         {
            REQUIRE("test1" == *prev);
         }
      }
   }

   GIVEN("A vmtype with some elements and two iterators")
   {
      vmtype<unsigned int> type({"*"}, {4, 7, 72, 33});
      vmtype<unsigned int>::iterator a = type.begin();
      vmtype<unsigned int>::iterator b = type.begin();
      vmtype<unsigned int>::const_iterator ca = type.cbegin();
      vmtype<unsigned int>::const_iterator cb = type.cbegin();

      WHEN("The iterators point at the same value")
      {
         a = b = type.begin()+1;
         ca = cb = type.cbegin()+1;
         THEN("They are equal by comparison")
         {
            REQUIRE(a == b);
            REQUIRE(ca == cb);
         }
         AND_THEN("They are not non-equal")
         {
            REQUIRE(!(a != b));
            REQUIRE(!(ca != cb));
         }
         AND_THEN("They are not strictly smaller to each other")
         {
            REQUIRE(!(a < b));
            REQUIRE(!(b < a));
            REQUIRE(!(ca < cb));
            REQUIRE(!(cb < ca));
         }
         AND_THEN("They are smaller-or-equal to each other")
         {
            REQUIRE(a <= b);
            REQUIRE(b <= a);
            REQUIRE(ca <= cb);
            REQUIRE(cb <= ca);
         }
         AND_THEN("They are not strictly larger to each other")
         {
            REQUIRE(!(a > b));
            REQUIRE(!(b > a));
            REQUIRE(!(ca > cb));
            REQUIRE(!(cb > ca));
         }
         AND_THEN("They are larger-or-equal to each other")
         {
            REQUIRE(a >= b);
            REQUIRE(b >= a);
            REQUIRE(ca >= cb);
            REQUIRE(cb >= ca);
         }
      }

      AND_WHEN("The iterators point to different values")
      {
         b = type.begin()+2;
         cb = type.cbegin()+2;

         THEN("The iterators are not equal (==)")
         {
            REQUIRE(!(a==b));
            REQUIRE(!(ca==cb));
         }
         AND_THEN("The iterators are non-equal (!=)")
         {
            REQUIRE(a != b);
            REQUIRE(ca != cb);
         }
         AND_THEN("One is ordinally smaller than the other")
         {
            REQUIRE(a < b);
            REQUIRE(a <= b);
            REQUIRE(ca < cb);
            REQUIRE(ca <= cb);
         }
         AND_THEN("The ordinally smaller iterator is not larger than the other")
         {
            REQUIRE(!(a > b));
            REQUIRE(!(a >= b));
            REQUIRE(!(ca > cb));
            REQUIRE(!(ca >= cb));
         }
         AND_THEN("One is ordinally larger than the other")
         {
            REQUIRE(b > a);
            REQUIRE(b >= a);
            REQUIRE(cb > ca);
            REQUIRE(cb >= ca);
         }
         AND_THEN("The ordinally larger iterator is not smaller than the other")
         {
            REQUIRE(!(b < a));
            REQUIRE(!(b <= a));
            REQUIRE(!(cb < ca));
            REQUIRE(!(cb <= ca));
         }
      }
   }
}



