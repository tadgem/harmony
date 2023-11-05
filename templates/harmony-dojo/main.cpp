#include "Core/Memory.h"
#include "EditorApplication.h"
#include <filesystem>
#include "MiniGuis/LoadProjectGui.h"

void *operator new(size_t size) {
    harmony::Memory::AddAllocatedMemory(size);
    return malloc(size);
}

void operator delete(void *memory, size_t size) {
    harmony::Memory::AddFreedMemory(size);
    free(memory);
}


int main() {
    using namespace harmony;
    Editor app;

    app.AddMiniGuiApp(CreateRef<LoadProjectGui>(app));

    std::cout << std::filesystem::current_path() << std::endl;
    app.Run("../../../../projects/MonoTest/MonoTest.harmonyproj", NULL);

    return 0;
}