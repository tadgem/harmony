cmake_minimum_required(VERSION 3.20.0)
project(harmony-editor-runtime VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" src/*.cpp)
file(GLOB_RECURSE HEADER_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" include/*.h)
file(GLOB_RECURSE HEADERPP_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" include/*.hpp)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS /W2)
endif ()

add_library(harmony-editor-runtime STATIC ${HEADER_FILES} ${HEADERPP_FILES} ${SRC_FILES})
set_property(TARGET harmony-editor-runtime PROPERTY CXX_STANDARD 17)

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


get_filename_component(TEMP_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(ROOT_DIR ${TEMP_DIR} DIRECTORY)

set(HARMONY_EDITOR_INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${ROOT_DIR}/submodules/efsw/include
        ${HARMONY_CORE_RUNTIME_INCLUDES}
        ${HARMONY_ASSIMP_INCLUDES}
        CACHE INTERNAL "")

target_include_directories(harmony-editor-runtime PUBLIC ${HARMONY_EDITOR_INCLUDES})
target_link_libraries(harmony-editor-runtime harmony-runtime efsw)

if(MSVC)
    target_compile_options(harmony-editor-runtime PRIVATE "/MP" "/Zi")
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<$<CONFIG:Debug,Release>:ProgramDatabase>")
endif()