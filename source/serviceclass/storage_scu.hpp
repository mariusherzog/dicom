#ifndef STORAGE_SCU_HPP
#define STORAGE_SCU_HPP

#include <string>
#include <functional>

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

class storage_scu : public Iserviceclass
{
   public:
      storage_scu(dicom::network::connection endpoint,
                  dicom::data::dictionary::dictionaries& dict,
                  std::function<void(storage_scu*, dicom::data::dataset::commandset_data, std::unique_ptr<dicom::data::dataset::iod>)> handler);

      ~storage_scu();

      /**
       * @brief send_next_request starts a new association on the connection
       *        defined in the ctor
       * @param data data to be sent
       */
      void send_next_request(dicom::data::dataset::iod data);

      /**
       * @brief set_store_data shall be called from the handler and sets the
       *        iod transmitted next
       * @param data iod transmitted next
       */
      void set_store_data(dicom::data::dataset::iod data)
      {
         senddata = data;
      }

      /**
       * @brief release sends a release request
       */
      void release();

      virtual void run() override;

   private:
      handlermap cstore_req;
      handlermap cstore_resp;

      std::vector<dicom::network::dimse::SOP_class> sop_classes;
      std::vector<dicom::network::dimse::SOP_class> sop_classes_response;
      dicom::network::dimse::association_definition assoc_def;
      dicom::network::upperlayer::a_associate_rq initial_rq;
      asio_tcp_client_acceptor infr_scu;
      dicom::network::upperlayer::scu scu;
      dicom::network::dimse::dimse_pm_manager dimse_pm;

      dicom::data::dataset::iod senddata;

      void send_store_request(dicom::network::dimse::dimse_pm* pm,
                              dicom::data::dataset::commandset_data command,
                              std::unique_ptr<dicom::data::dataset::iod> data);

      std::function<void(storage_scu*, dicom::data::dataset::commandset_data, std::unique_ptr<dicom::data::dataset::iod>)> handler;

      bool do_release;
};

}

}

#endif // STORAGE_SCU_HPP
