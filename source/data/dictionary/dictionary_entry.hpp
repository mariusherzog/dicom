#ifndef DICTIONARY_ENTRY_HPP
#define DICTIONARY_ENTRY_HPP

#include <string>
#include <map>

#include "data/attribute/attribute.hpp"

namespace dicom
{

namespace data
{

/**
 * The dictionary entry contains classes to retrieve information for a given
 * attribute.
 */
namespace dictionary
{

class dictionary_entry
{
   public:
      dictionary_entry(attribute::VR vr, std::string mf, std::string kw, std::string vm, bool ret);

      const attribute::VR vr;
      const std::string message_field;
      const std::string keyword;
      const std::string vm;
      const bool retired;

      const static std::map<std::string, attribute::VR> vr_of_string;
};

}

}

}

#endif // DICTIONARY_ENTRY_HPP