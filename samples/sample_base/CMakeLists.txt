cmake_minimum_required(VERSION 3.0.0)
project(harmony-sample-base VERSION 0.1.0)
add_executable(harmony-sample-base main.cpp)

set_property(TARGET harmony-sample-base PROPERTY CXX_STANDARD 17)

get_filename_component(TEMP_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(ROOT_DIR ${TEMP_DIR} DIRECTORY)

add_subdirectory(${ROOT_DIR}/harmony ${CMAKE_CURRENT_BINARY_DIR}/harmony)

target_include_directories(harmony-sample-base PRIVATE ${HARMONY_CORE_INCLUDES})
target_link_libraries(harmony-sample-base harmony-core)