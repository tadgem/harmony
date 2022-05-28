#pragma once
#include "Assets/AssetFactory.h"
#include "glm/glm.hpp"

#include "Rendering/Model.h"

struct aiNode;
struct aiScene;
struct aiMesh;
namespace harmony
{
    class AssimpModelAssetFactory : public AssetFactory
    {
    public:
        AssimpModelAssetFactory();
    protected:
        virtual std::unordered_map<size_t, std::vector<Ref<Asset>>> CreateAssetData(const std::string& path) override;

        void ProcessNode(aiNode* node, const aiScene* scene);
        void ProcessMesh(aiMesh* mesh, aiNode* node, const aiScene* scene);

        std::vector<Ref<Asset>> p_Meshes;
        std::vector<std::string> p_MeshNames;
        // std::vector<Ref<Texture>> p_Textures
    };
};