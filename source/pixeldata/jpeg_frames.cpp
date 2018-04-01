#include "jpeg_frames.hpp"

#include <vector>

//bool marker_with_length(const unsigned char c)
//{
//   return c != 0x00 && c != 0x01 && !(c >= 0xd0 && c <= 0xd8)
//         && c != 0x4f /*JPEG2000*/;
//}

//std::size_t read_marker_length(const unsigned char ch, const unsigned char cl)
//{
//   return (ch << 8u) | cl;
//}

std::size_t determine_frame_length(const encapsulated& data, std::size_t frame_index, std::size_t& fragment_count)
{
   if (data.have_compressed_frame_info()) {
      // this belongs in encapsulated
      auto start_fragment = data.fragment_index_of_first_frame(frame_index);
      auto end_fragment = start_fragment;
      ++end_fragment;
      while (!data.marks_frame_start(end_fragment)
             && end_fragment < data.fragment_count()) {
         ++end_fragment;
      }
      std::size_t size = 0;
      for (auto i=start_fragment; i<end_fragment; ++i) {
         size += data.get_fragment(i).size();
      }
      return size;
   } else {
      // we have to traverse all fragments to even find the beginning of
      // the compressed frame.
      std::vector<std::size_t> frame_beginnings;
//      frame_beginnings.push_back(0);
//      std::size_t offset_from_last_fragment = 0;
//      for (std::size_t i = 0; i < data.fragment_count(); ++i) {
//         const auto& current_fragment = data.get_fragment(i);
//         for (std::size_t j=offset_from_last_fragment; j < current_fragment.size();) {
//            if (current_fragment[j] == 0xff && current_fragment[j+1] == 0xd9) {
//               frame_beginnings.push_back(i+1); // if i=1 < fragment_count
//               j += 2; // continue outermost loop
//               while (current_fragment[j] == 0xff) ++j;
//            } else if (current_fragment[j] == 0xff && marker_with_length(current_fragment[j+1])) {
//               auto size = read_marker_length(current_fragment[j+2], current_fragment[j+3]);
//               j += 4;
//               j += size - 2;
//               if (j >= current_fragment.size()) {
//                  offset_from_last_fragment = j - current_fragment.size();
//               }
//            } else {
//               ++j;
//            }
//         }
//      }

      frame_beginnings.push_back(0);
      for (std::size_t i = 0; i < data.fragment_count(); ++i) {
         const auto& current_fragment = data.get_fragment(i);
         for (std::size_t j = current_fragment.size()-1; j > 0; --j) {
            if (current_fragment[j] == 0xd9 && current_fragment[j-1] == 0xff) {
               frame_beginnings.push_back(i+1);
               break;
            }
         }
      }

      auto start_fragment = frame_beginnings[frame_index];
      auto end_fragment = frame_beginnings[frame_index+1];
      fragment_count = end_fragment - start_fragment;
      std::size_t size = 0;
      for (auto i=start_fragment; i<end_fragment; ++i) {
         size += data.get_fragment(i).size();
      }
      return size;
   }
}

jpeg_frames::jpeg_frames(const encapsulated& encapsulated_data):
   encapsulated_data {encapsulated_data}
{

}

std::pair<std::size_t, std::size_t> jpeg_frames::fragments_of_frame(std::size_t frame_index) const
{
   if (encapsulated_data.have_compressed_frame_info()) {
      auto start_fragment = encapsulated_data.fragment_index_of_first_frame(frame_index);
      auto end_fragment = start_fragment;
      ++end_fragment;
      while (!encapsulated_data.marks_frame_start(end_fragment)
             && end_fragment < encapsulated_data.fragment_count()) {
         ++end_fragment;
      }

      return std::make_pair(start_fragment, end_fragment);
   } else {
      std::vector<std::size_t> frame_beginnings;
      frame_beginnings.push_back(0);
      for (std::size_t i = 0; i < encapsulated_data.fragment_count(); ++i) {
         const auto& current_fragment = encapsulated_data.get_fragment(i);
         for (std::size_t j = current_fragment.size()-1; j > 0; --j) {
            if (current_fragment[j] == 0xd9 && current_fragment[j-1] == 0xff) {
               frame_beginnings.push_back(i+1);
               break;
            }
         }
      }
      auto start_fragment = frame_beginnings[frame_index];
      auto end_fragment = frame_beginnings[frame_index+1];

      return std::make_pair(start_fragment, end_fragment);
   }
}
