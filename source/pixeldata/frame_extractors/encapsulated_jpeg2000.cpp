#include "encapsulated_jpeg2000.hpp"

#include "data/attribute/encapsulated.hpp"

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

std::vector<unsigned short> encapsulated_jpeg2000::operator[](std::size_t index) const
{
   type_of<VR::OB>::type ob_pixel_data;
   get_value_field<VR::OB>(set.at({0x7fe0, 0x0010}), ob_pixel_data);
   auto encapsulated_data = boost::get<encapsulated>(ob_pixel_data);

   auto compressed_pixel_data = encapsulated_data.get_fragment(index);


   auto fragment_read = [](void* buffer, OPJ_SIZE_T bytes, void* user_data) -> OPJ_SIZE_T
   {
      encapsulated* encap_data = static_cast<encapsulated*>(user_data);
      auto compressed_pixel_data = encap_data->get_fragment(0);

      //std::copy_n(compressed_pixel_data.begin(), bytes, buffer);
      ::memcpy(buffer, compressed_pixel_data.data(), compressed_pixel_data.size());

      return bytes;
   };

   auto fragment_skip = [](OPJ_OFF_T bytes, void * user_data) -> OPJ_OFF_T
   {
      return bytes;
   };

   auto fragment_seek = [](OPJ_OFF_T bytes, void * user_data) -> OPJ_BOOL
   {
      return OPJ_TRUE;
   };

   auto cleanup = [](void*) {};

   opj_stream_t* stream = opj_stream_default_create(true);
   opj_stream_set_read_function(stream, fragment_read);
   opj_stream_set_seek_function(stream, fragment_seek);
   opj_stream_set_skip_function(stream, fragment_skip);
   opj_stream_set_user_data(stream, static_cast<void*>(&encapsulated_data), cleanup);
   opj_stream_set_user_data_length(stream, compressed_pixel_data.size());

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
      double norm = (v - (700-(3200.0/2.0)))/3200.0;
      if (norm < 0.0) norm = 0.0;
      if (norm > 1.0) norm = 1.0;
      v = 65535.0*norm;
   }

   return data;
}
