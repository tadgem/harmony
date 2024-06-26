#include "STL/Algorithm.h"
#include <optick.h>
#include "Rendering/Renderer.h"

#include "bgfx/platform.h"
#include "ECS/ModelComponent.h"
#include "ECS/MeshComponent.h"
#include "ECS/MaterialComponent.h"
#include "Core/Log.hpp"
#include "Core/Time.h"
#include "Core/SerializationKeys.h"
#include "Rendering/Shaders/BuiltinShaders.h"
#include "Rendering/Shapes.h"
#include "Rendering/View.h"
#include "Rendering/Pipelines/PipelineStageRenderer.h"
#include "Rendering/Shaders/ShaderDataSource.h"
#include "Rendering/Pipelines/PipelineStages/PostProcessStage.h"
#include "Rendering/Pipelines/PipelineStages/PipelineDrawStage.h"

#if HARMONY_DEBUG

#include "ImGui/imgui_bgfx.h"
#include "ImGui/imgui.h"
#include "ImGui/icons_font_awesome.h"

#endif

harmony::Renderer::Renderer(AssetManager &assetManager) : p_AssetManager(assetManager) {
    OPTICK_EVENT();

#if HARMONY_DEBUG
    p_CreatePipelineWindow = false;
    p_CreateShaderProgramWindow = false;
    p_CreatePostProcessStageWindow = false;
    p_CreateDrawStageWindow = false;
    p_SelectedPipelineType = 0;
    p_SelectedPipelineDrawStageType = 0;
#endif
}

harmony::WeakPtr<harmony::ShaderProgram>
harmony::Renderer::AddBuiltInShader(const String &progName, const String &vsName, const String &fsName,
                                    uint32_t vsIndex, uint32_t fsIndex) {
    OPTICK_EVENT();
    RefCntPtr<ShaderProgram> prog = CreateRef<ShaderProgram>(progName);
    RefCntPtr<BuiltInShaderStage> vs = CreateRef<BuiltInShaderStage>(vsName, ShaderStage::Type::Vertex,
                                                                     s_BuiltInShader[vsIndex]);
    vs->LoadShaderBinary();
    RefCntPtr<BuiltInShaderStage> fs = CreateRef<BuiltInShaderStage>(fsName, ShaderStage::Type::Fragment,
                                                                     s_BuiltInShader[fsIndex]);
    fs->LoadShaderBinary();
    prog->AddStage(ShaderStage::Type::Vertex, vs);
    prog->AddStage(ShaderStage::Type::Fragment, fs);

    prog->Build();

    p_Shaders.emplace_back(prog);
    p_BuiltInShaders.emplace_back(prog);

    return prog;
}

harmony::WeakPtr<harmony::ShaderProgram>
harmony::Renderer::AddBuiltInShader(const String &progName, const String &csName, uint32_t csIndex) {
    OPTICK_EVENT();
    RefCntPtr<ShaderProgram> prog = CreateRef<ShaderProgram>(progName);
    RefCntPtr<BuiltInShaderStage> cs = CreateRef<BuiltInShaderStage>(csName, ShaderStage::Type::Compute,
                                                                     s_BuiltInShader[csIndex]);
    cs->LoadShaderBinary();
    prog->AddStage(ShaderStage::Type::Compute, cs);

    prog->Build();

    p_Shaders.emplace_back(prog);
    p_BuiltInShaders.emplace_back(prog);

    return prog;
}

void harmony::Renderer::AddBuiltInShaders() {
    OPTICK_EVENT();
    p_PresentProgram = AddBuiltInShader("TexturedMesh", "vs_simple_textured", "fs_simple_textured", 0, 1);
    p_PresentProgramTextureHandle = p_PresentProgram.lock()->m_Uniforms[0].BgfxHandle;
    AddBuiltInShader("Normal", "vs_normal", "fs_normal", 2, 3);
    AddBuiltInShader("NanoVG", "vs_nanovg_fill", "fs_nanovg_fill", 4, 5);
    AddBuiltInShader("BlinnPhongTextured", "vs_blinn_phong_textured", "fs_blinn_phong_textured", 6, 7);
    AddBuiltInShader("FXAA", "vs_simple_textured", "fs_fxaa", 0, 8);
    AddBuiltInShader("Sky", "vs_sky", "fs_sky", 9, 10);
    AddBuiltInShader("DeferredGBuffer", "vs_deferred_geom", "fs_deferred_geom", 11, 12);
    AddBuiltInShader("Moebius", "vs_simple_textured", "fs_moebius", 0, 13);
}

