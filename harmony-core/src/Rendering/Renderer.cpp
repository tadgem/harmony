#include <algorithm>
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
#include "Rendering/PostProcessStage.h"
#include "Rendering/PipelineDrawStage.h"

#if HARMONY_DEBUG
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
    p_CreatePostProcessStageWindow = false;
    p_CreateDrawStageWindow = false;
    p_SelectedPipelineType = 0;
    p_SelectedPipelineDrawStageType = 0;
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

    p_Shaders.emplace_back(prog);
    p_BuiltInShaders.emplace_back(prog);

    return prog;
}

void harmony::Renderer::AddBuiltInShaders()
{
    p_PresentProgram = AddBuiltInShader("Present", "vs_present", "fs_present", 4, 5);
    p_PresentProgramTextureHandle = p_PresentProgram.lock()->m_Uniforms[0].BgfxHandle;
    AddBuiltInShader("TexturedMesh", "vs_simple_textured", "fs_simple_textured", 0, 1);
    AddBuiltInShader("Normal", "vs_normal", "fs_normal", 2, 3);
    AddBuiltInShader("NanoVG", "vs_nanovg_fill", "fs_nanovg_fill", 6, 7);
    AddBuiltInShader("BlinnPhongTextured", "vs_blinn_phong_textured", "fs_blinn_phong_textured", 8, 9);
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

    p_Shaders.emplace_back(prog);

    return GetWeakRef<ShaderProgram>(prog);
}

uint32_t harmony::Renderer::p_ViewHandleCounter = 1;

harmony::WeakRef<harmony::View> harmony::Renderer::GetView(const std::string& name)
{
    for (auto& [view, stack] : p_Views)
    {
        if (view->m_Name == name)
        {
            return view;
        }
    }
    return WeakRef<View>();
}

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

        Ref<View> view          = m_ActiveViews[i].lock();
        Ref<ShaderProgram> prog = p_PresentProgram.lock();
        PipelineStack& stack    = p_Views[view];

        HandleStackPipelineAccumulation(view, stack, prog, registry);
        HandleStackPostProcess(view, stack, prog, registry);
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

void harmony::Renderer::AddViewPostProcessStage(WeakRef<View> viewWeakRef, WeakRef<PostProcessStage> stage)
{
    if (viewWeakRef.expired())
    {
        harmony::log::error("Trying to add pipeline association to a view which is expired.");
        return;
    }

    Ref<View> view = viewWeakRef.lock();

    if (stage.expired())
    {
        harmony::log::error("Trying to add pipeline to stack but pipeline is expired");
        return;
    }

    Ref<PostProcessStage> s = stage.lock();

    p_Views[view].AddPostProcessStage(s, view);
}

