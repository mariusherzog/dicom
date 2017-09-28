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


scp::scp(Iinfrastructure_server_acceptor& infrstr_scp,
         data::dictionary::dictionary& dict):
   acceptor {infrstr_scp},
   dict {dict}
{
   acceptor.set_handler_new([this](Iinfrastructure_upperlayer_connection* conn) { accept_new(conn);});
   acceptor.set_handler_end([this](Iinfrastructure_upperlayer_connection* conn) { connection_end(conn);});
}

scp::~scp()
{
}

void scp::accept_new(Iinfrastructure_upperlayer_connection* conn)
{
   scps[conn] = std::unique_ptr<scp_connection> {new scp_connection(conn, dict, port, handler_new_connection, handler_end_connection)};
}

void scp::connection_end(Iinfrastructure_upperlayer_connection* conn)
{
   auto& sc = scps.at(conn);
   handler_end_connection(sc.get());
   //sc->reset();
   scps.erase(conn);
}

void scp::run()
{
   acceptor.run();
}

void scp::new_connection(std::function<void(Iupperlayer_comm_ops*)> handler)
{
   handler_new_connection = handler;
}

void scp::end_connection(std::function<void(Iupperlayer_comm_ops*)> handler)
{
   handler_end_connection = handler;
}


scu::scu(Iinfrastructure_client_acceptor& infr_scu,
         data::dictionary::dictionary& dict,
         a_associate_rq& rq):
   acceptor {infr_scu},
   request {rq},
   dict {dict}
{
   using namespace std::placeholders;
   acceptor.set_handler_new([this](Iinfrastructure_upperlayer_connection* conn) { accept_new(conn);});
   acceptor.set_handler_end([this](Iinfrastructure_upperlayer_connection* conn) { connection_end(conn);});
}

scu::~scu()
{
}

void scu::accept_new(Iinfrastructure_upperlayer_connection* conn)
{
   scus[conn] = std::unique_ptr<scu_connection> {new scu_connection {conn, dict, request, handler_new_connection, handler_end_connection}};
}

void scu::accept_new()
{
   acceptor.accept_new_conn();
}

void scu::connection_end(Iinfrastructure_upperlayer_connection* conn)
{
   auto& sc = scus.at(conn);
   handler_end_connection(sc.get());
   //sc->reset();
   scus.erase(conn);
}

void scu::run()
{
   acceptor.run();
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
