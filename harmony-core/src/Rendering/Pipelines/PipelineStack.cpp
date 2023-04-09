#include "Core/Log.hpp"
#include "Core/SerializationKeys.h"
#include "Rendering/Pipelines/PipelineStack.h"
#include "Rendering/Shapes.h"
#include "Rendering/Renderer.h"
#include "Rendering/View.h"
#include "Rendering/Pipelines/PostProcessStage.h"

harmony::PipelineStack::PipelineStack()
{
    p_Initialized                       = false;
    m_FinalImageViewId                  = Renderer::GetPresentViewID();
    m_PipelineStackAccumulationView     = Renderer::GetPresentViewID();
    m_PipelineStackNoPostProcessView    = Renderer::GetPresentViewID();
}

bgfx::TextureHandle harmony::PipelineStack::GetFinalImage()
{
    if (!p_Initialized || m_FinalFramebufferHandle.idx >= 65534)
    {
        return bgfx::TextureHandle();
    }
    return bgfx::getTexture(m_FinalFramebufferHandle);
}

bgfx::TextureHandle harmony::PipelineStack::GetFinalDepth()
{
    if (!p_Initialized)
    {
        return bgfx::TextureHandle();
    }

    Ref<Pipeline> pipeline;
    Ref<Pipeline> selectedPipeline;
    for (int p = 0; p < m_PipelineStack.size(); p++)
    {
        pipeline = m_PipelineStack[p].lock();
        if (!pipeline)
        {
            harmony::log::warn("Pipeline {} is expired.", p);
            continue;
        }

        if (pipeline->HasDepth())
        {
            selectedPipeline = pipeline;
            continue;
        }

        break;
    }

    if (!selectedPipeline)
    {
        return bgfx::TextureHandle();
    }

    return GetPipelineFinalDepth(selectedPipeline->m_Handle);

}

void harmony::PipelineStack::PreUpdate(entt::registry& registry, WeakRef<View> view)
{
    HARMONY_PROFILE_FUNCTION()
    for (int p = 0; p < m_PipelineStack.size(); p++)
    {
        Ref<Pipeline> pipeline = m_PipelineStack[p].lock();
        if (!pipeline)
        {
            harmony::log::warn("Pipeline {} is expired.", p);
            continue;
        }
        pipeline->PreUpdate(registry, view, p_StackViewIDs[pipeline->m_Handle.Name], p_StackData[pipeline->m_Handle.Name] );

        int nextIndex = p + 1;
        if (nextIndex >= m_PipelineStack.size())
        {
            continue;
        }

        Ref<Pipeline> nextPipeline = m_PipelineStack[nextIndex].lock();

        if (!nextPipeline->HasDepth())
        {
            continue;
        }
        if (!pipeline->HasDepth())
        {
            continue;
        }

        // Get first view id of next pipeline
        bgfx::ViewId nextViewId = p_StackViewIDs[nextPipeline->m_Handle.Name][0];
        // Get tex handles for this stage final depth & next stage initial depth texture
        bgfx::TextureHandle srcTexture  = GetPipelineFinalDepth(pipeline->m_Handle);
        bgfx::TextureHandle destTexture = GetPipelineInitialDepth(nextPipeline->m_Handle);
        // this is blasphemy. Burn
        if (srcTexture.idx >=  4096 || destTexture.idx >= 4096)
        {
            continue;
        }
        bgfx::blit(
            nextViewId,
            destTexture,
            0,
            0,
            srcTexture
        );
     }
}

