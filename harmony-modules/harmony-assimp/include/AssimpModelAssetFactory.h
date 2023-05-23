#pragma once

#include "Core/Alias.h"
#include "Assets/AssetFactory.h"
#include "glm/glm.hpp"

#include "Rendering/Model.h"
#include "Rendering/Renderer.h"

struct aiNode;
struct aiScene;
struct aiMesh;
namespace harmony {
    class AssimpModelAssetFactory : public AssetFactory {
    public:
        AssimpModelAssetFactory(Renderer &renderer);

    protected:
        virtual void LoadAssetData(const String &path, entt::registry &registry) override;

        virtual void UnloadAssetData(const String &path, entt::registry &registry) override;

        void ProcessNode(const String &path, aiNode *node, const aiScene *scene);

        void ProcessMesh(const String &path, aiMesh *mesh, aiNode *node, const aiScene *scene);

        Vector<Ref<Asset>> p_Meshes;

        Vector<String> p_MeshNames;

        uint32_t p_MeshCounter = 0;

    protected:
        Renderer &p_Renderer;
    };
};