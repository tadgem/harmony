#include "Rendering/View.h"
#include "Core/Log.hpp"
#if HARMONY_DEBUG
#include "ImGui/imgui.h"
#include "ImGui/imgui_bgfx.h"
#include "Core/Input.h"
#endif

harmony::View::View(const std::string& name) : 
	m_View(glm::mat4(1.0)),
	m_Projection(glm::mat4(1.0)),
	m_Width(g_InitialWidth),
	m_Height(g_InitialHeight),
	m_Name(name),
	m_FOV(harmony::g_DefaultFOV),
	m_ProjectionType(harmony::ProjectionType::Perspective),
	p_Resized(false)
{
#if HARMONY_DEBUG
	m_ImGuiWindowWidth = 0;
	m_ImGuiWindowHeight = 0;
#endif
}

void harmony::View::OnPreUpdate(entt::registry& registry)
{
}

void harmony::View::OnPostUpdate(entt::registry& registry)
{
}

void harmony::View::OnResized(uint32_t w, uint32_t h)
{
	p_Resized = true;
	m_Width = w;
	m_Height = h;
}
#if HARMONY_DEBUG
void harmony::View::OnImGui()
{
	ImVec2 dim = ImGui::GetContentRegionAvail();
	uint32_t currentWidth = static_cast<uint32_t>(dim.x);
	uint32_t currentHeight = static_cast<uint32_t>(dim.y);

	if (currentWidth != m_ImGuiWindowWidth || currentHeight != m_ImGuiWindowHeight)
	{
		if (Input::Get()->GetMouseButton(Mouse::Button::Left))
		{
			return;
		}
		OnResized(currentWidth, currentHeight);
		m_ImGuiWindowWidth = currentWidth;
		m_ImGuiWindowHeight = currentHeight;
	}
}

void harmony::View::OnImGuiOptions()
{

}
#endif
bool harmony::View::operator==(const View& other)
{
	return	other.m_Name			== m_Name &&
			other.m_Width			== m_Width &&
			other.m_Height			== m_Height &&
			other.m_ProjectionType	== m_ProjectionType;
}

bool harmony::View::operator!=(const View& other)
{
	return	other.m_Name			!= m_Name ||
			other.m_Width			!= m_Width ||
			other.m_Height			!= m_Height ||
			other.m_ProjectionType	!= m_ProjectionType;
}

bool harmony::View::operator<(const View& other)
{
	return false;
}

nlohmann::json harmony::View::Serialize()
{
	auto j = nlohmann::json();
	j["name"] = m_Name;
	j["width"] = m_Width;
	j["height"] = m_Height;
	j["fov"] = m_FOV;
	j["projectionType"] = m_ProjectionType;

	return j;
}

void harmony::View::Deserialize(nlohmann::json& json)
{
	m_Name = json["name"];
	m_Width = json["width"];
	m_Height = json["height"];
	m_FOV = json["fov"];
	m_ProjectionType = json["projectionType"];
}