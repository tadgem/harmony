#include "Core/Memory.h"

void *operator new(size_t size) {
    harmony::Memory::AddAllocatedMemory(size);
    return malloc(size);
}

void operator delete(void *memory, size_t size) {
    harmony::Memory::AddFreedMemory(size);
    free(memory);
}

#include "EditorApplication.h"
#include "Script/GraphScript/GraphScriptProgramComponent.h"

int main() {
    harmony::Editor app;

    auto *graph = new harmony::GraphScript::CompiledGraph();
    auto graphScriptComponent = app.GetProgramComponent<harmony::GraphScriptProgramComponent>().lock();

    harmony::GraphScript::NodeRegistry* vm = graphScriptComponent->GetNodeRegistry();

    auto proc = []() {

    };

    app.Run("../../../projects/JoltTest/JoltTest.harmonyproj", proc);
    return 0;
}