#include "EditorView.h"
#include "Core/MathsUtils.h"
#include "Core/Log.hpp"
#include "Core/Time.h"
#include "ECS/TransformComponent.h"
#if HARMONY_DEBUG
#include "ImGui/imgui.h"
#include "ImGui/imgui_bgfx.h"
#include "ImGui/ImGuizmo.h"
#include "ImGui/icons_font_awesome.h"
#endif

#include "Core/Input.h"
#include "SDL.h"
harmony::DebugCamera::DebugCamera()
{
	Position = glm::vec3(0.0f, 10.0f, 0.0f);
	Euler = glm::vec3(0.0f, 0.0f, 0.0f);
	FOV = 80.0f;
	NearClipPlane = 0.1f;
	FarClipPlane = 300.0f;
	Speed = 10.0f;
	Type = ProjectionType::Perspective;
	Focussed = false;
	ShowCursor = true;
}

void harmony::DebugCamera::UpdateProjection(glm::mat4 projection)
{
	Projection = projection;
}

void harmony::DebugCamera::Update()
{
	
	if (Focussed)
	{
		if (Input::GetMouseButton(Mouse::Button::Right))
		{
			if (ShowCursor)
			{
				SDL_SetRelativeMouseMode(SDL_TRUE);
				ShowCursor = false;
			}
			if (Input::GetKey(Key::W))
			{
				Position += MathsUtils::CalculateForwardVector(Rotation) * (float)Time::GetFrameTime() * Speed;
			}
			if (Input::GetKey(Key::S))
			{
				Position -= MathsUtils::CalculateForwardVector(Rotation) * (float)Time::GetFrameTime() * Speed;
			}
			if (Input::GetKey(Key::A))
			{
				Position -= MathsUtils::CalculateRightVector(Rotation) * (float)Time::GetFrameTime() * Speed;
			}
			if (Input::GetKey(Key::D))
			{
				Position += MathsUtils::CalculateRightVector(Rotation) * (float)Time::GetFrameTime() * Speed;
			}
			if (Input::GetKey(Key::Q))
			{
				Position -= MathsUtils::CalculateUpVector(Rotation) * (float)Time::GetFrameTime() * Speed;
			}
			if (Input::GetKey(Key::E))
			{
				Position += MathsUtils::CalculateUpVector(Rotation) * (float)Time::GetFrameTime() * Speed;
			}

			glm::vec2 mouseVelocity = Input::GetMouseVelocity();
			
			float magnitude = glm::length(mouseVelocity);

			if (magnitude > 0.0015f)
			{
				Euler.x -= mouseVelocity.y * Time::GetFrameTime() * 180.0f * 180.0f;
				Euler.y += mouseVelocity.x * Time::GetFrameTime() * 180.0f * 180.0f;
			}
		}
		else
		{
			if (!ShowCursor)
			{
				SDL_SetRelativeMouseMode(SDL_FALSE);
				ShowCursor = true;
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
	
	glm::quat qPitch = glm::angleAxis(glm::radians(-Euler.x), glm::vec3(1, 0, 0));
	glm::quat qYaw = glm::angleAxis(glm::radians(Euler.y), glm::vec3(0, 1, 0));
	// omit roll
	Rotation = qPitch * qYaw;
	Rotation = glm::normalize(Rotation);
	glm::mat4 rotate = glm::mat4_cast(Rotation);
	glm::mat4 translate = glm::mat4(1.0f);
	translate = glm::translate(translate, -Position);

	View =  rotate * translate;
}

harmony::EditorView::EditorView(Program& program, Ref<ScenePanel> scenePanel) : View("Editor"), p_Program(program), p_Renderer(program.m_Renderer), p_ScenePanel(scenePanel)
{
	p_Op = ImGuizmo::OPERATION::TRANSLATE;
}

void harmony::EditorView::OnPreUpdate(entt::registry& registry)
{
	Camera.Update();
	m_View = Camera.View;
	m_Projection = Camera.Projection;
}
void harmony::EditorView::OnResized(uint32_t w, uint32_t h)
{
	View::OnResized(w, h);
	glm::mat4 proj = glm::perspectiveFov(glm::radians(Camera.FOV), static_cast<float>(m_Width), static_cast<float>(m_Height), Camera.NearClipPlane, Camera.FarClipPlane);
	Camera.UpdateProjection(proj);
	Camera.Width = w;
	Camera.Height = h;
}
#if HARMONY_DEBUG
void harmony::EditorView::OnImGui()
{
	if (p_Program.GetActiveScene().expired())
	{
		return;
	}

	Ref<Scene> scene = p_Program.GetActiveScene().lock();
	
	const std::string editorViewTitle = std::string(ICON_FA_VIDEO_CAMERA) + " Editor";
	glm::mat4 mat = glm::mat4(1.0);
	PipelineStack& stack = p_Renderer.GetViewPipelineStack("Editor");
	if (ImGui::Begin(editorViewTitle.c_str(), (bool*)0, ImGuiWindowFlags_NoScrollbar))
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

		if (ImGui::IsWindowFocused())
		{
			Camera.Focussed = true;
		}
		ImGuizmo::SetDrawlist(ImGui::GetWindowDrawList());
		ImGuizmo::AllowAxisFlip(false);
		float windowWidth = (float)ImGui::GetWindowWidth();
		float windowHeight = (float)ImGui::GetWindowHeight();
		
		if (!scene->m_Registry.valid(p_ScenePanel->m_SelectedEntity))
		{
			ImGui::End();
			return;
		}

		if (!scene->m_Registry.any_of<TransformComponent>(p_ScenePanel->m_SelectedEntity))
		{
			ImGui::End();
			return;
		}

		TransformComponent& tc = scene->m_Registry.get<TransformComponent>(p_ScenePanel->m_SelectedEntity);
		ImGuizmo::SetOrthographic(false);
		ImGuizmo::SetRect(ImGui::GetWindowPos().x, ImGui::GetWindowPos().y, windowWidth, windowHeight);
		if (ImGuizmo::Manipulate(
			&m_View[0][0],
			&m_Projection[0][0],
			p_Op,
			ImGuizmo::MODE::WORLD,
			&tc.Model[0][0]
		))
		{
			float matrixTranslation[3], matrixRotation[3], matrixScale[3];
			ImGuizmo::DecomposeMatrixToComponents(&tc.Model[0][0], matrixTranslation, matrixRotation, matrixScale);
			
			if (p_Op == ImGuizmo::OPERATION::TRANSLATE)
			{
				tc.Position.x = matrixTranslation[0];
				tc.Position.y = matrixTranslation[1];
				tc.Position.z = matrixTranslation[2];
			}

			if (p_Op == ImGuizmo::OPERATION::ROTATE)
			{
				tc.Euler.x = matrixRotation[0];
				tc.Euler.y = matrixRotation[1];
				tc.Euler.z = matrixRotation[2];
			}

			if (p_Op == ImGuizmo::OPERATION::SCALE)
			{
				tc.Scale.x = matrixScale[0];
				tc.Scale.y = matrixScale[1];
				tc.Scale.z = matrixScale[2];
			}

			ImGuizmo::RecomposeMatrixFromComponents(
				matrixTranslation,
				matrixRotation,
				matrixScale,
				&tc.Model[0][0]);
		}
		if (Input::GetMouseButton(Mouse::Button::Right))
		{
			ImGui::End();
			return;	
		}
		if (Input::GetKey(Key::W))
		{
			p_Op = ImGuizmo::OPERATION::TRANSLATE;
		}

		if (Input::GetKey(Key::R))
		{
			p_Op = ImGuizmo::OPERATION::ROTATE;
		}

		if (Input::GetKey(Key::S))
		{
			p_Op = ImGuizmo::OPERATION::SCALE;
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