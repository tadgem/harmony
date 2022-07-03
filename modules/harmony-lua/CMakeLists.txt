cmake_minimum_required(VERSION 3.0.0)
project(harmony-assimp VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE C_SRC_FILES src/*.c)
file(GLOB_RECURSE HEADER_FILES include/*.h)
file(GLOB_RECURSE HEADERPP_FILES include/*.hpp)

add_library(harmony-lua STATIC ${HEADER_FILES} ${HEADERPP_FILES} ${SRC_FILES}  ${C_SRC_FILES})
set_property(TARGET harmony-lua PROPERTY CXX_STANDARD 17)

add_subdirectory(${ROOT_DIR}/submodules/lua-cmake ${CMAKE_CURRENT_BINARY_DIR}/lua)
add_subdirectory(${ROOT_DIR}/submodules/sol2 ${CMAKE_CURRENT_BINARY_DIR}/sol2)

set(HARMONY_LUA_INCLUDES 
${CMAKE_CURRENT_SOURCE_DIR}/include 
${HARMONY_CORE_INCLUDES}
${ROOT_DIR}/submodules/lua-cmake/upstream 
${ROOT_DIR}/submodules/sol2/include 
CACHE INTERNAL "")

target_include_directories(harmony-lua PUBLIC ${HARMONY_LUA_INCLUDES})
target_link_libraries(harmony-lua harmony-core lua sol2)
if (MSVC)
  target_compile_options(harmony-lua PRIVATE /bigobj)
endif()