# -*- coding: utf-8 -*-
from re import I
from sdl2 import *
import ctypes
import OpenGL.GL as gl
import os
import subprocess
from enum import Enum

import imgui
from imgui.integrations.sdl2 import SDL2Renderer

# TODO: Add support for oher platforms.
shaderc_location = "tools/bgfx-shaderc/bin/shaderc.exe"

class ShaderStage(Enum):
    Vertex = 1
    Fragment = 2
    Compute = 3

shader_stages = ["Vertex", "Fragment", "Compute"]
shader_types = ["v","f", "c"]
current_shader_stage_selection = 0
current_platform_selection = 0

source_path = "shaders/vs_cubes.sc"
include_path = "shaders/include"
output_path = "shaders/bin/"

platforms = ["android", "asm.js","ios","linux","orbis","osx","windows"]

def build_output_path(platform):
    base = output_path + platforms[platform] + "/"
    directory = os.path.dirname(base)
    if not os.path.exists(directory):
        os.makedirs(directory)
    shader_name = source_path.rsplit('/', 1)[-1]
    shader_name = shader_name[:-3]
    return base + shader_name + ".bin"


def build_compile_command(shaderStage, platform):
    command = "\"" + shaderc_location + "\"" + " -f " + source_path + " -i " + include_path + " -o " + build_output_path(platform) + " --type " + shader_types[shaderStage] + " --plaform " + platforms[platform]
    print("Build command : ", command)
    return command

def shader_tool():
    global source_path
    global include_path
    global output_path
    
    imgui.separator()
    changed, shader_text = imgui.input_text(
    'Input Shader Path',
    source_path,
    256
    )
    source_path = shader_text
    
    changed, include_path_text = imgui.input_text(
    'Input Include Path',
    include_path,
    256
    )
    include_path = include_path_text

    changed, output_text = imgui.input_text(
    'Output Path',
    output_path,
    256
    )
    imgui.separator()
    output_path = output_text

    global current_shader_stage_selection
    clicked, current = imgui.combo(
    "Shader Type", current_shader_stage_selection, shader_stages)
    current_shader_stage_selection = current
    imgui.separator()

    global current_platform_selection
    clicked, current_platform = imgui.combo(
    "Platform", current_platform_selection, platforms)
    current_platform_selection = current_platform
    imgui.separator()

    if imgui.button("Compile Shaders"):
        command = build_compile_command(current_shader_stage_selection, current_platform_selection)
        subprocess.call(command)


def main():
    window, gl_context = impl_pysdl2_init()
    imgui.create_context()
    impl = SDL2Renderer(window)

    running = True
    event = SDL_Event()
    while running:
        while SDL_PollEvent(ctypes.byref(event)) != 0:
            if event.type == SDL_QUIT:
                running = False
                break
            impl.process_event(event)
        impl.process_inputs()
        imgui.new_frame()
        imgui.begin("BGFX Shader Tool")
        shader_tool()
        imgui.end()
        gl.glClearColor(0., 0., 0., 1)
        gl.glClear(gl.GL_COLOR_BUFFER_BIT)

        imgui.render()
        impl.render(imgui.get_draw_data())
        SDL_GL_SwapWindow(window)

    impl.shutdown()
    SDL_GL_DeleteContext(gl_context)
    SDL_DestroyWindow(window)
    SDL_Quit()


def impl_pysdl2_init():
    width, height = 1280, 720
    window_name = "minimal ImGui/SDL2 example"

    if SDL_Init(SDL_INIT_EVERYTHING) < 0:
        print("Error: SDL could not initialize! SDL Error: " + SDL_GetError().decode("utf-8"))
        exit(1)

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1)
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24)
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8)
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1)
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1)
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 16)
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG)
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4)
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1)
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE)

    SDL_SetHint(SDL_HINT_MAC_CTRL_CLICK_EMULATE_RIGHT_CLICK, b"1")
    SDL_SetHint(SDL_HINT_VIDEO_HIGHDPI_DISABLED, b"1")

    window = SDL_CreateWindow(window_name.encode('utf-8'),
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              width, height,
                              SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE)

    if window is None:
        print("Error: Window could not be created! SDL Error: " + SDL_GetError().decode("utf-8"))
        exit(1)

    gl_context = SDL_GL_CreateContext(window)
    if gl_context is None:
        print("Error: Cannot create OpenGL Context! SDL Error: " + SDL_GetError().decode("utf-8"))
        exit(1)

    SDL_GL_MakeCurrent(window, gl_context)
    if SDL_GL_SetSwapInterval(1) < 0:
        print("Warning: Unable to set VSync! SDL Error: " + SDL_GetError().decode("utf-8"))
        exit(1)

    return window, gl_context

if __name__ == "__main__":
    main()