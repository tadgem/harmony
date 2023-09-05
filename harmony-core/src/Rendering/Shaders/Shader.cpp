#include <algorithm>
#include "Rendering/Shaders/Shader.h"

#include "Core/Log.hpp"
#include "Core/Utils.h"
#include "bgfx/platform.h"
#include <bx/readerwriter.h>
#include <bx/string.h>
#include <bx/commandline.h>
#include <optick.h>

harmony::ShaderProgram::ShaderProgram(const std::string &name) : m_Name(name), m_Handle(BGFX_INVALID_HANDLE)
{
	OPTICK_EVENT();
}

harmony::ShaderProgram::ShaderProgram() : m_Handle(BGFX_INVALID_HANDLE)
{
	OPTICK_EVENT();
}

bool harmony::ShaderProgram::AddStage(ShaderStage::Type stageType, WeakRef<ShaderStage> shader)
{
	OPTICK_EVENT();
	if (m_Stages.find(stageType) != m_Stages.end())
	{
		harmony::log::warn("Shader program already contains stage : %s",
						   ShaderStage::GetShaderStageNameFromEnum(stageType));
		return false;
	}

	m_Stages.emplace(stageType, shader);
	return true;
}

bool harmony::ShaderProgram::RemoveStage(ShaderStage::Type stageType)
{
	OPTICK_EVENT();
	if (m_Stages.find(stageType) != m_Stages.end())
	{
		m_Stages.erase(stageType);
		return true;
	}
	return false;
}

void harmony::ShaderProgram::Build()
{
	OPTICK_EVENT();
	GetUniforms();
	if (m_Stages.find(ShaderStage::Type::Compute) != m_Stages.end())
	{
		m_Handle = bgfx::createProgram(m_Stages[ShaderStage::Type::Compute].lock()->m_ProgramHandle, true);
	}

	if (m_Stages.find(ShaderStage::Type::Vertex) != m_Stages.end() &&
		m_Stages.find(ShaderStage::Type::Fragment) != m_Stages.end())
	{
		auto vertStage = m_Stages[ShaderStage::Type::Vertex].lock();
		auto fragStage = m_Stages[ShaderStage::Type::Fragment].lock();
		m_Handle = bgfx::createProgram(vertStage->m_ProgramHandle,fragStage->m_ProgramHandle, false);
	}
	if (m_Handle.idx == bgfx::kInvalidHandle)
	{
		harmony::log::error("Shader : {} : Failed to build!.", m_Name);
	}
}

void harmony::ShaderProgram::Destroy()
{
	OPTICK_EVENT();
	if (bgfx::isValid(m_Handle))
	{
		bgfx::destroy(m_Handle);
	}
}

void harmony::ShaderProgram::GetUniforms()
{
	OPTICK_EVENT();
	m_Uniforms.clear();
	for (auto [type, s]: m_Stages)
	{
		Ref<ShaderStage> stage = s.lock();
		bgfx::UniformHandle uniforms[64];
		uint16_t stageUniformCount = bgfx::getShaderUniforms(stage->m_ProgramHandle, &uniforms[0], 64);
		uint16_t samplerCount = 0;
		for (uint16_t i = 0; i < stageUniformCount; i++)
		{
			bgfx::UniformInfo info;
			bgfx::getUniformInfo(uniforms[i], info);

			ShaderUniform uniform;
			uniform.BgfxHandle = uniforms[i];
			uniform.Name = info.name;
			uniform.Type = info.type;
			uniform.ArraySize = info.num;

			if (std::find(m_Uniforms.begin(), m_Uniforms.end(), uniform) == m_Uniforms.end())
			{
				m_Uniforms.emplace_back(uniform);
			}

			if (uniform.Type == bgfx::UniformType::Vec4)
			{
				m_Vec4Values.emplace(uniform, glm::vec4(0.0f));
				continue;
			}

			if (uniform.Type == bgfx::UniformType::Mat3)
			{
				m_Mat3Values.emplace(uniform, glm::mat3(1.0f));
				continue;
			}

			if (uniform.Type == bgfx::UniformType::Mat4)
			{
				m_Mat4Values.emplace(uniform, glm::mat4(1.0f));
				continue;
			}

			if (uniform.Type == bgfx::UniformType::Sampler)
			{
				auto textureHandle = BGFXTextureHandle();
				textureHandle.SamplerSlot = samplerCount;
				samplerCount++;

				m_TextureValues.emplace(uniform, textureHandle);
				continue;
			}
		}
	}
}

