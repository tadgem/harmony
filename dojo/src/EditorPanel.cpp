#include "EditorPanel.h"
#include "EditorUtils.h"
#include "ECS/TransformComponent.h";
#include "ECS/MeshComponent.h";
#include "ECS/MaterialComponent.h";
#include "ImGui/icons_font_awesome.h"
harmony::ScenePanel::ScenePanel(Program& program) : p_Prog(program)
{
}

void harmony::ScenePanel::OnImGui()
{
	if (ImGui::Begin("Scene Inspector"))
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
	if (ImGui::Begin("Entity Inspector"))
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
	if (AssetTypeSelector<Mesh>("Mesh", p_AssetManager, ah))
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

harmony::MaterialComponentUI::MaterialComponentUI(Renderer& r) : ComponentUI("Material"), p_Renderer(r)
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
	WeakRef<ShaderProgram> shaderWr = mc.Data.m_Shader;
	std::string sn = "Shader Name : ";
	
	if (shaderWr.expired() == false)
	{
		Ref<ShaderProgram> shader = shaderWr.lock();
		sn += shader->m_Name;
	}

	ImGui::Text(sn.c_str());
	if (ShaderSelector("Select Shader", p_Renderer, shaderWr))
	{
		mc.Data.UpdateShader(shaderWr);
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
