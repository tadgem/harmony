#pragma once

#include "AssetHotReload.h"
#include "Assets/Asset.h"
#include "bx/platform.h"
#include "Rendering/Shaders/Shader.h"

namespace harmony {
    class Program;

    class Renderer;

    class ShaderSourceAsset;

    class ShaderHotReload : public AssetHotReloadProvider {
    public:
        ShaderHotReload(Program &prog);

        ~ShaderHotReload();

        virtual void Init() override;

    protected:
        Program &p_Program;
        Renderer &p_Renderer;
        std::string p_ShaderCompilerLocation;

        int CompileShader(const std::string &shaderName);

        String Exec(const char *command);

        void ReloadTrackedShaders();

        void OnChange(const std::string &filename, const std::string &directory, efsw::Action action);

        std::map<std::string, RefCntPtr<ShaderSourceAsset>> p_LoadedShaderSources;
        std::map<std::string, RefCntPtr<ShaderStage>> p_LoadedShaderBinaries;
        std::map<std::string, std::string> p_RendererProfileMapping;

        efsw::FileWatcher *p_FileWatcher;
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