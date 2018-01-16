#ifndef TRANSFER_PROCESSOR_HPP
#define TRANSFER_PROCESSOR_HPP

#include <vector>
#include <string>

#include "datasets.hpp"
#include "data/dictionary/dictionary.hpp"
#include "data/dictionary/datadictionary.hpp"
#include "data/dictionary/dictionary_dyn.hpp"
#include "data/attribute/attribute.hpp"
#include "util/channel_sev_logger.hpp"

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

class transfer_processor;

std::vector<std::string> supported_transfer_syntaxes();

std::unique_ptr<transfer_processor> make_transfer_processor(std::string transfer_syntax_uid, dictionary::dictionaries& dict);

/**
 * @brief The transfer_processor class defines the interface for serializing
 *        and deserializing attribute sets (IODs), honoring the transfer
 *        syntax
 * This abstraction shall be mapped by the DIMSE layer to each transfer syntax
 * it wants to offer for each presentation context.
 */
class transfer_processor
{
   protected:
      /**
       * @brief The VR_TYPE enum defines if an explicit VR is used in the
       *        transfer syntax.
       */
      enum class VR_TYPE
      {
         IMPLICIT, EXPLICIT
      };

      /**
       * @brief The vr_of_tag struct defines a transfer-syntax specific mapping
       *        of a tag (range) to a VR.
       */
      struct vr_of_tag
      {
            const attribute::tag_type tag;
            const unsigned eid_mask;
            const unsigned gid_mask;

            const attribute::VR vr;

            vr_of_tag(attribute::tag_type tag,
                      attribute::VR vr,
                      unsigned eid_mask = 0xffff,
                      unsigned gid_mask = 0xffff);
      };

      /**
       * @brief transfer_processor constructor
       * @param dict optional dictionary, only necessary for implicit VR TSs
       * @param tfs transfer syntax UID
       * @param vrtype enum instance defining if the ts is [ex|im]plicit VR.
       * @param tstags list of transfer-syntax-specific tag-to-VR-mapping
       */
      transfer_processor(boost::optional<dictionary::dictionaries&> dict,
                         std::string tfs,
                         VR_TYPE vrtype,
                         attribute::ENDIANNESS endianness,
                         std::initializer_list<vr_of_tag> tstags = {});

      transfer_processor(const transfer_processor& other);

      /**
       * @brief get_vr returns the VR of a given tag, honoring transfer-syntax
       *        specific settings specified by a subclass.
       * @param tag tag of the VR to be looked for
       * @return VR associated with the tag
       */
      attribute::VR get_vr(attribute::tag_type tag) const;

      dicom::data::dictionary::dictionaries& get_dictionary() const;

   public:

      /**
       * @brief serialize is used to serialize an iod / command set
       * @param data structured dataset to be serialized
       * @return bytestream of serialized data
       */
      std::vector<unsigned char> serialize(iod data) const;

      /**
       * @brief deserialize shall be called to deserialize a datastream into
       *        a structured attribute
       * @param data datastream
       * @return structured attribute
       */
      dataset_type deserialize(std::vector<unsigned char> data) const;

      /**
       * @brief get_transfer_syntax is used to acquire the UID of the classe's
       *        implemented transfer syntax.
       * @return UID of the transfer syntax
       */
      std::string get_transfer_syntax() const;

      std::size_t dataelement_length(const dicom::data::attribute::elementfield& ef) const;

      virtual ~transfer_processor();

   private:
      /**
       * @brief serialize_attribute is overriden by a subclass to implement
       *        transfer-syntax specific serialization of data.
       * @param e attribute
       * @param vr VR of the attribute
       * @return vector of bytes with serialized data
       */
      virtual std::vector<unsigned char>
      serialize_attribute(attribute::elementfield e, attribute::ENDIANNESS end, attribute::VR vr) const = 0;

      /**
       * @brief deserialize_attribute is overriden by a subclass to implement
       *        transfer-syntax specific deserialization of data.
       * @param data array containing serialized bytes
       * @param len length of the attribute's data field
       * @param vr VR of the attribute
       * @param pos starting position of the data field in the serialized array
       * @return elementfield with structured data
       */
      virtual attribute::elementfield
      deserialize_attribute(std::vector<unsigned char>& data,
                            attribute::ENDIANNESS end,
                            std::size_t len, attribute::VR vr, std::string vm,
                            std::size_t pos) const = 0;

      /**
       * @brief deserialize_VR deserializes and returns the VR, which may be
       *        explicit or implicit.
       * @param dataset serialized data
       * @param tag tag of the current attribute
       * @param[in, out] pos
       * @return deserialized VR
       */
      attribute::VR deserialize_VR(std::vector<unsigned char> dataset,
                                   attribute::tag_type tag,
                                   std::size_t& pos) const;

