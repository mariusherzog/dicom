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

// forward declaration
template <std::size_t BITS_ALLOC, std::size_t COMPS, bool SIGNED>
struct pixel_base_type;

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


template <std::size_t BITS_ALLOC, std::size_t COMPS, bool SIGNED, typename IS_SIGNED>
typename std::enable_if<std::is_same<IS_SIGNED, std::true_type>::value, pixel_base_type<BITS_ALLOC, COMPS, true>>::type
detect_signedness(pixel_base_type<BITS_ALLOC, COMPS, SIGNED>, IS_SIGNED)
{
   return pixel_base_type<BITS_ALLOC, COMPS, true> {};
}

template <std::size_t BITS_ALLOC, std::size_t COMPS, bool SIGNED, typename IS_SIGNED>
typename std::enable_if<std::is_same<IS_SIGNED, std::false_type>::value, pixel_base_type<BITS_ALLOC, COMPS, false>>::type
detect_signedness(pixel_base_type<BITS_ALLOC, COMPS, SIGNED>, IS_SIGNED)
{
   return pixel_base_type<BITS_ALLOC, COMPS, false> {};
}


template <std::size_t BITS_ALLOC, std::size_t COMPS, bool SIGNED, typename COMPONENTS>
typename std::enable_if<std::is_same<COMPONENTS, std::integral_constant<char, 1>>::value, pixel_base_type<BITS_ALLOC, 1, SIGNED>>::type
detect_components(pixel_base_type<BITS_ALLOC, COMPS, SIGNED>, COMPONENTS)
{
   return pixel_base_type<BITS_ALLOC, 1, SIGNED> {};
}

template <std::size_t BITS_ALLOC, std::size_t COMPS, bool SIGNED, typename COMPONENTS>
typename std::enable_if<std::is_same<COMPONENTS, std::integral_constant<char, 3>>::value, pixel_base_type<BITS_ALLOC, 3, SIGNED>>::type
detect_components(pixel_base_type<BITS_ALLOC, COMPS, SIGNED>, COMPONENTS)
{
   return pixel_base_type<BITS_ALLOC, 3, SIGNED> {};
}

template <std::size_t BITS_ALLOC, std::size_t COMPS, bool SIGNED, typename BITS_ALLOCATED>
typename std::enable_if<std::is_same<BITS_ALLOCATED, std::integral_constant<char, 8>>::value, pixel_base_type<8, COMPS, SIGNED>>::type
detect_bits(pixel_base_type<BITS_ALLOC, COMPS, SIGNED>, BITS_ALLOCATED)
{
   return pixel_base_type<8, COMPS, SIGNED> {};
}

template <std::size_t BITS_ALLOC, std::size_t COMPS, bool SIGNED, typename BITS_ALLOCATED>
typename std::enable_if<std::is_same<BITS_ALLOCATED, std::integral_constant<char, 16>>::value, pixel_base_type<16, COMPS, SIGNED>>::type
detect_bits(pixel_base_type<BITS_ALLOC, COMPS, SIGNED>, BITS_ALLOCATED)
{
   return pixel_base_type<16, COMPS, SIGNED> {};
}

template <std::size_t BITS_ALLOC, std::size_t COMPS, bool SIGNED, typename BITS_ALLOCATED>
typename std::enable_if<std::is_same<BITS_ALLOCATED, std::integral_constant<char, 32>>::value, pixel_base_type<32, COMPS, SIGNED>>::type
detect_bits(pixel_base_type<BITS_ALLOC, COMPS, SIGNED>, BITS_ALLOCATED)
{
   return pixel_base_type<32, COMPS, SIGNED> {};
}

template <std::size_t BITS_ALLOC, std::size_t COMPS, bool SIGNED, typename F>
pixeltype detect_bits_fun(pixel_base_type<BITS_ALLOC, COMPS, SIGNED> pixeltype,
                          std::size_t bits_allocated, std::size_t components, bool,
                          F&& extractor)
{
   if (bits_allocated <= 8) {
      auto t = detect_bits(pixeltype, std::integral_constant<char, 8>{});
      using tt = typename decltype(t)::type;
      return extractor(components, tt{});
   } else if (bits_allocated <= 16) {
      auto t = detect_bits(pixeltype, std::integral_constant<char, 16>{});
      using tt = typename decltype(t)::type;
      return extractor(components, tt{});
   } else {
      auto t = detect_bits(pixeltype, std::integral_constant<char, 32>{});
      using tt = typename decltype(t)::type;
      return extractor(components, tt{});
   }
}

template <std::size_t BITS_ALLOC, std::size_t COMPS, bool SIGNED, typename F>
pixeltype detect_components_fun(pixel_base_type<BITS_ALLOC, COMPS, SIGNED> pixeltype,
                                std::size_t bits_allocated, std::size_t components, bool is_signed,
                                F&& extractor)
{
   if (components == 3) {
      auto t = detect_components(pixeltype, std::integral_constant<char, 3>{});
      return detect_bits_fun(t, bits_allocated, components, is_signed, std::forward<F>(extractor));
   } else {
      auto t = detect_components(pixeltype, std::integral_constant<char, 1>{});
      return detect_bits_fun(t, bits_allocated, components, is_signed,std::forward<F>(extractor));
   }
}

template <std::size_t BITS_ALLOC, std::size_t COMPS, bool SIGNED, typename F>
pixeltype detect_signedness_fun(pixel_base_type<BITS_ALLOC, COMPS, SIGNED> pixeltype,
                                std::size_t bits_allocated, std::size_t components, bool is_signed,
                                F&& extractor)
{
   if (is_signed) {
      auto t = detect_signedness(pixeltype, std::true_type{});
      return detect_components_fun(t, bits_allocated, components, is_signed, std::forward<F>(extractor));
   } else {
      auto t = detect_signedness(pixeltype, std::false_type{});
      return detect_components_fun(t, bits_allocated, components, is_signed, std::forward<F>(extractor));
   }
}

template <std::size_t BITS_ALLOC, std::size_t COMPS, bool SIGNED, typename F>
pixeltype detect(pixel_base_type<BITS_ALLOC, COMPS, SIGNED> pixeltype,
                 std::size_t bits_allocated, std::size_t components, bool is_signed,
                 F&& extractor)
{
   return detect_signedness_fun(pixeltype, bits_allocated, components, is_signed, std::forward<F>(extractor));
}

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
   return impl::detect(pixel_base_type<8, 1, false>{}, bits_allocated, components, is_signed, extractor);
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
