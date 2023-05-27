#pragma once

#include "Core/Memory.h"
#include "ThirdParty/entt.hpp"
#include "ThirdParty/json.hpp"
#include "ShaderUniform.h"

namespace harmony {
    class ShaderProgram;

    class ShaderDataSource {
    public:
        ShaderDataSource(const std::string &name);

        virtual void OnPreUpdate(entt::registry &registry, Ref<ShaderProgram> shader);

        virtual void OnPostUpdate(entt::registry &registry, Ref<ShaderProgram> shader);

        std::string m_Name;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShaderDataSource, m_Name);
    };
}