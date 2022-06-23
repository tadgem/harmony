#include "Rendering/Renderer.h"
#include "Core/Profile.hpp"
#include "bgfx/platform.h"
#include "ECS/ModelComponent.h"
#include "ECS/MeshComponent.h"
#include "ECS/MaterialComponent.h"
#include "Core/Log.hpp"
#include "Core/Time.h"
#if HARMONY_DEBUG
#include "ImGui/imgui_bgfx.h"
#include "ImGui/imgui.h"
#endif

harmony::Renderer::Renderer(AssetManager& assetManager) : p_AssetManager(assetManager)
{
    HARMONY_PROFILE_FUNCTION()
}

bgfx::VertexLayout harmony::PosColorTexCoord0Vertex::ms_layout;
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
    for (auto& [key, val] : p_Views)
    {
        for (int i = 0; i < val.size(); i++)
        {
            Ref<Pipeline> pipeline = val[i];
            pipeline->Init(entt::registry(), key);
        }
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
        std::vector<Ref<Pipeline>>& pipelines = p_Views[view];
        
        for (int p = 0; p < pipelines.size(); p++)
        {
            if (!pipelines[p])
            {
                harmony::log::warn("Pipeline {} is expired.", p);
                continue;
            }
            pipelines[i]->PreUpdate(registry, m_ActiveViews[i]);
        }
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
        std::vector<Ref<Pipeline>>& pipelines = p_Views[view];

        for (int p = 0; p < pipelines.size(); p++)
        {
            if (!pipelines[p])
            {
                harmony::log::warn("Pipeline {} is expired.", p);
                continue;
            }
            pipelines[i]->PostUpdate(registry, m_ActiveViews[i]);
        }
    }
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
    p_Views[view].emplace_back(pipeline);
}

#if HARMONY_DEBUG
void harmony::Renderer::OnImGui()
{
    if (ImGui::Begin("View Manager"))
    {
        ImGui::Text("Frametime : %f", Time::GetFrameTime());
        ImGui::Text("FPS : %f", 1.0 / Time::GetFrameTime());
        ImGui::Separator();
        ImGui::Text("Views");
        ImGui::Separator();

        for (auto& [view, pipelines] : p_Views)
        {
            ImGui::Text(view->m_Name.c_str());
            view->OnImGui();
            ImGui::Separator();
        }
    }
    ImGui::End();

    for (int i = 0; i < m_ActiveViews.size();i++)
    {
        Ref<View> view = m_ActiveViews[i].lock();
        if (ImGui::Begin(view->m_Name.c_str()))
        {
            for (int p = 0; p < p_Views[view].size(); p++)
            {
                bgfx::TextureHandle fbHandle = p_Views[view][p]->GetFinalImage();
                if (fbHandle.idx == bgfx::kInvalidHandle)
                {
                    harmony::log::warn("Renderer OnImGui : Invalid framebuffer handle for view {} pipeline {}", view->m_Name, p_Views[view][p]->m_Name);
                    continue;
                }
                if (!bgfx::isValid(fbHandle))
                {
                    continue;
                }
                ImGui::Image(
                    fbHandle,
                    ImVec2(view->m_Width, view->m_Height)
                );
            }
        }
        ImGui::End();
    }
}
#endif

bgfx::ViewId harmony::Renderer::GetViewID()
{
    bgfx::ViewId v = p_ViewHandleCounter;
    p_ViewHandleCounter++;
    return v;
}

void harmony::Renderer::ScreenSpaceQuad(float _textureWidth, float _textureHeight, bool _originBottomLeft, float _width, float _height)
{
    if (3 == bgfx::getAvailTransientVertexBuffer(3, PosColorTexCoord0Vertex::ms_layout))
    {
        bgfx::TransientVertexBuffer vb;
        bgfx::allocTransientVertexBuffer(&vb, 3, PosColorTexCoord0Vertex::ms_layout);
        PosColorTexCoord0Vertex* vertex = (PosColorTexCoord0Vertex*)vb.data;

        const float zz = 0.0f;

        const float minx = -_width;
        const float maxx = _width;
        const float miny = 0.0f;
        const float maxy = _height * 2.0f;

        const float texelHalfW = s_texelHalf / _textureWidth;
        const float texelHalfH = s_texelHalf / _textureHeight;
        const float minu = -1.0f + texelHalfW;
        const float maxu = 1.0f + texelHalfW;

        float minv = texelHalfH;
        float maxv = 2.0f + texelHalfH;

        if (_originBottomLeft)
        {
            float temp = minv;
            minv = maxv;
            maxv = temp;

            minv -= 1.0f;
            maxv -= 1.0f;
        }

        vertex[0].m_x = minx;
        vertex[0].m_y = miny;
        vertex[0].m_z = zz;
        vertex[0].m_rgba = 0xffffffff;
        vertex[0].m_u = minu;
        vertex[0].m_v = minv;

        vertex[1].m_x = maxx;
        vertex[1].m_y = miny;
        vertex[1].m_z = zz;
        vertex[1].m_rgba = 0xffffffff;
        vertex[1].m_u = maxu;
        vertex[1].m_v = minv;

        vertex[2].m_x = maxx;
        vertex[2].m_y = maxy;
        vertex[2].m_z = zz;
        vertex[2].m_rgba = 0xffffffff;
        vertex[2].m_u = maxu;
        vertex[2].m_v = maxv;

        bgfx::setVertexBuffer(0, &vb);
    }
}

harmony::WeakRef<harmony::ShaderProgram> harmony::Renderer::LoadShader(const std::string& name, const std::string& vertName, const std::string& fragName)
{
    HARMONY_PROFILE_FUNCTION()
    Ref<ShaderProgram> prog = CreateRef<ShaderProgram>(name);
    Ref<ShaderStage> vertStage = CreateRef<ShaderStage>(vertName, ShaderStage::Type::Vertex);
    vertStage->LoadShaderBinary();
    Ref<ShaderStage> fragStage = CreateRef<ShaderStage>(fragName, ShaderStage::Type::Fragment);
    fragStage->LoadShaderBinary();
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

    return m;
}

harmony::BGFXTextureHandle harmony::Renderer::SubmitTextureToGPU(WeakRef<Texture> textureWeakRef)
{
    uint64_t flags = 0;

    BGFXTextureHandle handle;

    Ref<Texture> texture = textureWeakRef.lock();
    handle.AssetHandle = texture->m_Handle;
    bimg::ImageContainer* imageContainer = texture->p_ImageContainer;

    if (imageContainer->m_cubeMap)
    {
        handle.Handle = bgfx::createTextureCube(
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
        handle.Handle = bgfx::createTexture3D(
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
        handle.Handle = bgfx::createTexture2D(
            uint16_t(imageContainer->m_width)
            , uint16_t(imageContainer->m_height)
            , 1 < imageContainer->m_numMips
            , imageContainer->m_numLayers
            , bgfx::TextureFormat::Enum(imageContainer->m_format)
            , flags
            , texture->p_Memory
        );
    }

    if (bgfx::isValid(handle.Handle))
    {
        bgfx::setName(handle.Handle, texture->m_Handle.Path.c_str());
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
