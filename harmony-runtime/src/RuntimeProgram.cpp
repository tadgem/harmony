#include <optick.h>
#include "RuntimeProgram.h"
#include "AssimpModelAssetFactory.h"
#include "Assets/FontAssetFactory.h"
#include "ECS/EntityTemplate.h"
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
#include "Script/GraphScript/GraphScriptProgramComponent.h"
#include "Script/GraphScript/GraphScriptSystem.h"
#include "Rendering/Pipelines/PipelineStages/SkyStage.h"
#include "Rendering/Modules/Moebius/MoebiusModule.h"
#include "MonoProgramComponent.h"
#include "MonoAssemblyAssetFactory.h"
#include "MonoSystem.h"
#include "JoltMonoBind.h"

harmony::RuntimeProgram::RuntimeProgram(const String &name) : Program(name) {
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


void harmony::RuntimeProgram::Run(const String &projectPath) {
    OPTICK_EVENT();
    Init();
    m_Renderer.Init();

    AddPipelineDrawStages();
    AddPostProcessStages();
    InitializeViews();
    SDL_SetRelativeMouseMode(SDL_TRUE);
    LoadBuiltInAssets();
    LoadProject(projectPath);
    OpenScene(0);
    RunSystemInit();
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
    m_AssetManager.AddAssetFactory(CreateRef<MonoAssemblyAssetFactory>(p_MonoProgramComponent));
    m_AssetManager.AddAssetFactory(CreateRef<JSONTextAssetFactory<EntityTemplate>>());

}

void harmony::RuntimeProgram::AddProgramComponents() {
    OPTICK_EVENT();
    p_LuaProgramComponent = AddProgramComponent<LuaProgramComponent>(m_AssetManager).lock();
    p_GraphScriptComponent = AddProgramComponent<GraphScriptProgramComponent>().lock();

    auto monoMethodProviders = Vector<RefCntPtr<MonoInternalMethodProvider>>();
    monoMethodProviders.emplace_back(CreateRef<JoltMonoInternalMethodProvider>());

    auto monoProgramDelegateProviders = Vector<RefCntPtr<MonoDelegateInvokeProvider>>();
    p_MonoProgramComponent = AddProgramComponent<MonoProgramComponent>(
        m_AssetManager, monoMethodProviders, monoProgramDelegateProviders).lock();
} 

void harmony::RuntimeProgram::AddSystems() {
    OPTICK_EVENT();
    AddSystem<TransformSystem>();
    AddSystem<CameraSystem>();
    AddSystem<MaterialSystem>(m_Renderer, m_AssetManager);
    AddSystem<MeshSystem>(m_AssetManager);
    AddSystem<LightSystem>();
    p_GraphScriptSystem = AddSystem<GraphScriptSystem>(p_GraphScriptComponent).lock();
    p_JoltPhysicsSystem = AddSystem<JoltPhysicsSystem>().lock();
    auto joltMonoCallback = CreateRef<JoltMonoContactListenerCallback>(
        p_JoltPhysicsSystem);
    p_JoltPhysicsSystem->AddContactCallback(joltMonoCallback);
    p_EntityDataSystem = AddSystem<EntityDataSystem>().lock();
    p_LuaSystem = AddSystem<LuaSystem>(m_AssetManager, p_LuaProgramComponent).lock();

    auto monoSystemDelegateProviders = Vector<RefCntPtr<MonoDelegateInvokeProvider>>
    {
        joltMonoCallback
    };

    p_MonoSystem = AddSystem<MonoSystem>(p_MonoProgramComponent, monoSystemDelegateProviders).lock();
}

void harmony::RuntimeProgram::AddPipelineStageRenderers() {
    OPTICK_EVENT();
    m_Renderer.AddPipelineStageRenderer(CreateRef<MeshRenderer>());
}

void harmony::RuntimeProgram::AddPipelineDrawStages() {
    OPTICK_EVENT();
    RefCntPtr<PipelineDrawStage> normalStage = CreateRef<PipelineDrawStage>(
            "NormalStage",
            PipelineDrawStage::Type::PrimaryDraw,
            m_Renderer.GetShader("Normal"),
            m_Renderer.GetPipelineStageRenderer("MeshRenderer")
    );

    RefCntPtr<PipelineDrawStage> texturedMeshStage = CreateRef<PipelineDrawStage>(
            "TexturedMeshStage",
            PipelineDrawStage::Type::PrimaryDraw,
            m_Renderer.GetShader("TexturedMesh"),
            m_Renderer.GetPipelineStageRenderer("MeshRenderer")
    );

    RefCntPtr<PipelineDrawStage> blinnPhongStage = CreateRef<PipelineDrawStage>(
            "BlinnPhongTextured",
            PipelineDrawStage::Type::PrimaryDraw,
            m_Renderer.GetShader("BlinnPhongTextured"),
            m_Renderer.GetPipelineStageRenderer("MeshRenderer")
    );

    RefCntPtr<SkyStage> skyStage = CreateRef<SkyStage>(
            m_Renderer.GetShader("Sky")
    );

    RefCntPtr<VectorGraphicsStage> vectorGraphicsStage = CreateRef<VectorGraphicsStage>(VectorGraphics::Layer::One);
    RefCntPtr<DebugDrawStage> debugDrawStage = CreateRef<DebugDrawStage>(GfxDebug::Channel::Game);

    blinnPhongStage->AddShaderDataSource(m_Renderer.GetShaderDataSource("BlinnPhong"));

    m_Renderer.AddPipelineStage(skyStage);
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
    RefCntPtr<BlinnPhongDataSource> blinnPhong = CreateRef<BlinnPhongDataSource>();
    m_Renderer.AddShaderDataSource(blinnPhong);
}

void harmony::RuntimeProgram::InitializePipelines() {
    OPTICK_EVENT();
    log::info("RuntimeProgram : Initializing View Pipelines");
    if (false)
    {

        auto skyFB = p_RuntimePipeline->AddFramebuffer("Sky FB", { AttachmentType::RGBA16F, AttachmentType::Depth32F },
            Resolution::Type::FullScale);
        auto forwardFB = p_RuntimePipeline->AddFramebuffer("Forward FB",
            { AttachmentType::RGBA16F, AttachmentType::Depth32F },
            Resolution::Type::FullScale);
        auto vectorFB = p_RuntimePipeline->AddFramebuffer("Vector FB", { AttachmentType::RGBA16F, AttachmentType::Depth32F },
            Resolution::Type::FullScale);

        auto crosshatchTexture = m_AssetManager.GetAsset<TextureAsset>("assets\\crosshatch.png");
        auto moebiusFB = Moebius::AddMoebiusToPipeline(m_Renderer, p_RuntimePipeline, crosshatchTexture.lock());

        auto finalFB = p_RuntimePipeline->AddFramebuffer("Final FB", { AttachmentType::RGBA16F, AttachmentType::Depth32F },
            Resolution::Type::FullScale);

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
            forwardFB});
        RefCntPtr<DrawScreenTextureStage> drawVectorStage = CreateRef<DrawScreenTextureStage>(screenShaderWR,
            AttachmentType::RGBA8,
            Vector<WeakPtr<Framebuffer>>{
            vectorFB});
        RefCntPtr<DrawScreenTextureStage> drawMoebiusStage = CreateRef<DrawScreenTextureStage>(screenShaderWR,
            AttachmentType::RGBA8,
            Vector<WeakPtr<Framebuffer>>{
            moebiusFB});

        p_RuntimePipeline->AddPipelineStage(skyFB, m_Renderer.GetPipelineStage("SkyStage").lock());
        p_RuntimePipeline->AddPipelineStage(forwardFB, m_Renderer.GetPipelineStage("DebugDrawStage").lock());
        p_RuntimePipeline->AddPipelineStage(forwardFB, m_Renderer.GetPipelineStage("NormalStage").lock());
        p_RuntimePipeline->AddPipelineStage(forwardFB, m_Renderer.GetPipelineStage("TexturedMeshStage").lock());
        p_RuntimePipeline->AddPipelineStage(forwardFB, m_Renderer.GetPipelineStage("BlinnPhongTextured").lock());

        p_RuntimePipeline->AddPipelineStage(vectorFB, m_Renderer.GetPipelineStage("VectorGraphicsStage").lock());

        p_RuntimePipeline->AddPipelineStage(finalFB, drawSkyStage);
        p_RuntimePipeline->AddPipelineStage(finalFB, drawForwardStage);
        p_RuntimePipeline->AddPipelineStage(finalFB, drawMoebiusStage);
        p_RuntimePipeline->AddPipelineStage(finalFB, drawVectorStage);

        p_RuntimePipeline->SetOutputFramebuffer(finalFB);
    }

}

