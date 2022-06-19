#include "Rendering/ShaderDataContainer.h"
#include "Core/Log.hpp"
harmony::ShaderDataContainer::ShaderDataContainer(WeakRef<ShaderProgram> shaderProgram) : p_Shader(shaderProgram)
{
	p_ShaderUniformCount = 0;
	if (p_Shader.expired())
	{
		harmony::log::error("Shader for data container is expired!");
	}

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
		}
	}
}

void harmony::ShaderDataContainer::AddValue(const std::string name, WeakRef<float> value)
{
	if (ReturnIfNull) return;
	
	ShaderUniform uniform = GetShaderUniform<float>(name);

	if (uniform.BgfxHandle.idx == bgfx::kInvalidHandle)
	{
		harmony::log::error("Failed to find float uniform with name {0} in shader {1}", name, p_Shader.lock()->m_Name);
		return;
	}

	harmony::log::info("Adding shader value : float : {}", name);
	p_FloatValues.emplace(uniform, value);
	
}

void harmony::ShaderDataContainer::AddValue(const std::string name, WeakRef<glm::vec2> value)
{
	if (ReturnIfNull) return;

	ShaderUniform uniform = GetShaderUniform<glm::vec2>(name);

	if (uniform.BgfxHandle.idx == bgfx::kInvalidHandle)
	{
		harmony::log::error("Failed to find vec2 uniform with name {0} in shader {1}", name, p_Shader.lock()->m_Name);
		return;
	}

	harmony::log::info("Adding shader value : vec2 : {}", name);
	p_Vec2Values.emplace(uniform, value);
}

void harmony::ShaderDataContainer::AddValue(const std::string name, WeakRef<glm::vec3> value)
{
	if (ReturnIfNull) return;

	ShaderUniform uniform = GetShaderUniform<glm::vec3>(name);

	if (uniform.BgfxHandle.idx == bgfx::kInvalidHandle)
	{
		harmony::log::error("Failed to find vec3 uniform with name {0} in shader {1}", name, p_Shader.lock()->m_Name);
		return;
	}

	harmony::log::info("Adding shader value : vec3 : {}", name);
	p_Vec3Values.emplace(uniform, value);
}

void harmony::ShaderDataContainer::AddValue(const std::string name, WeakRef<glm::mat3> value)
{
	if (ReturnIfNull) return;

	ShaderUniform uniform = GetShaderUniform<glm::mat3>(name);

	if (uniform.BgfxHandle.idx == bgfx::kInvalidHandle)
	{
		harmony::log::error("Failed to find mat3 uniform with name {0} in shader {1}", name, p_Shader.lock()->m_Name);
		return;
	}

	harmony::log::info("Adding shader value : mat3 : {}", name);
	p_Mat3Values.emplace(uniform, value);
}

void harmony::ShaderDataContainer::AddValue(const std::string name, WeakRef<glm::mat4> value)
{
	if (ReturnIfNull) return;

	ShaderUniform uniform = GetShaderUniform<glm::mat4>(name);

	if (uniform.BgfxHandle.idx == bgfx::kInvalidHandle)
	{
		harmony::log::error("Failed to find mat4 uniform with name {0} in shader {1}", name, p_Shader.lock()->m_Name);
		return;
	}
	harmony::log::info("Adding shader value : mat4 : {}", name);
	p_Mat4Values.emplace(uniform, value);
}


void harmony::ShaderDataContainer::AddValue(const std::string name, WeakRef<BGFXTextureHandle> value)
{
	if (ReturnIfNull) return;

	ShaderUniform uniform = GetShaderUniform<BGFXTextureHandle>(name);

	if (uniform.BgfxHandle.idx == bgfx::kInvalidHandle)
	{
		harmony::log::error("Failed to find texture uniform with name {0} in shader {1}", name, p_Shader.lock()->m_Name);
		return;
	}
	harmony::log::info("Adding shader value : texture : {}", name);
	p_TextureValues.emplace(uniform, value);
}

void harmony::ShaderDataContainer::SetContainerUniforms()
{
	uint8_t textureCount = 0;

	if (p_FloatValues.size() > 0)
	{
		for (auto& [handle, valueWeakRef] : p_FloatValues)
		{
			bgfx::setUniform(handle.BgfxHandle, valueWeakRef.lock().get());
		}
	}

	if (p_Vec2Values.size() > 0)
	{
		for (auto& [handle, valueWeakRef] : p_Vec2Values)
		{
			bgfx::setUniform(handle.BgfxHandle, valueWeakRef.lock().get());
		}
	}

	if (p_Vec3Values.size() > 0)
	{
		for (auto& [handle, valueWeakRef] : p_Vec3Values)
		{
			bgfx::setUniform(handle.BgfxHandle, valueWeakRef.lock().get());
		}
	}

	if (p_Mat3Values.size() > 0)
	{
		for (auto& [handle, valueWeakRef] : p_Mat3Values)
		{
			bgfx::setUniform(handle.BgfxHandle, valueWeakRef.lock().get());
		}
	}
	if (p_Mat4Values.size() > 0)
	{
		for (auto& [handle, valueWeakRef] : p_Mat4Values)
		{
			bgfx::setUniform(handle.BgfxHandle, valueWeakRef.lock().get());
		}
	}

	if (p_TextureValues.size() > 0)
	{
		for (auto& [handle, valueWeakRef] : p_TextureValues)
		{
		}
	}
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




