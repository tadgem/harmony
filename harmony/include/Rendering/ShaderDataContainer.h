#pragma once
#include "Core/Memory.h"
#include "Rendering/Shader.h"
#include "Rendering/Texture.h"
#include "glm/glm.hpp"
namespace harmony
{
    class ShaderDataContainer
    {
    public:
        ShaderDataContainer(WeakRef<ShaderProgram> shaderProgram);

        std::map<ShaderUniform, float>     m_FloatValues;
        std::map<ShaderUniform, glm::vec2> m_Vec2Values;
        std::map<ShaderUniform, glm::vec3> m_Vec3Values;
        std::map<ShaderUniform, glm::mat3> m_Mat3Values;
        std::map<ShaderUniform, glm::mat4> m_Mat4Values;
        std::map<ShaderUniform, BGFXTextureHandle> m_TextureValues;

        void UpdateShader(WeakRef<ShaderProgram> newShader);
        void UpdateContainer();
        void SetContainerUniforms();
        void Clear();
        static constexpr uint16_t g_MaxUniforms = 16;
        std::vector<bgfx::UniformInfo> m_UniformInfos;
        std::vector<bgfx::UniformHandle> m_UniformHandles;
        std::vector<ShaderUniform> m_Uniforms;
    protected:

        bool ReturnIfNull();

        template <typename T>
        ShaderUniform GetShaderUniform(const std::string name)
        {
            ShaderUniform uniform;
            uniform.BgfxHandle = BGFX_INVALID_HANDLE;
            uniform.Name = name;
            uniform.TypeHash = typeid(T).hash_code();

            for (uint16_t i = 0; i < m_UniformInfos.size(); i++)
            {
                bgfx::UniformInfo info = m_UniformInfos[i];

                std::string uniformName = info.name;
                if (uniformName == name)
                {
                    uniform.BgfxHandle = m_UniformHandles[i];
                }
            }
            
            return uniform;
        }
        WeakRef<ShaderProgram> p_Shader;
        uint16_t p_ShaderUniformCount;
    };
};