#ifndef STORAGE_SCP_HPP
#define STORAGE_SCP_HPP

#include <string>
#include <functional>
#include <memory>

#include "network/upperlayer/upperlayer.hpp"
#include "network/dimse/dimse_pm.hpp"
#include "network/dimse/sop_class.hpp"
#include "network/dimse/association_definition.hpp"
#include "serviceclass.hpp"


/**
 * @brief The storage_scp class implements a storage scp
 */
class storage_scp : public Iserviceclass
{
   public:
      storage_scp(std::string calling_ae, std::string called_ae,
                  int max_message_len, dicom::data::dictionary::dictionary& dict,
                  std::function<void(storage_scp*, dicom::data::dataset::commandset_data, std::unique_ptr<dicom::data::dataset::iod>)> handler);

      ~storage_scp() override;

      virtual void run() override;

   private:
      void handle_cstore(dicom::network::dimse::dimse_pm* pm,
                         dicom::data::dataset::commandset_data command,
                         std::unique_ptr<dicom::data::dataset::iod> data);

      dicom::data::dictionary::dictionary& dict;
      dicom::network::dimse::SOP_class sop_class;
      dicom::network::dimse::association_definition assoc_def;
      dicom::network::upperlayer::scp scp;
      dicom::network::dimse::dimse_pm_manager dimse_pm;

      std::function<void(storage_scp*, dicom::data::dataset::commandset_data, std::unique_ptr<dicom::data::dataset::iod>)> handler;
};

#endif // STORAGE_SCP_HPP
