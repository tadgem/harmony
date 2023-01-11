#pragma once
#include "AssetHotReload.h"
#include "Assets/Asset.h"
#include "bx/platform.h"
namespace harmony
{
    class Program;
    class LuaScriptAsset;
    class LuaSystem;
    class LuaScriptHotReload : public AssetHotReloadProvider
    {
    public:
        LuaScriptHotReload(Program& prog, Ref<LuaSystem> luaSystem);
        ~LuaScriptHotReload();
        virtual void Init() override;

    protected:
        void ReloadLuaScripts();
        void OnChange(const std::string& filename, const std::string& directory, efsw::Action action);

        std::string GetCleanFileName(const std::string& filename, const std::string& directory);

        Program&                    p_Program;
        Ref<LuaSystem>              p_LuaSystem;

        std::map<std::string, Ref<LuaScriptAsset>> p_LoadedScriptSources;

    };
}