#include "Rendering/Pipeline.h"
#include "Core/Log.hpp"
harmony::Pipeline::Pipeline(const PipelineHandle& handle, const std::string name) : m_Handle(handle), m_Name(name)
{
}

void harmony::Pipeline::Init(entt::registry& registry)
{
	if (p_Stages.size() == 0)
	{
		return;
	}
	for (int i = 0; i < p_Stages.size(); i++)
	{
		p_Stages[i]->Init(registry);
	}
}

void harmony::Pipeline::Render(entt::registry& registry)
{
	if (p_Stages.size() == 0)
	{
		return;
	}
	for (int i = 0; i < p_Stages.size(); i++)
	{
		p_Stages[i]->Render(registry);
	}
}

void harmony::Pipeline::Cleanup(entt::registry& registry)
{
	if (p_Stages.size() == 0)
	{
		return;
	}
	for (int i = 0; i < p_Stages.size(); i++)
	{
		p_Stages[i]->Cleanup();
	}
}

bgfx::FrameBufferHandle harmony::Pipeline::GetFinalImage()
{
	if (p_Stages.size() == 0)
	{
		harmony::log::warn("Pipeline with handle {} is empty!", m_Handle.Index);
		return bgfx::FrameBufferHandle();
	}
	bgfx::FrameBufferHandle v = p_Stages[p_Stages.size() - 1]->GetStageFinalFramebuffer();
	return v;
}
