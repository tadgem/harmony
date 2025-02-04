#pragma once

#include "Core/Memory.h"
#include "STL/Json.hpp"
#include "ThirdParty/entt.hpp"
#include "Core/TypeDef.h"
#include "bgfx/bgfx.h"
#include "glm/glm.hpp"

namespace harmony {
    inline static const uint32_t g_InitialWidth = 1024;

    inline static const uint32_t g_InitialHeight = 600;

    inline static const float g_DefaultFOV = 75.0f;

    enum class ProjectionType {
        Orthographic,
        Perspective
    };

    NLOHMANN_JSON_SERIALIZE_ENUM(ProjectionType,
                                 {
                                     { ProjectionType::Orthographic, "Orthographic" },
                                     { ProjectionType::Perspective, "Perspective" },
                                 })

    class View {
    public:
        View(const String &name);

        virtual void OnPreUpdate(entt::registry &registry);

        virtual void OnPostUpdate(entt::registry &registry);

        virtual void OnResized(uint32_t w, uint32_t h);

        virtual Json Serialize();

        virtual void Deserialize(Json &json);

#if HARMONY_DEBUG

        virtual void OnImGui();

        virtual void OnImGuiOptions();

        uint32_t m_ImGuiWindowWidth;
        uint32_t m_ImGuiWindowHeight;
#endif

        bool operator==(const View &other);

        bool operator!=(const View &other);

        bool operator<(const View &other);

        String m_Name;
        uint32_t m_Width;
        uint32_t m_Height;
        glm::mat4 m_View;
        glm::mat4 m_Projection;
        float m_FOV;
        ProjectionType m_ProjectionType;

    protected:
        friend class Renderer;

        bool p_Resized;
    };
}; // namespace harmony