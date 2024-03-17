#pragma once

#include "Core/Memory.h"
#include "ShaderUniform.h"
#include "ThirdParty/entt.hpp"
#include "ThirdParty/json.hpp"

namespace harmony {
    class ShaderProgram;

    class ShaderDataSource {
    public:
        ShaderDataSource(const std::string &name);

        virtual void OnPreUpdate(entt::registry &registry, RefCntPtr<ShaderProgram> shader);

        virtual void OnPostUpdate(entt::registry &registry,
                                  RefCntPtr<ShaderProgram> shader);

        std::string m_Name;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShaderDataSource, m_Name);
    };
} // namespace harmony