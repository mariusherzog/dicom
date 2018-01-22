#ifndef ENCAPSULATED_HPP
#define ENCAPSULATED_HPP

#include <vector>
#include <ostream>

#include "boost/variant.hpp"

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

   public:
      encapsulated(OFFSET_TABLE_INFO offset_table = OFFSET_TABLE_INFO::FRAGMENTS);

      bool have_compressed_frame_info() const;

      std::size_t fragment_count() const;

      /**
       * @brief push_fragment adds another fragment to the encapsulated data
       * @param data byte array of fragment data
       */
      void push_fragment(std::vector<unsigned char> data);

      std::vector<unsigned char> get_fragment(std::size_t index);

      bool marks_frame_start(std::size_t index) const;


      /**
       * @brief mark_compressed_frame_start marks the beginning of a compressed
       *        frame consisting of one or more fragments
       */
      void mark_compressed_frame_start();

};

class byte_length : public boost::static_visitor<std::size_t>
{
public:

    std::size_t operator()(const encapsulated& encapsulated_data) const
    {
        return 920080;
    }

    std::size_t operator()(const std::vector<unsigned char>& str) const
    {
        return str.size();
    }

};

class printer : public boost::static_visitor<std::ostream&>
{
    private:
        std::ostream& os;

public:
        printer(std::ostream& os): os{os}
        {

        }

    std::ostream& operator()(const encapsulated& encapsulated_data) const
    {
        return os << "tt";
    }

    std::ostream& operator()(const std::vector<unsigned char>& data) const
    {
        std::size_t printsize = std::min(data.size(), 128ul);
        std::copy(data.begin(), data.begin()+printsize, std::ostream_iterator<char>(os, " "));
        return os;
    }

};

#endif // ENCAPSULATED_HPP
