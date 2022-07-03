#pragma once
#include "Core/Memory.h"
#include "Core/Scene.h"
#include "Core/Program.h"
#include "entt.hpp"

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

    class ComponentUI
    {
    public:
        virtual void OnComponentImGui(entt::registry& registry, entt::entity entity) = 0;
    };

    class TransformComponentUI : public ComponentUI
    {
    public:
        TransformComponentUI();
        virtual void OnComponentImGui(entt::registry& registry, entt::entity entity) override;
    };

    class EntityInspectorPanel : public Panel
    {
    public:

        EntityInspectorPanel(Program& prog);

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

        entt::entity m_SelectedEntity;
    protected:
        Program& p_Prog;
        std::vector<Ref<ComponentUI>> p_ComponentUIProviders;
    };
}