#ifndef ENDIAN_TYPE_BY_SIZE_HPP
#define ENDIAN_TYPE_BY_SIZE_HPP

template<std::size_t S>
struct type_by_size {
};

template<>
struct type_by_size<1> {
    typedef uint8_t type;
};

template<>
struct type_by_size<2> {
    typedef uint16_t type;
};

template<>
struct type_by_size<4> {
    typedef uint32_t type;
};

template<>
struct type_by_size<8> {
    typedef uint64_t type;
};

#endif