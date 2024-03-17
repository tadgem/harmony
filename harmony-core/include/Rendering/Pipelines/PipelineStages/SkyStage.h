//
// Created by liam_ on 6/24/2023.
//

#ifndef HARMONY_DOJO_SKYSTAGE_H
#define HARMONY_DOJO_SKYSTAGE_H

#include "Rendering/Pipelines/PipelineStage.h"

namespace harmony {
    class ShaderProgram;

    class SkyDataSource;

    class SkyStage : public PipelineStage {
    public:
        SkyStage(WeakPtr<ShaderProgram> shaderProgram);

        void PreUpdate(entt::registry &registry, WeakPtr<View> view,
                       bgfx::ViewId viewId) override;

        void PostUpdate(entt::registry &registry, WeakPtr<View> view,
                        bgfx::ViewId viewId) override;

        void Cleanup(WeakPtr<View> view, bgfx::ViewId viewId) override;

        void AddShaderDataSource(WeakPtr<ShaderDataSource> source) override;

        Json Serialize() override;

        void Deserialize(Json json) override;

    protected:
        RefCntPtr<SkyDataSource> p_Src;
    };
} // namespace harmony

#endif // HARMONY_DOJO_SKYSTAGE_H
