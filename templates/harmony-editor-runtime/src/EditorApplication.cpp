#include <optick.h>
#include <Rendering/Pipelines/PipelineStages/DrawScreenTextureStage.h>
#include <Rendering/Modules/Moebius/MoebiusModule.h>
#include "EditorApplication.h"
#include "Rendering/Shapes.h"
#include "ECS/MaterialSystem.h"
#include "ECS/CameraSystem.h"
#include "Core/Time.h"
#include "Core/Input.h"
#include "ShaderHotReload.h"
#include "LuaScriptHotReload.h"
#include "Rendering/Views/RuntimeView.h"
#include "Rendering/Pipelines/PipelineStageRenderers/MeshRenderer.h"
#include "Assets/ShaderSourceAssetFactory.h"
#include "AssimpModelAssetFactory.h"
#include "EditorView.h"
#include "JoltMonoBind.h"
#include "Script/GraphScript/GraphScriptProgramComponent.h"

harmony::Editor::Editor() : harmony::RuntimeProgram("Editor"), p_MainMenuBar(*this) {
    OPTICK_EVENT();
    //m_Logger.Init();
    Editor::AddAssetTypeNames();
    Editor::AddAssetFactories();
    Editor::AddProgramComponents();
    Editor::AddSystems();
    log::info("Editor : Add PipelineStageRenderers");
    Editor::AddPipelineStageRenderers();
    AddEditorPanels();
}

void harmony::Editor::AddAssetTypeNames() {
    OPTICK_EVENT();
    m_AssetManager.AddAssetTypeName<ShaderSourceAsset>();
}

void harmony::Editor::AddAssetFactories() {
    OPTICK_EVENT();
    m_AssetManager.AddAssetFactory(CreateRef<ShaderSourceAssetFactory>());
}

void harmony::Editor::AddProgramComponents() {
    OPTICK_EVENT();
    auto assetHotReload = AddProgramComponent<AssetHotReload>(*this).lock();
    auto shaderProvider = CreateRef<ShaderHotReload>(*this);
    auto luaProvider = CreateRef<LuaScriptHotReload>(*this, p_LuaSystem);

    assetHotReload->AddHotReloadProvider(shaderProvider);
    assetHotReload->AddHotReloadProvider(luaProvider);
}

void harmony::Editor::AddSystems() {
    OPTICK_EVENT();
    p_TransformSystem = GetSystem<TransformSystem>().lock();
    p_CameraSystem = GetSystem<CameraSystem>().lock();
    p_MeshSystem = GetSystem<MeshSystem>().lock();
    p_LightSystem = GetSystem<LightSystem>().lock();

}

void harmony::Editor::AddPipelineStageRenderers() {
    OPTICK_EVENT();
    RuntimeProgram::AddPipelineStageRenderers();
}

void harmony::Editor::AddEditorPanels() {
    OPTICK_EVENT();
    p_ScenePanel = CreateRef<ScenePanel>(*this);
    p_Panels.emplace_back(p_ScenePanel);

    RefCntPtr<AssetManagerPanel> assetManagerPanel = CreateRef<AssetManagerPanel>(*this);
    RefCntPtr<LuaScriptPanel> luaScriptPanel = CreateRef<LuaScriptPanel>(*this);
    RefCntPtr<MonoPanel> monoPanel = CreateRef<MonoPanel>(*this);

    p_Panels.emplace_back(assetManagerPanel);
    p_Panels.emplace_back(luaScriptPanel);
    p_Panels.emplace_back(monoPanel);

    RefCntPtr<EntityInspectorPanel> inspector = CreateRef<EntityInspectorPanel>(*this, p_ScenePanel);
    inspector->AddComponentUI<EntityDataComponentUI>();
    inspector->AddComponentUI<TransformComponentUI>();
    inspector->AddComponentUI<MeshComponentUI>(m_AssetManager);
    inspector->AddComponentUI<MaterialComponentUI>(m_Renderer, m_AssetManager);
    inspector->AddComponentUI<CameraComponentUI>(m_Renderer);
    inspector->AddComponentUI<DirectionalLightComponentUI>();
    inspector->AddComponentUI<PointLightComponentUI>();
    inspector->AddComponentUI<SpotLightComponentUI>();
    inspector->AddComponentUI<SkyComponentUI>();
    inspector->AddComponentUI<LuaScriptComponentUI>(m_AssetManager);
    inspector->AddComponentUI<JoltBodyComponentUI>();
    inspector->AddComponentUI<MonoBehaviourComponentUI>(p_MonoSystem, m_AssetManager);

    p_Panels.emplace_back(inspector);
}

