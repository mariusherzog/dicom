#include "vmtype.hpp"

namespace dicom
{

namespace data
{

namespace attribute
{


std::ostream& operator<<(std::ostream& os, vmtype<std::string> data)
{
    bool more_elements = false;
    for (const auto& field : data) {
        if (more_elements) {
            os << static_cast<char>(0x5c);
        }
        os << field;
        more_elements = data.size() > 1;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, vmtype<attribute::tag_type> tag)
{
   std::ios state(nullptr);
   state.copyfmt(os);

   for (const auto& ctag : tag)
   {
      os << ctag;
   }

   os.copyfmt(state);
   return os;
}


}

}

}
