#include "Core/Memory.h"
#include "EditorApplication.h"
#include <filesystem>

void *operator new(size_t size) {
    harmony::Memory::AddAllocatedMemory(size);
    return malloc(size);
}

void operator delete(void *memory, size_t size) {
    harmony::Memory::AddFreedMemory(size);
    free(memory);
}


int main() {
    harmony::Editor app;

    std::cout << std::filesystem::current_path() << std::endl;
    app.Run("../../../../../../projects/JoltTest/JoltTest.harmonyproj", NULL);

    return 0;
}