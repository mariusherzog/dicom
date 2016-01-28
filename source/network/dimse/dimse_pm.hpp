#ifndef DIMSE_PM_HPP
#define DIMSE_PM_HPP

#include <map>
#include <string>
#include <set>
#include <functional>
#include <vector>
#include <utility>
#include <initializer_list>

#include <boost/optional.hpp>

#include "response.hpp"
#include "sop_class.hpp"
#include "network/upperlayer/upperlayer.hpp"
#include "data/dataset/transfer_processor.hpp"
#include "data/dictionary/dictionary.hpp"
#include "sop_class.hpp"


namespace dicom
{

namespace network
{

namespace dimse
{

/**
 * @brief The dimse_pm class implements the DIMSE protocol machine as specified
 *        in chapter 3.7 of the DICOM standard.
 */
class dimse_pm
{
   public:
      enum class CONN_STATE
      {
         IDLE, CONNECTED
      };

      dimse_pm(upperlayer::Iupperlayer_comm_ops& sc,
               std::vector<std::pair<SOP_class, std::vector<std::string>>> operations,
               data::dictionary::dictionary& dict);
      ~dimse_pm();

   private:
      /**
       * @brief association_rq_handler is called upon reception of an a-associate-rq property. It negotiates the supported
       *        abstract syntaxes and the application context and transmits a respective a-associate-ac property.
       * @param[in, out] sc upperlayer service received from
       * @param[in] rq associate request data
       */
      void association_rq_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> rq);

      /**
       * @brief data_handler is called when a p-data-tf property is received.
       * @param[in, out] sc upperlayer service received from
       * @param[in] d data
       */
      void data_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> d);

      /**
       * @brief release_rq_handler is called when an a-associate-rq property is received. An a-associate-rp is transmitted.
       * @param[in, out] sc upperlayer service received from
       * @param[in] r release
       */
      void release_rq_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> r);

      /**
       * @brief abort_handler is called upon reception of an a-abort pdu
       * @param[in, out] sc
       * @param r
       */
      void abort_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> r);


      CONN_STATE state;

      boost::optional<upperlayer::a_associate_ac> connection_properties;
      std::map<std::string, std::pair<SOP_class, std::vector<std::string>>> operations;
      std::vector<std::string> application_contexts;

      static std::map<data::dataset::DIMSE_SERVICE_GROUP
         , std::function<upperlayer::p_data_tf(response r, int mid, data::dictionary::dictionary&)>> assemble_response;
      data::dictionary::dictionary& dict;
};


}

}

}

#endif // DIMSE_PM_HPP
