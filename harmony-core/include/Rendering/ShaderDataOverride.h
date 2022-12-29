#pragma once
#include "Core/Memory.h"
#include "Rendering/Texture.h"
#include "glm.hpp"
#include "Rendering/ShaderUniform.h"
#include "Rendering/Shader.h"
#include "Assets/AssetManager.h"

namespace harmony
{
    class ShaderDataOverride
    {
    public:
        ShaderDataOverride();

        std::map<ShaderUniform, glm::vec4>          m_Vec4Overrides;
        std::map<ShaderUniform, glm::mat3>          m_Mat3Overrides;
        std::map<ShaderUniform, glm::mat4>          m_Mat4Overrides;
        std::map<ShaderUniform, BGFXTextureHandle>  m_TextureOverrides;

        std::string                                 m_ShaderName;

        void UpdateContainer(WeakRef<ShaderProgram> container, AssetManager& am);
        void SetOverrides();
        void Clear();

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShaderDataOverride, m_Vec4Overrides, m_Mat3Overrides, m_Mat4Overrides, m_TextureOverrides, m_ShaderName)
    };
}