harmony::WeakPtr<harmony::ShaderProgram>
harmony::Renderer::BuildShader(const String name, WeakPtr<ShaderStage> vertStage, WeakPtr<ShaderStage> fragStage) {
    OPTICK_EVENT();
    RefCntPtr<ShaderProgram> prog = CreateRef<ShaderProgram>(name);
    RefCntPtr<ShaderStage> vs = vertStage.lock();
    RefCntPtr<ShaderStage> fs = fragStage.lock();
    vs->LoadShaderBinary();
    fs->LoadShaderBinary();
    prog->AddStage(ShaderStage::Type::Vertex, vs);
    prog->AddStage(ShaderStage::Type::Fragment, fs);

    prog->Build();

    p_Shaders.emplace_back(prog);

    return GetWeakRef<ShaderProgram>(prog);
}

harmony::WeakPtr<harmony::ShaderProgram>
harmony::Renderer::BuildShader(const String name, WeakPtr<ShaderStage> computeStage) {
    OPTICK_EVENT();
    RefCntPtr<ShaderProgram> prog = CreateRef<ShaderProgram>(name);
    RefCntPtr<ShaderStage> cs = computeStage.lock();

    cs->LoadShaderBinary();

    prog->AddStage(ShaderStage::Type::Compute, cs);

    prog->Build();

    p_Shaders.emplace_back(prog);

    return GetWeakRef<ShaderProgram>(prog);
}

uint32_t harmony::Renderer::p_ViewHandleCounter = 2;

uint32_t harmony::Renderer::p_PresentViewHandleCounter = 1;

harmony::WeakPtr<harmony::View> harmony::Renderer::GetView(const String &name) {
    OPTICK_EVENT();
    for (auto &[view, stack]: p_Views) {
        if (view->m_Name == name) {
            return view;
        }
    }
    return WeakPtr<View>();
}

harmony::WeakPtr<harmony::PipelineV2> harmony::Renderer::GetViewPipeline(WeakPtr<View> view) {
    OPTICK_EVENT();

    if (view.expired()) {
        harmony::log::error("Renderer : Cannot get view pipeline, passed view is expired.");
        return WeakPtr<PipelineV2>();
    }
    auto v = view.lock();
    if (p_Views.find(v) != p_Views.end()) {
        return p_Views[v];
    }

    return WeakPtr<PipelineV2>();
}

void harmony::Renderer::RemoveView(WeakPtr<View> view) {
    OPTICK_EVENT();
    if (view.expired()) {
        harmony::log::error("Renderer : Removing expired view weak ref!");
        return;
    }
    {
        RefCntPtr<View> _view = view.lock();
        p_Views.erase(_view);
    }
}

void harmony::Renderer::SetViewActive(WeakPtr<View> viewWeakRef, bool active) {
    OPTICK_EVENT();
    if (viewWeakRef.expired()) {
        harmony::log::warn("Passed Weak RefCntPtr to view which is not managed by view manager!");
        return;
    }

    auto view = viewWeakRef.lock();
    int indexToRemove = -1;

    for (int i = 0; i < m_ActiveViews.size(); i++) {
        if (m_ActiveViews[i].lock() == view) {
            if (active) {
                harmony::log::info("View already active!");
                return;
            } else {
                indexToRemove = i;
            }
        }
    }

    if (indexToRemove >= 0) {
        m_ActiveViews.erase(m_ActiveViews.begin() + indexToRemove);
    } else {
        m_ActiveViews.emplace_back(viewWeakRef);
    }

}

void harmony::Renderer::Init() {
    OPTICK_EVENT();
    PosColorTexCoord0Vertex::init();
    AddBuiltInShaders();
}

void harmony::Renderer::OnPreUpdate(entt::registry &registry) {
    OPTICK_EVENT();

    for (int i = 0; i < m_ActiveViews.size(); i++) {
        if (m_ActiveViews[i].expired()) {
            harmony::log::warn("View {} is expired.", i);
            continue;
        }

        RefCntPtr<View> view = m_ActiveViews[i].lock();
        RefCntPtr<PipelineV2> pipeline = p_Views[view];

        if (view->p_Resized) {
            pipeline->Resize(registry, view);
            view->p_Resized = false;
        }

        view->OnPreUpdate(registry);
        pipeline->PreUpdate(registry, view);
    }
}

void harmony::Renderer::OnPostUpdate(entt::registry &registry) {
    OPTICK_EVENT();

    for (int i = 0; i < m_ActiveViews.size(); i++) {
        if (m_ActiveViews[i].expired()) {
            harmony::log::warn("View {} is expired.", i);
            continue;
        }

        RefCntPtr<View> view = m_ActiveViews[i].lock();
        RefCntPtr<PipelineV2> pipeline = p_Views[view];
        RefCntPtr<ShaderProgram> prog = p_PresentProgram.lock();
        pipeline->PostUpdate(registry, view);
    }
}

