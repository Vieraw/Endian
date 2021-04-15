#ifndef ENDIAN_TYPES_HPP
#define ENDIAN_TYPES_HPP

#include "number.hpp"

namespace endian {
    typedef number<int8_t, details::order::big> big_int8_t;
    typedef number<int16_t, details::order::big> big_int16_t;
    typedef number<int32_t, details::order::big> big_int32_t;
    typedef number<int64_t, details::order::big> big_int64_t;

    typedef number<int8_t, details::order::little> little_int8_t;
    typedef number<int16_t, details::order::little> little_int16_t;
    typedef number<int32_t, details::order::little> little_int32_t;
    typedef number<int64_t, details::order::little> little_int64_t;

    typedef number<uint8_t, details::order::big> big_uint8_t;
    typedef number<uint16_t, details::order::big> big_uint16_t;
    typedef number<uint32_t, details::order::big> big_uint32_t;
    typedef number<uint64_t, details::order::big> big_uint64_t;

    typedef number<uint8_t, details::order::little> little_uint8_t;
    typedef number<uint16_t, details::order::little> little_uint16_t;
    typedef number<uint32_t, details::order::little> little_uint32_t;
    typedef number<uint64_t, details::order::little> little_uint64_t;

    typedef number<float, details::order::big> big_float_t;
    typedef number<double, details::order::big> big_double_t;

    typedef number<float, details::order::little> little_float_t;
    typedef number<double, details::order::little> little_double_t;
}

#endif