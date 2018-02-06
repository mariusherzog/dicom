#ifndef DICOMFILE_HPP
#define DICOMFILE_HPP

#include <iostream>
#include <memory>

#include <boost/filesystem.hpp>

#include "data/dataset/datasets.hpp"
#include "data/dataset/transfer_processor.hpp"
#include "util/channel_sev_logger.hpp"

namespace dicom
{

namespace filesystem
{

/**
 * @brief The dicomfile class encapsulates a dicom dataset / iod for writing to
 *        and reading from a stream in the format as specified by DICOM standard
 *        part 10 chapter 7.
 */
class dicomfile
{
   private:
      dicom::data::dataset::iod dataset_;
      dicom::data::dataset::iod filemetaheader;

      std::array<unsigned char, 128> preamble;
      std::array<unsigned char, 4> prefix;

      dicom::data::dictionary::dictionaries& dict;
      std::unique_ptr<dicom::data::dataset::transfer_processor> metaheader_proc;
      std::unique_ptr<dicom::data::dataset::transfer_processor> transfer_proc;

      util::log::channel_sev_logger logger;

      /**
       * @brief create_filemetaheader creates the meta file header (0002 group)
       *        using information from the dicom dataset to be written.
       */
      void create_filemetaheader();

   public:
      /**
       * @brief dicomfile , ctor
       * @param dataset dataset which shall be written to a stream in binary
       * @param dict dictionary to be used, applies to little endian vr
       */
      dicomfile(dicom::data::dataset::iod dataset,
                dicom::data::dictionary::dictionaries& dict);

      /**
       * @brief write_dataset writes the iod to the given stream in binary
       * @param os stream to write into
       * @return stream written to
       */
      std::ostream& write_dataset(std::ostream& os);

      /**
       * @brief read_dataset reads from the given stream in binary
       * @param is stream to read from
       * @return stream read from
       */
      std::istream& read_dataset(std::istream& is);

      /**
       * @brief set_transfer_syntax explicitly sets the transfer syntax used to
       *        read or write the dataset (excluding the file meta header)
       * @param transfer_syntax UID of the requested transfer syntax
       */
      void set_transfer_syntax(std::string transfer_syntax);

      /**
       * @brief dataset is used to access the dataset, for example to access
       *        dataset read from stream
       * @return dataset encapsulated in this instance
       */
      dicom::data::dataset::iod& dataset();
};

std::ostream& operator<<(std::ostream& os, dicomfile& dicom);

std::istream& operator>>(std::istream& is, dicomfile& dicom);

}

}





#endif // DICOMFILE_HPP
