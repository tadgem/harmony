cmake_minimum_required(VERSION 3.20.0)
project(harmony-jolt VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" src/*.cpp)
file(GLOB_RECURSE C_SRC_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" src/*.c)
file(GLOB_RECURSE HEADER_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" include/*.h)
file(GLOB_RECURSE HEADERPP_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" include/*.hpp)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS /W2)
endif ()

add_library(harmony-jolt STATIC ${HEADER_FILES} ${HEADERPP_FILES} ${SRC_FILES} ${C_SRC_FILES})
set_property(TARGET harmony-jolt PROPERTY CXX_STANDARD 17)

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

set(HARMONY_JOLT_INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${HARMONY_CORE_INCLUDES}
        ${ROOT_DIR}/submodules/jolt
        CACHE INTERNAL "")

target_include_directories(harmony-jolt PUBLIC ${HARMONY_JOLT_INCLUDES})
target_link_libraries(harmony-jolt Jolt harmony-core)

if(MSVC)
    target_compile_options(harmony-jolt PRIVATE "/MP" "/Zi")
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<$<CONFIG:Debug,Release>:ProgramDatabase>")
    # should this be in root? 
    set_property(TARGET Jolt PROPERTY
    MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()