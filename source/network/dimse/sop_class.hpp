#ifndef SOP_CLASS_HPP
#define SOP_CLASS_HPP

#include <string>
#include <vector>
#include <map>
#include <set>
#include <initializer_list>
#include <memory>
#include <functional>

#include "response.hpp"
#include "data/dataset/datasets.hpp"

namespace dicom
{

namespace network
{

namespace dimse
{

class dimse_pm;

/**
 * @brief The SOP_class class represents a Service-Object-Pair and respective
 *        operations to be performed upon them.
 * @see DICOM standard chapter 3.7, Annex D.1.
 *
 * Each SOP class consists of multiple operations (DIMSE Service Groups) that
 * operate on a specific iod on which they operate. In the context of an
 * association between two peers, the SOP class UID is used as the abstract
 * syntax name.
 */
class SOP_class
{
   public:      
      SOP_class(std::string SOP_class_UID,
                std::map<data::dataset::DIMSE_SERVICE_GROUP,
                  std::function<void(dimse_pm* pm, data::dataset::commandset_data cdata, std::unique_ptr<data::dataset::iod> data)>> handler);

      /**
       * @brief operator() is called by the DIMSE protocol machine to notify the
       *        performing DIMSE service user.
       * @param op DSG of the operation
       * @param data data received by the protocol machine
       */
      void operator()(dimse_pm* pm, data::dataset::DIMSE_SERVICE_GROUP op,
                          data::dataset::commandset_data cdata,
                          std::unique_ptr<data::dataset::iod> data) const;

      std::string get_SOP_class_UID() const;

      /**
       * @brief get_service_groups retrieves the service groups defined for this
       *        instance's SOP.
       * @return set of service groups associated to the SOP
       */
      std::set<data::dataset::DIMSE_SERVICE_GROUP> get_service_groups() const;

   private:
      const std::string sop_uid;
      const std::map<data::dataset::DIMSE_SERVICE_GROUP,
         std::function<void(dimse_pm* pm, data::dataset::commandset_data cdata, std::unique_ptr<data::dataset::iod> data)>> operations;

};

}

}

}

#endif // SOP_CLASS_HPP
