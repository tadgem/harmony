#include <optick.h>
#include "Core/Scene.h"

harmony::Scene::Scene() {
    OPTICK_EVENT();
    m_NumEntities = 0;
}

harmony::Scene::Scene(const String &name) : m_Name(name) {
    OPTICK_EVENT();
    m_NumEntities = 0;
}

void harmony::Scene::Deserialize(Vector<RefCntPtr<System>> &systems) {
    OPTICK_EVENT();
    m_Registry.clear();
    for (int i = 0; i < p_Entities.size(); i++) {
        entt::entity e = m_Registry.create(p_Entities[i].m_Handle);
    }

    for (auto &[systemTypeHash, json]: p_SystemSerializationAttributes) {
        for (int i = 0; i < systems.size(); i++) {
            if (systems[i]->m_TypeHash == HashString(systemTypeHash)) {
                systems[i]->DeserializeSystem(m_Registry, json);
                break;
            }
        }
    }
}

harmony::Vector<entt::entity> harmony::Scene::GetChildEntities(entt::entity e)
{
    auto ret = Vector<entt::entity>();

    auto view = m_Registry.view<EntityData>();

    for (auto [entity, entity_data] : view.each())
    {
        if (entity_data.m_Parent == static_cast<uint32_t>(e))
        {
            ret.emplace_back(entity);
        }
    }

    return ret;
}

void harmony::Scene::UpdateSceneSystemSerializationAttributes(Vector<RefCntPtr<System>> &systems) {
    OPTICK_EVENT();
    p_SystemSerializationAttributes.clear();

    for (int i = 0; i < systems.size(); i++) {
        RefCntPtr<System> system = systems[i];
        Json sceneSystemJson = system->SerializeSystem(m_Registry);
        p_SystemSerializationAttributes.emplace(system->m_TypeHash, sceneSystemJson);
    }
    m_NumEntities = static_cast<uint32_t>(m_Registry.size());
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