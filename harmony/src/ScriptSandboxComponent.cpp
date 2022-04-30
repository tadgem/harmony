#include "ScriptSandboxComponent.h"
#include "src/dasBGFX.h"
#include "daScript/STBImageModule.h"
#include "Log.hpp"
harmony::ScriptSandboxComponent::ScriptSandboxComponent()
{
}

void harmony::ScriptSandboxComponent::Init()
{
    // request all da-script built in modules
    NEED_ALL_DEFAULT_MODULES;
    using namespace das;
    // request stb image
    NEED_MODULE(Module_dasStbImage)
    // request our custom module
    NEED_MODULE(Module_dasBGFX);
    
    // Initialize modules
    das::Module::Initialize();

    das::TextPrinter tout;                               // output stream for all compiler messages (stdout. for stringstream use TextWriter)
    das::ModuleGroup dummyLibGroup;                      // module group for compiled program
    auto fAccess = das::make_smart<das::FsFileAccess>();      // default file access
    // compile program
    auto program = compileDaScript(m_ScriptPath, fAccess, tout, dummyLibGroup);

    if (program->failed()) {
        // if compilation failed, report errors
        log::error("daScript : Failed to compile script {} :", m_ScriptPath);
        for (auto& err : program->errors) {
            log::error(" - {}", reportError(err.at, err.what, err.extra, err.fixme, err.cerr));
        }
        return;
    }

    // create daScript context
    p_Context = CreateRef<das::Context>(program->getContextStackSize());
    if (!program->simulate(*p_Context, tout)) {
        // if interpretation failed, report errors
        log::error("daScript : Failed to simulate script {} :", m_ScriptPath);
        for (auto& err : program->errors) {
            log::error(" - {}", reportError(err.at, err.what, err.extra, err.fixme, err.cerr));
        }
        return;
    }

    // find function 'init' in the context
    p_fInit = p_Context->findFunction("init");
    if (!p_fInit) {
        log::error("function 'init' not found\n");
        p_fInit = nullptr;
    }

    // find function 'init' in the context
    p_fUpdate = p_Context->findFunction("update");
    if (!p_fUpdate) {
        log::error("function 'update' not found\n");
        p_fUpdate = nullptr;
    }

    // find function 'init' in the context
    p_fCleanup = p_Context->findFunction("cleanup");
    if (!p_fCleanup) {
        log::error("function 'cleanup' not found\n");
        p_fCleanup = nullptr;
    }

    // verify if 'test' is a function, with the correct signature
    // note, this operation is slow, so don't do it every time for every call
    /*if (!verifyCall<void>(fnTest->debugInfo, dummyLibGroup)) {
        tout << "function 'test', call arguments do not match. expecting def test : void\n";
        return;
    }*/
    // evaluate 'init' function in the context

    if (p_fInit == nullptr) return;
    p_Context->eval(p_fInit, nullptr);
    if (auto ex = p_Context->getException()) {
        log::error("daScript : init : exception: {}", ex);
        return;
    }
}

void harmony::ScriptSandboxComponent::Update()
{
    if (p_fUpdate == nullptr) return;
    p_Context->eval(p_fUpdate, nullptr);
    if (auto ex = p_Context->getException()) {
        log::error("daScript : update : exception: {}", ex);
        return;
    }
}

void harmony::ScriptSandboxComponent::Render()
{
}

void harmony::ScriptSandboxComponent::Cleanup()
{
    if (p_fCleanup != nullptr)
    {
        p_Context->eval(p_fCleanup, nullptr);
        if (auto ex = p_Context->getException()) {
            log::error("daScript : cleanup : exception: {}", ex);
            return;
        }
    }
    das::Module::Shutdown();
}