harmony::WeakPtr<harmony::PipelineV2> harmony::Renderer::GetViewPipelineFromName(const String &viewName) {
    OPTICK_EVENT();
    for (auto &[view, p]: p_Views) {
        if (view->m_Name == viewName) {
            return p;
        }
    }
    harmony::log::error("No pipeline stack with name : {}", viewName);
    return WeakPtr<PipelineV2>();
}

void harmony::Renderer::RefreshViews() {
    OPTICK_EVENT();
    for (auto &[view, stack]: p_Views) {
        view->OnResized(view->m_Width, view->m_Height);
    }
}

#if HARMONY_DEBUG

void harmony::Renderer::OnImGui() {
    OPTICK_EVENT();
    const String rendererTitle = String(ICON_FA_SLIDERS) + " Renderer";

    ImGui::SetNextWindowSizeConstraints(ImVec2(300, 300), ImVec2(300, 300));
    if (ImGui::Begin(rendererTitle.c_str())) {
        ImGui::Text("Frametime : %f, ", Time::GetFrameTime() * 1000.0f);
        ImGui::SameLine();
        ImGui::Text("FPS : %f", 1.0 / Time::GetFrameTime());
        ImGui::Separator();
        if (ImGui::CollapsingHeader("[Shaders]", ImGuiTreeNodeFlags_SpanFullWidth | ImGuiTreeNodeFlags_Framed)) {
            ImGui::Indent();
            for (auto &shader: p_Shaders) {
                ImGui::Text(shader->m_Name.c_str());
            }
            ImGui::Unindent();
            ImGui::Separator();
            if (ImGui::Button("Create Shader")) {
                p_CreateShaderProgramWindow = true;
            }
        }
        ImGui::Separator();
        if (ImGui::CollapsingHeader("[DrawStages]", ImGuiTreeNodeFlags_SpanFullWidth | ImGuiTreeNodeFlags_Framed)) {
            ImGui::Indent();
            ImGui::Unindent();
            ImGui::Separator();
            if (ImGui::Button("Create Draw Stage")) {
                p_CreateDrawStageWindow = true;
            }
        }
        ImGui::Separator();
        if (ImGui::CollapsingHeader("[PostProcessStages]",
                                    ImGuiTreeNodeFlags_SpanFullWidth | ImGuiTreeNodeFlags_Framed)) {
            ImGui::Indent();
            ImGui::Unindent();
            ImGui::Separator();
            if (ImGui::Button("Create Post Process Stage")) {
                p_CreatePostProcessStageWindow = true;
            }
        }
        
        ImGui::Separator();
    }
    ImGui::End();

    if (p_CreateShaderProgramWindow) {
        ImGui::SetNextWindowSize(ImVec2(320, 180));
        if (ImGui::Begin("New Shader")) {
            // Type
            // VS and FS Asset Selector
            ImGui::Text("Surface Shader");

            p_AssetManager.AssetTypeSelector<ShaderStage>("Vert Stage", p_SelectedVertexAsset);
            p_AssetManager.AssetTypeSelector<ShaderStage>("Frag Stage", p_SelectedFragmentAsset);

            ImGui::InputText("Shader Name", p_ShaderNameInput, 64);

            if (ImGui::Button("Build")) {
                bool canBuild = true;
                WeakPtr<ShaderStage> vStage = p_AssetManager.GetAsset<ShaderStage>(p_SelectedVertexAsset);
                WeakPtr<ShaderStage> fStage = p_AssetManager.GetAsset<ShaderStage>(p_SelectedFragmentAsset);

                if (vStage.expired()) {
                    harmony::log::error("Cannot build shader, invalid vertex stage provided");
                    canBuild = false;
                }

                if (fStage.expired()) {
                    harmony::log::error("Cannot build shader, invalid vertex stage provided");
                    canBuild = false;
                }

                String shaderName = String(p_ShaderNameInput);
                Utils::TrimString(shaderName);

                if (shaderName.size() == 0) {
                    canBuild = false;
                }

                if (canBuild) {
                    BuildShader(shaderName, vStage, fStage);
                    p_CreateShaderProgramWindow = false;
                }

            }
        }
        ImGui::End();
    }

    if (p_CreatePipelineWindow) {
        ImGui::SetNextWindowSize(ImVec2(320, 180));
        if (ImGui::Begin("New Pipeline")) {
            static String pipelineTypes[] = {"Compute", "ScreenSpace", "Surface", "PostProcess"};
            ImGui::Text("Basic Surface Pipeline");
            ImGui::InputText("Pipeline Name", p_PipelineNameInput, 64);
            if (ImGui::BeginCombo("Pipeline Type", pipelineTypes[p_SelectedPipelineType].c_str())) {
                for (int i = 0; i < BX_COUNTOF(pipelineTypes); i++) {
                    if (ImGui::Selectable(pipelineTypes[i].c_str())) {
                        p_SelectedPipelineType = i;
                    }
                }
                ImGui::EndCombo();
            }
            ShaderSelector("Choose Surface Shader", p_SelectedShaderProgram);

            if (ImGui::Button("Create Pipeline")) {
                bool canCreate = true;
                if (p_SelectedShaderProgram.expired()) {
                    harmony::log::error("Cannot create pipeline : invalid shader selected.");
                    canCreate = false;
                }

                String pipelineName = String(p_PipelineNameInput);
                Utils::TrimString(pipelineName);

                if (pipelineName.size() == 0) {
                    canCreate = false;
                }

                if (canCreate) {
                }

            }
        }
        ImGui::End();
    }

    if (p_CreateDrawStageWindow) {
        ImGui::SetNextWindowSize(ImVec2(320, 180));
        if (ImGui::Begin("New Draw Stage")) {
            ImGui::InputText("Name", &p_PipelineDrawStageNameInput[0], 64);
            PipelineStageRendererSelector("Stage Renderer", p_SelectedRenderer);
            ShaderSelector("Stage Shader", p_SelectedShaderProgram);
            if (ImGui::Button("Build")) {
                String name = String(p_PipelineDrawStageNameInput);
                Utils::TrimString(name);
                RefCntPtr<PipelineDrawStage> stage = CreateRef<PipelineDrawStage>(
                        name,
                        PipelineStage::Type::PrimaryDraw, // TODO: Make selectable
                        p_SelectedShaderProgram,
                        p_SelectedRenderer
                );
                p_CreateDrawStageWindow = false;
            }
            ImGui::SameLine();
            if (ImGui::Button("Cancel")) {
                p_CreateDrawStageWindow = false;
            }
        }
        ImGui::End();
    }

    if (p_CreatePostProcessStageWindow) {
        ImGui::SetNextWindowSize(ImVec2(320, 180));
        if (ImGui::Begin("New Post Process Draw Stage")) {
            ImGui::InputText("Name", &p_PipelinePostProcessStageNameInput[0], 64);
            ShaderSelector("Stage Shader", p_SelectedShaderProgram);
            if (ImGui::Button("Build")) {
                String name = String(p_PipelinePostProcessStageNameInput);
                Utils::TrimString(name);
                Vector<AttachmentType> attachments{AttachmentType::RGBA8};
                RefCntPtr<PostProcessStage> stage = CreateRef<PostProcessStage>(
                        name,
                        PipelineStage::Type::PostProcess, // TODO: Make selectable
                        p_SelectedShaderProgram,
                        WeakPtr<PipelineStageRenderer>(),
                        attachments
                );
                // AddPostProcessStage(stage);
                p_CreatePostProcessStageWindow = false;
            }
            ImGui::SameLine();
            if (ImGui::Button("Cancel")) {
                p_CreatePostProcessStageWindow = false;
            }
        }
        ImGui::End();
    }

    for (auto &[view, stack]: p_Views) {
        view->OnImGui();
    }
}

