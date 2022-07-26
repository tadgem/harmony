#pragma once

#include "bgfx/bgfx.h"
#include "bgfx/embedded_shader.h"
#include "Assets/Asset.h"
#include "Core/Memory.h"
#include "bx/readerwriter.h"
#include "bx/file.h"
namespace harmony
{
	struct ShaderUniform
	{
		bgfx::UniformHandle BgfxHandle{ UINT16_MAX };
		std::string Name;
		bgfx::UniformType::Enum Type;
		uint16_t ArraySize;

		bool Valid();

		bool operator<(const ShaderUniform& o)  const {
			return BgfxHandle.idx < o.BgfxHandle.idx;
		}
		NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShaderUniform, Name, Type)
	};

	class ShaderStage : public Asset
	{
	public:

		enum Type : char
		{
			Vertex,
			Fragment, 
			Compute,
			Unknown = CHAR_MAX
		};
		NLOHMANN_JSON_SERIALIZE_ENUM(Type, {
			{Vertex, "vert"},
			{Fragment, "frag"},
			{Compute, "compute"},
			{Unknown, "unknown"}
		})

		ShaderStage(const std::string& name, const Type& shaderType);
		ShaderStage();
		~ShaderStage();

		virtual void LoadShaderBinary();
		static std::string GetShaderStageNameFromEnum(Type type);
		static std::string GetShaderRendererDirectory();
		
		Type m_Type;
		std::string m_Name;
		std::string m_BinaryPath;
		NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShaderStage, m_Name, m_Type, m_Handle)

		std::vector<bgfx::UniformInfo> m_UniformInfos;
		bgfx::ShaderHandle m_ProgramHandle;


	private:
		bx::FileReader _reader;
	};

	class BuiltInShaderStage : public ShaderStage
	{
	public:
		BuiltInShaderStage(const std::string& name, const Type& shaderType, bgfx::EmbeddedShader embeddedShader);
		virtual void LoadShaderBinary() override;
	protected:
		bgfx::EmbeddedShader p_EmbeddedShader;
	};

	class ShaderProgram
	{
	public:
		ShaderProgram(const std::string& name);
		ShaderProgram();

		bool AddStage(ShaderStage::Type stageType, WeakRef<ShaderStage> shader);
		bool RemoveStage(ShaderStage::Type stageType);
		void Build();
		void Destroy();
		void GetUniforms();

		std::string m_Name;
		std::unordered_map<ShaderStage::Type, WeakRef<ShaderStage>> m_Stages;
		std::vector<ShaderUniform> m_Uniforms;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShaderProgram, m_Name, m_Stages)

		static constexpr uint16_t g_MaxUniforms = 16;

		bgfx::ProgramHandle m_Handle;
	};
};