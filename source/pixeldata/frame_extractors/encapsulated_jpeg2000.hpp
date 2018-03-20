#ifndef ENCAPSULATED_JPEG2000_HPP
#define ENCAPSULATED_JPEG2000_HPP


#include "data/attribute/attribute.hpp"
#include "data/dataset/datasets.hpp"

class encapsulated_jpeg2000
{
   public:
      encapsulated_jpeg2000(const dicom::data::dataset::dataset_type& dataset);

      std::vector<unsigned short> operator[](std::size_t index) const;

   private:
      const dicom::data::dataset::dataset_type& set;
      const unsigned short samples_per_pixel;
      const unsigned short rows;
      const unsigned short cols;
};

#endif // ENCAPSULATED_JPEG2000_HPP
