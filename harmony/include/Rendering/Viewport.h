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

        void OnResized(uint32_t w, uint32_t h);

        Ref<View> m_ViewData;
        PipelineStack m_Stack;
    protected:
        void RefreshPipelineViews();
    };
}