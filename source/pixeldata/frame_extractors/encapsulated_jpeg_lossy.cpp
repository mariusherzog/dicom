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

   jpeg_source_mgr fragment_src;
   fragment_src.init_source = [](j_decompress_ptr) -> void { };
   fragment_src.fill_input_buffer = [](j_decompress_ptr cptr) -> int
   {
      //current_fragment++;
      int frag = 0; // increment after each
      encapsulated* encaps_data = static_cast<encapsulated*>(cptr->client_data);
      auto compressed_pixel_data = encaps_data->get_fragment(frag);
      cptr->src->next_input_byte = static_cast<JOCTET*>(compressed_pixel_data.data());
      cptr->src->bytes_in_buffer = compressed_pixel_data.size();
      return true;
   };
   fragment_src.skip_input_data = [](j_decompress_ptr cptr, long bytes)
   {
      if (bytes < 1) return;
      cptr->src->next_input_byte += bytes;
      cptr->src->bytes_in_buffer -= bytes;
   };
   fragment_src.resync_to_restart = jpeg_resync_to_restart;
   fragment_src.term_source = [](j_decompress_ptr) {};

   fragment_src.next_input_byte = static_cast<JOCTET*>(compressed_pixel_data.data());
   fragment_src.bytes_in_buffer = compressed_pixel_data.size();

   jpeg_create_decompress(&cinfo);
   //jpeg_mem_src(&cinfo, compressed_pixel_data.data(), compressed_pixel_data.size());
   cinfo.src = &fragment_src;
   cinfo.client_data = (void*)&encapsulated_data;

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
