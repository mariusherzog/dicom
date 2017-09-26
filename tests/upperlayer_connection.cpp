#include "catch.hpp"

#include <string>
#include <exception>

#include "stubs/infrastructure_connection_stub.hpp"
#include "../source/data/dictionary/dictionary.hpp"
#include "../source/network/upperlayer/upperlayer_connection.hpp"

using namespace dicom::network::upperlayer;

// Change this scenario description later
SCENARIO("Usage of the upperlayer")
{
   infrastructure_read_connection_stub stub("scp.bin");
   dicom::data::dictionary::dictionary dict {"commanddictionary.csv", "datadictionary.csv"};

   std::function<void(Iupperlayer_comm_ops*)> handler_new_conn = [](Iupperlayer_comm_ops*) {};
   std::function<void(Iupperlayer_comm_ops*)> handler_end_conn = [](Iupperlayer_comm_ops*) {};

   dicom::network::upperlayer::scp_connection scp {&stub, dict, 0, handler_new_conn, handler_end_conn};

}


