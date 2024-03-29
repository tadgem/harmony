cmake_minimum_required(VERSION 3.20.0)
project(harmony-dojo VERSION 0.1.0)


add_executable(harmony-dojo main.cpp)

set_property(TARGET harmony-dojo PROPERTY CXX_STANDARD 17)

if (WIN32)
    add_definitions(-D_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING)    
else ()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-error")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error")
endif ()

get_filename_component(TEMP_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(ROOT_DIR ${TEMP_DIR} DIRECTORY)

target_include_directories(harmony-dojo PRIVATE ${HARMONY_EDITOR_INCLUDES})

target_link_libraries(harmony-dojo harmony-editor-runtime)

if(MSVC)
    target_compile_options(harmony-dojo PRIVATE "/MP" "/Zi")
    target_link_options(harmony-dojo PRIVATE "/DEBUG" "/INCREMENTAL:NO")
endif()