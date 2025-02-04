#include "ECS/EntityDataSystem.h"
#include "ECS/Entity.h"
#include "Core/Memory.h"
#include <optick.h>
void harmony::EntityDataSystem::Init(entt::registry &registry) {
    OPTICK_EVENT()
    uint32_t index = 0;
    for (uint32_t index = 0; index < registry.size(); index++) {
        entt::entity e = (entt::entity) index;
        if (!registry.valid(e))
        {
            return;
        }
        if (!registry.try_get<EntityData>(e)) {
            registry.emplace<EntityData>(e);
        }
        auto &data = registry.get<EntityData>(e);
        if (data.m_Name.empty()) {
            data.m_Name = "Entity " + ToString(index);
        }
    }
}

void harmony::EntityDataSystem::Update(entt::registry &registry) {
    OPTICK_EVENT()

}

void harmony::EntityDataSystem::Render(entt::registry &registry) {
    OPTICK_EVENT()

}

void harmony::EntityDataSystem::Cleanup(entt::registry &registry) {
    OPTICK_EVENT()

}

harmony::Json harmony::EntityDataSystem::SerializeSystem(entt::registry &registry) {
    OPTICK_EVENT()
    Json j;
    auto view = registry.view<EntityData>();

    for (auto [e, d]: view.each()) {
        j[GetEntityKey(e)] = d;
    }
    return j;
}

void harmony::EntityDataSystem::DeserializeSystem(entt::registry &registry, Json systemJson) {
    OPTICK_EVENT()
    for (auto entry = systemJson.begin(); entry != systemJson.end(); entry++) {
        entt::entity e = GetEntityFromKey(entry.key());
        Json dataJson = entry.value();
        EntityData data;
        dataJson.get_to<EntityData>(data);

        // TODO: Should be somwhere better

        if (!registry.valid(e))
        {
            e = registry.create(e);
        }

        registry.emplace<EntityData>(e, data);
    }
}

harmony::Json harmony::EntityDataSystem::SerializeEntity(entt::registry& registry, entt::entity e)
{
    OPTICK_EVENT()
    Json j;

    if(registry.any_of<EntityData>(e))
    {
        EntityData& c = registry.get<EntityData>(e);
        j = c;
    }

    return j;
}

void harmony::EntityDataSystem::DeserializeEntity(entt::registry& registry, entt::entity e, Json entityJson)
{
    OPTICK_EVENT()
    EntityData ed;
    entityJson.get_to<EntityData>(ed);
    registry.emplace<EntityData>(e, ed);
}

void harmony::EntityDataSystem::Refresh() {
    OPTICK_EVENT()
}

harmony::EntityDataSystem::EntityDataSystem() : System(GetTypeHash<EntityDataSystem>()) {
    OPTICK_EVENT()
}

