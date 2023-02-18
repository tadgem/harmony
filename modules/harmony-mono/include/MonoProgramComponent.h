#pragma once
#include "Core/ProgramComponent.h"
#include "ECS/System.h"
namespace harmony
{
    class MonoProgramComponent : public ProgramComponent
    {
    public:
        MonoProgramComponent();
        // Inherited via ProgramComponent
        virtual void Init() override;
        virtual void Update() override;
        virtual void Render() override;
        virtual void Cleanup() override;
        virtual nlohmann::json ToJson() override;
        virtual void FromJson(const nlohmann::json& json) override;
    };

    class MonoSystem : public System
    {
    public:
        MonoSystem();
        // Inherited via System
        virtual void Init(entt::registry& registry) override;
        virtual void Update(entt::registry& registry) override;
        virtual void Render(entt::registry& registry) override;
        virtual void Cleanup(entt::registry& registry) override;
        virtual nlohmann::json SerializeSystem(entt::registry& registry) override;
        virtual void DeserializeSystem(entt::registry& registry, nlohmann::json systemJson) override;
        virtual void Refresh() override;
    };
}