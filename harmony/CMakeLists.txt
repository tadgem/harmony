cmake_minimum_required(VERSION 3.0.0)
project(harmony-core VERSION 0.1.0)

option(HARMONY_DEBUG "Build harmony with debug functionality enabled." ON)

file(GLOB_RECURSE CORE_SRC_FILES src/*.cpp)
file(GLOB_RECURSE CORE_HEADER_FILES include/*.h)
file(GLOB_RECURSE CORE_HEADERPP_FILES include/*.hpp)
get_filename_component(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

add_subdirectory(${ROOT_DIR}/submodules/glm ${CMAKE_CURRENT_BINARY_DIR}/glm)
add_subdirectory(${ROOT_DIR}/submodules/bgfx ${CMAKE_CURRENT_BINARY_DIR}/bgfx)
add_subdirectory(${ROOT_DIR}/submodules/sdl ${CMAKE_CURRENT_BINARY_DIR}/sdl)
add_subdirectory(${ROOT_DIR}/submodules/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
set(HARMONY_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE INTERNAL "")

add_library(harmony-core STATIC ${CORE_HEADER_FILES} ${CORE_HEADERPP_FILES} ${CORE_SRC_FILES})
set_property(TARGET harmony-core PROPERTY CXX_STANDARD 17)

set(HARMONY_CORE_INCLUDES 
${CMAKE_CURRENT_SOURCE_DIR}/include 
${ROOT_DIR}/submodules/sdl/include
${ROOT_DIR}/submodules/spdlog/include
${ROOT_DIR}/submodules/bgfx/bgfx/include
${ROOT_DIR}/submodules/bgfx/bx/include
${ROOT_DIR}/submodules/bgfx/bimg/include
${ROOT_DIR}/submodules/glm/glm
CACHE INTERNAL "")

target_include_directories(harmony-core PRIVATE 
    ${HARMONY_CORE_INCLUDES}
)

if(HARMONY_DEBUG)
    target_compile_definitions(harmony-core PUBLIC SDL_SENSOR_DUMMY HARMONY_DEBUG)
endif()

target_link_libraries(harmony-core SDL2-static spdlog::spdlog bx bimg bgfx glm)