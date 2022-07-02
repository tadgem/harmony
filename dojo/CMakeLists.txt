cmake_minimum_required(VERSION 3.0.0)
project(Dojo VERSION 0.1.0)

file(GLOB_RECURSE CORE_SRC_FILES src/*.cpp)
file(GLOB_RECURSE CORE_HEADER_FILES include/*.h)
file(GLOB_RECURSE CORE_HEADERPP_FILES include/*.hpp)

add_executable(Dojo main.cpp ${CORE_SRC_FILES} ${CORE_HEADER_FILES} ${CORE_HEADERPP_FILES})

set_property(TARGET Dojo PROPERTY CXX_STANDARD 17)

get_filename_component(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

add_subdirectory(${ROOT_DIR}/harmony ${CMAKE_CURRENT_BINARY_DIR}/harmony)
add_subdirectory(${ROOT_DIR}/modules/harmony-assimp ${CMAKE_CURRENT_BINARY_DIR}/harmony-assimp)
add_subdirectory(${ROOT_DIR}/modules/harmony-lua ${CMAKE_CURRENT_BINARY_DIR}/harmony-lua)

target_include_directories(Dojo PRIVATE ${HARMONY_CORE_INCLUDES} ${CMAKE_CURRENT_SOURCE_DIR}/include ${HARMONY_ASSIMP_INCLUDES} ${ROOT_DIR}/submodules/assimp/include ${HARMONY_LUA_INCLUDES})
target_link_libraries(Dojo harmony-core harmony-assimp harmony-lua)