bool
harmony::Renderer::ShaderSelector(const String &selectorName, harmony::WeakPtr<harmony::ShaderProgram> &prog) {
    OPTICK_EVENT();
    bool selectedAsset = false;
    Vector<String> shaders = GetShaderNames();

    if (ImGui::BeginCombo(selectorName.c_str(), "")) {
        for (int i = 0; i < shaders.size(); i++) {
            if (ImGui::Selectable(shaders[i].c_str())) {
                prog = GetShader(shaders[i]);
                selectedAsset = true;
            }
        }
        ImGui::EndCombo();
    }

    return selectedAsset;

}

bool harmony::Renderer::PipelineStageRendererSelector(const String &selectorName,
                                                      harmony::WeakPtr<harmony::PipelineStageRenderer> renderer) {
    OPTICK_EVENT();
    bool selectedAsset = false;

    if (ImGui::BeginCombo(selectorName.c_str(), "")) {
        for (int i = 0; i < p_PipelineStageRenderers.size(); i++) {
            if (ImGui::Selectable(p_PipelineStageRenderers[i]->m_Name.c_str())) {
                renderer = p_PipelineStageRenderers[i];
                selectedAsset = true;
            }
        }
        ImGui::EndCombo();
    }

    return selectedAsset;
}

#endif

bool harmony::Renderer::IsBuiltInShaderName(const String &name) {
    OPTICK_EVENT();
    for (int i = 0; i < p_BuiltInShaders.size(); i++) {
        RefCntPtr<ShaderProgram> shader = p_BuiltInShaders[i].lock();

        if (!shader) {
            harmony::log::error("Renderer : Invalid built in shader. This should never happen");
            continue;
        }

        if (shader->m_Name == name) {
            return true;
        }
    }
    return false;
}