std::vector<harmony::PipelineStack::Data>  harmony::PipelineStack::PostUpdate(entt::registry& registry, WeakRef<View> view)
{
    HARMONY_PROFILE_FUNCTION()
    for (int p = 0; p < m_PipelineStack.size(); p++)
    {
        Ref<Pipeline> pipeline = m_PipelineStack[p].lock();
        if (!pipeline)
        {
            harmony::log::warn("Pipeline {} is expired.", p);
            continue;
        }
        pipeline->PostUpdate(registry, view, p_StackViewIDs[pipeline->m_Handle.Name], p_StackData[pipeline->m_Handle.Name]);
    }
    
    Ref<View> _view = view.lock();

    std::vector<Data> texturesToBlit = std::vector<Data>();

    for (int p = 0; p < m_PipelineStack.size(); p++)
    {
        Ref<Pipeline> pipeline = m_PipelineStack[p].lock();
        if (!pipeline)
        {
            harmony::log::warn("Pipeline {} is expired.", p);
            continue;
        }
        // Get final image of this pipeline
        auto ph = pipeline->m_Handle;
        for (auto& data : p_StackData[ph.Name])
        {
            bgfx::TextureHandle th = BGFX_INVALID_HANDLE;

            if (data.m_Attachments.find(Attachment::Type::RGBA8F) != data.m_Attachments.end())
            {
                th = data.m_Attachments[Attachment::Type::RGBA8F].m_Handle;
            }
            if (data.m_Attachments.find(Attachment::Type::RGBA16F) != data.m_Attachments.end())
            {
                th = data.m_Attachments[Attachment::Type::RGBA16F].m_Handle;
            }
            if (data.m_Attachments.find(Attachment::Type::RGBA32F) != data.m_Attachments.end())
            {
                th = data.m_Attachments[Attachment::Type::RGBA32F].m_Handle;
            }

            if (th.idx == bgfx::kInvalidHandle)
            {
                harmony::log::warn("Pipeline {} has no colour attachments.", p);
                continue;
            }
            // bind & draw w/ present shader
            Data stackDataEntry {th.idx, pipeline->m_PostProcess};
            texturesToBlit.emplace_back(stackDataEntry);
        }       
    }

    return texturesToBlit;
}

void harmony::PipelineStack::AddPipeline(WeakRef<Pipeline> pipeline, WeakRef<View> view)
{
    InitializeStack(view);

    Ref<Pipeline> p = pipeline.lock();
    if (!p)
    {
        harmony::log::warn("Pipeline is expired, cannot remove from the stack.");
        return;
    }

    if (p_StackData.find(p->m_Handle.Name) == p_StackData.end())
    {
        // add pipeline
        m_PipelineStack.push_back(pipeline);
        // create view ids
        InitializePipeline(p, view);
        SortPipelineStack();
    }
    else
    {
        harmony::log::warn("Pipeline : {} already added to the stack.", p->m_Handle.Name);
    }
}

void harmony::PipelineStack::AddPipelineAtIndex(WeakRef<Pipeline> pipeline, WeakRef<View> view, int index)
{
    AddPipeline(pipeline, view);
    if (index < 0)
    {
        return;
    }

    if (index >= m_PipelineStack.size())
    {
        return;
    }
    Ref<Pipeline> p = pipeline.lock();
    int pipelineIndex = GetPipelineIndex(pipeline);
    while (pipelineIndex != index)
    {
        if (pipelineIndex < index)
        {
            MovePipelineUp(p->m_Handle);
        }
        else
        {
            MovePipelineDown(p->m_Handle);
        }
        pipelineIndex = GetPipelineIndex(pipeline);
    }

}

void harmony::PipelineStack::RemovePipeline(WeakRef<Pipeline> pipeline, WeakRef<View> view)
{
    Ref<Pipeline> p = pipeline.lock();

    if (!p)
    {
        harmony::log::warn("Pipeline is expired, cannot remove from the stack.");
        return;
    }
    if (p_StackViewIDs.find(p->m_Handle.Name) == p_StackViewIDs.end())
    {
        harmony::log::warn("Pipeline : {} not in the stack.", p->m_Handle.Name);
        return;
    }
    else
    {
        int indexToRemove = -1;

        for (int i = 0; i < m_PipelineStack.size(); i++)
        {
            if (m_PipelineStack[i].lock() == p)
            {
                indexToRemove = i;
                break;
            }
        }


        for (auto& data : p_StackData[p->m_Handle.Name])
        {
            bgfx::destroy(data.m_FramebufferHandle);
            for (auto& [type, attachment] :data.m_Attachments)
            {
                bgfx::destroy(attachment.m_Handle);
            }
        }
        p_StackData.erase(p->m_Handle.Name);
        
        if (indexToRemove >= 0)
        {
            entt::registry reg = entt::registry();
            m_PipelineStack[indexToRemove].lock()->Cleanup(reg, view, p_StackViewIDs[p->m_Handle.Name]);
            m_PipelineStack.erase(m_PipelineStack.begin() + indexToRemove);
        }
        SortPipelineStack();
    }
}

