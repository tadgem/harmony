#include "EditorPanel.h"
#include "EditorUtils.h"
#include "ECS/TransformComponent.h";
#include "ECS/MeshComponent.h";
#include "ECS/MaterialComponent.h";
#include "ECS/LightComponents.h";
#include "Rendering/Model.h"
#include "ImGui/icons_font_awesome.h"
#include "ImGui/ImGuiFileDialog.h"
#include "Assets/ShaderSourceAsset.h"
#include "ECS/CameraComponent.h"
harmony::ScenePanel::ScenePanel(Program& program) : p_Prog(program)
{
}

void harmony::ScenePanel::OnImGui()
{
	const std::string  scenePanelTitle = std::string(ICON_FA_GLOBE) + " Scene";
	if (ImGui::Begin(scenePanelTitle.c_str()))
	{
		auto activeSceneWr = p_Prog.GetActiveScene();

		if (activeSceneWr.expired())
		{
			ImGui::End();
			return;
		}

		Ref<Scene> activeScene = activeSceneWr.lock();

		if (ImGui::Button("Add Entity"))
		{
			activeScene->AddEntity();
		}
		const std::string entityNamePrefix = "Entity ";
		ImGui::Separator();
		activeScene->m_Registry.each([&](entt::entity e)
		{
			std::string entityName = entityNamePrefix + std::to_string(static_cast<uint32_t>(e));
			if (ImGui::Selectable(entityName.c_str()))
			{
				m_SelectedEntity = e;
			}
		});

	}
	ImGui::End();
}

harmony::EntityInspectorPanel::EntityInspectorPanel(Program& prog, Ref<ScenePanel> scenePanel) : p_Prog(prog), p_ScenePanel(scenePanel)
{
}

void harmony::EntityInspectorPanel::OnImGui()
{
	const std::string  entityInspectorTitle = std::string(ICON_FA_INFO_CIRCLE) + " Inspector";
	if (ImGui::Begin(entityInspectorTitle.c_str()))
	{
		auto activeSceneWr = p_Prog.GetActiveScene();

		if (activeSceneWr.expired())
		{
			ImGui::End();
			return;
		}

		Ref<Scene> activeScene = activeSceneWr.lock();

		if (activeScene->m_Registry.valid(p_ScenePanel->m_SelectedEntity) == false)
		{
			ImGui::End();
			return;
		}

		if (p_ComponentUIProviders.size() == 0)
		{
			ImGui::End();
			return;
		}

		for (int i = 0; i < p_ComponentUIProviders.size(); i++)
		{
			if (!p_ComponentUIProviders[i]->HasComponent(activeScene->m_Registry, p_ScenePanel->m_SelectedEntity))
			{
				continue;
			}
			if (ImGui::TreeNode(p_ComponentUIProviders[i]->GetComponentName().c_str()))
			{
				p_ComponentUIProviders[i]->OnComponentImGui(activeScene->m_Registry, p_ScenePanel->m_SelectedEntity);
				ImGui::TreePop();
			}
			ImGui::Separator();
		}
		ImGui::Separator();
		if (ImGui::BeginCombo("Add Component", ICON_FA_PLUS_CIRCLE))
		{
			for (int i = 0; i < p_ComponentUIProviders.size(); i++)
			{
				//p_ComponentUIProviders[i]->OnComponentImGui(activeScene->m_Registry, p_ScenePanel->m_SelectedEntity);
				if (ImGui::Selectable(p_ComponentUIProviders[i]->GetComponentName().c_str()))
				{
					p_ComponentUIProviders[i]->AddComponent(activeScene->m_Registry, p_ScenePanel->m_SelectedEntity);
				}
			}
			ImGui::EndCombo();
		}
		
	}
	ImGui::End();
}

harmony::TransformComponentUI::TransformComponentUI() : ComponentUI("Transform")
{
}

void harmony::TransformComponentUI::OnComponentImGui(entt::registry& registry, entt::entity entity)
{
	if (registry.valid(entity) == false)
	{
		return;
	}
	if (RegistryHasComponent<TransformComponent>(registry, entity) == false)
	{
		return;
	}
	const int _MAX = 1000;
	TransformComponent& t = registry.get<TransformComponent>(entity);
	ImGui::DragFloat3("Position", &t.Position[0]);
	ImGui::DragFloat3("Rotation", &t.Euler[0]);
	ImGui::DragFloat3("Scale", &t.Scale[0]);
}

