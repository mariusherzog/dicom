#ifndef STORAGE_SCP_HPP
#define STORAGE_SCP_HPP

#include <string>
#include <functional>
#include <memory>

#include "network/upperlayer/upperlayer.hpp"
#include "network/dimse/dimse_pm.hpp"
#include "network/dimse/sop_class.hpp"
#include "network/dimse/association_definition.hpp"
#include "network/connection.hpp"
#include "serviceclass.hpp"

namespace dicom
{

namespace serviceclass
{

/**
 * @brief The storage_scp class implements a storage scp
 */
class storage_scp : public Iserviceclass
{
   public:
      storage_scp(dicom::network::connection endpoint,
                  dicom::data::dictionary::dictionary& dict,
                  std::function<void(storage_scp*, dicom::data::dataset::commandset_data, std::unique_ptr<dicom::data::dataset::iod>)> handler);

      ~storage_scp() override;

      virtual void run() override;

   private:
      void handle_cstore(dicom::network::dimse::dimse_pm* pm,
                         dicom::data::dataset::commandset_data command,
                         std::unique_ptr<dicom::data::dataset::iod> data);

      handlermap cstore_sop;

      dicom::data::dictionary::dictionary& dict;
      std::vector<dicom::network::dimse::SOP_class> sop_classes;
      dicom::network::dimse::association_definition assoc_def;
      dicom::network::upperlayer::scp scp;
      dicom::network::dimse::dimse_pm_manager dimse_pm;

      std::function<void(storage_scp*, dicom::data::dataset::commandset_data, std::unique_ptr<dicom::data::dataset::iod>)> handler;
};

}

}

#endif // STORAGE_SCP_HPP
