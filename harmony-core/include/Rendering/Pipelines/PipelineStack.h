#pragma once

#include <map>
#include <vector>
#include "Pipeline.h"

namespace harmony {
    class View;

    class PostProcessStage;

    class PipelineStack {
    public:

        struct Data {
            uint16_t m_Handle;
            bool m_PostProcess;
        };

        PipelineStack();

        bgfx::TextureHandle GetFinalImage();

        bgfx::TextureHandle GetFinalDepth();

        void AddPipeline(WeakRef<Pipeline> pipeline, WeakRef<View> view);

        void AddPipelineAtIndex(WeakRef<Pipeline> pipeline, WeakRef<View> view, int index);

        void RemovePipeline(WeakRef<Pipeline> pipeline, WeakRef<View> view);

        int GetPipelineIndex(WeakRef<Pipeline> pipeline);

        void MovePipelineUp(const PipelineHandle &pipelineHandle);

        void MovePipelineDown(const PipelineHandle &pipelineHandle);

        void AddPostProcessStage(WeakRef<PostProcessStage> postProcessStage, WeakRef<View> view);

        void AddPostProcessStageAtIndex(WeakRef<PostProcessStage> postProcessStage, WeakRef<View> view, int index);

        void RemovePostProcessStage(WeakRef<PostProcessStage> postProcessStage, WeakRef<View> view);

        int GetPostProcessStageIndex(WeakRef<PostProcessStage> postProcessStage);

        void MovePostProcessStageUp(const std::string &stageName);

        void MovePostProcessStageDown(const std::string &stageName);

        void OnViewResized(WeakRef<View> view);

        void PreUpdate(entt::registry &registry, WeakRef<View> view);

        std::vector<Data> PostUpdate(entt::registry &registry, WeakRef<View> view);

        nlohmann::json Serialize();

        bgfx::FrameBufferHandle m_FinalFramebufferHandle;
        bgfx::FrameBufferHandle m_PipelineStackAccumulationFB;
        bgfx::FrameBufferHandle m_PipelineStackNoPostProcessFB;
        bgfx::ViewId m_FinalImageViewId;
        bgfx::ViewId m_PipelineStackAccumulationView;
        bgfx::ViewId m_PipelineStackNoPostProcessView;
        bgfx::TextureHandle m_FinalFramebufferAttachment;
        bgfx::TextureHandle m_PipelineStackAccumulationAttachment;
        bgfx::TextureHandle m_PipelineStackNoPostProcessAttachment;

        std::vector<WeakRef<Pipeline>> m_PipelineStack;
        std::vector<WeakRef<PostProcessStage>> m_PostProcessPipelineStack;

        inline static const AttachmentType s_AccumulationBufferFormat = AttachmentType::RGBA16F;


    protected:
        friend class Renderer;

        void InitializeStack(WeakRef<View> view);

        void InitializePipeline(Ref<Pipeline> pipeline, WeakRef<View> view);

        void InitializePostProcessStage(Ref<PostProcessStage> stage, WeakRef<View> view);

        void SortPipelineStack();

        void MovePipeline(const PipelineHandle &pipelineHandle, bool moveUp);

        void MovePostProcessStage(const std::string &postProcessStageName, bool moveUp);

        bgfx::TextureHandle GetPipelineInitialDepth(PipelineHandle &handle);

        bgfx::TextureHandle GetPipelineFinalDepth(PipelineHandle &handle);

        std::map<std::string, std::vector<bgfx::ViewId>> p_StackViewIDs;
        std::map<std::string, std::vector<PipelineStage::Data>> p_StackData;

        bool p_Initialized;

    };
}