bgfx::ViewId harmony::Renderer::GetViewID() {
    OPTICK_EVENT();
    bgfx::ViewId v = p_ViewHandleCounter;
    p_ViewHandleCounter++;
    return v;
}

bgfx::ViewId harmony::Renderer::GetPresentViewID() {
    OPTICK_EVENT();
    bgfx::ViewId v = p_MaxViews - p_PresentViewHandleCounter;
    p_PresentViewHandleCounter++;
    return v;
}

harmony::Json harmony::Renderer::Serialize() {
    OPTICK_EVENT();
    auto json = Json();

    json[sk_RendererName] = Json();
    json[sk_RendererName][sk_RendererShaderCollection] = SerializeShaders();
    json[sk_RendererName][sk_RendererDrawStageCollection] = SerializePipelineDrawStages();
    json[sk_RendererName][sk_RendererPostProcessStageCollection] = SerializePostProcessStages();
    json[sk_RendererName][sk_RendererStageRendererCollection] = SerializePipelineStageRenderers();
    json[sk_RendererName][sk_RendererShaderDataSourceCollection] = SerializeShaderDataSources();
    json[sk_RendererName][sk_RendererViewCollection] = SerializeViews();
    json[sk_RendererName][sk_RendererActiveViewCollection] = SerializeActiveViews();

    return json;
}

void harmony::Renderer::Deserialize(AssetManager &am, Json &json) {
    OPTICK_EVENT();
    harmony::log::info("Renderer : De-serializing Project Renderer Data");

    DeserializeShaders(json, am);
    DeserializePipelineDrawStages(json, am);
    DeserializePostProcessStages(json, am);
    DeserializePipelineStageRenderers(json, am);
    DeserializeShaderDataSources(json, am);
    DeserializeViews(json, am);
    DeserializeActiveViews(json, am);
}

void harmony::Renderer::AddPipelineStageRenderer(RefCntPtr<PipelineStageRenderer> renderer) {
    OPTICK_EVENT();
    auto it = Find(p_PipelineStageRenderers.begin(), p_PipelineStageRenderers.end(), renderer);

    if (it == p_PipelineStageRenderers.end()) {
        p_PipelineStageRenderers.push_back(renderer);
        return;
    }
}

harmony::WeakPtr<harmony::PipelineStageRenderer> harmony::Renderer::GetPipelineStageRenderer(const String &name) {
    OPTICK_EVENT();
    for (int i = 0; i < p_PipelineStageRenderers.size(); i++) {
        if (p_PipelineStageRenderers[i]->m_Name == name) {
            return p_PipelineStageRenderers[i];
        }
    }
    return WeakPtr<PipelineStageRenderer>();
}

void harmony::Renderer::ReloadShader(WeakPtr<ShaderProgram> shader) {
    OPTICK_EVENT();
    if (shader.expired()) {
        harmony::log::error("Trying to reload an invalid shader.");
        return;
    }

    RefCntPtr<ShaderProgram> prog = shader.lock();

    for (int i = 0; i < p_BuiltInShaders.size(); i++) {
        if (p_BuiltInShaders[i].expired()) {
            continue;
        }

        auto b = p_BuiltInShaders[i].lock();
        if (prog == b) {
            harmony::log::warn("Cannot reload a built in shader");
            return;
        }
    }

    prog->Destroy();
    for (auto &[type, stageWr]: prog->m_Stages) {
        if (stageWr.expired()) {
            harmony::log::error("Trying to reload an invalid shader.");
            return;
        }

        RefCntPtr<ShaderStage> stage = stageWr.lock();
        stage->LoadShaderBinary();
    }

    prog->Build();

}

void harmony::Renderer::ReloadAllShaders() {
    OPTICK_EVENT();
    for (auto shader: p_Shaders) {
        ReloadShader(shader);
    }
}

bool harmony::Renderer::IsShaderLoaded(const String &name) {
    OPTICK_EVENT();
    for (auto &shader: p_Shaders) {
        if (shader->m_Name == name) {
            return true;
        }
    }
    return false;
}

harmony::WeakPtr<harmony::ShaderProgram> harmony::Renderer::GetShader(const String &name) {
    OPTICK_EVENT();
    for (auto &shader: p_Shaders) {
        if (shader->m_Name == name) {
            return GetWeakRef<ShaderProgram>(shader);
        }
    }
    return WeakPtr<ShaderProgram>();
}

harmony::Vector<harmony::String> harmony::Renderer::GetShaderNames() {
    OPTICK_EVENT();
    Vector<String> shaders = Vector<String>();
    for (auto &shader: p_Shaders) {
        shaders.push_back(shader->m_Name);
    }
    return shaders;
}

