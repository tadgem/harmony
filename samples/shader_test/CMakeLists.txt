cmake_minimum_required(VERSION 3.0.0)
project(shader_test VERSION 0.1.0)
add_executable(shader_test main.cpp)

set_property(TARGET shader_test PROPERTY CXX_STANDARD 17)

target_include_directories(shader_test PRIVATE ${HARMONY_CORE_INCLUDES} ${HARMONY_DAS_INCLUDES})
target_link_libraries(shader_test harmony-core)