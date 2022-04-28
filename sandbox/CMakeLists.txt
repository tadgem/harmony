cmake_minimum_required(VERSION 3.0.0)
project(sandbox VERSION 0.1.0)
add_executable(sandbox main.cpp)

target_include_directories(sandbox PRIVATE ${HARMONY_INCLUDE_DIR})
target_link_libraries(sandbox harmony)