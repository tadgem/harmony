#include "Rendering/Renderer.h"
#include "Core/Profile.hpp"
#include "bgfx/platform.h"
#include "ECS/ModelComponent.h"
#include "ECS/MeshComponent.h"
#include "ECS/MaterialComponent.h"
#include "Core/Log.hpp"
#include "Core/Time.h"
#include "Core/SerializationKeys.h"
#include "Rendering/BuiltinShaders.h"
#include "Rendering/Shapes.h"
#include "Rendering/View.h"
#include "Rendering/PipelineStageRenderer.h"
#include "Rendering/ShaderDataSource.h"
#if HARMONY_DEBUG
#include <algorithm>
#include "ImGui/imgui_bgfx.h"
#include "ImGui/imgui.h"
#include "ImGui/icons_font_awesome.h"
#endif

harmony::Renderer::Renderer(AssetManager& assetManager) : p_AssetManager(assetManager)
{
    HARMONY_PROFILE_FUNCTION()
#if HARMONY_DEBUG
    p_CreatePipelineWindow = false;
    p_CreateShaderProgramWindow = false;
    p_SelectedPipelineType = 0;
#endif
}

harmony::WeakRef<harmony::ShaderProgram>  harmony::Renderer::AddBuiltInShader(const std::string& progName, const std::string& vsName, const std::string& fsName, uint32_t vsIndex, uint32_t fsIndex)
{
    Ref<ShaderProgram> prog = CreateRef<ShaderProgram>(progName);
    Ref<BuiltInShaderStage> vs = CreateRef<BuiltInShaderStage>(vsName, ShaderStage::Type::Vertex, s_BuiltInShader[vsIndex]);
    vs->LoadShaderBinary();
    Ref<BuiltInShaderStage> fs = CreateRef<BuiltInShaderStage>(fsName, ShaderStage::Type::Fragment, s_BuiltInShader[fsIndex]);
    fs->LoadShaderBinary();
    prog->AddStage(ShaderStage::Type::Vertex, vs);
    prog->AddStage(ShaderStage::Type::Fragment, fs);

    prog->Build();

    p_Shaders.emplace_back(prog);
    p_BuiltInShaders.emplace_back(prog);

    return prog;
}

harmony::WeakRef<harmony::ShaderProgram> harmony::Renderer::AddBuiltInShader(const std::string& progName, const std::string& csName, uint32_t csIndex)
{
    Ref<ShaderProgram> prog = CreateRef<ShaderProgram>(progName);
    Ref<BuiltInShaderStage> cs = CreateRef<BuiltInShaderStage>(csName, ShaderStage::Type::Compute, s_BuiltInShader[csIndex]);
    cs->LoadShaderBinary();
    prog->AddStage(ShaderStage::Type::Compute, cs);

    prog->Build();

    ShaderDataContainer dataContainer = ShaderDataContainer(prog);
    p_Shaders.emplace_back(prog);
    p_BuiltInShaders.emplace_back(prog);

    return prog;
}

void harmony::Renderer::AddBuiltInShaders()
{
    p_PresentProgram = AddBuiltInShader("Present", "vs_present", "fs_present", 4, 5);
    AddBuiltInShader("TexturedMesh", "vs_simple_textured", "fs_simple_textured", 0, 1);
    AddBuiltInShader("Normal", "vs_normal", "fs_normal", 2, 3);
    AddBuiltInShader("NanoVG", "vs_nanovg_fill", "fs_nanovg_fill", 6, 7);
}

harmony::WeakRef<harmony::ShaderProgram> harmony::Renderer::BuildShader(const std::string name, WeakRef<ShaderStage> vertStage, WeakRef<ShaderStage> fragStage)
{
    Ref<ShaderProgram> prog = CreateRef<ShaderProgram>(name);
    Ref<ShaderStage> vs = vertStage.lock();
    Ref<ShaderStage> fs = fragStage.lock();
    vs->LoadShaderBinary();
    fs->LoadShaderBinary();
    prog->AddStage(ShaderStage::Type::Vertex, vs);
    prog->AddStage(ShaderStage::Type::Fragment, fs);

    prog->Build();

    ShaderDataContainer dataContainer = ShaderDataContainer(prog);
    p_Shaders.emplace_back(prog);

    return GetWeakRef<ShaderProgram>(prog);
}

