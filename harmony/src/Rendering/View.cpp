#include "Rendering/View.h"

harmony::View::View() : 
	c_InitialViewWidth(1280), 
	c_InitialViewHeight(720),
	m_View(glm::mat4(1.0)),
	m_Projection(glm::mat4(1.0)),
	m_Width(c_InitialViewWidth),
	m_Height(c_InitialViewHeight)
{
}
