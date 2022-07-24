#include "Rendering/Renderer.h"
#include "Core/Profile.hpp"
#include "bgfx/platform.h"
#include "ECS/ModelComponent.h"
#include "ECS/MeshComponent.h"
#include "ECS/MaterialComponent.h"
#include "Core/Log.hpp"
#include "Core/Time.h"
#include "Rendering/BuiltinShaders.h"
#include "Rendering/Shapes.h"
#if HARMONY_DEBUG
#include "ImGui/imgui_bgfx.h"
#include "ImGui/imgui.h"
#include "ImGui/icons_font_awesome.h"
#endif

harmony::Renderer::Renderer(AssetManager& assetManager) : p_AssetManager(assetManager)
{
    HARMONY_PROFILE_FUNCTION()
}

void harmony::Renderer::AddBuiltInShader(const std::string& progName, const std::string& vsName, const std::string& fsName, uint32_t vsIndex, uint32_t fsIndex)
{
    Ref<ShaderProgram> prog = CreateRef<ShaderProgram>(progName);
    Ref<BuiltInShaderStage> vs = CreateRef<BuiltInShaderStage>(vsName, ShaderStage::Type::Vertex, s_BuiltInShader[vsIndex]);
    vs->LoadShaderBinary();
    Ref<BuiltInShaderStage> fs = CreateRef<BuiltInShaderStage>(fsName, ShaderStage::Type::Fragment, s_BuiltInShader[fsIndex]);
    fs->LoadShaderBinary();
    prog->AddStage(ShaderStage::Type::Vertex, vs);
    prog->AddStage(ShaderStage::Type::Fragment, fs);

    prog->Build();

    ShaderDataContainer dataContainer = ShaderDataContainer(prog);
    p_Shaders.emplace(prog, dataContainer);
}

void harmony::Renderer::AddBuiltInShader(const std::string& progName, const std::string& csName, uint32_t csIndex)
{
    Ref<ShaderProgram> prog = CreateRef<ShaderProgram>(progName);
    Ref<BuiltInShaderStage> cs = CreateRef<BuiltInShaderStage>(csName, ShaderStage::Type::Compute, s_BuiltInShader[csIndex]);
    cs->LoadShaderBinary();
    prog->AddStage(ShaderStage::Type::Compute, cs);

    prog->Build();

    ShaderDataContainer dataContainer = ShaderDataContainer(prog);
    p_Shaders.emplace(prog, dataContainer);
}

void harmony::Renderer::AddBuiltInShaders()
{
    AddBuiltInShader("TexturedMesh", "vs_simple_textured", "fs_simple_textured", 0, 1);
    AddBuiltInShader("Normal", "vs_normal", "fs_normal", 2, 3);
    AddBuiltInShader("Present", "vs_present", "fs_present", 4, 5);
    AddBuiltInShader("NanoVG", "vs_nanovg_fill", "fs_nanovg_fill", 6, 7);
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
        if (p_Views.find(_view) != p_Views.end())
        {
            p_Views.erase(_view);
        }
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
    entt::registry tempRegistry;
    for (auto& [view, stack] : p_Views)
    {
        for (int i = 0; i < stack.m_Stack.size(); i++)
        {
            Ref<Pipeline> pipeline = stack.m_Stack[i];
            pipeline->Init(tempRegistry, view);
        }
        stack.Init(tempRegistry);
    }
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
        view->OnPreUpdate(registry);
        PipelineStack& stack = p_Views[view];
        
        stack.PreUpdate(registry);
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

        stack.PostUpdate(registry);
    }
}

harmony::PipelineStack& harmony::Renderer::GetViewPipelineStack(const std::string& viewName)
{
    for (auto& [view, stack] : p_Views)
    {
        if (view->m_Name == viewName)
        {
            return stack;
        }
    }
    // TODO: This is horrible, fix me
    return p_Views.begin()->second;
}

void harmony::Renderer::AddViewPipeline(WeakRef<View> viewWeakRef, WeakRef<Pipeline> pipeline)
{
    if (viewWeakRef.expired())
    {
        harmony::log::error("Trying to add pipeline association to a view which is expired.");
        return;
    }

    Ref<View> view = viewWeakRef.lock();

    if (p_Views.find(view) == p_Views.end())
    {
        harmony::log::error("Trying to add pipeline association to a view not managed by this View Manager.");
        return;
    }

    if (pipeline.expired())
    {
        harmony::log::error("Trying to add pipeline to stack but pipeline is expired");
        return;
    }

    Ref<Pipeline> p = pipeline.lock();
    entt::registry r;
    p->Init(r, viewWeakRef);

    p_Views[view].m_Stack.emplace_back(pipeline);
}

void harmony::Renderer::RefreshViews()
{
    for (int i = 0; i < m_ActiveViews.size(); i++)
    {
        Ref<View> view = m_ActiveViews[i].lock();
        for (int p = 0; p < p_Views[view].m_Stack.size(); p++)
        {
        }
    }
}

