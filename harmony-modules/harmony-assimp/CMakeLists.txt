cmake_minimum_required(VERSION 3.20.0)
project(harmony-assimp VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" src/*.cpp)
file(GLOB_RECURSE HEADER_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" include/*.h)
file(GLOB_RECURSE HEADERPP_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" include/*.hpp)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS /W2)
endif ()

add_library(harmony-assimp STATIC ${HEADER_FILES} ${HEADERPP_FILES} ${SRC_FILES})
set_property(TARGET harmony-assimp PROPERTY CXX_STANDARD 17)

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

# Set Options
SET(ASSIMP_BUILD_ASSIMP_TOOLS OFF CACHE BOOL "Dont build assimp tools")
SET(ASSIMP_BUILD_TESTS OFF CACHE BOOL "Dont build assimp tests")
SET(ASSIMP_INSTALL OFF CACHE BOOL "Dont install assimp")

add_subdirectory(${ROOT_DIR}/submodules/assimp ${CMAKE_CURRENT_BINARY_DIR}/assimp)

set_target_properties(assimp PROPERTIES FOLDER "ThirdParty")
set_target_properties(zlibstatic PROPERTIES FOLDER "ThirdParty")


set(HARMONY_ASSIMP_INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${HARMONY_CORE_INCLUDES}
        ${ROOT_DIR}/submodules/assimp/include CACHE INTERNAL "")

target_include_directories(harmony-assimp PUBLIC ${HARMONY_ASSIMP_INCLUDES})
target_link_libraries(harmony-assimp harmony-core assimp)

if(MSVC)
    target_compile_options(harmony-assimp PRIVATE "/MP" "/Zi")
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<$<CONFIG:Debug,Release>:ProgramDatabase>")
endif()