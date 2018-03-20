#include "uncompressed_ow.hpp"

namespace dicom
{

namespace pixeldata
{

namespace frames
{

using namespace dicom::data::attribute;
using namespace dicom::data::dataset;

uncompressed_ow::uncompressed_ow(const dataset_type& dataset):
   set {dataset},
   samples_per_pixel {dataset.at({0x0028, 0x0002}).value<VR::US>()},
   rows {dataset.at({0x0028, 0x0010}).value<VR::US>()},
   cols {dataset.at({0x0028, 0x0011}).value<VR::US>()}
{
}

std::vector<unsigned short> uncompressed_ow::operator[](std::size_t index)
{
   auto frame_offset = samples_per_pixel*index*rows*cols;
   auto frame_length = samples_per_pixel*rows*cols;

   std::vector<unsigned short> pixel_data;
   get_value_field<VR::OW>(set.at({0x7fe0, 0x0010}), pixel_data);

   for (auto& v : pixel_data) {
      double norm = (v - (650-(1250.0/2.0)))/1250.0;
      if (norm < 0.0) norm = 0.0;
      if (norm > 1.0) norm = 1.0;
      v = 65535.0*norm;
   }

   std::vector<unsigned short> frame(pixel_data.begin()+frame_offset, pixel_data.begin()+frame_offset+frame_length);
   return frame;
}

}

}

}
