#pragma once

#include "Core/Memory.h"
#include "ShaderUniform.h"
#include "ThirdParty/entt.hpp"
#include "STL/Json.hpp"

namespace harmony {
    class ShaderProgram;

    class ShaderDataSource {
    public:
        ShaderDataSource(const String &name);

        virtual void OnPreUpdate(entt::registry &registry, RefCntPtr<ShaderProgram> shader);

        virtual void OnPostUpdate(entt::registry &registry,
                                  RefCntPtr<ShaderProgram> shader);

        String m_Name;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShaderDataSource, m_Name);
    };
} // namespace harmony