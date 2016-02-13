#include "dictionary.hpp"

namespace dicom
{

namespace data
{

namespace dictionary
{


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


dictionary_entry dictionary::lookup_datadic(unsigned short gid,
                                            unsigned short eid)
{
   return datadic.lookup(gid, eid);
}

dictionary_entry dictionary::lookup(unsigned short gid, unsigned short eid)
{
   try {
      return commanddic.lookup(gid, eid);
   } catch (std::exception&) {
      return datadic.lookup(gid, eid);
   }
}

dictionary_entry dictionary::lookup_commanddic(unsigned short gid,
                                               unsigned short eid)
{
   return commanddic.lookup(gid, eid);
}



}

}

}
