cmake_minimum_required(VERSION 3.0.0)
project(mono-editor-test VERSION 0.1.0)


add_executable(mono-editor-test main.cpp)

set_property(TARGET mono-editor-test PROPERTY CXX_STANDARD 17)

if (WIN32)
  # set stuff for windows
else()
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-error")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error")
endif()

get_filename_component(TEMP_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(ROOT_DIR ${TEMP_DIR} DIRECTORY)

add_subdirectory(${ROOT_DIR}/templates/harmony-editor-runtime ${CMAKE_CURRENT_BINARY_DIR}/harmony-editor-runtime)
add_subdirectory(${ROOT_DIR}/modules/harmony-mono ${CMAKE_CURRENT_BINARY_DIR}/harmony-mono)

target_include_directories(mono-editor-test PRIVATE ${HARMONY_EDITOR_INCLUDES} ${HARMONY_MONO_INCLUDES})

target_link_libraries(mono-editor-test harmony-editor-runtime harmony-mono)