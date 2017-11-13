#include "catch.hpp"

#include <string>

#include <fstream>

#include "../source/network/dimse/dimse_pm.hpp"
#include "../source/network/dimse/association_definition.hpp"
#include "../source/data/dictionary/dictionary.hpp"
#include "../source/data/dataset/datasets.hpp"

#include "stubs/upperlayer_communication_stub.hpp"

using namespace dicom::network;
using namespace dicom::network::dimse;
using namespace dicom::data;
using namespace dicom::data::dataset;

SCENARIO("Association negotiation on the dimse protocol machine as SCP", "[network][dimse]")
{
   upperlayer_communication_stub ul_stub;
   dicom::data::dictionary::dictionary dict;

   GIVEN("An association with no presentation contexts")
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
         AND_THEN("The reject reason is the invalid application context uid")
         {
            auto rj_pdu = dynamic_cast<a_associate_rj*>(response.get());
            REQUIRE(rj_pdu->reason_ == a_associate_rj::REASON::APPL_CONT_NOT_SUPP);
         }
      }
      AND_WHEN("The dimse_pm receives an a-associate-rq with a valid application context uid and no presentation contexts")
      {
         std::unique_ptr<property> response;
         ul_stub.set_handler_on_queue_for_write([&](std::unique_ptr<property> p)
         {
            response = std::move(p);
         });

         auto a = new a_associate_rq();
         a->application_context = "1.2.840.10008.3.1.1.1";
         ul_stub.invoke_received_message(TYPE::A_ASSOCIATE_RQ, std::unique_ptr<property>(a));
// TODO: Check behaviour in standard
//         THEN("The association is rejected")
//         {
//            REQUIRE(response->type() == TYPE::A_ASSOCIATE_RJ);
//         }
//         AND_THEN("The reject reason is that there are no supported application contexts")
//         {

//         }
      }
   }

   GIVEN("An association with one presentation contexts")
   {
      dimse::SOP_class echo {"1.2.840.10008.1.1",
                             { { dataset::DIMSE_SERVICE_GROUP::C_ECHO_RSP,
                     [](dimse::dimse_pm*, dataset::commandset_data, std::unique_ptr<dataset::iod>) {
               }}}
                            };
      association_definition::presentation_context pc {echo, {"1.2.840.10008.1.2"}, association_definition::DIMSE_MSG_TYPE::RESPONSE};
      association_definition assoc {"CALLING", "CALLED", {pc}};

      dimse_pm dpm(ul_stub, assoc,  dict);

      WHEN("The dimse_pm receives an a-associate-rq with a matching presentation context from the upperlayer")
      {
         std::unique_ptr<property> response;
         ul_stub.set_handler_on_queue_for_write([&](std::unique_ptr<property> p)
         {
            response = std::move(p);
         });

         auto a = new a_associate_rq();
         a->application_context = "1.2.840.10008.3.1.1.1";
         a->pres_contexts.emplace_back();
         a->pres_contexts[0].abstract_syntax = "1.2.840.10008.1.1";
         a->pres_contexts[0].id = 1;
         a->pres_contexts[0].transfer_syntaxes.push_back("1.2.840.10008.1.2");

         ul_stub.invoke_received_message(TYPE::A_ASSOCIATE_RQ, std::unique_ptr<property>(a));
         THEN("The response is accepted, ie. of type A_ASSOCIATE_AC")
         {
            REQUIRE(response->type() == TYPE::A_ASSOCIATE_AC);
         }
         AND_THEN("The presentation context in the a_associate_ac pdu is accepted")
         {
            auto ac_pdu = dynamic_cast<a_associate_ac*>(response.get());
            REQUIRE(ac_pdu->pres_contexts[0].result_ == a_associate_ac::presentation_context::RESULT::ACCEPTANCE);
         }
         AND_THEN("Transfer syntax is equal to the one from our association definition")
         {
            auto ac_pdu = dynamic_cast<a_associate_ac*>(response.get());
            REQUIRE(ac_pdu->pres_contexts[0].transfer_syntax == "1.2.840.10008.1.2");
         }
      }
      AND_WHEN("The dimse_pm receives an a-associate-rq with an unsupported transfer syntax from the upperlayer")
      {
         std::unique_ptr<property> response;
         ul_stub.set_handler_on_queue_for_write([&](std::unique_ptr<property> p)
         {
            response = std::move(p);
         });

         auto a = new a_associate_rq();
         a->application_context = "1.2.840.10008.3.1.1.1";
         a->pres_contexts.emplace_back();
         a->pres_contexts[0].abstract_syntax = "1.2.840.10008.1.1";
         a->pres_contexts[0].id = 1;
         a->pres_contexts[0].transfer_syntaxes.push_back("9.9.9.9.9");

         ul_stub.invoke_received_message(TYPE::A_ASSOCIATE_RQ, std::unique_ptr<property>(a));
         THEN("The presentation context in the a_associate_ac pdu is rejected")
         {
            auto ac_pdu = dynamic_cast<a_associate_ac*>(response.get());
            REQUIRE(ac_pdu->pres_contexts[0].result_ == a_associate_ac::presentation_context::RESULT::TRANSF_SYNT_NOT_SUPP);
         }
      }
      AND_WHEN("The dimse_pm receives an a-associate-rq with an unsupported abstract syntax from the upperlayer")
      {
         std::unique_ptr<property> response;
         ul_stub.set_handler_on_queue_for_write([&](std::unique_ptr<property> p)
         {
            response = std::move(p);
         });

         auto a = new a_associate_rq();
         a->application_context = "1.2.840.10008.3.1.1.1";
         a->pres_contexts.emplace_back();
         a->pres_contexts[0].abstract_syntax = "17.77.77.77";
         a->pres_contexts[0].id = 1;
         a->pres_contexts[0].transfer_syntaxes.push_back("1.2.840.10008.1.2");

         ul_stub.invoke_received_message(TYPE::A_ASSOCIATE_RQ, std::unique_ptr<property>(a));
         THEN("The presentation context in the a_associate_ac pdu is rejected")
         {
            auto ac_pdu = dynamic_cast<a_associate_ac*>(response.get());
            REQUIRE(ac_pdu->pres_contexts[0].result_ == a_associate_ac::presentation_context::RESULT::ABSTR_CONT_NOT_SUPP);
         }
      }
   }



      // When the list of presentation contexts is empty
      // When the application context is unknown
      // When the calling ae matches, then ... etc.
}


