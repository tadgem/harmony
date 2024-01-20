cmake_minimum_required(VERSION 3.0.0)
project(harmony-runtime VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" src/*.cpp)
file(GLOB_RECURSE HEADER_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" include/*.h)
file(GLOB_RECURSE HEADERPP_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" include/*.hpp)

IF(MSVC)
    ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS -D_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING /W2)
ENDIF()

add_library(harmony-runtime STATIC ${HEADER_FILES} ${HEADERPP_FILES} ${SRC_FILES})
set_property(TARGET harmony-runtime PROPERTY CXX_STANDARD 17)

# VS Filters
foreach(header IN LISTS HEADER_FILES)
    get_filename_component(source_path "${header}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${header}")
endforeach()

foreach(header IN LISTS HEADERPP_FILES)
    get_filename_component(source_path "${header}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${header}")
endforeach()

foreach(source IN LISTS SRC_FILES)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()

get_filename_component(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

add_subdirectory(${ROOT_DIR}/harmony-core ${CMAKE_CURRENT_BINARY_DIR}/harmony)
add_subdirectory(${ROOT_DIR}/harmony-modules/harmony-assimp ${CMAKE_CURRENT_BINARY_DIR}/harmony-assimp)
add_subdirectory(${ROOT_DIR}/harmony-modules/harmony-jolt ${CMAKE_CURRENT_BINARY_DIR}/harmony-jolt)
add_subdirectory(${ROOT_DIR}/harmony-modules/harmony-mono ${CMAKE_CURRENT_BINARY_DIR}/harmony-mono)

set(HARMONY_CORE_RUNTIME_INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${ROOT_DIR}/submodules/assimp/include
        ${HARMONY_CORE_INCLUDES}
        ${HARMONY_JOLT_INCLUDES}
        ${HARMONY_MONO_INCLUDES}
        CACHE INTERNAL "")

target_include_directories(harmony-runtime PUBLIC ${HARMONY_CORE_RUNTIME_INCLUDES})
target_link_libraries(harmony-runtime harmony-core harmony-assimp harmony-jolt harmony-mono)