#include "MonoAssemblyAssetFactory.h"
#include "MonoAssembly.h"
#include "MonoProgramComponent.h"
#include "Core/Utils.h"
#include "Core/Log.hpp"
#include "Core/Memory.h"
#include "MonoAPI.h"
harmony::MonoAssemblyAssetFactory::MonoAssemblyAssetFactory(WeakPtr<MonoProgramComponent> mono) : p_Mono(mono), p_AssemblyTypeHash(GetTypeHash<MonoAssemblyAsset>())
{
	m_Capabilities.AssetTypeHashes.push_back(p_AssemblyTypeHash);
}

void harmony::MonoAssemblyAssetFactory::LoadAssetData(const String& path, entt::registry& registry)
{
	Vector<uint8_t> assemblyBytes = Utils::LoadBinaryFromPath(path);
	if (assemblyBytes.empty())
	{
		harmony::log::error("MonoAssemblyAssetFactory : Unable to load Assembly at path {}", path);
		return;
	}
	
	RefCntPtr<MonoAssemblyAsset> assembly = CreateRef<MonoAssemblyAsset>(assemblyBytes, path);

	AssetHandle assemblyHandle{ path, 0, p_AssemblyTypeHash };
    assembly->m_Handle = assemblyHandle;

	AssetComponent<MonoAssemblyAsset> assemblyComponent{ assembly, assemblyHandle };

	entt::entity e = registry.create();
	registry.emplace<AssetComponent<MonoAssemblyAsset>>(e, assemblyComponent);
	registry.emplace<AssetHandle>(e, assemblyHandle);

}

void harmony::MonoAssemblyAssetFactory::UnloadAssetData(const String& path, entt::registry& registry)
{
	Vector<entt::entity> entitiesToDestroy;

	auto assemblyView = registry.view<AssetComponent<MonoAssemblyAsset>, AssetHandle>();

	for (auto [e, assembly, handle] : assemblyView.each())
	{
		if (handle.Path == path)
		{
			entitiesToDestroy.push_back(e);
			assembly.Asset.reset();
		}
	}
	for (int i = 0; i < entitiesToDestroy.size(); i++)
	{
		registry.destroy(entitiesToDestroy[i]);
	}
}
