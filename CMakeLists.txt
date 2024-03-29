cmake_minimum_required(VERSION 3.10.0)
project(harmony-all VERSION 0.1.0)

# harmony build options
option(HARMONY_DEBUG "Build harmony with debug functionality enabled." ON)
option(HARMONY_USE_LUAJIT "Use LuaJIT instead of regular Lua" ON)

# options for dependencies
set(BGFX_BUILD_EXAMPLES         OFF CACHE BOOL "Disable BGFX Examples")
set(SDL2_DISABLE_SDL2MAIN       ON CACHE BOOL "Disable SDL Entrypoint")
set(SDL2_DISABLE_INSTALL        ON CACHE BOOL "Disable SDL Install")
set(SDL2_DISABLE_UNINSTALL      ON CACHE BOOL "Disable SDL Uninstall")
SET(ASSIMP_BUILD_ASSIMP_TOOLS   OFF CACHE BOOL "Dont build assimp tools")
SET(ASSIMP_BUILD_TESTS          OFF CACHE BOOL "Dont build assimp tests")
SET(ASSIMP_INSTALL              OFF CACHE BOOL "Dont install assimp")
set(TARGET_UNIT_TESTS OFF)
set(TARGET_HELLO_WORLD OFF)
set(TARGET_PERFORMANCE_TEST OFF)
set(TARGET_SAMPLES OFF)
set(TARGET_VIEWER OFF)




# add core dependencies
add_subdirectory(submodules/glm)
add_subdirectory(submodules/bgfx)
add_subdirectory(submodules/sdl)
add_subdirectory(submodules/spdlog)
add_subdirectory(submodules/optick)

# add module dependencies (swap out / remove if not needed)
add_subdirectory(submodules/assimp)
add_subdirectory(submodules/jolt/Build)
add_subdirectory(submodules/efsw)

if (HARMONY_USE_LUAJIT)
add_subdirectory(submodules/luajit-cmake)
# Put in a "luajit" folder in Visual Studio
set_target_properties(libluajit PROPERTIES FOLDER "ThirdParty/LuaJIT-Libs")
set_target_properties(buildvm_arch_h PROPERTIES FOLDER "ThirdParty/LuaJIT-Libs")
set_target_properties(buildvm PROPERTIES FOLDER "ThirdParty/LuaJIT-Libs")
set_target_properties(lj_gen_headers PROPERTIES FOLDER "ThirdParty/LuaJIT-Libs")
set_target_properties(lj_gen_folddef PROPERTIES FOLDER "ThirdParty/LuaJIT-Libs")
set_target_properties(lj_gen_vm_s PROPERTIES FOLDER "ThirdParty/LuaJIT-Libs")
set_target_properties(minilua PROPERTIES FOLDER "ThirdParty/LuaJIT-Libs")
set_target_properties(luajit PROPERTIES FOLDER "ThirdParty/LuaJIT-Libs")
else ()
add_subdirectory(submodules/lua-cmake)
endif ()

# organize for VS
set_target_properties(SDL2 PROPERTIES FOLDER "ThirdParty/SDL")
set_target_properties(SDL2_test PROPERTIES FOLDER "ThirdParty/SDL")
set_target_properties(SDL2-static PROPERTIES FOLDER "ThirdParty/SDL")
set_target_properties(sdl_headers_copy PROPERTIES FOLDER "ThirdParty/SDL")
set_target_properties(spdlog PROPERTIES FOLDER "ThirdParty")
set_target_properties(OptickCore PROPERTIES FOLDER "ThirdParty")
set_target_properties(assimp PROPERTIES FOLDER "ThirdParty")
set_target_properties(zlibstatic PROPERTIES FOLDER "ThirdParty")
set_target_properties(Jolt PROPERTIES FOLDER "ThirdParty")
set_target_properties(efsw PROPERTIES FOLDER "ThirdParty")

add_subdirectory(harmony-core)
add_subdirectory(harmony-modules/harmony-assimp)
add_subdirectory(harmony-modules/harmony-jolt)
add_subdirectory(harmony-modules/harmony-mono)
add_subdirectory(harmony-runtime)
add_subdirectory(templates/harmony-editor-runtime)
add_subdirectory(templates/game-core-runtime)
add_subdirectory(templates/harmony-app)
add_subdirectory(templates/harmony-dojo)