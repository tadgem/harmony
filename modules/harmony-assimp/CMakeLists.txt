cmake_minimum_required(VERSION 3.0.0)
project(harmony-assimp VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.h)
file(GLOB_RECURSE HEADERPP_FILES include/*.hpp)

add_library(harmony-assimp ${HEADER_FILES} ${HEADERPP_FILES} ${SRC_FILES})

set(HARMONY_ASSIMP_INCLUDES 
${HARMONY_CORE_INCLUDES}
 CACHE INTERNAL "")

target_include_directories(harmony-assimp PRIVATE 
    ${HARMONY_ASSIMP_INCLUDES}
)


target_link_libraries(harmony-assimp harmony-core)