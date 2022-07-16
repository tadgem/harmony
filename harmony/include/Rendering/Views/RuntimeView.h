#pragma once
#include "Rendering/View.h"

namespace harmony 
{
    class RuntimeView : public View
    {
    public:
        RuntimeView();

        virtual void OnPreUpdate(entt::registry& registry) override;
        virtual void OnPostUpdate(entt::registry& registry) override;
#if HARMONY_DEBUG
        virtual void OnImGui() override;
#endif
    };
}