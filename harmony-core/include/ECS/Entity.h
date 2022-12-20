#pragma once
#include "entt.hpp"
#include "json.hpp"
#include <optional>
namespace harmony
{
    class Entity
    {
    public:
        Entity();
        entt::entity m_Handle;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Entity, m_Handle)
    protected:
        friend class Scene;
    };
}