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
#include "ECS/SimpleCollisionSystem.h"

harmony::Editor::Editor() : harmony::RuntimeProgram("Editor"), p_MainMenuBar(*this) {
    AddAssetTypeNames();
    AddAssetFactories();
    AddProgramComponents();
    AddSystems();
    AddPipelineStageRenderers();

    AddEditorPanels();
}

void harmony::Editor::AddAssetTypeNames() {
    m_AssetManager.AddAssetTypeName<ShaderSourceAsset>();
}

void harmony::Editor::AddAssetFactories() {
    m_AssetManager.AddAssetFactory(CreateRef<ShaderSourceAssetFactory>());
}

void harmony::Editor::AddProgramComponents() {
    auto assetHotReload = AddProgramComponent<AssetHotReload>(*this).lock();
    auto shaderProvider = CreateRef<ShaderHotReload>(*this);
    auto luaProvider = CreateRef<LuaScriptHotReload>(*this, p_LuaSystem);

    assetHotReload->AddHotReloadProvider(shaderProvider);
    assetHotReload->AddHotReloadProvider(luaProvider);
}

void harmony::Editor::AddSystems() {
    p_TransformSystem = GetSystem<TransformSystem>().lock();
    p_CameraSystem = GetSystem<CameraSystem>().lock();
    p_MeshSystem = GetSystem<MeshSystem>().lock();
    p_LightSystem = GetSystem<LightSystem>().lock();

}

void harmony::Editor::AddPipelineStageRenderers() {
}

void harmony::Editor::AddEditorPanels() {
    p_ScenePanel = CreateRef<ScenePanel>(*this);
    p_Panels.emplace_back(p_ScenePanel);

    Ref<AssetManagerPanel> assetManagerPanel = CreateRef<AssetManagerPanel>(*this);
    p_Panels.emplace_back(assetManagerPanel);

    Ref<EntityInspectorPanel> inspector = CreateRef<EntityInspectorPanel>(*this, p_ScenePanel);
    inspector->AddComponentUI<TransformComponentUI>();
    inspector->AddComponentUI<MeshComponentUI>(m_AssetManager);
    inspector->AddComponentUI<MaterialComponentUI>(m_Renderer, m_AssetManager);
    inspector->AddComponentUI<CameraComponentUI>(m_Renderer);
    inspector->AddComponentUI<DirectionalLightComponentUI>();
    inspector->AddComponentUI<PointLightComponentUI>();
    inspector->AddComponentUI<SpotLightComponentUI>();
    inspector->AddComponentUI<LuaScriptComponentUI>(m_AssetManager);
    inspector->AddComponentUI<JoltBodyComponentUI>();

    p_Panels.emplace_back(inspector);
}

void harmony::Editor::InitializePipelines() {
    RuntimeProgram::InitializePipelines();
}

void harmony::Editor::InitializeViews() {
    RuntimeProgram::InitializeViews();

    auto editorViewWr = m_Renderer.CreateView<EditorView>(*this, p_ScenePanel);
    m_Renderer.AddViewPipeline(editorViewWr, p_DebugPipeline);
    m_Renderer.AddViewPipeline(editorViewWr, p_ForwardPipeline);
    m_Renderer.AddViewPipeline(editorViewWr, p_VectorGraphicsPipeline);
    m_Renderer.SetViewActive(editorViewWr, true);

    p_EditorView = editorViewWr.lock();
}

void harmony::Editor::SaveProject() {
    Program::SaveProject();
    SaveImGuiSettings();
}

void harmony::Editor::LoadProject(const std::string &path) {
    Program::LoadProject(path);
    LoadImGuiSettings();
}

int harmony::Editor::OnEditUpdate() {
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
        p_SimpleCollisionSystem->Update(p_ActiveScene->m_Registry);

        VectorGraphics::Get()->FontSize(VectorGraphics::One, 20.0f);
        VectorGraphics::Get()->FontFace(VectorGraphics::One, "carbontype");
        VectorGraphics::Get()->FontBlur(VectorGraphics::One, 0);
        VectorGraphics::Get()->FillColor(VectorGraphics::One, nvgRGBA(220, 220, 220, 160));
        VectorGraphics::Get()->Text(VectorGraphics::One, 0.0f, 30.0f, "carbontype");
        p_TransformSystem->Render(p_ActiveScene->m_Registry);
    }


    RunRendererPostUpdate();

    RunProgramComponentRender();

    Input::PostFrame();

    UpdateEditor();

    ImGuiPostUpdate();

    Frame();

    return FSM::NO_TRIGGER;
}

void harmony::Editor::OnEditExit() {
    SaveScene(p_LoadedScenePath);
}