SCENARIO("Data transmission on an established association", "[network][dimse]")
{
   upperlayer_communication_stub ul_stub;
   dicom::data::dictionary::dictionary dict;

   std::unique_ptr<property> response;
   ul_stub.set_handler_on_queue_for_write([&](std::unique_ptr<property> p)
   {
      response = std::move(p);
   });

   std::vector<unsigned char> cecho_bin;
   std::fstream cecho_file {"data/cechorq.bin", std::ios::in | std::ios::binary};
   std::copy(std::istreambuf_iterator<char>{cecho_file},
             std::istreambuf_iterator<char>{},
             std::back_inserter(cecho_bin));


   GIVEN("An established association")
   {
      bool called = false;
      dimse::SOP_class echo {
         "1.2.840.10008.1.1",
         { { dataset::DIMSE_SERVICE_GROUP::C_ECHO_RQ,
                     [&called](dimse::dimse_pm*, dataset::commandset_data, std::unique_ptr<dataset::iod>) {
                  called = true;
               }}}
      };
      association_definition::presentation_context pc {echo, {"1.2.840.10008.1.2"}, association_definition::DIMSE_MSG_TYPE::RESPONSE};
      association_definition assoc {"CALLING", "CALLED", {pc}};

      dimse_pm dpm(ul_stub, assoc,  dict);

      auto a = new a_associate_rq();
      a->application_context = "1.2.840.10008.3.1.1.1";
      a->pres_contexts.emplace_back();
      a->pres_contexts[0].abstract_syntax = "1.2.840.10008.1.1";
      a->pres_contexts[0].id = 1;
      a->pres_contexts[0].transfer_syntaxes.push_back("1.2.840.10008.1.2");

      ul_stub.invoke_received_message(TYPE::A_ASSOCIATE_RQ, std::unique_ptr<property>(a));

      WHEN("Data is sent on an accepted resentation context")
      {
         auto data = new p_data_tf;
         data->command_set = cecho_bin;
         ul_stub.invoke_received_message(TYPE::P_DATA_TF, std::unique_ptr<property>(data));

         THEN("The handler for this sop class with the respective service group is called")
         {
            REQUIRE(called);
         }
      }

      AND_WHEN("An error occurs during data transmission")
      {
         //ul_stub.invoke_sent_message();
      }

   }
}

SCENARIO("Association release on the dimse protocol machine", "[network][dimse]")
{

}