harmony::WeakRef<harmony::ShaderProgram> harmony::Renderer::BuildShader(const std::string name, WeakRef<ShaderStage> computeStage)
{
    Ref<ShaderProgram> prog = CreateRef<ShaderProgram>(name);
    Ref<ShaderStage> cs = computeStage.lock();
    
    cs->LoadShaderBinary();
    
    prog->AddStage(ShaderStage::Type::Compute, cs);
    
    prog->Build();

    ShaderDataContainer dataContainer = ShaderDataContainer(prog);
    p_Shaders.emplace_back(prog);

    return GetWeakRef<ShaderProgram>(prog);
}

uint32_t harmony::Renderer::p_ViewHandleCounter = 1;

void harmony::Renderer::RemoveView(WeakRef<View> view)
{
    if (view.expired())
    {
        harmony::log::error("Removing expired view weak ref!");
        return;
    }
    {
        Ref<View> _view = view.lock();
        p_Views.erase(_view);
    }
}

void harmony::Renderer::SetViewActive(WeakRef<View> viewWeakRef, bool active)
{
    if (viewWeakRef.expired())
    {
        harmony::log::warn("Passed Weak Ref to view which is not managed by view manager!");
        return;
    }

    auto view = viewWeakRef.lock();

    int indexToRemove = -1;

    for (int i = 0; i < m_ActiveViews.size(); i++)
    {
        if (m_ActiveViews[i].lock() == view)
        {
            if (active)
            {
                harmony::log::info("View already active!");
                return;
            }
            else
            {
                indexToRemove = i;
            }
        }
    }

    if (indexToRemove >= 0)
    {
        m_ActiveViews.erase(m_ActiveViews.begin() + indexToRemove);
    }
    else
    {
        m_ActiveViews.emplace_back(viewWeakRef);
    }

}

void harmony::Renderer::Init()
{
    PosColorTexCoord0Vertex::init();
    AddBuiltInShaders();
}

void harmony::Renderer::OnPreUpdate(entt::registry& registry)
{
    for (int i = 0; i < m_ActiveViews.size(); i++)
    {
        if (m_ActiveViews[i].expired())
        {
            harmony::log::warn("View {} is expired.", i);
            continue;
        }

        Ref<View> view = m_ActiveViews[i].lock();
        PipelineStack& stack = p_Views[view];

        if (view->p_Resized)
        {
            stack.OnViewResized(view);
            view->p_Resized = false;
        }

        view->OnPreUpdate(registry);
        stack.PreUpdate(registry, m_ActiveViews[i]);
    }
}

void harmony::Renderer::OnPostUpdate(entt::registry& registry)
{
    for (int i = 0; i < m_ActiveViews.size(); i++)
    {
        if (m_ActiveViews[i].expired())
        {
            harmony::log::warn("View {} is expired.", i);
            continue;
        }

        Ref<View> view = m_ActiveViews[i].lock();
        view->OnPostUpdate(registry);
        
        PipelineStack& stack = p_Views[view];
        auto texturesToBlit = stack.PostUpdate(registry, m_ActiveViews[i]);
        Ref<ShaderProgram> prog = p_PresentProgram.lock();
        bgfx::setViewClear(stack.m_FinalImageViewId, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x00000000);

        for (int i = 0; i < texturesToBlit.size(); i++)
        {
            bgfx::TextureHandle th = texturesToBlit[i];
            bgfx::setTexture(0, prog->m_Uniforms[0].BgfxHandle, th);
            // do this better
            ScreenSpaceQuad(view->m_Width, view->m_Height);
            bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A | BGFX_STATE_BLEND_NORMAL);
            bgfx::submit(stack.m_FinalImageViewId, prog->m_Handle);
        }
    }
}

harmony::PipelineStack& harmony::Renderer::GetViewPipelineStack(const std::string& viewName)
{
    for (auto& [view , stack]: p_Views)
    {
        if (view->m_Name == viewName)
        {
            return stack;
        }
    }
    harmony::log::error("No pipeline stack with name : {}", viewName);
    // TODO: This is horrible, fix me
    auto emptyStack = PipelineStack();
    return emptyStack;
}

void harmony::Renderer::AddViewPipeline(WeakRef<View> viewWeakRef, WeakRef<Pipeline> pipeline)
{
    if (viewWeakRef.expired())
    {
        harmony::log::error("Trying to add pipeline association to a view which is expired.");
        return;
    }

    Ref<View> view = viewWeakRef.lock();

    if (pipeline.expired())
    {
        harmony::log::error("Trying to add pipeline to stack but pipeline is expired");
        return;
    }

    Ref<Pipeline> p = pipeline.lock();
    
    p_Views[view].AddPipeline(pipeline, view);
}