int harmony::Editor::OnRuntimeUpdate() {
    UpdateTimeVariables();

    HandleSDLEvent();

    if (Input::GetKey(Key::Escape)) {
        m_EditorFSM.Trigger(Trigger::Stop);
    }

    RunRendererPreUpdate();

    ImGuiPreUpdate();

    RunProgramComponentUpdate();

    RunSystemUpdate();

    RunSystemRender();

    RunRendererPostUpdate();

    RunProgramComponentRender();

    RunSystemRender();

    UpdateEditor();

    Input::PostFrame();

    ImGuiPostUpdate();

    Frame();

    return FSM::NO_TRIGGER;
}

void harmony::Editor::OnRuntimeEntry() {
    SetStyle();
    RunSystemInit();
    p_EditorView->Camera.Focussed = false;
    SDL_SetRelativeMouseMode(SDL_TRUE);
}

void harmony::Editor::OnRuntimeExit() {
    SetRunningStyle();
    RunSystemCleanup();
    LoadScene(p_LoadedScenePath);
    p_EditorView->Camera.Focussed = true;
    SDL_SetRelativeMouseMode(SDL_FALSE);
}

void harmony::Editor::Run() {
    

    Init();
    m_Renderer.Init();

    AddPipelineDrawStages();
    AddPostProcessStages();

    InitializePipelines();
    InitializeViews();
    PreRunInit();

    SetRunningStyle();

    while (p_Run) {
        m_EditorFSM.Process();
    }
}

void harmony::Editor::Init() {
    Program::Init();

    m_EditorFSM.AddState(Mode::Edit, [this]() { return OnEditUpdate(); });
    m_EditorFSM.AddStateExit(Mode::Edit, [this]() { OnEditExit(); });

    m_EditorFSM.AddState(Mode::Debug, [this]() { return OnRuntimeUpdate(); });
    m_EditorFSM.AddStateExit(Mode::Debug, [this]() { OnRuntimeExit(); });
    m_EditorFSM.AddStateEntry(Mode::Debug, [this]() { OnRuntimeEntry(); });

    m_EditorFSM.AddTrigger(Trigger::Play, Mode::Edit, Mode::Debug);
    m_EditorFSM.AddTrigger(Trigger::Stop, Mode::Debug, Mode::Edit);

    m_EditorFSM.SetStartingState(Mode::Edit);
}

void harmony::Editor::Run(const std::string &projectPath, harmony::Procedure proc) {
    

    Init();
    m_Renderer.Init();

    AddPipelineDrawStages();
    AddPostProcessStages();

    InitializePipelines();
    InitializeViews();

    LoadProject(projectPath);

    PreRunInit();

    SetRunningStyle();

    while (p_Run) {
        m_EditorFSM.Process();
        proc();
    }
}

void harmony::Editor::LoadScene(const std::string &path) {
    Program::LoadScene(path);
    p_LoadedScenePath = path;
    p_SimpleCollisionSystem->Init(p_ActiveScene->m_Registry);
}

void harmony::Editor::OpenScene(uint32_t index) {
    Program::OpenScene(index);
    p_LoadedScenePath = m_Project->m_SerializedScenes[index];
    p_SimpleCollisionSystem->Init(p_ActiveScene->m_Registry);
}

void harmony::Editor::UpdateEditor() {
    
    p_MainMenuBar.OnImGui();
    GlobalDockspace();

    m_GraphScriptEditor.Render();
    m_Renderer.OnImGui();
    m_AssetManager.OnImGui();

    for (int i = 0; i < p_Panels.size(); i++) {
        p_Panels[i]->OnImGui();
    }

    if (!p_ActiveScene) {
        return;
    }

    //GfxDebug::Get()->setColor(GfxDebug::Channel::Editor, 0xfffffff);
    //GfxDebug::Get()->drawGrid(GfxDebug::Channel::Editor, Axis::Enum::Y, bx::Vec3(0.0f, 0.0f, 0.0f), 1000);

}

