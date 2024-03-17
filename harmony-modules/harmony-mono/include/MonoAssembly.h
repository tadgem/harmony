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

        Vector<MonoUtils::CsTypeInfo>           m_TypeInfos;
        Vector<MonoUtils::CsDerivedTypeInfo>    m_DerivedTypeInfos;
        Vector<MonoUtils::CsTypeSpecInfo>       m_TypeSpecInfos;
        Vector<MonoUtils::CsInterfaceImplInfo>  m_InterfaceImplInfos;
        Vector<MonoUtils::CsTypeRefInfo>        m_TypeRefInfos;
        Vector<MonoUtils::CsAssemblyRefInfo>    m_AssemblyRefInfos;
        Vector<MonoUtils::CsMethodImplInfo>     m_MethodImplInfos;

    protected:
        friend class MonoProgramComponent;
        friend class MonoSystem;
        void CollectAssemblyData(String path);
        const Vector<uint8_t>   p_AssemblyBinary;
        MonoAssembly*           p_MonoAssembly;
    };
}