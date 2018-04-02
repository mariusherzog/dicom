#ifndef JPEG_FRAMES_HPP
#define JPEG_FRAMES_HPP

#include <utility>

#include "data/attribute/attribute.hpp"

using namespace dicom::data::attribute;

/**
 * @brief The jpeg_frames class encapsulates functionality to retrieve information about
 *        jpeg - compressed frames.
 */
class jpeg_frames
{
   private:
      const encapsulated& encapsulated_data;

   public:
      jpeg_frames(const encapsulated& encapsulated_data);

      /**
       * @brief fragments_of_frame calculates the number of fragments for the compressed frame
       *        as defined by the parameter
       * @param frame_index index of the compressed frame
       * @return half-open range of the compressed frame, ie. [start_fragment, end_fragment)
       */
      std::pair<std::size_t, std::size_t> fragments_of_frame(std::size_t frame_index) const;
};

#endif // JPEG_FRAMES_HPP

