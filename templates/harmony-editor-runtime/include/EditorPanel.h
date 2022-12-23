#pragma once
#include "Core/Memory.h"
#include "Core/Scene.h"
#include "Core/Program.h"
#include "ThirdParty/entt.hpp"

namespace harmony
{
    class Panel
    {
    public:
        virtual void OnImGui() = 0;
    };

    class ScenePanel : public Panel
    {
    public:

        ScenePanel(Program& program);
        entt::entity m_SelectedEntity;
        virtual void OnImGui() override;
    protected:
        Program& p_Prog;
    };

    class AssetManagerPanel : public Panel
    {
    public:

        AssetManagerPanel(Program& program);
        virtual void OnImGui() override;

    protected:
        std::string p_SelectedTypeHash;
        AssetManager& p_AssetManager;
        Program& p_Prog;
    };

    class ComponentUI
    {
    public:
        ComponentUI(const std::string name);
        virtual void OnComponentImGui(entt::registry& registry, entt::entity entity) = 0;
        const std::string& GetComponentName();
        virtual void AddComponent(entt::registry& registry, entt::entity entity) = 0;
        virtual bool HasComponent(entt::registry& registry, entt::entity entity) = 0;

        template<typename T>
        bool RegistryHasComponent(entt::registry& reg, entt::entity e)
        {
            return reg.any_of<T>(e);
        }

    protected:
        const std::string p_ComponentName;

    };

    class TransformComponentUI : public ComponentUI
    {
    public:
        TransformComponentUI();
        virtual void OnComponentImGui(entt::registry& registry, entt::entity entity) override;
        virtual void AddComponent(entt::registry& registry, entt::entity entity) override;
        virtual bool HasComponent(entt::registry& registry, entt::entity entity) override;

    };

    class MeshComponentUI : public ComponentUI
    {
    public:
        MeshComponentUI(AssetManager& am);
        virtual void OnComponentImGui(entt::registry& registry, entt::entity entity) override;
        virtual void AddComponent(entt::registry& registry, entt::entity entity) override;
        virtual bool HasComponent(entt::registry& registry, entt::entity entity) override;

    protected:
        AssetManager& p_AssetManager;
    };

    class MaterialComponentUI : public ComponentUI
    {
    public:
        MaterialComponentUI(Renderer& r, AssetManager& am);
        virtual void OnComponentImGui(entt::registry& registry, entt::entity entity) override;
        virtual void AddComponent(entt::registry& registry, entt::entity entity) override;
        virtual bool HasComponent(entt::registry& registry, entt::entity entity) override;

    protected:
        Renderer& p_Renderer;
        AssetManager& p_AssetManager;
    };

    class CameraComponentUI : public ComponentUI
    {
    public:
        CameraComponentUI(Renderer& r);
        virtual void OnComponentImGui(entt::registry& registry, entt::entity entity) override;
        virtual void AddComponent(entt::registry& registry, entt::entity entity) override;
        virtual bool HasComponent(entt::registry& registry, entt::entity entity) override;

    protected:
        Renderer& p_Renderer;
    };


    class EntityInspectorPanel : public Panel
    {
    public:
        EntityInspectorPanel(Program& prog, Ref<ScenePanel> scenePanel);

        template<typename T, typename ... Args>
        WeakRef<T> AddComponentUI(Args&& ... args)
        {
            HARMONY_PROFILE_FUNCTION()
            static_assert(std::is_base_of<ComponentUI, T>());
            Ref<T> ui = CreateRef<T>(std::forward<Args>(args)...);
            p_ComponentUIProviders.emplace_back(ui);
            return GetWeakRef<T>(ui);
        }
        virtual void OnImGui() override;

    protected:
        Program& p_Prog;
        Ref<ScenePanel> p_ScenePanel;
        std::vector<Ref<ComponentUI>> p_ComponentUIProviders;
    };
}