void harmony::Editor::InitializePipelines() {
    OPTICK_EVENT();
    RuntimeProgram::InitializePipelines();
    // return;
    auto skyFB = p_EditorPipeline->AddFramebuffer("Sky FB", {AttachmentType::RGBA16F}, Resolution::Type::FullScale);
    auto mainFB = p_EditorPipeline->AddFramebuffer("Forward FB", {AttachmentType::RGBA16F, AttachmentType::Depth32F},
                                                   Resolution::Type::FullScale);
    auto vectorFB = p_EditorPipeline->AddFramebuffer("Vector FB", {AttachmentType::RGBA8}, Resolution::Type::FullScale);
    auto finalFB = p_EditorPipeline->AddFramebuffer("Final FB", {AttachmentType::RGBA8}, Resolution::Type::FullScale);

    auto crosshatchTexture = m_AssetManager.GetAsset<TextureAsset>("assets\\crosshatch.png");
    auto moebiusFB = Moebius::AddMoebiusToPipeline(m_Renderer, p_EditorPipeline, crosshatchTexture.lock());
    auto screenShaderWR = m_Renderer.p_PresentProgram;

    if (screenShaderWR.expired()) {
        harmony::log::error(
                "RuntimeProgram : Initialize Pipelines : Present Program is expired. This should never happen.");
        return;
    }

    RefCntPtr<DrawScreenTextureStage> drawSkyStage = CreateRef<DrawScreenTextureStage>(screenShaderWR, AttachmentType::RGBA8,
                                                                                 Vector<WeakPtr<Framebuffer>>{skyFB});
    RefCntPtr<DrawScreenTextureStage> drawForwardStage = CreateRef<DrawScreenTextureStage>(screenShaderWR,
                                                                                     AttachmentType::RGBA8,
                                                                                     Vector<WeakPtr<Framebuffer>>{
                                                                                             mainFB});
    RefCntPtr<DrawScreenTextureStage> drawVectorStage = CreateRef<DrawScreenTextureStage>(screenShaderWR,
                                                                                    AttachmentType::RGBA8,
                                                                                    Vector<WeakPtr<Framebuffer>>{
                                                                                            vectorFB});
    RefCntPtr<DebugDrawStage> debugDrawStage = CreateRef<DebugDrawStage>(GfxDebug::Channel::Editor);
    RefCntPtr<DrawScreenTextureStage> drawMoebiusStage = CreateRef<DrawScreenTextureStage>(screenShaderWR,
                                                                                     AttachmentType::RGBA8,
                                                                                     Vector<WeakPtr<Framebuffer>>{
                                                                                             moebiusFB});

    p_EditorPipeline->AddPipelineStage(skyFB, m_Renderer.GetPipelineStage("SkyStage").lock());
    p_EditorPipeline->AddPipelineStage(mainFB, debugDrawStage);
    p_EditorPipeline->AddPipelineStage(mainFB, m_Renderer.GetPipelineStage("NormalStage").lock());
    p_EditorPipeline->AddPipelineStage(mainFB, m_Renderer.GetPipelineStage("TexturedMeshStage").lock());
    p_EditorPipeline->AddPipelineStage(mainFB, m_Renderer.GetPipelineStage("BlinnPhongTextured").lock());

    p_EditorPipeline->AddPipelineStage(vectorFB, m_Renderer.GetPipelineStage("VectorGraphicsStage").lock());

    p_EditorPipeline->AddPipelineStage(finalFB, drawSkyStage);
    p_EditorPipeline->AddPipelineStage(finalFB, drawMoebiusStage);
    p_EditorPipeline->AddPipelineStage(finalFB, drawForwardStage);
    p_EditorPipeline->AddPipelineStage(finalFB, drawVectorStage);

    p_EditorPipeline->SetOutputFramebuffer(finalFB);
}