int harmony::PipelineStack::GetPipelineIndex(WeakRef<Pipeline> pipeline)
{
    int index = -1;
    
    if (pipeline.expired())
    {
        return index;
    }

    Ref<Pipeline> p = pipeline.lock();

    for (int i = 0; i < m_PipelineStack.size(); i++)
    {
        if (m_PipelineStack[i].lock() == p)
        {
            index = i;
            break;
        }
    }

    return index;
}

void harmony::PipelineStack::MovePipelineUp(const PipelineHandle& pipelineHandle)
{
    MovePipeline(pipelineHandle, true);
}

void harmony::PipelineStack::MovePipelineDown(const PipelineHandle& pipelineHandle)
{
    MovePipeline(pipelineHandle, false);
}

void harmony::PipelineStack::AddPostProcessStage(WeakRef<PostProcessStage> postProcessStage, WeakRef<View> view)
{
    InitializeStack(view);
    Ref<PostProcessStage> stage = postProcessStage.lock();

    if (!stage)
    {
        harmony::log::warn("Post process stage is expired, cannot remove from the stack.");
        return;
    }

    if (p_StackData.find(stage->m_Name) == p_StackData.end())
    {
        // add pipeline
        m_PostProcessPipelineStack.push_back(postProcessStage);
        // create view ids
        InitializePostProcessStage(stage, view);
    }
    else
    {
        harmony::log::warn("Post process stage : {} already added to the stack.", stage->m_Name);
    }
}

void harmony::PipelineStack::AddPostProcessStageAtIndex(WeakRef<PostProcessStage> postProcessStage, WeakRef<View> view, int index)
{
    AddPostProcessStage(postProcessStage, view);
    if (index < 0)
    {
        return;
    }

    if (index >= m_PostProcessPipelineStack.size())
    {
        return;
    }
    Ref<PostProcessStage> p = postProcessStage.lock();
    int postProcessIndex = GetPostProcessStageIndex(postProcessStage);

    while (postProcessIndex != index)
    {
        if (postProcessIndex < index)
        {
            MovePostProcessStageUp(p->m_Name);
        }
        else
        {
            MovePostProcessStageDown(p->m_Name);
        }
        postProcessIndex = GetPostProcessStageIndex(postProcessStage);
    }
}

void harmony::PipelineStack::RemovePostProcessStage(WeakRef<PostProcessStage> postProcessStage, WeakRef<View> view)
{
    Ref<PostProcessStage> p = postProcessStage.lock();
    
    if (!p)
    {
        harmony::log::warn("Post process stage is expired, cannot remove from the stack.");
        return;
    }
    if (p_StackViewIDs.find(p->m_Name) == p_StackViewIDs.end())
    {
        harmony::log::warn("Pipeline : {} not in the stack.", p->m_Name);
        return;
    }
    else
    {
        int indexToRemove = -1;

        for (int i = 0; i < m_PostProcessPipelineStack.size(); i++)
        {
            if (m_PostProcessPipelineStack[i].lock() == p)
            {
                indexToRemove = i;
                break;
            }
        }


        for (auto& data : p_StackData[p->m_Name])
        {
            bgfx::destroy(data.m_FramebufferHandle);
            for (auto& [type, attachment] : data.m_Attachments)
            {
                bgfx::destroy(attachment.m_Handle);
            }
        }
        p_StackData.erase(p->m_Name);

        if (indexToRemove >= 0)
        {
            entt::registry reg = entt::registry();
            // potentially an issue here.
            m_PostProcessPipelineStack[indexToRemove].lock()->Cleanup(view, p_StackViewIDs[p->m_Name][0]);
            m_PostProcessPipelineStack.erase(m_PostProcessPipelineStack.begin() + indexToRemove);
        }
    }
}

