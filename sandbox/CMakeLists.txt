cmake_minimum_required(VERSION 3.0.0)
project(sandbox VERSION 0.1.0)
add_executable(sandbox main.cpp)

set_property(TARGET sandbox PROPERTY CXX_STANDARD 17)

target_include_directories(sandbox PRIVATE ${HARMONY_CORE_INCLUDES} ${HARMONY_DAS_INCLUDES})
target_link_libraries(sandbox harmony-core harmony-das)