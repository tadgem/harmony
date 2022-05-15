#include "Core/ProgramComponent.h"
#include "Core/Memory.h"
#include "Project.h"
#include "Assets/AssetManager.h"
#include "daScript/daScript.h"
#include <string>
namespace harmony
{
    class DaScriptSandboxComponent : public ProgramComponent
    {
    public:
        DaScriptSandboxComponent(AssetManager& assetManager);
        virtual ~DaScriptSandboxComponent() override;
        // Inherited via ProgramComponent
        virtual void Init() override;
        virtual void Update() override;
        virtual void Render() override;
        virtual void Cleanup() override;
        virtual nlohmann::json ToJson() override;
        virtual void FromJson(const nlohmann::json& json) override;
        virtual void Refresh() override;
        void RefreshAvailableScripts();
        
    private:
        std::vector<std::string> p_AvailableScripts;
        std::string p_SelectedScript;
        Ref<das::Context> p_Context;
        Ref<Project> p_Project;
        das::SimFunction* p_fInit;
        das::SimFunction* p_fUpdate;
        das::SimFunction* p_fRender;
        das::SimFunction* p_fCleanup;
        AssetManager& p_AssetManager;        
    };
};
