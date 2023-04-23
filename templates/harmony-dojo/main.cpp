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

    auto * graph = new harmony::GraphScript::Graph();

    // create a graph.

    app.m_GraphScriptEditor.AddGraph(graph);

	// app.Run("../../../projects/Test3/Test3.harmonyproj");
	app.Run("../../../../projects/JoltTest/JoltTest.harmonyproj");
	return 0;
}