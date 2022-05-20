#pragma once

#include "bgfx/bgfx.h"
#include "Assets/Asset.h"
#include "Core/Memory.h"

namespace harmony
{
	class ShaderStage : public Asset
	{
	public:

		enum class Type
		{
			Vertex,
			Fragment, 
			Compute
		};

		ShaderStage(const std::string& name, const Type& shaderType);
		~ShaderStage();

		void LoadShaderBinary();

		static std::string GetShaderStageNameFromEnum(Type type);
		static std::string GetShaderRendererDirectory();
		
		const Type m_Type;
		const std::string m_Name;

		std::vector<bgfx::UniformInfo> m_UniformInfos;
		bgfx::ShaderHandle m_Handle;

	private:
		bgfx::Memory* p_Memory;
	};

	class ShaderProgram
	{
	public:
		ShaderProgram(const std::string& name);

		bool AddStage(ShaderStage::Type stageType, Ref<ShaderStage> shader);
		bool RemoveStage(ShaderStage::Type stageType);
		void Build();

		const std::string m_Name;
		
		std::unordered_map<ShaderStage::Type, Ref<ShaderStage>> m_Stages;
		bgfx::ProgramHandle m_Handle;
	};
};