#pragma once
#include <stack>
#include "Rendering/Pipeline.h"
#include "Rendering/View.h"
namespace harmony
{
    class PipelineStack
    {
    public:

        PipelineStack(WeakRef<View> view);


        std::stack<Pipeline> m_Stack;

    protected:
        Ref<View> p_View;
    };
}