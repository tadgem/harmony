cmake_minimum_required(VERSION 3.20.0)
project(harmony-mono VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" src/*.cpp)
file(GLOB_RECURSE C_SRC_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" src/*.c)
file(GLOB_RECURSE HEADER_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" include/*.h)
file(GLOB_RECURSE HEADERPP_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" include/*.hpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake-etc)

add_library(harmony-mono STATIC ${HEADER_FILES} ${HEADERPP_FILES} ${SRC_FILES}  ${C_SRC_FILES}
        include/MonoAPI.h
        src/MonoAPI.cpp
        include/MonoSystem.h
        src/MonoSystem.cpp)
set_property(TARGET harmony-mono PROPERTY CXX_STANDARD 17)


# VS Filters
foreach(header IN LISTS HEADER_FILES)
    get_filename_component(source_path "${header}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${header}")
endforeach()

foreach(header IN LISTS HEADERPP_FILES)
    get_filename_component(source_path "${header}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${header}")
endforeach()

foreach(source IN LISTS SRC_FILES)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()

foreach(source IN LISTS C_SRC_FILES)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()

# Stop Cmake complaining about MONO_ROOT env variable
cmake_policy(SET CMP0074 NEW)
set(MONO_ROOT $ENV{MONO_PATH} CACHE INTERNAL "")
find_package(mono REQUIRED)

set(HARMONY_MONO_INCLUDES 
${CMAKE_CURRENT_SOURCE_DIR}/include 
${HARMONY_CORE_INCLUDES}
${MONO_INCLUDE_DIRS}
CACHE INTERNAL "")

target_include_directories(harmony-mono PUBLIC ${HARMONY_MONO_INCLUDES})
target_link_directories(harmony-mono PUBLIC ${MONO_LIBRARY_DIRS})
target_link_libraries(harmony-mono PUBLIC ${MONO_LIBRARIES} harmony-core)

if(MSVC)
    target_compile_options(harmony-mono PRIVATE "/MP" "/Zi")
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<$<CONFIG:Debug,Release>:ProgramDatabase>")
endif()