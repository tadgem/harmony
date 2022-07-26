#include "Core/Log.hpp"
#include "AssimpModelAssetFactory.h"
#include "assimp/Importer.hpp"
#include "assimp/postprocess.h"
#include "assimp/cimport.h"
#include "assimp/mesh.h"
#include "assimp/scene.h"

static glm::vec3 AssimpToGLM(aiVector3D aiVec)
{
	return glm::vec3(aiVec.x, aiVec.y, aiVec.z);
}

static glm::vec2 AssimpToGLM(aiVector2D aiVec)
{
	return glm::vec2(aiVec.x, aiVec.y);
}

static std::string AssimpToSTD(aiString str)
{
	return std::string(str.C_Str());
}

harmony::AssimpModelAssetFactory::AssimpModelAssetFactory(Renderer& renderer) : harmony::AssetFactory(), p_Renderer(renderer)
{
	size_t modelTypeHash = GetTypeHash<Model>();
	size_t meshTypeHash = GetTypeHash<Mesh>();

	m_Capabilities.AssetTypeHashes.push_back(modelTypeHash);
	m_Capabilities.AssetTypeHashes.push_back(meshTypeHash);
}

void harmony::AssimpModelAssetFactory::ProcessNode(const std::string& path, aiNode* node, const aiScene* scene)
{
	HARMONY_PROFILE_FUNCTION()
	if (node->mNumMeshes > 0)
	{
		for (unsigned int i = 0; i < node->mNumMeshes; i++)
		{
			unsigned int sceneIndex = node->mMeshes[i];
			aiMesh* mesh = scene->mMeshes[sceneIndex];
			ProcessMesh(path, mesh, node, scene);
		}
	}

	if (node->mNumChildren == 0)
	{
		return;
	}

	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		ProcessNode(path, node->mChildren[i], scene);
	}
}

void harmony::AssimpModelAssetFactory::ProcessMesh(const std::string& path, aiMesh* mesh, aiNode* node, const aiScene* scene)
{
	HARMONY_PROFILE_FUNCTION()
	Ref<Mesh> meshAsset = CreateRef<Mesh>(path, p_MeshCounter);
	p_MeshCounter++;
	bool hasPositions = mesh->HasPositions();
	bool hasIndices = mesh->HasFaces();
	bool hasNormals = mesh->HasNormals();
	bool hasUVs = mesh->HasTextureCoords(0);
	bool hasTangentsAndBitangents = false;

	std::vector<glm::vec3> positions;
	if (hasPositions)
	{
		for (unsigned int i = 0; i < mesh->mNumVertices; i++)
		{
			positions.push_back(AssimpToGLM(mesh->mVertices[i]));
		}

	}
	std::vector<unsigned int> indices;
	if (hasIndices)
	{
		for (unsigned int i = 0; i < mesh->mNumFaces; i++)
		{
			aiFace currentFace = mesh->mFaces[i];
			if(currentFace.mNumIndices != 3)
			{
				harmony::log::error("Attempting to import a mesh with non triangular face structure! cannot load this mesh.");
				return;
			}
			for (unsigned int index = 0; index < mesh->mFaces[i].mNumIndices; index++)
			{
				indices.push_back(mesh->mFaces[i].mIndices[index]);
			}
		}
	}

	std::vector<glm::vec3> normals;
	if (hasNormals)
	{
		for (unsigned int i = 0; i < mesh->mNumVertices; i++)
		{
			normals.push_back(AssimpToGLM(mesh->mNormals[i]));
		}
	}
	
	std::vector<glm::vec2> uvs;
	// TODO: Support additional sets of texture coords.
	if (hasUVs)
	{
		for (unsigned int i = 0; i < mesh->mNumVertices; i++)
		{
			uvs.emplace_back(AssimpToGLM(mesh->mTextureCoords[0][i]));
		}
	}

	/*std::vector<glm::vec3> tangents;
	std::vector<glm::vec3> bitangents;

	if (hasTangentsAndBitangents)
	{
		for (int i = 0; i < mesh->mNumVertices; i++)
		{
			tangents.emplace_back(AssimpToGLM(mesh->mTangents[i]));
			bitangents.emplace_back(AssimpToGLM(mesh->mBitangents[i]));
		}
	}*/

	if (hasPositions && hasIndices && !hasNormals && !hasUVs && !hasTangentsAndBitangents)
	{
		meshAsset->InitializeMesh(positions, indices);
	}
	else if (hasPositions && hasIndices && hasNormals && !hasUVs && !hasTangentsAndBitangents)
	{
		meshAsset->InitializeMesh(positions, indices, normals);
	}
	else if (hasPositions && hasIndices && hasNormals && hasUVs && !hasTangentsAndBitangents)
	{
		meshAsset->InitializeMesh(positions, indices, normals, uvs);
	}
	/*else if (hasPositions && hasIndices && hasNormals && hasUVs && hasTangentsAndBitangents)
	{
		meshAsset->InitializeMesh(positions, indices, normals, tangents, bitangents, uvs);
	}*/
	else
	{
		harmony::log::error("AssimpModelAssetFactory : Could not initialize mesh!");
	}

	p_Meshes.emplace_back(meshAsset);
	p_MeshNames.emplace_back(AssimpToSTD(mesh->mName));
}

