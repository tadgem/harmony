cmake_minimum_required(VERSION 3.0.0)
project(harmony-jolt VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE C_SRC_FILES src/*.c)
file(GLOB_RECURSE HEADER_FILES include/*.h)
file(GLOB_RECURSE HEADERPP_FILES include/*.hpp)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS /W2)
endif()

add_library(harmony-jolt STATIC ${HEADER_FILES} ${HEADERPP_FILES} ${SRC_FILES}  ${C_SRC_FILES})
set_property(TARGET harmony-jolt PROPERTY CXX_STANDARD 17)

add_subdirectory(${ROOT_DIR}/submodules/jolt/Build ${CMAKE_CURRENT_BINARY_DIR}/jolt)

set(HARMONY_JOLT_INCLUDES 
${CMAKE_CURRENT_SOURCE_DIR}/include 
${HARMONY_CORE_INCLUDES}
${ROOT_DIR}/submodules/jolt 
CACHE INTERNAL "")

target_include_directories(harmony-jolt PUBLIC ${HARMONY_JOLT_INCLUDES})
target_link_libraries(harmony-jolt Jolt harmony-core)