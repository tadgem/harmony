#pragma once

#include "Assets/AssetManager.h"
#include "Assets/TextureAsset.h"
#include "Core/Memory.h"
#include "Shader.h"

namespace harmony {
    class ShaderDataOverride {
    public:
        ShaderDataOverride();

        std::string m_ShaderName;
        std::vector<ShaderUniform> m_AvailableOverrides;
        std::map<ShaderUniform, glm::vec4> m_Vec4Overrides;
        std::map<ShaderUniform, glm::mat3> m_Mat3Overrides;
        std::map<ShaderUniform, glm::mat4> m_Mat4Overrides;
        std::map<ShaderUniform, BGFXTextureHandle> m_TextureOverrides;

        void AddVec4Override(ShaderUniform uniform, glm::vec4 value);

        void AddMat3Override(ShaderUniform uniform, glm::mat3 value);

        void AddMat4Override(ShaderUniform uniform, glm::mat4 value);

        void AddTextureOverride(ShaderUniform uniform, BGFXTextureHandle value);

        void UpdateOverrides(WeakPtr<ShaderProgram> shaderWr, AssetManager &am);

        void SetOverrides();

        void Clear();

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShaderDataOverride, m_Vec4Overrides,
                                       m_Mat3Overrides, m_Mat4Overrides,
                                       m_TextureOverrides, m_ShaderName)

    protected:
        void UpdateUniform(ShaderUniform &uniform);
    };
} // namespace harmony