#ifndef DICTIONARY_DYN_HPP
#define DICTIONARY_DYN_HPP

#include <string>
#include <map>
#include <fstream>

#include "dictionary_entry.hpp"

namespace dicom
{

namespace data
{

namespace dictionary
{

/**
 * @brief The commanddictionary_dyn class is used to acquire information about
 *        an iod at runtime.
 * Two modes are offered; either the complete dictionary is loaded into the
 * memory, or the file will be traversed for each query.
 */
class dictionary_dyn
{
   public:
      /**
       * @brief The MODE enum is used to control if the content of the
       *        dictionary file should be buffered
       */
      enum class MODE
      {
         LAZY,    /** do not buffer */
         GREEDY   /** buffer complete dictionary */
      };


      dictionary_dyn(std::string file, MODE mode = MODE::LAZY);

      /**
       * @brief lookup performs an dynamic lookup on the tag.
       * @param gid group id
       * @param eid element id
       * @return dictionary entry corresponding to the tag
       */
      dictionary_entry lookup(attribute::tag_type tag);

   private:
      std::ifstream dictionary_file;
      MODE buffermode;

      std::map<attribute::tag_type, dictionary_entry> dict_buffer;

      /**
       * @brief comparetag
       * @param tag tag in the form (gggg,eeee)
       * @param gid gid to be looked for
       * @param eid eid to be looked for
       * @return true if the tag and gid / eid match, false otherwise
       */
      bool comparetag(std::string strtag, attribute::tag_type tag) const;

      /**
       * @brief lazylookup performs a lookup on the tag directly from the
       *        dictionary file.
       * @param gid gid to be looked for
       * @param eid eid to be looked for
       * @return dictionary entry corresponding to the tag
       */
      dictionary_entry lazylookup(attribute::tag_type tag);

      /**
       * @brief greedylookup performs a greedy lookup given the tag, ie. the
       *        contents are read from an internal buffer.
       * @param gid gid to be looked for
       * @param eid eid to be looked for
       * @return dictionary entry corresponding to the tag
       */
      dictionary_entry greedylookup(attribute::tag_type tag);

};

}

}

}

#endif // COMMANDDICTIONARY_DYN_HPP
