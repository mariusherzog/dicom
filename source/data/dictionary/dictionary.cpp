#include "dictionary.hpp"

#include <iostream>

namespace dicom
{

namespace data
{

namespace dictionary
{

static dictionary_entry unknown {{attribute::VR::UN}, "UNKNOWN", "UNKNOWN", "*", false};

dictionary::dictionary(std::string cmddic_path,
                       std::string datadic_path):
   commanddic {cmddic_path},
   datadic {datadic_path}
{
}

dictionary_dyn& dictionary::get_dyn_commanddic()
{
   return commanddic;
}

dictionary_dyn& dictionary::get_dyn_datadic()
{
   return datadic;
}


dictionary_entry dictionary::lookup_datadic(attribute::tag_type tag)
{
   return datadic.lookup(tag);
}

dictionary_entry dictionary::lookup(attribute::tag_type tag)
{
   try {
      return commanddic.lookup(tag);
   } catch (std::exception& e) {
      try {
         return datadic.lookup(tag);
      } catch (...) {
         return unknown;
      }
   }
}

dictionary_entry dictionary::lookup_commanddic(attribute::tag_type tag)
{
   return commanddic.lookup(tag);
}



}

}

}
