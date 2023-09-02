#include "Core/Memory.h"
#include "bx/platform.h"
#include <filesystem> 

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

    std::cout << std::filesystem::current_path() << std::endl;

#if BX_PLATFORM_WINDOWS
    app.Run("../../projects/JoltTest/JoltTest.harmonyproj", NULL);
#else
    app.Run("../../../projects/JoltTest/JoltTest.harmonyproj", proc);

#endif
    return 0;
}