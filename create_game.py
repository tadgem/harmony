import os
import sys
from distutils.dir_util import copy_tree

template_core_target_name = "game-core-runtime";
template_editor_target_name = "game-editor-runtime";

template_core_includes_name = "GAME_CORE_RUNTIME_INCLUDES"
template_editor_includes_name = "GAME_EDITOR_INCLUDES"

def main():
    print("Hello World!")
    name = sys.argv[1]

    core_runtime_dst = name.lower() + "-core-runtime"
    editor_runtime_dst = name.lower() + "-editor-runtime"

    copy_tree("templates/game-core-runtime", core_runtime_dst)
    copy_tree("templates/game-editor-runtime", editor_runtime_dst)

    os.rename(core_runtime_dst + "/include/Game.h", core_runtime_dst + "/include/" + name + ".h")
    os.rename(core_runtime_dst + "/src/Game.cpp", core_runtime_dst + "/src/" + name + ".cpp")

    os.rename(editor_runtime_dst + "/include/GameEditor.h", editor_runtime_dst + "/include/" + name + "Editor.h")
    os.rename(editor_runtime_dst + "/src/GameEditor.cpp", editor_runtime_dst + "/src/" + name + "Editor.cpp")

if __name__ == "__main__":
    main()