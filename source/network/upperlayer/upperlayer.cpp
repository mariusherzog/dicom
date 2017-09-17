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
   acceptor {new asio_tcp_server_acceptor(port, nullptr, nullptr)},
   port {port},
   dict {dict}
{
   acceptor->handler_new = [this](asio_tcp_connection* conn) { accept_new(conn);};
   acceptor->handler_end = [this](asio_tcp_connection* conn) { connection_end(conn);};
//   connection->handler_end = [this](asio_tcp_connection* conn)
//   {
//      handler_end_connection(conn);
//   };
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

void scp::connection_end(asio_tcp_connection* conn)
{
   auto& sc = scps.at(conn);
   handler_end_connection(sc.get());
   //sc->reset();
   scps.erase(conn);
}

void scp::run()
{
   acceptor->run();
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
   handler_end_connection = handler;
}


scu::scu(data::dictionary::dictionary& dict,
         std::string host, std::string port,
         a_associate_rq& rq):
//   io_service {},
   acceptor {new asio_tcp_client_acceptor(host, port, nullptr, nullptr)},
   host {host},
   port {port},
   request {rq},
   dict {dict}
{
   using namespace std::placeholders;
   acceptor->handler_new = [this](asio_tcp_connection* conn) { accept_new(conn);};
   acceptor->handler_end = [this](asio_tcp_connection* conn)
   {
      //handler_end_connection(conn);
   };
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
   acceptor->accept_new_conn();
}

void scu::run()
{
//   accept_new();
//   io_service.run();
   acceptor->run();
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
