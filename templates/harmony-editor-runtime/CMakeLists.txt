cmake_minimum_required(VERSION 3.0.0)
project(harmony-editor-runtime VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.h)
file(GLOB_RECURSE HEADERPP_FILES include/*.hpp)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS /W2)
endif ()

add_library(harmony-editor-runtime STATIC ${HEADER_FILES} ${HEADERPP_FILES} ${SRC_FILES})
set_property(TARGET harmony-editor-runtime PROPERTY CXX_STANDARD 17)

get_filename_component(TEMP_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(ROOT_DIR ${TEMP_DIR} DIRECTORY)

add_subdirectory(${ROOT_DIR}/harmony-runtime ${CMAKE_CURRENT_BINARY_DIR}/harmony-runtime)
add_subdirectory(${ROOT_DIR}/submodules/efsw ${CMAKE_CURRENT_BINARY_DIR}/efsw)

set(HARMONY_EDITOR_INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${ROOT_DIR}/submodules/efsw/include
        ${HARMONY_CORE_RUNTIME_INCLUDES}
        ${HARMONY_ASSIMP_INCLUDES}
        CACHE INTERNAL "")

target_include_directories(harmony-editor-runtime PUBLIC ${HARMONY_EDITOR_INCLUDES})
target_link_libraries(harmony-editor-runtime harmony-runtime efsw)