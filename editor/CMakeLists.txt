cmake_minimum_required(VERSION 3.0.0)
project(editor VERSION 0.1.0)
add_executable(editor main.cpp)

set_property(TARGET editor PROPERTY CXX_STANDARD 17)

get_filename_component(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

add_subdirectory(${ROOT_DIR}/harmony ${CMAKE_CURRENT_BINARY_DIR}/harmony)
add_subdirectory(${ROOT_DIR}/modules/harmony-assimp ${CMAKE_CURRENT_BINARY_DIR}/harmony-assimp)

target_include_directories(editor PRIVATE ${HARMONY_CORE_INCLUDES}  ${HARMONY_ASSIMP_INCLUDES} ${ROOT_DIR}/submodules/assimp/include)
target_link_libraries(editor harmony-core harmony-assimp)