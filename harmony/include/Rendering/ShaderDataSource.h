#pragma once
#include "Core/Memory.h"
#include "entt.hpp"
namespace harmony
{
    class ShaderProgram;
    class ShaderDataSource
    {
    public:
        ShaderDataSource(const std::string& name);

        virtual void OnPreUpdate(entt::registry& registry, Ref<ShaderProgram> shader);
        virtual void OnPostUpdate(entt::registry& registry, Ref<ShaderProgram> shader);

        const std::string m_Name;
    };
}