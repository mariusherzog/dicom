#include "asio_tcp_connection.hpp"


asio_tcp_server_acceptor::asio_tcp_server_acceptor(short port,
                                                   std::function<void(asio_tcp_connection*)> new_connection,
                                                   std::function<void(asio_tcp_connection*)> end_connection):
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
                                                   std::function<void (asio_tcp_connection *)> new_connection,
                                                   std::function<void (asio_tcp_connection *)> end_connection):
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

void asio_tcp_client_acceptor::accept_new_conn()
{
   accept_new();
}

//


asio_tcp_connection::asio_tcp_connection(boost::asio::io_service& ioservice,
                                         std::shared_ptr<boost::asio::ip::tcp::socket> sock,
                                         std::function<void(asio_tcp_connection*)> on_end_connection):
   io_s {ioservice},
   socket {sock},
   handler_end_connection {on_end_connection}
{

}

// boost::asio::buffer(data_offset, len)
void asio_tcp_connection::write_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                                     std::function<void (const boost::system::error_code&, std::size_t)> on_complete)
{
   boost::asio::async_write(*socket, boost::asio::buffer(*buffer), on_complete);
}

void asio_tcp_connection::write_data(void* data_offset, std::size_t len,
                                     std::function<void (const boost::system::error_code&, std::size_t)> on_complete)
{
   boost::asio::async_write(*socket, boost::asio::buffer(data_offset, len), on_complete);
}

void asio_tcp_connection::read_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                                    std::size_t len,
                                    std::function<void(const boost::system::error_code&, std::size_t)> on_complete)
{
   boost::asio::async_read(*socket, boost::asio::buffer(*buffer), boost::asio::transfer_exactly(len), on_complete);
}

void asio_tcp_connection::read_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                                    std::function<void(const boost::system::error_code&, std::size_t)> on_complete)
{
   boost::asio::async_read(*socket, boost::asio::buffer(*buffer), on_complete);
}





