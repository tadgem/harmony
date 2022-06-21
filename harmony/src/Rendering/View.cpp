#include "Rendering/View.h"

harmony::View::View(const std::string& name) : 
	c_InitialViewWidth(1280), 
	c_InitialViewHeight(720),
	m_View(glm::mat4(1.0)),
	m_Projection(glm::mat4(1.0)),
	m_Width(1280),
	m_Height(720),
	m_Name(name)
{
}

void harmony::View::OnPreUpdate(entt::registry& registry)
{
}

void harmony::View::OnPostUpdate(entt::registry& registry)
{
}
