#pragma once

#include "Core/Memory.h"
#include "Core/Scene.h"
#include "Core/Program.h"
#include "ThirdParty/entt.hpp"
#include "STL/TypeTraits.h"

namespace harmony {

    struct EntityData;

    class Panel {
    public:
        virtual void OnImGui() = 0;
    };

    class ScenePanel : public Panel {
    public:

        ScenePanel(Program &program);

        entt::entity m_SelectedEntity;

        virtual void OnImGui() override;

    protected:
        void EntityImGui(entt::entity e, entt::registry &reg, bool topLevel = false);

        void EntityNameRename(entt::entity e, EntityData &data);

        void EntityDragDrop(entt::entity e, entt::registry &reg);

        Program &p_Prog;
        AssetManager& p_AssetManager;
        bool p_RenamingSelectedEntity = false;
        bool p_ImportModelDialog = false;
        Vector<entt::entity> p_FrameHandledEntities;
    };

    class AssetManagerPanel : public Panel {
    public:

        AssetManagerPanel(Program &program);

        virtual void OnImGui() override;

    protected:
        HashString p_SelectedTypeHash;
        AssetManager &p_AssetManager;
        Program &p_Prog;
    };

    class LuaProgramComponent;

    class LuaScriptPanel : public Panel {
    public:
        LuaScriptPanel(Program &prog);

        virtual void OnImGui() override;

    protected:
        WeakPtr<LuaProgramComponent> p_Lua;
        Program &p_Program;
        AssetManager &p_AssetManager;
    };

    class MonoProgramComponent;
    class MonoSystem;
    class MonoPanel : public Panel {
    public:
        MonoPanel(Program &prog);

        virtual void OnImGui() override;

    protected:
        WeakPtr<MonoProgramComponent> p_Mono;
        WeakPtr<MonoSystem> p_System;
        Program &p_Program;
        AssetManager &p_AssetManager;
    };

    class ComponentUI {
    public:

        enum ImGuiParentType {
            TreeNode,
            Custom,
        };

        ComponentUI(const String name, const ImGuiParentType uiType = ImGuiParentType::TreeNode);

        virtual void OnComponentImGui(entt::registry &registry, entt::entity entity) = 0;

        const String &GetComponentName();

        virtual void AddComponent(entt::registry &registry, entt::entity entity) = 0;

        virtual void RemoveComponent(entt::registry &registry, entt::entity entity) = 0;

        virtual bool HasComponent(entt::registry &registry, entt::entity entity) = 0;

        virtual void Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) = 0;

        template<typename T>
        bool RegistryHasComponent(entt::registry &reg, entt::entity e) {
            return reg.any_of<T>(e);
        }