void harmony::RuntimeProgram::InitializeViews() {
    OPTICK_EVENT();
    log::info("RuntimeProgram : Initializing Views");
    auto runtimeViewWr = m_Renderer.CreateView<RuntimeView>(*this);

    m_Renderer.SetViewActive(runtimeViewWr, true);
    p_RuntimeView = runtimeViewWr.lock();

    auto pipelineWr = m_Renderer.GetViewPipeline(runtimeViewWr);
    if (pipelineWr.expired()) {
        harmony::log::error("RuntimeProgram : Failed to create a runtime view pipeline.");
        return;
    }
    p_RuntimePipeline = pipelineWr.lock();

}


void harmony::RuntimeProgram::LoadScene(const String &path) {
    OPTICK_EVENT();
    log::info("RuntimeProgram : Load Scene at path : {}", path);
    Program::LoadScene(path);
    //RunSystemInit();
}

void harmony::RuntimeProgram::OpenScene(uint32_t index) {
    OPTICK_EVENT();
    Program::OpenScene(index);
    log::info("RuntimeProgram : Open Scene at index : {}", index);
    //RunSystemInit();
}

int harmony::RuntimeProgram::OnRuntimeUpdate() {
    OPTICK_EVENT();
    UpdateTimeVariables();

    HandleSDLEvent();

    RunRendererPreUpdate();

    RunProgramComponentUpdate();

    RunSystemUpdate();

    RunProgramComponentRender();

    RunSystemRender();

    RunRendererPostUpdate();

    PresentRuntimeImage();

    Frame();

    return FSM::NO_TRIGGER;
}

