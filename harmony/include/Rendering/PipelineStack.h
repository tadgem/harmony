#pragma once
#include <map>
#include <vector>
#include "Rendering/Pipeline.h"
namespace harmony
{
    class View;
    class PipelineStack
    {
    public:
        PipelineStack(); 

        bgfx::TextureHandle GetFinalImage();

        void AddPipeline(WeakRef<Pipeline> pipeline, WeakRef<View> view);
        void RemovePipeline(WeakRef<Pipeline> pipeline);
        void MoveUp(const PipelineHandle& pipelineHandle);
        void MoveDown(const PipelineHandle& pipelineHandle);

        void PreUpdate(entt::registry& registry, WeakRef<View> view);
        std::vector<bgfx::TextureHandle> PostUpdate(entt::registry& registry, WeakRef<View> view);

        nlohmann::json  Serialize();
        void            Deserialize(nlohmann::json& json);

        bgfx::FrameBufferHandle         m_FinalFramebufferHandle;
        bgfx::ViewId                    m_FinalImageViewId;

        std::vector<WeakRef<Pipeline>>  m_Stack;
    protected:
        void InitializePipeline(Ref<Pipeline> pipeline, WeakRef<View> view);
        void SortStack();
        void MovePipeline(const PipelineHandle& pipelineHandle, bool moveUp);

        bgfx::TextureHandle GetPipelineInitialDepth(PipelineHandle& handle);
        bgfx::TextureHandle GetPipelineFinalDepth(PipelineHandle& handle);

        std::map<PipelineHandle, std::vector<bgfx::ViewId>>             p_StackViewIDs;
        std::map<PipelineHandle, std::vector<PipelineStage::Data>>      p_StackData;

        bool p_Initialized;        
    };
}