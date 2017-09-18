#ifndef ASIO_TCP_CONNECTION_HPP
#define ASIO_TCP_CONNECTION_HPP

#include <boost/optional.hpp>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/log/trivial.hpp>

#include <functional>
#include <memory>
#include <chrono>

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
        boost::asio::ip::tcp::acceptor acptr;
};

class asio_tcp_client_acceptor
{
    public:
        asio_tcp_client_acceptor(std::string host, std::string port,
                                 std::function<void(asio_tcp_connection*)> new_connection,
                                 std::function<void(asio_tcp_connection*)> end_connection);

        void run();

        boost::asio::io_service& io_svc()
        {
            return io_s;
        }

        void accept_new_conn();

        std::function<void(asio_tcp_connection*)> handler_new;
        std::function<void(asio_tcp_connection*)> handler_end;

    private:
        void accept_new();

        std::vector<std::unique_ptr<asio_tcp_connection>> connections;

        boost::asio::io_service io_s;
        boost::asio::ip::tcp::resolver resolver;
        boost::asio::ip::tcp::resolver::query query;
        boost::asio::ip::tcp::resolver::iterator endpoint_iterator;
};


class timeout_connection
{
   public:
      timeout_connection(boost::asio::io_service& io_svc,
                         std::chrono::duration<int> timeout,
                         std::function<void()> on_timeout);

      void cancel();
      void wait_async();

   private:
      std::chrono::duration<int> timeout;
      std::function<void()> on_timeout;
      std::shared_ptr<boost::asio::steady_timer> timer;
};


// scx will take an instance of this class!
class asio_tcp_connection
{
   public:
      asio_tcp_connection(boost::asio::io_service& io_svc,
                          std::shared_ptr<boost::asio::ip::tcp::socket> sock,
                          std::function<void(asio_tcp_connection*)> on_end_connection);

      void write_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                      std::function<void(const boost::system::error_code&, std::size_t)> on_complete);

      void write_data(void* data_offset, std::size_t len,
                      std::function<void (const boost::system::error_code&, std::size_t)> on_complete);

      void read_data(std::shared_ptr<std::vector<unsigned char>> buffer, std::size_t len,
                     std::function<void(const boost::system::error_code&, std::size_t)> on_complete);

      void read_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                     std::function<void(const boost::system::error_code&, std::size_t)> on_complete);

      timeout_connection timeout_timer(std::chrono::duration<int> timeout,
                                       std::function<void()> on_timeout);


      boost::asio::io_service& io_svc()
      {
          return io_s;
      }

      bool is_stopped() const
      {
         return io_s.stopped();
      }

      void close()
      {
          io_s.post([this]() {
             socket->shutdown(boost::asio::ip::tcp::socket::shutdown_both);
             socket->close();
             handler_end_connection(this);
//             shutdown_requested = false;
          });
      }

    private:
      boost::asio::io_service& io_s;
      std::shared_ptr<boost::asio::ip::tcp::socket> socket;
      std::unique_ptr<boost::asio::steady_timer> timeout;

      std::function<void(asio_tcp_connection*)> handler_end_connection;
};

#endif // ASIO_TCP_CONNECTION_HPP
