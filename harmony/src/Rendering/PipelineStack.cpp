#include "Rendering/PipelineStack.h"
#include "Rendering/Shapes.h"
#include "Core/Log.hpp"
#include "Rendering/Renderer.h"

harmony::PipelineStack::PipelineStack()
{
    p_Initialized = false;
}


bgfx::TextureHandle harmony::PipelineStack::GetStackFinalImage()
{
    if (!p_Initialized)
    {
        return bgfx::TextureHandle();
    }
    if (!bgfx::isValid(p_FinalFramebufferHandle))
    {
        return bgfx::TextureHandle();
    }
    return bgfx::getTexture(p_FinalFramebufferHandle);
}

void harmony::PipelineStack::Init(entt::registry& registry, WeakRef<View> view)
{
    /*for (int p = 0; p < m_Stack.size(); p++)
    {
        if (!m_Stack[p])
        {
            harmony::log::warn("Pipeline {} is expired.", p);
            continue;
        }
        m_Stack[p]->Init(registry, view);
    }

    p_FinalImageViewId = Renderer::GetViewID();
    p_FinalFramebufferHandle = bgfx::createFrameBuffer(view->m_Width, view->m_Height, bgfx::TextureFormat::BGRA8);
    bgfx::setViewFrameBuffer(p_FinalImageViewId, p_FinalFramebufferHandle);
    bgfx::setViewRect(p_FinalImageViewId, 0, 0, bgfx::BackbufferRatio::Equal);
    bgfx::setViewName(p_FinalImageViewId, "FinalImage");
    p_TexHandle = p_PresentProgram->m_Uniforms[0].BgfxHandle;
    p_Initialized = true;*/
}

void harmony::PipelineStack::PreUpdate(entt::registry& registry, WeakRef<View> view)
{
    //for (int p = 0; p < m_Stack.size(); p++)
    //{
    //    if (!m_Stack[p])
    //    {
    //        harmony::log::warn("Pipeline {} is expired.", p);
    //        continue;
    //    }
    //    m_Stack[p]->PreUpdate(registry, view);
    //    int nextIndex = p + 1;

    //    if (nextIndex >= m_Stack.size())
    //    {
    //        continue;
    //    }

    //    if (!m_Stack[nextIndex]->HasDepth())
    //    {
    //        continue;
    //    }

    //    if (!m_Stack[p]->HasDepth())
    //    {
    //        continue;
    //    }

    //    bgfx::ViewId nextViewId = m_Stack[nextIndex]->GetFirstViewID();
    //    bgfx::TextureHandle destTexture = m_Stack[nextIndex]->GetInitialDepth();
    //    bgfx::TextureHandle srcTexture = m_Stack[p]->GetFinalDepth();
    //    if (srcTexture.idx >=  4096 || destTexture.idx >= 4096)
    //    {
    //        continue;
    //    }
    //    bgfx::blit(
    //        nextViewId,
    //        destTexture,
    //        0,
    //       0,
    //        srcTexture
    //    );
    // }
}

void harmony::PipelineStack::PostUpdate(entt::registry& registry, WeakRef<View> view)
{
    //for (int p = 0; p < m_Stack.size(); p++)
    //{
    //    if (!m_Stack[p])
    //    {
    //        harmony::log::warn("Pipeline {} is expired.", p);
    //        continue;
    //    }
    //    m_Stack[p]->PostUpdate(registry, view);
    //}
    //bgfx::setViewClear(p_FinalImageViewId, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x00000000);
    //
    //for (int p = 0; p < m_Stack.size(); p++)
    //{
    //    if (!m_Stack[p])
    //    {
    //        harmony::log::warn("Pipeline {} is expired.", p);
    //        continue;
    //    }
    //    bgfx::TextureHandle pipelineFinalImage = m_Stack[p]->GetFinalImage();
    //    bgfx::setTexture(0, p_TexHandle, pipelineFinalImage);
    //    ScreenSpaceQuad(view->m_Width, view->m_Height);
    //    bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A | BGFX_STATE_BLEND_NORMAL);
    //    bgfx::submit(p_FinalImageViewId, p_PresentProgram->m_Handle);
    //}
}

void harmony::PipelineStack::Cleanup(entt::registry& registry, WeakRef<View> view)
{
    /*for (int p = 0; p < m_Stack.size(); p++)
    {
        if (!m_Stack[p])
        {
            harmony::log::warn("Pipeline {} is expired.", p);
            continue;
        }
        m_Stack[p]->Cleanup(registry, view);
    }*/
}

void harmony::PipelineStack::AddPipeline(WeakRef<Pipeline> pipeline)
{
    Ref<Pipeline> p = pipeline.lock();
    if (!p)
    {
        harmony::log::warn("Pipeline is expired, cannot remove from the stack.");
        return;
    }

    if (p_StackViewIDs.find(p->m_Handle) == p_StackViewIDs.end())
    {
        // add pipeline
        p_StackViewIDs.emplace(p->m_Handle, std::vector<bgfx::ViewId>());
        m_Stack.push_back(pipeline);
        // create view ids
        InitializePipelineViewIDs(p);
        SortStack();
    }
    else
    {
        harmony::log::warn("Pipeline : {} already added to the stack.", p->m_Handle.Name);
    }
}

void harmony::PipelineStack::RemovePipeline(WeakRef<Pipeline> pipeline)
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

        if (indexToRemove >= 0)
        {
            m_Stack.erase(m_Stack.begin() + indexToRemove);
        }

        p_StackViewIDs.erase(p->m_Handle);
        SortStack();
    }
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
    /*for (auto pipeline : m_Stack)
    {
        json.emplace_back(pipeline->Serialize());
    }*/
    return json;
}

void harmony::PipelineStack::Deserialize(nlohmann::json& json)
{
    /*for (int i = 0; i < json.size(); i++)
    {
        Ref<Pipeline> p = CreateRef<Pipeline>(PipelineHandle::New(""));
        p->Deserialize(json[i]);
    }*/
}

void harmony::PipelineStack::InitializePipelineViewIDs(Ref<Pipeline> pipeline)
{
    int numViewsRequired = pipeline->NumPipelineStages();

    harmony::log::info("Generating {} ViewIds for Pipeline {}", numViewsRequired, pipeline->m_Name);

    for (int i = 0; i < numViewsRequired; i++)
    {
        p_StackViewIDs[pipeline->m_Handle].emplace_back(Renderer::GetViewID());
    }
}

void harmony::PipelineStack::SortStack()
{
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
