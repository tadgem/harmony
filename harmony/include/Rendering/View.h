#pragma once
#include "Core/Memory.h"
#include "entt.hpp"
#include "glm/glm.hpp"
#include "bgfx/bgfx.h"
namespace harmony
{
    class View
    {
    public:

        enum class Type
        {
            Orthographic,
            Perspective
        };

        View(const std::string& name);

        virtual void OnPreUpdate(entt::registry& registry);
        virtual void OnPostUpdate(entt::registry& registry);
#if HARMONY_DEBUG
        virtual void OnImGui();
        virtual void OnImGuiOptions();
#endif

        uint32_t m_Width;
        uint32_t m_Height;
        glm::mat4 m_View;
        glm::mat4 m_Projection;

        const std::string m_Name;
    protected:

        friend class ViewManager;
        friend class Renderer;

        const uint32_t c_InitialViewWidth;
        const uint32_t c_InitialViewHeight;

        
    };
};