#include "Rendering/ShaderDataContainer.h"
#include "Core/Log.hpp"
harmony::ShaderDataContainer::ShaderDataContainer(WeakRef<ShaderProgram> shaderProgram)
{
	UpdateShader(shaderProgram);
}

void harmony::ShaderDataContainer::UpdateShader(WeakRef<ShaderProgram> newShader)
{
	p_ShaderUniformCount = 0;
	p_Shader = newShader;

	if (p_Shader.expired())
	{
		harmony::log::error("Shader for data container is expired!");
		return;
	}

	UpdateContainer();
}

void harmony::ShaderDataContainer::UpdateContainer()
{
	Clear();

	Ref<ShaderProgram> shader = p_Shader.lock();
	for (auto& [key, val] : shader->m_Stages)
	{
		bgfx::UniformHandle uniforms[g_MaxUniforms];
		uint16_t stageUniformCount = bgfx::getShaderUniforms(val.lock()->m_Handle, &uniforms[0], g_MaxUniforms);

		for (uint16_t i = 0; i < stageUniformCount; i++)
		{
			bgfx::UniformInfo info;
			bgfx::getUniformInfo(uniforms[i], info);

			m_UniformInfos.emplace_back(info);
			m_UniformHandles.emplace_back(uniforms[i]);
		}
	}
}

void harmony::ShaderDataContainer::SetContainerUniforms()
{
	uint8_t textureCount = 0;

	if (m_FloatValues.size() > 0)
	{
		for (auto& [handle, value] : m_FloatValues)
		{
			bgfx::setUniform(handle.BgfxHandle, &value);
		}
	}

	if (m_Vec2Values.size() > 0)
	{
		for (auto& [handle, value] : m_Vec2Values)
		{
			bgfx::setUniform(handle.BgfxHandle, &value[0]);
		}
	}

	if (m_Vec3Values.size() > 0)
	{
		for (auto& [handle, value] : m_Vec3Values)
		{
			bgfx::setUniform(handle.BgfxHandle, &value[0]);
		}
	}

	if (m_Mat3Values.size() > 0)
	{
		for (auto& [handle, value] : m_Mat3Values)
		{
			bgfx::setUniform(handle.BgfxHandle, &value[0]);
		}
	}
	if (m_Mat4Values.size() > 0)
	{
		for (auto& [handle, value] : m_Mat4Values)
		{
			bgfx::setUniform(handle.BgfxHandle, &value[0]);
		}
	}

	if (m_TextureValues.size() > 0)
	{
		for (auto& [handle, value] : m_TextureValues)
		{
			bgfx::setTexture(textureCount, handle.BgfxHandle, value.Handle);
			textureCount++;
		}
	}
}

void harmony::ShaderDataContainer::Clear()
{
	m_UniformInfos.clear();
	m_UniformHandles.clear();
	m_Uniforms.clear();

	m_FloatValues.clear();
	m_Vec2Values.clear();
	m_Vec3Values.clear();
	m_Mat3Values.clear();
	m_Mat4Values.clear();
	m_TextureValues.clear();
}

bool harmony::ShaderDataContainer::ReturnIfNull()
{
	if (p_Shader.expired())
	{
		harmony::log::error("Shader for data container is expired!");
		return true;
	}
	return false;
}




