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
        String p_ShaderCompilerLocation;

        int CompileShader(const String &shaderName);

        String Exec(const char *command);

        void ReloadTrackedShaders();

        void OnChange(const String &filename, const String &directory, efsw::Action action);

        Map<String, RefCntPtr<ShaderSourceAsset>> p_LoadedShaderSources;
        Map<String, RefCntPtr<ShaderStage>> p_LoadedShaderBinaries;
        Map<String, String> p_RendererProfileMapping;

        efsw::FileWatcher *p_FileWatcher;
        efsw::WatchID p_DirectoryWatchID;

        bool p_Initialized;

#if BX_PLATFORM_WINDOWS
        const String PLATFORM_SHADER_COMPILER_EXECUTABLE = "-win.exe";
#elif BX_PLATFORM_OSX
        const String PLATFORM_SHADER_COMPILER_EXECUTABLE = "-osx";
#elif BX_PLATFORM_LINUX
        const String PLATFORM_SHADER_COMPILER_EXECUTABLE = "-osx";
#endif


    };
}