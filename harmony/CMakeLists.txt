cmake_minimum_required(VERSION 3.0.0)
project(harmony-core VERSION 0.1.0)

file(GLOB_RECURSE CORE_SRC_FILES src/*.cpp)
file(GLOB_RECURSE CORE_HEADER_FILES include/*.h)
file(GLOB_RECURSE CORE_HEADERPP_FILES include/*.hpp)

get_filename_component(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

set(HARMONY_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE INTERNAL "")

set(IMGUI_BACKEND_SRC_FILES 
${imgui_INCLUDE_DIR}/backends/imgui_impl_sdl.h
${imgui_INCLUDE_DIR}/backends/imgui_impl_sdl.cpp
CACHE INTERNAL "")


add_library(harmony ${CORE_HEADER_FILES} ${CORE_HEADERPP_FILES} ${CORE_SRC_FILES} ${IMGUI_BACKEND_SRC_FILES})

set_property(TARGET harmony PROPERTY CXX_STANDARD 17)

set(HARMONY_CORE_INCLUDES 
${CMAKE_CURRENT_SOURCE_DIR}/include 
${DAS_BX_INCLUDE_DIR} 	
${DAS_BX_3P_INCLUDE_DIR}
${DAS_BGFX_INCLUDE_DIR} 
${DAS_BGFX_3P_INCLUDE_DIR}
${DAS_BIMG_INCLUDE_DIR} 
${DAS_BIMG_3P_INCLUDE_DIR}
${DAS_BGFX_COMPAT_DIR}
${DAS_BGFX_KHRONOS_DIR}
${DAS_BGFX_DX12_DIR}
${DAS_BGFX_ASTC_CODEC_DIR}
${DAS_INCLUDE_DIR}
"${CMAKE_CURRENT_SOURCE_DIR}/../submodules/sdl/include"
${imgui_INCLUDE_DIR} 
${ROOT_DIR}/submodules/daScript/modules/dasStbImage/src
${ROOT_DIR}/submodules/spdlog/include
${DAS_BGFX_DIR}/src CACHE INTERNAL "")

target_include_directories(harmony PRIVATE 
    ${HARMONY_CORE_INCLUDES}
)

target_compile_definitions(harmony PUBLIC SDL_SENSOR_DUMMY)
target_link_libraries(harmony libDaScript libDasModuleStbImage libDasModuleBGFX libDasModuleBGFXImgui libDasModuleImGui  SDL2-static spdlog::spdlog)