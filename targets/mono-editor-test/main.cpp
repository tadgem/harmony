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

	harmony::AddMono(app);

	app.Run("../../../projects/mono-test/MonoTest.harmonyproj");

	return 0;
}