cmake_minimum_required(VERSION 3.0.0)
project(harmony-editor VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.h)
file(GLOB_RECURSE HEADERPP_FILES include/*.hpp)
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS /W2)
endif()

add_library(harmony-editor STATIC ${HEADER_FILES} ${HEADERPP_FILES} ${SRC_FILES})
set_property(TARGET harmony-editor PROPERTY CXX_STANDARD 17)

set(HARMONY_EDITOR_INCLUDES 
${CMAKE_CURRENT_SOURCE_DIR}/include 
${HARMONY_INCLUDES} CACHE INTERNAL "")

target_include_directories(harmony-editor PUBLIC ${HARMONY_EDITOR_INCLUDES})
target_link_libraries(harmony-editor harmony-core)