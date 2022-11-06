from __future__ import absolute_import
from enum import Enum
from re import I
import ctypes
import os
import subprocess
import sys
import dearpygui.dearpygui as dpg


# TODO: Add support for other platforms
shaderc_location = "tools/bgfx-shaderc/bin/shaderc.exe"

class ShaderStage(Enum):
    Vertex = 1
    Fragment = 2
    Compute = 3

shader_stages = ["Vertex", "Fragment", "Compute"]
shader_types = ["v","f", "c"]
shader_name = ""
dx_shader_types = ["v", "p", "c"]
current_shader_stage_selection = 0
current_platform_selection = 0

source_path = "shaders/vs_normal.sc"
include_path = "shaders/include"
output_path = "shaders/bin/"
varying_def_path = "shaders/varying.def.sc"

renderers = ["dx9", "dx11","pssl","metal","glsl","essl", "spv"]
renderer_shader_profile = ["s_3_0", "s_5_0", "pssl", "metal", "430", "300_es", "spirv"]

def build_output_path(platform):
    base = output_path + renderers[platform] + "/"
    directory = os.path.dirname(base)
    if not os.path.exists(directory):
        os.makedirs(directory)
    shader_name = source_path.rsplit('/', 1)[-1]
    shader_name = shader_name[:-3]
    return base + shader_name + ".bin"

def build_bintoexe_output_path(platform):
    base = output_path + renderers[platform] + "/"
    directory = os.path.dirname(base)
    if not os.path.exists(directory):
        os.makedirs(directory)
    shader_name = source_path.rsplit('/', 1)[-1]
    shader_name = shader_name[:-3]
    return base + shader_name + ".bin.h"

def build_renderer_profile_name(shaderStage, platform):
    ret = renderer_shader_profile[platform]
    if(platform < 2):
        return dx_shader_types[shaderStage] + ret
    return ret

def build_compile_command(shaderStage, platform):
    command = "\"" + shaderc_location + "\"" + " -f " + source_path + " -i " + include_path + " -o " + build_output_path(platform) + " --type " + shader_types[shaderStage] + " --varyingdef " + varying_def_path + " -p " + build_renderer_profile_name(shaderStage, platform)
    print("Build command : ", command)
    return command

def build_bintoexe_command(shaderStage, platform):
    global shader_name
    shader_name = source_path.rsplit('/', 1)[-1]
    shader_name = shader_name[:-3]
    command = "\"" + shaderc_location + "\"" + " -f " + source_path + " -i " + include_path + " -o " + build_bintoexe_output_path(platform) + " --bin2c " + shader_name + "_" + renderers[platform] + " --type " + shader_types[shaderStage] + " --varyingdef " + varying_def_path + " -p " + build_renderer_profile_name(shaderStage, platform)
    print("Build Embedded Shader Command : ", command)
    return command

def shader_tool():
    global source_path
    global include_path
    global output_path
    global varying_def_path
        
    dpg.add_separator()
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

    changed, varying_def_path_text = imgui.input_text(
    'Varying Def Path',
    varying_def_path,
    256
    )
    varying_def_path = varying_def_path_text

    changed, output_text = imgui.input_text(
    'Output Path',
    output_path,
    256
    )
    dpg.add_separator()
    output_path = output_text

    global current_shader_stage_selection
    clicked, current = imgui.combo(
    "Shader Type", current_shader_stage_selection, shader_stages)
    current_shader_stage_selection = current
    dpg.add_separator()

    global current_platform_selection
    clicked, current_platform = imgui.combo(
    "Renderer", current_platform_selection, renderers)
    current_platform_selection = current_platform
    dpg.add_separator()

    if imgui.button("Compile Shaders"):
        command = build_compile_command(current_shader_stage_selection, current_platform_selection)
        subprocess.call(command)

    if imgui.button("Compile Shaders (All Platforms)"):
        for renderer in range(len(renderers)):
            command = build_compile_command(current_shader_stage_selection, renderer)
            subprocess.call(command)

    if imgui.button("Build Embedded Shader"):
        for renderer in range(len(renderers)):
            command = build_bintoexe_command(current_shader_stage_selection, renderer)
            subprocess.call(command)
        binary_array_strings = []
        binary_array_strings.append("#pragma once")
        for dir in os.listdir("./shaders/bin"):
            if os.path.isdir("./shaders/bin/" + dir) == False:
                continue

            print(dir)
            
            filedir = "./shaders/bin/" + dir + "/" + shader_name + ".bin.h"
            if(os.path.exists(filedir)):
                text_file = open(filedir, 'r')
                data = text_file.read();
                binary_array_strings.append(data)
                text_file.close()
                os.remove(filedir)
            else:
                empty_shader = "extern const uint8_t* " + shader_name + "_" + dir + ";"
                empty_shader_size = "extern const uint32_t " + shader_name + "_" + dir + "_size;"
                binary_array_strings.append(empty_shader)
                binary_array_strings.append(empty_shader_size)
        text_file = open("./shaders/bin/" + shader_name + ".bin.h", 'w')
        for shader in binary_array_strings:
            text_file.write(shader)
            text_file.write("\n\n")

        text_file.close()

        for dir in os.listdir("./shaders/bin"):
            renderer_dir = "./shaders/bin/" + dir
            if(os.path.isdir(renderer_dir)):
                os.rmdir("./shaders/bin/" + dir)
                


def main():
    dpg.create_context()
    dpg.create_viewport()
    dpg.setup_dearpygui()

    with dpg.window(label="Harmony Shader Tool"):
        shader_tool()

    dpg.show_viewport()
    dpg.start_dearpygui()
    dpg.destroy_context()

if __name__ == "__main__":
    main()