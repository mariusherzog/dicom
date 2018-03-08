#ifndef ENCAPSULATED_JPEG_LOSSY_HPP
#define ENCAPSULATED_JPEG_LOSSY_HPP

#include <vector>

#include "data/attribute/attribute.hpp"
#include "data/dataset/datasets.hpp"

namespace dicom
{

namespace pixeldata
{

namespace frames
{

class encapsulated_jpeg_lossy
{
   public:
      encapsulated_jpeg_lossy(const dicom::data::dataset::dataset_type& dataset);

      std::vector<unsigned char> operator[](std::size_t index);

   private:
      const dicom::data::dataset::dataset_type& set;
      /*const */unsigned short samples_per_pixel;
      unsigned short rows;
      unsigned short cols;
};

}

}

}
#endif // ENCAPSULATED_JPEG_LOSSY_HPP
