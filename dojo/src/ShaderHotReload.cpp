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
    p_ShaderCompilerLocation = currentPath + "/../../tools/bgfx-shaderc/bin/shaderc" + PLATFORM_SHADER_COMPILER_EXECUTABLE;

    if (!std::filesystem::exists(p_ShaderCompilerLocation))
    {
        harmony::log::error("ShaderHotReload : Failed to find shaderc executable at path : {}", p_ShaderCompilerLocation);
    }
    p_RendererProfileMapping = {
        {"dx9", "s_3_0"},
        {"dx11", "s_5_0"},
        {"pssl", "pssl"},
        {"metal", "metal"},
        {"glsl", "430"},
        {"essl", "300_es"},
        {"spv", "spirv"},

    };

    p_FileWatcher = new efsw::FileWatcher();
}

harmony::ShaderHotReload::~ShaderHotReload()
{
    delete p_FileWatcher;
}

void harmony::ShaderHotReload::Init()
{
    if (p_Program.m_Project)
    {
        std::string projDirectory = p_Program.m_Project->m_ProjectDirectory;
        std::string shadersDirectory = projDirectory + "\\assets\\shaders";

        efsw::FileWatchListener* listener = this;

        /*p_FileWatcher = new filewatch::FileWatch<std::string>(
            shadersDirectory,
            [&](const std::string& path, const filewatch::Event change_type) {
                OnChange(path, change_type);
            }
        );*/

        p_DirectoryWatchID = p_FileWatcher->addWatch(shadersDirectory, listener, true);
        p_FileWatcher->watch();
    }

    ReloadTrackedShaders();
    
}

void harmony::ShaderHotReload::Update()
{
}

void harmony::ShaderHotReload::Render()
{
}

void harmony::ShaderHotReload::Cleanup()
{
    p_FileWatcher->removeWatch(p_DirectoryWatchID);
}

nlohmann::json harmony::ShaderHotReload::ToJson()
{
    return nlohmann::json();
}

void harmony::ShaderHotReload::FromJson(const nlohmann::json& json)
{
}

void harmony::ShaderHotReload::OnChange(const std::string& filename, const std::string& directory, efsw::Action action)
{
    harmony::log::info("ShaderHotReload : Path : {} Change Type : {}", filename);
    ReloadTrackedShaders();
    // ignore changes to include shader files
    if (filename.find("include") < filename.size())
    {
        return;
    }
    // varying def is only a concern of shaderc
    if (filename.find("varying.def.sc") < filename.size())
    {
        return;
    }
    if (action == efsw::Actions::Add)
    {
        if (filename.find(".sc") < filename.size())
        {
            auto handle = p_Program.m_AssetManager.LoadAsset<ShaderSourceAsset>(filename);
            Ref<ShaderSourceAsset> source = p_Program.m_AssetManager.GetAsset<ShaderSourceAsset>(handle[0]).lock();
            size_t lastIndex = filename.find(".sc");
            std::string shaderName = filename.substr(0, lastIndex);
            if (CompileShader(shaderName) == 0)
            {
                p_LoadedShaderSources.emplace(filename, source);
            }
            else
            {
                harmony::log::error("Failed to compile shader : {}", filename);
            }
        }
        if (filename.find(".bin") < filename.size())
        {
            size_t firstIndex = filename.find_last_of("\\");
            size_t lastIndex = filename.find(".bin");
            std::string shaderName = filename.substr(firstIndex + 1, lastIndex - (firstIndex + 1));

            std::string rendererName = ShaderStage::GetShaderRendererName();
            if (filename.find(rendererName) < filename.size())
            {
                auto handle = p_Program.m_AssetManager.LoadAsset<ShaderStage>(shaderName);
                Ref<ShaderStage> stage = p_Program.m_AssetManager.GetAsset<ShaderStage>(handle[0]).lock();
                p_LoadedShaderBinaries.emplace(shaderName, stage);
            }
        }
    }
    if (action == efsw::Actions::Modified)
    {
        if (filename.find(".sc") < filename.size())
        {
            // Update shader text...
            std::string newText = Utils::LoadStringFromPath("assets/shaders" + filename);
            if (p_LoadedShaderSources.find(filename) == p_LoadedShaderSources.end())
            {
                harmony::log::warn("shader not being tracked by hot reload.");
                return;
            }
            // recompile shader
            size_t lastIndex = filename.find(".sc");
            std::string shaderName = filename.substr(0, lastIndex);
            if (CompileShader(shaderName) > 0)
            {
                harmony::log::error("Failed to compile shader : {}", filename);
            }
        }
        if (filename.find(".bin") < filename.size())
        {
            std::string rendererName = ShaderStage::GetShaderRendererName();
            if (directory.find(rendererName) < directory.size())
            {
                size_t lastIndex = filename.find(".bin");
                std::string shaderName = filename.substr(0, lastIndex);

                if (p_LoadedShaderBinaries.find(shaderName) != p_LoadedShaderBinaries.end())
                {
                    p_LoadedShaderBinaries[shaderName]->LoadShaderBinary();
                    p_Program.m_Renderer.ReloadAllShaders();
                }
            }

        }
    }


}

void harmony::ShaderHotReload::ReloadTrackedShaders()
{
    auto sourceHandles = p_Program.m_AssetManager.GetLoadedAssets<ShaderSourceAsset>();
    auto binaryHandles = p_Program.m_AssetManager.GetLoadedAssets<ShaderStage>();

    p_LoadedShaderSources.clear();
    for (auto handle : sourceHandles)
    {
        p_LoadedShaderSources.emplace(handle.Path, p_Program.m_AssetManager.GetAsset<ShaderSourceAsset>(handle).lock());
    }

    p_LoadedShaderBinaries.clear();
    for (auto handle : binaryHandles)
    {
        p_LoadedShaderBinaries.emplace(handle.Path, p_Program.m_AssetManager.GetAsset<ShaderStage>(handle).lock());
    }
}

int harmony::ShaderHotReload::CompileShader(const std::string& shaderName)
{
    std::string shaderRendererName = ShaderStage::GetShaderRendererName();
    std::string outputPath = std::filesystem::current_path().string() + "//assets/shaders/bin/" + shaderRendererName + "/" + shaderName + ".bin";
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

void harmony::ShaderHotReload::handleFileAction(efsw::WatchID watchid, const std::string& dir, const std::string& filename, efsw::Action action, std::string oldFilename)
{
    OnChange(filename, dir, action);
}
