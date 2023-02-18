#include "Core/Memory.h"
#include "MonoProgramComponent.h"
#include "MonoAssemblyAssetFactory.h"

void* operator new(size_t size)
{
	harmony::Memory::AddAllocatedMemory(size);
	return malloc(size);
}

void operator delete(void* memory, size_t size)
{
	harmony::Memory::AddFreedMemory(size);
	free(memory);
}

#include "EditorApplication.h"

int main()
{
	harmony::Editor app;

	app.m_AssetManager.AddAssetFactory(harmony::CreateRef<harmony::MonoAssemblyAssetFactory>());
	app.AddProgramComponent<harmony::MonoProgramComponent>();
	app.AddSystem<harmony::MonoSystem>();
	app.Run("../../../projects/mono-test/MonoTest.harmonyproj");

	return 0;
}