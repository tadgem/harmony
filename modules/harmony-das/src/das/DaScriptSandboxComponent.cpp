#include "das/DaScriptSandboxComponent.h"
#include "src/dasBGFX.h"
#include "dasIMGUI.h"
#include "das/STBImageModule.h"
#include "Core/Log.hpp"
#include "das/Assets/DaScriptAsset.h"
harmony::DaScriptSandboxComponent::DaScriptSandboxComponent(AssetManager& assetManager) : p_AssetManager(assetManager)
{
    m_TypeHash = typeid(DaScriptSandboxComponent).hash_code();
    p_fInit = nullptr;
    p_fUpdate = nullptr;
    p_fCleanup = nullptr;
    p_fRender = nullptr;
    // request all da-script built in modules
    NEED_ALL_DEFAULT_MODULES;
    using namespace das;
    // request stb image
    NEED_MODULE(Module_dasStbImage)
        // request our custom module
        NEED_MODULE(Module_dasBGFX);
    // request our custom module
    NEED_MODULE(Module_dasIMGUI);

    // Initialize modules
    das::Module::Initialize();
}

harmony::DaScriptSandboxComponent::~DaScriptSandboxComponent()
{
    das::Module::Shutdown();
}

void harmony::DaScriptSandboxComponent::Init()
{
    std::string pathString = std::filesystem::current_path().string();
    das::setDasRoot(pathString);
    das::TextPrinter tout;                               // output stream for all compiler messages (stdout. for stringstream use TextWriter)
    das::ModuleGroup dummyLibGroup;                      // module group for compiled program
    auto fAccess = das::make_smart<das::FsFileAccess>();      // default file access
    // compile program
    auto program = compileDaScript(p_SelectedScript, fAccess, tout, dummyLibGroup);

    if (program->failed()) {
        // if compilation failed, report errors
        log::error("daScript : Failed to compile script {} :", p_SelectedScript);
        for (auto& err : program->errors) {
            log::error(" - {}", reportError(err.at, err.what, err.extra, err.fixme, err.cerr));
        }
        return;
    }

    // create daScript context
    p_Context = CreateRef<das::Context>(program->getContextStackSize());
    if (!program->simulate(*p_Context, tout)) {
        // if interpretation failed, report errors
        log::error("daScript : Failed to simulate script {} :", p_SelectedScript);
        log::error("daScript : Failed to simulate script {} :", p_SelectedScript);
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
    p_fRender = p_Context->findFunction("render");
    if (!p_fRender) {
        log::error("function 'render' not found\n");
        p_fRender = nullptr;
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

void harmony::DaScriptSandboxComponent::Update()
{
    if (ImGui::Begin("Script Sandbox Settings"))
    {
        if (ImGui::BeginCombo("Choose Script", p_SelectedScript.c_str()))
        {
            for (std::string option : p_AvailableScripts)
            {
                if (ImGui::Selectable(option.c_str()))
                {
                    p_SelectedScript = option;
                }
            }
            ImGui::EndCombo();
        }
        

        if(ImGui::Button("Reload Script"))
        {
            Cleanup();
            Init();
        }
    }
    ImGui::End();

    p_AssetManager.OnImGui();

    if (p_fUpdate == nullptr) return;
    p_Context->eval(p_fUpdate, nullptr);
    if (auto ex = p_Context->getException()) {
        log::error("daScript : update : exception: {}", ex);
        return;
    }
}

void harmony::DaScriptSandboxComponent::Render()
{
    if (p_fRender == nullptr) return;
    p_Context->eval(p_fRender, nullptr);
    if (auto ex = p_Context->getException()) {
        log::error("daScript : render : exception: {}", ex);
        return;
    }
}

void harmony::DaScriptSandboxComponent::Cleanup()
{
    if (p_fCleanup != nullptr)
    {
        p_Context->eval(p_fCleanup, nullptr);
        if (auto ex = p_Context->getException()) {
            log::error("daScript : cleanup : exception: {}", ex);
            return;
        }
    }
    p_Context.reset();
}

void harmony::DaScriptSandboxComponent::RefreshAvailableScripts()
{
    p_AvailableScripts.clear();
    auto scripts = p_AssetManager.GetAllAssetsOfType<DaScriptAsset>();
    for (auto& wr : scripts)
    {
        auto script = wr.lock();
        p_AvailableScripts.emplace_back(script->m_AssetPath);
    }
}

nlohmann::json harmony::DaScriptSandboxComponent::ToJson()
{
    nlohmann::json json = nlohmann::json();
    std::string hash = std::to_string(m_TypeHash);
    json[hash] = nlohmann::json(p_AvailableScripts);

    return json;
}

void harmony::DaScriptSandboxComponent::FromJson(const nlohmann::json& json)
{
    harmony::log::warn("attempting to deserialize script json");
    std::string typeHash = std::to_string(m_TypeHash);
    for (auto path : json[typeHash])
    {
        std::string pathStr = path.get<std::string>();
        p_AssetManager.LoadAssetFromPath<DaScriptAsset>(pathStr);
    }
}

void harmony::DaScriptSandboxComponent::Refresh()
{
    Cleanup();
    RefreshAvailableScripts();
    Init();
}