void harmony::ShaderProgram::UpdateUniforms(AssetManager &am)
{
	OPTICK_EVENT();
	std::map<std::string, glm::vec4> vec4s;
	std::map<std::string, glm::mat3> mat3s;
	std::map<std::string, glm::mat4> mat4s;
	std::map<std::string, BGFXTextureHandle> textures;

	if (m_Vec4Values.size() > 0)
	{
		for (auto &[handle, value]: m_Vec4Values)
		{
			vec4s.emplace(handle.Name, value);
		}
	}

	if (m_Mat3Values.size() > 0)
	{
		for (auto &[handle, value]: m_Mat3Values)
		{
			mat3s.emplace(handle.Name, value);
		}
	}
	if (m_Mat4Values.size() > 0)
	{
		for (auto &[handle, value]: m_Mat4Values)
		{
			mat4s.emplace(handle.Name, value);
		}
	}

	if (m_TextureValues.size() > 0)
	{
		for (auto &[handle, value]: m_TextureValues)
		{
			textures.emplace(handle.Name, value);
		}
	}

	Clear();

	for (int i = 0; i < m_Uniforms.size(); i++)
	{
		UpdateUniform(m_Uniforms[i]);
	}

	if (m_Vec4Values.size() > 0)
	{
		for (auto &[handle, value]: m_Vec4Values)
		{
			if (vec4s.find(handle.Name) != vec4s.end())
			{
				value = vec4s[handle.Name];
			}
		}
	}

	if (m_Mat3Values.size() > 0)
	{
		for (auto &[handle, value]: m_Mat3Values)
		{
			if (mat3s.find(handle.Name) != mat3s.end())
			{
				value = mat3s[handle.Name];
			}
		}
	}
	if (m_Mat4Values.size() > 0)
	{
		for (auto &[handle, value]: m_Mat4Values)
		{
			if (mat4s.find(handle.Name) != mat4s.end())
			{
				value = mat4s[handle.Name];
			}
		}
	}

	if (m_TextureValues.size() > 0)
	{
		for (auto &[handle, value]: m_TextureValues)
		{
			if (textures.find(handle.Name) != textures.end())
			{
				value = textures[handle.Name];
				WeakRef<TextureAsset> texWr = am.GetAsset<TextureAsset>(value.Handle);

				if (texWr.expired())
				{
					continue;
				}
				Ref<TextureAsset> tex = texWr.lock();
				value = tex->m_TextureHandle;
			}
		}
	}
}

void harmony::ShaderProgram::AddUniformOverride(ShaderUniform &uniform)
{
	OPTICK_EVENT();
	if (std::find(m_ActiveUniformOverrides.begin(), m_ActiveUniformOverrides.end(), uniform) ==
		m_ActiveUniformOverrides.end())
	{
		m_ActiveUniformOverrides.emplace_back(uniform);
		return;
	}
	harmony::log::warn("ShaderProgram : Uniform {} already marked as overriden for this shader.", uniform.Name);
}

void harmony::ShaderProgram::RemoveUniformOverride(ShaderUniform &uniform)
{
	OPTICK_EVENT();
	auto it = std::find(m_ActiveUniformOverrides.begin(), m_ActiveUniformOverrides.end(), uniform);
	if (it == m_ActiveUniformOverrides.end())
	{
		harmony::log::warn("ShaderProgram : Uniform {} not marked as overriden for this shader.", uniform.Name);
		return;
	}
	m_ActiveUniformOverrides.erase(it);
}

void harmony::ShaderProgram::SetUniforms()
{
	OPTICK_EVENT();
	if (m_Vec4Values.size() > 0)
	{
		for (auto &[handle, value]: m_Vec4Values)
		{
			if (IsOverridenUniform(handle))
			{
				continue;
			}
			bgfx::setUniform(handle.BgfxHandle, &value[0]);
		}
	}

	if (m_Mat3Values.size() > 0)
	{
		for (auto &[handle, value]: m_Mat3Values)
		{
			if (IsOverridenUniform(handle))
			{
				continue;
			}
			bgfx::setUniform(handle.BgfxHandle, &value[0]);
		}
	}
	if (m_Mat4Values.size() > 0)
	{
		for (auto &[handle, value]: m_Mat4Values)
		{
			if (IsOverridenUniform(handle))
			{
				continue;
			}
			bgfx::setUniform(handle.BgfxHandle, &value[0]);
		}
	}

	if (m_TextureValues.size() > 0)
	{
		for (auto &[handle, value]: m_TextureValues)
		{
			if (IsOverridenUniform(handle))
			{
				continue;
			}
			bgfx::setTexture(value.SamplerSlot, handle.BgfxHandle, value.BgfxHandle);
		}
	}
}

