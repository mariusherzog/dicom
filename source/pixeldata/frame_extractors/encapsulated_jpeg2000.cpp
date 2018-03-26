#include "encapsulated_jpeg2000.hpp"

#include "data/attribute/encapsulated.hpp"

#include <algorithm>

#include <openjpeg-2.3/openjpeg.h>
#include <openjpeg-2.3/opj_config.h>

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
      std::size_t frame_index;
      std::size_t current_fragment;
      encapsulated& pixel_data;

      std::size_t absolute_position;
      std::size_t position_in_fragment;
      std::size_t cumulated_fragment_size;

      std::vector<unsigned char> compressed_pixel_data;

   public:
      jpeg2000_fragment_source(encapsulated& pixel_data, std::size_t frame_index):
         frame_index {frame_index},
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
         //auto compressed_pixel_data = pixel_data.get_fragment(current_fragment);

         //std::copy_n(compressed_pixel_data.begin(), bytes, buffer);

         OPJ_SIZE_T read_size = bytes;
         if (read_size > compressed_pixel_data.size() - position_in_fragment) {
            read_size = compressed_pixel_data.size() - position_in_fragment;
         }

         ::memcpy(buffer, position_in_fragment + compressed_pixel_data.data(), read_size);

         return read_size;
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
            cumulated_fragment_size += compressed_pixel_data.size();
         }
      }

      void load_at_position(std::size_t pos)
      {
         while (pos > cumulated_fragment_size) {
            ++current_fragment;
            compressed_pixel_data = pixel_data.get_fragment(current_fragment);
            cumulated_fragment_size += compressed_pixel_data.size();
         }
         position_in_fragment = pos - (cumulated_fragment_size-compressed_pixel_data.size());
      }

};

std::vector<unsigned short> encapsulated_jpeg2000::operator[](std::size_t index) const
{
   type_of<VR::OB>::type ob_pixel_data;
   get_value_field<VR::OB>(set.at({0x7fe0, 0x0010}), ob_pixel_data);
   auto encapsulated_data = boost::get<encapsulated>(ob_pixel_data);

   auto compressed_pixel_data = encapsulated_data.get_fragment(index);


//   auto fragment_read = [](void* buffer, OPJ_SIZE_T bytes, void* user_data) -> OPJ_SIZE_T
//   {
//      encapsulated* encap_data = static_cast<encapsulated*>(user_data);
//      auto compressed_pixel_data = encap_data->get_fragment(0);

//      //std::copy_n(compressed_pixel_data.begin(), bytes, buffer);

//      OPJ_SIZE_T read_size = bytes;
//      if (read_size > compressed_pixel_data.size()-offset) {
//         read_size = compressed_pixel_data.size()-offset;
//      }

//      ::memcpy(buffer, offset + compressed_pixel_data.data(), read_size);

//      return read_size;
//   };

//   auto fragment_skip = [](OPJ_OFF_T bytes, void * user_data) -> OPJ_OFF_T
//   {
//      return bytes;
//   };

//   auto fragment_seek = [](OPJ_OFF_T bytes, void * user_data) -> OPJ_BOOL
//   {
//      offset = bytes;
//      return OPJ_TRUE;
//   };

//   auto cleanup = [](void*) {};

   opj_stream_t* stream = opj_stream_default_create(true);
//   opj_stream_set_read_function(stream, fragment_read);
//   opj_stream_set_seek_function(stream, fragment_seek);
//   opj_stream_set_skip_function(stream, fragment_skip);
//   opj_stream_set_user_data(stream, static_cast<void*>(&encapsulated_data), cleanup);
//   opj_stream_set_user_data_length(stream, compressed_pixel_data.size());

   jpeg2000_fragment_source fragment_src(encapsulated_data, index);
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
   opj_stream_set_user_data_length(stream, compressed_pixel_data.size()+45896);


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
      double norm = (v - (700-(3200.0/2.0)))/3250.0;
      if (norm < 0.0) norm = 0.0;
      if (norm > 1.0) norm = 1.0;
      v = 65535.0*norm;
   }

   return data;
}
