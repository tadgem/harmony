#pragma once
#include "Assets/Asset.h"
#define GLM_FORCE_PURE
#define GLM_ENABLE_EXPERIMENTAL
#include "glm.hpp"
#include "bgfx/bgfx.h"

namespace harmony {

	struct BGFXMeshHandle
	{
		bgfx::VertexBufferHandle m_VBH;
		bgfx::IndexBufferHandle m_IBH;
		bgfx::VertexLayout m_Layout;
	};

	class Mesh : public Asset
    {
    public:
        Mesh(const std::string& path, uint32_t index);

        ~Mesh() override
        {
        }

		void InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices);
		void InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices,std::vector<glm::vec3> normals);
		void InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices,std::vector<glm::vec2> uvs);
		void InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices,std::vector<glm::vec3> normals, std::vector<glm::vec2> uvs);
		void InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices,std::vector<glm::vec3> normals, std::vector<glm::vec3> tangents, std::vector<glm::vec2> uvs);
		void InitializeMesh(std::vector<glm::vec3> positions, std::vector<unsigned int> indices,std::vector<glm::vec3> normals, std::vector<glm::vec3> tangents,std::vector<glm::vec3> bitangents, std::vector<glm::vec2> uvs);

		// build float array to submit mesh to GPU
		void BuildBGFXData();

		void Bind();

		void Release();

		bool m_HasNormals;
		bool m_HasUVs;
		bool m_HasTangents;
		bool m_HasBitangents;
		bool m_IsSkeletal;
		uint32_t m_NumVerts = 0;

		bool m_SubmittedToGpu;
		BGFXMeshHandle m_Handle;

		std::vector<unsigned int> m_Indices;
		std::vector<glm::vec3> m_Positions;
		std::vector<glm::vec3> m_Normals;
		std::vector<glm::vec3> m_Tangents;
		std::vector<glm::vec3> m_Bitangents;
		std::vector<glm::vec2> m_UVs;

		std::vector<float> m_BGFXData;

		uint64_t m_Id;
	private:
		inline static const uint16_t p_Stream = 0;
    };
};