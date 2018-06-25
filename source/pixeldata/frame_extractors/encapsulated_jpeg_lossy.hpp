#ifndef ENCAPSULATED_JPEG_LOSSY_HPP
#define ENCAPSULATED_JPEG_LOSSY_HPP

#include <vector>

#include "data/attribute/attribute.hpp"
#include "data/dataset/datasets.hpp"
#include "pixeldata/frame_manipulator.hpp"
#include "pixeldata/pixeltype.hpp"

namespace dicom
{

namespace pixeldata
{

namespace frames
{

class encapsulated_jpeg_lossy : public Iframe_manipulator
{
   public:
      encapsulated_jpeg_lossy(const dicom::data::dataset::dataset_type& dataset);

      pixeltype operator[](std::size_t index) const override;

   private:
      const dicom::data::dataset::dataset_type& set;
      const unsigned short samples_per_pixel;
      const unsigned short rows;
      const unsigned short cols;
      const unsigned short bits_allocated;
      const bool is_signed;
};

}

}

}
#endif // ENCAPSULATED_JPEG_LOSSY_HPP