void harmony::Renderer::RefreshViews()
{
    for (auto& [view, stack] :p_Views)
    {

    }
}

#if HARMONY_DEBUG
void harmony::Renderer::OnImGui()
{
    const std::string rendererTitle = std::string(ICON_FA_SLIDERS) + " Renderer";

    ImGui::SetNextWindowSizeConstraints(ImVec2(300, 300), ImVec2(300, 300));
    if (ImGui::Begin(rendererTitle.c_str()))
    {
        ImGui::Text("Frametime : %f, ", Time::GetFrameTime());
        ImGui::SameLine();
        ImGui::Text("FPS : %f", 1.0 / Time::GetFrameTime());
        ImGui::Separator();
        if (ImGui::TreeNode("[Shaders]"))
        {
            for (auto& shader : p_Shaders)
            {
                ImGui::Text(shader->m_Name.c_str());
            }
            ImGui::TreePop();
        }
        if (ImGui::Button("Create Shader"))
        {
            p_CreateShaderProgramWindow = true;
        }
        ImGui::Separator();
        if (ImGui::TreeNode("[Pipelines]"))
        {
            for (auto&  pipeline : p_Pipelines)
            {
                ImGui::Text(pipeline->m_Name.c_str());
            }
            ImGui::TreePop();
        }
        if (ImGui::Button("Create Pipeline"))
        {
            p_CreatePipelineWindow = true;
        }
        ImGui::Separator();
        if (ImGui::TreeNode("[Views]")) {
            int count = 0;
            for (auto& [view, stack] : p_Views)
            {
                auto addPipelineNameHash = "Add Pipeline##" + std::to_string(count);
                count++;

                if (ImGui::TreeNode(view->m_Name.c_str()))
                {
                    if (ImGui::BeginCombo(addPipelineNameHash.c_str(), ""))
                    {
                        for (int i = 0; i < p_Pipelines.size(); i++)
                        {
                            if (ImGui::Selectable(p_Pipelines[i]->m_Name.c_str(), false))
                            {
                                AddViewPipeline(view, p_Pipelines[i]);
                            }
                        }
                        ImGui::EndCombo();
                    }

                    if (ImGui::TreeNode("Stack"))
                    {
                        for (int i = 0; i < stack.m_Stack.size(); i++)
                        {
                            std::string indexString = std::to_string(i);
                            std::string upArrowText = std::string(ICON_FA_ARROW_UP) + "##" + indexString;
                            std::string downArrowText = std::string(ICON_FA_ARROW_DOWN) + "##" + indexString;
                            if (ImGui::Button(downArrowText.c_str()))
                            {
                                stack.MoveUp(stack.m_Stack[i].lock()->m_Handle);
                            }
                            ImGui::SameLine();
                            if (ImGui::Button(upArrowText.c_str()))
                            {
                                stack.MoveDown(stack.m_Stack[i].lock()->m_Handle);
                            }
                            ImGui::SameLine();
                            std::string pipelineName = stack.m_Stack[i].lock()->m_Name + " : " + indexString;
                            ImGui::Text(pipelineName.c_str());
                        }
                        ImGui::TreePop();
                    }
                    ImGui::Separator();
                    view->OnImGuiOptions();
                    ImGui::TreePop();
                }
            }
            ImGui::TreePop();
        }
    }
    ImGui::End();

    if (p_CreateShaderProgramWindow)
    {
        ImGui::SetNextWindowSize(ImVec2(320, 180));
        if (ImGui::Begin("New Shader"))
        {
            // Type
            // VS and FS Asset Selector 
            ImGui::Text("Surface Shader");

            p_AssetManager.AssetTypeSelector<ShaderStage>("Vert Stage", p_SelectedVertexAsset);
            p_AssetManager.AssetTypeSelector<ShaderStage>("Frag Stage", p_SelectedFragmentAsset);

            ImGui::InputText("Shader Name", p_ShaderNameInput, 64);
            
            if (ImGui::Button("Build"))
            {
                bool canBuild = true;
                WeakRef<ShaderStage> vStage = p_AssetManager.GetAsset<ShaderStage>(p_SelectedVertexAsset);
                WeakRef<ShaderStage> fStage = p_AssetManager.GetAsset<ShaderStage>(p_SelectedFragmentAsset);

                if (vStage.expired())
                {
                    harmony::log::error("Cannot build shader, invalid vertex stage provided");
                    canBuild = false;
                }

                if (fStage.expired())
                {
                    harmony::log::error("Cannot build shader, invalid vertex stage provided");
                    canBuild = false;
                }

                std::string shaderName = std::string(p_ShaderNameInput);
                Utils::TrimString(shaderName);

                if (shaderName.size() == 0)
                {
                    canBuild = false;
                }

                if (canBuild)
                {
                    BuildShader(shaderName, vStage, fStage);
                    p_CreateShaderProgramWindow = false;
                }


            }

            // or
            // CS Selector
        }
        ImGui::End();
    }

    if (p_CreatePipelineWindow)
    {
        ImGui::SetNextWindowSize(ImVec2(320, 180));
        if (ImGui::Begin("New Pipeline"))
        {
            static std::string pipelineTypes[] = { "Compute", "ScreenSpace", "Surface", "PostProcess" };
            ImGui::Text("Basic Surface Pipeline");
            ImGui::InputText("Pipeline Name", p_PipelineNameInput, 64);
            if (ImGui::BeginCombo("Pipeline Type", pipelineTypes[p_SelectedPipelineType].c_str()))
            {
                for (int i = 0; i < BX_COUNTOF(pipelineTypes); i++)
                {
                    if (ImGui::Selectable(pipelineTypes[i].c_str()))
                    {
                        p_SelectedPipelineType = i;
                    }
                }
                ImGui::EndCombo();
            }
            ShaderSelector("Choose Surface Shader", p_SelectedShaderProgram);

            if (ImGui::Button("Create Pipeline"))
            {
                bool canCreate = true;
                if (p_SelectedShaderProgram.expired())
                {
                    harmony::log::error("Cannot create pipeline : invalid shader selected.");
                    canCreate = false;
                }

                std::string pipelineName = std::string(p_PipelineNameInput);
                Utils::TrimString(pipelineName);

                if (pipelineName.size() == 0)
                {
                    canCreate = false;
                }

                if (canCreate)
                {
                    Ref<Pipeline> pipeline = CreateRef<Pipeline>(PipelineHandle( pipelineName ), Pipeline::Type::Surface);
                    pipeline->AddPipelineStage<PipelineStage>(pipelineName + ".surface", PipelineStage::Type::PrimaryDraw, p_SelectedShaderProgram, GetPipelineStageRenderer("MeshRenderer"));
                    AddPipeline(pipeline);
                    p_CreatePipelineWindow = false;
                }

            }
        }
        ImGui::End();
    }

    for (auto& [view , stack]: p_Views)
    {
        view->OnImGui();
    }
}