void harmony::Renderer::AddPipelineStage(RefCntPtr<PipelineStage> pipelineStage) {
    OPTICK_EVENT();
    if (!pipelineStage) {
        harmony::log::warn("Renderer : Invalid PipelineStage supplied, doing nothing.");
        return;
    }

    if (Find(p_PipelineStages.begin(), p_PipelineStages.end(), pipelineStage) != p_PipelineStages.end()) {
        harmony::log::warn("Renderer : PipelineStage : {} : Already managed by renderer.", pipelineStage->m_Name);
        return;
    }

    p_PipelineStages.emplace_back(pipelineStage);
}

harmony::WeakPtr<harmony::PipelineStage> harmony::Renderer::GetPipelineStage(const String &name) {
    OPTICK_EVENT();
    for (auto p: p_PipelineStages) {
        if (p->m_Name == name) {
            return p;
        }
    }
    harmony::log::warn("Renderer : GetPipelineStage : Cannot find PipelineStage : {}", name);
    return WeakPtr<PipelineStage>();
}

void harmony::Renderer::AddShaderDataSource(RefCntPtr<ShaderDataSource> dataSource) {
    OPTICK_EVENT();
    if (Find(p_ShaderDataSources.begin(), p_ShaderDataSources.end(), dataSource) != p_ShaderDataSources.end()) {
        harmony::log::warn(
                "Renderer : Trying to add a shader data source that the renderer has already been provided.");
        return;
    }
    p_ShaderDataSources.emplace_back(dataSource);
}

harmony::WeakPtr<harmony::ShaderDataSource> harmony::Renderer::GetShaderDataSource(const String &name) {
    OPTICK_EVENT();
    for (int i = 0; i < p_ShaderDataSources.size(); i++) {
        if (p_ShaderDataSources[i]->m_Name == name) {
            return p_ShaderDataSources[i];
        }
    }
    return WeakPtr<ShaderDataSource>();
}

harmony::BGFXMeshHandle harmony::Renderer::SubmitMeshToGPU(WeakPtr<Mesh> mesh) {
    OPTICK_EVENT();

    auto meshRef = mesh.lock();
    BGFXMeshHandle m = BGFXMeshHandle();
    m.m_Layout = BuildVertexLayout(mesh);
    meshRef->BuildBGFXData();
    uint32_t indexBufferSize    = static_cast<uint32_t>(meshRef->m_Indices.size() * sizeof(unsigned int));
    uint32_t vertexBufferSize   = static_cast<uint32_t>(meshRef->m_BGFXData.size() * sizeof(float));
    m.m_VBH = bgfx::createVertexBuffer(bgfx::makeRef(meshRef->m_BGFXData.data(), vertexBufferSize), m.m_Layout);
    m.m_IBH = bgfx::createIndexBuffer( bgfx::makeRef(meshRef->m_Indices.data(), indexBufferSize), BGFX_BUFFER_INDEX32);
    meshRef->m_SubmittedToGpu = true;
    meshRef->m_Handle = m;
    return m;
}

harmony::BGFXTextureHandle harmony::Renderer::SubmitTextureToGPU(WeakPtr<TextureAsset> textureWeakRef) {
    OPTICK_EVENT();
    uint64_t flags = 0;
    BGFXTextureHandle handle;
    RefCntPtr<TextureAsset> texture = textureWeakRef.lock();
    handle.Handle = texture->m_Handle;
    bimg::ImageContainer *imageContainer = texture->p_ImageContainer;

    if (imageContainer->m_cubeMap) {
        handle.BgfxHandle = bgfx::createTextureCube(
                uint16_t(imageContainer->m_width), 1 < imageContainer->m_numMips, imageContainer->m_numLayers,
                bgfx::TextureFormat::Enum(imageContainer->m_format), flags, texture->p_Memory
        );
    } else if (1 < imageContainer->m_depth) {
        handle.BgfxHandle = bgfx::createTexture3D(
                uint16_t(imageContainer->m_width), uint16_t(imageContainer->m_height),
                uint16_t(imageContainer->m_depth), 1 < imageContainer->m_numMips,
                bgfx::TextureFormat::Enum(imageContainer->m_format), flags, texture->p_Memory
        );
    } else if (bgfx::isTextureValid(0, false, imageContainer->m_numLayers,
                                    bgfx::TextureFormat::Enum(imageContainer->m_format), flags)) {
        handle.BgfxHandle = bgfx::createTexture2D(
                uint16_t(imageContainer->m_width), uint16_t(imageContainer->m_height), 1 < imageContainer->m_numMips,
                imageContainer->m_numLayers, bgfx::TextureFormat::Enum(imageContainer->m_format), flags,
                texture->p_Memory
        );
    }

    if (bgfx::isValid(handle.BgfxHandle)) {
        bgfx::setName(handle.BgfxHandle, texture->m_Handle.Path.c_str());
    }

    if (&handle.Info != NULL) {
        bgfx::calcTextureSize(
                handle.Info, uint16_t(imageContainer->m_width), uint16_t(imageContainer->m_height),
                uint16_t(imageContainer->m_depth), imageContainer->m_cubeMap, 1 < imageContainer->m_numMips,
                imageContainer->m_numLayers, bgfx::TextureFormat::Enum(imageContainer->m_format)
        );
    }

    texture->m_TextureHandle = handle;
    texture->m_SubmittedToGPU = true;
    return handle;
}

