#ifndef DIMSE_PM_HPP
#define DIMSE_PM_HPP

#include <map>
#include <string>
#include <set>
#include <functional>
#include <vector>

#include <boost/optional.hpp>

#include "network/upperlayer/upperlayer.hpp"
#include "data/attribute/transfer_processor.hpp"


/**
 * @brief The dimse_pm class
 * @todo - implement (de)serialization methods <BR>
 */
class dimse_pm
{
   public:
      enum class CONN_STATE
      {
         IDLE, CONNECTED
      };

      //static const std::map<service, std::string> service_uid;

      dimse_pm(upperlayer::Iupperlayer_comm_ops& sc);
      ~dimse_pm();

      void inject(std::string transfer_syntax, std::function<void(std::vector<unsigned char>, std::vector<unsigned char>)> fn);

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

      /**
       * @brief trans_synt_from_mid acquires the transfer-syntax-name from a given context id
       * @param[in] mid
       * @return transfer-syntax-name
       */
      std::string trans_synt_from_mid(unsigned char cid);


      CONN_STATE state;

      boost::optional<upperlayer::a_associate_ac> connection_properties;

      std::map<std::string, std::function<void(std::vector<unsigned char> cs, std::vector<unsigned char> ds)>> procs;
      std::map<std::string, std::unique_ptr<const Itransfer_processor>> transfer_syntax_handler;

      std::vector<std::string> ts_of_cont_id;

      // supported
      std::set<std::string> transfer_syntaxes;
      std::set<std::string> abstract_syntaxes;
      std::set<std::string> application_contexts;
};

#endif // DIMSE_PM_HPP
