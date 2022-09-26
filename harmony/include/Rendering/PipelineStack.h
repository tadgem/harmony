#pragma once
#include <map>
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

        // N.B call after stack has run pre/post update
        bgfx::TextureHandle GetStackFinalImage();
        
        void Init(entt::registry& registry, WeakRef<View> view);
        void PreUpdate(entt::registry& registry, WeakRef<View> view);
        void PostUpdate(entt::registry& registry, WeakRef<View> view);
        void Cleanup(entt::registry& registry, WeakRef<View> view);


        nlohmann::json  Serialize();
        void            Deserialize(nlohmann::json& json);

    protected:
        std::map<PipelineHandle, std::vector<bgfx::ViewId>>  m_Stack;
        bool                        p_Initialized;

        bgfx::FrameBufferHandle     p_FinalFramebufferHandle;
        bgfx::ViewId                p_FinalImageViewId;
        
    };
}