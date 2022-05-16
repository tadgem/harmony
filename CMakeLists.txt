cmake_minimum_required(VERSION 3.0.0)
project(Harmony)


SET(DAS_FLEX_BISON_DISABLED TRUE CACHE BOOL "disable flex/bison")
SET(DAS_CLANG_BIND_DISABLED OFF CACHE BOOL "disable libclang")
SET(DAS_IMGUI_DISABLED FALSE CACHE BOOL "enable imgui")
SET(DAS_GLFW_DISABLED FALSE CACHE BOOL "disable glfw")
SET(DAS_BGFX_DISABLED OFF CACHE BOOL "enable bgfx")
SET(DAS_BUILD_PROFILE OFF CACHE BOOL "enable bgfx")
SET(DAS_BUILD_TUTORIAL OFF CACHE BOOL "enable bgfx")

SET(SDL_SENSOR_ENABLED_BY_DEFAULT OFF CACHE BOOL "Disable SDL Sensor API")
SET(SDL_SENSOR OFF CACHE BOOL "Disable SDL Sensor API")

add_subdirectory(submodules/glm)
add_subdirectory(submodules/bgfx)
add_subdirectory(submodules/daScript)
add_subdirectory(submodules/sdl)
add_subdirectory(submodules/spdlog)

add_subdirectory(harmony)
add_subdirectory(modules/harmony-das)
add_subdirectory(sandbox)