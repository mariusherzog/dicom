#ifndef DICTIONARY_DYN_HPP
#define DICTIONARY_DYN_HPP

#include <string>
#include <map>

#include "dictionary_entry.hpp"

/**
 * @brief The commanddictionary_dyn class is used to acquire information about
 *        an iod at runtime.
 * Two modes are offered; either the complete dictionary is loaded into the
 * memory, or the file will be traversed for each query.
 */
class dictionary_dyn
{
   public:
      enum class MODE
      {
         FROMFILE, INMEMORY
      };


      dictionary_dyn(std::string file, MODE mode);

      /**
       * @brief lookup performs an dynamic lookup on the tag.
       * @param gid group id
       * @param eid element id
       * @return dictionary entry corresponding to the tag
       * @todo trim leading and trailing whitespaces from segments
       */
      dictionary_entry lookup(unsigned gid, unsigned eid);

   private:
      std::fstream dictionary_file;
      MODE mode_;

      /**
       * @brief comparetag
       * @param tag tag in the form (gggg,eeee)
       * @param gid gid to be looked for
       * @param eid eid to be looked for
       * @return true if the tag and gid / eid match, false otherwise
       */
      bool comparetag(std::string tag, unsigned gid, unsigned eid) const;

};

#endif // COMMANDDICTIONARY_DYN_HPP