int harmony::PipelineStack::GetPostProcessStageIndex(WeakRef<PostProcessStage> postProcessStage)
{
    int index = -1;

    if (postProcessStage.expired())
    {
        return index;
    }

    Ref<PostProcessStage> stage = postProcessStage.lock();

    for (int i = 0; i < m_PostProcessPipelineStack.size(); i++)
    {
        if (m_PostProcessPipelineStack[i].lock() == stage)
        {
            index = i;
            break;
        }
    }

    return index;
}

void harmony::PipelineStack::MovePostProcessStageUp(const std::string& stageName)
{
    MovePostProcessStage(stageName, true);
}

void harmony::PipelineStack::MovePostProcessStageDown(const std::string& stageName)
{
    MovePostProcessStage(stageName, false);
}

nlohmann::json harmony::PipelineStack::Serialize()
{
    nlohmann::json j;
    auto pipelinesJson = nlohmann::json::array();
    for (auto pipeline : m_PipelineStack)
    {
        pipelinesJson.emplace_back(pipeline.lock()->m_Handle);
    }

    auto postProcessJson = nlohmann::json::array();
    for (auto pipeline : m_PostProcessPipelineStack)
    {
        postProcessJson.emplace_back(pipeline.lock()->Serialize());
    }


    j[sk_PipelineStackPipelines] = pipelinesJson;
    j[sk_PipelineStackPostProcessStages] = postProcessJson;
    return j;
}

void harmony::PipelineStack::InitializeStack(WeakRef<View> view)
{
    if (!p_Initialized)
    {
        Ref<View> _view = view.lock();
        std::vector<bgfx::TextureHandle> attachments = std::vector<bgfx::TextureHandle>();

        m_PipelineStackAccumulationAttachment   = bgfx::createTexture2D(
            _view->m_Width
            , _view->m_Height
            , false
            , 1
            , bgfx::TextureFormat::RGBA16F // TODO Link to s_AccumulationBufferFormat.
            , BGFX_TEXTURE_RT | BGFX_TEXTURE_BLIT_DST
        );

        std::string stackAccumulationViewName = _view->m_Name + "-accumulate";

        attachments.emplace_back(m_PipelineStackAccumulationAttachment);
        m_PipelineStackAccumulationFB = bgfx::createFrameBuffer(attachments.size(), attachments.data(), false);
        bgfx::setViewFrameBuffer(m_PipelineStackAccumulationView, m_PipelineStackAccumulationFB);
        bgfx::setViewName(m_PipelineStackAccumulationView, stackAccumulationViewName.c_str());
        bgfx::setViewRect(m_PipelineStackAccumulationView, 0, 0, (uint16_t)_view->m_Width, (uint16_t)_view->m_Height);
        attachments.clear();

        m_PipelineStackNoPostProcessAttachment = bgfx::createTexture2D(
            _view->m_Width
            , _view->m_Height
            , false
            , 1
            , bgfx::TextureFormat::RGBA16F // TODO Link to s_AccumulationBufferFormat.
            , BGFX_TEXTURE_RT | BGFX_TEXTURE_BLIT_DST
        );

        std::string stackNoPostProcessViewName = _view->m_Name + "-no-post-process";

        attachments.emplace_back(m_PipelineStackNoPostProcessAttachment);
        m_PipelineStackNoPostProcessFB = bgfx::createFrameBuffer(attachments.size(), attachments.data(), false);
        bgfx::setViewFrameBuffer(m_PipelineStackNoPostProcessView, m_PipelineStackNoPostProcessFB);
        bgfx::setViewName(m_PipelineStackNoPostProcessView, stackNoPostProcessViewName.c_str());
        bgfx::setViewRect(m_PipelineStackNoPostProcessView, 0, 0, (uint16_t)_view->m_Width, (uint16_t)_view->m_Height);
        attachments.clear();

        m_FinalFramebufferAttachment    = bgfx::createTexture2D(
            _view->m_Width
            , _view->m_Height
            , false
            , 1
            , bgfx::TextureFormat::BGRA8
            , BGFX_TEXTURE_RT
        );
        attachments.emplace_back(m_FinalFramebufferAttachment);

        std::string stackFinalViewName = _view->m_Name + "-final";

        m_FinalFramebufferHandle = bgfx::createFrameBuffer(attachments.size(), attachments.data(), false);
        bgfx::setViewFrameBuffer(m_FinalImageViewId, m_FinalFramebufferHandle);
        bgfx::setViewName(m_FinalImageViewId, stackFinalViewName.c_str());
        bgfx::setViewRect(m_FinalImageViewId, 0, 0, (uint16_t)_view->m_Width, (uint16_t)_view->m_Height);
        p_Initialized = true;
    }
}

