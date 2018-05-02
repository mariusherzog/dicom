#include "uncompressed.hpp"

#include <type_traits>

#include <boost/variant.hpp>

#include "pixeldata/image_pixel.hpp"
#include "pixeldata/rgb.hpp"

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


class extract_uncompressed
{
   private:
      const dataset_type& set;
      const std::size_t frame_offset;
      const std::size_t frame_length;
      const std::size_t samples_per_pixel;
      const VR pixeldata_vr;

      template <typename T>
      typename std::enable_if<std::is_integral<T>::value, std::vector<T>>::type
      extract_frame_impl(T)
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

      template <typename T, typename Q = typename T::base_type>
      typename std::enable_if<std::is_same<rgb<Q>, T>::value, std::vector<T>>::type
      extract_frame_impl(T)
      {
         auto data = extract_frame_impl(Q{});
         auto pixeldata = boost::get<std::vector<Q>>(data);
         std::vector<T> rgb_data;
         rgb_data.reserve(pixeldata.size()/samples_per_pixel);
         for (std::size_t i=0; i<pixeldata.size(); i += samples_per_pixel) {
            unsigned char r = pixeldata[i];
            unsigned char g = pixeldata[i+1];
            unsigned char b = pixeldata[i+2];
            rgb_data.emplace_back(r, g, b);
         }
         return rgb_data;
      }

   public:
      extract_uncompressed(const dataset_type& set, std::size_t frame_offset,
                           std::size_t frame_length, std::size_t samples_per_pixel,
                           VR pixeldata_vr):
         set {set},
         frame_offset {frame_offset},
         frame_length {frame_length},
         samples_per_pixel {samples_per_pixel},
         pixeldata_vr {pixeldata_vr}
      {
      }

      template <typename T>
      std::vector<T> operator()(std::size_t components, T)
      {
         return extract_frame_impl(T{});
      }
};


pixeltype uncompressed::operator[](std::size_t index)
{
   const std::size_t frame_length = samples_per_pixel*rows*cols;
   const std::size_t frame_offset = index*frame_length;

   const auto vr = *set.at({0x7fe0, 0x0010}).value_rep;

   extract_uncompressed extractor(set, frame_offset, frame_length, samples_per_pixel, vr);
   return extract_image(extractor, bits_allocated, samples_per_pixel, is_signed);
}

}

}

}
