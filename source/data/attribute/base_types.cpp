#include "base_types.hpp"

#include <algorithm>
#include <iterator>

namespace dicom
{

namespace data
{

namespace attribute
{

std::size_t byte_length(empty_t)
{
   return 0;
}


std::size_t byte_length(std::vector<unsigned char> value_field)
{
   return value_field.size();
}

std::size_t byte_length(std::vector<unsigned short> value_field)
{
   return 2 * value_field.size();
}

std::size_t byte_length(std::vector<float> value_field)
{
   return 4 * value_field.size();
}

std::size_t byte_length(std::vector<double> value_field)
{
   return 8 * value_field.size();
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
   return 8;
}

std::ostream& operator<<(std::ostream& os, empty_t)
{
   return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<unsigned char>& data)
{
   std::size_t printsize = std::min(data.size(), 128ul);
   std::copy(data.begin(), data.begin()+printsize, std::ostream_iterator<char>(os, " "));
   return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<unsigned short>& data)
{
   std::size_t printsize = std::min(data.size(), 128ul);
   std::copy(data.begin(), data.begin()+printsize, std::ostream_iterator<char>(os, " "));
   return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<float>& data)
{
   std::size_t printsize = std::min(data.size(), 128ul);
   std::copy(data.begin(), data.begin()+printsize, std::ostream_iterator<char>(os, " "));
   return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<double>& data)
{
   std::size_t printsize = std::min(data.size(), 128ul);
   std::copy(data.begin(), data.begin()+printsize, std::ostream_iterator<char>(os, " "));
   return os;
}


}

}

}
