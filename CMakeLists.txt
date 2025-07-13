cmake_minimum_required(VERSION 3.12)

project(harmony-engine)

# configure project
set(CMAKE_CXX_STANDARD 20)
# SDL config
set(SDL_SHARED OFF CACHE INTERNAL "")
set(SDL_STATIC ON  CACHE INTERNAL "")
set(SDL_TEST_LIBRARY OFF CACHE INTERNAL "")

# add submodule libs
add_subdirectory(submodules/SDL)

set(HARMONY_INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}/third-party
        ${CMAKE_CURRENT_SOURCE_DIR}/harmony/include
)

file(GLOB_RECURSE HARMONY_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/harmony/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/harmony/src/*.c
)

add_library(harmony ${HARMONY_SOURCES})
target_link_libraries(harmony PUBLIC SDL3-static)
target_include_directories(harmony PUBLIC ${HARMONY_INCLUDES})

add_executable(harmony-entry entry.cpp)
target_link_libraries(harmony-entry harmony)
target_include_directories(harmony PRIVATE ${HARMONY_INCLUDES})