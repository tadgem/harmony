#pragma once

#include "Core/Memory.h"
#include "ECS/System.h"
#include "sol.hpp"

namespace harmony {
    class AssetManager;

    class LuaProgramComponent;

    class LuaComponent;

    class Scene;

    class LuaSystem : public System {
    public:
        LuaSystem(AssetManager &am, RefCntPtr<LuaProgramComponent> luaPc);

        virtual void Init(entt::registry &registry) override;

        virtual void Update(entt::registry &registry) override;

        virtual void Render(entt::registry &registry) override;

        virtual void Cleanup(entt::registry &registry) override;

        virtual Json SerializeSystem(entt::registry &registry) override;

        virtual void DeserializeSystem(entt::registry &registry,
                                       Json systemJson) override;

        virtual Json SerializeEntity(entt::registry& registry, entt::entity e) override;

        virtual void DeserializeEntity(entt::registry& registry, entt::entity e, Json entityJson) override;

        virtual void Refresh() override;

        entt::entity GetCurrentEntity();

        void UpdateScripts(WeakPtr<Scene> scene);

        void InitEntityScript(entt::entity e, entt::registry &r, sol::state &state,
                              LuaComponent &lua);

    protected:
        RefCntPtr<LuaProgramComponent> p_LuaProgramComponent;
        AssetManager &p_AssetManager;
        entt::entity p_CurrentEntity;
    };
} // namespace harmony