#ifndef UPPERLAYER_SERVER_ACCEPTOR_STUB_HPP
#define UPPERLAYER_SERVER_ACCEPTOR_STUB_HPP

#include <string>
#include <exception>
#include <functional>
#include <memory>

#include "../../source/network/upperlayer/upperlayer.hpp"
#include "infrastructure_connection_stub.hpp"

using namespace dicom::network;
using namespace dicom::network::upperlayer;

/**
 * @brief The upperlayer_server_acceptor_stub simulates incoming connections
 *        from a remote client
 */
class upperlayer_server_acceptor_stub : public Iinfrastructure_server_acceptor
{
   private:
      std::function<void(Iinfrastructure_upperlayer_connection*)> handler_new_conn;
      std::function<void(Iinfrastructure_upperlayer_connection*)> handler_end_conn;

      std::vector<infrastructure_read_connection_stub> conns;

      std::function<void()> on_run;

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
       * @brief push_connection signals a new incoming connection
       * @param on_connect handler to be invoked after the connection initiates,
       *        may be used to set invariants before it is actually accessed by
       *        the scp connection.
       */
      template <typename Fn>
      void push_connection(Fn&& on_connect)
      {
         conns.push_back(infrastructure_read_connection_stub {});
         on_connect(&conns.back());
         handler_new_conn(&conns.back());
      }

      /**
       * @brief pop_connection terminates the last connection
       */
      void pop_connection()
      {
         handler_end_conn(&conns.back());
         conns.pop_back();
      }

};



#endif // UPPERLAYER_SERVER_ACCEPTOR_STUB_HPP
