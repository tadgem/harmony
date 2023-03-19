#include "Core/Memory.h"

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
	app.Run("../../../projects/Test3/Test3.harmonyproj");
	//app.Run();
	return 0;
}