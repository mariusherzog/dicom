#include "encapsulated_jpeg_lossy.hpp"

#include <boost/variant.hpp>
#include <jpeglib.h>

#include "data/attribute/encapsulated.hpp"

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

   public:
      jpeg_fragment_source(encapsulated& pixel_data, std::size_t frame_index):
         frame_index {frame_index},
         current_fragment {frame_index},
         pixel_data {pixel_data}
      {
      }

      void init_source(j_decompress_ptr) {}

      int fill_input_buffer(j_decompress_ptr cptr)
      {
         ++current_fragment;
         auto compressed_pixel_data = pixel_data.get_fragment(current_fragment);
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

encapsulated_jpeg_lossy::encapsulated_jpeg_lossy(const dataset_type& dataset):
    set {dataset}
{
    samples_per_pixel = 1;
    //get_value_field<VR::US>(dataset.at({0x0028, 0x0002}), samples_per_pixel);
    get_value_field<VR::US>(dataset.at({0x0028, 0x0010}), rows);
    get_value_field<VR::US>(dataset.at({0x0028, 0x0011}), cols);
}


std::vector<unsigned char> encapsulated_jpeg_lossy::operator[](std::size_t index)
{
   type_of<VR::OB>::type ob_pixel_data;
   get_value_field<VR::OB>(set.at({0x7fe0, 0x0010}), ob_pixel_data);
   auto encapsulated_data = boost::get<encapsulated>(ob_pixel_data);

   auto compressed_pixel_data = encapsulated_data.get_fragment(index);
   auto current_fragment = index;
   auto skip = -1;

   // Variables for the decompressor itself
   struct jpeg_decompress_struct cinfo;
   struct jpeg_error_mgr jerr;

   cinfo.err = jpeg_std_error(&jerr);

   jpeg_fragment_source fragment_src_manager(encapsulated_data, index);
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



   fragment_src.next_input_byte = static_cast<JOCTET*>(compressed_pixel_data.data());
   fragment_src.bytes_in_buffer = compressed_pixel_data.size();

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

   std::vector<unsigned char> uncompressed_pixel_data(width*height*samples);
   uncompressed_pixel_data.resize(width*height*samples);

   int stride = width * samples;

   while (cinfo.output_scanline < cinfo.output_height) {
//      std::vector<unsigned char> scanline_buffer;
//      scanline_buffer.resize(cinfo.output_scanline*stride);
      unsigned char* row_buffer = &uncompressed_pixel_data[cinfo.output_scanline*stride];
      unsigned char* buf_array[1];
      buf_array[0] = row_buffer;
      jpeg_read_scanlines(&cinfo, buf_array, 1);
   }

   jpeg_finish_decompress(&cinfo);

   jpeg_destroy_decompress(&cinfo);

   return uncompressed_pixel_data;

}

}

}

}
