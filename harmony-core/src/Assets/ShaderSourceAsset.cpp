#include <optick.h>
#include "Assets/ShaderSourceAsset.h"
#include "Core/TypeDef.h"

harmony::ShaderSourceAsset::ShaderSourceAsset(const String &path, harmony::ShaderStage::Type type) : Asset(
        AssetHandle{path, 0, GetTypeHash<ShaderSourceAsset>()}), m_StageType(type) {
    OPTICK_EVENT();
}