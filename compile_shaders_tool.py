from __future__ import absolute_import
from enum import Enum
from re import I
import ctypes
import os
import subprocess
import sys
import platform
import dearpygui.dearpygui as dpg

class ShaderStage(Enum):
    Vertex = 1
    Fragment = 2
    Compute = 3

shader_stages   = ['Vertex', 'Fragment', 'Compute']
shader_types    = ['v','f', 'c']
dx_shader_types = ['v','p', 'c']
shader_name     = ''

current_shader_stage_selection  = 0
current_platform_selection      = 0

source_path         = 'shaders/vs_normal.sc'
include_path        = 'shaders/include'
output_path         = 'shaders/bin/'
varying_def_path    = 'shaders/varying.def.sc'

shaderc_location    = 'tools/bgfx-shaderc/bin/'

renderers               = ['dx9', 'dx11','pssl','metal','glsl','essl', 'spv']
renderer_shader_profile = ['s_3_0', 's_5_0', 'pssl', 'metal', '430', '300_es', 'spirv']

current_os = platform.system()

def run_command(command):
    global current_os

    if(current_os == 'Windows'):
        subprocess.call(command)
    else:
        os.system(command)

def build_shaderc_path():
    global shaderc_location
    global current_os
    
    if(current_os == 'Windows'):
        if(os.path.isfile(shaderc_location + "shaderc-win")):
            try:
                os.rename(shaderc_location + "shaderc-win", shaderc_location + "shaderc-win.exe")
            except WindowsError:
                os.remove(shaderc_location + "shaderc-win.exe")
                os.rename(shaderc_location + "shaderc-win", shaderc_location + "shaderc-win.exe")

    if(current_os == 'Linux'):
        shaderc_location += 'shaderc-ubuntu'
    elif(current_os == 'Windows'):
        shaderc_location += 'shaderc-win.exe'
    elif(current_os == 'Darwin'):
        shaderc_location += 'shaderc-osx'
    else:
        print('Unknown platform :(')
    

    print('shaderc Location : ' + shaderc_location)

def build_output_path(platform):
    base = output_path + renderers[platform] + '/'
    directory = os.path.dirname(base)
    if not os.path.exists(directory):
        os.makedirs(directory)
    shader_name = source_path.rsplit('/', 1)[-1]
    shader_name = shader_name[:-3]
    return base + shader_name + '.bin'

def build_bintoexe_output_path(platform):
    base = output_path + renderers[platform] + '/'
    directory = os.path.dirname(base)
    if not os.path.exists(directory):
        os.makedirs(directory)
    shader_name = source_path.rsplit('/', 1)[-1]
    shader_name = shader_name[:-3]
    return base + shader_name + '.bin.h'

def build_renderer_profile_name(shaderStage, platform):
    ret = renderer_shader_profile[platform]
    if(platform < 2):
        return dx_shader_types[shaderStage] + ret
    return ret

def build_compile_command(shaderStage, platform):
    command = './' + shaderc_location + ' -f ' + source_path + ' -i ' + include_path + ' -o ' + build_output_path(platform) + ' --type ' + shader_types[shaderStage] + ' --varyingdef ' + varying_def_path + ' -p ' + build_renderer_profile_name(shaderStage, platform)
    print('Build command : ', command)
    return command

def build_bintoexe_command(shaderStage, platform):
    global shader_name
    shader_name = source_path.rsplit('/', 1)[-1]
    shader_name = shader_name[:-3]
    command = './' + shaderc_location + ' -f ' + source_path + ' -i ' + include_path + ' -o ' + build_bintoexe_output_path(platform) + ' --bin2c ' + shader_name + '_' + renderers[platform] + ' --type ' + shader_types[shaderStage] + ' --varyingdef ' + varying_def_path + ' -p ' + build_renderer_profile_name(shaderStage, platform)
    print('Build Embedded Shader Command : ', command)
    return command

def shader_source_path_callback(sender, app_data, user_data):
    global source_path
    source_path = app_data

def shader_include_path_callback(sender, app_data, user_data):
    global include_path
    include_path = app_data

