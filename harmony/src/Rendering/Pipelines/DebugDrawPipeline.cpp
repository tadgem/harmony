#include "Rendering/Pipelines/DebugDrawPipeline.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Core/MathsUtils.h"
#include "Core/Input.h"
harmony::DebugDrawStage::DebugDrawStage() : PipelineStage(PipelineStage::Type::Draw, WeakRef<ShaderProgram>())
{
}

void harmony::DebugDrawStage::Init(entt::registry& registry, WeakRef<View> view)
{
	PipelineStage::Init(registry, view);
	ddInit(&p_Allocator);
}

void harmony::DebugDrawStage::PreUpdate(entt::registry& registry, WeakRef<View> view)
{
	Ref<View> _view = view.lock();
	glm::mat4 viewMatrix = Camera.GetViewMatrix();
	glm::mat4 projectionMatrix = Camera.GetProjectionMatrix(_view->m_Width, _view->m_Height);
	bgfx::setViewTransform(m_ViewId, &viewMatrix[0], &projectionMatrix[0]);
	bgfx::setViewRect(m_ViewId, 0, 0, _view->m_Width, _view->m_Height);
	DebugDraw.begin(m_ViewId);

	DebugDraw.drawGrid(Axis::Enum::Y, bx::Vec3(0.0f, 0.0f, 0.0f), 1000);
	DebugDraw.drawAxis(0.0f, 1.0f, 0.0f, 1.0f);
}

void harmony::DebugDrawStage::PostUpdate(entt::registry& registry, WeakRef<View> view)
{
	DebugDraw.end();
}

void harmony::DebugDrawStage::Cleanup()
{
	ddShutdown();
}

harmony::DebugDrawPipeline::DebugDrawPipeline() : Pipeline(PipelineHandle::New("DebugDrawPipline"))
{
	AddPipelineStage<DebugDrawStage>();
}

harmony::DebugCamera::DebugCamera()
{
	Position = glm::vec3(0.0f, 3.0f, 0.0f);
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
	glm::mat4 viewMatrix = glm::mat4(1.0);

	glm::vec3 forward = MathsUtils::CalculateForwardVector(Euler);

	return viewMatrix;
}

glm::mat4 harmony::DebugCamera::GetProjectionMatrix(uint32_t width, uint32_t height)
{
	glm::mat4 projMatrix = glm::mat4(1.0);

	projMatrix = glm::perspectiveFov(glm::radians(FOV), static_cast<float>(width), static_cast<float>(height), Near, Far);

	return projMatrix;
}
