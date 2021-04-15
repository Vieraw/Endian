#ifndef ENDIAN_STORE_HPP
#define ENDIAN_STORE_HPP

#include <cstring>
#include "order.hpp"
#include "type_by_size.hpp"

namespace endian {
    namespace details {
        template<typename T, order O1, order O2>
        struct endian_store_imp {
            void operator()(unsigned char *p, T const &value) const {
                for (std::size_t i = 0; i < sizeof(T); i++) {
                    p[sizeof(T) - 1 - i] = static_cast<unsigned char>(value >> (i << 3));
                }
            }
        };

        template<typename T, order O>
        struct endian_store_imp<T, O, O> {
            void operator()(unsigned char *p, T const &value) const {
                for (std::size_t i = 0; i < sizeof(T); i++) {
                    p[i] = static_cast<unsigned char>(value >> (i << 3));
                }
            }

        };

        template<typename T, order O>
        void endian_store(unsigned char *p, T const &value) {
            static_assert(sizeof(T) == 1 || sizeof(T) == 2 || sizeof(T) == 4 || sizeof(T) == 8, "");

            typedef typename type_by_size<sizeof(T)>::type value_t;
            value_t val;
            std::memcpy(&val, &value, sizeof(T));
            endian_store_imp<value_t, order::native, O>()(p, val);
        }
    }
}
#endif