void harmony::Editor::InitializeViews() {
    OPTICK_EVENT();
    RuntimeProgram::InitializeViews();

    auto editorViewWr = m_Renderer.CreateView<EditorView>(*this, p_ScenePanel);
    m_Renderer.SetViewActive(editorViewWr, true);
    p_EditorView = editorViewWr.lock();
    auto pipelineWR = m_Renderer.GetViewPipeline(editorViewWr);
    if (pipelineWR.expired()) {
        harmony::log::error("RuntimeProgram : Failed to create a runtime view pipeline.");
        return;
    }
    p_EditorPipeline = pipelineWR.lock();
}

void harmony::Editor::SaveProject() {
    OPTICK_EVENT();
    Program::SaveProject();
    SaveImGuiSettings();
}

void harmony::Editor::LoadProject(const String &path) {
    OPTICK_EVENT();
    Program::LoadProject(path);
    LoadImGuiSettings();

    if (m_Project) {
        InitializePipelines();
    } else {
        harmony::log::error("Editor : Failed to load project at path : {}", path);
    }
}

int harmony::Editor::OnEditUpdate() {
    OPTICK_EVENT();
    UpdateTimeVariables();

    HandleSDLEvent();

    if (Input::GetKey(Key::F5)) {
        m_EditorFSM.Trigger(Trigger::Play);
    }


    ImGuiPreUpdate();

    RunRendererPreUpdate();

    RunProgramComponentUpdate();

    if (p_ActiveScene) {
        p_MeshSystem->Update(p_ActiveScene->m_Registry);
        p_TransformSystem->Update(p_ActiveScene->m_Registry);
        p_CameraSystem->Update(p_ActiveScene->m_Registry);
        p_LightSystem->Update(p_ActiveScene->m_Registry);
        p_TransformSystem->Render(p_ActiveScene->m_Registry);
    }

    RunProgramComponentRender();
    RunSystemRender();
    RunRendererPostUpdate();
    Input::PostFrame();

    UpdateEditor();

    ImGuiPostUpdate();
    Frame();

    return FSM::NO_TRIGGER;
}

void harmony::Editor::OnEditExit() {
    OPTICK_EVENT();
    SaveScene(p_LoadedScenePath);
}

int harmony::Editor::OnMiniGuisUpdate() {
    OPTICK_EVENT();
    UpdateTimeVariables();

    HandleSDLEvent();

    ImGuiPreUpdate();

    // RunRendererPreUpdate();
    if(!p_MiniGuiApps.empty())
    {
        bool finished = p_MiniGuiApps.top()->OnImGui();
        if(finished)
        {
            p_MiniGuiApps.top().reset();
            p_MiniGuiApps.pop();
        }
    }

    Input::PostFrame();

    UpdateEditor();

    ImGuiPostUpdate();
    Frame();

    if(p_MiniGuiApps.empty())
    {
        m_EditorFSM.Trigger(Trigger::MiniGuisFinished);
    }

    return FSM::NO_TRIGGER;
}

void harmony::Editor::OnMiniGuisExit() {
    OPTICK_EVENT();
    log::info("Program : All MiniGuis processed.");
}

