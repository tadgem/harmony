#include "MonoAssembly.h"
#include "MonoUtils.hpp"
harmony::MonoAssembly::MonoAssembly(std::vector<uint8_t> assemblyBinary, const std::string& assemblyPath) : p_AssemblyBinary(assemblyBinary), m_AssemblyPath(assemblyPath)
{
	CreateMonoAssembly();
}

void harmony::MonoAssembly::CreateMonoAssembly()
{
	p_MonoAssembly = MonoUtils::LoadCSharpAssembly(m_AssemblyPath, (char*) p_AssemblyBinary.data(), p_AssemblyBinary.size());
}
