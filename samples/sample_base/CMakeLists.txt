cmake_minimum_required(VERSION 3.0.0)
project(harmony-sample-base VERSION 0.1.0)
add_executable(harmony-sample-base main.cpp)

set_property(TARGET harmony-sample-base PROPERTY CXX_STANDARD 17)

target_include_directories(harmony-sample-base PRIVATE ${HARMONY_CORE_INCLUDES} ${HARMONY_DAS_INCLUDES})
target_link_libraries(harmony-sample-base harmony-core)