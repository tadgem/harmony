#include "Rendering/GLTFModelAssetFactory.h"
#include "tiny_gltf.h"
#include "Core/Log.hpp"

harmony::GLTFModelAssetFactory::GLTFModelAssetFactory() : AssetFactory(typeid(Model).hash_code())
{

}

std::unordered_map<size_t, std::vector<harmony::Ref<harmony::Asset>>> harmony::GLTFModelAssetFactory::CreateAssetData(const std::string& path)
{
	auto assets = std::unordered_map<size_t, std::vector<Ref<Asset>>>();
	tinygltf::TinyGLTF loader;
	tinygltf::Model model;
	std::string err;
	std::string warn;

	bool res = loader.LoadASCIIFromFile(&model, &err, &warn, path);
	if (!warn.empty()) {
		harmony::log::warn("GLTFModelAssetFactory : ", warn);
	}

	if (!err.empty()) {
		harmony::log::error("GLTFModelAssetFactory : ", err);
	}

	if (!res)
	{
		harmony::log::error("GLTFModelAssetFactory : Failed to load model at path : ", path);
		return assets;
	}
	
	harmony::log::info("Loaded GLTF Model from path: ", path);
	

	return assets;
}
