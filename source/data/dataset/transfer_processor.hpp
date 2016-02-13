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
   protected:
      enum class VR_TYPE
      {
         IMPLICIT, EXPLICIT
      };

   public:
      transfer_processor(boost::optional<dictionary::dictionary_dyn&> dict, std::string tfs, VR_TYPE vrtype);

      std::vector<unsigned char> serialize(iod data) const;
      iod deserialize(std::vector<unsigned char> data) const;
      std::string get_transfer_syntax() const;

      virtual ~transfer_processor();

   private:
      virtual std::vector<unsigned char>
      serialize_attribute(attribute::elementfield e, attribute::VR vr) const = 0;

      virtual attribute::elementfield
      deserialize_attribute(std::vector<unsigned char>& data,
                            attribute::elementfield::tag_type tag,
                            std::size_t len, attribute::VR vr,
                            std::size_t pos) const = 0;

      boost::optional<dictionary::dictionary_dyn&> dict;
      std::string transfer_syntax;
      VR_TYPE vrtype;
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

   private:
      virtual std::vector<unsigned char>
      serialize_attribute(attribute::elementfield e, attribute::VR vr) const override;

      virtual attribute::elementfield
      deserialize_attribute(std::vector<unsigned char>& data,
                                                    attribute::elementfield::tag_type tag,
                                                    std::size_t len, attribute::VR vr,
                                                    std::size_t pos) const override;
};

}

}

}


#endif // TRANSFER_PROCESSOR_HPP
