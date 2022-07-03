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

        const size_t m_ComponentTypeHash;
    };

    class EntityInspectorPanel : public Panel
    {
    public:

        EntityInspectorPanel(Program& prog);

        virtual void OnImGui() override;

        entt::entity m_SelectedEntity;
    protected:
        Program& p_Prog;
        std::vector<Ref<ComponentUI>> p_ComponentUIProviders;
    };
}