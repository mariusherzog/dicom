#include "dictionary_dyn.hpp"

#include <vector>
#include <exception>
#include <sstream>
#include <array>

#include <cassert>

#include <boost/scope_exit.hpp>
#include <boost/bimap.hpp>

namespace dicom
{

namespace data
{

namespace dictionary
{

/**
 * @brief trim removes trailing and leading whitespaces
 * @param[in] s string to be trimmed
 * @return trimmed string
 */
static std::string trim(std::string s)
{
   if (s.size() > 0) {
      int f = s.find_first_not_of(" ");
      if (f < 0) return s;
      std::string n = s.substr(f, s.size());
      int l = n.find_last_not_of(" ");
      return s.substr(f, l+1);
   } else {
      return s;
   }
}

/**
 * @brief get_vrs tokenizes the parameter string and returns an array of VRs
 *        contained within.
 * @param vrstring string containing possible VRs, separated by whitespace
 * @return array of VRs contained in the string
 */
static std::array<attribute::VR, 3> get_vrs(std::string vrstring)
{
   std::array<attribute::VR, 3> vrs;
   int j = 0;
   bool end = false;
   do {
      std::size_t pos = vrstring.find_first_of(" \t");
      end = (pos == std::string::npos);
      pos = (pos == std::string::npos)
            ? vrstring.size()
            : pos+1;
      std::string strvr = trim(vrstring.substr(0, pos));
      vrstring = vrstring.substr(pos, vrstring.size());
      vrs[j++] = dictionary_entry::vr_of_string.left.at(strvr);
   } while (j<2 && !end);

   if (j==2 && !end) {
      std::string strvr = vrstring.substr(0, vrstring.size());
      vrs[j++] = dictionary_entry::vr_of_string.left.at(strvr);
   }

   for (; j<3; ++j) {
      vrs[j] = attribute::VR::NN;
   }
   return vrs;
}


dictionary_dyn::dictionary_dyn(std::string file, MODE mode):
   dictionary_file {file, std::ios_base::in}, buffermode {mode}
{
}


dictionary_entry dictionary_dyn::lookup(attribute::elementfield::tag_type tag)
{
   BOOST_SCOPE_EXIT(&dictionary_file) {
      dictionary_file.clear();
      dictionary_file.seekg(0, std::ios_base::beg);
   } BOOST_SCOPE_EXIT_END; // move the get pointer to the beginning of the
                           // dictionary file

   if (buffermode == MODE::LAZY) {
      return lazylookup(tag);
   } else {
      return greedylookup(tag);
   }
}

bool dictionary_dyn::comparetag(std::string strtag, attribute::elementfield::tag_type tag) const
{
   std::string gidstr {&strtag[1], &strtag[7]};
   std::string eidstr {&strtag[8], &strtag[14]};
   unsigned short taggid = static_cast<unsigned short>(std::stoul(gidstr, 0, 16));
   unsigned short tageid = static_cast<unsigned short>(std::stoul(eidstr, 0, 16));
   return taggid == tag.group_id && tageid == tag.element_id;
}

dictionary_entry dictionary_dyn::lazylookup(attribute::elementfield::tag_type tag)
{
   const int num_fields = 6;
   std::string line;

   if (!dictionary_file.is_open()) {
      throw std::runtime_error {"Error opening dictionary file!"};
   }

   while (std::getline(dictionary_file, line)) {
      std::stringstream entry {line};
      std::string strtag;
      std::getline(entry, strtag, ';');
      if (comparetag(strtag, tag)) {
         std::array<attribute::VR, 3> vrs;
         std::string fields[num_fields-1];
         for (int i=0; i<num_fields-1; ++i) {
            std::getline(entry, fields[i], ';');
            fields[i] = trim(fields[i]);
            if (i==0) {
               vrs = get_vrs(fields[i]);
            }
         }
         bool retired = fields[num_fields-2] == "RET";
         return dictionary_entry {
            {vrs[0], vrs[1], vrs[2]}, fields[1], fields[2], fields[3], retired};

      }
   }
   throw std::runtime_error {"Tag not found"};
}

dictionary_entry dictionary_dyn::greedylookup(attribute::elementfield::tag_type tag)
{
   using namespace dicom::data::attribute;
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
         unsigned short taggid = static_cast<unsigned short>(std::stoul(gidstr, 0, 16));
         unsigned short tageid = static_cast<unsigned short>(std::stoul(eidstr, 0, 16));

         std::string fields[num_fields-1];
         for (int i=0; i<num_fields-1; ++i) {
            std::getline(entry, fields[i], ';');
            fields[i] = trim(fields[i]);
         }
         bool retired = fields[num_fields-2] == "RET";

         dict_buffer.emplace(elementfield::tag_type {taggid, tageid}
            , dictionary_entry {
               {dictionary_entry::vr_of_string.left.at(fields[2]), attribute::VR::NN, attribute::VR::NN}
               , fields[0], fields[1], fields[3], retired});
      }
   }
   return dict_buffer.at(tag);
}

}

}

}