int harmony::Editor::OnRuntimeUpdate() {
    OPTICK_EVENT();

    if (Input::GetKey(Key::Escape)) {
        m_EditorFSM.Trigger(Trigger::Stop);
        return FSM::NO_TRIGGER;
    }

    UpdateTimeVariables();

    HandleSDLEvent();

    RunRendererPreUpdate();

    ImGuiPreUpdate();

    RunProgramComponentUpdate();

    RunSystemUpdate();

    RunProgramComponentRender();

    RunSystemRender();

    RunRendererPostUpdate();

    UpdateEditor();

    Input::PostFrame();

    ImGuiPostUpdate();

    Frame();

    return FSM::NO_TRIGGER;
}

void harmony::Editor::OnRuntimeEntry() {
    OPTICK_EVENT();
    SetStyle();
    RunSystemInit();
    p_EditorView->Camera.Focussed = false;
    SDL_SetRelativeMouseMode(SDL_TRUE);
}

void harmony::Editor::OnRuntimeExit() {
    OPTICK_EVENT();
    SetRunningStyle();
    RunSystemCleanup();
    LoadScene(p_LoadedScenePath);
    p_EditorView->Camera.Focussed = true;
    SDL_SetRelativeMouseMode(SDL_FALSE);
    m_Renderer.RefreshViews();
}

void harmony::Editor::Init() {
    OPTICK_EVENT();
    RuntimeProgram::Init();

    m_EditorFSM.AddState(Mode::Edit, [this]() { return OnEditUpdate(); });
    m_EditorFSM.AddStateExit(Mode::Edit, [this]() { OnEditExit(); });

    m_EditorFSM.AddState(Mode::Debug, [this]() { return OnRuntimeUpdate(); });
    m_EditorFSM.AddStateExit(Mode::Debug, [this]() { OnRuntimeExit(); });
    m_EditorFSM.AddStateEntry(Mode::Debug, [this]() { OnRuntimeEntry(); });

    m_EditorFSM.AddState(Mode::MiniGuis, [this]() { return OnMiniGuisUpdate();});
    m_EditorFSM.AddStateExit(Mode::MiniGuis, [this]() { OnMiniGuisExit();});


    m_EditorFSM.AddTrigger(Trigger::Play, Mode::Edit, Mode::Debug);
    m_EditorFSM.AddTrigger(Trigger::Stop, Mode::Debug, Mode::Edit);
    m_EditorFSM.AddTrigger(Trigger::MiniGuisFinished, Mode::MiniGuis, Mode::Edit);

    m_EditorFSM.SetStartingState(Mode::MiniGuis);
}

void harmony::Editor::Run(const String &projectPath, harmony::Procedure proc) {
    OPTICK_EVENT();

    Init();
    m_Renderer.Init();

    AddPipelineDrawStages();
    AddPostProcessStages();

    InitializeViews();

    PreRunInit();

    SetRunningStyle();

    while (p_Run) {
        ProfilerBeginFrame();
        m_EditorFSM.Process();
        if (proc == NULL) continue;
        proc();
    }
}

void harmony::Editor::LoadScene(const String &path) {
    OPTICK_EVENT();
    RuntimeProgram::LoadScene(path);
    p_LoadedScenePath = path;
}

void harmony::Editor::OpenScene(uint32_t index) {
    OPTICK_EVENT();
    RuntimeProgram::OpenScene(index);
    p_LoadedScenePath = m_Project->m_SerializedScenes[index];
}

void harmony::Editor::UpdateEditor() {
    OPTICK_EVENT();
    p_MainMenuBar.OnImGui();
    GlobalDockspace();

    m_Logger.Render();
#if HARMONY_DEBUG
    m_Renderer.OnImGui();
    m_AssetManager.OnImGui();
#endif
    for (int i = 0; i < p_Panels.size(); i++) {
        p_Panels[i]->OnImGui();
    }

    if (!p_ActiveScene) {
        return;
    }
}

