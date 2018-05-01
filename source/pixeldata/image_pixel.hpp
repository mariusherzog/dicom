#ifndef IMAGE_PIXEL_HPP
#define IMAGE_PIXEL_HPP

#include <type_traits>

//#include "libdicompp/dicomdata.hpp"
#include "pixeltype.hpp"


namespace dicom
{

namespace pixeldata
{

namespace frames
{


namespace impl
{

template <std::size_t S, typename = void>
struct pixel_base_impl_bits_alloc
{
      using type = void;
};
template <std::size_t S>
struct pixel_base_impl_bits_alloc<S, typename std::enable_if<(S <= 8)>::type>
{
      using type = char;
};
template <std::size_t S>
struct pixel_base_impl_bits_alloc<S, typename std::enable_if<(S > 8 && S <= 16)>::type>
{
      using type = short;
};
template <std::size_t S>
struct pixel_base_impl_bits_alloc<S, typename std::enable_if<(S > 16)>::type>
{
      using type = int;
};

template <bool G, typename T, typename = void>
struct pixel_base_impl_signed
{
      using type = void;
};
template <bool G, typename T>
struct pixel_base_impl_signed<G, T, typename std::enable_if<G>::type>
{
      using type = typename std::make_signed<T>::type;
};
template <bool G, typename T>
struct pixel_base_impl_signed<G, T, typename std::enable_if<!G>::type>
{
      using type = typename std::make_unsigned<T>::type;
};

template <std::size_t C, typename T, typename = void>
struct pixel_base_impl_components
{
      using type = void;
};
template <std::size_t C, typename T>
struct pixel_base_impl_components<C, T, typename std::enable_if<(C == 3)>::type>
{
      using type = rgb<T>;
};
template <std::size_t C, typename T>
struct pixel_base_impl_components<C, T, typename std::enable_if<(C == 1)>::type>
{
      using type = T;
};

}

/**
 * @brief The pixel_base_type struct provides a type which fits best for the
 *        underlying pixel data, depending on size, signedness and number of
 *        components
 */
template <std::size_t BITS_ALLOC, std::size_t COMPS, bool SIGNED>
struct pixel_base_type
{
      using type = typename impl::pixel_base_impl_components<COMPS,
         typename impl::pixel_base_impl_signed<SIGNED,
            typename impl::pixel_base_impl_bits_alloc<BITS_ALLOC
            >::type
         >::type
      >::type;
};


/**
 * @brief extract_image returns a vector of strongly typed image data
 *        (=pixeltype variant) using a callback function to retrieve the
 *        actual pixel data.
 * @param extractor frame_extractor specific function to retrieve the actual
 *        image data.
 * @param bits_allocated
 * @param components
 * @param is_signed
 * @return strongly typed vector of the image data
 */
template <typename F>
pixeltype extract_image(F extractor, std::size_t bits_allocated, std::size_t components, bool is_signed)
{
   if (bits_allocated <= 8) {
      if (components == 1) {
         if (is_signed) {
            using type = typename pixel_base_type<8, 1, true>::type;
            return extractor(components, type{});
         } else {
            using type = typename pixel_base_type<8, 1, false>::type;
            return extractor(components, type{});
         }
      } else {
         using type = typename pixel_base_type<8, 3, false>::type;
         return extractor(components, type{});
      }
   } else if (bits_allocated <= 16) {
      if (components == 1) {
         if (is_signed) {
            using type = typename pixel_base_type<16, 1, true>::type;
            return extractor(components, type{});
         } else {
            using type = typename pixel_base_type<16, 1, false>::type;
            return extractor(components, type{});
         }
      } else {
         using type = typename pixel_base_type<16, 3, false>::type;
         return extractor(components, type{});
      }
   } else {
      if (components == 1) {
         if (is_signed) {
            using type = typename pixel_base_type<32, 1, true>::type;
            return extractor(components, type{});
         } else {
            using type = typename pixel_base_type<32, 1, false>::type;
            return extractor(components, type{});
         }
      } else {
         using type = typename pixel_base_type<32, 3, false>::type;
         return extractor(components, type{});
      }
   }
}


/**
 * @brief The image_pixel class encapsulates functionality related to the
 *        dicom image pixel module
 */
class image_pixel
{
   public:
      image_pixel();
};


}

}

}

#endif // IMAGE_PIXEL_HPP