bool harmony::Renderer::ShaderSelector(const std::string& selectorName, harmony::WeakRef<harmony::ShaderProgram>& prog)
{
    bool selectedAsset = false;
    std::vector<std::string> shaders = GetShaderNames();

    if (ImGui::BeginCombo(selectorName.c_str(), ""))
    {
        for (int i = 0; i < shaders.size(); i++)
        {
            if (ImGui::Selectable(shaders[i].c_str()))
            {
                prog = GetShader(shaders[i]);
                selectedAsset = true;
            }
        }
        ImGui::EndCombo();
    }

    return selectedAsset;

}

harmony::Pipeline::Type harmony::Renderer::GetPipelineTypeFromName(const std::string& type)
{
    if (type.find("Compute") < type.size())
    {
        return Pipeline::Type::Compute;
    }
    if (type.find("ScreenSpace") < type.size())
    {
        return Pipeline::Type::ScreenSpace;
    }
    if (type.find("Surface") < type.size())
    {
        return Pipeline::Type::Surface;
    }
    if (type.find("PostProcess") < type.size())
    {
        return Pipeline::Type::PostProcess;
    }

}
#endif
bool harmony::Renderer::IsBuiltInShaderName(const std::string& name)
{
    for (int i = 0; i < p_BuiltInShaders.size(); i++)
    {
        Ref<ShaderProgram> shader = p_BuiltInShaders[i].lock();

        if (!shader)
        {
            harmony::log::error("Renderer : Invalid built in shader. This should never happen");
            continue;
        }

        if (shader->m_Name == name)
        {
            return true;
        }
    }
    return false;
}

bgfx::ViewId harmony::Renderer::GetViewID()
{
    bgfx::ViewId v = p_ViewHandleCounter;
    p_ViewHandleCounter++;
    return v;
}

