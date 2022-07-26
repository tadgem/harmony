#include "ShaderHotReload.h"
#include "Core/Program.h"
#include "Core/Memory.h"
#include "Core/Log.hpp"
#include "Rendering/Renderer.h"
#include "Assets/ShaderSourceAsset.h"
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
        std::string shadersDirectory = projDirectory + "\\assets\\shaders";

        p_FileWatcher = new filewatch::FileWatch<std::string>(
            shadersDirectory,
            [&](const std::string& path, const filewatch::Event change_type) {
                OnChange(path, change_type);
            }

        );
    }

    auto sourceHandles = p_Program.m_AssetManager.GetLoadedAssets<ShaderSourceAsset>();
    auto binaryHandles = p_Program.m_AssetManager.GetLoadedAssets<ShaderStage>();
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

    if (change_type == filewatch::Event::added)
    {
        if (path.find(".sc") < path.size())
        {
            p_Program.m_AssetManager.LoadAsset<ShaderSourceAsset>(path);
            size_t lastIndex = path.find(".sc");
            std::string shaderName = path.substr(0, lastIndex);

            p_LoadedShaderSources.emplace_back(shaderName);
        }
        if (path.find(".bin") < path.size())
        {
            size_t firstIndex = path.find_last_of("\\");
            size_t lastIndex = path.find(".bin");
            std::string shaderName = path.substr(firstIndex + 1, lastIndex - (firstIndex + 1));

            p_LoadedShaderSources.emplace_back(shaderName);
            p_Program.m_AssetManager.LoadAsset<ShaderStage>(shaderName);
        }
    }
    if (change_type == filewatch::Event::modified)
    {
        if (path.find(".sc") < path.size())
        {
            
        }
        if (path.find(".bin") < path.size())
        {

        }
    }


}
