#ifndef ENDIAN_LOAD_HPP
#define ENDIAN_LOAD_HPP

#include <cstring>
#include "type_by_size.hpp"
#include "order.hpp"

namespace endian {
    namespace details {
        template<typename T, order O1, order O2>
        struct endian_load_imp {
            T operator()(unsigned char const *p) const {
                T res{};
                for (std::size_t i = 0; i < sizeof(T); i++) {
                    res |= T(p[sizeof(T) - 1 - i]) << (i << 3);
                }
                return res;
            }
        };

        template<typename T, order O>
        struct endian_load_imp<T, O, O> {
            T operator()(unsigned char const *p) const {
                T res{};
                for (std::size_t i = 0; i < sizeof(T); i++) {
                    res |= T(p[i]) << (i << 3);
                }
                return res;
            }
        };

        template<typename T, order O>
        T endian_load(unsigned char const *p) {
            static_assert(sizeof(T) == 1 || sizeof(T) == 2 || sizeof(T) == 4 || sizeof(T) == 8, "");

            typedef typename type_by_size<sizeof(T)>::type value_t;
            value_t value = endian_load_imp<value_t, order::native, O>()(p);
            T res{};
            std::memcpy(&res, &value, sizeof(T));
            return res;
        }
    }
}
#endif