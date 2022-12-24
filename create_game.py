import os
import sys
from distutils.dir_util import copy_tree

template_core_runtime_target_name = "game-core-runtime";
template_editor_runtime_target_name = "harmony-editor-runtime";
template_app_target_name = "harmony-app";
template_editor_target_name = "harmony-dojo";


template_core_includes_name = "GAME_CORE_RUNTIME_INCLUDES"
template_editor_includes_name = "GAME_EDITOR_INCLUDES"

cmake_dir_helper = "get_filename_component(TEMP_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)\nget_filename_component(ROOT_DIR ${TEMP_DIR} DIRECTORY)"
cmake_dir_helper_replacement = "get_filename_component(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)"

static_game_name_line = "inline static const std::string GameName = \"Game\";"

def build_static_game_name(name):
    return f"inline static const std::string GameName = \"{name}\";"

def inplace_change(filename, old_string, new_string):
    # Safely read the input filename using 'with'
    with open(filename) as f:
        s = f.read()
        if old_string not in s:
            print(f'"{old_string}" not found in {filename}.')
            return

    # Safely write the changed content, if found in the file
    with open(filename, 'w') as f:
        print(f'Changing "{old_string}" to "{new_string}" in {filename}')
        s = s.replace(old_string, new_string)
        f.write(s)

def main():
    name = sys.argv[1]
    print(f"Harmony : Generating project : {name}")

    core_runtime_dst = name.lower() + "-core-runtime"
    editor_runtime_dst = name.lower() + "-editor-runtime"
    app_dst = name.lower() + "-app"
    editor_dst = name.lower() + "-dojo"

    copy_tree(f"templates/{template_core_runtime_target_name}", core_runtime_dst)
    copy_tree(f"templates/{template_editor_runtime_target_name}", editor_runtime_dst)
    copy_tree(f"templates/{template_app_target_name}", app_dst)
    copy_tree(f"templates/{template_editor_target_name}", editor_dst)

    new_program_name = f"{name}Program"
    game_core_runtime_includes = f"{name.upper()}_CORE_RUNTIME_INCLUDES";
    game_editor_includes = f"{name.upper()}_EDITOR_INCLUDES";
    # Game Core Runtime
    game_program_header_name = core_runtime_dst + "/include/" + new_program_name + ".h"
    game_program_cpp_name = core_runtime_dst + "/src/" + new_program_name + ".cpp"

    os.rename(core_runtime_dst + "/include/GameProgram.h", game_program_header_name )
    os.rename(core_runtime_dst + "/src/GameProgram.cpp", game_program_cpp_name)
    
    inplace_change(game_program_header_name, "GameProgram", new_program_name)
    inplace_change(game_program_cpp_name, "GameProgram", new_program_name)
    inplace_change(game_program_header_name, static_game_name_line, build_static_game_name(name))
    inplace_change(f"{core_runtime_dst}/CMakeLists.txt", template_core_runtime_target_name, core_runtime_dst)
    inplace_change(f"{core_runtime_dst}/CMakeLists.txt", template_core_includes_name, game_core_runtime_includes)
    inplace_change(f"{core_runtime_dst}/CMakeLists.txt", cmake_dir_helper, cmake_dir_helper_replacement)

    # Game App
    game_app_cpp_name = app_dst + "/main.cpp"
    inplace_change(game_app_cpp_name, "Runtime", name)
    inplace_change(f"{app_dst}/CMakeLists.txt", "harmony-app", app_dst)
    inplace_change(f"{app_dst}/CMakeLists.txt", "HARMONY_CORE_RUNTIME_INCLUDES", game_core_runtime_includes)
    inplace_change(f"{app_dst}/CMakeLists.txt", "harmony-runtime", core_runtime_dst)
    inplace_change(f"{app_dst}/CMakeLists.txt", cmake_dir_helper, cmake_dir_helper_replacement)

    # Editor Runtime
    inplace_change(f"{editor_runtime_dst}/CMakeLists.txt", template_editor_runtime_target_name, editor_runtime_dst)
    inplace_change(f"{editor_runtime_dst}/CMakeLists.txt", "HARMONY_CORE_RUNTIME_INCLUDES", game_core_runtime_includes)
    inplace_change(f"{editor_runtime_dst}/CMakeLists.txt", "HARMONY_EDITOR_INCLUDES", game_editor_includes)
    inplace_change(f"{editor_runtime_dst}/CMakeLists.txt", "harmony-runtime", core_runtime_dst)
    inplace_change(f"{editor_runtime_dst}/include/EditorApplication.h", "RuntimeProgram", new_program_name)
    inplace_change(f"{editor_runtime_dst}/src/EditorApplication.cpp", "RuntimeProgram", new_program_name)
    inplace_change(f"{editor_runtime_dst}/CMakeLists.txt", cmake_dir_helper, cmake_dir_helper_replacement)

    # Dojo
    inplace_change(f"{editor_dst}/CMakeLists.txt", template_editor_target_name, editor_dst)
    inplace_change(f"{editor_dst}/CMakeLists.txt", template_editor_runtime_target_name, editor_runtime_dst)
    inplace_change(f"{editor_dst}/CMakeLists.txt", "HARMONY_EDITOR_INCLUDES", game_editor_includes)
    inplace_change(f"{editor_dst}/CMakeLists.txt", cmake_dir_helper, cmake_dir_helper_replacement)
    inplace_change(f"{editor_dst}/CMakeLists.txt", "${ROOT_DIR}/templates/", "${ROOT_DIR}/")

if __name__ == "__main__":
    main()