nlohmann::json harmony::Renderer::Serialize()
{
    auto json =  nlohmann::json();

    json[sk_RendererName] = nlohmann::json();
    json[sk_RendererName][sk_RendererShaderCollection] = SerializeShaders();
    json[sk_RendererName][sk_RendererPipelineCollection] = SerializePipelines();
    json[sk_RendererName][sk_RendererViewCollection] = SerializeViews();
    json[sk_RendererName][sk_RendererActiveViewCollection] = SerializeActiveViews();
    
    
    return json;
}

void harmony::Renderer::Deserialize(AssetManager& am, nlohmann::json& json)
{
    harmony::log::info("Renderer : Deserializing Project Renderer Data");

    DeserializeShaders(json, am);
    DeserializePipelines(json, am);
    DeserializeViews(json, am);
    DeserializeActiveViews(json, am);
}

void harmony::Renderer::AddPipeline(Ref<Pipeline> pipeline)
{
    if (pipeline)
    {
        if (std::find(p_Pipelines.begin(), p_Pipelines.end(), pipeline) != p_Pipelines.end())
        {
            harmony::log::error("Already have a pipeline with name {} ", pipeline->m_Name);
            return;
        }
        p_Pipelines.emplace_back(pipeline);

    }
    else
    {
        harmony::log::error("Invalid pipeline provided.");
    }
}

harmony::WeakRef<harmony::Pipeline> harmony::Renderer::GetPipeline(const PipelineHandle& handle)
{
    
    for (int i = 0; i < p_Pipelines.size(); i++)
    {
        if (p_Pipelines[i]->m_Handle == handle)
        {
            return p_Pipelines[i];
        }
    }
    return WeakRef<Pipeline>();
}

void harmony::Renderer::AddPipelineStageRenderer(Ref<PipelineStageRenderer> renderer)
{
    auto it = std::find(p_PipelineStageRenderers.begin(), p_PipelineStageRenderers.end(), renderer);

    if (it == p_PipelineStageRenderers.end())
    {
        p_PipelineStageRenderers.push_back(renderer);
        return;
    }
}

harmony::WeakRef<harmony::PipelineStageRenderer> harmony::Renderer::GetPipelineStageRenderer(const std::string& name)
{
    for (int i = 0; i < p_PipelineStageRenderers.size(); i++)
    {
        if (p_PipelineStageRenderers[i]->m_Name == name)
        {
            return p_PipelineStageRenderers[i];
        }
    }
    return WeakRef<PipelineStageRenderer>();
}

void harmony::Renderer::ReloadShader(WeakRef<ShaderProgram> shader)
{
    if (shader.expired())
    {
        harmony::log::error("Trying to reload an invalid shader.");
        return;
    }

    Ref<ShaderProgram> prog = shader.lock();

    for (int i = 0; i < p_BuiltInShaders.size(); i++)
    {
        if (p_BuiltInShaders[i].expired())
        {
            continue;
        }

        auto b = p_BuiltInShaders[i].lock();
        if (prog == b)
        {
            harmony::log::warn("Cannot reload a built in shader");
            return;
        }
    }

    prog->Destroy();
    for (auto& [type, stageWr] : prog->m_Stages)
    {
        if (stageWr.expired())
        {
            harmony::log::error("Trying to reload an invalid shader.");
            return;
        }

        Ref<ShaderStage> stage = stageWr.lock();
        stage->LoadShaderBinary();
    }

    prog->Build();
    
}

void harmony::Renderer::ReloadAllShaders()
{
    for (auto shader : p_Shaders)
    {
        ReloadShader(shader);
    }
}

bool harmony::Renderer::IsShaderLoaded(const std::string& name)
{
    for (auto& shader : p_Shaders)
    {
        if (shader->m_Name == name)
        {
            return true;
        }
    }
    return false;
}

harmony::WeakRef<harmony::ShaderProgram> harmony::Renderer::GetShader(const std::string& name)
{
    for (auto& shader : p_Shaders)
    {
        if (shader->m_Name == name)
        {
            return GetWeakRef<ShaderProgram>(shader);
        }
    }
    return WeakRef<ShaderProgram>();
}

std::vector<std::string> harmony::Renderer::GetShaderNames()
{
    std::vector<std::string> shaders = std::vector<std::string>();
    for (auto& shader : p_Shaders)
    {
        shaders.push_back(shader->m_Name);
    }
    return shaders;
}

void harmony::Renderer::RefreshShaderDataContainers()
{
}

