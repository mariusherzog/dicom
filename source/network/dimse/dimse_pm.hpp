#ifndef DIMSE_PM_HPP
#define DIMSE_PM_HPP

#include <map>
#include <string>
#include <set>
#include <functional>
#include <vector>
#include <utility>
#include <memory>
#include <initializer_list>

#include <boost/optional.hpp>

#include "response.hpp"
#include "association_definition.hpp"
#include "sop_class.hpp"
#include "network/upperlayer/upperlayer.hpp"
#include "data/dataset/transfer_processor.hpp"
#include "data/dictionary/dictionary.hpp"

#include "util/channel_sev_logger.hpp"


namespace dicom
{

namespace network
{

namespace dimse
{

class dimse_pm;

/**
 * @brief The dimse_pm_manager class is used to handle new connections and
 *        create instances of the dimse protocol machine.
 * This is mainly relevant for SCPs which can have multiple connections open
 * simultaneously.
 */
class dimse_pm_manager
{
   public:
      dimse_pm_manager(upperlayer::Iupperlayer_connection_handlers& conn,
                       association_definition operations,
                       data::dictionary::dictionary& dict);

      /**
       * @brief run starts handling connections
       */
      void run();

      /**
       * @brief connection_error_handler sets the callback for when an error
       *        occurs on one of dimse_pm connection of this manager
       * @param handler callback to be invoked upon an error
       */
      void connection_error_handler(std::function<void(dimse_pm*, std::exception_ptr)> handler);

      /**
       * @brief get_operations returns a reference to the association definition
       * @return reference to association definition
       * note that changes will be only applied to new connection after run(),
       * as the association_definition is copied into the connection-specific
       * dimse protocol machine
       */
      association_definition& get_operations();

   private:
      std::map<upperlayer::Iupperlayer_comm_ops*, std::unique_ptr<dimse_pm>> protocol_machines;

      void create_dimse(upperlayer::Iupperlayer_comm_ops* scx);
      void remove_dimse(upperlayer::Iupperlayer_comm_ops* scx);
      void connection_error(upperlayer::Iupperlayer_comm_ops* scx, std::exception_ptr err);

      upperlayer::Iupperlayer_connection_handlers& conn;
      association_definition operations;
      data::dictionary::dictionary& dict;
      std::function<void(dimse_pm*, std::exception_ptr)> error_handler;

      util::log::channel_sev_logger logger;
};


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
               association_definition operations,
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
      void association_rq_handler(upperlayer::Iupperlayer_comm_ops* sc, std::unique_ptr<upperlayer::property> rq);

      /**
       * @brief association_ac_handler is called upon reception of an a-associate-ac property.
       * @param[in, out] sc upperlayer service received from
       * @param[in] rq associate request data
       */
      void association_ac_handler(upperlayer::Iupperlayer_comm_ops* sc, std::unique_ptr<upperlayer::property> ac);

      void association_rj_handler(upperlayer::Iupperlayer_comm_ops* sc, std::unique_ptr<upperlayer::property> rj);

      /**
       * @brief data_handler is called when a p-data-tf property is received.
       * @param[in, out] sc upperlayer service received from
       * @param[in] d data
       */
      void data_handler(upperlayer::Iupperlayer_comm_ops* sc, std::unique_ptr<upperlayer::property> d);

      /**
       * @brief release_rq_handler is called when an a-associate-rq property is
       *        received. An a-associate-rp is transmitted.
       * @param[in, out] sc upperlayer service received from
       * @param[in] r release
       */
      void release_rq_handler(upperlayer::Iupperlayer_comm_ops* sc, std::unique_ptr<upperlayer::property> r);

      /**
       * @brief release_rp_handler is called when an a-associate-rp property is
       *        received. This handler will confirm the release to the user.
       * @param[in, out] sc upperlayer service received from
       * @param[in] r release
       */
      void release_rp_handler(upperlayer::Iupperlayer_comm_ops* sc, std::unique_ptr<upperlayer::property> r);