bgfx::VertexLayout harmony::Renderer::BuildVertexLayout(WeakPtr<Mesh> meshWeakRef) {
    OPTICK_EVENT();
    auto mesh = meshWeakRef.lock();
    bgfx::VertexLayout vl = bgfx::VertexLayout();
    vl.begin();

    // do we need to support 2 component positions?
    vl.add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float);

    if (mesh->m_HasNormals) {
        vl.add(bgfx::Attrib::Normal, 3, bgfx::AttribType::Float);
    }

    if (mesh->m_HasUVs) {
        vl.add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float);
    }

    if (mesh->m_HasTangents) {
        vl.add(bgfx::Attrib::Tangent, 3, bgfx::AttribType::Float);
    }

    if (mesh->m_HasBitangents) {
        vl.add(bgfx::Attrib::Bitangent, 3, bgfx::AttribType::Float);
    }

    vl.end();
    return vl;

}

harmony::Json harmony::Renderer::SerializeShaders() {
    OPTICK_EVENT();
    auto json = Json::array();
    for (auto &shader: p_Shaders) {
        Json shaderJson;

        shaderJson[sk_ShaderProgram] = *shader;

        json.emplace_back(shaderJson);
    }
    return json;
}

harmony::Json harmony::Renderer::SerializePipelineDrawStages() {
    OPTICK_EVENT();
    auto json = Json::array();

    return json;
}

harmony::Json harmony::Renderer::SerializePostProcessStages() {
    OPTICK_EVENT();
    auto json = Json::array();
    return json;
}

harmony::Json harmony::Renderer::SerializePipelineStageRenderers() {
    OPTICK_EVENT();
    auto json = Json::array();
    for (auto &renderer: p_PipelineStageRenderers) {
        json.emplace_back(renderer);
    }

    return json;
}

harmony::Json harmony::Renderer::SerializeShaderDataSources() {
    OPTICK_EVENT();
    auto json = Json::array();
    for (auto &source: p_ShaderDataSources) {
        json.emplace_back(source);
    }

    return json;
}

harmony::Json harmony::Renderer::SerializeViews() {
    OPTICK_EVENT();
    auto json = Json::array();
    for (auto &[view, stack]: p_Views) {
        Json viewJson;
        viewJson[sk_ViewData] = view->Serialize();
        json.emplace_back(viewJson);

    }

    return json;
}

harmony::Json harmony::Renderer::SerializeActiveViews() {
    OPTICK_EVENT();
    auto json = Json::array();
    for (WeakPtr<View> viewWr: m_ActiveViews) {
        if (viewWr.expired()) {
            continue;
        }

        RefCntPtr<View> view = viewWr.lock();
        json.emplace_back(view->Serialize());
    }
    return json;
}

