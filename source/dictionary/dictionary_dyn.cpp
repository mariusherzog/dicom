#include "dictionary_dyn.hpp"

#include <vector>
#include <exception>

#include <cassert>

std::map<std::string, VR> dictionary_dyn::dictionary_entry::vr_of_string
{
   {"AE", VR::AE},
   {"AS", VR::AS},
   {"AT", VR::AT},
   {"CS", VR::CS},
   {"DA", VR::DA},
   {"DS", VR::DS},
   {"DT", VR::DT},
   {"FL", VR::FL},
   {"FD", VR::FD},
   {"IS", VR::IS},
   {"LO", VR::LO},
   {"LT", VR::LT},
   {"OB", VR::OB},
   {"OF", VR::OF},
   {"OW", VR::OW},
   {"PN", VR::PN},
   {"SH", VR::SH},
   {"SL", VR::SL},
   {"SQ", VR::SQ},
   {"SS", VR::SS},
   {"ST", VR::ST},
   {"TM", VR::TM},
   {"UI", VR::UI},
   {"UL", VR::UL},
   {"UN", VR::UN},
   {"US", VR::US},
   {"UT", VR::UT}
};

dictionary_dyn::dictionary_dyn(std::string file, MODE mode):
   dictionary_file {file, std::ios_base::in}, mode_ {mode}
{
}


dictionary_dyn::dictionary_entry dictionary_dyn::lookup(unsigned gid, unsigned eid)
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
         }
         bool retired = fields[num_fields-2] == " RET";
         return dictionary_entry {dictionary_entry::vr_of_string[fields[0]]
                  , fields[1], fields[2], fields[3], retired};
      }
   }
   throw std::runtime_error {"Tag not found"};
}

bool dictionary_dyn::comparetag(std::string tag, unsigned gid, unsigned eid) const
{
   std::string gidstr {&tag[1], &tag[7]};
   std::string eidstr {&tag[8], &tag[14]};
   unsigned taggid = static_cast<unsigned>(std::stoul(gidstr, 0, 16));
   unsigned tageid = static_cast<unsigned>(std::stoul(eidstr, 0, 16));
   return taggid == gid && tageid == eid;
}

