#pragma once

#include "ECS/System.h"
#include "Assets/AssetManager.h"

namespace harmony {
    struct MeshComponent;

    class MeshSystem : public System {
    public:
        MeshSystem(AssetManager &am);

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
        AssetManager &p_AssetManager;

        void UpdateMeshComponent(MeshComponent &mc);
    };
};