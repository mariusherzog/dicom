#ifndef DICTIONARY_ENTRY_HPP
#define DICTIONARY_ENTRY_HPP

#include <string>
#include <map>

#include "attributedata/attribute.hpp"

class dictionary_entry
{
   public:
      dictionary_entry(VR vr, std::string mf, std::string kw, std::string vm, bool ret);

      const VR vr;
      const std::string message_field;
      const std::string keyword;
      const std::string vm;
      const bool retired;

      const static std::map<std::string, VR> vr_of_string;
};

#endif // DICTIONARY_ENTRY_HPP
