#ifndef DICOMFILE_HPP
#define DICOMFILE_HPP

#include <iostream>
#include <memory>

#include <boost/filesystem.hpp>

#include "data/dataset/datasets.hpp"
#include "data/dataset/transfer_processor.hpp"

namespace dicom
{

namespace filesystem
{

/**
 * @brief The dicomfile class encapsulates a dicom dataset / iod for writing to
 *        a stream in the format as specified by DICOM standard part 10
 *        chapter 7.
 */
class dicomfile
{
   private:
      dicom::data::dataset::iod dataset;

      std::array<unsigned char, 128> preamble;
      std::array<unsigned char, 4> prefix;

      dicom::data::dictionary::dictionary& dict;
      std::unique_ptr<dicom::data::dataset::transfer_processor> transfer_proc;

   public:
      /**
       * @brief dicomfile , ctor
       * @param dataset dataset which shall be written to a stream in binary
       * @param dict dictionary to be used, applies to little endian vr
       */
      dicomfile(dicom::data::dataset::iod dataset,
                dicom::data::dictionary::dictionary& dict);

      /**
       * @brief write_dataset writes the iod to the given stream in binary
       * @param os stream to write into
       * @return stream written to
       */
      std::ostream& write_dataset(std::ostream& os);
};

std::ostream& operator<<(std::ostream& os, dicomfile& dicom);

}

}





#endif // DICOMFILE_HPP