void harmony::Renderer::AddShaderDataSource(Ref<ShaderDataSource> dataSource)
{
    if (std::find(p_ShaderDataSources.begin(), p_ShaderDataSources.end(), dataSource) != p_ShaderDataSources.end())
    {
        harmony::log::warn("Renderer : Trying to add a shader data source that the renderer has already been provided.");
        return;
    }
    p_ShaderDataSources.emplace_back(dataSource);
}

harmony::WeakRef<harmony::ShaderDataSource> harmony::Renderer::GetShaderDataSource(const std::string& name)
{
    for (int i = 0; i < p_ShaderDataSources.size(); i++)
    {
        if (p_ShaderDataSources[i]->m_Name == name)
        {
            return p_ShaderDataSources[i];
        }
    }
    return WeakRef<ShaderDataSource>();
}

harmony::BGFXMeshHandle harmony::Renderer::SubmitMeshToGPU(WeakRef<Mesh> mesh)
{
    HARMONY_PROFILE_FUNCTION()
    auto meshRef = mesh.lock();
    BGFXMeshHandle m = BGFXMeshHandle();
    m.m_Layout = BuildVertexLayout(mesh);
    meshRef->BuildBGFXData();
    uint32_t indexBufferSize = static_cast<uint32_t>(meshRef->m_Indices.size() * sizeof(unsigned int));
    uint32_t vertexBufferSize = static_cast<uint32_t>(meshRef->m_BGFXData.size() * sizeof(float));
    m.m_VBH = bgfx::createVertexBuffer(bgfx::makeRef(meshRef->m_BGFXData.data(), vertexBufferSize), m.m_Layout);
    m.m_IBH = bgfx::createIndexBuffer(bgfx::makeRef(meshRef->m_Indices.data(), indexBufferSize), BGFX_BUFFER_INDEX32);
    meshRef->m_SubmittedToGpu = true;
    meshRef->m_Handle = m;
    return m;
}

harmony::BGFXTextureHandle harmony::Renderer::SubmitTextureToGPU(WeakRef<Texture> textureWeakRef)
{
    uint64_t flags = 0;

    BGFXTextureHandle handle;

    Ref<Texture> texture = textureWeakRef.lock();
    handle.Handle = texture->m_Handle;
    bimg::ImageContainer* imageContainer = texture->p_ImageContainer;

    if (imageContainer->m_cubeMap)
    {
        handle.BgfxHandle = bgfx::createTextureCube(
            uint16_t(imageContainer->m_width)
            , 1 < imageContainer->m_numMips
            , imageContainer->m_numLayers
            , bgfx::TextureFormat::Enum(imageContainer->m_format)
            , flags
            , texture->p_Memory
        );
    }
    else if (1 < imageContainer->m_depth)
    {
        handle.BgfxHandle = bgfx::createTexture3D(
            uint16_t(imageContainer->m_width)
            , uint16_t(imageContainer->m_height)
            , uint16_t(imageContainer->m_depth)
            , 1 < imageContainer->m_numMips
            , bgfx::TextureFormat::Enum(imageContainer->m_format)
            , flags
            , texture->p_Memory
        );
    }
    else if (bgfx::isTextureValid(0, false, imageContainer->m_numLayers, bgfx::TextureFormat::Enum(imageContainer->m_format), flags))
    {
        handle.BgfxHandle = bgfx::createTexture2D(
            uint16_t(imageContainer->m_width)
            , uint16_t(imageContainer->m_height)
            , 1 < imageContainer->m_numMips
            , imageContainer->m_numLayers
            , bgfx::TextureFormat::Enum(imageContainer->m_format)
            , flags
            , texture->p_Memory
        );
    }

    if (bgfx::isValid(handle.BgfxHandle))
    {
        bgfx::setName(handle.BgfxHandle, texture->m_Handle.Path.c_str());
    }

    if (&handle.Info != NULL)
    {
        bgfx::calcTextureSize(
            handle.Info
            , uint16_t(imageContainer->m_width)
            , uint16_t(imageContainer->m_height)
            , uint16_t(imageContainer->m_depth)
            , imageContainer->m_cubeMap
            , 1 < imageContainer->m_numMips
            , imageContainer->m_numLayers
            , bgfx::TextureFormat::Enum(imageContainer->m_format)
        );
    }

    texture->m_TextureHandle = handle;
    texture->m_SubmittedToGPU = true;
    return handle;
}

