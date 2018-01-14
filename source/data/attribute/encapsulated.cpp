#include "encapsulated.hpp"

encapsulated::encapsulated(OFFSET_TABLE_INFO offset_table):
   offset_table {offset_table}
{
}

bool encapsulated::have_compressed_frame_info() const
{
   return offset_table == OFFSET_TABLE_INFO::COMPRESSED_FRAMES;
}

void encapsulated::push_fragment(std::vector<unsigned char> data)
{
   fragments.push_back(data);
}

std::vector<unsigned char> encapsulated::get_fragment(std::size_t index)
{
   return fragments[index];
}

void encapsulated::mark_compressed_frame_start()
{
   if (!have_compressed_frame_info()) {
      throw std::runtime_error("Encapsulated data object has no frame information!");
   }
   compressed_frame_indices.push_back(fragments.size());
}
