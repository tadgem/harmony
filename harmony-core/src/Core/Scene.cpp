#include <optick.h>
#include "Core/Scene.h"

harmony::Scene::Scene() {
    OPTICK_EVENT();
}

harmony::Scene::Scene(const std::string &name) : m_Name(name) {
    OPTICK_EVENT();
}

void harmony::Scene::Deserialize(std::vector<RefCntPtr<System>> &systems) {
    OPTICK_EVENT();
    m_Registry.clear();
    for (int i = 0; i < p_Entities.size(); i++) {
        m_Registry.create(p_Entities[i].m_Handle);
    }

    for (auto &[systemTypeHash, json]: p_SystemSerializationAttributes) {
        for (int i = 0; i < systems.size(); i++) {
            if (systems[i]->m_TypeHash == systemTypeHash) {
                systems[i]->DeserializeSystem(m_Registry, json);
                break;
            }
        }
    }
}

void harmony::Scene::UpdateSceneSystemSerializationAttributes(std::vector<RefCntPtr<System>> &systems) {
    OPTICK_EVENT();
    p_SystemSerializationAttributes.clear();

    for (int i = 0; i < systems.size(); i++) {
        RefCntPtr<System> system = systems[i];
        nlohmann::json sceneSystemJson = system->SerializeSystem(m_Registry);
        p_SystemSerializationAttributes.emplace(system->m_TypeHash, sceneSystemJson);
    }
    m_NumEntities = m_Registry.size();
}

harmony::Entity harmony::Scene::AddEntity(uint32_t index) {
    OPTICK_EVENT();
    entt::entity e = (entt::entity) index;

    if ((uint32_t) e == UINT32_MAX) {
        e = m_Registry.create();
    }

    Entity entity = Entity();
    entity.m_Handle = e;
    p_Entities.emplace_back(entity);
    return entity;
}