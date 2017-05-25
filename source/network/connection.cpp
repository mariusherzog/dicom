#include "connection.hpp"

namespace dicom
{

namespace network
{

connection::connection(std::string calling_ae,
                       std::string called_ae,
                       std::string host,
                       short port):
   calling_ae {calling_ae},
   called_ae {called_ae},
   host {host},
   port {port}
{
}

connection::connection():
   connection("", "", "")
{

}

}

}
