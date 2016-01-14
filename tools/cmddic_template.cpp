#ifndef COMMANDDIC_TEMPLATE_HPP
#define COMMANDDIC_TEMPLATE_HPP

#include <string>
#include "iod.hpp"

struct commanddictionary_type 
{
   protected:
      commanddictionary_type(VR vr, std::string mf, std::string kw, std::string vm):
         vr {vr}, message_field {mf}, keyword {kw}, vm {vm}
      {

      }

   public:
      const VR vr;
      const std::string message_field;
      const std::string keyword;
      const std::string vm;
};

template<unsigned gid, unsigned eid>
struct commanddictionary;

