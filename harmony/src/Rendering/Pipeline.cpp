#include "Rendering/Pipeline.h"
#include "Core/Log.hpp"
harmony::Pipeline::Pipeline(const PipelineHandle& handle) : m_Handle(handle), m_Name(handle.Name)
{
}

void harmony::Pipeline::Init(entt::registry& registry, WeakRef<View> view)
{
	if (p_Stages.size() == 0)
	{
		return;
	}
	for (int i = 0; i < p_Stages.size(); i++)
	{
		p_Stages[i]->Init(registry, view);
	}
}

void harmony::Pipeline::PreUpdate(entt::registry& registry, WeakRef<View> view)
{
	if (p_Stages.size() == 0)
	{
		return;
	}
	for (int i = 0; i < p_Stages.size(); i++)
	{
		p_Stages[i]->PreUpdate(registry, view);
	}
}

void harmony::Pipeline::PostUpdate(entt::registry& registry, WeakRef<View> view)
{
	if (p_Stages.size() == 0)
	{
		return;
	}
	for (int i = 0; i < p_Stages.size(); i++)
	{
		p_Stages[i]->PostUpdate(registry, view);
	}
}

void harmony::Pipeline::Cleanup(entt::registry& registry, WeakRef<View> view)
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

bgfx::TextureHandle harmony::Pipeline::GetFinalImage()
{
	if (p_Stages.size() == 0)
	{
		harmony::log::warn("Pipeline with handle {} is empty!", m_Handle.Index);
		return BGFX_INVALID_HANDLE;
	}
	bgfx::FrameBufferHandle fbToBlit = p_Stages[p_Stages.size() - 1]->GetStageFinalFramebuffer();
	return bgfx::getTexture(fbToBlit);
}

harmony::PipelineHandle harmony::PipelineHandle::New(const std::string& name)
{
	PipelineHandle handle{ p_Counter, name };
	p_Counter++;
	return handle;
}
