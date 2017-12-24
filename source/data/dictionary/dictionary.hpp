#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <string>
#include <type_traits>

#include "dictionary_dyn.hpp"
#include "datadictionary.hpp"
#include "commanddictionary.hpp"

namespace dicom
{

namespace data
{

namespace dictionary
{

/**
 * @brief The dictionary class is a facade for the different kind of
 *        dictionaries.
 */
class dictionaries
{
   public:
      template <unsigned short gid>
      using static_gid = std::integral_constant<unsigned short, gid>;
      template <unsigned short eid>
      using static_eid = std::integral_constant<unsigned short, eid>;


      /**
       * @brief The dictionary constructor initializes the dynamic dictionaries
       *        to the paths specified in the parameters.
       * @param cmddic_path path to the command dictionary
       * @param datadic_path path toe the data dictionary
       */
      dictionaries(std::string cmddic_path = "commanddictionary.csv",
                   std::string datadic_path = "datadictionary.csv");


      /**
       * @brief lookup_commanddic performs a dynamic lookup of the given tag in
       *        the command dictionary.
       * @param tag
       * @return dictionary entry corresponding the tag, if not found, unknown
       *         placeholder
       * We do not return a boost::optional here because the clients may not
       * want to do an extra check for an unlikely result. The "unknown" tag
       * in case of an error has no constraints and the associated data element
       * can still be processed.
       */
      dictionary_entry lookup_commanddic(attribute::tag_type tag);

      /**
       * @brief lookup_datadic performs a dynamic lookup of the given tag in
       *        the data dictionary.
       * @param tag
       * @return dictionary entry corresponding the tag
       */
      dictionary_entry lookup_datadic(attribute::tag_type tag);

      /**
       * @brief lookup performs a lookup in the command dictionary and data
       *        dictionar respectively
       * @param gid group id of the tag
       * @param eid element id of the tag
       * @return dictionary entry corresponding the tag
       */
      dictionary_entry lookup(attribute::tag_type tag);

      /**
       * @brief lookup_commanddic performs a compile-time lookup of the given tag
       *        in the command dictionary.
       * @param gid group id of the tag
       * @param eid element id of the tag
       * @return dictionary entry corresponding the tag
       */
      template <unsigned short g, unsigned short e>
      dictionary_entry lookup_commanddic(std::integral_constant<unsigned short, g>,
                                         std::integral_constant<unsigned short, e>)
      {
         return commanddictionary<g, e> {};
      }

      /**
       * @brief lookup_datadic performs a compile-time lookup of the given tag
       *        in the data dictionary.
       * @param gid group id of the tag
       * @param eid element id of the tag
       * @return dictionary entry corresponding the tag
       */
      template <unsigned short g, unsigned short e>
      dictionary_entry lookup_datadic(std::integral_constant<unsigned short, g>,
                                      std::integral_constant<unsigned short, e>)
      {
         return datadictionary<g, e> {};
      }

      dictionary_dyn& get_dyn_commanddic();
      dictionary_dyn& get_dyn_datadic();

   private:
      dictionary_dyn commanddic;
      dictionary_dyn datadic;
};

/**
 * @brief get_default_dictionaries returns a reference to a standard
 *        dictionaries instance containing the command and data dictionaries.
 * @return dictionary instance
 */
dictionaries& get_default_dictionaries();


}

}

}

#endif // DICTIONARY_HPP
