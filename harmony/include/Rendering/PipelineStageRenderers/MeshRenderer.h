#pragma once
#include "Rendering/PipelineStageRenderer.h"
namespace harmony 
{
    class MeshRenderer : public PipelineStageRenderer
    {
        public:

        MeshRenderer();

        virtual void Draw(entt::registry& scene, Ref<ShaderProgram> shader, bgfx::ViewId viewId) override;
    };
}