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
	if (m_Stages.find(ShaderStage::Type::Compute) != m_Stages.end())
	{
		m_Handle = bgfx::createProgram(m_Stages[ShaderStage::Type::Compute].lock()->m_Handle, false);
		return;
	}

	if (m_Stages.find(ShaderStage::Type::Vertex) != m_Stages.end() && 
		m_Stages.find(ShaderStage::Type::Fragment) != m_Stages.end())
	{
		m_Handle = bgfx::createProgram(m_Stages[ShaderStage::Type::Vertex].lock()->m_Handle, m_Stages[ShaderStage::Type::Fragment].lock()->m_Handle, false);
		return;
	}

	harmony::log::error("Failed to build shader! invalid combination provided.");
}

harmony::ShaderStage::ShaderStage(const std::string& name, const Type& shaderType) : Asset(AssetHandle {name, 0, GetTypeHash<ShaderStage>()}), m_Type(shaderType), m_Handle(BGFX_INVALID_HANDLE), m_Name(name)
{
}

harmony::ShaderStage::ShaderStage() : Asset()
{
}

harmony::ShaderStage::~ShaderStage()
{
}

void harmony::ShaderStage::LoadShaderBinary()
{
	std::string binaryPath = GetShaderRendererDirectory() + m_Name + ".bin";

	if (bx::open(&_reader, binaryPath.c_str()))
	{
		uint32_t size = static_cast<uint32_t>(bx::getSize(&_reader));
		const bgfx::Memory* mem = bgfx::alloc(size + 1);
		bx::read(&_reader, mem->data, size, bx::ErrorAssert{});
		bx::close(&_reader);
		m_Handle = bgfx::createShader(mem);
		bgfx::setName(m_Handle, m_Name.c_str());
	}
	else
	{
		harmony::log::error("Failed to load shader binary at path : ", binaryPath);
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
	m_Handle = bgfx::createEmbeddedShader(&p_EmbeddedShader,type, m_Name.c_str());
	bgfx::setName(m_Handle, m_Name.c_str());
}
