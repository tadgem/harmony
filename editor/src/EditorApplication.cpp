#include "EditorApplication.h"
#include "Rendering/Model.h"
#include "Rendering/Mesh.h"
#include "Rendering/Texture.h"
#include "Assets/TextureAssetFactory.h"
#include "AssimpModelAssetFactory.h"

harmony::Editor::Editor() : harmony::Program("Harmony Editor")
{
	m_AssetManager.AddAssetTypeName<Mesh>();
	m_AssetManager.AddAssetTypeName<Model>();
	m_AssetManager.AddAssetTypeName<Texture>();

	m_AssetManager.AddAssetFactory(CreateRef<TextureAssetFactory>());
	m_AssetManager.AddAssetFactory(CreateRef<AssimpModelAssetFactory>());

}