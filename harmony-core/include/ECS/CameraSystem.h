#pragma once
#include "ECS/System.h"
#include "Rendering/Camera.h"
namespace harmony
{
    class CameraSystem : public System
    {
        public:
        CameraSystem();
        virtual void Init(entt::registry& registry) override;
        virtual void Update(entt::registry& registry) override;
        virtual void Render(entt::registry& registry) override;
        virtual void Cleanup(entt::registry& registry) override;
        virtual nlohmann::json SerializeSystem(entt::registry& registry) override;
        virtual void DeserializeSystem(entt::registry& registry, nlohmann::json systemJson) override;

    protected:
        Ref<Camera> p_MainCamera;

        // Inherited via System
        virtual void Refresh() override;
    };
};