void harmony::ShaderProgram::Clear()
{
	OPTICK_EVENT();
	m_Vec4Values.clear();
	m_Mat3Values.clear();
	m_Mat4Values.clear();
	m_TextureValues.clear();
}

void harmony::ShaderProgram::UpdateUniform(ShaderUniform &uniform)
{
	OPTICK_EVENT();
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

bool harmony::ShaderProgram::IsOverridenUniform(const ShaderUniform &uniform)
{
	OPTICK_EVENT();
	return std::find
				   (
						   m_ActiveUniformOverrides.begin(),
						   m_ActiveUniformOverrides.end(),
						   uniform
				   ) != m_ActiveUniformOverrides.end();
}

harmony::ShaderStage::ShaderStage(const std::string &name, const Type &shaderType)
		: Asset(AssetHandle{name, 0, GET_TYPE_HASH(ShaderStage)}), m_Type(shaderType),
		  m_ProgramHandle(BGFX_INVALID_HANDLE), m_Name(name)
{
	OPTICK_EVENT();
	m_BinaryPath = "assets/" + GetShaderRendererDirectory() + name + ".bin";
    m_BinaryPath = Utils::GetCleanPlatformPath(m_BinaryPath);
}

harmony::ShaderStage::ShaderStage() : Asset()
{
	OPTICK_EVENT();
}

harmony::ShaderStage::~ShaderStage()
{
	OPTICK_EVENT();
}

void harmony::ShaderStage::LoadShaderBinary()
{
	OPTICK_EVENT();
	if (bx::open(&_reader, m_BinaryPath.c_str()))
	{
		uint32_t size = static_cast<uint32_t>(bx::getSize(&_reader));
		const bgfx::Memory *mem = bgfx::alloc(size + 1);
		bx::read(&_reader, mem->data, size, bx::ErrorAssert{});
		bx::close(&_reader);
		m_ProgramHandle = bgfx::createShader(mem);
		bgfx::setName(m_ProgramHandle, m_Name.c_str());
	}
	else
	{
		harmony::log::error("Shader : {} : Failed to load shader binary at path : {}", m_Name, m_BinaryPath);
	}
}

std::string harmony::ShaderStage::GetShaderStageNameFromEnum(Type type)
{
	OPTICK_EVENT();
	std::string typeName = "";

	switch (type)
	{
		case Type::Vertex:
			typeName = "Vertex";
			break;
		case Type::Fragment:
			typeName = "Fragment";
			break;
		case Type::Compute:
			typeName = "Compute";
			break;
	}

	return typeName;
}

std::string harmony::ShaderStage::GetShaderRendererDirectory()
{
	OPTICK_EVENT();
	std::string shaderPath = "shaders/bin/" + GetShaderRendererName() + "/";
	return shaderPath;
}

std::string harmony::ShaderStage::GetShaderRendererName()
{
	OPTICK_EVENT();
	std::string shaderPath = "";

	switch (bgfx::getRendererType())
	{
		case bgfx::RendererType::Noop:
		case bgfx::RendererType::Direct3D9:
			shaderPath += "dx9";
			break;
		case bgfx::RendererType::Direct3D11:
		case bgfx::RendererType::Direct3D12:
			shaderPath += "dx11";
			break;
		case bgfx::RendererType::Agc:
		case bgfx::RendererType::Gnm:
			shaderPath += "pssl";
			break;
		case bgfx::RendererType::Metal:
			shaderPath += "metal";
			break;
		case bgfx::RendererType::OpenGL:
			shaderPath += "glsl";
			break;
		case bgfx::RendererType::OpenGLES:
			shaderPath += "essl";
			break;
		case bgfx::RendererType::Vulkan:
			shaderPath += "spirv";
			break;
		case bgfx::RendererType::WebGPU:
			shaderPath += "spirv";
			break;

		case bgfx::RendererType::Count:
			harmony::log::error("You should not be here!");
			break;
	}

	return shaderPath;
}

harmony::BuiltInShaderStage::BuiltInShaderStage(
		const std::string &name,
		const Type &shaderType,
		bgfx::EmbeddedShader embeddedShader) : ShaderStage(name, shaderType), p_EmbeddedShader(embeddedShader)
{
	OPTICK_EVENT();
}

void harmony::BuiltInShaderStage::LoadShaderBinary()
{
	OPTICK_EVENT();
	bgfx::RendererType::Enum type = bgfx::getRendererType();
	m_ProgramHandle = bgfx::createEmbeddedShader(&p_EmbeddedShader, type, m_Name.c_str());
	bgfx::setName(m_ProgramHandle, m_Name.c_str());
}

bool harmony::ShaderUniform::Valid()
{
	OPTICK_EVENT();
	return BgfxHandle.idx != UINT16_MAX;
}
