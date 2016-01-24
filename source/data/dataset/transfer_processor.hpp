#ifndef TRANSFER_PROCESSOR_HPP
#define TRANSFER_PROCESSOR_HPP

#include <vector>
#include <string>

#include "iod.hpp"
#include "commandset_data.hpp"
#include "data/dictionary/datadictionary.hpp"
#include "data/dictionary/dictionary_dyn.hpp"

namespace dicom
{

namespace data
{

/**
 * The dataset namespace contains all functionality related to sets of
 * attributes comprising a DICOM dataset (iod or command header data).
 */
namespace dataset
{

/**
 * @brief The Itransfer_processor struct defines the interface for serializing
 *        and deserializing attribute sets (IODs), honoring the transfer
 *        syntax
 * This abstraction shall be mapped by the DIMSE layer to each transfer syntax
 * it wants to offer for each presentation context.
 */
struct Itransfer_processor
{
      virtual std::vector<unsigned char> serialize(iod data) const = 0;
      virtual iod deserialize(std::vector<unsigned char> data) const = 0;
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
   public:
      explicit commandset_processor(dictionary::dictionary_dyn& dict);

      std::vector<unsigned char> serialize(commandset_data data) const;
      commandset_data deserialize(std::vector<unsigned char> data) const;

   private:
      dictionary::dictionary_dyn& dict;
};

}

}

}


#endif // TRANSFER_PROCESSOR_HPP