void harmony::PipelineStack::InitializePipeline(Ref<Pipeline> pipeline, WeakRef<View> view)
{
    if (p_StackViewIDs.find(pipeline->m_Handle.Name) == p_StackViewIDs.end())
    {
        p_StackViewIDs.emplace(pipeline->m_Handle.Name, std::vector<bgfx::ViewId>());

        int numViewsRequired = pipeline->NumPipelineStages();

        harmony::log::info("Generating {} ViewIds for Pipeline {}", numViewsRequired, pipeline->m_Name);

        for (int i = 0; i < numViewsRequired; i++)
        {
            p_StackViewIDs[pipeline->m_Handle.Name].emplace_back(Renderer::GetViewID());
        }
    }
    entt::registry reg = entt::registry();
    p_StackData[pipeline->m_Handle.Name] = pipeline->Init(reg, view, p_StackViewIDs[pipeline->m_Handle.Name]);
}

void harmony::PipelineStack::InitializePostProcessStage(Ref<PostProcessStage> stage, WeakRef<View> view)
{
    if (p_StackViewIDs.find(stage->m_Name) == p_StackViewIDs.end())
    {
        p_StackViewIDs.emplace(stage->m_Name, std::vector<bgfx::ViewId>());

        int numViewsRequired = 1;

        harmony::log::info("Generating {} ViewIds for Pipeline {}", numViewsRequired, stage->m_Name);

        for (int i = 0; i < numViewsRequired; i++)
        {
            p_StackViewIDs[stage->m_Name].emplace_back(Renderer::GetViewID());
        }
    }
    entt::registry reg = entt::registry();
    p_StackData[stage->m_Name] = std::vector<PipelineStage::Data>();

    PipelineStage::Data data = stage->Init(reg, view, p_StackViewIDs[stage->m_Name][0]);

    p_StackData[stage->m_Name].emplace_back(data);
}

