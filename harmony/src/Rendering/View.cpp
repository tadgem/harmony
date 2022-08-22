#include "Rendering/View.h"
#include "Core/Log.hpp"
#if HARMONY_DEBUG
#include "ImGui/imgui.h"
#include "ImGui/imgui_bgfx.h"
#endif

harmony::View::View(const std::string& name) : 
	c_InitialViewWidth(g_InitialWidth),
	c_InitialViewHeight(g_InitialHeight),
	m_View(glm::mat4(1.0)),
	m_Projection(glm::mat4(1.0)),
	m_Width(g_InitialWidth),
	m_Height(g_InitialHeight),
	m_Name(name)
{
}

void harmony::View::OnPreUpdate(entt::registry& registry)
{
}

void harmony::View::OnPostUpdate(entt::registry& registry)
{
}

void harmony::View::OnImGui()
{
    
}

void harmony::View::OnImGuiOptions()
{

}

nlohmann::json harmony::View::Serialize()
{
	auto j = nlohmann::json();
	j["name"] = m_Name;
	j["width"] = m_Width;
	j["height"] = m_Height;
}

void harmony::View::Deserialize(nlohmann::json& json)
{
	m_Name = json["name"];
	m_Width = json["width"];
	m_Height = json["height"];
}
