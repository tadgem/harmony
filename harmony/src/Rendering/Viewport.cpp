#include "Rendering/Viewport.h"

harmony::Viewport::Viewport()
{
}

harmony::Viewport::~Viewport()
{
}

void harmony::Viewport::OnResized(uint32_t w, uint32_t h)
{
	m_ViewData->m_Width = w;
	m_ViewData->m_Height = h;

	RefreshPipelineViews();
}

void harmony::Viewport::RefreshPipelineViews()
{
}
