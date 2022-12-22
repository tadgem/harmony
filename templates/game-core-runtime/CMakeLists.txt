cmake_minimum_required(VERSION 3.0.0)
project(game-core-runtime VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.h)
file(GLOB_RECURSE HEADERPP_FILES include/*.hpp)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS /W2)
endif()

add_library(game-core-runtime STATIC ${HEADER_FILES} ${HEADERPP_FILES} ${SRC_FILES})
set_property(TARGET game-core-runtime PROPERTY CXX_STANDARD 17)

get_filename_component(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

add_subdirectory(${ROOT_DIR}/harmony-core-runtime ${CMAKE_CURRENT_BINARY_DIR}/harmony-core-runtime)

set(GAME_CORE_RUNTIME_INCLUDES 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${HARMONY_CORE_RUNTIME_INCLUDES} 
    CACHE INTERNAL "")

target_include_directories(game-core-runtime PUBLIC ${GAME_CORE_RUNTIME_INCLUDES})
target_link_libraries(game-core-runtime harmony-core-runtime)