void harmony::Editor::SetRunningStyle() {
    // Photoshop style by Derydoca from ImThemes
    ImGuiStyle &style = ImGui::GetStyle();

    style.Alpha = 1.0f;
    style.DisabledAlpha = 0.6000000238418579f;
    style.DisplaySafeAreaPadding = ImVec2(0.0f, 0.0f);
    style.WindowPadding = ImVec2(0.0f, 0.0f);
    style.FramePadding = ImVec2(0.0f, 0.0f);
    style.DisplayWindowPadding = ImVec2(0.0f, 0.0f);


    style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.4980392158031464f, 0.4980392158031464f, 0.4980392158031464f, 1.0f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1764705926179886f, 0.1764705926179886f, 0.1764705926179886f, 1.0f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.2784313857555389f, 0.2784313857555389f, 0.2784313857555389f, 0.0f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3098039329051971f, 1.0f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.2627451121807098f, 0.2627451121807098f, 0.2627451121807098f, 1.0f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.2000000029802322f, 0.2000000029802322f, 0.2000000029802322f, 1.0f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.2784313857555389f, 0.2784313857555389f, 0.2784313857555389f, 1.0f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1450980454683304f, 1.0f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1450980454683304f, 1.0f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.1450980454683304f, 0.1450980454683304f, 0.1450980454683304f,
                                                     1.0f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.1921568661928177f, 0.1921568661928177f, 0.1921568661928177f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.1568627506494522f, 0.1568627506494522f, 0.1568627506494522f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.2745098173618317f, 0.2745098173618317f, 0.2745098173618317f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.2980392277240753f, 0.2980392277240753f, 0.2980392277240753f,
                                                         1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.3882353007793427f, 0.3882353007793427f, 0.3882353007793427f, 1.0f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_Button] = ImVec4(1.0f, 1.0f, 1.0f, 0.13f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.2560000032186508f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(1.0f, 1.0f, 1.0f, 0.3910000026226044f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3098039329051971f, 1.0f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.4666666686534882f, 0.4666666686534882f, 0.4666666686534882f, 1.0f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.4666666686534882f, 0.4666666686534882f, 0.4666666686534882f, 1.0f);
    style.Colors[ImGuiCol_Separator] = ImVec4(0.2627451121807098f, 0.2627451121807098f, 0.2627451121807098f, 1.0f);
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.3882353007793427f, 0.3882353007793427f, 0.3882353007793427f,
                                                     1.0f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.0f, 1.0f, 1.0f, 0.25f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.0f, 1.0f, 1.0f, 0.6700000166893005f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_Tab] = ImVec4(0.09411764889955521f, 0.09411764889955521f, 0.09411764889955521f, 1.0f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.3490196168422699f, 0.3490196168422699f, 0.3490196168422699f, 1.0f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.1921568661928177f, 0.1921568661928177f, 0.1921568661928177f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.09411764889955521f, 0.09411764889955521f, 0.09411764889955521f,
                                                 1.0f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.1921568661928177f, 0.1921568661928177f, 0.1921568661928177f,
                                                       1.0f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.4666666686534882f, 0.4666666686534882f, 0.4666666686534882f, 1.0f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.5843137502670288f, 0.5843137502670288f, 0.5843137502670288f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_TableHeaderBg] = ImVec4(0.1882352977991104f, 0.1882352977991104f, 0.2000000029802322f, 1.0f);
    style.Colors[ImGuiCol_TableBorderStrong] = ImVec4(0.3098039329051971f, 0.3098039329051971f, 0.3490196168422699f,
                                                      1.0f);
    style.Colors[ImGuiCol_TableBorderLight] = ImVec4(0.2274509817361832f, 0.2274509817361832f, 0.2470588237047195f,
                                                     1.0f);
    style.Colors[ImGuiCol_TableRowBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
    style.Colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.0f, 1.0f, 1.0f, 0.05999999865889549f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(1.0f, 1.0f, 1.0f, 0.1560000032186508f);
    style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_NavHighlight] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.0f, 0.3882353007793427f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.5860000252723694f);
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.5860000252723694f);
}

void harmony::Editor::GlobalDockspace() {
    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_PassthruCentralNode;

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDocking;

    ImGuiViewport *viewport = ImGui::GetMainViewport();
    ImVec2 winPos = viewport->Pos;
    ImVec2 winSize = viewport->Size;
    winPos.y += p_MainMenuBar.m_MenuBarSize.y;
    winSize.x = p_WindowWidth;
    winSize.y = p_WindowHeight + p_MainMenuBar.m_MenuBarSize.y;
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
    AssetHandle cubeHandle = m_AssetManager.AddBuiltInAsset<Mesh>("builtin/Cube", CreateRef<Cube>(1.0f));
    Ref<Mesh> cube = m_AssetManager.GetAsset<Mesh>(cubeHandle).lock();
    m_Renderer.SubmitMeshToGPU(cube);
    AssetHandle planeHandle = m_AssetManager.AddBuiltInAsset<Mesh>("builtin/Plane", CreateRef<Plane>(1.0f));
    Ref<Mesh> plane = m_AssetManager.GetAsset<Mesh>(planeHandle).lock();
    m_Renderer.SubmitMeshToGPU(plane);
}
