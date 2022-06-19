#include "Rendering/ShaderDataContainer.h"
#include "Core/Log.hpp"
harmony::ShaderDataContainer::ShaderDataContainer(WeakRef<ShaderProgram> shaderProgram)
{
	UpdateShader(shaderProgram);
}

void harmony::ShaderDataContainer::AddValue(const std::string name, WeakRef<float> value)
{
	if (ReturnIfNull()) return;
	
	ShaderUniform uniform = GetShaderUniform<float>(name);

	if (uniform.BgfxHandle.idx == bgfx::kInvalidHandle)
	{
		harmony::log::error("Failed to find float uniform with name {0} in shader {1}", name, p_Shader.lock()->m_Name);
		return;
	}

	harmony::log::info("Adding shader value : float : {}", name);
	p_FloatValues.emplace(uniform.BgfxHandle.idx, value);
	m_Uniforms.emplace_back(uniform);
	
}

void harmony::ShaderDataContainer::AddValue(const std::string name, WeakRef<glm::vec2> value)
{
	if (ReturnIfNull()) return;

	ShaderUniform uniform = GetShaderUniform<glm::vec2>(name);

	if (uniform.BgfxHandle.idx == bgfx::kInvalidHandle)
	{
		harmony::log::error("Failed to find vec2 uniform with name {0} in shader {1}", name, p_Shader.lock()->m_Name);
		return;
	}

	harmony::log::info("Adding shader value : vec2 : {}", name);
	p_Vec2Values.emplace(uniform.BgfxHandle.idx, value);
	m_Uniforms.emplace_back(uniform);
}

void harmony::ShaderDataContainer::AddValue(const std::string name, WeakRef<glm::vec3> value)
{
	if (ReturnIfNull()) return;

	ShaderUniform uniform = GetShaderUniform<glm::vec3>(name);

	if (uniform.BgfxHandle.idx == bgfx::kInvalidHandle)
	{
		harmony::log::error("Failed to find vec3 uniform with name {0} in shader {1}", name, p_Shader.lock()->m_Name);
		return;
	}

	harmony::log::info("Adding shader value : vec3 : {}", name);
	p_Vec3Values.emplace(uniform.BgfxHandle.idx, value);
	m_Uniforms.emplace_back(uniform);
}

void harmony::ShaderDataContainer::AddValue(const std::string name, WeakRef<glm::mat3> value)
{
	if (ReturnIfNull()) return;

	ShaderUniform uniform = GetShaderUniform<glm::mat3>(name);

	if (uniform.BgfxHandle.idx == bgfx::kInvalidHandle)
	{
		harmony::log::error("Failed to find mat3 uniform with name {0} in shader {1}", name, p_Shader.lock()->m_Name);
		return;
	}

	harmony::log::info("Adding shader value : mat3 : {}", name);
	p_Mat3Values.emplace(uniform.BgfxHandle.idx, value);
	m_Uniforms.emplace_back(uniform);
}

void harmony::ShaderDataContainer::AddValue(const std::string name, WeakRef<glm::mat4> value)
{
	if (ReturnIfNull()) return;

	ShaderUniform uniform = GetShaderUniform<glm::mat4>(name);

	if (uniform.BgfxHandle.idx == bgfx::kInvalidHandle)
	{
		harmony::log::error("Failed to find mat4 uniform with name {0} in shader {1}", name, p_Shader.lock()->m_Name);
		return;
	}
	harmony::log::info("Adding shader value : mat4 : {}", name);
	p_Mat4Values.emplace(uniform.BgfxHandle.idx, value);
	m_Uniforms.emplace_back(uniform);
}


void harmony::ShaderDataContainer::AddValue(const std::string name, WeakRef<BGFXTextureHandle> value)
{
	if (ReturnIfNull()) return;

	ShaderUniform uniform = GetShaderUniform<BGFXTextureHandle>(name);

	if (uniform.BgfxHandle.idx == bgfx::kInvalidHandle)
	{
		harmony::log::error("Failed to find texture uniform with name {0} in shader {1}", name, p_Shader.lock()->m_Name);
		return;
	}
	harmony::log::info("Adding shader value : texture : {}", name);
	p_TextureValues.emplace(uniform.BgfxHandle.idx, value);
	m_Uniforms.emplace_back(uniform);
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

	if (p_FloatValues.size() > 0)
	{
		for (auto& [handleIndex, valueWeakRef] : p_FloatValues)
		{
			bgfx::UniformHandle handle{ handleIndex };
			bgfx::setUniform(handle, valueWeakRef.lock().get());
		}
	}

	if (p_Vec2Values.size() > 0)
	{
		for (auto& [handleIndex, valueWeakRef] : p_Vec2Values)
		{
			bgfx::UniformHandle handle{ handleIndex };
			bgfx::setUniform(handle, valueWeakRef.lock().get());
		}
	}

	if (p_Vec3Values.size() > 0)
	{
		for (auto& [handleIndex, valueWeakRef] : p_Vec3Values)
		{
			bgfx::UniformHandle handle{ handleIndex };
			bgfx::setUniform(handle, valueWeakRef.lock().get());
		}
	}

	if (p_Mat3Values.size() > 0)
	{
		for (auto& [handleIndex, valueWeakRef] : p_Mat3Values)
		{
			bgfx::UniformHandle handle{ handleIndex };
			bgfx::setUniform(handle, valueWeakRef.lock().get());
		}
	}
	if (p_Mat4Values.size() > 0)
	{
		for (auto& [handleIndex, valueWeakRef] : p_Mat4Values)
		{
			bgfx::UniformHandle handle{ handleIndex };
			bgfx::setUniform(handle, valueWeakRef.lock().get());
		}
	}

	if (p_TextureValues.size() > 0)
	{
		for (auto& [handleIndex, valueWeakRef] : p_TextureValues)
		{
			bgfx::UniformHandle handle{ handleIndex };
			Ref<BGFXTextureHandle> textureHandle = valueWeakRef.lock();
			bgfx::setTexture(textureCount, handle, textureHandle->Handle);
			textureCount++;
		}
	}
}

void harmony::ShaderDataContainer::Clear()
{
	m_UniformInfos.clear();
	m_UniformHandles.clear();
	m_Uniforms.clear();

	p_FloatValues.clear();
	p_Vec2Values.clear();
	p_Vec3Values.clear();
	p_Mat3Values.clear();
	p_Mat4Values.clear();
	p_TextureValues.clear();
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




