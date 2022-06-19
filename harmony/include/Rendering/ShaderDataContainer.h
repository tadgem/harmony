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

        void AddValue(const std::string name, WeakRef<float> value);
        void AddValue(const std::string name, WeakRef<glm::vec2> value);
        void AddValue(const std::string name, WeakRef<glm::vec3> value);
        void AddValue(const std::string name, WeakRef<glm::mat3> value);
        void AddValue(const std::string name, WeakRef<glm::mat4> value);
        void AddValue(const std::string name, WeakRef<BGFXTextureHandle> value);

        std::unordered_map<ShaderUniform, WeakRef<float>>     p_FloatValues;
        std::unordered_map<ShaderUniform, WeakRef<glm::vec2>> p_Vec2Values;
        std::unordered_map<ShaderUniform, WeakRef<glm::vec3>> p_Vec3Values;
        std::unordered_map<ShaderUniform, WeakRef<glm::mat3>> p_Mat3Values;
        std::unordered_map<ShaderUniform, WeakRef<glm::mat4>> p_Mat4Values;
        std::unordered_map <ShaderUniform, WeakRef<BGFXTextureHandle>> p_TextureValues;

        void SetContainerUniforms();

        static constexpr uint16_t g_MaxUniforms = 16;
        std::vector<bgfx::UniformInfo> m_UniformInfos;
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
                    uniform.BgfxHandle = uniforms[i];
                }
            }
            
            return uniform;
        }
        WeakRef<ShaderProgram> p_Shader;
        uint16_t p_ShaderUniformCount;
    };
};