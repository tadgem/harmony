#include "Rendering/Mesh.h"

harmony::Mesh::Mesh()
{
}

void harmony::Mesh::Release()
{
	m_Positions.clear();
	m_Indices.clear();
	m_Normals.clear();
	m_Tangents.clear();
	m_Bitangents.clear();
	m_UVs.clear();
}

void harmony::Mesh::InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices)
{
	m_Positions = positions;
	m_Indices = indices;
	m_HasNormals = false;
	m_HasUVs = false;
	m_HasTangents = false;
	m_HasBitangents = false;
	m_IsSkeletal = false;
}

void harmony::Mesh::InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices, std::vector<glm::vec3> normals)
{
	m_Positions = positions;
	m_Indices = indices;
	m_Normals = normals;
	m_HasUVs = false;
	m_HasNormals = true;
	m_HasTangents = false;
	m_HasBitangents = false;
	m_IsSkeletal = false;
}

void harmony::Mesh::InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices, std::vector<glm::vec3> normals, std::vector<glm::vec2> uvs)
{
	m_Positions = positions;
	m_Indices = indices;
	m_Normals = normals;
	m_UVs = uvs;
	m_HasUVs = true;
	m_HasNormals = true;
	m_HasTangents = false;
	m_HasBitangents = false;
	m_IsSkeletal = false;
}

void harmony::Mesh::InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices, std::vector<glm::vec3> normals, std::vector<glm::vec3> tangents, std::vector<glm::vec2> uvs)
{
	m_Positions = positions;
	m_Indices = indices;
	m_Normals = normals;
	m_Tangents = tangents;
	m_UVs = uvs;
	m_HasUVs = true;
	m_HasNormals = true;
	m_HasTangents = true;
	m_HasBitangents = false;
	m_IsSkeletal = false;
}

void harmony::Mesh::InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices, std::vector<glm::vec3> normals, std::vector<glm::vec3> tangents, std::vector<glm::vec3> bitangents, std::vector<glm::vec2> uvs)
{
	m_Positions = positions;
	m_Indices = indices;
	m_Normals = normals;
	m_Tangents = tangents;
	m_Bitangents = bitangents;
	m_UVs = uvs;
	m_HasUVs = true;
	m_HasNormals = true;
	m_HasTangents = true;
	m_HasBitangents = true;
	m_IsSkeletal = false;
}