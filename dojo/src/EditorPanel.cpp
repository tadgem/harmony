#include "EditorPanel.h"
#include "ECS/TransformComponent.h";

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

		ImGui::Separator();
		activeScene->m_Registry.each([](entt::entity e)
		{
			ImGui::Text("", e);
		});

	}
	ImGui::End();
}

harmony::EntityInspectorPanel::EntityInspectorPanel(Program& prog) : p_Prog(prog)
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

		for (int i = 0; i < p_ComponentUIProviders.size(); i++)
		{
			p_ComponentUIProviders[i]->OnComponentImGui(activeScene->m_Registry, m_SelectedEntity);
		}
	}
	ImGui::End();
}

harmony::TransformComponentUI::TransformComponentUI()
{
}

void harmony::TransformComponentUI::OnComponentImGui(entt::registry& registry, entt::entity entity)
{
	if (registry.valid(entity) == false)
	{
		return;
	}
	if (registry.all_of<TransformComponent>(entity) == false)
	{
		return;
	}
	const int _MAX = 1000000;
	TransformComponent& t = registry.get<TransformComponent>(entity);
	ImGui::Text("Transform;");
	ImGui::Separator();
	ImGui::SliderFloat3("Position", &t.Position[0], -_MAX, _MAX, "", 0.01f);
	ImGui::SliderFloat3("Rotation", &t.Euler[0], -180, 180, "", 0.01f);
	ImGui::SliderFloat3("Scale", &t.Scale[0], -_MAX, _MAX, "", 0.01f);
}
