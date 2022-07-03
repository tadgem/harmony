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
		bool meshValid = bgfx::isValid(mesh.MeshHandle.m_VBH) && bgfx::isValid(mesh.MeshHandle.m_IBH);
		if (!meshValid)
		{
			WeakRef<Mesh> meshAssetWr = p_AssetManager.GetAsset<Mesh>(mesh.MeshAsset);
			if (meshAssetWr.expired())
			{
				harmony::log::warn("Asset not loaded at path: ", mesh.MeshAsset.Path);
				continue;
			}
			Ref<Mesh> meshAsset = meshAssetWr.lock();
			mesh.MeshHandle = meshAsset->m_Handle;
		}
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
	return nlohmann::json();
}

void harmony::MeshSystem::DeserializeSystem(entt::registry& registry, nlohmann::json systemJson)
{
}

void harmony::MeshSystem::Refresh()
{
}
