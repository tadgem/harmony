#include "MonoAssembly.h"

harmony::MonoAssembly::MonoAssembly(std::vector<uint8_t> assemblyBinary, const std::string& assemblyPath) : p_AssemblyBinary(assemblyBinary), m_AssemblyPath(assemblyPath)
{
}
