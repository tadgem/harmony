#pragma once
#include "Core/ProgramComponent.h"
#include "bx/platform.h"

#include "Core/FileWatcher.hpp"

namespace harmony
{
    class Program;
    class Renderer;
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
        Program& p_Program;
        Renderer& p_Renderer;
        std::string p_ShaderCompilerLocation;

        filewatch::FileWatch<std::string>* p_FileWatcher;
        std::vector<std::string> p_LoadedShaderSources;
        std::vector<std::string> p_LoadedShaderBinaries;
#if BX_PLATFORM_WINDOWS
        const std::string PLATFORM_SHADER_COMPILER_EXTENSION = ".exe";
#endif
    };
}