#include "MonoAssembly.h"
#include "MonoUtils.h"

harmony::MonoAssemblyAsset::MonoAssemblyAsset(std::vector<uint8_t> assemblyBinary, const std::string& assemblyPath) :
	Asset(),
	p_AssemblyBinary(assemblyBinary), 
	m_AssemblyPath(assemblyPath),
	p_MonoAssembly(MonoUtils::LoadCSharpAssembly(m_AssemblyPath, (char*)p_AssemblyBinary.data(), p_AssemblyBinary.size()))
{
}

harmony::MonoAssemblyAsset::~MonoAssemblyAsset()
{
	MonoUtils::FreeCSharpAssembly(p_MonoAssembly);
}