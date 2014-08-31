#ifndef DIMSE_PM_HPP
#define DIMSE_PM_HPP

#include <map>
#include <string>
#include <set>
#include <functional>

#include "upperlayer.hpp"


class dimse_pm
{
   public:
      enum class service
      {
         C_ECHO
      };

      static const std::map<service, std::string> service_uid;

      dimse_pm();
      bool associate();
      void receive();

      void inject(unsigned char, std::function<void(std::vector<unsigned char>, std::vector<unsigned char>)> f);

   private:
      scp ul;
      a_associate_ac connection_properties;

      std::map<unsigned char, std::function<void(std::vector<unsigned char>, std::vector<unsigned char>)>> procs;

      // supported
      std::set<std::string> transfer_syntaxes;
      std::set<std::string> abstract_syntaxes;
      std::set<std::string> application_contexts;

};

#endif // DIMSE_PM_HPP
