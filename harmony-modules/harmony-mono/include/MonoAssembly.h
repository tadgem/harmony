#pragma once

#include "Assets/Asset.h"
#include "MonoUtils.h"

namespace harmony
{
    enum class MonoAssemblyConfiguration
    {
        Debug = 0,
        Release = 1
    };

    class MonoAssemblyAsset : public Asset
    {
    public:
        MonoAssemblyAsset(std::vector<uint8_t> assemblyBinary, const std::string& assemblyPath);
        ~MonoAssemblyAsset();
        const String m_AssemblyPath;

        Vector<MonoUtils::CsTypeInfo> m_TypeInfos;
        Vector<MonoUtils::CsTypeSpecInfo> m_TypeSpecInfos;
        Vector<MonoUtils::CsInterfaceImplInfo> m_InterfaceImplInfos;
        Vector<MonoUtils::CsMethodImplInfo> m_MethodImplInfos;
        Vector<MonoUtils::CsTypeRefInfo> m_TypeRefInfos;
        Vector<MonoUtils::CsAssemblyRefInfo> m_AssemblyRefInfos;

    protected:
        void CollectAssemblyData();
        const Vector<uint8_t>   p_AssemblyBinary;
        MonoAssembly*           p_MonoAssembly;
    };
}