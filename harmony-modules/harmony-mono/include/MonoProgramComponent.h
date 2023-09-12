#pragma once
#include "Core/ProgramComponent.h"
#include "Core/Memory.h"
#include "ECS/System.h"
#include <mono/metadata/appdomain.h>
#include "MonoAssembly.h"

namespace harmony
{
    class Program;
    class MonoProgramComponent : public ProgramComponent
    {
    public:
        MonoProgramComponent();
        virtual void Init() override;
        virtual void Update() override;
        virtual void Render() override;
        virtual void Cleanup() override;
        virtual nlohmann::json ToJson() override;
        virtual void FromJson(const nlohmann::json& json) override;

        virtual void BindScriptingAPI();

        MonoAssembly* LoadAssembly();

    protected:
        MonoDomain* p_RootDomain;
        MonoDomain* p_AppDomain;
        // TODO: Make this customizable per-application
        const std::string p_RootDomainName = "Harmony";
        const std::string p_AppDomainName = "HarmonyApp";
        const MonoAssemblyConfiguration p_AssemblyConfig;
    };

    class MonoSystem : public System
    {
    public:
        MonoSystem(WeakRef<MonoProgramComponent> mono);
        virtual void Init(entt::registry& registry) override;
        virtual void Update(entt::registry& registry) override;
        virtual void Render(entt::registry& registry) override;
        virtual void Cleanup(entt::registry& registry) override;
        virtual nlohmann::json SerializeSystem(entt::registry& registry) override;
        virtual void DeserializeSystem(entt::registry& registry, nlohmann::json systemJson) override;
        virtual void Refresh() override;

    protected:
        WeakRef<MonoProgramComponent> p_Mono;
    };

    void AddMono(harmony::Program& program);
}