void harmony::Renderer::DeserializeShaders(Json &json, AssetManager &am) {
    OPTICK_EVENT();
    harmony::log::info("Renderer : Deserializing Shaders");
    for (auto shaderJson: json[sk_RendererName][sk_RendererShaderCollection]) {
        auto dataJson = shaderJson[sk_ShaderDataContainer];
        auto programJson = shaderJson[sk_ShaderProgram];

        if (IsBuiltInShaderName(programJson[sk_ShaderProgramName])) {
            continue;
        }

        harmony::log::info("Renderer : Deserializing shader {}", programJson[sk_ShaderProgramName]);

        String shaderName = programJson[sk_ShaderProgramName];
        if (IsShaderLoaded(shaderName)) {
            continue;
        }

        Map<ShaderStage::Type, RefCntPtr<ShaderStage>> stages = Map<ShaderStage::Type, RefCntPtr<ShaderStage>>();

        for (auto stageJson: programJson[sk_ShaderProgramStages]) {
            const int StageTypeIndex = 0;
            const int StageDataIndex = 1;
            auto stageDataJson = stageJson[StageDataIndex];
            AssetHandle assetHandle = stageDataJson[sk_AssetHandle];
            String stageName = stageDataJson[sk_ShaderStageName];
            ShaderStage::Type stageType = stageDataJson[sk_ShaderStageType];

            if (am.IsPathLoaded(assetHandle.Path)) {
                auto stage = am.GetAsset<ShaderStage>(assetHandle);
                if (stage.expired()) {
                    harmony::log::warn("Renderer : Shader Stage {} is supposedly loaded but cannot be found.",
                                       assetHandle.Path);
                } else {
                    stages.emplace(stageType, stage.lock());
                }
            } else {
                auto handles = am.LoadAsset<ShaderStage>(assetHandle.Path);

                if(handles.size() == 0)
                {
                    harmony::log::error("Renderer : Failed to load shader stage, asset not found at path : {}",
                                       assetHandle.Path);
                }
                else
                {
                    auto stage = am.GetAsset<ShaderStage>(handles[0]);
                    if (stage.expired()) {
                        harmony::log::warn("Renderer : Shader Stage {} could not be loaded.", assetHandle.Path);
                    } else {
                        stages.emplace(stageType, stage);
                    }
                }

            }
        }

        if (stages.find(ShaderStage::Type::Compute) != stages.end()) {
            harmony::log::info("Renderer : Loading compute shader {}", shaderName);
            BuildShader(shaderName, stages[ShaderStage::Type::Compute]);
            return;
        }

        if (stages.find(ShaderStage::Type::Vertex) != stages.end() &&
            stages.find(ShaderStage::Type::Fragment) != stages.end()) {
            harmony::log::info("Renderer : Loading surface shader {}", shaderName);
            BuildShader(shaderName, stages[ShaderStage::Type::Vertex], stages[ShaderStage::Type::Fragment]);
            return;
        }

        harmony::log::error("Renderer : failed to deserialize shader : {}", shaderName);
    }
}

void harmony::Renderer::DeserializePipelineDrawStages(Json &json, AssetManager &am) {
    OPTICK_EVENT();
    harmony::log::info("TODO : Deserialize pipeline draw stages.");
}

void harmony::Renderer::DeserializePostProcessStages(Json &json, AssetManager &am) {
    OPTICK_EVENT();
    harmony::log::info("Renderer : Deserializing Post Process Stages");
    for (auto postProcessJson: json[sk_RendererName][sk_RendererPostProcessStageCollection]) {
        String name = postProcessJson[sk_PipelineStageName];
        String shaderName = postProcessJson[sk_PipelineStageShader][sk_ShaderProgramName];
        WeakPtr<ShaderProgram> shader = GetShader(shaderName);

        if (shader.expired()) {
            harmony::log::warn(
                    "Renderer : Could not deserialize Post Process Stage : {} : Could not find shader with name : {}",
                    name, shaderName);
            continue;
        }

        PipelineStage::Type type = postProcessJson[sk_PipelineStageType];
        Vector<AttachmentType> attachments{AttachmentType::RGBA8};
        RefCntPtr<PostProcessStage> stage = CreateRef<PostProcessStage>(
                name,
                type,
                shader,
                WeakPtr<PipelineStageRenderer>(),
                attachments
        );
    }

}

void harmony::Renderer::DeserializePipelineStageRenderers(Json &json, AssetManager &am) {
    OPTICK_EVENT();
    harmony::log::info("TODO : Deserialize pipeline stage renderers.");
}

void harmony::Renderer::DeserializeShaderDataSources(Json &json, AssetManager &am) {
    OPTICK_EVENT();
}

void harmony::Renderer::DeserializeViews(Json &json, AssetManager &am) {
    OPTICK_EVENT();
    auto viewsJson = json[sk_RendererName][sk_RendererViewCollection];
    harmony::log::info("Renderer : Deserializing Views");

    for (auto viewJson: viewsJson) {
        auto viewDataJson = viewJson[sk_ViewData];
        auto pipelineStackJson = viewJson[sk_PipelineStack];
        String viewName = viewDataJson[sk_ViewName];
        for (auto &[view, stack]: p_Views) {
            if (view->m_Name == viewName) {
                view->Deserialize(viewDataJson);
                int stackIndex = 0;
                for (auto pipelineHandleJson: pipelineStackJson[sk_PipelineStackPipelines]) {
                    PipelineHandle handle = pipelineHandleJson;
                    stackIndex++;
                }
                for (auto postProcess: pipelineStackJson[sk_PipelineStackPostProcessStages]) {
                    String name = postProcess[sk_PipelineStageName];
                }
                stackIndex = 0;
            }
        }
    }
}

void harmony::Renderer::DeserializeActiveViews(Json &json, AssetManager &am) {
    OPTICK_EVENT();
    harmony::log::info("Renderer : Deserializing Active Views");
}
