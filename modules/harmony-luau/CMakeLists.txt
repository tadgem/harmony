cmake_minimum_required(VERSION 3.0.0)
project(harmony-luau VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE C_SRC_FILES src/*.c)
file(GLOB_RECURSE HEADER_FILES include/*.h)
file(GLOB_RECURSE HEADERPP_FILES include/*.hpp)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS /W2)
endif()

add_library(harmony-luau STATIC ${HEADER_FILES} ${HEADERPP_FILES} ${SRC_FILES}  ${C_SRC_FILES})
set_property(TARGET harmony-luau PROPERTY CXX_STANDARD 17)

get_filename_component(TEMP_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(ROOT_DIR ${TEMP_DIR} DIRECTORY)


add_subdirectory(${ROOT_DIR}/submodules/luau ${CMAKE_CURRENT_BINARY_DIR}/luau)

set(HARMONY_LUAU_INCLUDES 
${CMAKE_CURRENT_SOURCE_DIR}/include 
${HARMONY_CORE_INCLUDES}
${ROOT_DIR}/submodules/luau/Compiler/include
${ROOT_DIR}/submodules/luau/VM/include 
CACHE INTERNAL "")

target_include_directories(harmony-luau PUBLIC ${HARMONY_LUAU_INCLUDES})
target_link_libraries(harmony-luau harmony-core Luau.Compiler Luau.VM)
if (MSVC)
  target_compile_options(harmony-luau PRIVATE /bigobj)
endif()