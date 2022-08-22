#pragma once
#include "Core/Memory.h"
#include "entt.hpp"
#include "glm/glm.hpp"
#include "json.hpp"
#include "bgfx/bgfx.h"
namespace harmony
{
    inline static const uint32_t g_InitialWidth = 1024;
    inline static const uint32_t g_InitialHeight = 600;
    class View
    {
    public:

        enum class Type
        {
            Orthographic,
            Perspective
        };

        NLOHMANN_JSON_SERIALIZE_ENUM(Type, {
            {Orthographic, "orthographic"},
            {Perspective, "perspective"},
            })

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

        std::string m_Name;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(View, m_Name, m_Width, m_Height)

    protected:

        friend class Renderer;

        const uint32_t c_InitialViewWidth;
        const uint32_t c_InitialViewHeight;

        
    };
};