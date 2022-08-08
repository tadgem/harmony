#include "ShaderHotReload.h"
#include "Core/Program.h"
#include "Core/Memory.h"
#include "Core/Log.hpp"
#include "Rendering/Renderer.h"
#include "Rendering/Shader.h"
#include "Assets/ShaderSourceAsset.h"
#include <filesystem>
harmony::ShaderHotReload::ShaderHotReload(Program& prog) : p_Program(prog), p_Renderer(prog.m_Renderer)
{
    std::string currentPath = std::filesystem::current_path().string();
    p_ShaderCompilerLocation = currentPath + "/shaderc" + PLATFORM_SHADER_COMPILER_EXECUTABLE;

    p_RendererProfileMapping = {
        {"dx9", "s_3_0"},
        {"dx11", "s_5_0"},
        {"pssl", "pssl"},
        {"metal", "metal"},
        {"glsl", "430"},
        {"essl", "300_es"},
        {"spv", "spirv"},

    };
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

    for (auto handle : sourceHandles)
    {
        p_LoadedShaderSources.emplace(handle.Path, p_Program.m_AssetManager.GetAsset<ShaderSourceAsset>(handle).lock());
    }

    for (auto handle : binaryHandles)
    {
        p_LoadedShaderBinaries.emplace(handle.Path, p_Program.m_AssetManager.GetAsset<ShaderStage>(handle).lock());
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
    // ignore changes to include shader files
    if (path.find("include") < path.size())
    {
        return;
    }
    // varying def is only a concern of shaderc
    if (path.find("varying.def.sc") < path.size())
    {
        return;
    }
    if (change_type == filewatch::Event::added)
    {
        if (path.find(".sc") < path.size())
        {
            auto handle = p_Program.m_AssetManager.LoadAsset<ShaderSourceAsset>(path);
            Ref<ShaderSourceAsset> source = p_Program.m_AssetManager.GetAsset<ShaderSourceAsset>(handle[0]).lock();
            size_t lastIndex = path.find(".sc");
            std::string shaderName = path.substr(0, lastIndex);
            if (CompileShader(shaderName) == 0)
            {
                p_LoadedShaderSources.emplace(path, source);
            }
            else
            {
                harmony::log::error("Failed to compile shader : {}", path);
            }
        }
        if (path.find(".bin") < path.size())
        {
            size_t firstIndex = path.find_last_of("\\");
            size_t lastIndex = path.find(".bin");
            std::string shaderName = path.substr(firstIndex + 1, lastIndex - (firstIndex + 1));

            std::string rendererName = ShaderStage::GetShaderRendererName();
            if (path.find(rendererName) < path.size())
            {
                auto handle = p_Program.m_AssetManager.LoadAsset<ShaderStage>(shaderName);
                Ref<ShaderStage> stage = p_Program.m_AssetManager.GetAsset<ShaderStage>(handle[0]).lock();
                p_LoadedShaderBinaries.emplace(shaderName, stage);
            }
        }
    }
    if (change_type == filewatch::Event::modified)
    {
        if (path.find(".sc") < path.size())
        {
            // Update shader text...
            std::string newText = Utils::LoadStringFromPath("assets/shaders" + path);
            if (p_LoadedShaderSources.find(path) == p_LoadedShaderSources.end())
            {
                harmony::log::warn("shader not being tracked by hot reload.");
                return;
            }
            // recompile shader
            size_t lastIndex = path.find(".sc");
            std::string shaderName = path.substr(0, lastIndex);
            if (CompileShader(shaderName) > 0)
            {
                harmony::log::error("Failed to compile shader : {}", path);
            }
        }
        if (path.find(".bin") < path.size())
        {
            std::string rendererName = ShaderStage::GetShaderRendererName();
            if (path.find(rendererName) < path.size())
            {
                size_t firstIndex = path.find_last_of("\\");
                size_t lastIndex = path.find(".bin");
                std::string shaderName = path.substr(firstIndex + 1, lastIndex - (firstIndex + 1));

                if (p_LoadedShaderBinaries.find(shaderName) != p_LoadedShaderBinaries.end())
                {
                    p_LoadedShaderBinaries[shaderName]->LoadShaderBinary();
                    p_Program.m_Renderer.ReloadAllShaders();
                }
            }

        }
    }


}

int harmony::ShaderHotReload::CompileShader(const std::string& shaderName)
{
    std::string shaderRendererName = ShaderStage::GetShaderRendererName();
    std::string outputPath = "assets/shaders/bin/" + shaderRendererName + "/" + shaderName + ".bin";
    std::string input = "assets/shaders/" + shaderName + ".sc";
    std::string varyingDefPath = "assets/shaders/varying.def.sc";
    std::string includePath = "assets/shaders/include";
    std::string shaderStage = "";

    ShaderStage::Type type = ShaderStage::Type::Unknown;

    if (shaderName.find("vs") < shaderName.size())
    {
        type = ShaderStage::Type::Vertex;
    }

    if (shaderName.find("fs") < shaderName.size())
    {
        type = ShaderStage::Type::Fragment;
    }

    if (shaderName.find("cs") < shaderName.size())
    {
        type = ShaderStage::Type::Compute;
    }

    switch (type)
    {
    case ShaderStage::Type::Vertex:
        shaderStage = "v";
        break;
    case ShaderStage::Type::Fragment:
        shaderStage = "f";
        break;
    case ShaderStage::Type::Compute:
        shaderStage = "c";
        break;
    default:
        harmony::log::warn("Unknown Shader Type provided when compiling shader : {}", shaderName);
        return 1;
    }

    std::string compileCommand = p_ShaderCompilerLocation;

    //input file arg
    compileCommand += " -f ";
    //input file path
    compileCommand += input;
    //include path arg
    compileCommand += " -i ";
    //include path
    compileCommand += includePath;
    //output path // arg
    compileCommand += " -o ";
    //output path
    compileCommand += outputPath;
    //shader stage arg
    compileCommand += " --type ";
    // shader stage
    compileCommand += shaderStage;
    // varying def arg
    compileCommand += " --varyingdef ";
    //varying def path
    compileCommand += varyingDefPath;
    //profile arg
    compileCommand += " -p ";

    auto rendererType = bgfx::getRendererType();
    std::string profileName = "";
    switch (rendererType)
    {
        case bgfx::RendererType::Direct3D9:
        case bgfx::RendererType::Direct3D11:
        case bgfx::RendererType::Direct3D12:
            if (shaderStage == "f")
            {
                profileName = "p" + p_RendererProfileMapping[shaderRendererName];
                break;
            }

            profileName = shaderStage + p_RendererProfileMapping[shaderRendererName];
            break;
        default:
            profileName = p_RendererProfileMapping[shaderRendererName];
    }

    //profile
    compileCommand += profileName;

    harmony::log::info("ShaderHotReload : final compile command for input file {} : {}", shaderName, compileCommand);
    return system(compileCommand.c_str());

}