void harmony::AssimpModelAssetFactory::UnloadAssetData(const std::string& path, entt::registry& registry)
{
	std::vector<entt::entity> entitiesToDestroy;

	auto meshView = registry.view<AssetComponent<Mesh>, AssetHandle>();

	for (auto [e, mesh, handle] : meshView.each())
	{
		if (handle.Path == path)
		{
			entitiesToDestroy.push_back(e);
		}
	}
	auto modelView = registry.view<AssetComponent<Model>, AssetHandle>();

	for (auto [e, mesh, handle] : modelView.each())
	{
		if (handle.Path == path)
		{
			entitiesToDestroy.push_back(e);
		}
	}

	for (int i = 0; i < entitiesToDestroy.size(); i++)
	{
		registry.destroy(entitiesToDestroy[i]);
	}
}


void harmony::AssimpModelAssetFactory::LoadAssetData(const std::string& path, entt::registry& registry)
{
	HARMONY_PROFILE_FUNCTION()

	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path,
		aiProcess_Triangulate |
		aiProcess_FlipUVs |
		aiProcess_CalcTangentSpace |
		aiProcess_GenSmoothNormals |
		aiProcess_OptimizeMeshes |
		aiProcess_OptimizeGraph |
		aiProcess_GenBoundingBoxes
	);
	//
	if (scene == nullptr)
	{
		harmony::log::error("AssimpModelAssetFactory : Failed to load asset at path : ", path);
		return;
	}
	//
	ProcessNode(path, scene->mRootNode, scene);
	std::string modelName = std::string(scene->mName.C_Str());
	Ref<Model> model = CreateRef<Model>(modelName); 
	AssetHandle handle{ path, 0, GetTypeHash<Model>() };

	for (int i = 0; i < p_Meshes.size(); i++)
	{
		Ref<Mesh> meshAsset = std::static_pointer_cast<Mesh, Asset>(p_Meshes[i]);
		
		p_Renderer.SubmitMeshToGPU(meshAsset);

		AssetHandle meshHandle{ path, i, GetTypeHash<Mesh>() };
		AssetComponent<Mesh> meshComponent{ meshAsset, meshHandle };
		entt::entity e = registry.create();
		registry.emplace<AssetComponent<Mesh>>(e, meshComponent);
		registry.emplace<AssetHandle>(e, meshHandle);

	}

	AssetComponent<Model> modelComponent{ model, handle };
	
	entt::entity e = registry.create();
	registry.emplace<AssetComponent<Model>>(e, modelComponent);
	registry.emplace<AssetHandle>(e, handle);
		
}

