#include "Core/ProgramComponent.h"
#include "Core/Memory.h"
#include "Project.h"
#include "Assets/AssetManager.h"
#include "daScript/daScript.h"
#include <string>
namespace harmony
{
    class ScriptSandboxComponent : public ProgramComponent
    {
    public:
        ScriptSandboxComponent(AssetManager& assetManager);
        virtual ~ScriptSandboxComponent() override;
        // Inherited via ProgramComponent
        virtual void Init() override;
        virtual void Update() override;
        virtual void Render() override;
        virtual void Cleanup() override;

        void RefreshAvailableScripts();

    private:
        std::vector<std::string> p_AvailableScripts;
        std::string p_SelectedScript;
        Ref<das::Context> p_Context;
        Ref<Project> p_Project;
        das::SimFunction* p_fInit;
        das::SimFunction* p_fUpdate;
        das::SimFunction* p_fCleanup;
        AssetManager& p_AssetManager;
    };
};
