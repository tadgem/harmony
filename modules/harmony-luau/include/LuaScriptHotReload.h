#pragma once
#include "Core/ProgramComponent.h"
#include "Assets/Asset.h"
#include "bx/platform.h"
namespace harmony
{
    class Program;
    class LuaScriptAsset;
    class LuaProgramComponent;
    class LuaScriptHotReload : public ProgramComponent
    {
    public:
        LuaScriptHotReload(Program& prog, Ref<LuaProgramComponent> luaPc);
        virtual void Init() override;
        virtual void Update() override;
        virtual void Render() override;
        virtual void Cleanup() override;
        virtual nlohmann::json ToJson() override;
        virtual void FromJson(const nlohmann::json& json) override;

    protected:
        Program& p_Program;
        Ref<LuaProgramComponent> p_LuaComponent;

        std::map<std::string, Ref<LuaScriptAsset>> p_LoadedScriptSources;

    };
}