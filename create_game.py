import os
import sys
from distutils.dir_util import copy_tree

template_core_runtime_target_name = "game-core-runtime";
template_editor_runtime_target_name = "harmony-editor-runtime";
template_app_target_name = "harmony-app";
template_editor_target_name = "harmony-dojo";


template_core_includes_name = "GAME_CORE_RUNTIME_INCLUDES"
template_editor_includes_name = "GAME_EDITOR_INCLUDES"

temp_include_cmake_string = "get_filename_component(TEMP_DIR $\{CMAKE_CURRENT_SOURCE_DIR\} DIRECTORY)"


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

    os.rename(core_runtime_dst + "/include/GameProgram.h", core_runtime_dst + "/include/" + name + ".h")
    os.rename(core_runtime_dst + "/src/GameProgram.cpp", core_runtime_dst + "/src/" + name + ".cpp")

if __name__ == "__main__":
    main()