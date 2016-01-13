#ifndef DATADIC_TEMPLATE_HPP
#define DATADIC_TEMPLATE_HPP

#include <string>
#include "iod.hpp"

struct datadictionary_type
{
   protected:
      datadictionary_type(VR vr, std::string mf, std::string kw, std::string vm, bool ret):
         vr {vr}, message_field {mf}, keyword {kw}, vm {vm}, retired {ret}
      {

      }

   public:
      const VR vr;
      const std::string message_field;
      const std::string keyword;
      const std::string vm;
      const bool retired;
};


template<bool> struct bool_t;

template<unsigned gid, unsigned eid, typename = bool_t<true>, typename = bool_t<true> >
struct datadictionary;

