#ifndef TRANSFER_PROCESSOR_HPP
#define TRANSFER_PROCESSOR_HPP

#include <vector>
#include <string>

#include "../attributedata/iod.hpp"
#include "../attributedata/commandset_data.hpp"

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

/**
 * @brief The commandset_processor class is used to (de)serialize the command
 *        set of the DICOM message, which is always encoded in little endian
 *        with implicit vr.
 * @todo implementation
 */
class commandset_processor
{

      // Itransfer_processor interface
   public:
      std::vector<unsigned char> deserialize(commandset_data data) const;
      commandset_data serialize(std::vector<unsigned char> data) const;
};


#endif // TRANSFER_PROCESSOR_HPP