def shader_varying_def_path_callback(sender, app_data, user_data):
    global varying_def_path
    varying_def_path = app_data

def shader_output_path_callback(sender, app_data, user_data):
    global output_path
    output_path = app_data

def OnCompileShader(sender, app_data, user_data):
    global current_shader_stage_selection
    global current_platform_selection
    command = build_compile_command(current_shader_stage_selection, current_platform_selection)
    run_command(command)

def OnCompileShaderAllPlatform(sender, app_data, user_data):
    global current_shader_stage_selection
    for renderer in range(len(renderers)):
        command = build_compile_command(current_shader_stage_selection, renderer)
        run_command(command)

def OnSelectedShaderType(sender, app_data, user_data):
    global current_shader_stage_selection
    current_shader_stage_selection = shader_stages.index(app_data)

def OnSelectedRenderer(sender, app_data, user_data):
    global current_platform_selection
    current_platform_selection = renderers.index(app_data)

def OnBuildEmbeddedShader(sender, app_data, user_data):
    global current_shader_stage_selection
    for renderer in range(len(renderers)):
        command = build_bintoexe_command(current_shader_stage_selection, renderer)
        run_command(command)
    binary_array_strings = []
    binary_array_strings.append('#pragma once')
    for dir in os.listdir('./shaders/bin'):
        if os.path.isdir('./shaders/bin/' + dir) == False:
            continue

        print(dir)
        
        filedir = './shaders/bin/' + dir + '/' + shader_name + '.bin.h'
        if(os.path.exists(filedir)):
            text_file = open(filedir, 'r')
            data = text_file.read();
            binary_array_strings.append(data)
            text_file.close()
            os.remove(filedir)
        else:
            empty_shader = 'extern const uint8_t* ' + shader_name + '_' + dir + ';'
            empty_shader_size = 'extern const uint32_t ' + shader_name + '_' + dir + '_size;'
            binary_array_strings.append(empty_shader)
            binary_array_strings.append(empty_shader_size)
    text_file = open('./shaders/bin/' + shader_name + '.bin.h', 'w')
    for shader in binary_array_strings:
        text_file.write(shader)
        text_file.write('\n\n')

    text_file.close()

    for dir in os.listdir('./shaders/bin'):
        renderer_dir = './shaders/bin/' + dir
        if(os.path.isdir(renderer_dir)):
            os.rmdir('./shaders/bin/' + dir)

def shader_tool():
    global source_path
    global include_path
    global output_path
    global varying_def_path

    global current_shader_stage_selection
    global current_platform_selection

    dpg.add_separator()

    dpg.add_input_text(label='Input Shader Path', default_value=source_path, callback=shader_source_path_callback)
    dpg.add_input_text(label='Shader Include Path', default_value=include_path, callback=shader_include_path_callback)
    dpg.add_input_text(label='Shader Varying Def. Path', default_value=varying_def_path, callback=shader_varying_def_path_callback)
    dpg.add_input_text(label='Shader Output Path', default_value=output_path, callback=shader_output_path_callback)
    dpg.add_separator()

    dpg.add_combo(shader_stages, label='Shader Type', default_value=shader_stages[current_shader_stage_selection], callback=OnSelectedShaderType)
    dpg.add_separator()
    dpg.add_combo(renderers, label='Renderer', default_value=renderers[current_platform_selection], callback=OnSelectedRenderer)

    dpg.add_button(label='Compile Shader', callback=OnCompileShader)
    dpg.add_button(label='Compile Shader (All Platforms)', callback=OnCompileShaderAllPlatform)
    dpg.add_button(label='Build Embedded Shader', callback=OnBuildEmbeddedShader)
                
def main():
    build_shaderc_path()
    dpg.create_context()
    dpg.create_viewport()
    dpg.setup_dearpygui()

    with dpg.window(label='Harmony Shader Tool'):
        shader_tool()

    dpg.show_viewport()
    dpg.start_dearpygui()
    dpg.destroy_context()

if __name__ == '__main__':
    print("Working Directory : " + os.getcwd())
    main()