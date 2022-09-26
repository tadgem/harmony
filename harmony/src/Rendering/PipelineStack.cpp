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
    for (int p = 0; p < m_Stack.size(); p++)
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
    p_Initialized = true;
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

nlohmann::json harmony::PipelineStack::Serialize()
{
    /*auto json = nlohmann::json::array();
    for (auto pipeline : m_Stack)
    {
        json.emplace_back(pipeline->Serialize());
    }
    return json;*/
}

void harmony::PipelineStack::Deserialize(nlohmann::json& json)
{
    /*for (int i = 0; i < json.size(); i++)
    {
        Ref<Pipeline> p = CreateRef<Pipeline>(PipelineHandle::New(""));
        p->Deserialize(json[i]);
    }*/
}
