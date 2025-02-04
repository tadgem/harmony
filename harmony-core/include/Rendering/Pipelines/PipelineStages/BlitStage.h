//
// Created by liam_ on 6/4/2023.
//

#ifndef HARMONY_DOJO_BLITSTAGE_H
#define HARMONY_DOJO_BLITSTAGE_H

#include "Rendering/Pipelines/PipelineStage.h"

namespace harmony {
    class BlitStage : public PipelineStage {
    public:
        void PreUpdate(entt::registry &registry, WeakPtr<View> view,
                       bgfx::ViewId viewId) override;

        void PostUpdate(entt::registry &registry, WeakPtr<View> view,
                        bgfx::ViewId viewId) override;

    public:
    };
} // namespace harmony
#endif // HARMONY_DOJO_BLITSTAGE_H
