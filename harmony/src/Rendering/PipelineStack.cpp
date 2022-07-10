#include "Rendering/PipelineStack.h"
#include "Rendering/Shapes.h"
#include "Core/Log.hpp"
#include "Rendering/Renderer.h"

harmony::PipelineStack::PipelineStack()
{
}

harmony::PipelineStack::PipelineStack(WeakRef<View> view, WeakRef<ShaderProgram> presentShader) : p_View(view.lock()), p_PresentProgram(presentShader.lock())
{
}

void harmony::PipelineStack::Init(entt::registry& registry)
{
    for (int p = 0; p < m_Stack.size(); p++)
    {
        if (!m_Stack[p])
        {
            harmony::log::warn("Pipeline {} is expired.", p);
            continue;
        }
        m_Stack[p]->Init(registry, p_View);
    }

    p_FinalImageViewId = Renderer::GetViewID();
    p_FinalFramebufferHandle = bgfx::createFrameBuffer(p_View->m_Width, p_View->m_Height, bgfx::TextureFormat::BGRA8);
    bgfx::setViewFrameBuffer(p_FinalImageViewId, p_FinalFramebufferHandle);
    bgfx::setViewRect(p_FinalImageViewId, 0, 0, bgfx::BackbufferRatio::Equal);

    p_TexHandle = p_PresentProgram->m_Uniforms[0].BgfxHandle;
}

void harmony::PipelineStack::PreUpdate(entt::registry& registry)
{
    for (int p = 0; p < m_Stack.size(); p++)
    {
        if (!m_Stack[p])
        {
            harmony::log::warn("Pipeline {} is expired.", p);
            continue;
        }
        m_Stack[p]->PreUpdate(registry, p_View);
    }
}

void harmony::PipelineStack::PostUpdate(entt::registry& registry)
{
    for (int p = 0; p < m_Stack.size(); p++)
    {
        if (!m_Stack[p])
        {
            harmony::log::warn("Pipeline {} is expired.", p);
            continue;
        }
        m_Stack[p]->PostUpdate(registry, p_View);
    }

    for (int p = 0; p < m_Stack.size(); p++)
    {
        if (!m_Stack[p])
        {
            harmony::log::warn("Pipeline {} is expired.", p);
            continue;
        }
        ScreenSpaceQuad(p_View->m_Width, p_View->m_Height);
    }
}

void harmony::PipelineStack::Cleanup(entt::registry& registry)
{
    for (int p = 0; p < m_Stack.size(); p++)
    {
        if (!m_Stack[p])
        {
            harmony::log::warn("Pipeline {} is expired.", p);
            continue;
        }
        m_Stack[p]->Cleanup(registry, p_View);
    }
}
