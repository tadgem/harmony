#pragma once
#include "Core/Memory.h"
#include "Rendering/Pipeline.h"

namespace harmony
{
    class ViewManager
    {
    public:
        ViewManager();

        WeakRef<View>       AddView(const std::string& name);
        void                RemoveView(WeakRef<View> view);
        void                SetViewActive(WeakRef<View> viewWeakRef, bool active);

        void                AddViewPipelineAssociation(WeakRef<View> viewWeakRef, PipelineHandle pipelineHandle);

        std::vector<WeakRef<View>> m_ActiveViews;

        static bgfx::ViewId GetViewID();
    protected:
        friend class Renderer;
        static uint32_t p_HandleCounter;
        std::map<Ref<View>, std::vector<PipelineHandle>> p_Views;
    };
};