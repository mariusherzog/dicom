#ifndef ATTRIBUTE_FIELD_CODER_HPP
#define ATTRIBUTE_FIELD_CODER_HPP

#include <vector>

#include "../attributedata/iod.hpp"



std::vector<unsigned char> decode_little_endian(elementfield attr, const VR vr);

std::vector<unsigned char> decode_tag_little_endian(elementfield::tag_type tag);

std::vector<unsigned char> decode_len_little_endian(std::size_t len);

#endif // ATTRIBUTE_FIELD_CODER_HPP
