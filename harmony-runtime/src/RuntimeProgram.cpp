#include <optick.h>
#include "RuntimeProgram.h"
#include "AssimpModelAssetFactory.h"
#include "Assets/FontAssetFactory.h"
#include "Rendering/Views/RuntimeView.h"
#include "Rendering/ShaderDataSources/BlinnPhongDataSource.h"
#include "Rendering/Shapes.h"
#include "Core/FSM.h"
#include "ECS/LightSystem.h"
#include "Script/Lua/LuaProgramComponent.h"
#include "Script/Lua/LuaSystem.h"
#include "Script/Lua/LuaScriptAssetFactory.h"
#include "JoltPhysicsSystem.h"
#include "ECS/SimpleCollisionSystem.h"
#include "Script/GraphScript/GraphScriptProgramComponent.h"
#include "Script/GraphScript/GraphScriptSystem.h"

harmony::RuntimeProgram::RuntimeProgram(const std::string &name) : Program(name) {
    OPTICK_EVENT();
    AddAssetTypeNames();
    AddAssetFactories();
    AddProgramComponents();
    AddSystems();
    AddPipelineStageRenderers();
    AddShaderDataSources();
    AddPostProcessStages();

    // TODO: Need some way of tracking max view ids.
    p_PresentViewId = (bgfx::ViewId) 255;
}

void harmony::RuntimeProgram::Run() {
    OPTICK_EVENT();

    Init();
    m_Renderer.Init();

    AddPipelineDrawStages();

    InitializePipelines();
    InitializeViews();

    PreRunInit();

    SDL_SetRelativeMouseMode(SDL_TRUE);

    while (p_Run) {
        ProfilerBeginFrame();
        OnRuntimeUpdate();
    }
}

void harmony::RuntimeProgram::Run(const std::string &projectPath) {
    OPTICK_EVENT();
    Init();
    m_Renderer.Init();

    AddPipelineDrawStages();

    InitializePipelines();
    InitializeViews();

    PreRunInit();

    SDL_SetRelativeMouseMode(SDL_TRUE);

    LoadProject(projectPath);
    OpenScene(0);

    ResizeApplicationWindow(p_WindowWidth, p_WindowHeight);

    while (p_Run) {
        ProfilerBeginFrame();
        OnRuntimeUpdate();
    }
}

void harmony::RuntimeProgram::AddAssetTypeNames() {
    OPTICK_EVENT();
    m_AssetManager.AddAssetTypeName<Mesh>();
    m_AssetManager.AddAssetTypeName<Model>();
    m_AssetManager.AddAssetTypeName<TextureAsset>();
    m_AssetManager.AddAssetTypeName<ShaderStage>();
}

void harmony::RuntimeProgram::AddAssetFactories() {
    OPTICK_EVENT();
    m_AssetManager.AddAssetFactory(CreateRef<TextureAssetFactory>(m_Renderer));
    m_AssetManager.AddAssetFactory(CreateRef<ShaderStageBinaryAssetFactory>(m_Renderer));
    m_AssetManager.AddAssetFactory(CreateRef<AssimpModelAssetFactory>(m_Renderer));
    m_AssetManager.AddAssetFactory(CreateRef<FontAssetFactory>());
    m_AssetManager.AddAssetFactory(CreateRef<LuaScriptAssetFactory>());

}

void harmony::RuntimeProgram::AddProgramComponents() {
    OPTICK_EVENT();
    p_LuaProgramComponent  = AddProgramComponent<LuaProgramComponent>().lock();
    p_GraphScriptComponent = AddProgramComponent<GraphScriptProgramComponent>().lock();
}

void harmony::RuntimeProgram::AddSystems() {
    OPTICK_EVENT();
    AddSystem<TransformSystem>();
    AddSystem<CameraSystem>();
    AddSystem<MaterialSystem>(m_Renderer, m_AssetManager);
    AddSystem<MeshSystem>(m_AssetManager);
    AddSystem<LightSystem>();
    p_LuaSystem = AddSystem<LuaSystem>(m_AssetManager, p_LuaProgramComponent).lock();
    p_GraphScriptSystem = AddSystem<GraphScriptSystem>(p_GraphScriptComponent).lock();
    p_SimpleCollisionSystem = AddSystem<SimpleCollisionSystem>(m_AssetManager).lock();
    p_JoltPhysicsSystem = AddSystem<JoltPhysicsSystem>().lock();

}

void harmony::RuntimeProgram::AddPipelineStageRenderers() {
    OPTICK_EVENT();
    m_Renderer.AddPipelineStageRenderer(CreateRef<MeshRenderer>());
}

void harmony::RuntimeProgram::AddPipelineDrawStages() {
    OPTICK_EVENT();
    Ref<PipelineDrawStage> normalStage = CreateRef<PipelineDrawStage>(
            "NormalStage",
            PipelineDrawStage::Type::PrimaryDraw,
            m_Renderer.GetShader("Normal"),
            m_Renderer.GetPipelineStageRenderer("MeshRenderer"),
            (Attachment::Type) (Attachment::Type::RGBA16F | Attachment::Type::Depth32F)
    );

    Ref<PipelineDrawStage> texturedMeshStage = CreateRef<PipelineDrawStage>(
            "TexturedMeshStage",
            PipelineDrawStage::Type::PrimaryDraw,
            m_Renderer.GetShader("TexturedMesh"),
            m_Renderer.GetPipelineStageRenderer("MeshRenderer"),
            (Attachment::Type) (Attachment::Type::RGBA16F | Attachment::Type::Depth32F)
    );

    Ref<PipelineDrawStage> blinnPhongStage = CreateRef<PipelineDrawStage>(
            "BlinnPhongTextured",
            PipelineDrawStage::Type::PrimaryDraw,
            m_Renderer.GetShader("BlinnPhongTextured"),
            m_Renderer.GetPipelineStageRenderer("MeshRenderer"),
            (Attachment::Type) (Attachment::Type::RGBA16F | Attachment::Type::Depth32F)
    );


    blinnPhongStage->AddShaderDataSource(m_Renderer.GetShaderDataSource("BlinnPhong"));
    m_Renderer.AddPipelineDrawStage(normalStage);
    m_Renderer.AddPipelineDrawStage(texturedMeshStage);
    m_Renderer.AddPipelineDrawStage(blinnPhongStage);
}

