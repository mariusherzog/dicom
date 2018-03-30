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

         static std::size_t total_written = 0;
         std::size_t written = 0;

         std::size_t initial_position = position_in_fragment;
         OPJ_SIZE_T remaining_bytes = bytes;
         while (written < bytes) {
            OPJ_SIZE_T read_size = remaining_bytes;
            if (read_size > compressed_pixel_data.size() - position_in_fragment) {
               read_size = compressed_pixel_data.size() - position_in_fragment;
            }

            ::memcpy((char*)buffer + written, position_in_fragment + compressed_pixel_data.data(), read_size);
            written += read_size;
            total_written += read_size;
            remaining_bytes -= read_size;

            if (current_fragment >= pixel_data.fragment_count()-1) {
               break;
            }

            //load_at_position(position_in_fragment+cumulated_fragment_size+compressed_pixel_data.size());
            //load_at_position(written);
            seek(total_written, user_data);
         }
//         seek(initial_position, user_data);
         // reset
//         position_in_fragment = initial_position;
//         cumulated_fragment_size = 0;
//         current_fragment = frame_index;
//         absolute_position = 0; // todo remove
//         compressed_pixel_data = pixel_data.get_fragment(current_fragment);
//         position_in_fragment = initial_position;
//         load_at_position(initial_position);

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
                   && current_fragment+1 < pixel_data.fragment_count()) {
               ++current_fragment;
               cumulated_fragment_size += compressed_pixel_data.size();
               compressed_pixel_data = pixel_data.get_fragment(current_fragment);
            }
         }

         position_in_fragment = pos - (cumulated_fragment_size);

      }

};

//bool marker_with_length(const unsigned char c)
//{
//   return c != 0x00 && c != 0x01 && !(c >= 0xd0 && c <= 0xd8)
//         && c != 0x4f /*JPEG2000*/;
//}

//std::size_t read_marker_length(const unsigned char ch, const unsigned char cl)
//{
//   return (ch << 8u) | cl;
//}

std::size_t determine_frame_length(const encapsulated& data, std::size_t frame_index)
{
   if (data.have_compressed_frame_info()) {
      // this belongs in encapsulated
      auto start_fragment = data.fragment_index_of_first_frame(frame_index);
      auto end_fragment = start_fragment;
      ++end_fragment;
      while (!data.marks_frame_start(end_fragment)
             && end_fragment < data.fragment_count()) {
         ++end_fragment;
      }
      std::size_t size = 0;
      for (auto i=start_fragment; i<end_fragment; ++i) {
         size += data.get_fragment(i).size();
      }
      return size;
   } else {
      // we have to traverse all fragments to even find the beginning of
      // the compressed frame.
      std::vector<std::size_t> frame_beginnings;
//      frame_beginnings.push_back(0);
//      std::size_t offset_from_last_fragment = 0;
//      for (std::size_t i = 0; i < data.fragment_count(); ++i) {
//         const auto& current_fragment = data.get_fragment(i);
//         for (std::size_t j=offset_from_last_fragment; j < current_fragment.size();) {
//            if (current_fragment[j] == 0xff && current_fragment[j+1] == 0xd9) {
//               frame_beginnings.push_back(i+1); // if i=1 < fragment_count
//               j += 2; // continue outermost loop
//               while (current_fragment[j] == 0xff) ++j;
//            } else if (current_fragment[j] == 0xff && marker_with_length(current_fragment[j+1])) {
//               auto size = read_marker_length(current_fragment[j+2], current_fragment[j+3]);
//               j += 4;
//               j += size - 2;
//               if (j >= current_fragment.size()) {
//                  offset_from_last_fragment = j - current_fragment.size();
//               }
//            } else {
//               ++j;
//            }
//         }
//      }

      frame_beginnings.push_back(0);
      for (std::size_t i = 0; i < data.fragment_count(); ++i) {
         const auto& current_fragment = data.get_fragment(i);
         for (std::size_t j = current_fragment.size()-1; j > 0; --j) {
            if (current_fragment[j] == 0xd9 && current_fragment[j-1] == 0xff) {
               frame_beginnings.push_back(i+1);
               break;
            }
         }
      }

      auto start_fragment = frame_beginnings[frame_index];
      auto end_fragment = frame_beginnings[frame_index+1];
      std::size_t size = 0;
      for (auto i=start_fragment; i<end_fragment; ++i) {
         size += data.get_fragment(i).size();
      }
      return size;
   }
}

std::vector<unsigned short> encapsulated_jpeg2000::operator[](std::size_t index) const
{
   type_of<VR::OB>::type ob_pixel_data;
   get_value_field<VR::OB>(set.at({0x7fe0, 0x0010}), ob_pixel_data);
   auto encapsulated_data = boost::get<encapsulated>(ob_pixel_data);

   auto compressed_pixel_data = encapsulated_data.get_fragment(index);


   opj_stream_t* stream = opj_stream_default_create(true);


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
   auto frame_length = determine_frame_length(encapsulated_data, index);
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
      double norm = (v - (511.0-(1024.0/2.0)))/1024.0;
      if (norm < 0.0) norm = 0.0;
      if (norm > 1.0) norm = 1.0;
      v = 65535.0*norm;
   }

   return data;
}
