cmake_minimum_required(VERSION 3.0.0)
project(harmony-core-runtime VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.h)
file(GLOB_RECURSE HEADERPP_FILES include/*.hpp)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS /W2)
endif()

add_library(harmony-core-runtime STATIC ${HEADER_FILES} ${HEADERPP_FILES} ${SRC_FILES})
set_property(TARGET harmony-core-runtime PROPERTY CXX_STANDARD 17)


get_filename_component(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

add_subdirectory(${ROOT_DIR}/harmony-core ${CMAKE_CURRENT_BINARY_DIR}/harmony)
add_subdirectory(${ROOT_DIR}/modules/harmony-assimp ${CMAKE_CURRENT_BINARY_DIR}/harmony-assimp)

set(HARMONY_CORE_RUNTIME_INCLUDES 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${ROOT_DIR}/submodules/assimp/include  
    ${HARMONY_CORE_INCLUDES} 
    CACHE INTERNAL "")

target_include_directories(harmony-core-runtime PUBLIC ${HARMONY_CORE_RUNTIME_INCLUDES})
target_link_libraries(harmony-core-runtime harmony-core harmony-assimp)