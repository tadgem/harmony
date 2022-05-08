cmake_minimum_required(VERSION 3.0.0)
project(harmony-core VERSION 0.1.0)

file(GLOB_RECURSE CORE_SRC_FILES src/*.cpp)
file(GLOB_RECURSE CORE_HEADER_FILES include/*.h)
file(GLOB_RECURSE CORE_HEADERPP_FILES include/*.hpp)

get_filename_component(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

set(HARMONY_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE INTERNAL "")

add_library(harmony-core ${CORE_HEADER_FILES} ${CORE_HEADERPP_FILES} ${CORE_SRC_FILES})

set_property(TARGET harmony-core PROPERTY CXX_STANDARD 17)

set(HARMONY_CORE_INCLUDES 
${CMAKE_CURRENT_SOURCE_DIR}/include 
${ROOT_DIR}/submodules/sdl/include
${ROOT_DIR}/submodules/spdlog/include 
CACHE INTERNAL "")

target_include_directories(harmony-core PRIVATE 
    ${HARMONY_CORE_INCLUDES}
)

target_compile_definitions(harmony-core PUBLIC SDL_SENSOR_DUMMY)
target_link_libraries(harmony-core SDL2-static spdlog::spdlog bx bimg bgfx)