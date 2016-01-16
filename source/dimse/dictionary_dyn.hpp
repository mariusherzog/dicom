#ifndef DICTIONARY_DYN_HPP
#define DICTIONARY_DYN_HPP

#include <string>
#include <map>

#include "../attributedata/iod.hpp"
#include "../attributedata/commandset_data.hpp"
#include "../attributedata/attribute.hpp"

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

      struct dictionary_entry
      {
         friend class dictionary_dyn;
         private:
            dictionary_entry(VR vr, std::string mf, std::string kw, std::string vm):
               vr {vr}, message_field {mf}, keyword {kw}, vm {vm}
            {

            }

         public:
            const VR vr;
            const std::string message_field;
            const std::string keyword;
            const std::string vm;

            static std::map<std::string, VR> vr_of_string;
      };

      dictionary_dyn(std::string file, MODE mode);

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
