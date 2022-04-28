cmake_minimum_required(VERSION 3.0.0)
project(harmony-core VERSION 0.1.0)

file(GLOB_RECURSE CORE_SRC_FILES src/*.cpp)
file(GLOB_RECURSE CORE_HEADER_FILES include/*.h)

set(HARMONY_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE INTERNAL "")

add_library(harmony ${CORE_HEADER_FILES} ${CORE_SRC_FILES})

target_include_directories(harmony PRIVATE 
    include ${DAS_BX_INCLUDE_DIR} 	${DAS_BX_3P_INCLUDE_DIR}
    ${DAS_BGFX_INCLUDE_DIR} ${DAS_BGFX_3P_INCLUDE_DIR}
    ${DAS_BIMG_INCLUDE_DIR} ${DAS_BIMG_3P_INCLUDE_DIR}
    ${DAS_BGFX_COMPAT_DIR}
    ${DAS_BGFX_KHRONOS_DIR}
    ${DAS_BGFX_DX12_DIR}
    ${DAS_BGFX_ASTC_CODEC_DIR}
)
target_link_libraries(harmony libDaScript libDasModuleBGFX libDasModuleBGFXImgui)