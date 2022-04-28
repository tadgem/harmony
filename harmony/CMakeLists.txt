cmake_minimum_required(VERSION 3.0.0)
project(harmony VERSION 0.1.0)

file(GLOB_RECURSE CORE_SRC_FILES src/*.cpp)
file(GLOB_RECURSE CORE_HEADER_FILES include/*.h)

set(HARMONY_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE INTERNAL "")

add_library(harmony ${CORE_HEADER_FILES} ${CORE_SRC_FILES})

target_include_directories(harmony PRIVATE include)