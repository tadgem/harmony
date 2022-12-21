cmake_minimum_required(VERSION 3.0.0)
project(harmony-dojo VERSION 0.1.0)


add_executable(harmony-dojo main.cpp)

set_property(TARGET harmony-dojo PROPERTY CXX_STANDARD 17)

if (WIN32)
  # set stuff for windows
else()
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-error")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error")
endif()

get_filename_component(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

add_subdirectory(${ROOT_DIR}/harmony-editor-runtime ${CMAKE_CURRENT_BINARY_DIR}/harmony-editor-runtime)

target_include_directories(harmony-dojo PRIVATE ${HARMONY_EDITOR_INCLUDES})

target_link_libraries(harmony-dojo harmony-editor-runtime)