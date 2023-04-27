#pragma once

#include "ThirdParty/entt.hpp"
#include "ThirdParty/json.hpp"
#include <optional>

namespace harmony {
    class Entity {
    public:
        Entity();

        Entity(entt::entity handle);

        entt::entity m_Handle;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Entity, m_Handle)

    protected:
        friend class Scene;
    };
}