#if HARMONY_DEBUG
void harmony::Renderer::OnImGui()
{
    const std::string rendererTitle = std::string(ICON_FA_SLIDERS) + " Renderer";

    if (ImGui::Begin(rendererTitle.c_str()))
    {
        ImGui::Text("Frametime : %f", Time::GetFrameTime());
        ImGui::Text("FPS : %f", 1.0 / Time::GetFrameTime());
        ImGui::Separator();
        ImGui::Text("Shaders");
        ImGui::Indent();
        for (auto& [shader, data] : p_Shaders)
        {
            ImGui::Text(shader->m_Name.c_str());
        }
        ImGui::Unindent();
        ImGui::Separator();
        ImGui::Text("Shader Stages");
        ImGui::Indent();
        for (auto& [path, stage] : p_LoadedStagePaths)
        {
            ImGui::Text(path.c_str());
        }
        ImGui::Unindent();
        ImGui::Separator();
        
        ImGui::Text("View Properties");
        ImGui::Separator();

        for (auto& [view, pipelines] : p_Views)
        {
            ImGui::Text(view->m_Name.c_str());
            ImGui::Indent();
            view->OnImGuiOptions();
            ImGui::Unindent();
            ImGui::Separator();
        }
    }
    ImGui::End();

    for (auto& [view, pipelines] : p_Views)
    {
        view->OnImGui();
    }

    //for (int i = 0; i < m_ActiveViews.size();i++)
    //{
    //    Ref<View> view = m_ActiveViews[i].lock();
    //    if (ImGui::Begin(view->m_Name.c_str()))
    //    {
    //        bgfx::TextureHandle fbHandle = p_Views[view].GetStackFinalImage();
    //        if (fbHandle.idx == bgfx::kInvalidHandle)
    //        {
    //            // harmony::log::warn("Renderer OnImGui : Invalid framebuffer handle for view {} pipeline {}", view->m_Name, p_Views[view][p]->m_Name);
    //            continue;
    //        }
    //        if (!bgfx::isValid(fbHandle))
    //        {
    //            continue;
    //        }
    //        ImGui::Image(
    //            fbHandle,
    //            ImVec2(static_cast<float>(view->m_Width), static_cast<float>(view->m_Height))
    //        );
    //        ImGui::Separator();
    //        for (int p = 0; p < p_Views[view].m_Stack.size(); p++)
    //        {
    //            bgfx::TextureHandle fbHandle = p_Views[view].m_Stack[p]->GetFinalImage();
    //            if (fbHandle.idx == bgfx::kInvalidHandle)
    //            {
    //                // harmony::log::warn("Renderer OnImGui : Invalid framebuffer handle for view {} pipeline {}", view->m_Name, p_Views[view][p]->m_Name);
    //                continue;
    //            }
    //            if (!bgfx::isValid(fbHandle))
    //            {
    //                continue;
    //            }
    //            ImGui::Image(
    //                fbHandle,
    //                ImVec2(static_cast<float>(view->m_Width), static_cast<float>(view->m_Height))
    //            );
    //        }

    //    }
    //    ImGui::End();
    //}
}
#endif

bgfx::ViewId harmony::Renderer::GetViewID()
{
    bgfx::ViewId v = p_ViewHandleCounter;
    p_ViewHandleCounter++;
    return v;
}

harmony::WeakRef<harmony::ShaderProgram> harmony::Renderer::LoadShader(const std::string& name, const std::string& vertName, const std::string& fragName)
{
    HARMONY_PROFILE_FUNCTION()
    Ref<ShaderProgram> prog = CreateRef<ShaderProgram>(name);
    Ref<ShaderStage> vertStage = CreateRef<ShaderStage>(vertName, ShaderStage::Type::Vertex);
    vertStage->LoadShaderBinary();
    p_LoadedStagePaths.emplace(vertStage->m_Path, vertStage);
    Ref<ShaderStage> fragStage = CreateRef<ShaderStage>(fragName, ShaderStage::Type::Fragment);
    fragStage->LoadShaderBinary();
    p_LoadedStagePaths.emplace(fragStage->m_Path, fragStage);
    prog->AddStage(ShaderStage::Type::Vertex, GetWeakRef<ShaderStage>(vertStage));
    prog->AddStage(ShaderStage::Type::Fragment, GetWeakRef<ShaderStage>(fragStage));

    prog->Build();

    auto wr = GetWeakRef<ShaderProgram>(prog);

    ShaderDataContainer dataContainer = ShaderDataContainer(wr);
    p_Shaders.emplace(prog, dataContainer);

    return wr;
}

harmony::WeakRef<harmony::ShaderProgram> harmony::Renderer::LoadShader(const std::string& name, const std::string& computeName)
{
    HARMONY_PROFILE_FUNCTION()
    Ref<ShaderProgram> prog = CreateRef<ShaderProgram>(name);
    Ref<ShaderStage> compStage = CreateRef<ShaderStage>(computeName, ShaderStage::Type::Compute);

    prog->AddStage(ShaderStage::Type::Compute, GetWeakRef<ShaderStage>(compStage));

    prog->Build();

    auto wr = GetWeakRef<ShaderProgram>(prog);
    ShaderDataContainer dataContainer = ShaderDataContainer(wr);
    
    p_Shaders.emplace(prog, dataContainer);

    return wr;
}

void harmony::Renderer::ReloadShader(WeakRef<ShaderProgram> shader)
{
    if (shader.expired())
    {
        harmony::log::error("Trying to reload an invalid shader.");
        return;
    }

    Ref<ShaderProgram> prog = shader.lock();

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
    for (auto [shader, data] : p_Shaders)
    {
        ReloadShader(shader);
    }
}

harmony::WeakRef<harmony::ShaderProgram> harmony::Renderer::GetShader(const std::string& name)
{
    for (auto& [shader, data] : p_Shaders)
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
    for (auto& [shader, data] : p_Shaders)
    {
        shaders.push_back(shader->m_Name);
    }
    return shaders;
}

void harmony::Renderer::RefreshShaderDataContainers()
{
}

void harmony::Renderer::AddUniform(const std::string name, WeakRef<float> value)
{
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
