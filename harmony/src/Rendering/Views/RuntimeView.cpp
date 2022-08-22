#include "Rendering/Views/RuntimeView.h"
#include "ECS/CameraComponent.h"
#include "Core/Program.h"
#if HARMONY_DEBUG
#include "ImGui/imgui_bgfx.h"
#include "ImGui/icons_font_awesome.h"
#endif
harmony::RuntimeView::RuntimeView(Program& prog) : View("RuntimeView"), p_Program(prog), p_Renderer(prog.m_Renderer)
{
	CameraEntity = (entt::entity)UINT32_MAX;
}

void harmony::RuntimeView::OnPreUpdate(entt::registry& registry)
{
	if (!registry.valid(CameraEntity))
	{
		return;
	}
	if (registry.any_of<CameraComponent>(CameraEntity))
	{
		CameraComponent& component = registry.get<CameraComponent>(CameraEntity);
		m_View = component.Cam.View;
		m_Projection = component.Cam.Projection;
	}
}
#if HARMONY_DEBUG
void harmony::RuntimeView::OnImGui()
{
	if (p_Program.GetActiveScene().expired())
	{
		return;
	}

	Ref<Scene> scene = p_Program.GetActiveScene().lock();

	const std::string runteimeViewTitle = std::string(ICON_FA_PLAY_CIRCLE) + " Runtime";
	glm::mat4 mat = glm::mat4(1.0);
	PipelineStack& stack = p_Renderer.GetViewPipelineStack("RuntimeView");
	if (ImGui::Begin(runteimeViewTitle.c_str()))
	{
		bgfx::TextureHandle finalImageHandle = stack.GetStackFinalImage();
		if (!bgfx::isValid(finalImageHandle))
		{
			ImGui::End();
			return;
		}
		ImGui::Image(
			finalImageHandle,
			ImVec2(static_cast<float>(m_Width), static_cast<float>(m_Height))
		);

	}
	ImGui::End();
}


void harmony::RuntimeView::OnImGuiOptions()
{
	if (p_Program.GetActiveScene().expired())
	{
		return;
	}

	Ref<Scene> scene = p_Program.GetActiveScene().lock();
	std::string currentName = "Entity " + std::to_string(static_cast<uint32_t>(CameraEntity));
	if (ImGui::BeginCombo("Camera Entity", currentName.c_str()))
	{
		auto view = scene->m_Registry.view<CameraComponent>();

		for (auto& [entity, camera] : view.each())
		{
			std::string name = "Entity " + std::to_string(static_cast<uint32_t>(entity));
			if (ImGui::Selectable(name.c_str()))
			{
				CameraEntity = entity;
			}
		}

		ImGui::EndCombo();
	}
}
#endif