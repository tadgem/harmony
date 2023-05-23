#pragma once

#include "ECS/System.h"
#include "Core/Memory.h"
#include "sol.hpp"


namespace harmony {
    class AssetManager;

    class LuaProgramComponent;

    class LuaComponent;

    class Scene;

    class LuaSystem : public System {
    public:
        LuaSystem(AssetManager &am, Ref<LuaProgramComponent> luaPc);

        virtual void Init(entt::registry &registry) override;

        virtual void Update(entt::registry &registry) override;

        virtual void Render(entt::registry &registry) override;

        virtual void Cleanup(entt::registry &registry) override;

        virtual nlohmann::json SerializeSystem(entt::registry &registry) override;

        virtual void DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) override;

        virtual void Refresh() override;

        entt::entity GetCurrentEntity();

        void UpdateScripts(WeakRef<Scene> scene);

        void InitEntityScript(entt::entity e, entt::registry &r, sol::state &state, LuaComponent &lua);

    protected:
        Ref<LuaProgramComponent> p_LuaProgramComponent;
        AssetManager &p_AssetManager;
        entt::entity p_CurrentEntity;
    };
}