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

        void AddPipeline(WeakRef<Pipeline> pipeline);
        void RemovePipeline(WeakRef<Pipeline> pipeline);
        void MoveUp(const PipelineHandle& pipelineHandle);
        void MoveDown(const PipelineHandle& pipelineHandle);

        nlohmann::json  Serialize();
        void            Deserialize(nlohmann::json& json);

        std::vector<WeakRef<Pipeline>> m_Stack;

    protected:
        void InitializePipelineViewIDs(Ref<Pipeline> pipeline);
        void SortStack();
        void MovePipeline(const PipelineHandle& pipelineHandle, bool moveUp);
        bool                        p_Initialized;

        std::map<PipelineHandle, std::vector<bgfx::ViewId>> p_StackViewIDs;

        bgfx::FrameBufferHandle     p_FinalFramebufferHandle;
        bgfx::ViewId                p_FinalImageViewId;
        
    };
}