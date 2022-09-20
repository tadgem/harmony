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

        // N.B call after stack has run pre/post update
        bgfx::TextureHandle GetStackFinalImage();
        
        void Init(entt::registry& registry);
        void PreUpdate(entt::registry& registry);
        void PostUpdate(entt::registry& registry);
        void Cleanup(entt::registry& registry);


        nlohmann::json  Serialize();
        void            Deserialize(nlohmann::json& json);

    protected:
        Ref<View>                   p_View;
        Ref<ShaderProgram>          p_PresentProgram;
        std::vector<Ref<Pipeline>>  m_Stack;
        bool                        p_Initialized;

        bgfx::FrameBufferHandle     p_FinalFramebufferHandle;
        bgfx::ViewId                p_FinalImageViewId;
        bgfx::UniformHandle         p_TexHandle;
        
    };
}