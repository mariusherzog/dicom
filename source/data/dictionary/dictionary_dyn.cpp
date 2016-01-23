#include "dictionary_dyn.hpp"

#include <vector>
#include <exception>
#include <sstream>

#include <cassert>

#include <boost/scope_exit.hpp>


/**
 * @brief trim removes trailing and leading whitespaces
 * @param[in] s string to be trimmed
 * @return trimmed string
 */
static std::string trim(std::string s)
{
   if (s.size() > 0) {
      int f = s.find_first_not_of(" ");
      std::string n = s.substr(f, s.size());
      int l = n.find_last_not_of(" ");
      return s.substr(f, l+1);
   } else {
      return s;
   }
}


dictionary_dyn::dictionary_dyn(std::string file, MODE mode):
   dictionary_file {file, std::ios_base::in}, buffermode {mode}
{
}


dictionary_entry dictionary_dyn::lookup(short gid, short eid)
{
   BOOST_SCOPE_EXIT(&dictionary_file) {
      dictionary_file.seekg(0, std::ios_base::beg);
   } BOOST_SCOPE_EXIT_END; // move the get pointer to the beginning of the
                           // dictionary file

   if (buffermode == MODE::LAZY) {
      return lazylookup(gid, eid);
   } else {
      return greedylookup(gid, eid);
   }
}

bool dictionary_dyn::comparetag(std::string tag, short gid, short eid) const
{
   std::string gidstr {&tag[1], &tag[7]};
   std::string eidstr {&tag[8], &tag[14]};
   short taggid = static_cast<short>(std::stoul(gidstr, 0, 16));
   short tageid = static_cast<short>(std::stoul(eidstr, 0, 16));
   return taggid == gid && tageid == eid;
}

dictionary_entry dictionary_dyn::lazylookup(short gid, short eid)
{
   const int num_fields = 6;
   std::string line;

   if (!dictionary_file.is_open()) {
      throw std::runtime_error {"Error opening dictionary file!"};
   }

   while (std::getline(dictionary_file, line)) {
      std::stringstream entry {line};
      std::string tag;
      std::getline(entry, tag, ';');
      if (comparetag(tag, gid, eid)) {
         std::string fields[num_fields-1];
         for (int i=0; i<num_fields-1; ++i) {
            std::getline(entry, fields[i], ';');
            fields[i] = trim(fields[i]);
         }
         bool retired = fields[num_fields-2] == "RET";
         return dictionary_entry {dictionary_entry::vr_of_string.at(fields[2])
                  , fields[0], fields[1], fields[3], retired};
      }
   }
   throw std::runtime_error {"Tag not found"};
}

dictionary_entry dictionary_dyn::greedylookup(short gid, short eid)
{
   const int num_fields = 6;
   std::string line;

   if (!dictionary_file.is_open()) {
      throw std::runtime_error {"Error opening dictionary file!"};
   }

   if (dict_buffer.empty()) {
      while (std::getline(dictionary_file, line)) {
         std::stringstream entry {line};
         std::string tag;
         std::getline(entry, tag, ';');
         std::string gidstr {&tag[1], &tag[7]};
         std::string eidstr {&tag[8], &tag[14]};
         short taggid = static_cast<short>(std::stoul(gidstr, 0, 16));
         short tageid = static_cast<short>(std::stoul(eidstr, 0, 16));

         std::string fields[num_fields-1];
         for (int i=0; i<num_fields-1; ++i) {
            std::getline(entry, fields[i], ';');
            fields[i] = trim(fields[i]);
         }
         bool retired = fields[num_fields-2] == "RET";

         dict_buffer.emplace(elementfield::tag_type {taggid, tageid}
            , dictionary_entry {dictionary_entry::vr_of_string.at(fields[2])
               , fields[0], fields[1], fields[3], retired});
      }
   }
   return dict_buffer.at(elementfield::tag_type {gid, eid});
}
