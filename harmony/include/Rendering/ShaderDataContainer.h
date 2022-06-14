#pragma once
#include "Core/Memory.h"
#include "Rendering/Shader.h"
#include "glm/glm.hpp"

namespace harmony
{
    class ShaderDataContainer
    {
    public:
        ShaderDataContainer(WeakRef<ShaderProgram> shaderProgram);

        void AddUniform(const std::string name, WeakRef<float> value);
        void AddUniform(const std::string name, WeakRef<glm::vec2> value);
        void AddUniform(const std::string name, WeakRef<glm::vec3> value);
        void AddUniform(const std::string name, WeakRef<glm::mat3> value);
        void AddUniform(const std::string name, WeakRef<glm::mat4> value);

        std::unordered_map<bgfx::UniformHandle, WeakRef<float>>     p_FloatValues;
        std::unordered_map<bgfx::UniformHandle, WeakRef<glm::vec2>> p_Vec2Values;
        std::unordered_map<bgfx::UniformHandle, WeakRef<glm::vec3>> p_Vec3Values;
        std::unordered_map<bgfx::UniformHandle, WeakRef<glm::mat3>> p_Mat3Values;
        std::unordered_map<bgfx::UniformHandle, WeakRef<glm::mat4>> p_Mat4Values;
    };
};