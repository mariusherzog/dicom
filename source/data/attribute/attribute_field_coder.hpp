#ifndef ATTRIBUTE_FIELD_CODER_HPP
#define ATTRIBUTE_FIELD_CODER_HPP

#include <vector>

#include "data/dataset/datasets.hpp"
#include "data/attribute/attribute.hpp"

namespace dicom
{

namespace data
{

namespace attribute
{

/**
 * @brief encode_value_field converts the attribute into a serialized representation.
 * @param attr attribute to be encoded
 * @param endianness endiannes of the to-be-encoded data
 * @param vr VR of given attribute
 * @return vector of bytes representing the attribute
 */
std::vector<unsigned char> encode_value_field(elementfield attr, ENDIANNESS endianness, const VR vr);

/**
 * @brief decode_value_field converts a serialized attribute into a structured
 *        elementfield representation.
 * @param data stream with serialized data
 * @param endianness endiannes of the to-be-decoded data
 * @param len length of the value field
 * @param vr vr of the value field
 * @param begin beginning, as in absolute position from the data stream start,
 *        of the value field
 * @return instance of elementfield
 *
 * This function takes already parsed elementfield data like tag, length and vr
 * as a parameter, parses the respective value field, and returns an instance of
 * elementfield which contains all the data.
 */
elementfield decode_value_field(const std::vector<unsigned char>& data, ENDIANNESS endianness, std::size_t len, VR vr, std::string vm, int begin);


/**
 * @brief encode_tag converts the element tag into serialized representation of
 *        8 bytes
 * @param tag tag to be encoded
 * @param endianness endianness of the encoded stream
 * @return vector of bytes representing the tag
 */
std::vector<unsigned char> encode_tag(tag_type tag, ENDIANNESS endianness);

/**
 * @brief encode_len converts a length of a value field into a 4-byte serialized
 *        representation.
 * @param lenbytes size in bytes of the length field
 * @param len length
 * @param endianness endianness of the encoded stream
 * @return 4 bytes of the parameter length in little endian
 */
std::vector<unsigned char> encode_len(std::size_t lenbytes, std::size_t len, ENDIANNESS endianness);

/**
 * @brief decode_tag transforms the serialized tag data into a structured form.
 * @param data serialized stream data
 * @param begin beginning, as in absolute position from the data stream start,
 *        of the value field
 * @param endianness of the encoded data
 * @return instance of tag_type with the tag elements
 */
tag_type decode_tag(const std::vector<unsigned char>& data, int begin, ENDIANNESS endianness);

/**
 * @brief decode_len transforms the serialized length data into a structured
 *        form.
 * @param data serialized stream data
 * @param endianness endianness of the data stream
 * @param lenbytes size in bytes of the length field
 * @param begin beginning, as in absolute position from the data stream start,
 *        of the value field
 * @return length specified in the serialized stream data
 */
std::size_t decode_len(const std::vector<unsigned char>& data, ENDIANNESS endianness, std::size_t lenbytes, int begin);



}

}

}

#endif // ATTRIBUTE_FIELD_CODER_HPP
