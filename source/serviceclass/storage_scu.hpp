#ifndef STORAGE_SCU_HPP
#define STORAGE_SCU_HPP

#include <string>
#include <functional>

#include "network/upperlayer/upperlayer.hpp"
#include "network/dimse/dimse_pm.hpp"
#include "network/dimse/sop_class.hpp"
#include "network/dimse/association_definition.hpp"
#include "serviceclass.hpp"


class storage_scu : public Iserviceclass
{
   public:
      storage_scu(std::string calling_ae, std::string called_ae,
                  int max_message_len, dicom::data::dictionary::dictionary& dict,
                  std::function<void(storage_scu*, dicom::data::dataset::commandset_data, std::unique_ptr<dicom::data::dataset::iod>)> handler);

      ~storage_scu();

      void send_next_request(dicom::data::dataset::iod data);

      void release();

      virtual void run() override;

   private:
      dicom::network::dimse::SOP_class sop_class;
      dicom::network::dimse::SOP_class sop_class_response;
      dicom::network::dimse::association_definition assoc_def;
      dicom::network::upperlayer::a_associate_rq initial_rq;
      dicom::network::upperlayer::scu scu;
      dicom::network::dimse::dimse_pm_manager dimse_pm;

      dicom::data::dataset::iod senddata;

      void send_store_request(dicom::network::dimse::dimse_pm* pm,
                              dicom::data::dataset::commandset_data command,
                              std::unique_ptr<dicom::data::dataset::iod> data);

      std::function<void(storage_scu*, dicom::data::dataset::commandset_data, std::unique_ptr<dicom::data::dataset::iod>)> handler;

      bool do_release;
};

#endif // STORAGE_SCU_HPP
