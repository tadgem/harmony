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
    p_Shaders.emplace_back(prog);

    auto wr = GetWeakRef<ShaderProgram>(prog);
    return wr;
}

harmony::WeakRef<harmony::ShaderProgram> harmony::Renderer::LoadShader(const std::string& name, const std::string& computeName)
{
    HARMONY_PROFILE_FUNCTION()
    Ref<ShaderProgram> prog = CreateRef<ShaderProgram>(name);
    Ref<ShaderStage> compStage = CreateRef<ShaderStage>(computeName, ShaderStage::Type::Compute);

    prog->AddStage(ShaderStage::Type::Compute, GetWeakRef<ShaderStage>(compStage));

    prog->Build();
    p_Shaders.emplace_back(prog);

    auto wr = GetWeakRef<ShaderProgram>(prog);
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
    bimg::ImageContainer* imageContainer = texture->p_ImageContainer;

    if (imageContainer->m_cubeMap)
    {
        handle.m_Handle = bgfx::createTextureCube(
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
        handle.m_Handle = bgfx::createTexture3D(
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
        handle.m_Handle = bgfx::createTexture2D(
            uint16_t(imageContainer->m_width)
            , uint16_t(imageContainer->m_height)
            , 1 < imageContainer->m_numMips
            , imageContainer->m_numLayers
            , bgfx::TextureFormat::Enum(imageContainer->m_format)
            , flags
            , texture->p_Memory
        );
    }

    if (bgfx::isValid(handle.m_Handle))
    {
        bgfx::setName(handle.m_Handle, texture->m_AssetPath.c_str());
    }

    if (&handle.m_Info != NULL)
    {
        bgfx::calcTextureSize(
            handle.m_Info
            , uint16_t(imageContainer->m_width)
            , uint16_t(imageContainer->m_height)
            , uint16_t(imageContainer->m_depth)
            , imageContainer->m_cubeMap
            , 1 < imageContainer->m_numMips
            , imageContainer->m_numLayers
            , bgfx::TextureFormat::Enum(imageContainer->m_format)
        );
    }

    texture->m_Handle = handle;
    texture->m_SubmittedToGPU = true;
    return handle;
}

void harmony::Renderer::RenderMesh(const BGFXMeshHandle& meshHandle, const RenderState& renderState)
{
    HARMONY_PROFILE_FUNCTION()
    if (p_CurrentView != renderState.m_View)
    {
        p_CurrentView = renderState.m_View;
        bgfx::touch(p_CurrentView);
    }
    bgfx::setIndexBuffer(meshHandle.m_IBH);
    bgfx::setVertexBuffer(0, meshHandle.m_VBH);
    bgfx::submit(p_CurrentView, renderState.m_Program);
}

void harmony::Renderer::RenderScene(WeakRef<Scene> sceneWeakRef)
{
    HARMONY_PROFILE_FUNCTION()
    Ref<Scene> scene = sceneWeakRef.lock();
    // set all uniforms? 
    // foreach mesh drawable in scene.m_Registry...
    // CreateRenderState
    // Set transform matrix
    // RenderMesh(thatMesh, thatState);

    auto meshRegistryView = scene->m_Registry.view<const MeshComponent, const MaterialComponent>();
    auto modelRegistryView = scene->m_Registry.view<const ModelComponent, const MaterialComponent>();

    for (auto [entity, meshComponent, materialComponent] : meshRegistryView.each())
    {
        RenderState state;
        // need to figure out how we handle cameras as this is where the associated bgfx view id should be stored.
        // state.m_View = ? ;
        state.m_Program = materialComponent.ProgramHandle;
        RenderMesh(meshComponent.Handle, state);
    }

    for (auto [entity, modelComponent, materialComponent] : modelRegistryView.each())
    {
        RenderState state;
        // need to figure out how we handle cameras as this is where the associated bgfx view id should be stored.
        // state.m_View = ? ;
        state.m_Program = materialComponent.ProgramHandle;

    }
}

void harmony::Renderer::GlobalProcessRender(WeakRef<Scene> activeScene)
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
