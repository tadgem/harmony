#pragma once

#include "STL/Vector.h"
#include "ECS/Entity.h"
#include "ECS/System.h"
#include "Core/Memory.h"
#include "Core/TypeDef.h"

namespace harmony {
    class Scene {
    public:
        Scene();

        Scene(const String &name);

        Entity AddEntity(uint32_t index = UINT32_MAX);

        String m_Name;
        uint32_t m_NumEntities;
        entt::registry m_Registry;

        template<typename T>
        Json GetSystemJSON()
        {
            HashString typeHash = GetTypeHash<T>();
            if(p_SystemSerializationAttributes.find(typeHash.m_Value) != p_SystemSerializationAttributes.end())
            {
                return p_SystemSerializationAttributes[typeHash.m_Value];
            }

            return Json();
        }

        Vector<entt::entity> GetChildEntities(entt::entity e);

    protected:
        friend class Program;

        void UpdateSceneSystemSerializationAttributes(Vector<RefCntPtr<System>> &systems);

        void Deserialize(Vector<RefCntPtr<System>> &systems);

        Map<uint64_t, Json> p_SystemSerializationAttributes;
        Vector<Entity> p_Entities;
    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Scene, m_Name, m_NumEntities, p_Entities, p_SystemSerializationAttributes)
    };
};