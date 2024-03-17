#pragma once

#include "ECS/System.h"

namespace harmony {
    class LightSystem : public System {
    public:
        LightSystem();

        virtual void Init(entt::registry &registry) override;

        virtual void Update(entt::registry &registry) override;

        virtual void Render(entt::registry &registry) override;

        virtual void Cleanup(entt::registry &registry) override;

        virtual nlohmann::json SerializeSystem(entt::registry &registry) override;

        virtual void DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) override;

        virtual nlohmann::json SerializeEntity(entt::registry& registry, entt::entity e) override;

        virtual void DeserializeEntity(entt::registry& registry, entt::entity e, nlohmann::json entityJson) override;

        virtual void Refresh() override;

    protected:
        const String p_DirectionalLightKey = "DirectionalLight";
        const String p_PointLightKey = "PointLight";
        const String p_SpotLightKey = "Spotlight";
        const String p_SkyKey = "Sky";
    };
}