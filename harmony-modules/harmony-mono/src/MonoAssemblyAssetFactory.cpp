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

void harmony::MonoAssemblyAssetFactory::LoadAssetData(const std::string& path, entt::registry& registry)
{
	std::vector<uint8_t> assemblyBytes = Utils::LoadBinaryFromPath(path);
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

	// Do modules
	for(auto& interfaceImplInfo : assembly->m_InterfaceImplInfos)
	{
		// if derivative of Module
		if(interfaceImplInfo.m_InterfaceNamespace == p_MonoModuleNamespace)
		{
			if(interfaceImplInfo.m_InterfaceName == p_InitInterfaceName)
			{
				MonoUtils::CsTypeInfo& typeInfo = assembly->m_TypeInfos[interfaceImplInfo.m_ClassIndex];
				MonoObject* classObject   = MonoUtils::CreateMonoObject(p_Mono.lock()->GetAppDomain(), typeInfo);

				// Grab interface methods to call
				MonoClass * instanceClass = mono_object_get_class(classObject);
				MonoMethod* initMethod      = nullptr;

				initMethod = mono_class_get_method_from_name(instanceClass, p_InitMethodName.c_str(), 0);
				if(initMethod == nullptr) {
					log::error("MonoProgramComponent : Init : Module Type {} implements IOnInit but does not have an Init method.", typeInfo.m_TypeName);
					continue;;
				}
				MonoObject * exception = nullptr;
				mono_runtime_invoke(initMethod, classObject, nullptr, &exception);
				if(exception != nullptr)
				{
					log::error("MonoProgramComponent : Init : Module : exception encountered during init for type {}", typeInfo.m_TypeName);
				}

			}
		}
	}

	// have to temporarily cache refcntptrs as they are passed over C# as raw ptrs
	harmony_mono_renderer_clear_cached_objects();

}

void harmony::MonoAssemblyAssetFactory::UnloadAssetData(const std::string& path, entt::registry& registry)
{
	std::vector<entt::entity> entitiesToDestroy;

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
