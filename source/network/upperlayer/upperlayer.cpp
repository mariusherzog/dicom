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
}

scp::~scp()
{
}

void scp::accept_new(asio_tcp_connection* conn)
{
   scps[conn] = std::unique_ptr<scp_connection> {new scp_connection(conn, dict, port, handler_new_connection, handler_end_connection)};
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
   handler_end_connection = handler;
}


scu::scu(data::dictionary::dictionary& dict,
         std::string host, std::string port,
         a_associate_rq& rq):
   acceptor {new asio_tcp_client_acceptor(host, port, nullptr, nullptr)},
   host {host},
   port {port},
   request {rq},
   dict {dict}
{
   using namespace std::placeholders;
   acceptor->handler_new = [this](asio_tcp_connection* conn) { accept_new(conn);};
   acceptor->handler_end = [this](asio_tcp_connection* conn) { connection_end(conn);};
}

scu::~scu()
{
}

void scu::accept_new(asio_tcp_connection* conn)
{
//   connections.push_back(std::unique_ptr<scu_connection>
//   {
//      new scu_connection {conn, conn->io_svc(), dict, request, handler_new_connection, handler_end_connection}
//   });
   scus[conn] = std::unique_ptr<scu_connection> {new scu_connection {conn, dict, request, handler_new_connection, handler_end_connection}};
}

void scu::accept_new()
{
   acceptor->accept_new_conn();
}

void scu::connection_end(asio_tcp_connection* conn)
{
   auto& sc = scus.at(conn);
   handler_end_connection(sc.get());
   //sc->reset();
   scus.erase(conn);
}

void scu::run()
{
   acceptor->run();
}

void scu::new_connection(std::function<void(Iupperlayer_comm_ops*)> handler)
{
   handler_new_connection = handler;
}

void scu::end_connection(std::function<void(Iupperlayer_comm_ops*)> handler)
{
   handler_end_connection = handler;
}


}

}

}
