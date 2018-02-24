#ifndef UID_HPP
#define UID_HPP

#include <string>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace dicom
{

namespace util
{

class uid
{
   public:
      uid(std::string prefix = "999.999");

      std::string generate_uid(std::string suffix = "");

    private:
      const std::string prefix;
      boost::uuids::random_generator generator;
};

}

}

#endif // UID_HPP
