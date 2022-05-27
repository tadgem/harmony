cmake_minimum_required(VERSION 3.0.0)
project(harmony-das VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES src/das/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/das/*.h)
file(GLOB_RECURSE HEADERPP_FILES include/das/*.hpp)

add_library(harmony-das ${HEADER_FILES} ${HEADERPP_FILES} ${SRC_FILES})
set_property(TARGET harmony-das PROPERTY CXX_STANDARD 17)

add_subdirectory(${ROOT_DIR}/submodules/daScript ${CMAKE_CURRENT_BINARY_DIR}/daScript)

set(HARMONY_DAS_INCLUDES 
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
${ROOT_DIR}/submodules/sdl/include
${ROOT_DIR}/submodules/daScript/modules/dasStbImage/src
${ROOT_DIR}/submodules/daScript/modules/dasImgui/src
${ROOT_DIR}/submodules/spdlog/include
${HARMONY_CORE_INCLUDES}
${DAS_BGFX_DIR}/src CACHE INTERNAL "")

target_include_directories(harmony-das PRIVATE 
    ${HARMONY_DAS_INCLUDES}
)

target_link_libraries(harmony-das harmony-core libDaScript libDasModuleBGFX libDasModuleBGFXImgui libDasModuleImGui)