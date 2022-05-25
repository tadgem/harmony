#pragma once
#include "Core/Memory.h"
#include "Rendering/View.h"

namespace harmony
{
    class ViewManager
    {
    public:
        ViewManager();

        const ViewHandle& AddView();
        WeakRef<View> GetView(const ViewHandle& handle);

    protected:
        std::vector<Ref<View>> p_Views;
    };
};