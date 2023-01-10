#include "LuaScriptHotReload.h"
#include "LuaProgramComponent.h"
#include "Core/Memory.h"
#include "Core/Program.h"

harmony::LuaScriptHotReload::LuaScriptHotReload(Program& prog, Ref<LuaProgramComponent> luaPc) : p_Program(prog)
{
    p_FileWatcher = nullptr;
}

harmony::LuaScriptHotReload::~LuaScriptHotReload()
{
    if (p_FileWatcher)
    {
        delete p_FileWatcher;
    }
}

void harmony::LuaScriptHotReload::Init()
{
    if (p_Program.m_Project)
    {
        std::string projDirectory = p_Program.m_Project->m_ProjectDirectory;
        std::string shadersDirectory = projDirectory + "\\assets\\scripts";

        efsw::FileWatchListener* listener = this;

        // TODO : Need to restructure so only 1 watcher and handlers for various asset types.
        /*p_DirectoryWatchID = p_FileWatcher->addWatch(shadersDirectory, listener, true);
        p_FileWatcher->watch();*/
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

void harmony::LuaScriptHotReload::OnChange(const std::string& filename, const std::string& directory, efsw::Action action)
{
    harmony::log::info("LuaScriptHotReload : Path : {}, Change Type : TODO", filename);
}

void harmony::LuaScriptHotReload::handleFileAction(efsw::WatchID watchid, const std::string& dir, const std::string& filename, efsw::Action action, std::string oldFilename)
{
    OnChange(filename, dir, action);
}
