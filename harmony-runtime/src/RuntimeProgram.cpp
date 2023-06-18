#include <optick.h>
#include "RuntimeProgram.h"
#include "AssimpModelAssetFactory.h"
#include "Assets/FontAssetFactory.h"
#include "Rendering/Views/RuntimeView.h"
#include "Rendering/Shaders/ShaderDataSources/BlinnPhongDataSource.h"
#include "Rendering/Pipelines/PipelineStages/DrawScreenTextureStage.h"
#include "Rendering/Shapes.h"
#include "Core/FSM.h"
#include "ECS/EntityDataSystem.h"
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

    InitializeViews();
    InitializePipelines();

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

    InitializeViews();
    InitializePipelines();

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
    p_EntityDataSystem = AddSystem<EntityDataSystem>().lock();

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
            m_Renderer.GetPipelineStageRenderer("MeshRenderer")
    );

    Ref<PipelineDrawStage> texturedMeshStage = CreateRef<PipelineDrawStage>(
            "TexturedMeshStage",
            PipelineDrawStage::Type::PrimaryDraw,
            m_Renderer.GetShader("TexturedMesh"),
            m_Renderer.GetPipelineStageRenderer("MeshRenderer")
    );

    Ref<PipelineDrawStage> blinnPhongStage = CreateRef<PipelineDrawStage>(
            "BlinnPhongTextured",
            PipelineDrawStage::Type::PrimaryDraw,
            m_Renderer.GetShader("BlinnPhongTextured"),
            m_Renderer.GetPipelineStageRenderer("MeshRenderer")
    );

    Ref<VectorGraphicsStage> vectorGraphicsStage = CreateRef<VectorGraphicsStage>(VectorGraphics::Layer::One);
    Ref<DebugDrawStage> debugDrawStage = CreateRef<DebugDrawStage>(GfxDebug::Channel::Game);

    blinnPhongStage->AddShaderDataSource(m_Renderer.GetShaderDataSource("BlinnPhong"));

    m_Renderer.AddPipelineStage(normalStage);
    m_Renderer.AddPipelineStage(texturedMeshStage);
    m_Renderer.AddPipelineStage(blinnPhongStage);
    m_Renderer.AddPipelineStage(vectorGraphicsStage);
    m_Renderer.AddPipelineStage(debugDrawStage);
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

    auto mainFB = p_RuntimePipeline->AddFramebuffer("Forward FB",{AttachmentType::RGBA16F, AttachmentType::Depth32F}, Resolution::Type::FullScale);
    auto vectorFB = p_RuntimePipeline->AddFramebuffer("Vector FB", {AttachmentType::RGBA8}, Resolution::Type::FullScale);
    // auto accumulateFB = p_RuntimePipeline->AddFramebuffer("Accumulate FB", {AttachmentType::RGBA8}, Resolution::Type::FullScale);
    auto finalFB = p_RuntimePipeline->AddFramebuffer("Final FB", {AttachmentType::RGBA8}, Resolution::Type::FullScale);

    auto screenShaderWR = m_Renderer.p_PresentProgram;
    // auto fxaaShaderWr = m_Renderer.GetShader("FXAA");

    if(screenShaderWR.expired())
    {
        harmony::log::error("RuntimeProgram : Initialize Pipelines : Present Program is expired. This should never happen.");
        return;
    }

    Ref<DrawScreenTextureStage> drawForwardStage = CreateRef<DrawScreenTextureStage>(screenShaderWR, AttachmentType::RGBA8, Vector<WeakRef<Framebuffer>> {mainFB});
    Ref<DrawScreenTextureStage> drawVectorStage = CreateRef<DrawScreenTextureStage>(screenShaderWR, AttachmentType::RGBA8, Vector<WeakRef<Framebuffer>> {vectorFB});
    // Ref<DrawScreenTextureStage> drawFxaaStage = CreateRef<DrawScreenTextureStage>(fxaaShaderWr, AttachmentType::RGBA8, Vector<WeakRef<Framebuffer>> {accumulateFB});

    p_RuntimePipeline->AddPipelineStage(mainFB, m_Renderer.GetPipelineStage("DebugDrawStage").lock());
    p_RuntimePipeline->AddPipelineStage(mainFB, m_Renderer.GetPipelineStage("NormalStage").lock());
    p_RuntimePipeline->AddPipelineStage(mainFB, m_Renderer.GetPipelineStage("TexturedMesh").lock());
    p_RuntimePipeline->AddPipelineStage(mainFB, m_Renderer.GetPipelineStage("BlinnPhongTextured").lock());

    p_RuntimePipeline->AddPipelineStage(vectorFB, m_Renderer.GetPipelineStage("VectorGraphicsStage").lock());

    p_RuntimePipeline->AddPipelineStage(finalFB, drawForwardStage);
    p_RuntimePipeline->AddPipelineStage(finalFB, drawVectorStage);

    p_RuntimePipeline->SetOutputFramebuffer(finalFB);

}

void harmony::RuntimeProgram::InitializeViews() {
    OPTICK_EVENT();
    auto runtimeViewWr = m_Renderer.CreateView<RuntimeView>(*this);

    m_Renderer.SetViewActive(runtimeViewWr, true);
    p_RuntimeView = runtimeViewWr.lock();

    auto pipelineWr = m_Renderer.GetViewPipeline(runtimeViewWr);
    if(pipelineWr.expired())
    {
        harmony::log::error("RuntimeProgram : Failed to create a runtime view pipeline.");
        return;
    }
    p_RuntimePipeline = pipelineWr.lock();

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
    bgfx::setViewClear(p_PresentViewId, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x00000000, 1.0f);
    auto pipeline = m_Renderer.GetViewPipeline(p_RuntimeView->m_Name);
    bgfx::setTexture(0, m_Renderer.p_PresentProgramTextureHandle, pipeline.lock()->GetOutputFramebuffer().lock()->m_Attachments[0].m_Handle, BGFX_SAMPLER_POINT);
    ScreenSpaceQuad(static_cast<float>(p_WindowWidth), static_cast<float>(p_WindowHeight), static_cast<float>(p_WindowWidth), static_cast<float>(p_WindowHeight));
    bgfx::submit(p_PresentViewId, m_Renderer.p_PresentProgram.lock()->m_Handle);
}