bgfx::VertexLayout harmony::Renderer::BuildVertexLayout(WeakRef<Mesh> meshWeakRef)
{
    HARMONY_PROFILE_FUNCTION()
    auto mesh = meshWeakRef.lock();
    bgfx::VertexLayout vl = bgfx::VertexLayout();
    vl.begin();

    // do we need to support 2 component positions? 
    vl.add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float);

    if (mesh->m_HasNormals)
    {
        vl.add(bgfx::Attrib::Normal, 3, bgfx::AttribType::Float);
    }

    if (mesh->m_HasUVs)
    {
        vl.add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float);
    }

    if (mesh->m_HasTangents)
    {
       vl.add(bgfx::Attrib::Tangent, 3, bgfx::AttribType::Float);
    }

    if (mesh->m_HasBitangents)
    {
       vl.add(bgfx::Attrib::Bitangent, 3, bgfx::AttribType::Float);
    }

    // TODO add support for skeletal meshes.
    vl.end();
    return vl;

}

nlohmann::json harmony::Renderer::SerializeShaders()
{
    auto json = nlohmann::json::array();
    for (auto& shader : p_Shaders)
    {
        nlohmann::json shaderJson;
        shaderJson[sk_ShaderProgram] = *shader;

        json.emplace_back(shaderJson);
    }
    return json;
}

nlohmann::json harmony::Renderer::SerializePipelines()
{
    auto json = nlohmann::json::array();
    for (auto& pipeline : p_Pipelines)
    {
        json.emplace_back(pipeline->Serialize());
    }
    
    return json;
}

nlohmann::json harmony::Renderer::SerializeViews()
{
    auto json = nlohmann::json::array();
    for (auto& [view, stack] : p_Views)
    {
        nlohmann::json viewJson;
        viewJson[sk_ViewData] = view->Serialize();
        viewJson[sk_PipelineStack] = stack.Serialize();
        json.emplace_back(viewJson);

    }

    return json;
}

nlohmann::json harmony::Renderer::SerializeActiveViews()
{
    auto json = nlohmann::json::array();
    for (WeakRef<View> viewWr : m_ActiveViews)
    {
        if (viewWr.expired())
        {
            continue;
        }

        Ref<View> view = viewWr.lock();
        json.emplace_back(view->Serialize());
    }
    return json;
}

void harmony::Renderer::DeserializeShaders(nlohmann::json& json, AssetManager& am)
{
    harmony::log::info("Renderer : Deserializing Shaders");
    for (auto shaderJson : json[sk_RendererName][sk_RendererShaderCollection])
    {
        auto dataJson = shaderJson[sk_ShaderDataContainer];
        auto programJson = shaderJson[sk_ShaderProgram];

        if (IsBuiltInShaderName(programJson[sk_ShaderProgramName]))
        {
            continue;
        }

        harmony::log::info("Renderer : Deserializing shader {}", programJson[sk_ShaderProgramName]);

        std::string shaderName = programJson[sk_ShaderProgramName];
        if (IsShaderLoaded(shaderName))
        {
            continue;
        }

        std::map<ShaderStage::Type, Ref<ShaderStage>> stages = std::map<ShaderStage::Type, Ref<ShaderStage>>();

        for (auto stageJson : programJson[sk_ShaderProgramStages])
        {            
            const int StageTypeIndex = 0;
            const int StageDataIndex = 1;
            
            auto stageDataJson = stageJson[StageDataIndex];

            AssetHandle assetHandle = stageDataJson[sk_AssetHandle];
            std::string stageName = stageDataJson[sk_ShaderStageName];
            ShaderStage::Type stageType = stageDataJson[sk_ShaderStageType];

            if (am.IsPathLoaded(assetHandle.Path))
            {
                auto stage = am.GetAsset<ShaderStage>(assetHandle);
                if (stage.expired())
                {
                    harmony::log::warn("Renderer : Shader Stage {} is supposedly loaded but cannot be found.", assetHandle.Path);
                }
                else
                {
                    stages.emplace(stageType, stage.lock());
                }
            }
            else
            {
                auto handles = am.LoadAsset<ShaderStage>(assetHandle.Path);
                auto stage = am.GetAsset<ShaderStage>(handles[0]);

                if (stage.expired())
                {
                    harmony::log::warn("Renderer : Shader Stage {} could not be loaded.", assetHandle.Path);
                }
                else
                {
                    stages.emplace(stageType, stage);
                }
            }
        }

        if (stages.find(ShaderStage::Type::Compute) != stages.end())
        {
            harmony::log::info("Renderer : Loading compute shader {}", shaderName);
            BuildShader(shaderName, stages[ShaderStage::Type::Compute]);
        }

        if (stages.find(ShaderStage::Type::Vertex) != stages.end() && stages.find(ShaderStage::Type::Fragment) != stages.end())
        {
            harmony::log::info("Renderer : Loading surface shader {}", shaderName);
            BuildShader(shaderName, stages[ShaderStage::Type::Vertex], stages[ShaderStage::Type::Fragment]);
        }

    }
}

