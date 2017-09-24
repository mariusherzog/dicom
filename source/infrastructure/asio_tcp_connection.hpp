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
struct Iinfrastructure_upperlayer_connection;

class asio_tcp_server_acceptor
{
    public:
        asio_tcp_server_acceptor(short port,
                                 std::function<void(Iinfrastructure_upperlayer_connection*)> new_connection,
                                 std::function<void(Iinfrastructure_upperlayer_connection*)> end_connection);

        void run();

        boost::asio::io_service& io_svc()
        {
            return io_s;
        }

        std::function<void(Iinfrastructure_upperlayer_connection*)> handler_new;
        std::function<void(Iinfrastructure_upperlayer_connection*)> handler_end;

    private:
        void accept_new(std::shared_ptr<boost::asio::ip::tcp::socket> sock, boost::system::error_code ec);

        std::vector<std::unique_ptr<Iinfrastructure_upperlayer_connection>> connections;

        boost::asio::io_service io_s;
        boost::asio::ip::tcp::acceptor acptr;
};

class asio_tcp_client_acceptor
{
    public:
        asio_tcp_client_acceptor(std::string host, std::string port,
                                 std::function<void(Iinfrastructure_upperlayer_connection*)> new_connection,
                                 std::function<void(Iinfrastructure_upperlayer_connection*)> end_connection);

        void run();

        boost::asio::io_service& io_svc()
        {
            return io_s;
        }

        void accept_new_conn();

        std::function<void(Iinfrastructure_upperlayer_connection*)> handler_new;
        std::function<void(Iinfrastructure_upperlayer_connection*)> handler_end;

    private:
        void accept_new();

        std::vector<std::unique_ptr<Iinfrastructure_upperlayer_connection>> connections;

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


struct Iinfrastructure_upperlayer_connection
{

        virtual void write_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                        std::function<void(const boost::system::error_code&, std::size_t)> on_complete) = 0;

        virtual void write_data(void* data_offset, std::size_t len,
                        std::function<void (const boost::system::error_code&, std::size_t)> on_complete) = 0;

        virtual void read_data(std::shared_ptr<std::vector<unsigned char>> buffer, std::size_t len,
                       std::function<void(const boost::system::error_code&, std::size_t)> on_complete) = 0;

        virtual void read_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                       std::function<void(const boost::system::error_code&, std::size_t)> on_complete) = 0;

        virtual timeout_connection timeout_timer(std::chrono::duration<int> timeout,
                                         std::function<void()> on_timeout) = 0;

        virtual bool is_stopped() const = 0;

        virtual void close() = 0;

        virtual ~Iinfrastructure_upperlayer_connection() = 0;
};



// scx will take an instance of this class!
class asio_tcp_connection : public Iinfrastructure_upperlayer_connection
{
   public:
      asio_tcp_connection(boost::asio::io_service& io_svc,
                          std::shared_ptr<boost::asio::ip::tcp::socket> sock,
                          std::function<void(asio_tcp_connection*)> on_end_connection);

      void write_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                      std::function<void(const boost::system::error_code&, std::size_t)> on_complete) override;

      void write_data(void* data_offset, std::size_t len,
                      std::function<void (const boost::system::error_code&, std::size_t)> on_complete) override;

      void read_data(std::shared_ptr<std::vector<unsigned char>> buffer, std::size_t len,
                     std::function<void(const boost::system::error_code&, std::size_t)> on_complete) override;

      void read_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                     std::function<void(const boost::system::error_code&, std::size_t)> on_complete) override;

      timeout_connection timeout_timer(std::chrono::duration<int> timeout,
                                       std::function<void()> on_timeout) override;


      boost::asio::io_service& io_svc()
      {
          return io_s;
      }

      bool is_stopped() const override
      {
         return io_s.stopped();
      }

      void close() override
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
