#pragma once
#include <vector>
#include "Rendering/Pipeline.h"
#include "Rendering/View.h"
#include "Rendering/Shader.h"
namespace harmony
{
    class PipelineStack
    {
    public:
        PipelineStack(); 
        PipelineStack(WeakRef<View> view, WeakRef<ShaderProgram> presentShader);
        /// <summary>
        /// Call after all pipelines have been rendered
        /// </summary>
        /// <returns></returns>
        bgfx::TextureHandle GetStackFinalImage();
        
        void Init(entt::registry& registry);
        void PreUpdate(entt::registry& registry);
        void PostUpdate(entt::registry& registry);
        void Cleanup(entt::registry& registry);

        std::vector<Ref<Pipeline>> m_Stack;

    protected:
        Ref<View> p_View;

        bgfx::FrameBufferHandle p_FinalFramebufferHandle;
        bgfx::ViewId p_FinalImageViewId;
        
        Ref<ShaderProgram> p_PresentProgram;
        bgfx::UniformHandle p_TexHandle;
    };
}