void harmony::Editor::SetRunningStyle() {
    OPTICK_EVENT();
    // Deep Dark style by janekb04 from ImThemes
    ImGuiStyle& style = ImGui::GetStyle();

    style.Alpha = 1.0f;
    style.DisabledAlpha = 0.6000000238418579f;
    style.WindowPadding = ImVec2(4.0f, 4.0f);
    style.WindowRounding = 7.0f;
    style.WindowBorderSize = 1.0f;
    style.WindowMinSize = ImVec2(32.0f, 32.0f);
    style.WindowTitleAlign = ImVec2(0.0f, 0.5f);
    style.WindowMenuButtonPosition = ImGuiDir_Left;
    style.ChildRounding = 4.0f;
    style.ChildBorderSize = 1.0f;
    style.PopupRounding = 4.0f;
    style.PopupBorderSize = 1.0f;
    style.FramePadding = ImVec2(1.0f, 0.4f);
    style.FrameRounding = 3.0f;
    style.FrameBorderSize = 1.0f;
    style.ItemSpacing = ImVec2(4.0f, 4.0f);
    style.ItemInnerSpacing = ImVec2(4.0f, 4.0f);
    style.CellPadding = ImVec2(4.0f, 4.0f);
    style.IndentSpacing = 7.5f;
    style.ColumnsMinSpacing = 4.0f;
    style.ScrollbarSize = 7.5f;
    style.ScrollbarRounding = 9.0f;
    style.GrabMinSize = 10.0f;
    style.GrabRounding = 3.0f;
    style.TabRounding = 4.0f;
    style.TabBorderSize = 1.0f;
    style.TabMinWidthForCloseButton = 0.0f;
    style.ColorButtonPosition = ImGuiDir_Right;
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign = ImVec2(0.0f, 0.0f);

    style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.4980392158031464f, 0.4980392158031464f, 0.4980392158031464f, 1.0f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.09803921729326248f, 0.09803921729326248f, 0.09803921729326248f, 1.0f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.1882352977991104f, 0.1882352977991104f, 0.1882352977991104f, 0.9200000166893005f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.1882352977991104f, 0.1882352977991104f, 0.1882352977991104f, 0.2899999916553497f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.239999994635582f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.0470588244497776f, 0.0470588244497776f, 0.0470588244497776f, 0.5400000214576721f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.1882352977991104f, 0.1882352977991104f, 0.1882352977991104f, 0.5400000214576721f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2274509817361832f, 1.0f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.05882352963089943f, 0.05882352963089943f, 0.05882352963089943f, 1.0f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.1372549086809158f, 0.1372549086809158f, 0.1372549086809158f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.0470588244497776f, 0.0470588244497776f, 0.0470588244497776f, 0.5400000214576721f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.3372549116611481f, 0.3372549116611481f, 0.3372549116611481f, 0.5400000214576721f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.4000000059604645f, 0.4000000059604645f, 0.4000000059604645f, 0.5400000214576721f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.5568627715110779f, 0.5568627715110779f, 0.5568627715110779f, 0.5400000214576721f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.3294117748737335f, 0.6666666865348816f, 0.8588235378265381f, 1.0f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.3372549116611481f, 0.3372549116611481f, 0.3372549116611481f, 0.5400000214576721f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.5568627715110779f, 0.5568627715110779f, 0.5568627715110779f, 0.5400000214576721f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.0470588244497776f, 0.0470588244497776f, 0.0470588244497776f, 0.5400000214576721f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.1882352977991104f, 0.1882352977991104f, 0.1882352977991104f, 0.5400000214576721f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2274509817361832f, 1.0f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.0f, 0.0f, 0.0f, 0.5199999809265137f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.0f, 0.0f, 0.0f, 0.3600000143051147f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2274509817361832f, 0.3300000131130219f);
    style.Colors[ImGuiCol_Separator] = ImVec4(0.2784313857555389f, 0.2784313857555389f, 0.2784313857555389f, 0.2899999916553497f);
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.4392156898975372f, 0.4392156898975372f, 0.4392156898975372f, 0.2899999916553497f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.4000000059604645f, 0.4392156898975372f, 0.4666666686534882f, 1.0f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.2784313857555389f, 0.2784313857555389f, 0.2784313857555389f, 0.2899999916553497f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.4392156898975372f, 0.4392156898975372f, 0.4392156898975372f, 0.2899999916553497f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.4000000059604645f, 0.4392156898975372f, 0.4666666686534882f, 1.0f);
    style.Colors[ImGuiCol_Tab] = ImVec4(0.0f, 0.0f, 0.0f, 0.5199999809265137f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.1372549086809158f, 0.1372549086809158f, 0.1372549086809158f, 1.0f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.2000000029802322f, 0.2000000029802322f, 0.2000000029802322f, 0.3600000143051147f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.0f, 0.0f, 0.0f, 0.5199999809265137f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.1372549086809158f, 0.1372549086809158f, 0.1372549086809158f, 1.0f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.5199999809265137f);
    style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.0f, 0.0f, 0.0f, 0.5199999809265137f);
    style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.2784313857555389f, 0.2784313857555389f, 0.2784313857555389f, 0.2899999916553497f);
    style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.05999999865889549f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.2000000029802322f, 0.2196078449487686f, 0.2274509817361832f, 1.0f);
    style.Colors[ImGuiCol_DragDropTarget] = ImVec4(0.3294117748737335f, 0.6666666865348816f, 0.8588235378265381f, 1.0f);
    style.Colors[ImGuiCol_NavHighlight] = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 0.0f, 0.0f, 0.699999988079071f);
    style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(1.0f, 0.0f, 0.0f, 0.2000000029802322f);
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(1.0f, 0.0f, 0.0f, 0.3499999940395355f);
}

