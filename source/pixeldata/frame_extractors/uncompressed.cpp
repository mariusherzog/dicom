#include "uncompressed.hpp"

#include <boost/variant.hpp>

#include <type_traits>

namespace dicom
{

namespace pixeldata
{

namespace frames
{

using namespace dicom::data::attribute;
using namespace dicom::data::dataset;


uncompressed::uncompressed(const dataset_type& dataset):
   set {dataset},
   samples_per_pixel {dataset.at({0x0028, 0x0002}).value<VR::US>()},
   rows {dataset.at({0x0028, 0x0010}).value<VR::US>()},
   cols {dataset.at({0x0028, 0x0011}).value<VR::US>()},
   bits_allocated {dataset.at({0x0028, 0x0100}).value<VR::US>()},
   is_signed {dataset.at({0x0028, 0x0103}).value<VR::US>() == 1}
{
}

template <typename T>
pixeltype extract_frame(const dataset_type& set, std::size_t frame_offset, std::size_t frame_length, VR pixeldata_vr)
{
   if (pixeldata_vr == VR::OB) {
      std::vector<unsigned char> pixel_data;
      get_value_field<VR::OB>(set.at({0x7fe0, 0x0010}), pixel_data);
      if (!std::is_same<T, unsigned short>::value) {
         std::vector<T> frame(reinterpret_cast<T*>(&pixel_data[0])+frame_offset,
                              reinterpret_cast<T*>(&pixel_data[0])+frame_offset+frame_length);
         return frame;
      } else {
         std::vector<T> frame(pixel_data.begin()+frame_offset,
                              pixel_data.begin()+frame_offset+frame_length);
         return frame;
      }
   } else {
      std::vector<unsigned short> pixel_data;
      get_value_field<VR::OW>(set.at({0x7fe0, 0x0010}), pixel_data);
      if (!std::is_same<T, unsigned short>::value) {
         std::vector<T> frame(reinterpret_cast<T*>(&pixel_data[0])+frame_offset,
                              reinterpret_cast<T*>(&pixel_data[0])+frame_offset+frame_length);
         return frame;
      } else {
         std::vector<T> frame(pixel_data.begin()+frame_offset, pixel_data.begin()+frame_offset+frame_length);
         return frame;
      }
   }
}

pixeltype uncompressed::operator[](std::size_t index)
{
   const std::size_t frame_length = samples_per_pixel*rows*cols;
   const std::size_t frame_offset = index*frame_length;

   const auto vr = *set.at({0x7fe0, 0x0010}).value_rep;

   if (samples_per_pixel == 3) {
      auto data = extract_frame<unsigned char>(set, frame_offset, frame_length, vr);
      auto pixeldata = boost::get<std::vector<unsigned char>>(data);
      std::vector<rgb<unsigned char>> rgb_data;
      rgb_data.reserve(pixeldata.size()/3);
      for (std::size_t i=0; i<pixeldata.size(); i += 3) {
         unsigned char r = pixeldata[i];
         unsigned char g = pixeldata[i+1];
         unsigned char b = pixeldata[i+2];
         rgb_data.emplace_back(r, g, b);
      }
      return rgb_data;
   }

   if (bits_allocated <= 8) {
      return extract_frame<unsigned char>(set, frame_offset, frame_length, vr);
   } else if (bits_allocated <= 16) {
      return extract_frame<unsigned short>(set, frame_offset, frame_length, vr);
   } else {
      if (is_signed) {
         return extract_frame<int>(set, frame_offset, frame_length, vr);
      } else {
         return extract_frame<unsigned int>(set, frame_offset, frame_length, vr);
      }
   }
}

}

}

}