      /**
       * @brief abort_handler is called upon reception of an a-abort pdu
       * @param[in, out] sc
       * @param r
       */
      void abort_handler(upperlayer::Iupperlayer_comm_ops* sc, std::unique_ptr<upperlayer::property> r);

      /**
       * @brief sent_association_ac is set as a handler for the upperlayer when an
       *        a_associate_ac pdu is sent successfully.
       * @param[in, out] sc
       * @param r
       */
      void sent_association_ac(upperlayer::Iupperlayer_comm_ops* sc, upperlayer::property* r);

      /**
       * @brief sent_association_rq is set as a handler for the upperlayer when an
       *        a_associate_rq pdu is sent successfully.
       * @param[in, out] sc
       * @param r
       */
      void sent_association_rq(upperlayer::Iupperlayer_comm_ops* sc, upperlayer::property* r);

      /**
       * @brief sent_data_tf is set as a handler for the upperlayer when an
       *        p_data_tf pdu is sent successfully.
       * @param[in, out] sc
       * @param r
       */
      void sent_data_tf(upperlayer::Iupperlayer_comm_ops* sc, upperlayer::property* r);

      /**
       * @brief sent_release_rq is set as a handler for the upperlayer when an
       *        association request is sent successfully.
       * @param[in, out] sc
       * @param r
       */
      void sent_release_rq(upperlayer::Iupperlayer_comm_ops* sc, upperlayer::property* r);

      /**
       * @brief sent_release_rp is set as a handler for the upperlayer when an
       *        a_release_rp pdu is sent successfully.
       * @param[in, out] sc
       * @param r
       */
      void sent_release_rp(upperlayer::Iupperlayer_comm_ops* sc, upperlayer::property* r);

      /**
       * @brief sent_abort is set as a handler for the upperlayer when an
       *        a_abort pdu is sent successfully.
       * @param[in, out] sc
       * @param r
       */
      void sent_abort(upperlayer::Iupperlayer_comm_ops* sc, upperlayer::property* r);

      /**
       * @brief next_message_id returns a free message id
       * @return next free message id
       */
      int next_message_id();

      /**
       * @brief find_transfer_processor uses the connection properties and the
       *        availabe transfer processors to return a transfer processor
       *        appropriate for the presentation context on which dicom
       *        transmission / reception occurs.
       * @param presentation_context_id presentation context id where data is
       *        to be sent / received.
       * @return reference to a matching transfer processor
       */

      data::dataset::transfer_processor& find_transfer_processor(unsigned char presentation_context_id);

      //upperlayer::Iupperlayer_sethandlers& upperlayer_handlers;
      upperlayer::Iupperlayer_comm_ops& upperlayer_impl;
      CONN_STATE state;

      boost::optional<upperlayer::a_associate_rq> connection_request;
      boost::optional<upperlayer::a_associate_ac> connection_properties;

      association_definition operations;

      int msg_id = 1;

      std::size_t max_remote_msg_length;

      std::map<data::dataset::DIMSE_SERVICE_GROUP
         , std::function<upperlayer::p_data_tf(dimse_pm*, response r, int pres_context_id)>> assemble_response;

      upperlayer::p_data_tf assemble_cfind_rq(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_cfind_rsp(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_cecho_rq(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_cecho_rsp(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_cget_rq(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_cget_rsp(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_cmove_rq(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_cmove_rsp(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_cstore_rq(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_cstore_rsp(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_neventreport_rq(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_neventreport_rsp(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_nget_rq(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_nget_rsp(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_nset_rq(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_nset_rsp(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_naction_rq(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_naction_rsp(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_ncreate_rq(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_ncreate_rsp(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_ndelete_rq(response r, int pres_context_id);
      upperlayer::p_data_tf assemble_ndelete_rsp(response r, int pres_context_id);

      data::dictionary::dictionary& dict;

      std::map<std::string, std::unique_ptr<data::dataset::transfer_processor>> transfer_processors;

      util::log::channel_sev_logger logger;
};


}

}

}

#endif // DIMSE_PM_HPP