void harmony::Editor::GlobalDockspace() {
    OPTICK_EVENT();
    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_PassthruCentralNode;

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDocking;

    ImGuiViewport *viewport = ImGui::GetMainViewport();
    ImVec2 winPos = viewport->Pos;
    ImVec2 winSize = viewport->Size;
    winPos.y += p_MainMenuBar.m_MenuBarSize.y;
    ImGui::SetNextWindowPos(winPos);
    ImGui::SetNextWindowSize(winSize);
    ImGui::SetNextWindowViewport(viewport->ID);

    window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove |
                    ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;
    window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;


    // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background and handle the pass-thru hole, so we ask Begin() to not render a background.
    if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
        window_flags |= ImGuiWindowFlags_NoBackground;

    // Important: note that we proceed even if Begin() returns false (aka window is collapsed).
    // This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
    // all active windows docked into it will lose their parent and become undocked.
    // We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
    // any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
    ImGui::Begin("DockSpace", nullptr, window_flags);
    ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
    ImGui::DockSpace(dockspace_id, winSize, dockspace_flags);
    ImGui::End();
}

void harmony::Editor::LoadBuiltInAssets() {
    OPTICK_EVENT();
    AssetHandle cubeHandle = m_AssetManager.AddBuiltInAsset<Mesh>("builtin/Cube", CreateRef<Cube>(1.0f));
    RefCntPtr<Mesh> cube = m_AssetManager.GetAsset<Mesh>(cubeHandle).lock();
    m_Renderer.SubmitMeshToGPU(cube);
    AssetHandle planeHandle = m_AssetManager.AddBuiltInAsset<Mesh>("builtin/Plane", CreateRef<Plane>(1.0f));
    RefCntPtr<Mesh> plane = m_AssetManager.GetAsset<Mesh>(planeHandle).lock();
    m_Renderer.SubmitMeshToGPU(plane);
}

void harmony::Editor::AddMiniGuiApp(harmony::RefCntPtr<harmony::MiniGuiApp> app)
{
    p_MiniGuiApps.push(app);
}
