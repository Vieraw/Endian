#ifndef ENDIAN_ORDER_HPP
#define ENDIAN_ORDER_HPP

namespace endian {
    namespace details {
        enum class order {
            little = 0x01000000,
            big = 0x00000001,
            native = static_cast<uint8_t>(little) == 0 ? little : big
        };
    }
}

#endif