void harmony::Renderer::RefreshViews()
{
    for (auto& [view, stack] :p_Views)
    {
        stack.OnViewResized(view);
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
        if(ImGui::CollapsingHeader("[Shaders]", ImGuiTreeNodeFlags_SpanFullWidth | ImGuiTreeNodeFlags_Framed))
        {
            ImGui::Indent();
            for (auto& shader : p_Shaders)
            {
                ImGui::Text(shader->m_Name.c_str());
            }
            ImGui::Unindent();
            ImGui::Separator();
            if (ImGui::Button("Create Shader"))
            {
                p_CreateShaderProgramWindow = true;
            }
        }
        ImGui::Separator();
        if (ImGui::CollapsingHeader("[DrawStages]", ImGuiTreeNodeFlags_SpanFullWidth | ImGuiTreeNodeFlags_Framed))
        {
            ImGui::Indent();
            for (auto& stage : p_PipelineDrawStages)
            {
                ImGui::Text(stage->m_Name.c_str());
            }
            ImGui::Unindent();
            ImGui::Separator();
            if (ImGui::Button("Create Draw Stage"))
            {
                p_CreateDrawStageWindow = true;
            }
        }

        if (ImGui::CollapsingHeader("[PostProcessStages]", ImGuiTreeNodeFlags_SpanFullWidth | ImGuiTreeNodeFlags_Framed))
        {
            ImGui::Indent();
            for (auto& stage : p_PostProcessStages)
            {
                ImGui::Text(stage->m_Name.c_str());
            }
            ImGui::Unindent();
            ImGui::Separator();
            if (ImGui::Button("Create Post Process Stage"))
            {
                p_CreatePostProcessStageWindow = true;
            }
        }
        if (ImGui::CollapsingHeader("[Pipelines]"))
        {
            for (auto& pipeline : p_Pipelines)
            {
                ImGui::Text(pipeline->m_Name.c_str());
                ImGui::Indent();
                for (int i = 0; i < pipeline->NumPipelineStages(); i++)
                {
                    ImGui::Text(pipeline->p_Stages[i]->m_Name.c_str());
                }
                ImGui::Unindent();
            }
            if (ImGui::Button("Create Pipeline"))
            {
                p_CreatePipelineWindow = true;
            }
        }
        ImGui::Separator();
        if (ImGui::CollapsingHeader("[Views]")) {
            int count = 0;
            ImGui::Indent();
            for (auto& [view, stack] : p_Views)
            {
                if (ImGui::CollapsingHeader(view->m_Name.c_str()))
                {
                    auto addPipelineNameHash = "##combo" + std::to_string(count);
                    count++;
                    ImGui::Text("Add Pipeline");
                    ImGui::SameLine();
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

                    auto addPostProcessNameHash = "##combo" + std::to_string(count);
                    count++;
                    ImGui::Text("Add Post Process Stage");
                    ImGui::SameLine();
                    if (ImGui::BeginCombo(addPostProcessNameHash.c_str(), ""))
                    {
                        for (int i = 0; i < p_PostProcessStages.size(); i++)
                        {
                            if (ImGui::Selectable(p_PostProcessStages[i]->m_Name.c_str(), false))
                            {
                                AddViewPostProcessStage(view, p_PostProcessStages[i]);
                            }
                        }
                        ImGui::EndCombo();
                    }
                    ImGui::Indent();
                    if (ImGui::CollapsingHeader("Stack"))
                    {
                        ImGui::Text("Draw Pipelines");
                        ImGui::Indent();
                        int lastIndex = -1;
                        for (int i = 0; i < stack.m_PipelineStack.size(); i++)
                        {
                            std::string indexString = std::to_string(i);
                            std::string upArrowText = std::string(ICON_FA_ARROW_UP) + "##" + indexString;
                            std::string downArrowText = std::string(ICON_FA_ARROW_DOWN) + "##" + indexString;
                            if (ImGui::Button(downArrowText.c_str()))
                            {
                                stack.MovePipelineUp(stack.m_PipelineStack[i].lock()->m_Handle);
                            }
                            ImGui::SameLine();
                            if (ImGui::Button(upArrowText.c_str()))
                            {
                                stack.MovePipelineDown(stack.m_PipelineStack[i].lock()->m_Handle);
                            }
                            ImGui::SameLine();
                            std::string pipelineName = stack.m_PipelineStack[i].lock()->m_Name + " : " + indexString;
                            ImGui::Text(pipelineName.c_str());
                            lastIndex = i;
                        }
                        lastIndex += 1;
                        ImGui::Unindent();
                        ImGui::Text("Post Process Stages");
                        ImGui::Indent();
                        int indexToRemove = -1;
                        for (int i = 0; i < stack.m_PostProcessPipelineStack.size(); i++)
                        {
                            std::string indexString = std::to_string(lastIndex + i);
                            std::string upArrowText = std::string(ICON_FA_ARROW_UP) + "##" + indexString;
                            std::string downArrowText = std::string(ICON_FA_ARROW_DOWN) + "##" + indexString;
                            if (ImGui::Button(downArrowText.c_str()))
                            {
                                stack.MovePostProcessStageUp(stack.m_PostProcessPipelineStack[i].lock()->m_Name);
                            }
                            ImGui::SameLine();
                            if (ImGui::Button(upArrowText.c_str()))
                            {
                                stack.MovePostProcessStageDown(stack.m_PostProcessPipelineStack[i].lock()->m_Name);
                            }
                            ImGui::SameLine();
                            std::string pipelineName = stack.m_PostProcessPipelineStack[i].lock()->m_Name + " : " + std::to_string(i);
                            ImGui::Text(pipelineName.c_str());
                            std::string binText = std::string(ICON_FA_TRASH) + "##" + indexString;
                            ImGui::SameLine();
                            if (ImGui::Button(binText.c_str()))
                            {
                                indexToRemove = i;
                            }
                        }
                        if (indexToRemove >= 0)
                        {
                            stack.RemovePostProcessStage(stack.m_PostProcessPipelineStack[indexToRemove], view);
                        }
                        ImGui::Unindent();
                    }
                    ImGui::Separator();
                    
                    ImGui::Unindent();
                    view->OnImGuiOptions();
                }
            }
            ImGui::Unindent();
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
                    pipeline->AddPipelineStage<PipelineDrawStage>(pipelineName + ".surface", PipelineDrawStage::Type::PrimaryDraw, p_SelectedShaderProgram, GetPipelineStageRenderer("MeshRenderer"));
                    AddPipeline(pipeline);
                    p_CreatePipelineWindow = false;
                }

            }
        }
        ImGui::End();
    }

    if (p_CreateDrawStageWindow)
    {
        ImGui::SetNextWindowSize(ImVec2(320, 180));
        if (ImGui::Begin("New Draw Stage"))
        {
            ImGui::InputText("Name", &p_PipelineDrawStageNameInput[0], 64);
            PipelineStageRendererSelector("Stage Renderer", p_SelectedRenderer);
            ShaderSelector("Stage Shader", p_SelectedShaderProgram);
            if (ImGui::Button("Build"))
            {
                std::string name = std::string(p_PipelineDrawStageNameInput);
                Utils::TrimString(name);
                Ref<PipelineDrawStage> stage = CreateRef<PipelineDrawStage>(
                    name,
                    PipelineStage::Type::PrimaryDraw, // TODO: Make selectable
                    p_SelectedShaderProgram,
                    p_SelectedRenderer
                );
                AddPipelineDrawStage(stage);
                p_CreateDrawStageWindow = false;
            }
            ImGui::SameLine();
            if (ImGui::Button("Cancel"))
            {
                p_CreateDrawStageWindow = false;
            }
        }
        ImGui::End();
    }

    if (p_CreatePostProcessStageWindow)
    {
        ImGui::SetNextWindowSize(ImVec2(320, 180));
        if (ImGui::Begin("New Post Process Draw Stage"))
        {
            ImGui::InputText("Name", &p_PipelinePostProcessStageNameInput[0], 64);
            ShaderSelector("Stage Shader", p_SelectedShaderProgram);
            if (ImGui::Button("Build"))
            {
                std::string name = std::string(p_PipelinePostProcessStageNameInput);
                Utils::TrimString(name);
                Ref<PostProcessStage> stage = CreateRef<PostProcessStage>(
                    name,
                    PipelineStage::Type::PostProcess, // TODO: Make selectable
                    p_SelectedShaderProgram,
                    WeakRef<PipelineStageRenderer>()
                    );
                AddPostProcessStage(stage);
                p_CreatePostProcessStageWindow = false;
            }
            ImGui::SameLine();
            if (ImGui::Button("Cancel"))
            {
                p_CreatePostProcessStageWindow = false;
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

bool harmony::Renderer::PipelineStageRendererSelector(const std::string& selectorName, harmony::WeakRef<harmony::PipelineStageRenderer> renderer)
{
    bool selectedAsset = false;

    if (ImGui::BeginCombo(selectorName.c_str(), ""))
    {
        for (int i = 0; i < p_PipelineStageRenderers.size(); i++)
        {
            if (ImGui::Selectable(p_PipelineStageRenderers[i]->m_Name.c_str()))
            {
                renderer = p_PipelineStageRenderers[i];
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
    json[sk_RendererName][sk_RendererShaderCollection]              = SerializeShaders();
    json[sk_RendererName][sk_RendererPipelineCollection]            = SerializePipelines();
    json[sk_RendererName][sk_RendererDrawStageCollection]           = SerializePipelineDrawStages();
    json[sk_RendererName][sk_RendererPostProcessStageCollection]    = SerializePostProcessStages();
    json[sk_RendererName][sk_RendererStageRendererCollection]       = SerializePipelineStageRenderers();
    json[sk_RendererName][sk_RendererShaderDataSourceCollection]    = SerializeShaderDataSources();
    json[sk_RendererName][sk_RendererViewCollection]                = SerializeViews();
    json[sk_RendererName][sk_RendererActiveViewCollection]          = SerializeActiveViews();
    
    return json;
}

void harmony::Renderer::Deserialize(AssetManager& am, nlohmann::json& json)
{
    harmony::log::info("Renderer : Deserializing Project Renderer Data");

    DeserializeShaders(json, am);
    DeserializePipelines(json, am);
    DeserializePipelineDrawStages(json, am);
    DeserializePostProcessStages(json, am);
    DeserializePipelineStageRenderers(json, am);
    DeserializeShaderDataSources(json, am);
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

void harmony::Renderer::AddPipelineDrawStage(Ref<PipelineDrawStage> drawStage)
{
    if (std::find(p_PipelineDrawStages.begin(), p_PipelineDrawStages.end(), drawStage) != p_PipelineDrawStages.end())
    {
        harmony::log::warn("Renderer : AddPipelineDrawStage : Draw Stage {} instance already managed by renderer", drawStage->m_Name);
        return;
    }

    p_PipelineDrawStages.emplace_back(drawStage);
}

harmony::WeakRef<harmony::PipelineDrawStage> harmony::Renderer::GetPipelineDrawStage(const std::string& name)
{
    for (int i = 0; i < p_PipelineDrawStages.size(); i++)
    {
        if (p_PipelineDrawStages[i]->m_Name == name)
        {
            return p_PipelineDrawStages[i];
        }
    }

    return WeakRef<PipelineDrawStage>();
}

void harmony::Renderer::AddPostProcessStage(Ref<PostProcessStage> postProcessStage)
{
    if (std::find(p_PostProcessStages.begin(), p_PostProcessStages.end(), postProcessStage) != p_PostProcessStages.end())
    {
        harmony::log::warn("Renderer : AddPostProcessStage : Post Process Stage {} instance already managed by renderer", postProcessStage->m_Name);
        return;
    }

    p_PostProcessStages.emplace_back(postProcessStage);
}

harmony::WeakRef<harmony::PostProcessStage> harmony::Renderer::GetPostProcessStage(const std::string& name)
{
    for (int i = 0; i < p_PostProcessStages.size(); i++)
    {
        if (p_PostProcessStages[i]->m_Name == name)
        {
            return p_PostProcessStages[i];
        }
    }

    return WeakRef<PostProcessStage>();
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

nlohmann::json harmony::Renderer::SerializePipelineDrawStages()
{
    auto json = nlohmann::json::array();
    for (auto& drawStage : p_PipelineDrawStages)
    {
        json.emplace_back(drawStage->Serialize());
    }

    return json;
}

nlohmann::json harmony::Renderer::SerializePostProcessStages()
{
    auto json = nlohmann::json::array();
    for (auto& ppStage : p_PostProcessStages)
    {
        json.emplace_back(ppStage->Serialize());
    }

    return json;
}

nlohmann::json harmony::Renderer::SerializePipelineStageRenderers()
{
    auto json = nlohmann::json::array();
    for (auto& renderer : p_PipelineStageRenderers)
    {
        json.emplace_back(renderer);
    }

    return json;
}

nlohmann::json harmony::Renderer::SerializeShaderDataSources()
{
    auto json = nlohmann::json::array();
    for (auto& source : p_ShaderDataSources)
    {
        json.emplace_back(source);
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
            PipelineDrawStage::Type stageType = stageJson[sk_PipelineStageType];

            std::string stageShaderName = stageJson[sk_PipelineStageShader][sk_ShaderProgramName];
            WeakRef<ShaderProgram> stageShader = GetShader(stageShaderName);

            if (stageShader.expired())
            {
                harmony::log::warn("Renderer : Cannot deserialize pipeline stage {}, stage shader is not loaded! : {}", stageName, stageShaderName);
                pipelineCreationSuccessful = false;
                break;
            }
            // TODO : Change me to use the serialized pipeline stage renderer.
            Ref<PipelineDrawStage> pipelineStage = newPipeline->AddPipelineStage<PipelineDrawStage>(stageName, stageType, stageShader, GetPipelineStageRenderer("MeshRenderer"), stageAttachments).lock();
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

void harmony::Renderer::DeserializePipelineDrawStages(nlohmann::json& json, AssetManager& am)
{
    harmony::log::info("TODO : Deserialize pipeline draw stages.");
}

void harmony::Renderer::DeserializePostProcessStages(nlohmann::json& json, AssetManager& am)
{
    harmony::log::info("Renderer : Deserializing Post Process Stages");
    for (auto postProcessJson : json[sk_RendererName][sk_RendererPostProcessStageCollection])
    {
        std::string name = postProcessJson[sk_PipelineStageName];
        std::string shaderName = postProcessJson[sk_PipelineStageShader][sk_ShaderProgramName];
        
        WeakRef<ShaderProgram> shader = GetShader(shaderName);

        if (shader.expired())
        {
            harmony::log::warn("Renderer : Could not deserialize Post Process Stage : {} : Could not find shader with name : {}", name, shaderName);
            continue;
        }

        PipelineStage::Type type = postProcessJson[sk_PipelineStageType];
        Attachment::Type attachments = postProcessJson[sk_PipelineStageAttachments];

        Ref<PostProcessStage> stage = CreateRef<PostProcessStage>(
            name, 
            type,
            shader,
            WeakRef<PipelineStageRenderer>(),
            attachments
        );

        AddPostProcessStage(stage);
    }

}

void harmony::Renderer::DeserializePipelineStageRenderers(nlohmann::json& json, AssetManager& am)
{
    harmony::log::info("TODO : Deserialize pipeline stage renderers.");
}

void harmony::Renderer::DeserializeShaderDataSources(nlohmann::json& json, AssetManager& am)
{
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
                for (auto pipelineHandleJson : pipelineStackJson[sk_PipelineStackPipelines])
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
                for (auto postProcess : pipelineStackJson[sk_PipelineStackPostProcessStages])
                {
                    std::string name = postProcess[sk_PipelineStageName];
                    WeakRef<PostProcessStage> pipeline = GetPostProcessStage(name);

                    if (pipeline.expired())
                    {
                        harmony::log::warn("Renderer : Failed to add post process stage with name {} to view {}, pipeline was not found!", name, viewName);
                        continue;
                    }

                    stack.AddPostProcessStageAtIndex(pipeline, view, stackIndex);
                    stackIndex++;
                }
                stackIndex = 0;
            }
        }
    }
}

void harmony::Renderer::DeserializeActiveViews(nlohmann::json& json, AssetManager& am)
{
    harmony::log::info("Renderer : Deserializing Active Views");
}

void harmony::Renderer::HandleStackPipelineAccumulation(Ref<View> view, PipelineStack& stack, Ref<ShaderProgram> textureProg, entt::registry& registry)
{
    view->OnPostUpdate(registry);
    auto texturesToBlit = stack.PostUpdate(registry, view);

    bgfx::setViewClear(stack.m_PipelineStackAccumulationView, BGFX_CLEAR_COLOR, 0x00000000);

    bool touchNoPostProcess = true;
    auto noPostProcess = std::vector<bgfx::TextureHandle>();
    for(auto& [th, postProcess] : texturesToBlit)
    {
        bgfx::TextureHandle h{ th };
        // do this better
        if (postProcess)
        {
            bgfx::setTexture(0, textureProg->m_Uniforms[0].BgfxHandle, h);
            ScreenSpaceQuad(view->m_Width, view->m_Height);
            bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A | BGFX_STATE_BLEND_NORMAL);
            bgfx::submit(stack.m_PipelineStackAccumulationView, textureProg->m_Handle);
        }
        else
        {
            noPostProcess.emplace_back(h);
            touchNoPostProcess = false;
        }
    }

    bgfx::setViewClear(stack.m_PipelineStackNoPostProcessView, BGFX_CLEAR_COLOR, 0x00000000);
    if (touchNoPostProcess)
    {
        bgfx::touch(stack.m_PipelineStackNoPostProcessView);
    }
    else
    {
        for (auto th : noPostProcess)
        {
            bgfx::setTexture(0, textureProg->m_Uniforms[0].BgfxHandle, th);
            ScreenSpaceQuad(view->m_Width, view->m_Height);
            bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A | BGFX_STATE_BLEND_NORMAL);

            bgfx::submit(stack.m_PipelineStackNoPostProcessView, textureProg->m_Handle);
        }
    }
}

void harmony::Renderer::HandleStackPostProcess(Ref<View> view, PipelineStack& stack, Ref<ShaderProgram> textureProg, entt::registry& registry)
{
    PipelineStage::Data data;

    // Initialize with final result from draw pipelines.
    data.m_FramebufferHandle = stack.m_PipelineStackAccumulationFB;

    Attachment colourAttachment{ stack.m_PipelineStackAccumulationAttachment, stack.s_AccumulationBufferFormat };
    Attachment depthAttachment{ stack.GetFinalDepth(),  Attachment::Depth16F };

    data.m_Attachments.emplace(colourAttachment.m_Type, colourAttachment);
    data.m_Attachments.emplace(depthAttachment.m_Type, depthAttachment);

    for (int i = 0; i < stack.m_PostProcessPipelineStack.size(); i++)
    {
        WeakRef<PostProcessStage> stage = stack.m_PostProcessPipelineStack[i];
        if (stage.expired())
        {
            harmony::log::warn("Renderer : HandleStackPostProcess : View : {} : Invalid stage in post process", view->m_Name);
            continue;
        }

        Ref<PostProcessStage> s = stage.lock();

        s->PostUpdate(registry, view, stack.p_StackViewIDs[s->m_Name][0], data);

        data = stack.p_StackData[s->m_Name][0];
        data.m_Attachments[Attachment::Depth16F] = depthAttachment;
    }

    // post processing image drawn first
    bgfx::setViewClear(stack.m_FinalImageViewId, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x00000000);
    bgfx::setTexture(0, textureProg->m_Uniforms[0].BgfxHandle, data.m_Attachments[data.GetColorType()].m_Handle);
    ScreenSpaceQuad(view->m_Width, view->m_Height);
    bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A | BGFX_STATE_BLEND_ADD);
    bgfx::submit(stack.m_FinalImageViewId, textureProg->m_Handle);

    // next pipelines with no post processing drawn on top
    bgfx::setTexture(0, textureProg->m_Uniforms[0].BgfxHandle, stack.m_PipelineStackNoPostProcessAttachment);
    ScreenSpaceQuad(view->m_Width, view->m_Height);
    bgfx::setState(BGFX_STATE_WRITE_RGB | BGFX_STATE_WRITE_A | BGFX_STATE_BLEND_ADD);
    bgfx::submit(stack.m_FinalImageViewId, textureProg->m_Handle);
}
