#ifndef DIMSE_PM_HPP
#define DIMSE_PM_HPP

#include <map>
#include <string>
#include <set>
#include <functional>
#include <vector>

#include "upperlayer.hpp"


class attribute
{
};

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
      void send(std::vector<attribute> a);
      void abort();

      void inject(unsigned char, std::function<void(std::vector<unsigned char>, std::vector<unsigned char>)> f);

   private:
      std::vector<attribute> deserialize(upperlayer::p_data_tf* data);
      upperlayer::p_data_tf serialize(std::vector<attribute> a);

      CONN_STATE state;

      upperlayer::a_associate_ac connection_properties;

      std::map<unsigned char, std::function<void(std::vector<unsigned char>, std::vector<unsigned char>)>> procs;

      // supported
      std::set<std::string> transfer_syntaxes;
      std::set<std::string> abstract_syntaxes;
      std::set<std::string> application_contexts;

      upperlayer::scp ul;
};

#endif // DIMSE_PM_HPP
