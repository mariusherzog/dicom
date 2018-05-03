#include "encapsulated_jpeg_lossy.hpp"

#include <boost/variant.hpp>
#include <jpeglib.h>

#include "data/attribute/encapsulated.hpp"
#include "pixeldata/jpeg_frames.hpp"
#include "pixeldata/image_pixel.hpp"

namespace dicom
{

namespace pixeldata
{

namespace frames
{

using namespace dicom::data::attribute;
using namespace dicom::data::dataset;

/**
 * @brief The jpeg_fragment_source class is used as a source manager for the
 *        jpeg library. It fetches one fragment at a time as needed.
 */
class jpeg_fragment_source
{
   private:
      std::size_t frame_index;
      std::size_t current_fragment;
      encapsulated& pixel_data;

      std::vector<unsigned char> compressed_pixel_data;

   public:
      jpeg_fragment_source(encapsulated& pixel_data, std::size_t frame_index):
         frame_index {frame_index},
         current_fragment {frame_index},
         pixel_data {pixel_data}
      {
      }

      void init_source(j_decompress_ptr cptr)
      {
         compressed_pixel_data = pixel_data.get_fragment(current_fragment);
         cptr->src->next_input_byte = static_cast<JOCTET*>(compressed_pixel_data.data());
         cptr->src->bytes_in_buffer = compressed_pixel_data.size();
      }

      int fill_input_buffer(j_decompress_ptr cptr)
      {
         ++current_fragment;
         compressed_pixel_data = pixel_data.get_fragment(current_fragment);
         cptr->src->next_input_byte = static_cast<JOCTET*>(compressed_pixel_data.data());
         cptr->src->bytes_in_buffer = compressed_pixel_data.size();
         return true;
      }

      void skip_input_data(j_decompress_ptr cptr, long bytes)
      {
         if (bytes < 1) return;
         cptr->src->next_input_byte += bytes;
         cptr->src->bytes_in_buffer -= bytes;
      }

      void term_source(j_decompress_ptr)
      {
         current_fragment = frame_index; // reset to beginning of compressed frame
      }
};


class extract_jpeg_lossy
{
   private:
      const std::size_t datasize;
      jpeg_decompress_struct* const cinfo;
      const std::size_t samples;

      template <typename T>
      typename std::enable_if<std::is_integral<T>::value, std::vector<T>>::type
      extract_frame_impl(T)
      {
         std::vector<T> uncompressed_pixel_data;
         uncompressed_pixel_data.resize(datasize);

         auto stride = cinfo->output_width * samples;

         while (cinfo->output_scanline < cinfo->output_height) {
            unsigned char* row_buffer = reinterpret_cast<unsigned char*>(&uncompressed_pixel_data[cinfo->output_scanline*stride]);
            unsigned char* buf_array[1];
            buf_array[0] = row_buffer;
            jpeg_read_scanlines(cinfo, buf_array, 1);
         }
         return uncompressed_pixel_data;
      }

      template <typename T, typename Q = typename T::base_type>
      typename std::enable_if<std::is_same<rgb<Q>, T>::value, std::vector<T>>::type
      extract_frame_impl(T)
      {
         using base_type = typename T::base_type;
         std::vector<T> uncompressed_pixel_data;
         uncompressed_pixel_data.resize(datasize);

         auto stride = cinfo->output_width * samples;

         std::vector<base_type> buffer;
         buffer.resize(3*datasize);
         while (cinfo->output_scanline < cinfo->output_height) {
            unsigned char* row_buffer = reinterpret_cast<unsigned char*>(&buffer[cinfo->output_scanline*stride]);
            unsigned char* buf_array[1];
            buf_array[0] = row_buffer;
            jpeg_read_scanlines(cinfo, buf_array, 1);
         }
         std::size_t rgb_index = 0;
         for (std::size_t i=0; i<buffer.size(); i += 3) {
            uncompressed_pixel_data[rgb_index].r = buffer[i];
            uncompressed_pixel_data[rgb_index].g = buffer[i+1];
            uncompressed_pixel_data[rgb_index].b = buffer[i+2];
            ++rgb_index;
         }
         return uncompressed_pixel_data;
      }

   public:
      extract_jpeg_lossy(jpeg_decompress_struct* decomp_struct, std::size_t frame_length, std::size_t samples):
         datasize {frame_length},
         cinfo {decomp_struct},
         samples {samples}
      {

      }


      template <typename T>
      std::vector<T> operator()(std::size_t components, T)
      {
         return extract_frame_impl(T{});
      }
};

encapsulated_jpeg_lossy::encapsulated_jpeg_lossy(const dataset_type& dataset):
    set {dataset},
    samples_per_pixel {dataset.at({0x0028, 0x0002}).value<VR::US>()},
    rows {dataset.at({0x0028, 0x0010}).value<VR::US>()},
    cols {dataset.at({0x0028, 0x0011}).value<VR::US>()},
    bits_allocated {dataset.at({0x0028, 0x0100}).value<VR::US>()},
    is_signed {dataset.at({0x0028, 0x0103}).value<VR::US>() == 1}
{
}

pixeltype encapsulated_jpeg_lossy::operator[](std::size_t index) const
{
   type_of<VR::OB>::type ob_pixel_data;
   get_value_field<VR::OB>(set.at({0x7fe0, 0x0010}), ob_pixel_data);
   auto encapsulated_data = boost::get<encapsulated>(ob_pixel_data);

   auto compressed_pixel_data = encapsulated_data.get_fragment(index);

   jpeg_frames jpeg2000_frames(encapsulated_data);
   auto fragments_of_frame = jpeg2000_frames.fragments_of_frame(index);

   // Variables for the decompressor itself
   struct jpeg_decompress_struct cinfo;
   struct jpeg_error_mgr jerr;

   cinfo.err = jpeg_std_error(&jerr);

   jpeg_fragment_source fragment_src_manager(encapsulated_data, fragments_of_frame.first);
   jpeg_source_mgr fragment_src;

   fragment_src.resync_to_restart = jpeg_resync_to_restart;

   fragment_src.init_source = [](j_decompress_ptr ptr) -> void
   {
      static_cast<jpeg_fragment_source*>(ptr->client_data)->init_source(ptr);
   };
   fragment_src.fill_input_buffer = [](j_decompress_ptr ptr) -> int
   {
      return static_cast<jpeg_fragment_source*>(ptr->client_data)->fill_input_buffer(ptr);
   };
   fragment_src.skip_input_data = [](j_decompress_ptr ptr, long bytes)
   {
      static_cast<jpeg_fragment_source*>(ptr->client_data)->skip_input_data(ptr, bytes);
   };
   fragment_src.term_source = [](j_decompress_ptr ptr) -> void
   {
      static_cast<jpeg_fragment_source*>(ptr->client_data)->term_source(ptr);
   };

   jpeg_create_decompress(&cinfo);
   cinfo.src = &fragment_src;
   cinfo.client_data = static_cast<void*>(&fragment_src_manager);

   if (jpeg_read_header(&cinfo, true) != 1) {
      throw std::runtime_error("error reading jpeg header");
   }

   jpeg_start_decompress(&cinfo);

   int width = cinfo.output_width;
   int height = cinfo.output_height;
   int samples = cinfo.num_components;

   extract_jpeg_lossy extractor(&cinfo, width*height, samples);
   auto decompressed = extract_image(extractor, bits_allocated, samples, is_signed);

   jpeg_finish_decompress(&cinfo);
   jpeg_destroy_decompress(&cinfo);

   return decompressed;

}

}

}

}
