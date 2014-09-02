#ifndef DIMSE_PM_HPP
#define DIMSE_PM_HPP

#include <map>
#include <string>
#include <set>
#include <functional>

#include "upperlayer.hpp"

/**
 * @brief The dimse_pm class
 * @todo - implement (de)serialization methods <BR>
 */
class dimse_pm
{
   public:
      enum class service
      {
         C_ECHO
      };

      enum class CONN_STATE
      {
         IDLE, CONNECTED
      };

      static const std::map<service, std::string> service_uid;

      dimse_pm();
      ~dimse_pm();
      bool associate();
      void receive();
      void abort();

      void inject(unsigned char, std::function<void(std::vector<unsigned char>, std::vector<unsigned char>)> f);

   private:
      void deserialize(upperlayer::p_data_tf* data);

      CONN_STATE state;

      upperlayer::scp ul;
      upperlayer::a_associate_ac connection_properties;

      std::map<unsigned char, std::function<void(std::vector<unsigned char>, std::vector<unsigned char>)>> procs;

      // supported
      std::set<std::string> transfer_syntaxes;
      std::set<std::string> abstract_syntaxes;
      std::set<std::string> application_contexts;

};

#endif // DIMSE_PM_HPP
