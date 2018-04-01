#include "encapsulated_jpeg2000.hpp"

#include "data/attribute/encapsulated.hpp"
#include "pixeldata/jpeg_frames.hpp"

#include <algorithm>

//#include <openjpeg-2.3/openjpeg.h>
//#include <openjpeg-2.3/opj_config.h>
#include <openjpeg.h>

using namespace dicom::data::attribute;
using namespace dicom::data::dataset;


encapsulated_jpeg2000::encapsulated_jpeg2000(const dataset_type& dataset):
    set {dataset},
    samples_per_pixel {dataset.at({0x0028, 0x0002}).value<VR::US>()},
    rows {dataset.at({0x0028, 0x0010}).value<VR::US>()},
    cols {dataset.at({0x0028, 0x0011}).value<VR::US>()}
{

}

class jpeg2000_fragment_source
{
   private:
      const std::size_t frame_index;
      const std::size_t fragments_of_frame;
      std::size_t current_fragment;
      encapsulated& pixel_data;

      std::size_t absolute_position;
      std::size_t position_in_fragment;
      std::size_t cumulated_fragment_size;

      std::vector<unsigned char> compressed_pixel_data;

   public:
      jpeg2000_fragment_source(encapsulated& pixel_data, std::size_t frame_index, std::size_t fragments_of_frame):
         frame_index {frame_index},
         fragments_of_frame {fragments_of_frame},
         current_fragment {frame_index},
         pixel_data {pixel_data},
         absolute_position {0},
         position_in_fragment {0},
         cumulated_fragment_size {0}
      {
      }

      OPJ_SIZE_T read(void* buffer, OPJ_SIZE_T bytes, void* user_data)
      {
         fill_compressed_pixel_data_if_necessary();

         static std::size_t total_written = 0;
         std::size_t written = 0;

         OPJ_SIZE_T remaining_bytes = bytes;
         do {
            OPJ_SIZE_T read_size = remaining_bytes;
            if (read_size > compressed_pixel_data.size() - position_in_fragment) {
               read_size = compressed_pixel_data.size() - position_in_fragment;
            }

            std::copy_n(position_in_fragment + compressed_pixel_data.data(), read_size, (char*)buffer + written);
            written += read_size;
            total_written += read_size;
            remaining_bytes -= read_size;

            seek(total_written, user_data);
         } while (written < bytes && current_fragment < fragments_of_frame-1);

         total_written = written;
         return written;
      }

      OPJ_OFF_T skip(OPJ_OFF_T bytes, void* user_data)
      {
         fill_compressed_pixel_data_if_necessary();
         auto skip_offset = absolute_position+bytes;
         absolute_position = skip_offset;
         load_at_position(absolute_position);
         return bytes;
      }

      OPJ_BOOL seek(OPJ_OFF_T bytes, void* user_data)
      {
         fill_compressed_pixel_data_if_necessary();
         absolute_position = bytes;
         load_at_position(absolute_position);
         return OPJ_TRUE;
      }

   private:
      void fill_compressed_pixel_data_if_necessary()
      {
         if (compressed_pixel_data.empty()) {
            compressed_pixel_data = pixel_data.get_fragment(current_fragment);
         }
      }

      void load_at_position(std::size_t pos)
      {
         if (pos - cumulated_fragment_size >= compressed_pixel_data.size())
         {
            while (pos > cumulated_fragment_size /* + compressed size */
                   && current_fragment+1 < fragments_of_frame) {
               ++current_fragment;
               cumulated_fragment_size += compressed_pixel_data.size();
               compressed_pixel_data = pixel_data.get_fragment(current_fragment);
            }
         }

         position_in_fragment = pos - (cumulated_fragment_size);

      }

};

std::vector<unsigned short> encapsulated_jpeg2000::operator[](std::size_t index) const
{
   type_of<VR::OB>::type ob_pixel_data;
   get_value_field<VR::OB>(set.at({0x7fe0, 0x0010}), ob_pixel_data);
   auto encapsulated_data = boost::get<encapsulated>(ob_pixel_data);

   auto compressed_pixel_data = encapsulated_data.get_fragment(index);

   opj_stream_t* stream = opj_stream_default_create(true);

   jpeg_frames jpeg2000_frames(encapsulated_data);
   auto fragments_of_frame = jpeg2000_frames.fragments_of_frame(index);
   std::size_t frame_length = 0;

   for (int i=fragments_of_frame.first; i<fragments_of_frame.second; ++i) {
      frame_length += encapsulated_data.get_fragment(i).size();
   }

   jpeg2000_fragment_source fragment_src(encapsulated_data, index, fragments_of_frame.second - fragments_of_frame.first);
   auto fragment_read = [](void* buffer, OPJ_SIZE_T bytes, void* user_data) -> OPJ_SIZE_T
   {
      return static_cast<jpeg2000_fragment_source*>(user_data)->read(buffer, bytes, user_data);
   };

   auto fragment_seek = [](OPJ_OFF_T bytes, void * user_data) -> OPJ_BOOL
   {
      return static_cast<jpeg2000_fragment_source*>(user_data)->seek(bytes, user_data);
   };

   auto fragment_skip = [](OPJ_OFF_T bytes, void * user_data) -> OPJ_OFF_T
   {
      return static_cast<jpeg2000_fragment_source*>(user_data)->skip(bytes, user_data);
   };

   auto cleanup = [](void*) {};

   opj_stream_set_read_function(stream, fragment_read);
   opj_stream_set_seek_function(stream, fragment_seek);
   opj_stream_set_skip_function(stream, fragment_skip);
   opj_stream_set_user_data(stream, static_cast<void*>(&fragment_src), cleanup);
   opj_stream_set_user_data_length(stream, frame_length);


   opj_dparameters_t params;
   opj_set_default_decoder_parameters(&params);

   params.decod_format = 0;
   opj_codec_t* codec = opj_create_decompress(OPJ_CODEC_J2K);

   opj_setup_decoder(codec, &params);

   opj_image* image;
   opj_read_header(stream, codec, &image);

   opj_decode(codec, stream, image);

   opj_end_decompress(codec, stream);
   opj_destroy_codec(codec);

   auto datasize = (image->numcomps) * (image->comps[0].w) * (image->comps[0].h);

   std::vector<unsigned short> data;
   data.resize(datasize);
   for (int i=0; i<image->comps[0].w * image->comps[0].h; ++i) {
      unsigned short g = image->comps[0].data[i];
      g += (image->comps[0].sgnd ? 1 << (image->comps[0].prec - 1) : 0);
      data[i] = g;
   }


   for (auto& v : data) {
      double norm = (v - (511-(1024.0/2.0)))/1024.0;
      if (norm < 0.0) norm = 0.0;
      if (norm > 1.0) norm = 1.0;
      v = 65535.0*norm;
   }

   return data;
}