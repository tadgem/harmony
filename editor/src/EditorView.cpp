#include "EditorView.h"
#include "Core/MathsUtils.h"
#include "Core/Log.hpp"
#if HARMONY_DEBUG
#include "ImGui/imgui.h"
#include "ImGui/imgui_bgfx.h"
#endif
harmony::DebugCamera::DebugCamera()
{
	Position = glm::vec3(0.0f, 10.0f, 0.0f);
	Euler = glm::vec3(-20.0f, 0.0f, 0.0f);
	FOV = 80.0f;
	Near = 0.1f;
	Far = 300.0f;
	Type = ProjectionType::Perspective;
}

void harmony::DebugCamera::Update()
{
	if (Active)
	{
	}
}

glm::mat4 harmony::DebugCamera::GetViewMatrix()
{
	glm::vec3 forward = MathsUtils::CalculateForwardVector(Euler);
	glm::vec3 right = MathsUtils::CalculateRightVector(Euler);
	glm::vec3 up = MathsUtils::CalculateUpVector(forward, right);
	glm::mat4 viewMatrix = glm::lookAt(Position, Position + forward, up);
	return viewMatrix;
}

glm::mat4 harmony::DebugCamera::GetProjectionMatrix(uint32_t width, uint32_t height)
{
	glm::mat4 projMatrix = glm::mat4(1.0);

	projMatrix = glm::perspectiveFov(glm::radians(FOV), static_cast<float>(width), static_cast<float>(height), Near, Far);

	return projMatrix;
}

harmony::EditorView::EditorView() : View("Editor")
{
}

void harmony::EditorView::OnPreUpdate(entt::registry& registry)
{
	Camera.Update();
	m_View = Camera.GetViewMatrix();
	m_Projection = Camera.GetProjectionMatrix(m_Width, m_Height);
}

void harmony::EditorView::OnImGui()
{
	ImGui::SliderFloat3("Camera Position", &Camera.Position[0], -180.0f, 180.0f);
	ImGui::SliderFloat3("Camera Rotation", &Camera.Euler[0], -180.0f, 180.0f);
}
