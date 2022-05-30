#include "Rendering/Renderer.h"
#include "Core/Profile.hpp"
#include "bgfx/platform.h"

harmony::Renderer::Renderer()
{
    HARMONY_PROFILE_FUNCTION()
}

harmony::WeakRef<harmony::ShaderProgram> harmony::Renderer::LoadShader(const std::string& name, const std::string& vertName, const std::string& fragName)
{
    HARMONY_PROFILE_FUNCTION()
    Ref<ShaderProgram> prog = CreateRef<ShaderProgram>(name);
    Ref<ShaderStage> vertStage = CreateRef<ShaderStage>(vertName, ShaderStage::Type::Vertex);
    vertStage->LoadShaderBinary();
    p_ShaderStages.emplace_back(vertStage);
    Ref<ShaderStage> fragStage = CreateRef<ShaderStage>(fragName, ShaderStage::Type::Fragment);
    fragStage->LoadShaderBinary();
    p_ShaderStages.emplace_back(fragStage);
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

harmony::BGFXMeshHandle harmony::Renderer::SubmitMeshToGPU(WeakRef<Mesh> mesh)
{
    HARMONY_PROFILE_FUNCTION()
    auto meshRef = mesh.lock();
    BGFXMeshHandle m = BGFXMeshHandle();
    m.m_Layout = BuildVertexLayout(mesh);
    meshRef->BuildBGFXData();
    uint32_t dataSize = static_cast<uint32_t>(meshRef->m_Indices.size());
    m.m_VBH = bgfx::createVertexBuffer(bgfx::makeRef(meshRef->m_BGFXData.data(), meshRef->m_BGFXData.size() * sizeof(float)), m.m_Layout);
    m.m_IBH = bgfx::createIndexBuffer(bgfx::makeRef(meshRef->m_Indices.data(), (dataSize * sizeof(unsigned int))), BGFX_BUFFER_INDEX32);

    return m;
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
    bgfx::setVertexBuffer(p_CurrentView, meshHandle.m_VBH);
    bgfx::submit(p_CurrentView, renderState.m_Program);
}

void harmony::Renderer::RenderScene(Ref<Scene> scene)
{
    HARMONY_PROFILE_FUNCTION()
    // set all uniforms? 
    // foreach mesh drawable in scene.m_Registry...
    // CreateRenderState
    // RenderMesh(thatMesh, thatState);
}

bgfx::VertexLayout harmony::Renderer::BuildVertexLayout(WeakRef<Mesh> meshWeakRef)
{
    auto mesh = meshWeakRef.lock();
    HARMONY_PROFILE_FUNCTION()
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
