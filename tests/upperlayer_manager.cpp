#include "catch.hpp"

#include <string>
#include <exception>
#include <memory>
#include <deque>

#include "stubs/upperlayer_server_acceptor_stub.hpp"
#include "stubs/upperlayer_client_acceptor_stub.hpp"
#include "../source/data/dictionary/dictionary.hpp"
#include "../source/network/upperlayer/upperlayer.hpp"

using namespace dicom::network::upperlayer;
using namespace dicom::network;

SCENARIO("Managing of multiple upperlayer connections as a server", "[network][upperlayer]")
{
   /// TODO add case when using multiple connections and one fails

   dicom::data::dictionary::dictionary dict {"commanddictionary.csv", "datadictionary.csv"};

   GIVEN("An scp upperlayer connection manager")
   {
      upperlayer_server_acceptor_stub server_stub;
      upperlayer::scp scp_manager {server_stub, dict};

      WHEN("A new connection is started")
      {
         bool new_connection_called = false;
         Iupperlayer_comm_ops* connection = nullptr;
         // wire in some callbacks
         auto new_conn = [&](Iupperlayer_comm_ops* conn)
         {
            new_connection_called = true;
            connection = conn;
         };

         scp_manager.new_connection(new_conn);
         server_stub.push_connection([](infrastructure_read_connection_stub* conn)
         {
            // the new connection will want to read something, so we set something
            // here
            conn->set_next_segment("a_release_rq.bin");
         });

         THEN("The callback for a new connection is called")
         {
            REQUIRE(new_connection_called);
         }
         AND_THEN("The connection points to a valid object")
         {
            connection->queue_for_write(nullptr);
            REQUIRE(connection);
         }
      }

      AND_WHEN("An existing connection terminates")
      {
         bool end_connection_called = false;
         // wire in some callbacks
         auto new_conn = [](Iupperlayer_comm_ops*)
         {
         };
         auto end_conn = [&](Iupperlayer_comm_ops*)
         {
            end_connection_called = true;
         };

         scp_manager.new_connection(new_conn);
         scp_manager.end_connection(end_conn);
         server_stub.push_connection([](infrastructure_read_connection_stub* conn)
         {
            conn->set_next_segment("a_release_rq.bin");
         });

         server_stub.pop_connection();

         THEN("The callback for an ending connection is called")
         {
            REQUIRE(end_connection_called);
         }
      }

      AND_WHEN("run() is called on the scp manager")
      {
         bool run_called = false;
         server_stub.set_run_handler([&]() {run_called = true;});

         scp_manager.run();

         THEN("run() is called on the infrastructure acceptor")
         {
            REQUIRE(run_called);
         }
      }

   }
}

SCENARIO("Managing of multiple upperlayer connections as a client", "[network][upperlayer]")
{
   dicom::data::dictionary::dictionary dict {"commanddictionary.csv", "datadictionary.csv"};

   a_associate_rq associate_rq;
   associate_rq.application_context = "1.2.840.10008.3.1.1.1";
   associate_rq.called_ae = associate_rq.calling_ae = "0123456789abcdef";

   GIVEN("An scu upperlayer connection manager")
   {
      upperlayer_client_acceptor_stub client_stub;
      upperlayer::scu scu_manager {client_stub, dict, associate_rq};

      WHEN("A new connection is started")
      {
         bool new_connection_called = false;
         Iupperlayer_comm_ops* connection = nullptr;
         // wire in some callbacks
         auto new_conn = [&](Iupperlayer_comm_ops* conn)
         {
            new_connection_called = true;
            connection = conn;
         };

         scu_manager.new_connection(new_conn);

         // initiate a new connection to the "remote" peer
         client_stub.push_connection([](infrastructure_read_connection_stub* conn)
         {
            // the new connection will want to read something, so we set something
            // here
            conn->set_next_segment("a_release_rq.bin");
         });

         THEN("The callback for a new connection is called")
         {
            REQUIRE(new_connection_called);
         }
         AND_THEN("The connection points to a valid object")
         {
            connection->queue_for_write(nullptr);
            REQUIRE(connection);
         }
      }

      AND_WHEN("An existing connection terminates")
      {
         bool end_connection_called = false;
         // wire in some callbacks
         auto new_conn = [](Iupperlayer_comm_ops*)
         {
         };
         auto end_conn = [&](Iupperlayer_comm_ops*)
         {
            end_connection_called = true;
         };

         scu_manager.new_connection(new_conn);
         scu_manager.end_connection(end_conn);

         client_stub.push_connection([](infrastructure_read_connection_stub* conn)
         {
            // the new connection will want to read something, so we set something
            // here
            conn->set_next_segment("a_release_rq.bin");
         });

         client_stub.pop_connection();

         THEN("The callback for an ending connection is called")
         {
            REQUIRE(end_connection_called);
         }
      }

      AND_WHEN("run() is called on the scp manager")
      {
         bool run_called = false;
         client_stub.set_run_handler([&]() { run_called = true; });

         scu_manager.run();

         THEN("run() is called on the infrastructure acceptor")
         {
            REQUIRE(run_called);
         }
      }

      AND_WHEN("A new connection is initiated by the scu")
      {
         bool accept_new_called = false;
         client_stub.set_accept_new_handler([&]() { accept_new_called = true; });

         scu_manager.accept_new();

         THEN("accept_new() is called on infrastructure level")
         {
            REQUIRE(accept_new_called);
         }
      }

   }
}
