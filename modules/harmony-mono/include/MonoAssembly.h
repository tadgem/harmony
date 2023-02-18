#pragma once

#include "Assets/Asset.h"

namespace harmony
{
    class MonoAssembly : public Asset
    {
    public:
        MonoAssembly(std::vector<uint8_t> assemblyBinary, const std::string& assemblyPath);
        const std::string m_AssemblyPath;
    protected:
        const std::vector<uint8_t> p_AssemblyBinary;
    };
}