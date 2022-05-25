#pragma once
#include "Core/Memory.h"
#include "glm/glm.hpp"

namespace harmony
{
    struct ViewHandle
    {
        uint32_t m_Index;
    };

    class View
    {
    public:

        View(uint32_t index);

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
        uint32_t p_Index;
        friend class ViewManager;
        
    };
};