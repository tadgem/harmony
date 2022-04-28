cmake_minimum_required(VERSION 3.0.0)
project(Harmony)

SET(DAS_FLEX_BISON_DISABLED TRUE CACHE BOOL "disable flex/bison")
SET(DAS_CLANG_BIND_DISABLED OFF CACHE BOOL "disable libclang")
SET(DAS_IMGUI_DISABLED FALSE CACHE BOOL "enable imgui")
SET(DAS_GLFW_DISABLED FALSE CACHE BOOL "disable glfw")
SET(DAS_BGFX_DISABLED OFF CACHE BOOL "enable bgfx")
SET(DAS_BUILD_PROFILE OFF CACHE BOOL "enable bgfx")
SET(DAS_BUILD_TUTORIAL OFF CACHE BOOL "enable bgfx")

add_subdirectory(submodules/daScript)

add_subdirectory(harmony)
add_subdirectory(sandbox)