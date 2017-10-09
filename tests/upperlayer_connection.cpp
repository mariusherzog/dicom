#include "catch.hpp"

#include <string>
#include <exception>
#include <memory>
#include <deque>

#include "stubs/infrastructure_connection_stub.hpp"
#include "../source/data/dictionary/dictionary.hpp"
#include "../source/network/upperlayer/upperlayer_connection.hpp"

using namespace dicom::network::upperlayer;

SCENARIO("Usage of the upperlayer as a service class provider", "[network][upperlayer]")
{
   dicom::data::dictionary::dictionary dict {"commanddictionary.csv", "datadictionary.csv"};

   std::function<void(Iupperlayer_comm_ops*)> handler_new_conn = [](Iupperlayer_comm_ops*) {};
   std::function<void(Iupperlayer_comm_ops*)> handler_end_conn = [](Iupperlayer_comm_ops*) {};

   GIVEN("A remote connection")
   {
      infrastructure_read_connection_stub stub;

      stub.set_next_segment("a_associate_rq.bin");

      WHEN("Binary a_associate_rq pdu is received")
      {
         bool associate_rq_called = false;
         std::unique_ptr<property> received_prop = nullptr;
         auto handler = [&](Iupperlayer_comm_ops* ul, std::unique_ptr<property> prop)
         {
            associate_rq_called = true;
            received_prop = std::move(prop);
            ul->queue_for_write(std::unique_ptr<property> {new a_abort{}});
         };
         scp_connection scp {&stub, dict, 0, handler_new_conn, handler_end_conn, {{TYPE::A_ASSOCIATE_RQ, handler}}};

         THEN("The a-associate_rq handler is called")
         {
            REQUIRE(associate_rq_called);
         }
         AND_THEN("The received pdu is of type a_associate_rq")
         {
            REQUIRE(received_prop->type() == TYPE::A_ASSOCIATE_RQ);
         }
         AND_THEN("The pdu contains a correct application context")
         {
            auto pdu = dynamic_cast<a_associate_rq*>(received_prop.get());
            REQUIRE(pdu->application_context == "1.2.840.10008.3.1.1.1");
         }
         AND_THEN("The pdu contains at least one presentation context")
         {
            auto pdu = dynamic_cast<a_associate_rq*>(received_prop.get());
            REQUIRE(pdu->pres_contexts.size() > 0);
         }
      }

      AND_WHEN("p_data_tf is received after a_associate_rq")
      {
         bool p_data_tf_called = false;
         std::unique_ptr<property> received_prop = nullptr;
         auto rqhandler = [&](Iupperlayer_comm_ops* ul, std::unique_ptr<property>)
         {
            stub.set_next_segment("p_data_tf.bin");
            a_associate_ac* ac = new a_associate_ac;
            ac->called_ae = ac->calling_ae = "0123456789abcdef";
            ul->queue_for_write(std::unique_ptr<property> {ac});
         };
         auto handler = [&](Iupperlayer_comm_ops* ul, std::unique_ptr<property> prop)
         {
            p_data_tf_called = true;
            received_prop = std::move(prop);
            ul->queue_for_write(std::unique_ptr<property> {new a_abort{}});
         };
         scp_connection scp {&stub, dict, 0, handler_new_conn, handler_end_conn, {
               {TYPE::P_DATA_TF, handler},
               {TYPE::A_ASSOCIATE_RQ, rqhandler}}};

         THEN("The p_data_tf handler is called")
         {
            REQUIRE(p_data_tf_called);
         }
         AND_THEN("The received pdu is of type p_data_tf")
         {
            REQUIRE(received_prop->type() == TYPE::P_DATA_TF);
         }
         AND_THEN("The pdu contains a valid presentation context id")
         {
            auto pdu = dynamic_cast<p_data_tf*>(received_prop.get());
            unsigned char pres_cont_id = pdu->pres_context_id;
            REQUIRE(pres_cont_id % 2 == 1);
         }
         AND_THEN("The command set is not empty")
         {
            auto pdu = dynamic_cast<p_data_tf*>(received_prop.get());
            REQUIRE(pdu->command_set.size() > 0);
         }
      }

      AND_WHEN("a_release_rq is received after p_data_tf")
      {
         bool release_rq_called = false;
         std::unique_ptr<property> received_prop = nullptr;
         auto rqhandler = [&](Iupperlayer_comm_ops* ul, std::unique_ptr<property>)
         {
            stub.set_next_segment("p_data_tf.bin");
            a_associate_ac* ac = new a_associate_ac;
            ac->called_ae = ac->calling_ae = "0123456789abcdef";
            ul->queue_for_write(std::unique_ptr<property> {ac});
         };
         auto datahandler = [&](Iupperlayer_comm_ops*, std::unique_ptr<property>)
         {
            stub.set_next_segment("a_release_rq.bin");
         };
         auto handler = [&](Iupperlayer_comm_ops* ul, std::unique_ptr<property> prop)
         {
            release_rq_called = true;
            received_prop = std::move(prop);
            ul->queue_for_write(std::unique_ptr<property> {new a_release_rp{}});
         };
         scp_connection scp {&stub, dict, 0, handler_new_conn, handler_end_conn, {
               {TYPE::P_DATA_TF, datahandler},
               {TYPE::A_ASSOCIATE_RQ, rqhandler},
               {TYPE::A_RELEASE_RQ, handler}}};

         THEN("The p_data_tf handler is called")
         {
            REQUIRE(release_rq_called);
         }
         AND_THEN("The received pdu is of type p_data_tf")
         {
            REQUIRE(received_prop != nullptr);
            REQUIRE(received_prop->type() == TYPE::A_RELEASE_RQ);
         }
      }
   }


   GIVEN("An accepted remote connection")
   {
      infrastructure_read_connection_stub stub;
      stub.set_next_segment("a_associate_rq.bin");

      const std::size_t remote_msg_length = 16384;

      auto rqhandler = [&](Iupperlayer_comm_ops* ul, std::unique_ptr<property> prop)
      {
         auto rq = dynamic_cast<a_associate_rq*>(prop.get());
         stub.set_next_segment("p_data_tf.bin");
         a_associate_ac* ac = new a_associate_ac;
         ac->called_ae = ac->calling_ae = "0123456789abcdef";
         ac->max_message_length = rq->max_message_length;
         ul->queue_for_write(std::unique_ptr<property> {ac});
      };

      WHEN("Data is sent")
      {
         std::deque<std::size_t> fragment_sizes;

         auto datasent_handler = [&](Iupperlayer_comm_ops* ul, property*)
         {
            stub.set_write_handler([](std::size_t) {});
            ul->queue_for_write(std::unique_ptr<property> {new a_abort{}});
         };

         auto datahandler = [&](Iupperlayer_comm_ops* ul, std::unique_ptr<property> prop)
         {
            ul->inject_conf(TYPE::P_DATA_TF, datasent_handler);
            auto dat = dynamic_cast<p_data_tf*>(prop.get());
            // set the remote message length of this pdu
            dat->msg_length = remote_msg_length;

            stub.set_write_handler([&](std::size_t count)
            {
               fragment_sizes.push_back(count);
            });
            ul->queue_for_write(std::unique_ptr<property> {new p_data_tf {*dat}});
         };

         scp_connection scp {&stub, dict, 0, handler_new_conn, handler_end_conn, {
               {TYPE::P_DATA_TF, datahandler},
               {TYPE::A_ASSOCIATE_RQ, rqhandler}}};

         // the first element is the command set
         fragment_sizes.pop_front();

         THEN("The last fragment size is equal or less than the message length")
         {
            auto last_fragment = fragment_sizes.back();
            REQUIRE(last_fragment <= remote_msg_length);
         }
         AND_THEN("All other fragment sizes are equal to the message length")
         {
            bool all_equal = true;
            fragment_sizes.pop_back();
            std::all_of(fragment_sizes.begin(), fragment_sizes.end(),
                        [](std::size_t sz) { return sz == remote_msg_length; });
            REQUIRE(all_equal);
         }
      }


      AND_WHEN("The association is released via release-rq from the peer")
      {
         bool received_release_rp = false;
         std::unique_ptr<property> received_prop = nullptr;

         auto datahandler = [&](Iupperlayer_comm_ops* ul, std::unique_ptr<property> prop)
         {
            stub.set_next_segment("a_release_rq.bin");
            auto dat = dynamic_cast<p_data_tf*>(prop.get());
            // set the remote message length of this pdu
            dat->msg_length = remote_msg_length;
            ul->queue_for_write(std::unique_ptr<property> {new p_data_tf {*dat}});
         };

         auto releasehandler = [&](Iupperlayer_comm_ops* ul, std::unique_ptr<property> prop)
         {
            received_release_rp = true;
            received_prop = std::move(prop);
            ul->queue_for_write(std::unique_ptr<property> {new a_release_rp{}});
         };

         scp_connection scp {&stub, dict, 0, handler_new_conn, handler_end_conn, {
               {TYPE::P_DATA_TF, datahandler},
               {TYPE::A_ASSOCIATE_RQ, rqhandler},
               {TYPE::A_RELEASE_RQ, releasehandler}}};

         // TODO: check write confirmation handlers are called

         THEN("The release-rp handler is called")
         {
            REQUIRE(received_release_rp);
         }
         AND_THEN("The received pdu is of type a_release_rq")
         {
            REQUIRE(received_prop->type() == TYPE::A_RELEASE_RQ);
         }
      }
   }
}




