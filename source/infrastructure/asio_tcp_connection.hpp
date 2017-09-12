#ifndef ASIO_TCP_CONNECTION_HPP
#define ASIO_TCP_CONNECTION_HPP

#include <boost/optional.hpp>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/log/trivial.hpp>

#include <functional>
#include <memory>


class asio_tcp_connection
{
   public:
      asio_tcp_connection(boost::asio::io_service& ioservice, boost::asio::ip::tcp::socket& sock);

      void write_data(std::shared_ptr<std::vector<unsigned char>> buffer,
                      std::function<void(const boost::system::error_code&, std::size_t)> on_complete);

    private:
      boost::asio::io_service& io_s;
      boost::asio::ip::tcp::socket& socket;
};

#endif // ASIO_TCP_CONNECTION_HPP
