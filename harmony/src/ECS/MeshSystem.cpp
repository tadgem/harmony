#include "ECS/MeshSystem.h"
#include "ECS/MeshComponent.h"
#include "Core/Memory.h"

harmony::MeshSystem::MeshSystem(AssetManager& am) : System(GetTypeHash<MeshComponent>()), p_AssetManager(am)
{
}

void harmony::MeshSystem::Init(entt::registry& registry)
{
}

void harmony::MeshSystem::Update(entt::registry& registry)
{
	auto view = registry.view<MeshComponent>();

	for (auto& [entity, mesh] : view.each())
	{
		UpdateMeshComponent(mesh);
	}
}

void harmony::MeshSystem::Render(entt::registry& registry)
{
}

void harmony::MeshSystem::Cleanup(entt::registry& registry)
{
}

nlohmann::json harmony::MeshSystem::SerializeSystem(entt::registry& registry)
{
	nlohmann::json j;

	auto view = registry.view<MeshComponent>();

	for(auto [e, mesh] : view.each())
	{
		j[GetEntityKey(e)] = mesh;
	}

	return j;
}

void harmony::MeshSystem::DeserializeSystem(entt::registry& registry, nlohmann::json systemJson)
{
	for (auto entry = systemJson.begin(); entry != systemJson.end(); entry++)
	{
		entt::entity e = GetEntityFromKey(entry.key());
		MeshComponent mc = entry.value();

		UpdateMeshComponent(mc);

		registry.emplace<MeshComponent>(e, mc);
	}
}

void harmony::MeshSystem::Refresh()
{
}

void harmony::MeshSystem::UpdateMeshComponent(MeshComponent& mc)
{
	bool meshValid = mc.MeshHandle.m_Layout.m_stride > 0;
	if (!meshValid)
	{
		WeakRef<Mesh> meshAssetWr = p_AssetManager.GetAsset<Mesh>(mc.MeshAsset);
		if (meshAssetWr.expired())
		{
			harmony::log::warn("Asset not loaded at path: ", mc.MeshAsset.Path);
			return;
		}
		Ref<Mesh> meshAsset = meshAssetWr.lock();
		mc.MeshHandle = meshAsset->m_Handle;
	}
}
