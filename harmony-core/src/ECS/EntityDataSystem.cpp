#include "ECS/EntityDataSystem.h"
#include "ECS/Entity.h"
#include "Core/Memory.h"

void harmony::EntityDataSystem::Init(entt::registry &registry) {
    uint32_t index = 0;
    for (uint32_t index = 0; index < registry.size(); index++) {
        entt::entity e = (entt::entity) index;
        if (!registry.try_get<EntityData>(e)) {
            registry.emplace<EntityData>(e);
        }
        auto &data = registry.get<EntityData>(e);
        if (data.m_Name.empty()) {
            data.m_Name = "Entity " + std::to_string(index);
        }
    }
}

void harmony::EntityDataSystem::Update(entt::registry &registry) {

}

void harmony::EntityDataSystem::Render(entt::registry &registry) {

}

void harmony::EntityDataSystem::Cleanup(entt::registry &registry) {

}

nlohmann::json harmony::EntityDataSystem::SerializeSystem(entt::registry &registry) {
    nlohmann::json j;
    auto view = registry.view<EntityData>();

    for (auto [e, d]: view.each()) {
        j[GetEntityKey(e)] = d;
    }
    return j;
}

void harmony::EntityDataSystem::DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) {
    for (auto entry = systemJson.begin(); entry != systemJson.end(); entry++) {
        entt::entity e = GetEntityFromKey(entry.key());
        nlohmann::json dataJson = entry.value();
        EntityData data;
        dataJson.get_to<EntityData>(data);

        registry.emplace<EntityData>(e, data);
    }
}

void harmony::EntityDataSystem::Refresh() {

}

harmony::EntityDataSystem::EntityDataSystem() : System(GetTypeHash<EntityDataSystem>()) {

}

