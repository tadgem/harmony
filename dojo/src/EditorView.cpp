#include "EditorView.h"
#include "Core/MathsUtils.h"
#include "Core/Log.hpp"
#include "Core/Time.h"
#if HARMONY_DEBUG
#include "ImGui/imgui.h"
#include "ImGui/imgui_bgfx.h"
#include "ImGui/icons_font_awesome.h"
#endif

#include "Core/Input.h"
#include "SDL.h"
harmony::DebugCamera::DebugCamera()
{
	Position = glm::vec3(0.0f, 10.0f, 0.0f);
	Euler = glm::vec3(0.0f, 0.0f, 0.0f);
	FOV = 80.0f;
	Near = 0.1f;
	Far = 300.0f;
	Speed = 10.0f;
	Type = ProjectionType::Perspective;
	Focussed = false;
}

void harmony::DebugCamera::Update()
{
	
	if (Focussed)
	{
		if (Input::Get()->GetMouseButton(Mouse::Button::Right))
		{
			ImGui::SetMouseCursor(ImGuiMouseCursor_None);
			SDL_ShowCursor(SDL_DISABLE);
			
			if (Input::Get()->GetKey(Key::W))
			{
				Position += MathsUtils::CalculateForwardVector(Rotation) * (float)Time::GetFrameTime() * Speed;
			}
			if (Input::Get()->GetKey(Key::S))
			{
				Position -= MathsUtils::CalculateForwardVector(Rotation) * (float)Time::GetFrameTime() * Speed;
			}
			if (Input::Get()->GetKey(Key::A))
			{
				Position -= MathsUtils::CalculateRightVector(Rotation) * (float)Time::GetFrameTime() * Speed;
			}
			if (Input::Get()->GetKey(Key::D))
			{
				Position += MathsUtils::CalculateRightVector(Rotation) * (float)Time::GetFrameTime() * Speed;
			}
			if (Input::Get()->GetKey(Key::Q))
			{
				Position -= MathsUtils::CalculateUpVector(Rotation) * (float)Time::GetFrameTime() * Speed;
			}
			if (Input::Get()->GetKey(Key::E))
			{
				Position += MathsUtils::CalculateUpVector(Rotation) * (float)Time::GetFrameTime() * Speed;
			}

			glm::vec2 mouseVelocity = Input::Get()->GetMouseVelocity();
			
			float magnitude = glm::length(mouseVelocity);

			if (magnitude > 0.0015f)
			{
				Euler.x -= mouseVelocity.y * Time::GetFrameTime() * 180.0f * 180.0f;
				Euler.y += mouseVelocity.x * Time::GetFrameTime() * 180.0f * 180.0f;
			}
		}
	
	}
	if (Euler.x < -90.0f)
	{
		Euler.x = -90.0f;
	}
	if (Euler.x > 90.0f)
	{
		Euler.x = 90.0f;
	}
	if (Euler.y < -180.0f)
	{
		Euler.y += 360.0f;
	}
	if (Euler.y > 180.0f)
	{
		Euler.y -= 360.0f;
	}
}

glm::mat4 harmony::DebugCamera::GetViewMatrix()
{
	glm::quat qPitch = glm::angleAxis(glm::radians(-Euler.x), glm::vec3(1, 0, 0));
	glm::quat qYaw = glm::angleAxis(glm::radians(Euler.y), glm::vec3(0, 1, 0));
	// omit roll
	Rotation = qPitch * qYaw;
	Rotation = glm::normalize(Rotation);
	glm::mat4 rotate = glm::mat4_cast(Rotation);
	glm::mat4 translate = glm::mat4(1.0f);
	translate = glm::translate(translate, -Position);

	return rotate * translate;
}

glm::mat4 harmony::DebugCamera::GetProjectionMatrix(uint32_t width, uint32_t height)
{
	glm::mat4 projMatrix = glm::mat4(1.0);

	projMatrix = glm::perspectiveFov(glm::radians(FOV), static_cast<float>(width), static_cast<float>(height), Near, Far);

	return projMatrix;
}

harmony::EditorView::EditorView(Renderer& renderer) : View("Editor"), p_Renderer(renderer)
{
}

void harmony::EditorView::OnPreUpdate(entt::registry& registry)
{
	Camera.Update();
	m_View = Camera.GetViewMatrix();
	m_Projection = Camera.GetProjectionMatrix(m_Width, m_Height);
}
#if HARMONY_DEBUG
void harmony::EditorView::OnImGui()
{
	const std::string editorViewTitle = std::string(ICON_FA_VIDEO_CAMERA) + " Editor";

	PipelineStack& stack = p_Renderer.GetViewPipelineStack("Editor");
	if (ImGui::Begin(editorViewTitle.c_str()))
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

		if (ImGui::IsWindowFocused())
		{
			Camera.Focussed = true;
		}
	}
	ImGui::End();
}

void harmony::EditorView::OnImGuiOptions()
{
	ImGui::DragFloat3("Camera Position", &Camera.Position[0], -50.0f, 50.0f);
	ImGui::DragFloat3("Camera Rotation", &Camera.Euler[0], -180.0f, 180.0f);

}
#endif