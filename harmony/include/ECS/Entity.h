#pragma once
#include "entt.hpp"
#include "json.hpp"
namespace harmony
{
    class Entity
    {
    public:

        Entity(entt::entity handle, entt::registry& registry);

        template<typename T, typename ... Args>
        T& AddComponent(Args&& ... args)
        {
            p_Registry.emplace<T>(m_Handle, std::forward<Args>(args)...);
            return GetComponent<T>();
        }

        template<typename T>
        T& GetComponent()
        {
            return p_Registry.get<T>(m_Handle);
        }

        entt::entity m_Handle;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Entity, m_Handle)

    protected:
        entt::registry& p_Registry;
    };
}