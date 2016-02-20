#ifndef DICTIONARY_ENTRY_HPP
#define DICTIONARY_ENTRY_HPP

#define BOOST_BIND_NO_PLACEHOLDERS //prevent placeholder namespace collisions

#include <string>
#include <map>
#include <array>

#include <boost/bimap.hpp>

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
      constexpr static int max_vr_options = 3;

      dictionary_entry(std::array<attribute::VR, max_vr_options> vr, std::string mf, std::string kw, std::string vm, bool ret);

      int vr_options() const;

      const std::array<attribute::VR, max_vr_options> vr;
      const std::string message_field;
      const std::string keyword;
      const std::string vm;
      const bool retired;

      const static boost::bimap<std::string, attribute::VR> vr_of_string;
};

}

}

}

#endif // DICTIONARY_ENTRY_HPP
