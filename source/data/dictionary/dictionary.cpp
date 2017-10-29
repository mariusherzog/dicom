#include "dictionary.hpp"

#include <iostream>

namespace dicom
{

namespace data
{

namespace dictionary
{

static dictionary_entry unknown {{attribute::VR::UN}, "UNKNOWN", "UNKNOWN", "*", false};

dictionaries::dictionaries(std::string cmddic_path,
                       std::string datadic_path):
   commanddic {cmddic_path},
   datadic {datadic_path}
{
}

dictionary_dyn& dictionaries::get_dyn_commanddic()
{
   return commanddic;
}

dictionary_dyn& dictionaries::get_dyn_datadic()
{
   return datadic;
}


dictionary_entry dictionaries::lookup_datadic(attribute::tag_type tag)
{
   auto entry = datadic.lookup(tag);
   if (entry == boost::none) {
      return unknown;
   } else {
      return *entry;
   }
}

dictionary_entry dictionaries::lookup(attribute::tag_type tag)
{
   try {
      auto found_entry {commanddic.lookup(tag)};
      if (found_entry == boost::none) {
         auto found_data_entry {datadic.lookup(tag)};
         if (found_data_entry == boost::none) {
            return unknown;
         } else {
            return *found_data_entry;
         }
      }

      return *found_entry;
   } catch (std::exception&) {
      return unknown;
   }
}

dictionary_entry dictionaries::lookup_commanddic(attribute::tag_type tag)
{
   auto entry = commanddic.lookup(tag);
   if (entry == boost::none) {
      return unknown;
   } else {
      return *entry;
   }
}



}

}

}
