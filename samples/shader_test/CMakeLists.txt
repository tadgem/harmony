cmake_minimum_required(VERSION 3.0.0)
project(shader_test VERSION 0.1.0)
add_executable(shader_test main.cpp)

set_property(TARGET shader_test PROPERTY CXX_STANDARD 17)

get_filename_component(TEMP_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(ROOT_DIR ${TEMP_DIR} DIRECTORY)

add_subdirectory(${ROOT_DIR}/harmony ${CMAKE_CURRENT_BINARY_DIR}/harmony)
add_subdirectory(${ROOT_DIR}/modules/harmony-assimp ${CMAKE_CURRENT_BINARY_DIR}/harmony-assimp)

target_include_directories(shader_test PRIVATE ${HARMONY_CORE_INCLUDES} ${HARMONY_ASSIMP_INCLUDES})
target_link_libraries(shader_test harmony-core)