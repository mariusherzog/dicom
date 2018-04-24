#ifndef UNCOMPRESSED_HPP
#define UNCOMPRESSED_HPP

#include <vector>

#include "data/attribute/attribute.hpp"
#include "data/dataset/datasets.hpp"
#include "pixeldata/pixeltype.hpp"
#include "pixeldata/rgb.hpp"

namespace dicom
{

namespace pixeldata
{

namespace frames
{

class uncompressed
{
   public:
      uncompressed(const dicom::data::dataset::dataset_type& dataset);

      pixeltype operator[](std::size_t index);

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



#endif // UNCOMPRESSED_OW_HPP
