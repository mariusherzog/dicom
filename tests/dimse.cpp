#include "catch.hpp"

#include <string>

#include "../source/network/dimse/dimse_pm.hpp"
#include "../source/network/dimse/association_definition.hpp"
#include "../source/data/dictionary/dictionary.hpp"

#include "stubs/upperlayer_communication_stub.hpp"

using namespace dicom::network;
using namespace dicom::network::dimse;

SCENARIO("Association negotiation on the dimse protocol machine", "[network][dimse]")
{
   upperlayer_communication_stub ul_stub;
   dicom::data::dictionary::dictionary dict;

   GIVEN("A dimse protocol machine with one presentation context")
   {
      association_definition assoc("CALLING", "CALLED", {{}});

      dimse_pm dpm(ul_stub, assoc,  dict);

      WHEN("The dimse_pm receives an empty a-associate-rq from the upperlayer")
      {
         std::unique_ptr<property> response;
         ul_stub.set_handler_on_queue_for_write([&](std::unique_ptr<property> p)
         {
            response = std::move(p);
         });

         auto a = new a_associate_rq();
         ul_stub.invoke_received_message(TYPE::A_ASSOCIATE_RQ, std::unique_ptr<property>(a));

         THEN("The association is rejected")
         {
            REQUIRE(response->type() == TYPE::A_ASSOCIATE_RJ);
         }
      }

      // When the list of presentation contexts is empty
      // When the application context is unknown
      // When the calling ae matches, then ... etc.
   }
}

SCENARIO("Data transmission on an established association", "[network][dimse]")
{

}

SCENARIO("Association release on the dimse protocol machine", "[network][dimse]")
{

}
