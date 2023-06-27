#include <optick.h>
#include "Assets/ShaderSourceAsset.h"

harmony::ShaderSourceAsset::ShaderSourceAsset(const std::string &path, harmony::ShaderStage::Type type) : Asset(
		AssetHandle{path, 0, GetTypeHash<ShaderSourceAsset>()}), m_StageType(type)
{
	OPTICK_EVENT();
}