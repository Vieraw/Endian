# Endian

**Endian** - The Endian library provides facilities for dealing
with [endianness](https://en.wikipedia.org/wiki/Endianness).

## Dependencies & Requirements

- C++11 compiler
- CMake 3.1+

## Build

Clone repository to subfolder and link endian to your project:

```cmake
add_subdirectory(path/to/endian)
target_link_libraries(your-project-name endian)
```

## Examples

```cpp
#include <iostream>
#include <endian/types.hpp>

int main(int argc, char *argv[]) {
    endian::little_int64_t one = -2;
    endian::big_int64_t two = one;

    std::cout << one << " " << two << " " << std::endl;

    return 0;
}

```

## License

See accompanying [LICENSE](LICENSE) file.