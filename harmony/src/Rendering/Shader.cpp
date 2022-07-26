#include "Rendering/Shader.h"
#include "Core/Profile.hpp"
#include "Core/Log.hpp"
#include "Core/Utils.h"
#include "bgfx/platform.h"
#include <bx/readerwriter.h>
#include <bx/string.h>
#include <bx/commandline.h>

harmony::ShaderProgram::ShaderProgram(const std::string& name) : m_Name(name), m_Handle(BGFX_INVALID_HANDLE)
{
}

harmony::ShaderProgram::ShaderProgram() : m_Handle(BGFX_INVALID_HANDLE)
{
}

bool harmony::ShaderProgram::AddStage(ShaderStage::Type stageType, WeakRef<ShaderStage> shader)
{
	if (m_Stages.find(stageType) != m_Stages.end())
	{
		harmony::log::warn("Shader program already contains stage : %s", ShaderStage::GetShaderStageNameFromEnum(stageType));
		return false;
	}

	m_Stages.emplace(stageType, shader);
	return true;
}

bool harmony::ShaderProgram::RemoveStage(ShaderStage::Type stageType)
{
	if (m_Stages.find(stageType) != m_Stages.end())
	{
		m_Stages.erase(stageType);
		return true;
	}
	return false;
}

void harmony::ShaderProgram::Build()
{
	GetUniforms();
	if (m_Stages.find(ShaderStage::Type::Compute) != m_Stages.end())
	{
		m_Handle = bgfx::createProgram(m_Stages[ShaderStage::Type::Compute].lock()->m_ProgramHandle, true);
		return;
	}

	if (m_Stages.find(ShaderStage::Type::Vertex) != m_Stages.end() && 
		m_Stages.find(ShaderStage::Type::Fragment) != m_Stages.end())
	{
		m_Handle = bgfx::createProgram(m_Stages[ShaderStage::Type::Vertex].lock()->m_ProgramHandle, m_Stages[ShaderStage::Type::Fragment].lock()->m_ProgramHandle, true);
		return;
	}

	harmony::log::error("Failed to build shader! invalid combination provided.");
}

void harmony::ShaderProgram::Destroy()
{
	bgfx::destroy(m_Handle);
}

void harmony::ShaderProgram::GetUniforms()
{
	for (auto [type, s] : m_Stages)
	{
		Ref<ShaderStage> stage = s.lock();
		bgfx::UniformHandle uniforms[g_MaxUniforms];
		uint16_t stageUniformCount = bgfx::getShaderUniforms(stage->m_ProgramHandle, &uniforms[0], g_MaxUniforms);

		for (uint16_t i = 0; i < stageUniformCount; i++)
		{
			bgfx::UniformInfo info;
			bgfx::getUniformInfo(uniforms[i], info);

			ShaderUniform uniform;
			uniform.BgfxHandle = uniforms[i];
			uniform.Name = info.name;
			uniform.Type = info.type;
			uniform.ArraySize = info.num;
			m_Uniforms.emplace_back(uniform);
		}
	}
}

harmony::ShaderStage::ShaderStage(const std::string& name, const Type& shaderType) 
	: Asset(AssetHandle { name, 0, GetTypeHash<ShaderStage>()}), m_Type(shaderType), m_ProgramHandle(BGFX_INVALID_HANDLE), m_Name(name)
{
	m_BinaryPath = "assets/" + GetShaderRendererDirectory() + name + ".bin";
}

harmony::ShaderStage::ShaderStage() : Asset()
{
}

harmony::ShaderStage::~ShaderStage()
{
}


void harmony::ShaderStage::LoadShaderBinary()
{
	if (m_ProgramHandle.idx != UINT16_MAX)
	{
		bgfx::destroy(m_ProgramHandle);
	}

	if (bx::open(&_reader, m_BinaryPath.c_str()))
	{
		uint32_t size = static_cast<uint32_t>(bx::getSize(&_reader));
		const bgfx::Memory* mem = bgfx::alloc(size + 1);
		bx::read(&_reader, mem->data, size, bx::ErrorAssert{});
		bx::close(&_reader);
		m_ProgramHandle = bgfx::createShader(mem);
		bgfx::setName(m_ProgramHandle, m_Name.c_str());
	}
	else
	{
		harmony::log::error("Failed to load shader binary at path : ", m_BinaryPath);
	}
}

std::string harmony::ShaderStage::GetShaderStageNameFromEnum(Type type)
{
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
			typeName ="Compute";
			break;
	}

	return typeName;
}

std::string harmony::ShaderStage::GetShaderRendererDirectory()
{
	std::string shaderPath = "shaders/bin/";

	switch (bgfx::getRendererType())
	{
	case bgfx::RendererType::Noop:
	case bgfx::RendererType::Direct3D9:  shaderPath += "dx9/";   break;
	case bgfx::RendererType::Direct3D11:
	case bgfx::RendererType::Direct3D12: shaderPath += "dx11/";  break;
	case bgfx::RendererType::Agc:
	case bgfx::RendererType::Gnm:        shaderPath += "pssl/";  break;
	case bgfx::RendererType::Metal:      shaderPath += "metal/"; break;
	case bgfx::RendererType::OpenGL:     shaderPath += "glsl/";  break;
	case bgfx::RendererType::OpenGLES:   shaderPath += "essl/";  break;
	case bgfx::RendererType::Vulkan:     shaderPath += "spirv/"; break;
	case bgfx::RendererType::WebGPU:     shaderPath += "spirv/"; break;

	case bgfx::RendererType::Count:
		harmony::log::error("You should not be here!");
		break;
	}

	return shaderPath;
}

harmony::BuiltInShaderStage::BuiltInShaderStage(
	const std::string& name, 
	const Type& shaderType, 
	bgfx::EmbeddedShader embeddedShader) : ShaderStage(name, shaderType), p_EmbeddedShader(embeddedShader)
{
}

void harmony::BuiltInShaderStage::LoadShaderBinary()
{
	bgfx::RendererType::Enum type = bgfx::getRendererType();
	m_ProgramHandle = bgfx::createEmbeddedShader(&p_EmbeddedShader,type, m_Name.c_str());
	bgfx::setName(m_ProgramHandle, m_Name.c_str());
}

bool harmony::ShaderUniform::Valid()
{
	return BgfxHandle.idx != UINT16_MAX;
}
