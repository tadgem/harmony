#pragma once
#include "entt.hpp"
#include "json.hpp"

namespace harmony
{
    class System
    {
        public:
        System(size_t typeHash) : m_TypeHash(typeHash) {}
        virtual ~System() {};
        virtual void Init(entt::registry& registry) = 0;
        virtual void Update(entt::registry& registry) = 0;
        virtual void Render(entt::registry& registry) = 0;
        virtual void Cleanup(entt::registry& registry) = 0;
        virtual nlohmann::json SerializeSystem(entt::registry& registry) = 0;
        virtual void DeserializeSystem(entt::registry& registry, nlohmann::json systemJson) = 0;
        const size_t m_TypeHash;

        static std::string GetEntityKey(entt::entity& entity);
        static entt::entity GetEntityFromKey(const std::string& key);
    protected:
        friend class Program;
        virtual void Refresh() = 0;
    };
};