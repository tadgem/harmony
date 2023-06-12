#pragma once

#include "ThirdParty/entt.hpp"
#include "ThirdParty/json.hpp"
#include "ECS/Entity.h"
#include "ECS/System.h"
#include "Core/Memory.h"

namespace harmony {
    class Scene {
    public:
        Scene();

        Scene(const std::string &name);

        Entity AddEntity(uint32_t index = UINT32_MAX);

        std::string m_Name;
        uint32_t m_NumEntities;
        entt::registry m_Registry;


    protected:
        friend class Program;

        void UpdateSceneSystemSerializationAttributes(std::vector<Ref<System>> &systems);

        void Deserialize(std::vector<Ref<System>> &systems);

        std::map<std::string, nlohmann::json> p_SystemSerializationAttributes;
        std::vector<Entity> p_Entities;
    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Scene, m_Name, m_NumEntities, p_Entities, p_SystemSerializationAttributes)
    };
};