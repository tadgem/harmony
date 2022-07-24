#include "ShaderHotReload.h"
#include "Core/Program.h"
#include "Core/Memory.h"
#include "Core/Log.hpp"
#include "Rendering/Renderer.h"
#include <filesystem>
harmony::ShaderHotReload::ShaderHotReload(Program& prog) : p_Program(prog), p_Renderer(prog.m_Renderer)
{
    std::string currentPath = std::filesystem::current_path().string();
    p_ShaderCompilerLocation = currentPath + "/shaderc" + PLATFORM_SHADER_COMPILER_EXTENSION;
    int i = 1;
}

void harmony::ShaderHotReload::Init()
{
    if (p_Program.m_Project)
    {
        std::string projDirectory = p_Program.m_Project->m_ProjectDirectory;
        std::string shadersDirectory = projDirectory + "\\shaders";

        p_FileWatcher = new filewatch::FileWatch<std::string>(
            shadersDirectory,
            [&](const std::string& path, const filewatch::Event change_type) {
                OnChange(path, change_type);
            }

        );
    }
}

void harmony::ShaderHotReload::Update()
{
}

void harmony::ShaderHotReload::Render()
{
}

void harmony::ShaderHotReload::Cleanup()
{
}

nlohmann::json harmony::ShaderHotReload::ToJson()
{
    return nlohmann::json();
}

void harmony::ShaderHotReload::FromJson(const nlohmann::json& json)
{
}

void harmony::ShaderHotReload::OnChange(const std::string& path, const filewatch::Event change_type)
{
    harmony::log::info("Path : {} Change Type : {}", path);

    // if(change_type == filewatch::Event::)
}
