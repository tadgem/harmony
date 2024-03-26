#pragma once

#include "Assets/Asset.h"
#include "STL/Vector.h"

#define GLM_FORCE_PURE
#define GLM_ENABLE_EXPERIMENTAL

#include "bgfx/bgfx.h"
#include "glm.hpp"

namespace harmony {

    struct BGFXMeshHandle {
        bgfx::VertexBufferHandle m_VBH = {};
        bgfx::IndexBufferHandle m_IBH = {};
        bgfx::VertexLayout m_Layout = {};
    };

    class Mesh : public Asset {
    public:
        Mesh(const String &path, uint32_t index);

        ~Mesh() override {
        }

        void InitializeMesh(Vector<glm::vec3> positions,
                            Vector<unsigned int> indices);

        void InitializeMesh(Vector<glm::vec3> positions,
                            Vector<unsigned int> indices,
                            Vector<glm::vec3> normals);

        void InitializeMesh(Vector<glm::vec3> positions,
                            Vector<unsigned int> indices,
                            Vector<glm::vec2> uvs);

        void InitializeMesh(Vector<glm::vec3> positions,
                            Vector<unsigned int> indices,
                            Vector<glm::vec3> normals,
                            Vector<glm::vec2> uvs);

        void InitializeMesh(Vector<glm::vec3> positions,
                            Vector<unsigned int> indices,
                            Vector<glm::vec3> normals,
                            Vector<glm::vec3> tangents,
                            Vector<glm::vec2> uvs);

        void InitializeMesh(Vector<glm::vec3> positions,
                            Vector<unsigned int> indices,
                            Vector<glm::vec3> normals,
                            Vector<glm::vec3> tangents,
                            Vector<glm::vec3> bitangents,
                            Vector<glm::vec2> uvs);

        // build float array to submit mesh to GPU
        void BuildBGFXData();

        void Release();

        bool m_HasNormals;
        bool m_HasUVs;
        bool m_HasTangents;
        bool m_HasBitangents;
        bool m_IsSkeletal;
        uint32_t m_NumVerts = 0;
        bool m_SubmittedToGpu;
        BGFXMeshHandle m_Handle;
        Vector<unsigned int> m_Indices;
        Vector<glm::vec3> m_Positions;
        Vector<glm::vec3> m_Normals;
        Vector<glm::vec3> m_Tangents;
        Vector<glm::vec3> m_Bitangents;
        Vector<glm::vec2> m_UVs;
        Vector<float> m_BGFXData;
        uint64_t m_Id;

    private:
        inline static const uint16_t p_Stream = 0;
    };
}; // namespace harmony