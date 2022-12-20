#pragma once
#include "Assets/Asset.h"
#include "Rendering/Shader.h"
namespace harmony
{
	class ShaderSourceAsset : public Asset
	{
	public:
		ShaderSourceAsset(const std::string& path, ShaderStage::Type type);

		ShaderStage::Type m_StageType;
		std::string m_Source;
	};
}