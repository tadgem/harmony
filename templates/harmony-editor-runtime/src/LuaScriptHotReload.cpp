#include "LuaScriptHotReload.h"
#include "Script/Lua/LuaProgramComponent.h"
#include "Core/Memory.h"
#include "Core/Program.h"
#include "Script/Lua/LuaScriptAsset.h"
#include "Script/Lua/LuaSystem.h"


harmony::LuaScriptHotReload::LuaScriptHotReload(Program &prog, Ref<LuaSystem> luaSystem) : AssetHotReloadProvider(
        "LuaScript"), p_Program(prog), p_LuaSystem(luaSystem) {
}

harmony::LuaScriptHotReload::~LuaScriptHotReload() {

}

void harmony::LuaScriptHotReload::Init() {
    auto sourceHandles = p_Program.m_AssetManager.GetLoadedAssets<LuaScriptAsset>();
    for (auto handle: sourceHandles) {
        p_LoadedScriptSources.emplace(handle.Path, p_Program.m_AssetManager.GetAsset<LuaScriptAsset>(handle).lock());
    }
    ReloadLuaScripts();
}

void harmony::LuaScriptHotReload::ReloadLuaScripts() {
    auto scriptHandles = p_Program.m_AssetManager.GetLoadedAssets<LuaScriptAsset>();

    p_LoadedScriptSources.clear();
    for (auto handle: scriptHandles) {
        p_LoadedScriptSources.emplace(handle.Path, p_Program.m_AssetManager.GetAsset<LuaScriptAsset>(handle).lock());
        p_LoadedScriptSources[handle.Path]->m_Handle = handle;
    }
}


void
harmony::LuaScriptHotReload::OnChange(const std::string &filename, const std::string &directory, efsw::Action action) {
    //harmony::log::info("LuaScriptHotReload : Path : {}, Change Type : TODO", filename);

    if (action == efsw::Actions::Add) {
        if (filename.find(".lua") < filename.size()) {
        }
        // add lua script
    }
    if (action == efsw::Actions::Modified) {
        if (filename.find(".lua") < filename.size()) {
            if (!p_Program.m_Project) {
                return;
            }

            std::string cleanPath = GetCleanFileName(filename, directory);
            // Update shader text...
            std::string newText = Utils::LoadStringFromPath(directory + std::string("/") + filename);

            if (p_LoadedScriptSources.find(cleanPath) == p_LoadedScriptSources.end()) {
                harmony::log::warn("LuaScriptHotRelaod : script not being tracked by hot reload. {}", filename);
                return;
            }

            AssetHandle &h = p_LoadedScriptSources[cleanPath]->m_Handle;
            auto luaWr = p_Program.m_AssetManager.GetAsset<LuaScriptAsset>(h);
            if (luaWr.expired()) {
                harmony::log::warn("LuaScriptHotReload : could not find script in asset registry : {}", cleanPath);
                return;
            }

            luaWr.lock()->m_Script = newText;

            p_LuaSystem->UpdateScripts(p_Program.GetActiveScene());
        }
    }
}

std::string harmony::LuaScriptHotReload::GetCleanFileName(const std::string &filename, const std::string &directory) {
    std::string projDirectory = p_Program.m_Project->m_ProjectDirectory;
    std::string fullFileDirectory = directory;

    if (projDirectory.find("\\") < projDirectory.size()) {
        fullFileDirectory += "\\" + filename;
    } else {
        fullFileDirectory += "/" + filename;
    }

    auto str =  fullFileDirectory.substr(fullFileDirectory.find(projDirectory) + projDirectory.size() + 1,
                                    fullFileDirectory.size());

    auto found = str.find("\\\\");

    if(found)
    {
        str.replace(found, 2, "\\");
    }

    return str;
}