      /**
       * @brief deserialize_length deserializes and returns the length of the
       *        value field of the current attribute
       * @param dataset serialized data
       * @param tag tag of the current attribute
       * @param[in, out] pos
       * @return length of the value field
       */
      std::size_t deserialize_length(std::vector<unsigned char> dataset,
                                     attribute::tag_type tag,
                                     attribute::VR repr,
                                     std::size_t& pos) const;

      /**
       * @brief find_enclosing is used to determine the size of the nested set if it
       *        is not explicitly specified.
       * @todo convert this recursive function into an iterative one
       * @param data serialized dataset
       * @param explicitvr true if vr is explicit, false otherwise
       * @param endianness endianness of the data stream
       * @param beg first element
       * @param dict dictionary for the tag lookup
       * @return size of the nested set
       */
      std::size_t find_enclosing(std::vector<unsigned char> data, std::size_t beg) const;

      /**
       * @brief calculate_item_lengths calculates the correct sequence and item lengths
       *        given the specified transfer syntax.
       * @param dataset dataset which will receive updated length values
       * @return byte length of the set given in the parameter minus any item and / or
       *         sequence sizes which are undefined length.
       */
      std::size_t calculate_item_lengths(data::dataset::dataset_type& dataset) const;

      std::vector<vr_of_tag> tstags;

      boost::optional<dictionary::dictionaries&> dict;
      std::string transfer_syntax;
      VR_TYPE vrtype;
      attribute::ENDIANNESS endianness;

   protected:
      mutable dicom::util::log::channel_sev_logger logger;
};

/**
 * @brief The commandset_processor class is used to (de)serialize the command
 *        set of the DICOM message, which is always encoded in little endian
 *        with implicit vr.
 */
class commandset_processor: public transfer_processor
{
   public:
      explicit commandset_processor(dictionary::dictionaries& dict);

   private:
      virtual std::vector<unsigned char>
      serialize_attribute(attribute::elementfield e, attribute::ENDIANNESS end, attribute::VR vr) const override;

      virtual attribute::elementfield
      deserialize_attribute(std::vector<unsigned char>& data,
                            attribute::ENDIANNESS end,
                            std::size_t len, attribute::VR vr, std::string vm,
                            std::size_t pos) const override;
};

/**
 * @brief The little_endian_implicit class implements the little endian implicit
 *        transfer syntax.
 */
class little_endian_implicit: public transfer_processor
{
   public:
      explicit little_endian_implicit(dictionary::dictionaries& dict);

      little_endian_implicit(const little_endian_implicit& other);

   private:
      virtual std::vector<unsigned char>
      serialize_attribute(attribute::elementfield e, attribute::ENDIANNESS end, attribute::VR vr) const;

      virtual attribute::elementfield
      deserialize_attribute(std::vector<unsigned char>& data, attribute::ENDIANNESS end,
                            std::size_t len, attribute::VR vr, std::string vm,
                            std::size_t pos) const;
};

class little_endian_explicit: public transfer_processor
{
   public:
      explicit little_endian_explicit(dictionary::dictionaries& dict);

   private:
      virtual std::vector<unsigned char>
      serialize_attribute(attribute::elementfield e, attribute::ENDIANNESS end, attribute::VR vr) const;

      virtual attribute::elementfield
      deserialize_attribute(std::vector<unsigned char>& data,
                            attribute::ENDIANNESS end,
                            std::size_t len, attribute::VR vr, std::string vm,
                            std::size_t pos) const;
};

class big_endian_explicit: public transfer_processor
{
   public:
      explicit big_endian_explicit(dictionary::dictionaries& dict);

   private:
      virtual std::vector<unsigned char>
      serialize_attribute(attribute::elementfield e, attribute::ENDIANNESS end, attribute::VR vr) const;

      virtual attribute::elementfield
      deserialize_attribute(std::vector<unsigned char>& data,
                            attribute::ENDIANNESS end,
                            std::size_t len, attribute::VR vr, std::string vm,
                            std::size_t pos) const;
};



/**
 * @brief dataset_bytesize calculates the size in bytes of a dataset given a
 *        certain transfer syntax.
 * @param data dataset
 * @param transfer_proc represents the underlying transfer syntax for the
 *        calculation
 * @return size of the dataset in bytes
 */
std::size_t dataset_bytesize(dataset_type data, const transfer_processor& transfer_proc);


}

}

}


#endif // TRANSFER_PROCESSOR_HPP
