#include "Rendering/ShaderDataContainer.h"
#include "Core/Log.hpp"
#if HARMONY_DEBUG
#include "ImGui/imgui.h";
#endif
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

			CreateEmptyValue(info, uniforms[i]);
		}
	}
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
			bgfx::setTexture(textureCount, handle.BgfxHandle, value.Handle);
			textureCount++;
		}
	}
}

void harmony::ShaderDataContainer::Clear()
{
	m_UniformInfos.clear();
	m_UniformHandles.clear();

	m_Vec4Values.clear();
	m_Mat3Values.clear();
	m_Mat4Values.clear();
	m_TextureValues.clear();
}
#if HARMONY_DEBUG
void harmony::ShaderDataContainer::OnImGui()
{
}
#endif

bool harmony::ShaderDataContainer::ReturnIfNull()
{
	if (m_Shader.expired())
	{
		harmony::log::error("Shader for data container is expired!");
		return true;
	}
	return false;
}

void harmony::ShaderDataContainer::CreateEmptyValue(bgfx::UniformInfo info, bgfx::UniformHandle handle)
{
	ShaderUniform uniform;
	uniform.Name = std::string(info.name);
	uniform.BgfxHandle = handle;

	switch (info.type)
	{
		case bgfx::UniformType::Vec4:
			uniform.TypeHash = GetTypeHash<glm::vec4>();			
			m_Vec4Values.emplace(uniform, glm::vec4(0.0));;
			break;
		case bgfx::UniformType::Mat3:
			uniform.TypeHash = GetTypeHash<glm::mat3>();
			m_Mat3Values.emplace(uniform, glm::mat3(1.0));;
			break;
		case bgfx::UniformType::Mat4:
			uniform.TypeHash = GetTypeHash<glm::mat4>();
			m_Mat4Values.emplace(uniform, glm::mat4(1.0));;
			break;
		case bgfx::UniformType::Sampler:
			uniform.TypeHash = GetTypeHash<BGFXTextureHandle>();
			m_TextureValues.emplace(uniform, BGFXTextureHandle());;
			break;
	}
}



