#ifndef UPPERLAYER_CLIENT_ACCEPTOR_STUB_HPP
#define UPPERLAYER_CLIENT_ACCEPTOR_STUB_HPP

#include <string>
#include <exception>
#include <functional>
#include <memory>

#include "../../source/network/upperlayer/upperlayer.hpp"
#include "infrastructure_connection_stub.hpp"

using namespace dicom::network;
using namespace dicom::network::upperlayer;

/**
 * @brief The upperlayer_client_acceptor_stub simulates facilities to start
 *        connections with a "remote" peer
 */
class upperlayer_client_acceptor_stub : public Iinfrastructure_client_acceptor
{
   private:
      std::function<void(Iinfrastructure_upperlayer_connection*)> handler_new_conn;
      std::function<void(Iinfrastructure_upperlayer_connection*)> handler_end_conn;

      std::vector<infrastructure_read_connection_stub> conns;

      std::function<void()> on_run;
      std::function<void()> on_accept_new;

      // Iinfrastructure_server_acceptor interface
   public:
      void run() override
      {
         if (on_run) {
            on_run();
         }
      }

      void set_handler_new(std::function<void (Iinfrastructure_upperlayer_connection*)> handler) override
      {
         handler_new_conn = handler;
      }

      void set_handler_end(std::function<void (Iinfrastructure_upperlayer_connection*)> handler) override
      {
         handler_end_conn = handler;
      }

      void accept_new_conn() override
      {
         //push_connection();
         if (on_accept_new) {
            on_accept_new();
         }
      }

      /**
       * @brief set_run_handler sets the callback to be invoked when run()
       *        is called
       * @param run_handler handler to be called
       */
      void set_run_handler(decltype(on_run) run_handler)
      {
         on_run = run_handler;
      }

      /**
       * @brief set_accept_new_handler sets the handler for when handler_new
       *        for a new connection is called
       * @param accept_new_handler handler
       */
      void set_accept_new_handler(decltype(on_accept_new) accept_new_handler)
      {
         on_accept_new = accept_new_handler;
      }


      template <typename Fn>
      void push_connection(Fn&& on_connect)
      {
         conns.push_back(infrastructure_read_connection_stub {});
         on_connect(&conns.back());
         handler_new_conn(&conns.back());
      }

      void pop_connection()
      {
         handler_end_conn(&conns.back());
         conns.pop_back();
      }



};



#endif // UPPERLAYER_SERVER_ACCEPTOR_STUB_HPP
