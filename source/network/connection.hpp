#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <string>

namespace dicom
{

namespace network
{

/**
 * @brief The connection struct defines a dicom endpoint, consisting of local
 *        and remote AE title, host (ip) and port.
 * For SCPs, host will be ignored
 */
struct connection
{
   public:
      connection(std::string calling_ae,
                 std::string called_ae,
                 std::string host,
                 short port = 104);

      connection();

      std::string calling_ae;
      std::string called_ae;

      std::string host;
      short port;

};

}

}

#endif // CONNECTION_HPP
