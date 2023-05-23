cmake_minimum_required(VERSION 3.0.0)
project(harmony-app VERSION 0.1.0)

add_executable(harmony-app main.cpp)

set_property(TARGET harmony-app PROPERTY CXX_STANDARD 17)

if (WIN32)
    # set stuff for windows
else ()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-error")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error")
endif ()

get_filename_component(TEMP_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(ROOT_DIR ${TEMP_DIR} DIRECTORY)

add_subdirectory(${ROOT_DIR}/harmony-runtime ${CMAKE_CURRENT_BINARY_DIR}/harmony-runtime)

target_include_directories(harmony-app PRIVATE ${HARMONY_CORE_RUNTIME_INCLUDES})

target_link_libraries(harmony-app harmony-runtime)