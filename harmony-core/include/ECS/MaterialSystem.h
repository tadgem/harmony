#pragma once

#include "ECS/System.h"
#include "Rendering/Renderer.h"
#include "Assets/AssetManager.h"

namespace harmony {
    class MaterialSystem : public System {
    public:
        MaterialSystem(Renderer &renderer, AssetManager &assetManager);

        virtual void Init(entt::registry &registry) override;

        virtual void Update(entt::registry &registry) override;

        virtual void Render(entt::registry &registry) override;

        virtual void Cleanup(entt::registry &registry) override;

        virtual Json SerializeSystem(entt::registry &registry) override;

        virtual void DeserializeSystem(entt::registry &registry, Json systemJson) override;

        virtual Json SerializeEntity(entt::registry& registry, entt::entity e) override;

        virtual void DeserializeEntity(entt::registry& registry, entt::entity e, Json entityJson) override;

        virtual void Refresh() override;

    protected:
        Renderer &p_Renderer;
        AssetManager &p_AssetManager;
    };
};