void harmony::TransformComponentUI::AddComponent(entt::registry& registry, entt::entity entity)
{
	registry.emplace<TransformComponent>(entity);
}

bool harmony::TransformComponentUI::HasComponent(entt::registry& registry, entt::entity entity)
{
	return RegistryHasComponent<TransformComponent>(registry, entity);
}

harmony::ComponentUI::ComponentUI(const std::string name): p_ComponentName(name)
{
}

const std::string& harmony::ComponentUI::GetComponentName()
{
	return p_ComponentName;
}

harmony::MeshComponentUI::MeshComponentUI(AssetManager& am) : ComponentUI("Mesh"), p_AssetManager(am)
{
}

void harmony::MeshComponentUI::OnComponentImGui(entt::registry& registry, entt::entity entity)
{
	if (registry.valid(entity) == false)
	{
		return;
	}
	if (RegistryHasComponent<MeshComponent>(registry, entity) == false)
	{
		return;
	}
	AssetHandle ah;
	MeshComponent& mc = registry.get<MeshComponent>(entity);
	std::string meshPath = "Mesh Asset: " + mc.MeshAsset.Path;
	ImGui::Text(meshPath.c_str());
	if (p_AssetManager.AssetTypeSelector<Mesh>("Mesh", ah))
	{
		mc.MeshAsset = ah;
		harmony::log::info("Entity {} updated mesh to handle at path : {}", static_cast<uint32_t>(entity), mc.MeshAsset.Path);
	}

	if (ImGui::RadioButton("Cast Shadow", &mc.CastShadow))
	{
		mc.CastShadow = !mc.CastShadow;
	}
}

void harmony::MeshComponentUI::AddComponent(entt::registry& registry, entt::entity entity)
{
	registry.emplace<MeshComponent>(entity);
}

bool harmony::MeshComponentUI::HasComponent(entt::registry& registry, entt::entity entity)
{
	return RegistryHasComponent<MeshComponent>(registry, entity);
}

harmony::MaterialComponentUI::MaterialComponentUI(Renderer& r, AssetManager& am) : ComponentUI("Material"), p_Renderer(r), p_AssetManager(am)
{
}

void harmony::MaterialComponentUI::OnComponentImGui(entt::registry& registry, entt::entity entity)
{
	if (registry.valid(entity) == false)
	{
		return;
	}
	if (RegistryHasComponent<MaterialComponent>(registry, entity) == false)
	{
		return;
	}
	MaterialComponent& mc = registry.get<MaterialComponent>(entity);
	WeakRef<ShaderProgram> shaderWr = p_Renderer.GetShader(mc.Data.m_ShaderName);
	std::string sn = "Shader Name : ";
	
	if (shaderWr.expired() == false)
	{
		Ref<ShaderProgram> shader = shaderWr.lock();
		sn += shader->m_Name;
	}

	ImGui::Text(sn.c_str());
	ImGui::Separator();
	if (p_Renderer.ShaderSelector("Select Shader", shaderWr))
	{
		mc.Data.UpdateContainer(shaderWr, p_AssetManager);
	}
	ImGui::Text("Shader Variables");
	if (ImGui::TreeNode("Data"))
	{
		ImGui::Text("Vec4");
		for (auto& [key, v] : mc.Data.m_Vec4Overrides)
		{
			ImGui::DragFloat4(key.Name.c_str(), &v[0]);
		}
		ImGui::Separator();
		ImGui::Text("Textures");
		for (auto& [key, handle] : mc.Data.m_TextureOverrides)
		{
			std::string textureName = "Tex : " + handle.Handle.Path;
			ImGui::Text(textureName.c_str());
			if (p_AssetManager.AssetTypeSelector<Texture>(key.Name, handle.Handle))
			{
				WeakRef<Texture> texWr = p_AssetManager.GetAsset<Texture>(handle.Handle);
				Ref<Texture> tex = texWr.lock();
				handle.BgfxHandle = tex->m_TextureHandle.BgfxHandle;
			}
		}
		ImGui::Separator();
		ImGui::Text("Mat3");
		for (auto& [key, v] : mc.Data.m_Mat3Overrides)
		{
			ImGui::Text(key.Name.c_str());
		}
		ImGui::Separator();
		ImGui::Text("Mat4");
		for (auto& [key, v] : mc.Data.m_Mat4Overrides)
		{
			ImGui::Text(key.Name.c_str());
		}
		ImGui::Separator();

		ImGui::TreePop();
	}
}

