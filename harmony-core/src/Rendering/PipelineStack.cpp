#include "Core/Log.hpp"
#include "Rendering/PipelineStack.h"
#include "Rendering/Shapes.h"
#include "Rendering/Renderer.h"
#include "Rendering/View.h"

harmony::PipelineStack::PipelineStack()
{
    p_Initialized = false;
    m_FinalImageViewId = Renderer::GetViewID();
}

bgfx::TextureHandle harmony::PipelineStack::GetFinalImage()
{
    if (!p_Initialized)
    {
        return bgfx::TextureHandle();
    }
    return bgfx::getTexture(m_FinalFramebufferHandle);
}

void harmony::PipelineStack::PreUpdate(entt::registry& registry, WeakRef<View> view)
{
    for (int p = 0; p < m_Stack.size(); p++)
    {
        Ref<Pipeline> pipeline = m_Stack[p].lock();
        if (!pipeline)
        {
            harmony::log::warn("Pipeline {} is expired.", p);
            continue;
        }
        pipeline->PreUpdate(registry, view, p_StackViewIDs[pipeline->m_Handle], p_StackData[pipeline->m_Handle] );

        int nextIndex = p + 1;
        if (nextIndex >= m_Stack.size())
        {
            continue;
        }

        Ref<Pipeline> nextPipeline = m_Stack[nextIndex].lock();

        if (!nextPipeline->HasDepth())
        {
            continue;
        }
        if (!pipeline->HasDepth())
        {
            continue;
        }

        // Get first view id of next pipeline
        bgfx::ViewId nextViewId = p_StackViewIDs[nextPipeline->m_Handle][0];
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

std::vector<bgfx::TextureHandle>  harmony::PipelineStack::PostUpdate(entt::registry& registry, WeakRef<View> view)
{
    for (int p = 0; p < m_Stack.size(); p++)
    {
        Ref<Pipeline> pipeline = m_Stack[p].lock();
        if (!pipeline)
        {
            harmony::log::warn("Pipeline {} is expired.", p);
            continue;
        }
        pipeline->PostUpdate(registry, view, p_StackViewIDs[pipeline->m_Handle], p_StackData[pipeline->m_Handle]);
    }
    
    Ref<View> _view = view.lock();

    std::vector<bgfx::TextureHandle> texturesToBlit = std::vector<bgfx::TextureHandle>();

    for (int p = 0; p < m_Stack.size(); p++)
    {
        Ref<Pipeline> pipeline = m_Stack[p].lock();
        if (!pipeline)
        {
            harmony::log::warn("Pipeline {} is expired.", p);
            continue;
        }
        // Get final image of this pipeline
        auto ph = pipeline->m_Handle;
        for (auto& data : p_StackData[ph])
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

            texturesToBlit.push_back(th);
        }       
    }

    return texturesToBlit;
}

void harmony::PipelineStack::AddPipeline(WeakRef<Pipeline> pipeline, WeakRef<View> view)
{
    if (!p_Initialized)
    {
        Ref<View> _view = view.lock();
        p_FinalFramebufferAttachment = bgfx::createTexture2D(
            _view->m_Width
            , _view->m_Height
            , false
            , 1
            , bgfx::TextureFormat::BGRA8
            , BGFX_TEXTURE_RT
        );
        std::vector<bgfx::TextureHandle> attachments = std::vector<bgfx::TextureHandle>();
        attachments.emplace_back(p_FinalFramebufferAttachment);
        m_FinalFramebufferHandle = bgfx::createFrameBuffer(attachments.size(), attachments.data(), false);
        bgfx::setViewFrameBuffer(m_FinalImageViewId, m_FinalFramebufferHandle);
        bgfx::setViewName(m_FinalImageViewId, _view->m_Name.c_str());
        bgfx::setViewRect(m_FinalImageViewId, 0,0, (uint16_t)_view->m_Width, (uint16_t)_view->m_Height);
        p_Initialized = true;
    }
    Ref<Pipeline> p = pipeline.lock();
    if (!p)
    {
        harmony::log::warn("Pipeline is expired, cannot remove from the stack.");
        return;
    }

    if (p_StackData.find(p->m_Handle) == p_StackData.end())
    {
        // add pipeline
        m_Stack.push_back(pipeline);
        // create view ids
        InitializePipeline(p, view);
        SortStack();
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

    if (index >= m_Stack.size())
    {
        return;
    }
    Ref<Pipeline> p = pipeline.lock();
    int pipelineIndex = GetPipelineIndex(pipeline);
    while (pipelineIndex != index)
    {
        if (pipelineIndex < index)
        {
            MoveUp(p->m_Handle);
        }
        else
        {
            MoveDown(p->m_Handle);
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
    if (p_StackViewIDs.find(p->m_Handle) == p_StackViewIDs.end())
    {
        harmony::log::warn("Pipeline : {} not in the stack.", p->m_Handle.Name);
        return;
    }
    else
    {
        int indexToRemove = -1;

        for (int i = 0; i < m_Stack.size(); i++)
        {
            if (m_Stack[i].lock() == p)
            {
                indexToRemove = i;
                break;
            }
        }


        for (auto& data : p_StackData[p->m_Handle])
        {
            bgfx::destroy(data.m_FramebufferHandle);
            for (auto& [type, attachment] :data.m_Attachments)
            {
                bgfx::destroy(attachment.m_Handle);
            }
        }
        p_StackData.erase(p->m_Handle);
        
        if (indexToRemove >= 0)
        {
            entt::registry reg = entt::registry();
            m_Stack[indexToRemove].lock()->Cleanup(reg, view, p_StackViewIDs[p->m_Handle]);
            m_Stack.erase(m_Stack.begin() + indexToRemove);
        }
        SortStack();
    }
}

int harmony::PipelineStack::GetPipelineIndex(WeakRef<Pipeline> pipeline)
{
    int index = -1;
    
    if (pipeline.expired())
    {
        return index;
    }

    for (int i = 0; i < m_Stack.size(); i++)
    {
        if (m_Stack[i].lock() == pipeline.lock())
        {
            index = i;
        }
    }

    return index;
}

void harmony::PipelineStack::MoveUp(const PipelineHandle& pipelineHandle)
{
    MovePipeline(pipelineHandle, true);
}

void harmony::PipelineStack::MoveDown(const PipelineHandle& pipelineHandle)
{
    MovePipeline(pipelineHandle, false);
}

nlohmann::json harmony::PipelineStack::Serialize()
{
    auto json = nlohmann::json::array();
    for (auto pipeline : m_Stack)
    {
        json.emplace_back(pipeline.lock()->m_Handle);
    }
    return json;
}

void harmony::PipelineStack::InitializePipeline(Ref<Pipeline> pipeline, WeakRef<View> view)
{
    if (p_StackViewIDs.find(pipeline->m_Handle) == p_StackViewIDs.end())
    {
        p_StackViewIDs.emplace(pipeline->m_Handle, std::vector<bgfx::ViewId>());

        int numViewsRequired = pipeline->NumPipelineStages();

        harmony::log::info("Generating {} ViewIds for Pipeline {}", numViewsRequired, pipeline->m_Name);

        for (int i = 0; i < numViewsRequired; i++)
        {
            p_StackViewIDs[pipeline->m_Handle].emplace_back(Renderer::GetViewID());
        }
    }
    entt::registry reg = entt::registry();
    p_StackData[pipeline->m_Handle] = pipeline->Init(reg, view, p_StackViewIDs[pipeline->m_Handle]);
}

void harmony::PipelineStack::OnViewResized(WeakRef<View> view)
{
    if (view.expired())
    {
        harmony::log::error("PipelineStack : Cannot resize, view is expired.");
        return;
    }

    p_Initialized = false;
    bgfx::destroy(m_FinalFramebufferHandle);
    bgfx::destroy(p_FinalFramebufferAttachment);

    Ref<View> v = view.lock();
    std::vector<WeakRef<Pipeline>> stackCopy = std::vector<WeakRef<Pipeline>>();

    for (int i = 0; i < m_Stack.size(); i++)
    {
        stackCopy.push_back(m_Stack[i]);
    }

    for (int i = 0; i < stackCopy.size(); i++)
    {
        RemovePipeline(stackCopy[i], view);
    }

    for (int i = 0; i < stackCopy.size(); i++)
    {
        AddPipelineAtIndex(stackCopy[i], view, i);
    }

}

void harmony::PipelineStack::SortStack()
{
    bool sorted = false;
    int pipelineCounter = 0;

    while (!sorted)
    {
        if (pipelineCounter >= m_Stack.size())
        {
            sorted = true;
            continue;
        }
        bool hasPreviousPipeline = false;
        bool hasNextPipeline = false;

        // Get current pipeline
        WeakRef<Pipeline> currentPipeline = m_Stack[pipelineCounter];
        if (currentPipeline.expired())
        {
            harmony::log::error("Pipeline in stack is expired, cannot continue sorting.");
            return;
        }

        // Get Prev. Pipeline (if exists)
        WeakRef<Pipeline> previousPipeline  = WeakRef<Pipeline>();
        if (pipelineCounter > 0)
        {
            previousPipeline = m_Stack[pipelineCounter - 1];
            hasPreviousPipeline = true;
        }

        // Get Next. Pipeline (if exists)
        WeakRef<Pipeline> nextPipeline      = WeakRef<Pipeline>();
        if (pipelineCounter < (m_Stack.size() - 1))
        {
            nextPipeline = m_Stack[pipelineCounter + 1];
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
                    MoveDown(currentPipelineHandle);
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
                    MoveUp(currentPipelineHandle);
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

    for (int i = 0; i < m_Stack.size(); i++)
    {
        if (m_Stack[i].lock()->m_Handle == pipelineHandle)
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

    if (shiftDir + indexToShift < m_Stack.size())
    {
        std::iter_swap(m_Stack.begin() + indexToShift, m_Stack.begin() + (indexToShift + shiftDir));
    }
}

bgfx::TextureHandle harmony::PipelineStack::GetPipelineInitialDepth(PipelineHandle& handle)
{
    if (p_StackData.find(handle) == p_StackData.end())
    {
        harmony::log::error("Pipeline with handle {} is not in this stack.", handle.Name);
        return bgfx::TextureHandle();
    }

    auto datas = p_StackData[handle];

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
    if (p_StackData.find(handle) == p_StackData.end())
    {
        harmony::log::error("Pipeline with handle {} is not in this stack.", handle.Name);
        return bgfx::TextureHandle();
    }

    auto datas = p_StackData[handle];

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