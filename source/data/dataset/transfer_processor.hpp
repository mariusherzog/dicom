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
class transfer_processor
{
   public:
      explicit transfer_processor(dictionary::dictionary_dyn& dict);

      std::vector<unsigned char> serialize(iod data) const;
      virtual iod deserialize(std::vector<unsigned char> data) const = 0;
      virtual std::string get_transfer_syntax() const = 0;
      virtual ~transfer_processor() = 0;

   private:
      virtual std::vector<unsigned char>
      serialize_data(attribute::elementfield e, attribute::VR vr) const = 0;

   protected:
      dictionary::dictionary_dyn& dict;
};

/**
 * @brief The commandset_processor class is used to (de)serialize the command
 *        set of the DICOM message, which is always encoded in little endian
 *        with implicit vr.
 */
struct commandset_processor: transfer_processor
{
   public:
      explicit commandset_processor(dictionary::dictionary_dyn& dict);

//      std::vector<unsigned char> serialize(commandset_data data) const override;
      commandset_data deserialize(std::vector<unsigned char> data) const override;

      std::string get_transfer_syntax() const override;

   private:
      virtual std::vector<unsigned char>
      serialize_data(attribute::elementfield e, attribute::VR vr) const override;
};

}

}

}


#endif // TRANSFER_PROCESSOR_HPP
