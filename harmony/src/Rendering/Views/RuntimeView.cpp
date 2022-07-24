#include "Rendering/Views/RuntimeView.h"
#include "ECS/CameraComponent.h"
harmony::RuntimeView::RuntimeView() : View("RuntimeView")
{
}

void harmony::RuntimeView::OnPreUpdate(entt::registry& registry)
{
	if (registry.any_of<CameraComponent>(CameraEntity.m_Handle))
	{
		
	}
}

void harmony::RuntimeView::OnPostUpdate(entt::registry& registry)
{
	if (registry.any_of<CameraComponent>(CameraEntity.m_Handle))
	{

	}
}

void harmony::RuntimeView::OnImGui()
{
}
