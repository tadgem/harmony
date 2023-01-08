#pragma once
#include "Core/ProgramComponent.h"
#include "Assets/Asset.h"
#include "bx/platform.h"
#include "Rendering/Shader.h"
#include "efsw/efsw.hpp"

namespace harmony
{
    class Program;
    class Renderer;
    class ShaderSourceAsset;

    class ShaderHotReload : public ProgramComponent, public efsw::FileWatchListener
    {
    public:
        ShaderHotReload(Program& prog);
        ~ShaderHotReload();
        virtual void Init() override;
        virtual void Update() override;
        virtual void Render() override;
        virtual void Cleanup() override;
        virtual nlohmann::json ToJson() override;
        virtual void FromJson(const nlohmann::json& json) override;

    protected:
        Program& p_Program;
        Renderer& p_Renderer;
        std::string p_ShaderCompilerLocation;

        int CompileShader(const std::string& shaderName);
        void ReloadTrackedShaders();
        
        void OnChange(const std::string& filename, const std::string& directory, efsw::Action action);
        void handleFileAction(efsw::WatchID watchid, const std::string& dir, const std::string& filename, efsw::Action action, std::string oldFilename) override;

        std::map<std::string , Ref<ShaderSourceAsset>> p_LoadedShaderSources;
        std::map<std::string, Ref<ShaderStage>> p_LoadedShaderBinaries;
        std::map<std::string, std::string> p_RendererProfileMapping;

        efsw::FileWatcher* p_FileWatcher;
        efsw::WatchID p_DirectoryWatchID;

        bool p_Initialized;

#if BX_PLATFORM_WINDOWS
        const std::string PLATFORM_SHADER_COMPILER_EXECUTABLE = "-win.exe";
#elif BX_PLATFORM_OSX
        const std::string PLATFORM_SHADER_COMPILER_EXECUTABLE = "-osx";
#elif BX_PLATFORM_LINUX
        const std::string PLATFORM_SHADER_COMPILER_EXECUTABLE = "-osx";
#endif


    };
}