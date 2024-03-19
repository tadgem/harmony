#pragma once

#include "AssetHotReload.h"
#include "Assets/Asset.h"
#include "bx/platform.h"

namespace harmony {
    class Program;

    class LuaScriptAsset;

    class LuaSystem;

    class LuaScriptHotReload : public AssetHotReloadProvider {
    public:
        LuaScriptHotReload(Program &prog, RefCntPtr<LuaSystem> luaSystem);

        ~LuaScriptHotReload();

        virtual void Init() override;

    protected:
        void ReloadLuaScripts();

        void OnChange(const String &filename, const String &directory, efsw::Action action);

        String GetCleanFileName(const String &filename, const String &directory);

        Program &p_Program;
        RefCntPtr<LuaSystem> p_LuaSystem;

        Map<String, RefCntPtr<LuaScriptAsset>> p_LoadedScriptSources;

    };
}