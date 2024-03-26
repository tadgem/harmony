#pragma once

#include "Core/Alias.h"
#include "ThirdParty/entt.hpp"
#include "STL/Json.hpp"
#include "STL/Optional.h"
#include "STL/String.h"

namespace harmony {

    struct EntityData {
        EntityData();

        String m_Name;
        uint64_t m_LayerMask = 0; // TODO: do something with this.
        entt::entity m_Parent{UINT32_MAX};
        bool m_Static = false;
        bool m_Enabled = true;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(EntityData, m_Name, m_LayerMask, m_Parent, m_Static, m_Enabled)

    };

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