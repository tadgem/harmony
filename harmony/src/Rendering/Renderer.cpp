#include "Rendering/Renderer.h"
#include "Core/Profile.hpp"

harmony::Renderer::Renderer()
{
    HARMONY_PROFILE_FUNCTION()
}

harmony::WeakRef<harmony::ShaderProgram> harmony::Renderer::LoadShader(const std::string& name, const std::string& vertName, const std::string& fragName)
{
    HARMONY_PROFILE_FUNCTION()
    Ref<ShaderProgram> prog = CreateRef<ShaderProgram>(name);
    ShaderStage vertStage = ShaderStage(vertName, ShaderStage::Type::Vertex);
    vertStage.LoadShaderBinary();
    ShaderStage fragStage = ShaderStage(fragName, ShaderStage::Type::Fragment);
    fragStage.LoadShaderBinary();

    prog->AddStage(ShaderStage::Type::Vertex, vertStage);
    prog->AddStage(ShaderStage::Type::Vertex, fragStage);

    prog->Build();
    auto wr = GetWeakRef<ShaderProgram>(prog);
    return wr;
}

harmony::WeakRef<harmony::ShaderProgram> harmony::Renderer::LoadShader(const std::string& name, const std::string& computeName)
{
    HARMONY_PROFILE_FUNCTION()
    Ref<ShaderProgram> prog = CreateRef<ShaderProgram>(name);
    ShaderStage compStage = ShaderStage(computeName, ShaderStage::Type::Compute);

    prog->AddStage(ShaderStage::Type::Vertex, compStage);

    prog->Build();
    auto wr = GetWeakRef<ShaderProgram>(prog);
    return wr;
}

harmony::BGFXMeshHandle harmony::Renderer::SubmitMeshToGPU(const Mesh& mesh)
{
    HARMONY_PROFILE_FUNCTION()
    BGFXMeshHandle m = BGFXMeshHandle();
    m.m_Layout = BuildVertexLayout(mesh);
    auto data = BuildVertexBufferData(mesh);

    m.m_VBH = bgfx::createVertexBuffer(bgfx::makeRef(data.data(), mesh.m_NumVerts), m.m_Layout);
    m.m_IBH = bgfx::createIndexBuffer(bgfx::makeRef(mesh.m_Indices.data(), mesh.m_Indices.size()));

    return m;
}

bgfx::VertexLayout harmony::Renderer::BuildVertexLayout(const Mesh& mesh)
{
    HARMONY_PROFILE_FUNCTION()
    bgfx::VertexLayout vl = bgfx::VertexLayout();
    vl.begin();

    // do we need to support 2 component positions? 
    vl.add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float);

    if (mesh.m_HasNormals)
    {
        vl.add(bgfx::Attrib::Normal, 3, bgfx::AttribType::Float);
    }

    if (mesh.m_HasUVs)
    {
        vl.add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float);
    }

    if (mesh.m_HasTangents)
    {
        vl.add(bgfx::Attrib::Tangent, 3, bgfx::AttribType::Float);
    }

    if (mesh.m_HasBitangents)
    {
        vl.add(bgfx::Attrib::Bitangent, 3, bgfx::AttribType::Float);
    }

    // TODO add support for skeletal meshes.
    vl.end();
    return vl;

}

std::vector<float> harmony::Renderer::BuildVertexBufferData(const Mesh& mesh)
{
    HARMONY_PROFILE_FUNCTION()
    auto floats = std::vector<float>();
    for (int i = 0; i < mesh.m_NumVerts; i++)
    {
        floats.push_back(mesh.m_Positions[i].x);
        floats.push_back(mesh.m_Positions[i].y);
        floats.push_back(mesh.m_Positions[i].z);
        if (mesh.m_HasNormals)
        {
            floats.push_back(mesh.m_Normals[i].x);
            floats.push_back(mesh.m_Normals[i].y);
            floats.push_back(mesh.m_Normals[i].z);
        }

        if (mesh.m_HasUVs)
        {
            floats.push_back(mesh.m_UVs[i].x);
            floats.push_back(mesh.m_UVs[i].y);
        }

        if (mesh.m_HasTangents)
        {
            floats.push_back(mesh.m_Tangents[i].x);
            floats.push_back(mesh.m_Tangents[i].y);
            floats.push_back(mesh.m_Tangents[i].z);
        }

        if (mesh.m_HasBitangents)
        {
            floats.push_back(mesh.m_Bitangents[i].x);
            floats.push_back(mesh.m_Bitangents[i].y);
            floats.push_back(mesh.m_Bitangents[i].z);
        }
    }

    return floats;
}
