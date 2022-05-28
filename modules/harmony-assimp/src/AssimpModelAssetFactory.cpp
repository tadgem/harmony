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

harmony::AssimpModelAssetFactory::AssimpModelAssetFactory() : harmony::AssetFactory(GetTypeHash<Model>())
{
}

std::unordered_map<size_t, std::vector<harmony::Ref<harmony::Asset>>> harmony::AssimpModelAssetFactory::CreateAssetData(const std::string& path)
{
    auto assets = std::unordered_map<size_t, std::vector<Ref<Asset>>>();

    Assimp::Importer importer;
    // importer.ReadFile()
	const aiScene* scene = importer.ReadFile(path,
		aiProcess_Triangulate |
		aiProcess_FlipUVs |
		aiProcess_CalcTangentSpace |
		aiProcess_GenSmoothNormals |
		aiProcess_OptimizeMeshes |
		aiProcess_OptimizeGraph |
		aiProcess_GenBoundingBoxes);
    return assets;

	ProcessNode(scene->mRootNode, scene);
}

void harmony::AssimpModelAssetFactory::ProcessNode(aiNode* node, const aiScene* scene)
{
	if (node->mNumMeshes > 0)
	{
		for (int i = 0; i < node->mNumMeshes; i++)
		{
			unsigned int sceneIndex = node->mMeshes[i];
			aiMesh* mesh = scene->mMeshes[sceneIndex];
			ProcessMesh(mesh, node, scene);
		}
	}

	if (node->mNumChildren == 0)
	{
		return;
	}

	for (int i = 0; i < node->mNumChildren; i++)
	{
		ProcessNode(node->mChildren[i], scene);
	}
}

void harmony::AssimpModelAssetFactory::ProcessMesh(aiMesh* mesh, aiNode* node, const aiScene* scene)
{
	Ref<Mesh> meshAsset = CreateRef<Mesh>();

	bool hasPositions = mesh->HasPositions();
	bool hasIndices = mesh->HasFaces();
	bool hasNormals = mesh->HasNormals();
	bool hasUVs = mesh->HasTextureCoords(0);
	bool hasTangentsAndBitangents = mesh->HasTangentsAndBitangents();

	std::vector<glm::vec3> positions;
	if (hasPositions)
	{
		for (int i = 0; i < mesh->mNumVertices; i++)
		{
			positions.push_back(AssimpToGLM(mesh->mVertices[i]));
		}

	}
	std::vector<unsigned int> indices;
	if (hasIndices)
	{
		for (int i = 0; i < mesh->mNumFaces; i++)
		{
			if(mesh->mFaces[i].mNumIndices != 3);
			{
				harmony::log::error("Attempting to import a mesh with non triangular face structure! cannot load this mesh.");
				return;
			}
			for (int index = 0; index < mesh->mFaces[i].mNumIndices; index++)
			{
				indices.push_back(mesh->mFaces[i].mIndices[index]);
			}
		}
	}

	std::vector<glm::vec3> normals;
	if (hasNormals)
	{
		for (int i = 0; i < mesh->mNumVertices; i++)
		{
			normals.push_back(AssimpToGLM(mesh->mNormals[i]));
		}
	}
	
	std::vector<glm::vec2> uvs;
	// TODO: Support additional sets of texture coords.
	if (hasUVs)
	{
		for (int i = 0; i < mesh->mNumVertices; i++)
		{
			uvs.emplace_back(AssimpToGLM(mesh->mTextureCoords[0][i]));
		}
	}

	std::vector<glm::vec3> tangents;
	std::vector<glm::vec3> bitangents;

	if (hasTangentsAndBitangents)
	{
		for (int i = 0; i < mesh->mNumVertices; i++)
		{
			tangents.emplace_back(AssimpToGLM(mesh->mTangents[i]));
			bitangents.emplace_back(AssimpToGLM(mesh->mBitangents[i]));
		}
	}

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
	else if (hasPositions && hasIndices && hasNormals && hasUVs && hasTangentsAndBitangents)
	{
		meshAsset->InitializeMesh(positions, indices, normals, tangents, bitangents, uvs);
	}
	else
	{
		harmony::log::error("AssimpModelAssetFactory : Could not initialize mesh!");
	}

}

