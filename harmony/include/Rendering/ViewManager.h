#pragma once
#include "Core/Memory.h"
#include "Rendering/View.h"

namespace harmony
{
    class ViewManager
    {
    public:
        ViewManager();

        WeakRef<View>       AddView();
        void                RemoveView(WeakRef<View> view);
        void                SetViewActive(WeakRef<View> viewWeakRef, bool active);

        std::vector<WeakRef<View>> m_ActiveViews;

        bgfx::ViewId GetViewID();
    protected:
        uint32_t p_HandleCounter;
        std::vector<Ref<View>> p_Views;
    };
};