void harmony::PipelineStack::OnViewResized(WeakRef<View> view)
{
    if (view.expired())
    {
        harmony::log::error("PipelineStack : Cannot resize, view is expired.");
        return;
    }

    p_Initialized = false;
    bgfx::setViewClear(m_FinalImageViewId, BGFX_CLEAR_COLOR, 0);
    bgfx::setViewClear(m_PipelineStackAccumulationView, BGFX_CLEAR_COLOR, 0);

    for (auto [name, viewIds] : p_StackViewIDs)
    {
        for (int i = 0; i < viewIds.size(); i++)
        {
            bgfx::setViewClear(viewIds[i], BGFX_CLEAR_COLOR, 0);
        }
    }

    bgfx::destroy(m_FinalFramebufferHandle);
    bgfx::destroy(m_FinalFramebufferAttachment);

    for (auto [name, datas] : p_StackData)
    {
        for (int i = 0; i < datas.size(); i++)
        {
            datas[i].Clear();
        }
    }

    p_StackData.clear();

    Ref<View> v = view.lock();
    std::vector<WeakRef<Pipeline>> stackCopy = std::vector<WeakRef<Pipeline>>();
    std::vector<WeakRef<PostProcessStage>> ppStackCopy = std::vector<WeakRef<PostProcessStage>>();
    for (int i = 0; i < m_PipelineStack.size(); i++)
    {
        stackCopy.push_back(m_PipelineStack[i]);
    }
    for (int i = 0; i < m_PostProcessPipelineStack.size(); i++)
    {
        ppStackCopy.push_back(m_PostProcessPipelineStack[i]);
    }
    for (int i = 0; i < stackCopy.size(); i++)
    {
        RemovePipeline(stackCopy[i], view);
    }

    for (int i = 0; i < ppStackCopy.size(); i++)
    {
        RemovePostProcessStage(ppStackCopy[i], view);
    }

    for (int i = 0; i < stackCopy.size(); i++)
    {
        AddPipelineAtIndex(stackCopy[i], view, i);
    }

    for (int i = 0; i < ppStackCopy.size(); i++)
    {
        AddPostProcessStageAtIndex(ppStackCopy[i], view, i);
    }

}

void harmony::PipelineStack::SortPipelineStack()
{
    bool sorted = false;
    int pipelineCounter = 0;

    while (!sorted)
    {
        if (pipelineCounter >= m_PipelineStack.size())
        {
            sorted = true;
            continue;
        }
        bool hasPreviousPipeline = false;
        bool hasNextPipeline = false;

        // Get current pipeline
        WeakRef<Pipeline> currentPipeline = m_PipelineStack[pipelineCounter];
        if (currentPipeline.expired())
        {
            harmony::log::error("Pipeline in stack is expired, cannot continue sorting.");
            return;
        }

        // Get Prev. Pipeline (if exists)
        WeakRef<Pipeline> previousPipeline  = WeakRef<Pipeline>();
        if (pipelineCounter > 0)
        {
            previousPipeline = m_PipelineStack[pipelineCounter - 1];
            hasPreviousPipeline = true;
        }

        // Get Next. Pipeline (if exists)
        WeakRef<Pipeline> nextPipeline      = WeakRef<Pipeline>();
        if (pipelineCounter < (m_PipelineStack.size() - 1))
        {
            nextPipeline = m_PipelineStack[pipelineCounter + 1];
            hasNextPipeline = true;
        } 

        // Perform sort
        // Sort compute pipelines to bottom of stack
        Pipeline::Type currentPipelineType = currentPipeline.lock()->m_Type;
        PipelineHandle currentPipelineHandle = currentPipeline.lock()->m_Handle;
        // first must be compute
        if (currentPipelineType == Pipeline::Type::Compute)
        {
            if (hasPreviousPipeline)
            {
                if (previousPipeline.lock()->m_Type != Pipeline::Type::Compute)
                {
                    MovePipelineDown(currentPipelineHandle);
                    pipelineCounter--;
                    continue;
                }
            }
            else
            {
                pipelineCounter++;
                continue;
            }
        }
        // last must be post process
        if (currentPipelineType == Pipeline::Type::PostProcess)
        {
            if (hasNextPipeline)
            {
                if (nextPipeline.lock()->m_Type != Pipeline::Type::PostProcess)
                {
                    MovePipelineUp(currentPipelineHandle);
                    pipelineCounter--;
                    continue;
                }
            }
            else
            {
                pipelineCounter++;
                continue;
            }
        }

        pipelineCounter++;
    }
}

