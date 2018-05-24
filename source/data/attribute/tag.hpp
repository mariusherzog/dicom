#ifndef TAG_TYPE_HPP
#define TAG_TYPE_HPP

#include <ostream>

namespace dicom
{

namespace data
{

namespace attribute
{

/**
 * @brief The tag_type struct represents a tag used as the identifier in the
 *        attribute and as a value field type for AT VRs.
 */
struct tag_type
{
      unsigned short group_id;
      unsigned short element_id;

      tag_type(unsigned short gid = 0, unsigned short eid = 0);
};

std::ostream& operator<<(std::ostream& os, const tag_type tag);

bool operator<(const tag_type& lhs, const tag_type& rhs);
bool operator==(const tag_type& lhs, const tag_type& rhs);
bool operator!=(const tag_type& lhs, const tag_type& rhs);

std::size_t byte_length(tag_type);

}

}

}

#endif // TAG_TYPE_HPP
