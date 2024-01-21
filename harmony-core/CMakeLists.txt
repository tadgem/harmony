cmake_minimum_required(VERSION 3.0.0)
project(harmony-core VERSION 0.1.0)

option(HARMONY_DEBUG "Build harmony with debug functionality enabled." ON)
option(HARMONY_USE_LUAJIT "Use LuaJIT instead of regular Lua" ON)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS /W2)
endif ()

file(GLOB_RECURSE CORE_SRC_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" src/*.cpp)
file(GLOB_RECURSE CORE_HEADER_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" include/*.h)
file(GLOB_RECURSE CORE_HEADERPP_FILES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" include/*.hpp)
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

# organize for VS
set_target_properties(SDL2 PROPERTIES FOLDER "ThirdParty/SDL")
set_target_properties(SDL2_test PROPERTIES FOLDER "ThirdParty/SDL")
set_target_properties(SDL2-static PROPERTIES FOLDER "ThirdParty/SDL")
set_target_properties(sdl_headers_copy PROPERTIES FOLDER "ThirdParty/SDL")
set_target_properties(spdlog PROPERTIES FOLDER "ThirdParty")
set_target_properties(OptickCore PROPERTIES FOLDER "ThirdParty")

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
set(HARMONY_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE INTERNAL "")

add_library(harmony-core STATIC ${CORE_HEADER_FILES} ${CORE_HEADERPP_FILES} ${CORE_SRC_FILES})
set_property(TARGET harmony-core PROPERTY CXX_STANDARD 17)

# VS Filters
foreach(header IN LISTS CORE_HEADER_FILES)
    get_filename_component(source_path "${header}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${header}")
endforeach()

foreach(header IN LISTS CORE_HEADERPP_FILES)
    get_filename_component(source_path "${header}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${header}")
endforeach()

foreach(source IN LISTS CORE_SRC_FILES)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()

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

SET(HARMONY_CORE_LIBRARIES
        SDL2-static spdlog::spdlog bx bimg bimg_decode bimg_encode bgfx glm OptickCore
)

if (MSVC)
    target_compile_options(harmony-core PRIVATE "/bigobj" "/MP" "/Zi")
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<$<CONFIG:Debug,Release>:ProgramDatabase>")
    SET(HARMONY_CORE_LIBRARIES
            ${HARMONY_CORE_LIBRARIES} dwmapi
    )
else ()
    target_compile_options(harmony-core PRIVATE)
endif ()


if (HARMONY_USE_LUAJIT)
    add_subdirectory(${ROOT_DIR}/submodules/luajit-cmake ${CMAKE_CURRENT_BINARY_DIR}/luajit)
    set(HARMONY_CORE_INCLUDES ${HARMONY_CORE_INCLUDES} ${ROOT_DIR}/submodules/luajit-cmake/src CACHE INTERNAL "Harmony Core Includes")
    target_link_libraries(harmony-core ${HARMONY_CORE_LIBRARIES} libluajit)
else ()
    add_subdirectory(${ROOT_DIR}/submodules/lua-cmake ${CMAKE_CURRENT_BINARY_DIR}/lua)
    set(HARMONY_CORE_INCLUDES ${HARMONY_CORE_INCLUDES} ${ROOT_DIR}/submodules/lua-cmake/upstream CACHE INTERNAL "Harmony Core Includes")
    target_link_libraries(harmony-core ${HARMONY_CORE_LIBRARIES} lua)
endif ()

# Put in a "bgfx" folder in Visual Studio
set_target_properties(libluajit PROPERTIES FOLDER "ThirdParty/LuaJIT-Libs")
set_target_properties(buildvm_arch_h PROPERTIES FOLDER "ThirdParty/LuaJIT-Libs")
set_target_properties(buildvm PROPERTIES FOLDER "ThirdParty/LuaJIT-Libs")
set_target_properties(lj_gen_headers PROPERTIES FOLDER "ThirdParty/LuaJIT-Libs")
set_target_properties(lj_gen_folddef PROPERTIES FOLDER "ThirdParty/LuaJIT-Libs")
set_target_properties(lj_gen_vm_s PROPERTIES FOLDER "ThirdParty/LuaJIT-Libs")
set_target_properties(minilua PROPERTIES FOLDER "ThirdParty/LuaJIT-Libs")
set_target_properties(luajit PROPERTIES FOLDER "ThirdParty/LuaJIT-Libs")
# Includes + Link Dirs
target_include_directories(harmony-core PRIVATE
        ${HARMONY_CORE_INCLUDES}
        )
