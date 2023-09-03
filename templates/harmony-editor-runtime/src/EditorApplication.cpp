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
#include "Script/GraphScript/GraphScriptProgramComponent.h"

harmony::Editor::Editor() : harmony::RuntimeProgram("Editor"), p_MainMenuBar(*this), m_GraphScriptEditor(p_GraphScriptComponent->GetNodeRegistry()) {
    OPTICK_EVENT();
    // m_Logger.Init();
    AddAssetTypeNames();
    AddAssetFactories();
    AddProgramComponents();
    AddSystems();
    AddPipelineStageRenderers();

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
    RuntimeProgram::AddProgramComponents();
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
}

void harmony::Editor::AddEditorPanels() {
    OPTICK_EVENT();
    p_ScenePanel = CreateRef<ScenePanel>(*this);
    p_Panels.emplace_back(p_ScenePanel);

    Ref<AssetManagerPanel> assetManagerPanel = CreateRef<AssetManagerPanel>(*this);
    Ref<LuaScriptPanel> luaScriptPanel = CreateRef<LuaScriptPanel>(*this);

    p_Panels.emplace_back(assetManagerPanel);
    p_Panels.emplace_back(luaScriptPanel);

    Ref<EntityInspectorPanel> inspector = CreateRef<EntityInspectorPanel>(*this, p_ScenePanel);
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

    p_Panels.emplace_back(inspector);
}

void harmony::Editor::InitializePipelines() {
    OPTICK_EVENT();
    RuntimeProgram::InitializePipelines();

    auto skyFB = p_EditorPipeline->AddFramebuffer("Sky FB",{AttachmentType::RGBA16F}, Resolution::Type::FullScale);
    auto mainFB = p_EditorPipeline->AddFramebuffer("Forward FB",{AttachmentType::RGBA16F, AttachmentType::Depth32F}, Resolution::Type::FullScale);
    auto vectorFB = p_EditorPipeline->AddFramebuffer("Vector FB", {AttachmentType::RGBA8}, Resolution::Type::FullScale);
    auto finalFB = p_EditorPipeline->AddFramebuffer("Final FB", {AttachmentType::RGBA8}, Resolution::Type::FullScale);

	auto crosshatchTexture = m_AssetManager.GetAsset<TextureAsset>("assets\\crosshatch.png");
	auto moebiusFB = Moebius::AddMoebiusToPipeline(m_Renderer, p_EditorPipeline, crosshatchTexture.lock());
    auto screenShaderWR = m_Renderer.p_PresentProgram;

    if(screenShaderWR.expired())
    {
        harmony::log::error("RuntimeProgram : Initialize Pipelines : Present Program is expired. This should never happen.");
        return;
    }

    Ref<DrawScreenTextureStage> drawSkyStage = CreateRef<DrawScreenTextureStage>(screenShaderWR, AttachmentType::RGBA8, Vector<WeakRef<Framebuffer>> {skyFB});
    Ref<DrawScreenTextureStage> drawForwardStage = CreateRef<DrawScreenTextureStage>(screenShaderWR, AttachmentType::RGBA8, Vector<WeakRef<Framebuffer>> {mainFB});
    Ref<DrawScreenTextureStage> drawVectorStage = CreateRef<DrawScreenTextureStage>(screenShaderWR, AttachmentType::RGBA8, Vector<WeakRef<Framebuffer>> {vectorFB});
    Ref<DebugDrawStage> debugDrawStage = CreateRef<DebugDrawStage>(GfxDebug::Channel::Editor);
	Ref<DrawScreenTextureStage> drawMoebiusStage = CreateRef<DrawScreenTextureStage>(screenShaderWR, AttachmentType::RGBA8, Vector<WeakRef<Framebuffer>> {moebiusFB});

    p_EditorPipeline->AddPipelineStage(skyFB, m_Renderer.GetPipelineStage("SkyStage").lock());
    p_EditorPipeline->AddPipelineStage(mainFB, debugDrawStage);
    p_EditorPipeline->AddPipelineStage(mainFB, m_Renderer.GetPipelineStage("NormalStage").lock());
    p_EditorPipeline->AddPipelineStage(mainFB, m_Renderer.GetPipelineStage("TexturedMesh").lock());
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
    if(pipelineWR.expired())
    {
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

void harmony::Editor::LoadProject(const std::string &path) {
    OPTICK_EVENT();
    Program::LoadProject(path);
    LoadImGuiSettings();

    if (m_Project)
    {
        InitializePipelines();
    }
    else
    {
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

int harmony::Editor::OnRuntimeUpdate() {
    OPTICK_EVENT();
    UpdateTimeVariables();

    HandleSDLEvent();

    if (Input::GetKey(Key::Escape)) {
        m_EditorFSM.Trigger(Trigger::Stop);
    }

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
    OPTICK_EVENT();

    Init();
    m_Renderer.Init();

    AddPipelineDrawStages();
    AddPostProcessStages();

    InitializeViews();

    LoadProject(projectPath);


    PreRunInit();

    SetRunningStyle();

	if(m_Project)
	{
		if(m_Project->m_SerializedScenes.size() > 0)
		{
			LoadScene(m_Project->m_SerializedScenes[0]);
		}
	}

	while (p_Run) {
        ProfilerBeginFrame();
        m_EditorFSM.Process();
		if(proc == NULL) continue;
        proc();
    }
}

void harmony::Editor::LoadScene(const std::string &path) {
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
    m_GraphScriptEditor.Render();
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

    //GfxDebug::Get()->setColor(GfxDebug::Channel::Editor, 0xfffffff);
    //GfxDebug::Get()->drawGrid(GfxDebug::Channel::Editor, Axis::Enum::Y, bx::Vec3(0.0f, 0.0f, 0.0f), 1000);

}

void harmony::Editor::SetRunningStyle() {
    OPTICK_EVENT();
    // Photoshop style by Derydoca from ImThemes
    ImGuiStyle &style = ImGui::GetStyle();

    style.DisplaySafeAreaPadding = ImVec2(0.0f, 0.0f);
    style.WindowPadding = ImVec2(1.0f, 1.0f);
    style.FramePadding = ImVec2(1.0f, 1.0f);
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
    Ref<Mesh> cube = m_AssetManager.GetAsset<Mesh>(cubeHandle).lock();
    m_Renderer.SubmitMeshToGPU(cube);
    AssetHandle planeHandle = m_AssetManager.AddBuiltInAsset<Mesh>("builtin/Plane", CreateRef<Plane>(1.0f));
    Ref<Mesh> plane = m_AssetManager.GetAsset<Mesh>(planeHandle).lock();
    m_Renderer.SubmitMeshToGPU(plane);
}
