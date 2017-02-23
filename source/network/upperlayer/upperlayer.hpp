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
 * @brief The scp class acts as a service class provider
 */
class scp: public Iupperlayer_connection_handlers
{
   public:
      scp(data::dictionary::dictionary& dict,
          short port);
      scp(const scp&) = delete;
      scp& operator=(const scp&) = delete;

      ~scp();

      void run();

      virtual void new_connection(std::function<void(Iupperlayer_comm_ops*)> handler) override;
      virtual void end_connection(std::function<void(Iupperlayer_comm_ops*)> handler) override;

   private:

      void accept_new(std::shared_ptr<boost::asio::ip::tcp::socket>, boost::system::error_code);

      std::function<void(Iupperlayer_comm_ops*)> handler_new_connection;
      std::function<void(Iupperlayer_comm_ops*)> handler_end_connection;

      std::vector<std::unique_ptr<scp_connection>> connections;
      boost::asio::io_service io_service;
      boost::asio::ip::tcp::acceptor acptr;
      short port;
      data::dictionary::dictionary& dict;
};

}

}

}


#endif // UPPERLAYER_HPP