void harmony::Renderer::DeserializePipelines(nlohmann::json& json, AssetManager& am)
{
    harmony::log::info("Renderer : Deserializing Pipelines");
    for (auto pipelineJson : json[sk_RendererName][sk_RendererPipelineCollection])
    {
        auto stagesJson = pipelineJson[sk_PipelineObject][sk_PipelineStages];
        std::string pipelineName = pipelineJson[sk_PipelineObject][sk_PipelineName];
        PipelineHandle pipelineHandle{ pipelineName };
        Pipeline::Type pipelineType = pipelineJson[sk_PipelineObject][sk_PipelineType];
        bool pipelineLoaded = false;

        for (int i = 0; i < p_Pipelines.size(); i++)
        {
            if (p_Pipelines[i]->m_Handle == pipelineHandle)
            {
                pipelineLoaded = true;
                break;
            }
        }

        if (pipelineLoaded)
        {
            continue;
        }

        Ref<Pipeline> newPipeline = CreateRef<Pipeline>(pipelineHandle, pipelineType);
        
        harmony::log::info("Renderer : Creating serialized pipeline : {}", newPipeline->m_Name);

        bool pipelineCreationSuccessful = true;

        for (auto stageJson : stagesJson)
        {
            auto dump = stageJson.dump();
            harmony::log::debug("Renderer : Stage Json {}", dump);
            std::string stageName = stageJson[sk_PipelineStageName];
            
            Attachment::Type stageAttachments = stageJson[sk_PipelineStageAttachments];
            PipelineStage::Type stageType = stageJson[sk_PipelineStageType];
            ShaderDataContainer stageData = stageJson[sk_PipelineStageData];

            std::string stageShaderName = stageJson[sk_PipelineStageShader][sk_ShaderProgramName];
            WeakRef<ShaderProgram> stageShader = GetShader(stageShaderName);

            if (stageShader.expired())
            {
                harmony::log::warn("Renderer : Cannot deserialize pipeline stage {}, stage shader is not loaded! : {}", stageName, stageShaderName);
                pipelineCreationSuccessful = false;
                break;
            }

            stageData.UpdateShader(stageShader, am);

            Ref<PipelineStage> pipelineStage = newPipeline->AddPipelineStage<PipelineStage>(stageName, stageType, stageShader, GetPipelineStageRenderer("MeshRenderer"), stageAttachments).lock();
            pipelineStage->p_PipelineStageData = stageData;
        }

        if (pipelineCreationSuccessful)
        {
            p_Pipelines.emplace_back(newPipeline);
        }
        else
        {
            harmony::log::error("Renderer : Failed to deserialize pipeline : {}", pipelineName);
        }


    }
}

void harmony::Renderer::DeserializeViews(nlohmann::json& json, AssetManager& am)
{
    auto viewsJson = json[sk_RendererName][sk_RendererViewCollection];
    harmony::log::info("Renderer : Deserializing Views");

    for (auto viewJson : viewsJson)
    {
        auto viewDataJson = viewJson[sk_ViewData];
        auto pipelineStackJson = viewJson[sk_PipelineStack];

        std::string viewName = viewDataJson[sk_ViewName];
        for (auto& [view, stack] : p_Views)
        {
            if (view->m_Name == viewName)
            {
                view->Deserialize(viewDataJson);
                int stackIndex = 0;
                for (auto pipelineHandleJson : pipelineStackJson)
                {
                    PipelineHandle handle = pipelineHandleJson;
                    WeakRef<Pipeline> pipeline = GetPipeline(handle);

                    if (pipeline.expired())
                    {
                        harmony::log::warn("Renderer : Failed to add pipeline with handle {} to view {}, pipeline was not found!", handle.Name, viewName);
                        continue;
                    }

                    stack.AddPipelineAtIndex(pipeline, view, stackIndex);
                    stackIndex++;
                }                
            }
        }
    }
}

void harmony::Renderer::DeserializeActiveViews(nlohmann::json& json, AssetManager& am)
{
    harmony::log::info("Renderer : Deserializing Active Views");
}