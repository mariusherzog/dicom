#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include <vector>
#include <string>
#include <iostream>

namespace dicom
{

namespace data
{

namespace attribute
{

/**
 * @brief empty_t dummy type for attributes without a data field
 */
struct empty_t
{
};

std::size_t byte_length(empty_t data);

std::size_t byte_length(std::vector<unsigned char> value_field);

std::size_t byte_length(std::vector<unsigned short> value_field);

std::size_t byte_length(std::vector<float> value_field);

std::size_t byte_length(std::vector<double> value_field);

std::size_t byte_length(const std::string& value_field);

std::size_t byte_length(const unsigned char);

std::size_t byte_length(const unsigned short);

std::size_t byte_length(const short);

std::size_t byte_length(const unsigned int);

std::size_t byte_length(const long);

std::size_t byte_length(const float);

std::size_t byte_length(const double);

std::ostream& operator<<(std::ostream& os, empty_t);

std::ostream& operator<<(std::ostream& os, const std::vector<unsigned char>& data);

std::ostream& operator<<(std::ostream& os, const std::vector<unsigned short>& data);

std::ostream& operator<<(std::ostream& os, const std::vector<float>& data);

std::ostream& operator<<(std::ostream& os, const std::vector<double>& data);

}

}

}

#endif // BASE_TYPES_HPP