void harmony::RuntimeProgram::LoadBuiltInAssets() {
    OPTICK_EVENT();
    log::info("RuntimeProgram : Loading built in assets");
    AssetHandle cubeHandle = m_AssetManager.AddBuiltInAsset<Mesh>("builtin/Cube", CreateRef<Cube>(1.0f));
    RefCntPtr<Mesh> cube = m_AssetManager.GetAsset<Mesh>(cubeHandle).lock();
    m_Renderer.SubmitMeshToGPU(cube);
    AssetHandle planeHandle = m_AssetManager.AddBuiltInAsset<Mesh>("builtin/Plane", CreateRef<Plane>(1.0f));
    RefCntPtr<Mesh> plane = m_AssetManager.GetAsset<Mesh>(planeHandle).lock();
    m_Renderer.SubmitMeshToGPU(plane);
}

void harmony::RuntimeProgram::ResizeApplicationWindow(int w, int h) {
    OPTICK_EVENT();
    log::info("RuntimeProgram : App window resized, new size : w {} h {}", w,h);
    Program::ResizeApplicationWindow(w, h);
    bgfx::setViewRect(p_PresentViewId, 0, 0, p_WindowWidth, p_WindowHeight);

    p_RuntimeView->OnResized(p_WindowWidth, p_WindowHeight);
}

void harmony::RuntimeProgram::PresentRuntimeImage() {
    OPTICK_EVENT();
    bgfx::setViewClear(p_PresentViewId, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x00000000, 1.0f);
    auto pipeline = m_Renderer.GetViewPipeline(p_RuntimeView);
    auto fb = pipeline.lock()->GetOutputFramebuffer().lock();
    bgfx::setTexture(0, m_Renderer.p_PresentProgramTextureHandle, fb->m_Attachments[0].m_Handle, BGFX_SAMPLER_POINT);
    ScreenSpaceQuad(static_cast<float>(fb->m_FramebufferResolution.Width),
                    static_cast<float>(fb->m_FramebufferResolution.Height), static_cast<float>(p_WindowWidth),
                    static_cast<float>(p_WindowHeight));
    bgfx::submit(p_PresentViewId, m_Renderer.p_PresentProgram.lock()->m_Handle);
}
