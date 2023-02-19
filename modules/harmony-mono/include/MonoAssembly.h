#pragma once

#include "Assets/Asset.h"
#include "mono/metadata/assembly.h"

namespace harmony
{
    class MonoAssemblyAsset : public Asset
    {
    public:
        MonoAssemblyAsset(std::vector<uint8_t> assemblyBinary, const std::string& assemblyPath);
        ~MonoAssemblyAsset();
        const std::string m_AssemblyPath;
    protected:
        const std::vector<uint8_t>  p_AssemblyBinary;
        const MonoAssembly*         p_MonoAssembly;
    };
}