#ifndef FIND_SCU_HPP
#define FIND_SCU_HPP

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

class find_scu : public Iserviceclass
{
   public:
      find_scu(dicom::network::connection endpoint,
               dicom::data::dictionary::dictionaries& dict,
               std::function<void(find_scu*, dicom::data::dataset::commandset_data, std::unique_ptr<dicom::data::dataset::iod>)> handler);

      virtual void run() override;

      void set_request(dicom::data::dataset::iod request);

      ~find_scu() override;

    private:
      handlermap cfind_req;
      handlermap cfind_resp;

      dicom::data::dataset::iod sendrequest;

      std::vector<dicom::network::dimse::SOP_class> sop_classes;
      std::vector<dicom::network::dimse::SOP_class> sop_classes_response;
      dicom::network::dimse::association_definition assoc_def;
      dicom::network::upperlayer::a_associate_rq initial_rq;
      asio_tcp_client_acceptor infr_scu;
      dicom::network::upperlayer::scu scu;
      dicom::network::dimse::dimse_pm_manager dimse_pm;
      std::function<void(find_scu*, dicom::data::dataset::commandset_data, std::unique_ptr<dicom::data::dataset::iod>)> handler;

      void send_find_request(dicom::network::dimse::dimse_pm* pm,
                              dicom::data::dataset::commandset_data command,
                              std::unique_ptr<dicom::data::dataset::iod> data);

      void handle_find_response(dicom::network::dimse::dimse_pm* pm,
                              dicom::data::dataset::commandset_data command,
                              std::unique_ptr<dicom::data::dataset::iod> data);

};

}

}

#endif // FIND_SCU_HPP
