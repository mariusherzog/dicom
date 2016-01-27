#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <memory>

#include "data/dataset/iod.hpp"
#include "data/dataset/commandset_data.hpp"

namespace dicom
{

namespace network
{

namespace dimse
{

/**
 * @brief The response class is used by the user-specified handlers for each
 *        Service Group used in the SOP to prompt the dimse protocol machine
 *        to send a response.
 */
class response
{
   public:
      /**
       * @brief response constructor for the response
       * @param dsg service group of the response
       * @param data optional; pointer owning response iod data
       * @param status optional; status indication, SUCCESS by default
       * @param prio optional; priority of the response, MEDIUM by default
       */
      response(data::dataset::DIMSE_SERVICE_GROUP dsg,
               std::unique_ptr<data::dataset::iod> data = nullptr,
               data::dataset::STATUS status = data::dataset::STATUS::SUCCESS,
               data::dataset::DIMSE_PRIORITY prio = data::dataset::DIMSE_PRIORITY::MEDIUM
               );

      data::dataset::DIMSE_SERVICE_GROUP get_response_type();
      std::unique_ptr<data::dataset::iod>& get_data();
      data::dataset::STATUS get_status();
      data::dataset::DIMSE_PRIORITY get_priority();


   private:
      data::dataset::DIMSE_SERVICE_GROUP response_type;
      std::unique_ptr<data::dataset::iod> data;
      data::dataset::STATUS status;
      data::dataset::DIMSE_PRIORITY prio;
};

}

}

}

#endif // RESPONSE_HPP