        const ImGuiParentType m_UiType;
    protected:
        const String p_ComponentName;

    };

    class TransformComponentUI : public ComponentUI {
    public:
        TransformComponentUI();

        virtual void OnComponentImGui(entt::registry &registry, entt::entity entity) override;

        virtual void AddComponent(entt::registry &registry, entt::entity entity) override;

        virtual bool HasComponent(entt::registry &registry, entt::entity entity) override;

        virtual void RemoveComponent(entt::registry &registry, entt::entity entity) override;

        virtual void Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) override;
    };

    class DirectionalLightComponentUI : public ComponentUI {
    public:
        DirectionalLightComponentUI();

        virtual void OnComponentImGui(entt::registry &registry, entt::entity entity) override;

        virtual void AddComponent(entt::registry &registry, entt::entity entity) override;

        virtual void RemoveComponent(entt::registry &registry, entt::entity entity) override;

        virtual bool HasComponent(entt::registry &registry, entt::entity entity) override;

        virtual void Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) override;
    };

    class PointLightComponentUI : public ComponentUI {
    public:
        PointLightComponentUI();

        virtual void OnComponentImGui(entt::registry &registry, entt::entity entity) override;

        virtual void AddComponent(entt::registry &registry, entt::entity entity) override;

        virtual void RemoveComponent(entt::registry &registry, entt::entity entity) override;

        virtual bool HasComponent(entt::registry &registry, entt::entity entity) override;

        virtual void Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) override;
    };

    class SpotLightComponentUI : public ComponentUI {
    public:
        SpotLightComponentUI();

        virtual void OnComponentImGui(entt::registry &registry, entt::entity entity) override;

        virtual void AddComponent(entt::registry &registry, entt::entity entity) override;

        virtual void RemoveComponent(entt::registry &registry, entt::entity entity) override;

        virtual bool HasComponent(entt::registry &registry, entt::entity entity) override;

        virtual void Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) override;
    };

    class SkyComponentUI : public ComponentUI {
    public:
        SkyComponentUI();

        void OnComponentImGui(entt::registry &registry, entt::entity entity) override;

        void AddComponent(entt::registry &registry, entt::entity entity) override;

        void RemoveComponent(entt::registry &registry, entt::entity entity) override;

        bool HasComponent(entt::registry &registry, entt::entity entity) override;

        void Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) override;
    };

    class MeshComponentUI : public ComponentUI {
    public:
        MeshComponentUI(AssetManager &am);

        virtual void OnComponentImGui(entt::registry &registry, entt::entity entity) override;

        virtual void AddComponent(entt::registry &registry, entt::entity entity) override;

        virtual void RemoveComponent(entt::registry &registry, entt::entity entity) override;

        virtual bool HasComponent(entt::registry &registry, entt::entity entity) override;

        virtual void Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) override;

    protected:
        AssetManager &p_AssetManager;
    };

    class MaterialComponentUI : public ComponentUI {
    public:
        MaterialComponentUI(Renderer &r, AssetManager &am);

        virtual void OnComponentImGui(entt::registry &registry, entt::entity entity) override;

        virtual void AddComponent(entt::registry &registry, entt::entity entity) override;

        virtual void RemoveComponent(entt::registry &registry, entt::entity entity) override;

        virtual bool HasComponent(entt::registry &registry, entt::entity entity) override;

        virtual void Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) override;

    protected:
        Renderer &p_Renderer;
        AssetManager &p_AssetManager;
    };

    class CameraComponentUI : public ComponentUI {
    public:
        CameraComponentUI(Renderer &r);

        virtual void OnComponentImGui(entt::registry &registry, entt::entity entity) override;

        virtual void AddComponent(entt::registry &registry, entt::entity entity) override;

        virtual void RemoveComponent(entt::registry &registry, entt::entity entity) override;

        virtual bool HasComponent(entt::registry &registry, entt::entity entity) override;

        virtual void Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) override;

    protected:
        Renderer &p_Renderer;
    };

    class LuaScriptComponentUI : public ComponentUI {
    public:
        LuaScriptComponentUI(AssetManager &am);

        virtual void OnComponentImGui(entt::registry &registry, entt::entity entity) override;

        virtual void AddComponent(entt::registry &registry, entt::entity entity) override;

        virtual void RemoveComponent(entt::registry &registry, entt::entity entity) override;

        virtual bool HasComponent(entt::registry &registry, entt::entity entity) override;

        virtual void Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) override;

    protected:
        AssetManager &p_AssetManager;
    };

    class MonoSystem;
    class MonoBehaviourComponentUI : public ComponentUI {
    public:
        MonoBehaviourComponentUI(WeakPtr<MonoSystem> monoSystem, AssetManager &am);

        virtual void OnComponentImGui(entt::registry &registry, entt::entity entity) override;

        virtual void AddComponent(entt::registry &registry, entt::entity entity) override;

        virtual void RemoveComponent(entt::registry &registry, entt::entity entity) override;

        virtual bool HasComponent(entt::registry &registry, entt::entity entity) override;

        virtual void Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) override;

    protected:
        AssetManager &p_AssetManager;
        WeakPtr<MonoSystem> p_MonoSystem;
    };

    class AABBComponentUI : public ComponentUI {
    public:
        AABBComponentUI(AssetManager &am);

        virtual void OnComponentImGui(entt::registry &registry, entt::entity entity) override;

        virtual void AddComponent(entt::registry &registry, entt::entity entity) override;

        virtual void RemoveComponent(entt::registry &registry, entt::entity entity) override;

        virtual bool HasComponent(entt::registry &registry, entt::entity entity) override;

        virtual void Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) override;

    protected:
        AssetManager &p_AssetManager;
    };

    class SphereComponentUI : public ComponentUI {
    public:
        SphereComponentUI();

        virtual void OnComponentImGui(entt::registry &registry, entt::entity entity) override;

        virtual void AddComponent(entt::registry &registry, entt::entity entity) override;

        virtual void RemoveComponent(entt::registry &registry, entt::entity entity) override;

        virtual bool HasComponent(entt::registry &registry, entt::entity entity) override;

        virtual void Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) override;

    };

    class JoltBodyComponentUI : public ComponentUI {
    public:
        JoltBodyComponentUI();

        virtual void OnComponentImGui(entt::registry &registry, entt::entity entity) override;

        virtual void AddComponent(entt::registry &registry, entt::entity entity) override;

        virtual void RemoveComponent(entt::registry &registry, entt::entity entity) override;

        virtual bool HasComponent(entt::registry &registry, entt::entity entity) override;

        virtual void Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) override;

    };

    class EntityDataComponentUI : public ComponentUI {
    public:
        EntityDataComponentUI();

        void OnComponentImGui(entt::registry &registry, entt::entity entity) override;

        void AddComponent(entt::registry &registry, entt::entity entity) override;

        void RemoveComponent(entt::registry &registry, entt::entity entity) override;

        bool HasComponent(entt::registry &registry, entt::entity entity) override;

        void Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) override;

    public:

    };

    class EntityInspectorPanel : public Panel {
    public:
        EntityInspectorPanel(Program &prog, RefCntPtr<ScenePanel> scenePanel);

        template<typename T, typename ... Args>
        WeakPtr<T> AddComponentUI(Args &&... args) {
            static_assert(IsBaseOf<ComponentUI, T>());
            RefCntPtr<T> ui = CreateRef<T>(Forward<Args>(args)...);
            p_ComponentUIProviders.emplace_back(ui);
            return GetWeakRef<T>(ui);
        }

        virtual void OnImGui() override;

    protected:
        Program &p_Prog;
        RefCntPtr<ScenePanel> p_ScenePanel;
        Vector<RefCntPtr<ComponentUI>> p_ComponentUIProviders;
    };
}