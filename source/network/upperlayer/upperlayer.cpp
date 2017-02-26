#include "upperlayer.hpp"

#include "upperlayer_connection.hpp"

namespace dicom
{


namespace network
{


namespace upperlayer
{

Iupperlayer_connection_handlers::~Iupperlayer_connection_handlers()
{
}


scp::scp(data::dictionary::dictionary& dict,
         short port):
   io_service {},
   acptr {io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)},
   port {port},
   dict {dict}
{
   using namespace std::placeholders;
   auto socket = std::make_shared<boost::asio::ip::tcp::socket>(acptr.get_io_service());
   acptr.async_accept(*socket, [socket, this](boost::system::error_code ec) { accept_new(socket, ec); });
}

scp::~scp()
{
}

void scp::accept_new(std::shared_ptr<boost::asio::ip::tcp::socket> sock, boost::system::error_code ec)
{
   using namespace std::placeholders;
   if (!ec) {
      connections.push_back(std::unique_ptr<scp_connection>
         {
            new scp_connection {io_service, sock, dict, port, handler_new_connection, handler_end_connection}
         });
   } else {
      throw boost::system::system_error(ec);
   }
   auto newsock = std::make_shared<boost::asio::ip::tcp::socket>(acptr.get_io_service());
   acptr.async_accept(*newsock, [newsock, this](boost::system::error_code ec) { accept_new(newsock, ec); });
}

void scp::run()
{
   io_service.run();
}

void scp::new_connection(std::function<void(Iupperlayer_comm_ops*)> handler)
{
   handler_new_connection = handler;
}

void scp::end_connection(std::function<void(Iupperlayer_comm_ops*)> handler)
{
   handler_end_connection = [handler,this](Iupperlayer_comm_ops* conn) {
      handler(conn);
      for (auto& connection : connections) {
         if (connection.get() == conn) {
            connection.reset();
         }
      }
   };
}


scu::scu(data::dictionary::dictionary& dict,
         std::string host, std::string port,
         a_associate_rq& rq):
   io_service {},
   host {host},
   port {port},
   request {rq},
   dict {dict}
{
   using namespace std::placeholders;
}

scu::~scu()
{
}

void scu::accept_new()
{

   connections.push_back(std::unique_ptr<scu_connection>
   {
      new scu_connection {io_service, dict, host, port, request, handler_new_connection, handler_end_connection}
   });
}

void scu::run()
{
   accept_new();
   io_service.run();
}

void scu::new_connection(std::function<void(Iupperlayer_comm_ops*)> handler)
{
   handler_new_connection = handler;
}

void scu::end_connection(std::function<void(Iupperlayer_comm_ops*)> handler)
{
   handler_end_connection = [handler,this](Iupperlayer_comm_ops* conn) {
      handler(conn);
      for (auto& connection : connections) {
         if (connection.get() == conn) {
            connection.reset();
         }
      }
   };
}


}

}

}