void harmony::MaterialComponentUI::AddComponent(entt::registry& registry, entt::entity entity)
{
	registry.emplace<MaterialComponent>(entity);
}

bool harmony::MaterialComponentUI::HasComponent(entt::registry& registry, entt::entity entity)
{
	return RegistryHasComponent<MaterialComponent>(registry, entity);
}

harmony::AssetManagerPanel::AssetManagerPanel(Program& program) : p_Prog(program), p_AssetManager(program.m_AssetManager)
{
}

void harmony::AssetManagerPanel::OnImGui()
{
	const std::string  assetPanelTitle = std::string(ICON_FA_FOLDER) + " Assets";

	if (ImGui::Begin(assetPanelTitle.c_str()))
	{
		ImGui::Indent();
		const std::string textureAssetTitle = std::string(ICON_FA_FILE_IMAGE_O) + " Textures";
		ImGui::Text(textureAssetTitle.c_str());
		std::vector<AssetHandle> texHandles = p_AssetManager.GetLoadedAssets<Texture>();
		if (ImGui::TreeNode("Textures")) {
			for (int i = 0; i < texHandles.size(); i++)
			{
				ImGui::Text(texHandles[i].Path.c_str());
			}
			ImGui::TreePop();

			if (ImGui::Button("Load Texture"))
			{
				ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenAsset", "Choose Asset", ".png,.jpg", ".");
				p_SelectedTypeHash = GetTypeHash<Texture>();
			}
		}

		ImGui::Separator();
		const std::string meshAssetTitle = std::string(ICON_FA_CUBE) + " Meshes";
		ImGui::Text(meshAssetTitle.c_str());
		std::vector<AssetHandle> meshHandles = p_AssetManager.GetLoadedAssets<Mesh>();
		if (ImGui::TreeNode("Meshes")) {
			for (int i = 0; i < meshHandles.size(); i++)
			{
				ImGui::Text(meshHandles[i].Path.c_str());
			}
			ImGui::TreePop();
			if (ImGui::Button("Load Mesh/Model"))
			{
				ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenAsset", "Choose Model", ".fbx,.obj,.dae,.gltf,.blend", ".");
				p_SelectedTypeHash = GetTypeHash<Model>();
			}
		}

		ImGui::Separator();
		const std::string shaderSouceAssetTitle = std::string(ICON_FA_FILE_TEXT_O) + " Shader Source";
		ImGui::Text(shaderSouceAssetTitle.c_str());
		std::vector<AssetHandle> sourceHandles = p_AssetManager.GetLoadedAssets<ShaderSourceAsset>();
		if (ImGui::TreeNode("Shader Sources")) {
			for (int i = 0; i < sourceHandles.size(); i++)
			{
				ImGui::Text(sourceHandles[i].Path.c_str());
			}
			ImGui::TreePop();
			if (ImGui::Button("Load Shader Source"))
			{
				ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenAsset", "Choose Source", ".sc,.sh", ".");
				p_SelectedTypeHash = GetTypeHash<ShaderSourceAsset>();
			}
		}

		ImGui::Separator();
		const std::string shaderBinariesAssetTitle = std::string(ICON_FA_FILE_ARCHIVE_O) + " Shader Binaries";
		ImGui::Text(shaderBinariesAssetTitle.c_str());
		std::vector<AssetHandle> stageHandles = p_AssetManager.GetLoadedAssets<ShaderStage>();
		if (ImGui::TreeNode("Shader Binaries")) {
			for (int i = 0; i < stageHandles.size(); i++)
			{
				ImGui::Text(stageHandles[i].Path.c_str());
			}
			ImGui::TreePop();
		}
		ImGui::Unindent();
	}
	ImGui::End();

	if (ImGuiFileDialog::Instance()->Display("HarmonyOpenAsset"))
	{
		// action if OK
		if (ImGuiFileDialog::Instance()->IsOk())
		{
			std::string filepath = ImGuiFileDialog::Instance()->GetFilePathName();
			p_AssetManager.LoadAsset(filepath, p_SelectedTypeHash);
		}
		ImGuiFileDialog::Instance()->Close();
	}
}

