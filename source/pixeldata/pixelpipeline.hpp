#ifndef PIXELPIPELINE_HPP
#define PIXELPIPELINE_HPP

#include <type_traits>

#include <boost/variant.hpp>
#include "pixeltype.hpp"



template <typename P, typename... Ps>
struct resolve_return_type
{
        using return_type = typename resolve_return_type<Ps...>::return_type;
};

template <typename P>
struct resolve_return_type<P>
{
        using return_type = typename std::remove_reference<P>::type::result_type;
};



template <typename... Ps>
struct pipeline_impl;

template <typename P>
struct pipeline_impl<P>
{
      static typename resolve_return_type<P>::return_type
      invoke(pixeltype data, P visitor)
      {
         return boost::apply_visitor(visitor, data);
      }
};

template <typename P, typename... Ps>
struct pipeline_impl<P, Ps...>
{
      static typename resolve_return_type<Ps...>::return_type
      invoke(pixeltype data, P visitor, Ps &&... visitors)
      {
         return pipeline_impl<Ps...>::invoke(boost::apply_visitor(visitor, data), std::forward<Ps>(visitors)... );
      }
};

template <typename... Ps>
typename resolve_return_type<Ps...>::return_type
pipeline(pixeltype data, Ps &&... visitors)
{
   return pipeline_impl<Ps...>::invoke(data, std::forward<Ps>(visitors)...);
}


#endif // PIXELPIPELINE_HPP
