#ifndef SERVICECLASS_HPP
#define SERVICECLASS_HPP

#include "network/dimse/dimse_pm.hpp"
#include "network/dimse/association_definition.hpp"

namespace dicom
{

namespace serviceclass
{

/**
 * @brief The serviceclass interface contains all common operations performed
 *        with a concrete service class
 */
class Iserviceclass
{
   public:
      virtual ~Iserviceclass() = 0;

      /**
       * @brief run starts listening as scp or initiates contact as scu
       */
      virtual void run() = 0;
};

using handlermap = std::map<dicom::data::dataset::DIMSE_SERVICE_GROUP,
std::function<void(dicom::network::dimse::dimse_pm* pm, dicom::data::dataset::commandset_data cdata, std::unique_ptr<dicom::data::dataset::iod> data)>>;

}


}

#endif // SERVICECLASS_HPP
