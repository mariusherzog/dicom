#include "asio_tcp_connection_manager.hpp"


Iinfrastructure_server_acceptor::~Iinfrastructure_server_acceptor()
{

}

Iinfrastructure_client_acceptor::~Iinfrastructure_client_acceptor()
{

}


asio_tcp_server_acceptor::asio_tcp_server_acceptor(short port,
                                                   std::function<void(Iinfrastructure_upperlayer_connection*)> new_connection,
                                                   std::function<void(Iinfrastructure_upperlayer_connection*)> end_connection):
   handler_new {new_connection},
   handler_end {end_connection},
   io_s {},
   acptr {io_s, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)}
{
   using namespace std::placeholders;
   auto socket = std::make_shared<boost::asio::ip::tcp::socket>(acptr.get_io_service());
   acptr.async_accept(*socket, [socket, this](boost::system::error_code ec) { accept_new(socket, ec); });
}

void asio_tcp_server_acceptor::run()
{
   io_s.run();
}

void asio_tcp_server_acceptor::set_handler_new(std::function<void(Iinfrastructure_upperlayer_connection*)> handler)
{
   handler_new = handler;
}

void asio_tcp_server_acceptor::set_handler_end(std::function<void (Iinfrastructure_upperlayer_connection *)> handler)
{
   handler_end = handler;
}

void asio_tcp_server_acceptor::accept_new(std::shared_ptr<boost::asio::ip::tcp::socket> sock, boost::system::error_code ec)
{
   using namespace std::placeholders;
   if (!ec) {
      connections.push_back(std::unique_ptr<asio_tcp_connection>
         {
            new asio_tcp_connection {io_s, sock, handler_end}
         });
   } else {
      throw boost::system::system_error(ec);
   }

   handler_new(connections.back().get());

   auto newsock = std::make_shared<boost::asio::ip::tcp::socket>(acptr.get_io_service());
   acptr.async_accept(*newsock, [newsock, this](boost::system::error_code ec) { accept_new(newsock, ec); });
}

//

asio_tcp_client_acceptor::asio_tcp_client_acceptor(std::string host, std::string port,
                                                   std::function<void(Iinfrastructure_upperlayer_connection*)> new_connection,
                                                   std::function<void(Iinfrastructure_upperlayer_connection*)> end_connection):
   handler_new {new_connection},
   handler_end {end_connection},
   io_s {},
   resolver {io_s},
   query {host, port},
   endpoint_iterator {resolver.resolve(query)}
{

}

void asio_tcp_client_acceptor::accept_new()
{
   auto socket = std::make_shared<boost::asio::ip::tcp::socket>(io_s);
   boost::asio::ip::tcp::resolver::iterator end;
   boost::system::error_code error = boost::asio::error::host_not_found;
   while(error && endpoint_iterator != end)
   {
     socket->close();
     socket->connect(*endpoint_iterator++, error);
   }
   connections.emplace_back(new asio_tcp_connection(io_s, socket, handler_end));

   handler_new(connections.back().get());
}

void asio_tcp_client_acceptor::run()
{
   accept_new();
   io_s.run();
}

void asio_tcp_client_acceptor::set_handler_new(std::function<void(Iinfrastructure_upperlayer_connection*)> handler)
{
   handler_new = handler;
}

void asio_tcp_client_acceptor::set_handler_end(std::function<void (Iinfrastructure_upperlayer_connection *)> handler)
{
   handler_end = handler;
}

void asio_tcp_client_acceptor::accept_new_conn()
{
   accept_new();
}