void harmony::RuntimeProgram::AddPostProcessStages() {
    OPTICK_EVENT();

}

void harmony::RuntimeProgram::AddShaderDataSources() {
    OPTICK_EVENT();
    Ref<BlinnPhongDataSource> blinnPhong = CreateRef<BlinnPhongDataSource>();
    m_Renderer.AddShaderDataSource(blinnPhong);
}

void harmony::RuntimeProgram::InitializePipelines() {
    OPTICK_EVENT();
    p_ForwardPipeline = CreateRef<Pipeline>(PipelineHandle("Forward Pipeline"), Pipeline::Type::Surface);
    p_VectorGraphicsPipeline = CreateRef<VectorPipeline>(VectorGraphics::Layer::One);
    p_DebugPipeline = CreateRef<DebugDrawPipeline>(GfxDebug::Channel::Editor);

    p_ForwardPipeline->AddPipelineStage(m_Renderer.GetPipelineDrawStage("NormalStage").lock());
    p_ForwardPipeline->AddPipelineStage(m_Renderer.GetPipelineDrawStage("TexturedMeshStage").lock());
    p_ForwardPipeline->AddPipelineStage(m_Renderer.GetPipelineDrawStage("BlinnPhongTextured").lock());

    m_Renderer.AddPipeline(p_DebugPipeline);
    m_Renderer.AddPipeline(p_ForwardPipeline);
    m_Renderer.AddPipeline(p_VectorGraphicsPipeline);
}

void harmony::RuntimeProgram::InitializeViews() {
    OPTICK_EVENT();
    auto runtimeViewWr = m_Renderer.CreateView<RuntimeView>(*this);

    m_Renderer.AddViewPipeline(runtimeViewWr, p_ForwardPipeline);
    m_Renderer.AddViewPipeline(runtimeViewWr, p_VectorGraphicsPipeline);
    m_Renderer.SetViewActive(runtimeViewWr, true);

    p_RuntimeView = runtimeViewWr.lock();
}


void harmony::RuntimeProgram::LoadScene(const std::string &path) {
    OPTICK_EVENT();
    Program::LoadScene(path);
    RunSystemInit();
}

void harmony::RuntimeProgram::OpenScene(uint32_t index) {
    OPTICK_EVENT();
    Program::OpenScene(index);
    RunSystemInit();
}

int harmony::RuntimeProgram::OnRuntimeUpdate() {
    OPTICK_EVENT();
    UpdateTimeVariables();

    HandleSDLEvent();

    RunRendererPreUpdate();

    RunProgramComponentUpdate();

    RunSystemUpdate();

    RunSystemRender();

    RunRendererPostUpdate();

    RunProgramComponentRender();

    RunSystemRender();

    PresentRuntimeImage();

    Frame();

    return FSM::NO_TRIGGER;
}

void harmony::RuntimeProgram::LoadBuiltInAssets() {
    OPTICK_EVENT();
    AssetHandle cubeHandle = m_AssetManager.AddBuiltInAsset<Mesh>("builtin/Cube", CreateRef<Cube>(1.0f));
    Ref<Mesh> cube = m_AssetManager.GetAsset<Mesh>(cubeHandle).lock();
    m_Renderer.SubmitMeshToGPU(cube);
    AssetHandle planeHandle = m_AssetManager.AddBuiltInAsset<Mesh>("builtin/Plane", CreateRef<Plane>(1.0f));
    Ref<Mesh> plane = m_AssetManager.GetAsset<Mesh>(planeHandle).lock();
    m_Renderer.SubmitMeshToGPU(plane);
}

void harmony::RuntimeProgram::ResizeApplicationWindow(int w, int h) {
    OPTICK_EVENT();

    Program::ResizeApplicationWindow(w, h);
    bgfx::setViewRect(p_PresentViewId, 0, 0, p_WindowWidth, p_WindowHeight);

    p_RuntimeView->OnResized(p_WindowWidth, p_WindowHeight);
}

void harmony::RuntimeProgram::PresentRuntimeImage() {
    OPTICK_EVENT();
    bgfx::setViewClear(p_PresentViewId, BGFX_CLEAR_COLOR, 0);
    bgfx::setViewClear(p_PresentViewId, BGFX_CLEAR_DEPTH, 0, 1.0f);
    auto stack = m_Renderer.GetViewPipelineStack(p_RuntimeView->m_Name);
    bgfx::setTexture(0, m_Renderer.p_PresentProgramTextureHandle, stack.GetFinalImage(), BGFX_SAMPLER_POINT);
    ScreenSpaceQuad(static_cast<float>(p_WindowWidth), static_cast<float>(p_WindowHeight));
    bgfx::submit(p_PresentViewId, m_Renderer.p_PresentProgram.lock()->m_Handle);
}
