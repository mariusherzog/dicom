#ifndef ASIO_TCP_CONNECTION_MANAGER_HPP
#define ASIO_TCP_CONNECTION_MANAGER_HPP

#include "asio_tcp_connection.hpp"

class asio_tcp_server_acceptor
{
    public:
        asio_tcp_server_acceptor(short port,
                                 std::function<void(Iinfrastructure_upperlayer_connection*)> new_connection,
                                 std::function<void(Iinfrastructure_upperlayer_connection*)> end_connection);

        void run();

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
#endif // ASIO_TCP_CONNECTION_MANAGER_HPP
