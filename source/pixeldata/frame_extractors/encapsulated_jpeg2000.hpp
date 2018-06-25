#ifndef ENCAPSULATED_JPEG2000_HPP
#define ENCAPSULATED_JPEG2000_HPP


#include "data/attribute/attribute.hpp"
#include "data/dataset/datasets.hpp"
#include "pixeldata/pixeltype.hpp"
#include "pixeldata/frame_manipulator.hpp"

namespace dicom
{

namespace pixeldata
{

namespace frames
{


class encapsulated_jpeg2000 : public Iframe_manipulator
{
   public:
      encapsulated_jpeg2000(const dicom::data::dataset::dataset_type& dataset);

      pixeltype operator[](std::size_t index) const override;

   private:
      const dicom::data::dataset::dataset_type& set;
      const unsigned short samples_per_pixel;
      const unsigned short rows;
      const unsigned short cols;
      const unsigned short bits_allocated;
};

}

}

}

#endif // ENCAPSULATED_JPEG2000_HPP
