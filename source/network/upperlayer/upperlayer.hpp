#ifndef UPPERLAYER_HPP
#define UPPERLAYER_HPP

#include <functional>
#include <memory>

#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/log/trivial.hpp>

#include "upperlayer_connection.hpp"
#include "data/dictionary/dictionary.hpp"


namespace dicom
{


namespace network
{


namespace upperlayer
{


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

      virtual ~Iupperlayer_connection_handlers() = 0;
};


/**
 * @brief The scp class acts as a service class provider which can have
 *        and manages multiple connections simultaneously.
 */
class scp: public Iupperlayer_connection_handlers
{
   public:
      scp(data::dictionary::dictionary& dict,
          short port);
      scp(const scp&) = delete;
      scp& operator=(const scp&) = delete;

      ~scp();

      /**
       * @brief run() instructs the server to start listening for associations
       */
      void run();

      virtual void new_connection(std::function<void(Iupperlayer_comm_ops*)> handler) override;
      virtual void end_connection(std::function<void(Iupperlayer_comm_ops*)> handler) override;

   private:

      void accept_new(std::shared_ptr<boost::asio::ip::tcp::socket>, boost::system::error_code);

      std::function<void(Iupperlayer_comm_ops*)> handler_new_connection;
      std::function<void(Iupperlayer_comm_ops*)> handler_end_connection;

      std::vector<std::unique_ptr<scp_connection>> connections;
      boost::asio::io_service& io_service;
      boost::asio::ip::tcp::acceptor acptr;
      short port;
      data::dictionary::dictionary& dict;
};

/**
 * @brief The scu class
 */
class scu: public Iupperlayer_connection_handlers
{
   public:
      scu(data::dictionary::dictionary& dict,
          std::string host, std::string port,
          a_associate_rq& rq);
      scu(const scu&) = delete;
      scu& operator=(const scu&) = delete;

      ~scu();

      /**
       * @brief run() instructs to client to start transmitting
       */
      void run();

      /**
       * @brief accept_new starts a new association with the parameters
       *        specified in the constructor.
       */
      void accept_new();

      virtual void new_connection(std::function<void(Iupperlayer_comm_ops*)> handler) override;
      virtual void end_connection(std::function<void(Iupperlayer_comm_ops*)> handler) override;

   private:
      std::function<void(Iupperlayer_comm_ops*)> handler_new_connection;
      std::function<void(Iupperlayer_comm_ops*)> handler_end_connection;

      std::vector<std::unique_ptr<scu_connection>> connections;
      boost::asio::io_service& io_service;
      std::string host;
      std::string port;
      a_associate_rq& request;
      data::dictionary::dictionary& dict;
};

}

}

}


#endif // UPPERLAYER_HPP
