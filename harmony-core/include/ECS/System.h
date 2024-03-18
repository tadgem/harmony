#pragma once

#include "ThirdParty/entt.hpp"
#include "Core/TypeDef.h"

namespace harmony {
    class System {
    public:
        System(const HashString &typeHash) : m_TypeHash(typeHash) {}

        virtual ~System() {};

        virtual void Init(entt::registry &registry) = 0;

        virtual void Update(entt::registry &registry) = 0;

        virtual void Render(entt::registry &registry) = 0;

        virtual void Cleanup(entt::registry &registry) = 0;

        virtual Json SerializeSystem(entt::registry &registry) = 0;

        virtual void DeserializeSystem(entt::registry &registry, Json systemJson) = 0;

        virtual Json SerializeEntity(entt::registry& registry, entt::entity e) = 0;

        virtual void DeserializeEntity(entt::registry& registry, entt::entity e, Json entityJson) = 0;

        const HashString m_TypeHash;

        static String GetEntityKey(entt::entity &entity);

        static entt::entity GetEntityFromKey(const String &key);

    protected:
        friend class Program;

        virtual void Refresh() = 0;
    };
};