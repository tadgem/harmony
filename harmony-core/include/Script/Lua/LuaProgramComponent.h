#pragma once

#include "Core/ProgramComponent.h"
#include "Core/Alias.h"
#include "Assets/Asset.h"
#include "sol.hpp"

namespace harmony {
    class AssetManager;

    class LuaScriptAsset;
    class LuaComponent;

    class LuaProgramComponent : public ProgramComponent {
    public:
        LuaProgramComponent(AssetManager &am);

        virtual void Init() override;

        virtual void Update() override;

        virtual void Render() override;

        virtual void Cleanup() override;

        virtual Json ToJson() override;

        virtual void FromJson(const Json &json) override;

        Vector<AssetHandle> m_LuaProgramScripts;
    protected:
        AssetManager &p_AssetManager;
        sol::state p_State;
        Vector<LuaComponent> p_LuaProgramScripts;

        void RedirectPrintOutput();

        friend class LuaSystem;
    };
}