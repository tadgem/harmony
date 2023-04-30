#include <optick.h>
#include "ECS/MeshSystem.h"
#include "ECS/MeshComponent.h"
#include "Core/Memory.h"

harmony::MeshSystem::MeshSystem(AssetManager &am) : System(GetTypeHash<MeshSystem>()), p_AssetManager(am) {
    OPTICK_EVENT();
}

void harmony::MeshSystem::Init(entt::registry &registry) {
    OPTICK_EVENT();
}

void harmony::MeshSystem::Update(entt::registry &registry) {
    OPTICK_EVENT();

    auto view = registry.view<MeshComponent>();

    for (auto [entity, mesh]: view.each()) {
        UpdateMeshComponent(mesh);
    }
}

void harmony::MeshSystem::Render(entt::registry &registry) {
    OPTICK_EVENT();
}

void harmony::MeshSystem::Cleanup(entt::registry &registry) {
    OPTICK_EVENT();
}

nlohmann::json harmony::MeshSystem::SerializeSystem(entt::registry &registry) {
    OPTICK_EVENT();
    nlohmann::json j;

    auto view = registry.view<MeshComponent>();

    for (auto [e, mesh]: view.each()) {
        j[GetEntityKey(e)] = mesh;
    }

    return j;
}

void harmony::MeshSystem::DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) {
    OPTICK_EVENT();
    for (auto entry = systemJson.begin(); entry != systemJson.end(); entry++) {
        entt::entity e = GetEntityFromKey(entry.key());
        MeshComponent mc = entry.value();

        UpdateMeshComponent(mc);

        registry.emplace<MeshComponent>(e, mc);
    }
}

void harmony::MeshSystem::Refresh() {
    OPTICK_EVENT();
}

void harmony::MeshSystem::UpdateMeshComponent(MeshComponent &mc) {
    OPTICK_EVENT();

    bool meshValid = mc.MeshHandle.m_Layout.m_stride > 0;
    if (!meshValid) {
        WeakRef<Mesh> meshAssetWr = p_AssetManager.GetAsset<Mesh>(mc.MeshAsset);
        if (meshAssetWr.expired()) {
            harmony::log::warn("Asset not loaded at path: ", mc.MeshAsset.Path);
            return;
        }
        Ref<Mesh> meshAsset = meshAssetWr.lock();
        mc.MeshHandle = meshAsset->m_Handle;
    }
}