void harmony::PipelineStack::MovePipeline(const PipelineHandle& pipelineHandle, bool moveUp)
{
    int shiftDir = moveUp ? 1 : -1;
    int indexToShift = -1;

    for (int i = 0; i < m_PipelineStack.size(); i++)
    {
        if (m_PipelineStack[i].lock()->m_Handle == pipelineHandle)
        {
            indexToShift = i;
            break;
        }
    }

    if (indexToShift < 0)
    {
        harmony::log::warn("Pipeline {} is not in the stack!", pipelineHandle.Name);
        return;
    }

    if (shiftDir + indexToShift < m_PipelineStack.size())
    {
        std::iter_swap(m_PipelineStack.begin() + indexToShift, m_PipelineStack.begin() + (indexToShift + shiftDir));
    }
}

void harmony::PipelineStack::MovePostProcessStage(const std::string& postProcessStageName, bool moveUp)
{
    int shiftDir = moveUp ? 1 : -1;
    int indexToShift = -1;

    for (int i = 0; i < m_PostProcessPipelineStack.size(); i++)
    {
        if (m_PostProcessPipelineStack[i].lock()->m_Name == postProcessStageName)
        {
            indexToShift = i;
            break;
        }
    }

    if (indexToShift < 0)
    {
        harmony::log::warn("Post Process Stage {} is not in the stack!", postProcessStageName);
        return;
    }

    if (shiftDir + indexToShift < m_PostProcessPipelineStack.size())
    {
        std::iter_swap(m_PostProcessPipelineStack.begin() + indexToShift, m_PostProcessPipelineStack.begin() + (indexToShift + shiftDir));
    }
}

bgfx::TextureHandle harmony::PipelineStack::GetPipelineInitialDepth(PipelineHandle& handle)
{
    if (p_StackData.find(handle.Name) == p_StackData.end())
    {
        harmony::log::error("Pipeline with handle {} is not in this stack.", handle.Name);
        return bgfx::TextureHandle();
    }

    auto datas = p_StackData[handle.Name];

    for (auto data : datas)
    {
        if (data.m_Attachments.find(Attachment::Type::Depth16F) != data.m_Attachments.end())
        {
            Attachment& a = data.m_Attachments[Attachment::Type::Depth16F];
            return a.m_Handle;
        }
        if (data.m_Attachments.find(Attachment::Type::Depth24F) != data.m_Attachments.end())
        {
            Attachment& a = data.m_Attachments[Attachment::Type::Depth24F];
            return a.m_Handle;
        }
        if (data.m_Attachments.find(Attachment::Type::Depth32F) != data.m_Attachments.end())
        {
            Attachment& a = data.m_Attachments[Attachment::Type::Depth32F];
            return a.m_Handle;
        }
    }

    harmony::log::error("Pipeline with handle {} does not have a depth texture.", handle.Name);
    return bgfx::TextureHandle();
}

bgfx::TextureHandle harmony::PipelineStack::GetPipelineFinalDepth(PipelineHandle& handle)
{
    if (p_StackData.find(handle.Name) == p_StackData.end())
    {
        harmony::log::error("Pipeline with handle {} is not in this stack.", handle.Name);
        return bgfx::TextureHandle();
    }

    auto datas = p_StackData[handle.Name];

    for (int i = datas.size() - 1; i >= 0; i--)
    {
        auto data = datas[i];
        if (data.m_Attachments.find(Attachment::Type::Depth16F) != data.m_Attachments.end())
        {
            Attachment& a = data.m_Attachments[Attachment::Type::Depth16F];
            return a.m_Handle;
        }
        if (data.m_Attachments.find(Attachment::Type::Depth24F) != data.m_Attachments.end())
        {
            Attachment& a = data.m_Attachments[Attachment::Type::Depth24F];
            return a.m_Handle;
        }
        if (data.m_Attachments.find(Attachment::Type::Depth32F) != data.m_Attachments.end())
        {
            Attachment& a = data.m_Attachments[Attachment::Type::Depth32F];
            return a.m_Handle;
        }
    }
}
