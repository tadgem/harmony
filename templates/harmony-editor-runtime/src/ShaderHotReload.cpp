#include "ShaderHotReload.h"
#include "Core/Program.h"
#include "Core/Memory.h"
#include "Core/Log.hpp"
#include "Rendering/Shaders/Shader.h"
#include "Assets/ShaderSourceAsset.h"
#include <filesystem>
#include <chrono>
#include <thread>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>


harmony::ShaderHotReload::ShaderHotReload(Program &prog) : AssetHotReloadProvider("Shader"), p_Program(prog),
                                                           p_Renderer(prog.m_Renderer) {
    String currentPath = FileSystem::current_path().string();
    p_ShaderCompilerLocation =
            currentPath + "/../../../../tools/bgfx-shaderc/bin/shaderc" + PLATFORM_SHADER_COMPILER_EXECUTABLE;
    p_Initialized = false;
    if (!FileSystem::exists(p_ShaderCompilerLocation)) {
        harmony::log::error("ShaderHotReload : Failed to find shaderc executable at path : {}",
                            p_ShaderCompilerLocation);
    }

    p_RendererProfileMapping = {
            {"dx9",   "s_3_0"},
            {"dx11",  "s_5_0"},
            {"pssl",  "pssl"},
            {"metal", "metal"},
            {"glsl",  "430"},
            {"essl",  "300_es"},
            {"spv",   "spirv"},
    };

    p_FileWatcher = new efsw::FileWatcher();
}

harmony::ShaderHotReload::~ShaderHotReload() {
    delete p_FileWatcher;
}

void harmony::ShaderHotReload::Init() {
    ReloadTrackedShaders();
}

void
harmony::ShaderHotReload::OnChange(const String &filename, const String &directory, efsw::Action action) {
    harmony::log::info("ShaderHotReload : {} : {} : {}", GetActionName(action), directory, filename);
    // ignore changes to include shader files
    if (filename.find("include") < filename.size()) {
        return;
    }
    // varying def is only a concern of shaderc
    if (filename.find("varying.def.sc") < filename.size()) {
        return;
    }
    if (action == efsw::Actions::Add) {
        if (filename.find(".sc") < filename.size()) {
            auto handle = p_Program.m_AssetManager.LoadAsset<ShaderSourceAsset>(filename);
            RefCntPtr<ShaderSourceAsset> source = p_Program.m_AssetManager.GetAsset<ShaderSourceAsset>(handle[0]).lock();
            size_t lastIndex = filename.find(".sc");
            String shaderName = filename.substr(0, lastIndex);
            if (CompileShader(shaderName) == 0) {
                p_LoadedShaderSources.emplace(filename, source);
                ReloadTrackedShaders();
            } else {
                harmony::log::error("ShaderHotReload : Failed to compile shader : {}", filename);
            }
        }
        if (filename.find(".bin") < filename.size()) {
            size_t firstIndex = filename.find_last_of("\\");
            size_t lastIndex = filename.find(".bin");
            String shaderName = filename.substr(firstIndex + 1, lastIndex - (firstIndex + 1));

            String rendererName = ShaderStage::GetShaderRendererName();
            if (directory.find(rendererName) < directory.size()) {
                auto handle = p_Program.m_AssetManager.LoadAsset<ShaderStage>(shaderName);
                RefCntPtr<ShaderStage> stage = p_Program.m_AssetManager.GetAsset<ShaderStage>(handle[0]).lock();
                p_LoadedShaderBinaries.emplace(shaderName, stage);
                ReloadTrackedShaders();
            }
        }
    }
    if (action == efsw::Actions::Modified) {
        if (filename.find(".sc") < filename.size()) {
            // Update shader text...
            String newText = Utils::LoadStringFromPath("assets/shaders" + filename);
            String finalPath = filename;
            bool found = false;
            for (auto &[path, data]: p_LoadedShaderSources) {
                if (path.find(filename) < path.size()) {
                    found = true;
                    finalPath = path;
                }
                if (path == filename) {
                    found = true;
                }
            }
            if (!found) {
                harmony::log::warn("ShaderHotRelaod : {} not being tracked by hot reload.", filename);
                return;
            }
            // recompile shader
            size_t lastIndex = finalPath.find(".sc");
            String shaderName = finalPath.substr(0, lastIndex);
            if (CompileShader(shaderName) > 0) {
                harmony::log::error("ShaderHotRelaod : Failed to compile shader : {}", filename);
            }

            return;
        }
        if (filename.find(".bin") < filename.size()) {
            String rendererName = ShaderStage::GetShaderRendererName();
            if (directory.find(rendererName) < directory.size()) {
                size_t lastIndex = filename.find(".bin");
                String shaderName = filename.substr(0, lastIndex);

                Chrono::milliseconds timespan(500);
                ThisThread::sleep_for(timespan);

                if (p_LoadedShaderBinaries.find(shaderName) != p_LoadedShaderBinaries.end()) {
                    p_LoadedShaderBinaries[shaderName]->LoadShaderBinary();
                    p_Program.m_Renderer.ReloadAllShaders();
                } else {
                    auto handle = p_Program.m_AssetManager.LoadAsset<ShaderStage>(shaderName);
                    RefCntPtr<ShaderStage> stage = p_Program.m_AssetManager.GetAsset<ShaderStage>(handle[0]).lock();
                    p_LoadedShaderBinaries.emplace(shaderName, stage);
                    ReloadTrackedShaders();
                }
            }

        }
    }


}

