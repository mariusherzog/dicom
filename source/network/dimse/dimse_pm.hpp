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
#include "initial_request.hpp"
#include "sop_class.hpp"
#include "network/upperlayer/upperlayer.hpp"
#include "data/dataset/transfer_processor.hpp"
#include "data/dictionary/dictionary.hpp"


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
               initial_request operations,
               data::dictionary::dictionary& dict);
      ~dimse_pm();

      /**
       * @brief send_response sends a response to the peer.
       * @param r response data
       */
      void send_response(response r);

      /**
       * @brief abort_associations aborts the current association by sending an
       *        a_abort package to the peer.
       */
      void abort_association();

      /**
       * @brief release_association
       */
      void release_association();

   private:
      /**
       * @brief association_rq_handler is called upon reception of an a-associate-rq property. It negotiates the supported
       *        abstract syntaxes and the application context and transmits a respective a-associate-ac property.
       * @param[in, out] sc upperlayer service received from
       * @param[in] rq associate request data
       */
      void association_rq_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> rq);

      /**
       * @brief association_ac_handler is called upon reception of an a-associate-ac property.
       * @param[in, out] sc upperlayer service received from
       * @param[in] rq associate request data
       */
      void association_ac_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> ac);

      /**
       * @brief data_handler is called when a p-data-tf property is received.
       * @param[in, out] sc upperlayer service received from
       * @param[in] d data
       */
      void data_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> d);

      /**
       * @brief release_rq_handler is called when an a-associate-rq property is
       *        received. An a-associate-rp is transmitted.
       * @param[in, out] sc upperlayer service received from
       * @param[in] r release
       */
      void release_rq_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> r);

      /**
       * @brief release_rp_handler is called when an a-associate-rp property is
       *        received. This handler will confirm the release to the user.
       * @param[in, out] sc upperlayer service received from
       * @param[in] r release
       */
      void release_rp_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> r);

      /**
       * @brief abort_handler is called upon reception of an a-abort pdu
       * @param[in, out] sc
       * @param r
       */
      void abort_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> r);

      /**
       * @brief sent_release_rq is set as a handler for the upperlayer when an
       *        association request is sent successfully.
       * @param[in, out] sc
       * @param r
       */
      void sent_release_rq(upperlayer::scx* sc, upperlayer::property* r);

      /**
       * @brief next_message_id returns a free message id
       * @return next free message id
       */
      int next_message_id();

      upperlayer::Iupperlayer_comm_ops& upperlayer_impl;

      //SOP_class request;

      CONN_STATE state;

      boost::optional<upperlayer::a_associate_rq> connection_request;
      boost::optional<upperlayer::a_associate_ac> connection_properties;

      initial_request operations;
      std::vector<std::string> application_contexts;

      static std::map<data::dataset::DIMSE_SERVICE_GROUP
         , std::function<upperlayer::p_data_tf(response r, int message_id, data::dictionary::dictionary&)>> assemble_response;
      data::dictionary::dictionary& dict;
};


}

}

}

#endif // DIMSE_PM_HPP
