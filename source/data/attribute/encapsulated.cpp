#include "encapsulated.hpp"

namespace dicom
{

namespace data
{

namespace attribute
{


void encapsulated::throw_if_no_compressed_frame_info() const
{
   if (!have_compressed_frame_info()) {
      throw std::runtime_error("Encapsulated data object has no frame information!");
   }
}

encapsulated::encapsulated(OFFSET_TABLE_INFO offset_table):
   offset_table {offset_table}
{
}

bool encapsulated::have_compressed_frame_info() const
{
    return offset_table == OFFSET_TABLE_INFO::COMPRESSED_FRAMES;
}

std::size_t encapsulated::fragment_count() const
{
    return fragments.size();
}

void encapsulated::push_fragment(std::vector<unsigned char> data)
{
   fragments.push_back(data);
}

std::vector<unsigned char> encapsulated::get_fragment(std::size_t index)
{
    return fragments[index];
}

const std::vector<unsigned char>& encapsulated::get_fragment(std::size_t index) const
{
   return fragments[index];
}

bool encapsulated::marks_frame_start(std::size_t index) const
{
   throw_if_no_compressed_frame_info();
   return std::find(compressed_frame_indices.begin(), compressed_frame_indices.end(), index)
            != compressed_frame_indices.end();
}

void encapsulated::mark_compressed_frame_start()
{
   throw_if_no_compressed_frame_info();
   compressed_frame_indices.push_back(fragments.size());
}

}

}

}
