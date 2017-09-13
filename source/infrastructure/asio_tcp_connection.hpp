#ifndef ASIO_TCP_CONNECTION_HPP
#define ASIO_TCP_CONNECTION_HPP

#include <boost/optional.hpp>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/log/trivial.hpp>

#include <functional>
#include <memory>

class asio_tcp_connection;

class asio_tcp_server_acceptor
{
    public:
        asio_tcp_server_acceptor(short port,
                                 std::function<void(asio_tcp_connection*)> new_connection,
                                 std::function<void(asio_tcp_connection*)> end_connection);

        void run();

        boost::asio::io_service& io_svc()
        {
            return io_s;
        }

        std::function<void(asio_tcp_connection*)> handler_new;
        std::function<void(asio_tcp_connection*)> handler_end;

    private:
        void accept_new(std::shared_ptr<boost::asio::ip::tcp::socket> sock, boost::system::error_code ec);

        std::vector<std::unique_ptr<asio_tcp_connection>> connections;

        boost::asio::io_service io_s;
        //boost::asio::ip::tcp::socket socket;
        boost::asio::ip::tcp::acceptor acptr;
};


// scx will take an instance of this class!
class asio_tcp_connection
{
   public:
      asio_tcp_connection(boost::asio::io_service& ioservice, std::shared_ptr<boost::asio::ip::tcp::socket> sock);

      void write_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                      std::function<void(const boost::system::error_code&, std::size_t)> on_complete);

      void read_data(std::shared_ptr<std::vector<unsigned char>> buffer, std::size_t len,
                     std::function<void(const boost::system::error_code&, std::size_t)> on_complete);

      void read_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                     std::function<void(const boost::system::error_code&, std::size_t)> on_complete);

      boost::asio::io_service& io_svc()
      {
          return io_s;
      }

      void close()
      {
          io_s.post([this]() {
             socket->shutdown(boost::asio::ip::tcp::socket::shutdown_both);
             socket->close();
//             handler_end_connection(this);
//             shutdown_requested = false;
          });
      }

    private:
      boost::asio::io_service& io_s;
      std::shared_ptr<boost::asio::ip::tcp::socket> socket;
};

#endif // ASIO_TCP_CONNECTION_HPP
