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
void harmony::RuntimeView::OnResized(uint32_t w, uint32_t h)
{
	View::OnResized(w, h);
	if (p_Program.GetActiveScene().expired())
	{
		return;
	}

	Ref<Scene> scene = p_Program.GetActiveScene().lock();

	if (scene->m_Registry.any_of<CameraComponent>(CameraEntity))
	{
		CameraComponent& c = scene->m_Registry.get<CameraComponent>(CameraEntity);
		if (m_ProjectionType == ProjectionType::Perspective)
		{
			c.Cam.Projection = glm::mat4(1.0);
			c.Cam.Projection = glm::perspectiveFov(glm::radians(c.Cam.FOV), static_cast<float>(m_Width), static_cast<float>(m_Height), c.Cam.NearClipPlane, c.Cam.FarClipPlane);
		}
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

	const std::string runtimeViewTitle = std::string(ICON_FA_PLAY_CIRCLE) + " Runtime";
	glm::mat4 mat = glm::mat4(1.0);
	PipelineStack& stack = p_Renderer.GetViewPipelineStack("RuntimeView");
	if (ImGui::Begin(runtimeViewTitle.c_str(), (bool*)0, ImGuiWindowFlags_NoScrollbar))
	{
		View::OnImGui();
		bgfx::TextureHandle finalImageHandle = stack.GetFinalImage();
		if (!bgfx::isValid(finalImageHandle))
		{
			ImGui::End();
			return;
		}
		ImGui::Image(
			finalImageHandle,
			ImGui::GetContentRegionAvail()
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

		for (auto [entity, camera] : view.each())
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
nlohmann::json harmony::RuntimeView::Serialize()
{
	nlohmann::json j = View::Serialize();
	j["entity"] = CameraEntity;
	return j;
}
void harmony::RuntimeView::Deserialize(nlohmann::json& json)
{
	View::Deserialize(json);
	CameraEntity = json["entity"];

}
#endif