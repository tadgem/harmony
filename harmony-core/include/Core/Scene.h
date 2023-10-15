#pragma once

#include "ThirdParty/entt.hpp"
#include "ThirdParty/json.hpp"
#include "ECS/Entity.h"
#include "ECS/System.h"
#include "Core/Memory.h"
#include "Core/TypeDef.h"

namespace harmony {
    class Scene {
    public:
        Scene();

        Scene(const std::string &name);

        Entity AddEntity(uint32_t index = UINT32_MAX);

        std::string m_Name;
        uint32_t m_NumEntities;
        entt::registry m_Registry;

        template<typename T>
        nlohmann::json GetSystemJSON()
        {
            HashString typeHash = GetTypeHash<T>();
            if(p_SystemSerializationAttributes.find(typeHash.m_Value) != p_SystemSerializationAttributes.end())
            {
                return p_SystemSerializationAttributes[typeHash.m_Value];
            }

            return nlohmann::json();
        }

    protected:
        friend class Program;

        void UpdateSceneSystemSerializationAttributes(std::vector<RefCntPtr<System>> &systems);

        void Deserialize(std::vector<RefCntPtr<System>> &systems);

        std::map<uint64_t, nlohmann::json> p_SystemSerializationAttributes;
        std::vector<Entity> p_Entities;
    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Scene, m_Name, m_NumEntities, p_Entities, p_SystemSerializationAttributes)
    };
};