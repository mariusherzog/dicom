#ifndef TAG_TYPE_HPP
#define TAG_TYPE_HPP

#include <ostream>

namespace dicom
{

namespace data
{

namespace attribute
{

struct tag_type
{
      unsigned short group_id;
      unsigned short element_id;

      tag_type(unsigned short gid = 0, unsigned short eid = 0);
};

std::ostream& operator<<(std::ostream& os, tag_type tag);

}

}

}

#endif // TAG_TYPE_HPP
