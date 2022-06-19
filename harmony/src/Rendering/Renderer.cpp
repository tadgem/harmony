#include "Rendering/Renderer.h"
#include "Core/Profile.hpp"
#include "bgfx/platform.h"
#include "ECS/ModelComponent.h"
#include "ECS/MeshComponent.h"
#include "ECS/MaterialComponent.h"
harmony::Renderer::Renderer(AssetManager& assetManager) : p_AssetManager(assetManager)
{
    HARMONY_PROFILE_FUNCTION()
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

void harmony::Renderer::ProcessRendering()
{
    HARMONY_PROFILE_FUNCTION()
    for (int i = 0; i < m_ViewManager.m_ActiveViews.size(); i++)
    {
        Ref<View> currentView = m_ViewManager.m_ActiveViews[i].lock();

    }
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

    //if (mesh->m_HasTangents)
    //{
    //    vl.add(bgfx::Attrib::Tangent, 3, bgfx::AttribType::Float);
    //}

    //if (mesh->m_HasBitangents)
    //{
    //    vl.add(bgfx::Attrib::Bitangent, 3, bgfx::AttribType::Float);
    //}

    // TODO add support for skeletal meshes.
    vl.end();
    return vl;

}
