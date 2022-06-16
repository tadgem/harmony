#pragma once
#include "Core/Memory.h"
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

        View();

        uint32_t m_Width;
        uint32_t m_Height;
        glm::mat4 m_View;
        glm::mat4 m_Projection;

    protected:

        friend class ViewManager;
        friend class Renderer;

        const uint32_t c_InitialViewWidth;
        const uint32_t c_InitialViewHeight;

        
    };
};