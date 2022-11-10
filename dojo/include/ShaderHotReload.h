#pragma once
#include "Core/ProgramComponent.h"
#include "FileWatcher.hpp"
#include "Assets/Asset.h"
#include "bx/platform.h"
#include "Rendering/Shader.h"
namespace harmony
{
    class Program;
    class Renderer;
    class ShaderSourceAsset;

    class ShaderHotReload : public ProgramComponent
    {
    public:
        ShaderHotReload(Program& prog);
        virtual void Init() override;
        virtual void Update() override;
        virtual void Render() override;
        virtual void Cleanup() override;
        virtual nlohmann::json ToJson() override;
        virtual void FromJson(const nlohmann::json& json) override;

    protected:
        void OnChange(const std::string& path, const filewatch::Event change_type);
        void ReloadTrackedShaders();
        Program& p_Program;
        Renderer& p_Renderer;
        std::string p_ShaderCompilerLocation;
        
        int CompileShader(const std::string& shaderName);

        filewatch::FileWatch<std::string>* p_FileWatcher;
        std::map<std::string , Ref<ShaderSourceAsset>> p_LoadedShaderSources;
        std::map<std::string, Ref<ShaderStage>> p_LoadedShaderBinaries;
        std::map<std::string, std::string> p_RendererProfileMapping;
#if BX_PLATFORM_WINDOWS
        const std::string PLATFORM_SHADER_COMPILER_EXECUTABLE = "-win.exe";
#elif BX_PLATFORM_OSX
        const std::string PLATFORM_SHADER_COMPILER_EXECUTABLE = "-osx";
#elif BX_PLATFORM_LINUX
        const std::string PLATFORM_SHADER_COMPILER_EXECUTABLE = "-osx";
#endif


    };
}