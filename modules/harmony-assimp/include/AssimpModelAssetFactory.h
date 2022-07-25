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
        virtual void LoadAssetData(const std::string& path, entt::registry& registry) override;
        virtual void UnloadAssetData(const std::string& path, entt::registry& registry) override;

        void ProcessNode(const std::string& path, aiNode* node, const aiScene* scene);
        void ProcessMesh(const std::string& path, aiMesh* mesh, aiNode* node, const aiScene* scene);

        std::vector<Ref<Asset>> p_Meshes;
        std::vector<std::string> p_MeshNames;

        uint32_t p_MeshCounter = 0;
    };
};