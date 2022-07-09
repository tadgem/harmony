cmake_minimum_required(VERSION 3.0.0)
project(harmony-assimp VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.h)
file(GLOB_RECURSE HEADERPP_FILES include/*.hpp)
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS /W2)
endif()

add_library(harmony-assimp STATIC ${HEADER_FILES} ${HEADERPP_FILES} ${SRC_FILES})
set_property(TARGET harmony-assimp PROPERTY CXX_STANDARD 17)

add_subdirectory(${ROOT_DIR}/submodules/assimp ${CMAKE_CURRENT_BINARY_DIR}/assimp)

set(HARMONY_ASSIMP_INCLUDES 
${CMAKE_CURRENT_SOURCE_DIR}/include 
${HARMONY_CORE_INCLUDES}
${ROOT_DIR}/submodules/assimp/include CACHE INTERNAL "")

target_include_directories(harmony-assimp PUBLIC ${HARMONY_ASSIMP_INCLUDES})
target_link_libraries(harmony-assimp harmony-core assimp)