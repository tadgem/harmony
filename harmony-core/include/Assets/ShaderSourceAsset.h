#pragma once

#include "Assets/Asset.h"
#include "Rendering/Shaders/Shader.h"

namespace harmony {
    class ShaderSourceAsset : public Asset {
    public:
        ShaderSourceAsset(const String &path, ShaderStage::Type type);

        ShaderStage::Type m_StageType;
        String m_Source;
    };
}