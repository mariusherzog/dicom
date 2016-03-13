#ifndef ATTRIBUTE_FIELD_CODER_HPP
#define ATTRIBUTE_FIELD_CODER_HPP

#include <vector>

#include "data/dataset/datasets.hpp"

namespace dicom
{

namespace data
{

namespace attribute
{

/**
 * @brief encode_little_endian converts the attribute into a serialized little
 *        endian representation.
 * @param attr attribute to be encoded
 * @param vr VR of given attribute
 * @return vector of bytes representing the attribute
 */
std::vector<unsigned char> encode_little_endian(elementfield attr, const VR vr);

/**
 * @brief decode_little_endian converts a serialized attribute into a structured
 *        elementfield representation.
 * @param data stream with serialized data
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
elementfield decode_little_endian(const std::vector<unsigned char>& data, std::size_t len, VR vr, int begin);

/**
 * @brief encode_tag_little_endian converts the element tag into a little endian
 *        representation of 8 bytes
 * @param tag tag to be encoded
 * @return vector of bytes representing the tag in little endian
 */
std::vector<unsigned char> encode_tag_little_endian(elementfield::tag_type tag);

/**
 * @brief encode_len_little_endian converts a length of a value field into
 *        a 4-byte little endian representation.
 * @param len length
 * @return 4 bytes of the parameter length in little endian
 */
std::vector<unsigned char> encode_len_little_endian(bool explicitvr, std::size_t len);

/**
 * @brief decode_tag_little_endian transforms the serialized tag data into a
 *        structured form.
 * @param data serialized stream data
 * @param begin beginning, as in absolute position from the data stream start,
 *        of the value field
 * @return instance of tag_type with the tag elements
 */
elementfield::tag_type decode_tag_little_endian(const std::vector<unsigned char>& data, int begin);

/**
 * @brief decode_len_little_endian transforms the serialized length data into a
 *        structured form.
 * @param data serialized stream data
 * @param begin beginning, as in absolute position from the data stream start,
 *        of the value field
 * @return length specified in the serialized stream data
 */
std::size_t decode_len_little_endian(const std::vector<unsigned char>& data, bool explicitvr, int begin);

}

}

}

#endif // ATTRIBUTE_FIELD_CODER_HPP
