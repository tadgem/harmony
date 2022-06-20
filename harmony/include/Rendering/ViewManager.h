#pragma once
#include "Core/Memory.h"
#include "Rendering/Pipeline.h"

namespace harmony
{
    class Renderer;

    class ViewManager
    {
    public:
        ViewManager(Renderer& renderer);

        WeakRef<View>       AddView(const std::string& name);
        void                RemoveView(WeakRef<View> view);
        void                SetViewActive(WeakRef<View> viewWeakRef, bool active);

        void                AddViewPipelineAssociation(WeakRef<View> viewWeakRef, WeakRef<Pipeline> pipelineHandle);

#if HARMONY_DEBUG
   private:
        void                OnImGui();
        PipelineHandle      p_SelectedPipelineHandle;
#endif
    public:
        std::vector<WeakRef<View>> m_ActiveViews;

        static bgfx::ViewId GetViewID();
    protected:
        friend class Renderer;
        static uint32_t p_HandleCounter;
        std::map<Ref<View>, std::vector<WeakRef<Pipeline>>> p_Views;
        Renderer& p_Renderer;
    };
};