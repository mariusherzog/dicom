#ifndef TRANSFER_PROCESSOR_HPP
#define TRANSFER_PROCESSOR_HPP

#include <vector>
#include <string>

#include "iod.hpp"

struct Itransfer_processor
{
      virtual std::vector<unsigned char> deserialize(iod data) const = 0;
      virtual iod serialize(std::vector<unsigned char> data) const = 0;
      virtual std::string get_transfer_syntax() const = 0;
      virtual ~Itransfer_processor() = 0;
};

#endif // TRANSFER_PROCESSOR_HPP
