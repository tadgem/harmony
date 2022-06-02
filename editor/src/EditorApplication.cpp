#include "EditorApplication.h"
#include "Rendering/Model.h"
#include "Rendering/Mesh.h"
#include "Rendering/Texture.h"
harmony::Editor::Editor() : harmony::Program("Harmony Editor")
{
	m_AssetManager.AddAssetTypeName<Mesh>();
	m_AssetManager.AddAssetTypeName<Model>();
	m_AssetManager.AddAssetTypeName<Texture>();

}