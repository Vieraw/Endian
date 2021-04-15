cmake_minimum_required(VERSION 3.1)
project(endian CXX)

set(CMAKE_CXX_STANDARD 11)

add_library(endian INTERFACE)
target_include_directories(endian INTERFACE include)

target_compile_options(${PROJECT_NAME} INTERFACE $<IF:$<CXX_COMPILER_ID:MSVC>,/W4 /WX,-Wall -Wextra -pedantic -Werror>)