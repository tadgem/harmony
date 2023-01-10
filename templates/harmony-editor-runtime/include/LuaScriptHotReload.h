#pragma once
#include "Core/ProgramComponent.h"
#include "Assets/Asset.h"
#include "bx/platform.h"
#include "efsw/efsw.hpp"
namespace harmony
{
    class Program;
    class LuaScriptAsset;
    class LuaProgramComponent;
    class LuaScriptHotReload : public ProgramComponent, public efsw::FileWatchListener
    {
    public:
        LuaScriptHotReload(Program& prog, Ref<LuaProgramComponent> luaPc);
        ~LuaScriptHotReload();
        virtual void Init() override;
        virtual void Update() override;
        virtual void Render() override;
        virtual void Cleanup() override;
        virtual nlohmann::json ToJson() override;
        virtual void FromJson(const nlohmann::json& json) override;

    protected:
        void OnChange(const std::string& filename, const std::string& directory, efsw::Action action);
        void handleFileAction(efsw::WatchID watchid, const std::string& dir, const std::string& filename, efsw::Action action, std::string oldFilename) override;
        Program& p_Program;
        Ref<LuaProgramComponent> p_LuaComponent;

        efsw::FileWatcher* p_FileWatcher;
        efsw::WatchID p_DirectoryWatchID;

        std::map<std::string, Ref<LuaScriptAsset>> p_LoadedScriptSources;

    };
}