#include "asio_tcp_connection.hpp"



asio_tcp_connection::asio_tcp_connection(boost::asio::io_service& ioservice,
                                         boost::asio::ip::tcp::socket& sock):
   io_s {ioservice},
   socket {sock}
{

}

void asio_tcp_connection::write_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                                     std::function<void (const boost::system::error_code&, std::size_t)> on_complete)
{
   boost::asio::async_write(socket, boost::asio::buffer(*buffer), on_complete);
}
