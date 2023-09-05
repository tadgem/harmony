#include <optick.h>
#include "Assets/ShaderSourceAsset.h"
#include "Core/TypeDef.h"

harmony::ShaderSourceAsset::ShaderSourceAsset(const std::string &path, harmony::ShaderStage::Type type) : Asset(
		AssetHandle{path, 0, GET_TYPE_HASH(ShaderSourceAsset)}), m_StageType(type)
{
	OPTICK_EVENT();
}