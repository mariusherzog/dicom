#ifndef UPPERLAYER_COMMUNICATION_STUB_HPP
#define UPPERLAYER_COMMUNICATION_STUB_HPP

#include <string>
#include <exception>
#include <functional>
#include <memory>

#include "../../source/network/upperlayer/upperlayer.hpp"

using namespace dicom::network;
using namespace dicom::network::upperlayer;

/**
 * @brief The upperlayer_communication_stub class is a stub for the
 *        Iupperlayer_comm_ops interface. It can be used to facilitate testing.
 */
class upperlayer_communication_stub : public Iupperlayer_comm_ops
{
      std::function<void(std::unique_ptr<property>)> queue_for_write_handler;

      std::map<TYPE, std::function<void (Iupperlayer_comm_ops*, std::unique_ptr<property>)>> upperlayer_msg_handlers;
      std::map<TYPE, std::function<void (Iupperlayer_comm_ops*, property*)> > upperlayer_conf_handlers;


   public:
      // Iupperlayer_comm_ops_interface
      void queue_for_write(std::unique_ptr<property> p) override
      {
         queue_for_write_handler(std::move(p));
      }

      void inject(TYPE t, std::function<void (Iupperlayer_comm_ops*, std::unique_ptr<property>)> f) override
      {
         upperlayer_msg_handlers[t] = f;
      }

      void inject_conf(TYPE t, std::function<void (Iupperlayer_comm_ops*, property*)> f) override
      {
         upperlayer_conf_handlers[t] = f;
      }

      // Functions for testing
      /**
       * @brief set_handler_on_queue_for_write can be used to set a callback
       *        when the dimse_pm wants to send a response property / PDU. The
       *        callback may then examine the response.
       * @param f callback
       */
      void set_handler_on_queue_for_write(std::function<void(std::unique_ptr<property>)> f)
      {
         queue_for_write_handler = f;
      }

      /**
       * @brief invoke_received_message simulates an incoming PDU notification
       *        from the upperlayer.
       * @param t type of the PDU / property
       * @param prop actual structured property data
       */
      void invoke_received_message(TYPE t, std::unique_ptr<property> prop)
      {
         upperlayer_msg_handlers[t](this, std::move(prop));
      }

      /**
       * @brief invoke_sent_message simulates an successful sent PDU
       *        notification from the upperlayer
       * @param t type of the sent PDU / property
       * @param prop actual property data
       */
      void invoke_sent_message(TYPE t, property* prop)
      {
         upperlayer_conf_handlers[t](this, prop);
      }



};


#endif // UPPERLAYER_COMMUNICATION_STUB_HPP
