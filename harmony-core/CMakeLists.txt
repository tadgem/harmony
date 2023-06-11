cmake_minimum_required(VERSION 3.0.0)
project(harmony-core VERSION 0.1.0)

option(HARMONY_DEBUG "Build harmony with debug functionality enabled." ON)
option(HARMONY_USE_LUAJIT "Use LuaJIT instead of regular Lua" ON)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS /W2)
endif ()

file(GLOB_RECURSE CORE_SRC_FILES src/*.cpp)
file(GLOB_RECURSE CORE_HEADER_FILES include/*.h)
file(GLOB_RECURSE CORE_HEADERPP_FILES include/*.hpp)
get_filename_component(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

set(BGFX_BUILD_EXAMPLES ON CACHE BOOL "Disable BGFX Examples")
set(SDL2_DISABLE_SDL2MAIN ON CACHE BOOL "Disable SDL Entrypoint")
set(SDL2_DISABLE_INSTALL ON CACHE BOOL "Disable SDL Install")
set(SDL2_DISABLE_UNINSTALL ON CACHE BOOL "Disable SDL Uninstall")

add_subdirectory(${ROOT_DIR}/submodules/glm ${CMAKE_CURRENT_BINARY_DIR}/glm)
add_subdirectory(${ROOT_DIR}/submodules/bgfx ${CMAKE_CURRENT_BINARY_DIR}/bgfx)
add_subdirectory(${ROOT_DIR}/submodules/sdl ${CMAKE_CURRENT_BINARY_DIR}/sdl)
add_subdirectory(${ROOT_DIR}/submodules/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
add_subdirectory(${ROOT_DIR}/submodules/optick ${CMAKE_CURRENT_BINARY_DIR}/optick)

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
set(HARMONY_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE INTERNAL "")

add_library(harmony-core STATIC ${CORE_HEADER_FILES} ${CORE_HEADERPP_FILES} ${CORE_SRC_FILES} src/Rendering/Texture.cpp src/Rendering/Pipelines/PipelineV2.cpp include/Rendering/TypeDef.h include/Rendering/Pipelines/PipelineStages/BlitStage.h src/Rendering/Pipelines/PipelineStages/BlitStage.cpp)
set_property(TARGET harmony-core PROPERTY CXX_STANDARD 17)

set(HARMONY_CORE_INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${ROOT_DIR}/submodules/sdl/include
        ${ROOT_DIR}/submodules/spdlog/include
        ${ROOT_DIR}/submodules/bgfx/bgfx/include
        ${ROOT_DIR}/submodules/bgfx/bx/include
        ${ROOT_DIR}/submodules/bgfx/bimg/include
        ${ROOT_DIR}/submodules/glm/glm
        ${ROOT_DIR}/submodules/optick/src
        )


if (HARMONY_DEBUG)
    target_compile_definitions(harmony-core PUBLIC SDL_SENSOR_DUMMY HARMONY_DEBUG)
endif ()

if (HARMONY_USE_LUAJIT)
    add_subdirectory(${ROOT_DIR}/submodules/luajit-cmake ${CMAKE_CURRENT_BINARY_DIR}/luajit)
    set(HARMONY_CORE_INCLUDES ${HARMONY_CORE_INCLUDES} ${ROOT_DIR}/submodules/luajit-cmake/src CACHE INTERNAL "Harmony Core Includes")
    target_link_libraries(harmony-core SDL2-static spdlog::spdlog bx bimg bimg_decode bgfx glm OptickCore libluajit)
else ()
    add_subdirectory(${ROOT_DIR}/submodules/lua-cmake ${CMAKE_CURRENT_BINARY_DIR}/lua)
    set(HARMONY_CORE_INCLUDES ${HARMONY_CORE_INCLUDES} ${ROOT_DIR}/submodules/lua-cmake/upstream CACHE INTERNAL "Harmony Core Includes")
    target_link_libraries(harmony-core SDL2-static spdlog::spdlog bx bimg bimg_decode bgfx glm OptickCore lua)
endif ()

if (MSVC)
    target_compile_options(harmony-core PRIVATE /bigobj)
else ()
    target_compile_options(harmony-core PRIVATE -Wa,-mbig-obj)
endif ()

# Includes + Link Dirs
target_include_directories(harmony-core PRIVATE
        ${HARMONY_CORE_INCLUDES}
        )
