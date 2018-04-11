#ifndef RGB_HPP
#define RGB_HPP

#include <type_traits>

template <typename T>
struct rgb
{
   public:
        using base_type = T;

        T r;
        T g;
        T b;

        //template <typename = typename std::enable_if<std::is_numeric<T>::value, void>::type>
        explicit rgb(T r = 0, T g = 0, T b = 0):
            r {r},
            g {g},
            b {b}
        {
        }
};

#endif // RGB_HPP
