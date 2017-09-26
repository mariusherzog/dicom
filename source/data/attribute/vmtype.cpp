#include "vmtype.hpp"

namespace dicom
{

namespace data
{

namespace attribute
{

std::size_t byte_length(std::vector<unsigned char> value_field)
{
   return value_field.size();
}

std::size_t byte_length(const std::string& value_field)
{
   auto size = value_field.length();
   return size;
}

std::size_t byte_length(const unsigned char)
{
   return 1;
}

std::size_t byte_length(const unsigned short)
{
   return 2;
}

std::size_t byte_length(const short)
{
   return 2;
}

std::size_t byte_length(const unsigned int)
{
   return 4;
}

std::size_t byte_length(const long)
{
   return 4;
}

std::size_t byte_length(const float)
{
   return 4;
}

std::size_t byte_length(const double)
{
   return 4;
}

std::size_t byte_length(tag_type)
{
   return 4;
}

std::size_t byte_length(std::vector<dataset::dataset_type>)
{
   return 0xffffffff;
}


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
