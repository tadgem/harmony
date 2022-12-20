#include "Rendering/ShaderDataContainer.h"
#include "Core/Log.hpp"
#include "Rendering/Renderer.h"
#if HARMONY_DEBUG
#include "ImGui/imgui.h";
#endif
harmony::ShaderDataContainer::ShaderDataContainer()
{
}
harmony::ShaderDataContainer::ShaderDataContainer(WeakRef<ShaderProgram> shaderProgram) : m_Shader(shaderProgram)
{
}

void harmony::ShaderDataContainer::UpdateShader(WeakRef<ShaderProgram> newShader, AssetManager& am)
{
	p_ShaderUniformCount = 0;
	m_Shader = newShader;

	if (m_Shader.expired())
	{
		harmony::log::error("Shader for data container is expired!");
		return;
	}

	UpdateContainer(am);
}

void harmony::ShaderDataContainer::UpdateContainer(AssetManager& am)
{
	std::map<std::string, glm::vec4> vec4s;
	std::map<std::string, glm::mat3> mat3s;
	std::map<std::string, glm::mat4> mat4s;
	std::map<std::string, BGFXTextureHandle> textures;

	if (m_Vec4Values.size() > 0)
	{
		for (auto& [handle, value] : m_Vec4Values)
		{
			vec4s.emplace(handle.Name, value);
		}
	}

	if (m_Mat3Values.size() > 0)
	{
		for (auto& [handle, value] : m_Mat3Values)
		{
			mat3s.emplace(handle.Name, value);
		}
	}
	if (m_Mat4Values.size() > 0)
	{
		for (auto& [handle, value] : m_Mat4Values)
		{
			mat4s.emplace(handle.Name, value);
		}
	}

	if (m_TextureValues.size() > 0)
	{
		for (auto& [handle, value] : m_TextureValues)
		{
			textures.emplace(handle.Name, value);
		}
	}

	Clear();

	Ref<ShaderProgram> shader = m_Shader.lock();
	for (int i = 0; i < shader->m_Uniforms.size(); i++)
	{
		UpdateUniform(shader->m_Uniforms[i]);
	}

	if (m_Vec4Values.size() > 0)
	{
		for (auto& [handle, value] : m_Vec4Values)
		{
			if (vec4s.find(handle.Name) != vec4s.end())
			{
				value = vec4s[handle.Name];
			}
		}
	}

	if (m_Mat3Values.size() > 0)
	{
		for (auto& [handle, value] : m_Mat3Values)
		{
			if (mat3s.find(handle.Name) != mat3s.end())
			{
				value = mat3s[handle.Name];
			}
		}
	}
	if (m_Mat4Values.size() > 0)
	{
		for (auto& [handle, value] : m_Mat4Values)
		{
			if (mat4s.find(handle.Name) != mat4s.end())
			{
				value = mat4s[handle.Name];
			}
		}
	}

	if (m_TextureValues.size() > 0)
	{
		for (auto& [handle, value] : m_TextureValues)
		{
			if (textures.find(handle.Name) != textures.end())
			{
				value = textures[handle.Name];
				WeakRef<Texture> texWr = am.GetAsset<Texture>(value.Handle);

				if (texWr.expired())
				{
					continue;
				}
				Ref<Texture> tex = texWr.lock();
				value = tex->m_TextureHandle;
			}
		}
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

void harmony::ShaderDataContainer::UpdateUniform(ShaderUniform& uniform)
{
	bool exists = false;
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