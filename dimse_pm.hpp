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
      enum class CONN_STATE
      {
         IDLE, CONNECTED
      };

      //static const std::map<service, std::string> service_uid;

      dimse_pm(upperlayer::Iupperlayer_comm_ops& sc);
      ~dimse_pm();

      void inject(unsigned char, std::function<void(std::vector<unsigned char>, std::vector<unsigned char>)> f);

   private:
      void associate(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> rq);
      void data_handler(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> d);
      void release_resp(upperlayer::scx* sc, std::unique_ptr<upperlayer::property> r);

      CONN_STATE state;

      upperlayer::a_associate_ac connection_properties;

      std::map<unsigned char, std::function<void(std::vector<unsigned char>, std::vector<unsigned char>)>> procs;

      // supported
      std::set<std::string> transfer_syntaxes;
      std::set<std::string> abstract_syntaxes;
      std::set<std::string> application_contexts;

      //upperlayer::Iupperlayer_comm_ops& ul;
};

#endif // DIMSE_PM_HPP
