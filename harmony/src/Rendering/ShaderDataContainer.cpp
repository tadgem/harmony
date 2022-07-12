#include "Rendering/ShaderDataContainer.h"
#include "Core/Log.hpp"
#if HARMONY_DEBUG
#include "ImGui/imgui.h";
#endif
harmony::ShaderDataContainer::ShaderDataContainer()
{
}
harmony::ShaderDataContainer::ShaderDataContainer(WeakRef<ShaderProgram> shaderProgram)
{
	UpdateShader(shaderProgram);
}

void harmony::ShaderDataContainer::UpdateShader(WeakRef<ShaderProgram> newShader)
{
	p_ShaderUniformCount = 0;
	m_Shader = newShader;

	if (m_Shader.expired())
	{
		harmony::log::error("Shader for data container is expired!");
		return;
	}

	UpdateContainer();
}

void harmony::ShaderDataContainer::UpdateContainer()
{
	Clear();

	Ref<ShaderProgram> shader = m_Shader.lock();
	for (int i = 0; i < shader->m_Uniforms.size(); i++)
	{
		CreateEmptyValue(shader->m_Uniforms[i]);
	}

	m_ShaderName = shader->m_Name;
}

void harmony::ShaderDataContainer::SetContainerUniforms()
{
	uint8_t textureCount = 0;

	if (m_Vec4Values.size() > 0)
	{
		for (auto& [handle, value] : m_Vec4Values)
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
			bgfx::setTexture(textureCount, handle.BgfxHandle, value.BgfxHandle);
			textureCount++;
		}
	}
}

void harmony::ShaderDataContainer::Clear()
{
	m_Vec4Values.clear();
	m_Mat3Values.clear();
	m_Mat4Values.clear();
	m_TextureValues.clear();
}
bool harmony::ShaderDataContainer::ReturnIfNull()
{
	if (m_Shader.expired())
	{
		harmony::log::error("Shader for data container is expired!");
		return true;
	}
	return false;
}

void harmony::ShaderDataContainer::CreateEmptyValue(ShaderUniform& uniform)
{
	switch (uniform.Type)
	{
		case bgfx::UniformType::Vec4:	
			m_Vec4Values.emplace(uniform, glm::vec4(0.0));;
			break;
		case bgfx::UniformType::Mat3:
			m_Mat3Values.emplace(uniform, glm::mat3(1.0));;
			break;
		case bgfx::UniformType::Mat4:
			m_Mat4Values.emplace(uniform, glm::mat4(1.0));;
			break;
		case bgfx::UniformType::Sampler:
			m_TextureValues.emplace(uniform, BGFXTextureHandle());;
			break;
	}
}




