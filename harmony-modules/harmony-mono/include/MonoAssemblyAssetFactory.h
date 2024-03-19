#pragma once

#include "Assets/AssetFactory.h"

namespace harmony
{
    class MonoProgramComponent;
    class MonoAssemblyAssetFactory : public AssetFactory
    {
    public:
        MonoAssemblyAssetFactory(WeakPtr<MonoProgramComponent> mono);

        virtual void LoadAssetData(const    String& path, entt::registry& registry) override;
        virtual void UnloadAssetData(const  String& path, entt::registry& registry) override;

    protected:
        WeakPtr<MonoProgramComponent> p_Mono;
        const HashString p_AssemblyTypeHash;

        const String p_MonoModuleNamespace = "Harmony.Module";
        const String p_InitInterfaceName = "IOnInit";
        const String p_InitMethodName = "Init";
    };
}