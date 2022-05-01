#include "Core/ProgramComponent.h"
#include "Core/Memory.h"
#include "daScript/daScript.h"
#include <string>
namespace harmony
{
    class ScriptSandboxComponent : public ProgramComponent
    {
    public:
        ScriptSandboxComponent();
        ~ScriptSandboxComponent() {}
        // Inherited via ProgramComponent
        virtual void Init() override;
        virtual void Update() override;
        virtual void Render() override;
        virtual void Cleanup() override;

        std::string m_ScriptPath = "testscript.das";
    private:
        Ref<das::Context> p_Context;
        das::SimFunction* p_fInit;
        das::SimFunction* p_fUpdate;
        das::SimFunction* p_fCleanup;
    };
};