void harmony::ShaderHotReload::ReloadTrackedShaders() {
    auto sourceHandles = p_Program.m_AssetManager.GetLoadedAssets<ShaderSourceAsset>();
    auto binaryHandles = p_Program.m_AssetManager.GetLoadedAssets<ShaderStage>();

    p_LoadedShaderSources.clear();
    for (auto handle: sourceHandles) {
        p_LoadedShaderSources.emplace(handle.Path, p_Program.m_AssetManager.GetAsset<ShaderSourceAsset>(handle).lock());
    }

    p_LoadedShaderBinaries.clear();
    for (auto handle: binaryHandles) {
        p_LoadedShaderBinaries.emplace(handle.Path, p_Program.m_AssetManager.GetAsset<ShaderStage>(handle).lock());
    }
}

int harmony::ShaderHotReload::CompileShader(const String &shaderName) {
    String shaderRendererName = ShaderStage::GetShaderRendererName();
    String outputPath =
            FileSystem::current_path().string() + "//assets/shaders/bin/" + shaderRendererName + "/" + shaderName +
            ".bin";
    String input = "assets/shaders/" + shaderName + ".sc";
    String varyingDefPath = "assets/shaders/varying.def.sc";
    String includePath = "assets/shaders/include";
    String shaderStage = "";

    ShaderStage::Type type = ShaderStage::Type::Unknown;

    if (shaderName.find("vs") < shaderName.size()) {
        type = ShaderStage::Type::Vertex;
    }

    if (shaderName.find("fs") < shaderName.size()) {
        type = ShaderStage::Type::Fragment;
    }

    if (shaderName.find("cs") < shaderName.size()) {
        type = ShaderStage::Type::Compute;
    }

    switch (type) {
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

    String compileCommand = p_ShaderCompilerLocation;

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
    compileCommand += FileSystem::current_path().string() + "\\" + varyingDefPath;
    //profile arg
    compileCommand += " -p ";

    auto rendererType = bgfx::getRendererType();
    String profileName = "";
    switch (rendererType) {
        case bgfx::RendererType::Direct3D9:
        case bgfx::RendererType::Direct3D11:
        case bgfx::RendererType::Direct3D12:
            profileName = p_RendererProfileMapping[shaderRendererName];
            break;
        default:
            profileName = p_RendererProfileMapping[shaderRendererName];
    }

    //profile
    compileCommand += profileName;

    harmony::log::info("ShaderHotReload : final compile command for input file {} : {}", shaderName, compileCommand);
    auto ret = Exec(compileCommand.c_str());

    harmony::log::info("ShaderHotReload : Compile Result : {}", ret);

    return 0;
}

harmony::String harmony::ShaderHotReload::Exec(const char *command) {
    Array<char, 128> buffer;
    String result;
#if BX_PLATFORM_WINDOWS
    CustomUPtr<FILE, decltype(&_pclose)> pipe(_popen(command, "r"), _pclose);
#else
    CustomUPtr<FILE, decltype(&pclose)> pipe(popen(command, "r"), pclose);
#endif
    if (!pipe) {
        return "Error";
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    return result;
}

