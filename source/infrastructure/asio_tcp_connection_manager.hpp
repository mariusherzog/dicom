#ifndef ASIO_TCP_CONNECTION_MANAGER_HPP
#define ASIO_TCP_CONNECTION_MANAGER_HPP

#include "asio_tcp_connection.hpp"


/**
 * @brief The Iinfrastructure_server_acceptor interface represents the functionality
 *        used by an scp to accept new connections and be notified when one ends.
 * TODO: To facilitate DIP this should be moved to where it is actually used
 */
struct Iinfrastructure_server_acceptor
{
      /**
       * @brief run starts the process, for a TCP socket this would start
       *        listening.
       */
      virtual void run() = 0;

      /**
       * @brief set_handler_new sets the callback to be invoked for a new
       *        connection
       * @param handler callback to be invoked
       */
      virtual void set_handler_new(std::function<void(Iinfrastructure_upperlayer_connection*)> handler) = 0;

      /**
       * @brief set_handler_end sets the callback to be invoked when a
       *        connection terminates
       * @param handler callback to be invoked
       */
      virtual void set_handler_end(std::function<void(Iinfrastructure_upperlayer_connection*)> handler) = 0;

      virtual ~Iinfrastructure_server_acceptor() = 0;
};

/**
 * @brief The Iinfrastructure_client_acceptor interface abstracts functionality
 *        used by an scu to start a new connection and be notified when one
 *        ends.
 * TODO: To facilitate DIP this should be moved to where it is actually used
 */
struct Iinfrastructure_client_acceptor
{
      /**
       * @brief run starts the connection
       */
      virtual void run() = 0;

      /**
       * @brief set_handler_new sets the callback to be invoked for a new
       *        connection
       * @param handler callback to be invoked
       */
      virtual void set_handler_new(std::function<void(Iinfrastructure_upperlayer_connection*)> handler) = 0;

      /**
       * @brief set_handler_end sets the callback to be invoked when a
       *        connection terminates
       * @param handler callback to be invoked
       */
      virtual void set_handler_end(std::function<void(Iinfrastructure_upperlayer_connection*)> handler) = 0;

      /**
       * @brief accept_new_conn invokes a new connection as a client
       */
      virtual void accept_new_conn() = 0;

      virtual ~Iinfrastructure_client_acceptor() = 0;
};

/**
 * @brief The asio_tcp_server_acceptor class encapsulates functionality to
 *        accept tcp connection as a server using boost asio.
 */
class asio_tcp_server_acceptor : public Iinfrastructure_server_acceptor
{
    public:
        asio_tcp_server_acceptor(short port,
                                 std::function<void(Iinfrastructure_upperlayer_connection*)> new_connection,
                                 std::function<void(Iinfrastructure_upperlayer_connection*)> end_connection);

        void run() override;

        void set_handler_new(std::function<void(Iinfrastructure_upperlayer_connection*)> handler) override;

        void set_handler_end(std::function<void(Iinfrastructure_upperlayer_connection*)> handler) override;


    private:
        void accept_new(std::shared_ptr<boost::asio::ip::tcp::socket> sock, boost::system::error_code ec);

        std::vector<std::unique_ptr<Iinfrastructure_upperlayer_connection>> connections;

        std::function<void(Iinfrastructure_upperlayer_connection*)> handler_new;
        std::function<void(Iinfrastructure_upperlayer_connection*)> handler_end;

        boost::asio::io_service io_s;
        boost::asio::ip::tcp::acceptor acptr;
};

/**
 * @brief The asio_tcp_client_acceptor class encapsulates functionality to
 *        start new tcp connections to a remote peer as a client, using boost
 *        asio.
 */
class asio_tcp_client_acceptor : public Iinfrastructure_client_acceptor
{
    public:
        asio_tcp_client_acceptor(std::string host, std::string port,
                                 std::function<void(Iinfrastructure_upperlayer_connection*)> new_connection,
                                 std::function<void(Iinfrastructure_upperlayer_connection*)> end_connection);

        void run() override;

        void set_handler_new(std::function<void(Iinfrastructure_upperlayer_connection*)> handler) override;

        void set_handler_end(std::function<void(Iinfrastructure_upperlayer_connection*)> handler) override;

        void accept_new_conn() override;

    private:
        void accept_new();

        std::vector<std::unique_ptr<Iinfrastructure_upperlayer_connection>> connections;

        std::function<void(Iinfrastructure_upperlayer_connection*)> handler_new;
        std::function<void(Iinfrastructure_upperlayer_connection*)> handler_end;

        boost::asio::io_service io_s;
        boost::asio::ip::tcp::resolver resolver;
        boost::asio::ip::tcp::resolver::query query;
        boost::asio::ip::tcp::resolver::iterator endpoint_iterator;
};
#endif // ASIO_TCP_CONNECTION_MANAGER_HPP