harmony::CameraComponentUI::CameraComponentUI(Renderer& r) : ComponentUI("Camera"), p_Renderer(r)
{
}

void harmony::CameraComponentUI::OnComponentImGui(entt::registry& registry, entt::entity entity)
{
	if (registry.valid(entity) == false)
	{
		return;
	}
	if (RegistryHasComponent<CameraComponent>(registry, entity) == false)
	{
		return;
	}

	CameraComponent& c = registry.get<CameraComponent>(entity);
	ImGui::DragFloat("Aspect", &c.Cam.Aspect);
	ImGui::DragFloat("FOV", &c.Cam.FOV);
	ImGui::DragFloat("Near Clip Plane", &c.Cam.NearClipPlane);
	ImGui::DragFloat("Far Clip Plane", &c.Cam.FarClipPlane);
}

void harmony::CameraComponentUI::AddComponent(entt::registry& registry, entt::entity entity)
{
	registry.emplace<CameraComponent>(entity);
}

bool harmony::CameraComponentUI::HasComponent(entt::registry& registry, entt::entity entity)
{
	return RegistryHasComponent<CameraComponent>(registry, entity);
}

harmony::DirectionalLightComponentUI::DirectionalLightComponentUI() : ComponentUI("Directional Light")
{
}

void harmony::DirectionalLightComponentUI::OnComponentImGui(entt::registry& registry, entt::entity entity)
{
	if (registry.valid(entity) == false)
	{
		return;
	}
	if (RegistryHasComponent<DirectionalLight>(registry, entity) == false)
	{
		return;
	}

	DirectionalLight& dl	= registry.get<DirectionalLight>(entity);

	ImGui::ColorEdit4("Diffuse", &dl .Diffuse[0]);
	ImGui::ColorEdit4("Ambient", &dl.Ambient[0]);
}

void harmony::DirectionalLightComponentUI::AddComponent(entt::registry& registry, entt::entity entity)
{
	registry.emplace<DirectionalLight>(entity);
}

bool harmony::DirectionalLightComponentUI::HasComponent(entt::registry& registry, entt::entity entity)
{
	return registry.any_of<DirectionalLight>(entity);
}

harmony::PointLightComponentUI::PointLightComponentUI() : ComponentUI("Point Light")
{
}

void harmony::PointLightComponentUI::OnComponentImGui(entt::registry& registry, entt::entity entity)
{
	if (registry.valid(entity) == false)
	{
		return;
	}
	if (RegistryHasComponent<PointLight>(registry, entity) == false)
	{
		return;
	}

	PointLight& pl = registry.get<PointLight>(entity);

	ImGui::ColorEdit4("Diffuse", &pl.Diffuse[0]);
	ImGui::ColorEdit4("Ambient", &pl.Ambient[0]);
	ImGui::SliderFloat("Range", &pl.Radius, 0.0f, 5000.0f);
}

void harmony::PointLightComponentUI::AddComponent(entt::registry& registry, entt::entity entity)
{
	registry.emplace<PointLight>(entity);
}

bool harmony::PointLightComponentUI::HasComponent(entt::registry& registry, entt::entity entity)
{
	return registry.any_of<PointLight>(entity);
}

harmony::SpotLightComponentUI::SpotLightComponentUI() : ComponentUI("Spot Light")
{
}

void harmony::SpotLightComponentUI::OnComponentImGui(entt::registry& registry, entt::entity entity)
{
	if (registry.valid(entity) == false)
	{
		return;
	}
	if (RegistryHasComponent<SpotLight>(registry, entity) == false)
	{
		return;
	}

	SpotLight& sl = registry.get<SpotLight>(entity);

	ImGui::ColorEdit4("Diffuse", &sl.Diffuse[0]);
	ImGui::ColorEdit4("Ambient", &sl.Ambient[0]);
	ImGui::SliderFloat("Range", &sl.Radius, 0.0f, 5000.0f);
	ImGui::SliderFloat("Angle", &sl.Angle, 0.0f, 360.0f);
}

void harmony::SpotLightComponentUI::AddComponent(entt::registry& registry, entt::entity entity)
{
	registry.emplace<SpotLight>(entity);
}

bool harmony::SpotLightComponentUI::HasComponent(entt::registry& registry, entt::entity entity)
{
	return registry.any_of<SpotLight>(entity);
}