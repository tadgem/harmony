#include "Rendering/Mesh.h"
#include "Core/Profile.hpp"
harmony::Mesh::Mesh()
{
}

void harmony::Mesh::Release()
{
	HARMONY_PROFILE_FUNCTION()
	m_Positions.clear();
	m_Indices.clear();
	m_Normals.clear();
	m_Tangents.clear();
	m_Bitangents.clear();
	m_UVs.clear();
}

void harmony::Mesh::InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices)
{
	HARMONY_PROFILE_FUNCTION()
	m_Positions = positions;
	m_Indices = indices;
	m_HasNormals = false;
	m_HasUVs = false;
	m_HasTangents = false;
	m_HasBitangents = false;
	m_IsSkeletal = false;
	m_NumVerts = positions.size();
}

void harmony::Mesh::InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices, std::vector<glm::vec3> normals)
{
	HARMONY_PROFILE_FUNCTION()
	m_Positions = positions;
	m_Indices = indices;
	m_Normals = normals;
	m_HasUVs = false;
	m_HasNormals = true;
	m_HasTangents = false;
	m_HasBitangents = false;
	m_IsSkeletal = false;
	m_NumVerts = positions.size();
}

void harmony::Mesh::InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices, std::vector<glm::vec3> normals, std::vector<glm::vec2> uvs)
{
	HARMONY_PROFILE_FUNCTION()
	m_Positions = positions;
	m_Indices = indices;
	m_Normals = normals;
	m_UVs = uvs;
	m_HasUVs = true;
	m_HasNormals = true;
	m_HasTangents = false;
	m_HasBitangents = false;
	m_IsSkeletal = false;
	m_NumVerts = positions.size();
}

void harmony::Mesh::InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices, std::vector<glm::vec3> normals, std::vector<glm::vec3> tangents, std::vector<glm::vec2> uvs)
{
	HARMONY_PROFILE_FUNCTION()
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
	m_NumVerts = positions.size();
}

void harmony::Mesh::InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices, std::vector<glm::vec3> normals, std::vector<glm::vec3> tangents, std::vector<glm::vec3> bitangents, std::vector<glm::vec2> uvs)
{
	HARMONY_PROFILE_FUNCTION()
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
	m_NumVerts = positions.size();
}

void harmony::Mesh::BuildBGFXData()
{
	HARMONY_PROFILE_FUNCTION()
	m_BGFXData.clear();
	for (unsigned int i = 0; i < m_NumVerts; i++)
	{
		m_BGFXData.push_back(m_Positions[i].x);
		m_BGFXData.push_back(m_Positions[i].y);
		m_BGFXData.push_back(m_Positions[i].z);
		if (m_HasNormals)
		{
			m_BGFXData.push_back(m_Normals[i].x);
			m_BGFXData.push_back(m_Normals[i].y);
			m_BGFXData.push_back(m_Normals[i].z);
		}

		if (m_HasUVs)
		{
			m_BGFXData.push_back(m_UVs[i].x);
			m_BGFXData.push_back(m_UVs[i].y);
		}

		if (m_HasTangents)
		{
			m_BGFXData.push_back(m_Tangents[i].x);
			m_BGFXData.push_back(m_Tangents[i].y);
			m_BGFXData.push_back(m_Tangents[i].z);
		}

		if (m_HasBitangents)
		{
			m_BGFXData.push_back(m_Bitangents[i].x);
			m_BGFXData.push_back(m_Bitangents[i].y);
			m_BGFXData.push_back(m_Bitangents[i].z);
			m_BGFXData.push_back(m_Bitangents[i].z);
		}
	}

	m_Positions.clear();
	m_Normals.clear();
	m_UVs.clear();
	m_Tangents.clear();
	m_Bitangents.clear();
}
