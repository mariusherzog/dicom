#ifndef TRANSFER_PROCESSOR_HPP
#define TRANSFER_PROCESSOR_HPP

#include <vector>
#include <string>

#include "iod.hpp"

/**
 * @brief The Itransfer_processor struct defines the interface for serializing
 *        and deserializing attribute sets (IODs), honoring the transfer
 *        syntax
 * This abstraction shall be mapped by the DIMSE layer to each transfer syntax
 * it wants to offer for each presentation context.
 */
struct Itransfer_processor
{
      virtual std::vector<unsigned char> deserialize(iod data) const = 0;
      virtual iod serialize(std::vector<unsigned char> data) const = 0;
      virtual std::string get_transfer_syntax() const = 0;
      virtual ~Itransfer_processor() = 0;
};

#endif // TRANSFER_PROCESSOR_HPP
