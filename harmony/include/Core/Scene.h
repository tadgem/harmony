#pragma once
#include "entt.hpp"
#include "json.hpp"
#include "ECS/Entity.h"
#include "ECS/System.h"
#include "Core/Memory.h"
namespace harmony
{
    class Scene
    {
        public:
        Scene();
        Scene(const std::string& name);
        std::string m_Name;
        uint32_t m_NumEntities;
        entt::registry m_Registry;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Scene, m_Name, m_NumEntities, p_SystemSerializationAttributes)
    
    protected:

        void UpdateSceneSystemSerializationAttributes(std::vector<Ref<System>>& systems);
        void Deserialize(std::vector<Ref<System>>& systems);
        std::map<size_t, nlohmann::json>    p_SystemSerializationAttributes;
        std::vector<Entity> p_Entities;
        friend class Program;
    };
};