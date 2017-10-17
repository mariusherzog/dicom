#ifndef UPPERLAYER_HPP
#define UPPERLAYER_HPP

#include <functional>
#include <memory>

#include <boost/log/trivial.hpp>

#include "upperlayer_connection.hpp"
#include "infrastructure/asio_tcp_connection_manager.hpp"
#include "data/dictionary/dictionary.hpp"


namespace dicom
{


namespace network
{


namespace upperlayer
{

void run();


/**
 * @brief The Iupperlayer_connection_handlers struct defines an interface to inject callbacks
 *        for the start / termination of a connection.
 */
struct Iupperlayer_connection_handlers
{
      /**
       * @brief new_connection is the handler that will be invoked when a new
       *        connection is established.
       * @param f function which receives a pointer to the communication object
       *        as a parameter
       */
      virtual void new_connection(std::function<void(Iupperlayer_comm_ops*)> f) = 0;

      /**
       * @brief end_connection is the handler when an existing association is
       *        terminated.
       * @param f function with the communication instance as parameter which
       *        has ended.
       */
      virtual void end_connection(std::function<void(Iupperlayer_comm_ops*)> f) = 0;

      /**
       * @brief run starts the handling of the connections
       */
      virtual void run() = 0;

      virtual ~Iupperlayer_connection_handlers() = 0;
};


/**
 * @brief The scp class acts as a service class provider which can have
 *        and manages multiple connections simultaneously as specified by the
 *        constructor's parameters.
 */
class scp: public Iupperlayer_connection_handlers
{
   public:
      scp(Iinfrastructure_server_acceptor& infrstr_scp,
          data::dictionary::dictionary& dict);
      scp(const scp&) = delete;
      scp& operator=(const scp&) = delete;

      ~scp();

      /**
       * @brief run() instructs the server to start listening for associations
       */
      virtual void run() override;

      virtual void new_connection(std::function<void(Iupperlayer_comm_ops*)> handler) override;
      virtual void end_connection(std::function<void(Iupperlayer_comm_ops*)> handler) override;

   private:

      std::map<Iinfrastructure_upperlayer_connection*, std::unique_ptr<scp_connection>> scps;

      void accept_new(Iinfrastructure_upperlayer_connection* conn);

      void connection_end(Iinfrastructure_upperlayer_connection* conn);

      std::function<void(Iupperlayer_comm_ops*)> handler_new_connection;
      std::function<void(Iupperlayer_comm_ops*)> handler_end_connection;

      Iinfrastructure_server_acceptor& acceptor;
      data::dictionary::dictionary& dict;
};

/**
 * @brief The scu class handles all connections to a remote application entity.
 */
class scu: public Iupperlayer_connection_handlers
{
   public:
      scu(Iinfrastructure_client_acceptor& infr_scu,
          data::dictionary::dictionary& dict,
          a_associate_rq& rq);
      scu(const scu&) = delete;
      scu& operator=(const scu&) = delete;

      ~scu();

      /**
       * @brief run() instructs to client to start transmitting
       */
      virtual void run() override;

      /**
       * @brief accept_new starts a new association with the parameters
       *        specified in the constructor.
       */
      void accept_new(Iinfrastructure_upperlayer_connection* conn);

      void accept_new();

      virtual void new_connection(std::function<void(Iupperlayer_comm_ops*)> handler) override;
      virtual void end_connection(std::function<void(Iupperlayer_comm_ops*)> handler) override;

   private:
      void connection_end(Iinfrastructure_upperlayer_connection* conn);

      std::function<void(Iupperlayer_comm_ops*)> handler_new_connection;
      std::function<void(Iupperlayer_comm_ops*)> handler_end_connection;

      Iinfrastructure_client_acceptor& acceptor;

      std::map<Iinfrastructure_upperlayer_connection*, std::unique_ptr<scu_connection>> scus;
      a_associate_rq& request;
      data::dictionary::dictionary& dict;
};

}

}

}


#endif // UPPERLAYER_HPP
