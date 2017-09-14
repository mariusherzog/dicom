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
//   io_service {},
//   acptr {io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)},
   connection {new asio_tcp_server_acceptor(port, nullptr, nullptr)},
   port {port},
   dict {dict}
{
   connection->handler_new = [this](asio_tcp_connection* conn) { accept_new(conn);};
//   using namespace std::placeholders;
//   auto socket = std::make_shared<boost::asio::ip::tcp::socket>(acptr.get_io_service());
//   acptr.async_accept(*socket, [socket, this](boost::system::error_code ec) { accept_new(socket, ec); });
}

scp::~scp()
{
}

void scp::accept_new(asio_tcp_connection* conn)
{
//   using namespace std::placeholders;
//   if (!ec) {
//      connections.push_back(std::unique_ptr<scp_connection>
//         {
//            new scp_connection {io_service, sock, dict, port, handler_new_connection, handler_end_connection}
//         });
//   } else {
//      throw boost::system::system_error(ec);
//   }
//   auto newsock = std::make_shared<boost::asio::ip::tcp::socket>(acptr.get_io_service());
//   acptr.async_accept(*newsock, [newsock, this](boost::system::error_code ec) { accept_new(newsock, ec); });
   scps[conn] = std::unique_ptr<scp_connection> {new scp_connection(conn, conn->io_svc(), dict, port, handler_new_connection, handler_end_connection)};
}

void scp::run()
{
   connection->run();
}

void scp::new_connection(std::function<void(Iupperlayer_comm_ops*)> handler)
{
   handler_new_connection = handler;
}

void scp::end_connection(std::function<void(Iupperlayer_comm_ops*)> handler)
{
//   handler_end_connection = [handler,this](Iupperlayer_comm_ops* conn) {
//      handler(conn);
//      for (auto& connection : connections) {
//         if (connection.get() == conn) {
//            connection.reset();
//         }
//      }
//   };
}


scu::scu(data::dictionary::dictionary& dict,
         std::string host, std::string port,
         a_associate_rq& rq):
//   io_service {},
   connection {new asio_tcp_client_acceptor(host, port, nullptr, nullptr)},
   host {host},
   port {port},
   request {rq},
   dict {dict}
{
   using namespace std::placeholders;
   connection->handler_new = [this](asio_tcp_connection* conn) { accept_new(conn);};
}

scu::~scu()
{
}

void scu::accept_new(asio_tcp_connection* conn)
{
//   connections.push_back(std::unique_ptr<scu_connection>
//   {
//      new scu_connection {io_service, dict, host, port, request, handler_new_connection, handler_end_connection}
//   });
   connections.push_back(std::unique_ptr<scu_connection>
   {
      new scu_connection {conn, conn->io_svc(), dict, request, handler_new_connection, handler_end_connection}
   });
}

void scu::accept_new()
{
   connection->accept_new_conn();
}

void scu::run()
{
//   accept_new();
//   io_service.run();
   connection->run();
}

void scu::new_connection(std::function<void(Iupperlayer_comm_ops*)> handler)
{
   handler_new_connection = handler;
}

void scu::end_connection(std::function<void(Iupperlayer_comm_ops*)> handler)
{
//   handler_end_connection = [handler,this](Iupperlayer_comm_ops* conn) {
//      handler(conn);
//      for (auto& connection : connections) {
//         if (connection.get() == conn) {
//            connection.reset();
//         }
//      }
//   };
}


}

}

}
