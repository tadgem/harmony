#pragma once
#include "Rendering/View.h"
#include "Rendering/PipelineStack.h"

namespace harmony
{
    class Viewport
    {
    public:
        Viewport();
        ~Viewport();

        View m_ViewData;
        PipelineStack m_Stack;

    };
}