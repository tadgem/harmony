//
// Created by liam_ on 7/6/2023.
//
#include "Core/Log.hpp"
#include "Rendering/Shaders/ShaderDataSources/DeferredDataSource.h"
#include "Rendering/Shaders/Shader.h"

harmony::DeferredDataSource::DeferredDataSource(Ref<Framebuffer> gBuffer) : ShaderDataSource("DeferredDataSource"), m_GBuffer(gBuffer)
{
	p_UniformsCollected = false;
}


void harmony::DeferredDataSource::OnPreUpdate(entt::registry &registry, harmony::Ref<harmony::ShaderProgram> shader)
{
	if(!p_UniformsCollected)
	{
		CollectUniforms(shader);
	}

	Ref<Framebuffer> fb = m_GBuffer.lock();

	if(!fb)
	{
		harmony::log::warn("DeferredDataSource : framebuffer is invalid, ignoring.");
		return;
	}

	if(fb->m_Attachments.size() < 3)
	{
		harmony::log::error("DeferredDataSource : framebuffer does not have enough attachments to be a g-buffer.");
		return;
	}
	if(m_PositionTextureUniform.BgfxHandle.idx != UINT16_MAX)
	{
		bgfx::setTexture(0,  m_PositionTextureUniform.BgfxHandle, fb->m_Attachments[0].m_Handle);
	}
	if(m_NormalTextureUniform.BgfxHandle.idx != UINT16_MAX)
	{
		bgfx::setTexture(1, m_NormalTextureUniform.BgfxHandle, fb->m_Attachments[1].m_Handle);
	}
	if(m_ColorTextureUniform.BgfxHandle.idx != UINT16_MAX)
	{
		bgfx::setTexture(2,  m_ColorTextureUniform.BgfxHandle, fb->m_Attachments[2].m_Handle);
	}

	if(m_UVTextureUniform.BgfxHandle.idx != UINT16_MAX)
	{
		bgfx::setTexture(3,  m_UVTextureUniform.BgfxHandle, fb->m_Attachments[3].m_Handle);
	}

	if(m_DepthTextureUniform.BgfxHandle.idx != UINT16_MAX)
	{
		bgfx::setTexture(4,  m_DepthTextureUniform.BgfxHandle, fb->m_Attachments[4].m_Handle);
	}
}

void harmony::DeferredDataSource::OnPostUpdate(entt::registry &registry, harmony::Ref<harmony::ShaderProgram> shader)
{
	ShaderDataSource::OnPostUpdate(registry, shader);
}

void harmony::DeferredDataSource::CollectUniforms(harmony::Ref<harmony::ShaderProgram> prog)
{
	for (ShaderUniform &uniform: prog->m_Uniforms)
	{
		if (uniform.Name == g_Position)
		{
			m_PositionTextureUniform = uniform;
			continue;
		}

		if (uniform.Name == g_Normal)
		{
			m_NormalTextureUniform = uniform;
			continue;
		}

		if (uniform.Name == g_Color)
		{
			m_ColorTextureUniform = uniform;
			continue;
		}

		if (uniform.Name == g_UV)
		{
			m_UVTextureUniform = uniform;
			continue;
		}

		if (uniform.Name == g_Depth)
		{
			m_DepthTextureUniform = uniform;
			continue;
		}
	}
}

