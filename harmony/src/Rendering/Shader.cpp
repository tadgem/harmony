#include "Rendering/Shader.h"
#include "Core/Profile.hpp"
#include "Core/Log.hpp"
#include "Core/Utils.h"

harmony::ShaderProgram::ShaderProgram(const std::string& name) : m_Handle(BGFX_INVALID_HANDLE)
{
}

bool harmony::ShaderProgram::AddStage(ShaderStage::Type stageType, Ref<ShaderStage> shader)
{
	if (m_Stages.find(stageType) != m_Stages.end())
	{
		harmony::log::warn("Shader program already contains stage : %s", ShaderStage::GetShaderStageNameFromEnum(stageType));
		return false;
	}

	m_Stages.emplace(stageType, shader);
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
		m_Handle = bgfx::createProgram(m_Stages[ShaderStage::Type::Compute]->m_Handle, true);
		return;
	}

	if (m_Stages.find(ShaderStage::Type::Vertex) != m_Stages.end() && 
		m_Stages.find(ShaderStage::Type::Fragment) != m_Stages.end())
	{
		m_Handle = bgfx::createProgram(m_Stages[ShaderStage::Type::Vertex]->m_Handle, m_Stages[ShaderStage::Type::Fragment]->m_Handle, true);
		return;
	}

	harmony::log::error("Failed to build shader! invalid combination provided.");
}

harmony::ShaderStage::ShaderStage(const std::string& name, const Type& shaderType) : m_Type(shaderType), m_Handle(BGFX_INVALID_HANDLE), m_Name(name)
{
}

harmony::ShaderStage::~ShaderStage()
{
	delete p_Memory;
}

void harmony::ShaderStage::LoadShaderBinary()
{
	std::string binaryPath = GetShaderRendererDirectory() + m_Name + ".bin";
	std::vector<uint8_t> binary = Utils::LoadBinaryFromPath(binaryPath);
	uint32_t binarySize = static_cast<uint32_t>(binary.size());

	p_Memory = new bgfx::Memory{ binary.data(), binarySize};
	bgfx::createShader(p_Memory);
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
	std::string shaderPath = "";

	switch (bgfx::getRendererType())
	{
		case bgfx::RendererType::Noop:
		case bgfx::RendererType::Direct3D9:  shaderPath = "shaders/dx9/";   break;
		case bgfx::RendererType::Direct3D11:
		case bgfx::RendererType::Direct3D12: shaderPath = "shaders/dx11/";  break;
		case bgfx::RendererType::Agc:
		case bgfx::RendererType::Gnm:        shaderPath = "shaders/pssl/";  break;
		case bgfx::RendererType::Metal:      shaderPath = "shaders/metal/"; break;
		case bgfx::RendererType::Nvn:        shaderPath = "shaders/nvn/";   break;
		case bgfx::RendererType::OpenGL:     shaderPath = "shaders/glsl/";  break;
		case bgfx::RendererType::OpenGLES:   shaderPath = "shaders/essl/";  break;
		case bgfx::RendererType::Vulkan:     shaderPath = "shaders/spirv/"; break;
		case bgfx::RendererType::WebGPU:     shaderPath = "shaders/spirv/"; break;

		case bgfx::RendererType::Count:
			harmony::log::error("Could not deduce BGFX renderer!");
		break;
	}

	return shaderPath;
}
