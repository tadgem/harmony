#pragma once
#include "Assets/Asset.h"
#define GLM_FORCE_PURE
#define GLM_ENABLE_EXPERIMENTAL
#include "glm.hpp"
#include "bgfx/bgfx.h"

namespace harmony {

	class Mesh : public Asset
    {
    public:
        Mesh();

        ~Mesh() override
        {
        }

		void InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices);
		void InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices,std::vector<glm::vec3> normals);
		void InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices,std::vector<glm::vec2> uvs);
		void InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices,std::vector<glm::vec3> normals, std::vector<glm::vec2> uvs);
		void InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices,std::vector<glm::vec3> normals, std::vector<glm::vec3> tangents, std::vector<glm::vec2> uvs);
		void InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices,std::vector<glm::vec3> normals, std::vector<glm::vec3> tangents,std::vector<glm::vec3> bitangents, std::vector<glm::vec2> uvs);

		void Release();

		bool m_HasNormals;
		bool m_HasUVs;
		bool m_HasTangents;
		bool m_HasBitangents;
		bool m_IsSkeletal;
		unsigned int m_NumVerts = 0;

		std::vector<unsigned int> m_Indices;
		std::vector<glm::vec3> m_Positions;
		std::vector<glm::vec3> m_Normals;
		std::vector<glm::vec3> m_Tangents;
		std::vector<glm::vec3> m_Bitangents;
		std::vector<glm::vec2> m_UVs;

    };
};