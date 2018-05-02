#ifndef ENCAPSULATED_HPP
#define ENCAPSULATED_HPP

#include <vector>
#include <ostream>

#include "boost/variant.hpp"

#include "base_types.hpp"


namespace dicom
{

namespace data
{

namespace attribute
{


/**
 * @brief The encapsulated class manages encapsulated data consisting of
 *        fragments and possibly information about compressed frames
 */
class encapsulated
{
   public:
      enum class OFFSET_TABLE_INFO
      {
         COMPRESSED_FRAMES,
         FRAGMENTS
      };

   private:
      OFFSET_TABLE_INFO offset_table;
      std::vector<std::vector<unsigned char>> fragments;
      std::vector<std::size_t> compressed_frame_indices;

      void throw_if_no_compressed_frame_info() const;

   public:
      encapsulated(OFFSET_TABLE_INFO offset_table = OFFSET_TABLE_INFO::FRAGMENTS);

      /**
       * @brief have_compressed_frame_info checks whether there is information
       *        of compressed frames
       * @return true if compressed frame info exists, false otherwise
       */
      bool have_compressed_frame_info() const;

      /**
       * @brief fragment_count returns the number of fragments
       * @return number of fragments
       */
      std::size_t fragment_count() const;

      /**
       * @brief push_fragment adds another fragment to the encapsulated data
       * @param data byte array of fragment data
       */
      void push_fragment(std::vector<unsigned char> data);

      /**
       * @brief get_fragment retrieves the fragment at index
       * @param index fragment index to retrieve
       * @return raw fragment byte data
       */
      std::vector<unsigned char> get_fragment(std::size_t index);

      /**
       * @brief get_fragment retrieves the fragment at index
       * @param index fragment index to retrieve
       * @return raw fragment byte data
       */
      const std::vector<unsigned char>& get_fragment(std::size_t index) const;

      /**
       * @brief marks_frame_start checks whether the fragment at index is the
       *        beginning of a compressed frame
       * @param index fragment index
       * @return true if fragment is start of a frame, false otherwise
       */
      bool marks_frame_start(std::size_t index) const;

      /**
       * @brief fragment_index_of_first_frame returns the index to the first
       *        fragment of the compressed frame, in case we have a basic
       *        offset table. Throws otherwise.
       * @return first fragment of compressed frame number passed in the
       *         parameter
       */
      std::size_t fragment_index_of_first_frame(std::size_t index) const;


      /**
       * @brief mark_compressed_frame_start marks the beginning of a compressed
       *        frame consisting of one or more fragments
       */
      void mark_compressed_frame_start();

};


using ob_type = boost::variant<std::vector<unsigned char>, encapsulated>;


class byte_size : public boost::static_visitor<std::size_t>
{
   public:
       std::size_t operator()(const encapsulated& encapsulated_data) const;
       std::size_t operator()(const std::vector<unsigned char>& str) const;
};

std::size_t byte_length(const ob_type& data);

class printer : public boost::static_visitor<std::ostream&>
{
    private:
        std::ostream& os;

   public:
        printer(std::ostream& os);

        std::ostream& operator()(const encapsulated& encapsulated_data) const;
        std::ostream& operator()(const std::vector<unsigned char>& data) const;
};

std::ostream& operator<<(std::ostream& os, const ob_type& data);

}

}

}

#endif // ENCAPSULATED_HPP
