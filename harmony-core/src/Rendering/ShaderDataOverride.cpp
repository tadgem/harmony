#include "Rendering/ShaderDataOverride.h"
harmony::ShaderDataOverride::ShaderDataOverride()
{
}

void harmony::ShaderDataOverride::AddVec4Override(ShaderUniform uniform, glm::vec4 value)
{
	if (m_Vec4Overrides.find(uniform) != m_Vec4Overrides.end())
	{
		harmony::log::warn("ShaderDataOverride : {} : Already contains uniform : {}", m_ShaderName, uniform.Name);
		return;
	}

	m_Vec4Overrides.emplace(uniform, value);
}

void harmony::ShaderDataOverride::AddMat3Override(ShaderUniform uniform, glm::mat3 value)
{
	if (m_Mat3Overrides.find(uniform) != m_Mat3Overrides.end())
	{
		harmony::log::warn("ShaderDataOverride : {} : Already contains uniform : {}", m_ShaderName, uniform.Name);
		return;
	}

	m_Mat3Overrides.emplace(uniform, value);
}

void harmony::ShaderDataOverride::AddMat4Override(ShaderUniform uniform, glm::mat4 value)
{
	if (m_Mat4Overrides.find(uniform) != m_Mat4Overrides.end())
	{
		harmony::log::warn("ShaderDataOverride : {} : Already contains uniform : {}", m_ShaderName, uniform.Name);
		return;
	}

	m_Mat4Overrides.emplace(uniform, value);
}

void harmony::ShaderDataOverride::AddTextureOverride(ShaderUniform uniform, BGFXTextureHandle value)
{
	if (m_TextureOverrides.find(uniform) != m_TextureOverrides.end())
	{
		harmony::log::warn("ShaderDataOverride : {} : Already contains uniform : {}", m_ShaderName, uniform.Name);
		return;
	}

	m_TextureOverrides.emplace(uniform, value);
}

void harmony::ShaderDataOverride::UpdateOverrides(WeakRef<ShaderProgram> shaderWr, AssetManager& am)
{
	std::map<std::string, glm::vec4> vec4s;
	std::map<std::string, glm::mat3> mat3s;
	std::map<std::string, glm::mat4> mat4s;
	std::map<std::string, BGFXTextureHandle> textures;

	Ref<ShaderProgram> shader = shaderWr.lock();

	m_AvailableOverrides.clear();
	for (int i = 0; i < shader->m_Uniforms.size(); i++)
	{
		m_AvailableOverrides.emplace_back(shader->m_Uniforms[i]);
	}

	if (m_Vec4Overrides.size() > 0)
	{
		for (auto& [handle, value] : m_Vec4Overrides)
		{
			vec4s.emplace(handle.Name, value);
		}
	}

	if (m_Mat3Overrides.size() > 0)
	{
		for (auto& [handle, value] : m_Mat3Overrides)
		{
			mat3s.emplace(handle.Name, value);
		}
	}

	if (m_Mat4Overrides.size() > 0)
	{
		for (auto& [handle, value] : m_Mat4Overrides)
		{
			mat4s.emplace(handle.Name, value);
		}
	}

	if (m_TextureOverrides.size() > 0)
	{
		for (auto& [handle, value] : m_TextureOverrides)
		{
			textures.emplace(handle.Name, value);
		}
	}

	Clear();

	for (auto& [uniformName, val] : vec4s)
	{
		for (int i = 0; i < m_AvailableOverrides.size(); i++)
		{
			if (m_AvailableOverrides[i].Name == uniformName)
			{
				m_Vec4Overrides.emplace(m_AvailableOverrides[i], val);
				shader->AddUniformOverride(m_AvailableOverrides[i]);
				break;
			}
		}
	}

	for (auto& [uniformName, val] : mat3s)
	{
		for (int i = 0; i < m_AvailableOverrides.size(); i++)
		{
			if (m_AvailableOverrides[i].Name == uniformName)
			{
				m_Mat3Overrides.emplace(m_AvailableOverrides[i], val);
				shader->AddUniformOverride(m_AvailableOverrides[i]);
				break;
			}
		}
	}

	for (auto& [uniformName, val] : mat4s)
	{
		for (int i = 0; i < m_AvailableOverrides.size(); i++)
		{
			if (m_AvailableOverrides[i].Name == uniformName)
			{
				m_Mat4Overrides.emplace(m_AvailableOverrides[i], val);
				shader->AddUniformOverride(m_AvailableOverrides[i]);
				break;
			}
		}
	}

	for (auto& [uniformName, val] : textures)
	{
		for (int i = 0; i < m_AvailableOverrides.size(); i++)
		{
			if (m_AvailableOverrides[i].Name == uniformName)
			{
				m_TextureOverrides.emplace(m_AvailableOverrides[i], val);
				shader->AddUniformOverride(m_AvailableOverrides[i]);
				break;
			}
		}
	}
}

void harmony::ShaderDataOverride::SetOverrides()
{
	if (m_Vec4Overrides.size() > 0)
	{
		for (auto& [handle, value] : m_Vec4Overrides)
		{
			bgfx::setUniform(handle.BgfxHandle, &value[0]);
		}
	}

	if (m_Mat3Overrides.size() > 0)
	{
		for (auto& [handle, value] : m_Mat3Overrides)
		{
			bgfx::setUniform(handle.BgfxHandle, &value[0]);
		}
	}

	if (m_Mat4Overrides.size() > 0)
	{
		for (auto& [handle, value] : m_Mat4Overrides)
		{
			bgfx::setUniform(handle.BgfxHandle, &value[0]);
		}
	}

	if (m_TextureOverrides.size() > 0)
	{
		for (auto& [handle, value] : m_TextureOverrides)
		{
			bgfx::setTexture(value.SamplerSlot, handle.BgfxHandle, value.BgfxHandle);
		}
	}
}

void harmony::ShaderDataOverride::Clear()
{
	m_Vec4Overrides.clear();
	m_Mat3Overrides.clear();
	m_Mat4Overrides.clear();
	m_TextureOverrides.clear();
}

void harmony::ShaderDataOverride::UpdateUniform(ShaderUniform& uniform)
{
	bool exists = false;
	switch (uniform.Type)
	{
	case bgfx::UniformType::Vec4:
		m_Vec4Overrides.emplace(uniform, glm::vec4(0.0));;
		break;
	case bgfx::UniformType::Mat3:
		m_Mat3Overrides.emplace(uniform, glm::mat3(1.0));;
		break;
	case bgfx::UniformType::Mat4:
		m_Mat4Overrides.emplace(uniform, glm::mat4(1.0));;
		break;
	case bgfx::UniformType::Sampler:
		m_TextureOverrides.emplace(uniform, BGFXTextureHandle());;
		break;
	}
}
