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

        SkyStage(WeakRef<ShaderProgram> shaderProgram);

        void PreUpdate(entt::registry &registry, WeakRef<View> view, bgfx::ViewId viewId) override;

        void PostUpdate(entt::registry &registry, WeakRef<View> view, bgfx::ViewId viewId) override;

        void Cleanup(WeakRef<View> view, bgfx::ViewId viewId) override;

        void AddShaderDataSource(WeakRef<ShaderDataSource> source) override;

        nlohmann::json Serialize() override;

        void Deserialize(nlohmann::json json) override;


    protected:
        Ref<SkyDataSource> p_Src;

    };
}

#endif //HARMONY_DOJO_SKYSTAGE_H
