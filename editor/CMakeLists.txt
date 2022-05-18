cmake_minimum_required(VERSION 3.0.0)
project(harmony-editor VERSION 0.1.0)
add_executable(harmony-editor main.cpp)

set_property(TARGET harmony-editor PROPERTY CXX_STANDARD 17)

target_include_directories(harmony-editor PRIVATE ${HARMONY_CORE_INCLUDES} ${HARMONY_DAS_INCLUDES})
target_link_libraries(harmony-editor harmony-core)