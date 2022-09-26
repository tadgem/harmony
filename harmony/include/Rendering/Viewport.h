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

        Ref<View> m_ViewData;
        PipelineStack m_Stack;

    };
}