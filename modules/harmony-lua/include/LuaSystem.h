#pragma once
#include "ECS/System.h"
#include "Core/Memory.h"

namespace harmony
{
    class LuaProgramComponent;
    class LuaSystem : public System
    {
    public:
        LuaSystem(Ref<LuaProgramComponent> luaPc);

        virtual void Init(entt::registry& registry) override;
        virtual void Update(entt::registry& registry) override;
        virtual void Render(entt::registry& registry) override;
        virtual void Cleanup(entt::registry& registry) override;
        virtual nlohmann::json SerializeSystem(entt::registry& registry) override;
        virtual void DeserializeSystem(entt::registry& registry, nlohmann::json systemJson) override;
        virtual void Refresh() override;

    protected:
        Ref<LuaProgramComponent> p_LuaProgramComponent;
    };
}