cmake_minimum_required(VERSION 3.22)

project(harmonyc)
set (CMAKE_CXX_STANDARD 17)

# Add clang compile_commands.json for nvim
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(MI_BUILD_SHARED OFF CACHE INTERNAL "")
set(MI_BUILD_TESTS OFF CACHE INTERNAL "")
set(SDL_SHARED OFF CACHE INTERNAL "")
set(SDL_STATIC ON  CACHE INTERNAL "")
set(SDL_TEST_LIBRARY OFF CACHE INTERNAL "")
set(DAWN_FETCH_DEPENDENCIES ON CACHE INTERNAL "")

# Enable this to remove the examples + their dependencies (glm, assimp)
add_subdirectory(submodules/sdl)
add_subdirectory(submodules/flecs)
add_subdirectory(third_party/dawn)
add_subdirectory(third_party/mimalloc)

set(harmonyc_libs
		SDL3-static
		flecs_static
		mimalloc-static
		webgpu_cpp
		dawn_internal_config
		dawn::dawn_common
		dawn::dawn_system_utils
		dawn::dawn_wgpu_utils
		dawn::dawn_proc
		dawn::dawn_native
		webgpu_dawn
)

set(harmonyc_definitions "IMGUI_IMPL_WEBGPU_BACKEND_DAWN")
file(GLOB_RECURSE harmonyc_srcs RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" harmony/src/*.cpp)
set(harmonyc_srcs ${harmonyc_srcs}
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui/imgui.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui/imgui_draw.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui/imgui_tables.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui/imgui_widgets.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui/backends/imgui_impl_sdl3.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui/backends/imgui_impl_wgpu.cpp
)

set(harmonyc_includes
  	${CMAKE_CURRENT_SOURCE_DIR}/third_party/mimalloc/include
  	${CMAKE_CURRENT_SOURCE_DIR}/third_party/mimalloc/src
  	${CMAKE_CURRENT_SOURCE_DIR}/third_party/dawn/include
  	${CMAKE_CURRENT_SOURCE_DIR}/third_party
  	${CMAKE_CURRENT_SOURCE_DIR}/submodules/sdl/include
  	${CMAKE_CURRENT_SOURCE_DIR}/submodules/sdl3webgpu
  	${CMAKE_CURRENT_SOURCE_DIR}/submodules/flecs/include
  	${CMAKE_CURRENT_SOURCE_DIR}/harmony/include
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/glm
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui
)

function(add_harmony_exe exe_name entry_file)
	add_executable(${exe_name} ${harmonyc_srcs} ${entry_file}
			${CMAKE_CURRENT_SOURCE_DIR}/submodules/sdl3webgpu/sdl3webgpu.c)
	target_compile_definitions(${exe_name} PRIVATE ${harmonyc_definitions} )
	target_link_libraries(${exe_name} ${harmonyc_libs})
	target_include_directories(${exe_name} PRIVATE ${harmonyc_includes})
endfunction()

add_harmony_exe(harmonyc_entry tests/Entry.cpp)
add_harmony_exe(harmonyc_core_tests tests/EngineTests.cpp)

add_custom_command(
        TARGET harmonyc_core_tests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.bin
                ${CMAKE_CURRENT_BINARY_DIR}/test.bin)
