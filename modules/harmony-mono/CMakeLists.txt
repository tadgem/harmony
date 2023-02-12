cmake_minimum_required(VERSION 3.0.0)
project(harmony-mono VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE C_SRC_FILES src/*.c)
file(GLOB_RECURSE HEADER_FILES include/*.h)
file(GLOB_RECURSE HEADERPP_FILES include/*.hpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake-etc)

add_library(harmony-mono STATIC ${HEADER_FILES} ${HEADERPP_FILES} ${SRC_FILES}  ${C_SRC_FILES})
set_property(TARGET harmony-mono PROPERTY CXX_STANDARD 17)

set(MONO_ROOT $ENV{MONO_PATH})
find_package(mono)

set(HARMONY_MONO_INCLUDES 
${CMAKE_CURRENT_SOURCE_DIR}/include 
${HARMONY_CORE_INCLUDES}
${MONO_INCLUDE_DIRS}
CACHE INTERNAL "")

target_include_directories(harmony-mono PUBLIC ${HARMONY_MONO_INCLUDES})
target_link_directories(harmony-mono PUBLIC ${MONO_LIBRARY_DIRS})
target_link_libraries(harmony-mono ${MONO_LIBRARIES})