#ifndef UNCOMPRESSED_OW_HPP
#define UNCOMPRESSED_OW_HPP

#include <vector>

#include "data/attribute/attribute.hpp"
#include "data/dataset/datasets.hpp"

namespace dicom
{

namespace pixeldata
{

namespace frames
{

class uncompressed_ow
{
   public:
      uncompressed_ow(const dicom::data::dataset::dataset_type& dataset);

      std::vector<unsigned short> operator[](std::size_t index);

   private:
      const dicom::data::dataset::dataset_type& set;
      /*const */unsigned short samples_per_pixel;
      unsigned short rows;
      unsigned short cols;
};

}

}

}



#endif // UNCOMPRESSED_OW_HPP
