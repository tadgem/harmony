#include "LuaScriptHotReload.h"
#include "LuaProgramComponent.h"
#include "Core/Memory.h"
#include "Core/Program.h"

harmony::LuaScriptHotReload::LuaScriptHotReload(Program& prog, Ref<LuaProgramComponent> luaPc) : p_Program(prog)
{
}

void harmony::LuaScriptHotReload::Init()
{
    if (p_Program.m_Project)
    {
        std::string projDirectory = p_Program.m_Project->m_ProjectDirectory;
        std::string shadersDirectory = projDirectory + "\\assets\\scripts";

        p_FileWatcher = new filewatch::FileWatch<std::string>(
            shadersDirectory,
            [&](const std::string& path, const filewatch::Event change_type) {
                OnChange(path, change_type);
            }
        );
    }

    auto sourceHandles = p_Program.m_AssetManager.GetLoadedAssets<LuaScriptAsset>();
    for (auto handle : sourceHandles)
    {
        p_LoadedScriptSources.emplace(handle.Path, p_Program.m_AssetManager.GetAsset<LuaScriptAsset>(handle).lock());
    }
}

void harmony::LuaScriptHotReload::Update()
{
}

void harmony::LuaScriptHotReload::Render()
{
}

void harmony::LuaScriptHotReload::Cleanup()
{
}

nlohmann::json harmony::LuaScriptHotReload::ToJson()
{
	return nlohmann::json();
}

void harmony::LuaScriptHotReload::FromJson(const nlohmann::json& json)
{
}

void harmony::LuaScriptHotReload::OnChange(const std::string& path, const filewatch::Event change_type)
{
    harmony::log::info("LuaScriptHotReload : Path : {} Change Type : {}", path);
    if (change_type == filewatch::Event::added)
    {
    }
    if (change_type == filewatch::Event::modified)
    {
    }
}
