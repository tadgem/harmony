cmake_minimum_required(VERSION 3.0.0)
project(sandbox VERSION 0.1.0)
add_executable(sandbox main.cpp)

set_property(TARGET sandbox PROPERTY CXX_STANDARD 17)

get_filename_component(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
add_subdirectory(${ROOT_DIR}/harmony ${CMAKE_CURRENT_BINARY_DIR}/harmony)
add_subdirectory(${ROOT_DIR}/modules/harmony-das ${CMAKE_CURRENT_BINARY_DIR}/harmony-das)

target_include_directories(sandbox PRIVATE ${HARMONY_CORE_INCLUDES} ${HARMONY_DAS_INCLUDES})
target_link_libraries(sandbox harmony-core harmony-das)