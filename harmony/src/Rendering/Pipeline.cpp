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
		p_Stages[i]->Init(registry, view, m_Handle);
	}
}

void harmony::Pipeline::PreUpdate(entt::registry& registry, WeakRef<View> view)
{
	Ref<View> _v = view.lock();
	if (p_Stages.size() == 0)
	{
		return;
	}
	for (int i = 0; i < p_Stages.size(); i++)
	{
		bgfx::setViewClear(p_Stages[i]->m_ViewId, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x00000000, 1.0f);
	}
	for (int i = 0; i < p_Stages.size(); i++)
	{
		p_Stages[i]->PreUpdate(registry, view, m_Handle);
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
		p_Stages[i]->PostUpdate(registry, view, m_Handle);
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
		// harmony::log::warn("Pipeline with handle {} is empty!", m_Handle.Index);
		return BGFX_INVALID_HANDLE;
	}
	bgfx::FrameBufferHandle fbToBlit = p_Stages[p_Stages.size() - 1]->GetStageFinalFramebuffer();

	if (fbToBlit.idx == bgfx::kInvalidHandle)
	{
		return bgfx::TextureHandle();
	}

	return bgfx::getTexture(fbToBlit);
}

bgfx::TextureHandle harmony::Pipeline::GetInitialDepth()
{
	for (int i = 0; i < p_Stages.size(); i++)
	{
		if (p_Stages[i]->m_HasDepthAttachment)
		{
			return bgfx::getTexture(p_Stages[i]->GetStageFinalFramebuffer(), 1);
		}
	}
	
	return bgfx::TextureHandle();
}

bgfx::TextureHandle harmony::Pipeline::GetFinalDepth()
{
	int index = p_Stages.size() - 1;
	while (!p_Stages[index]->m_HasDepthAttachment)
	{
		index--;
	}
	if (index < 0)
	{
		return bgfx::TextureHandle();
	}
	return bgfx::getTexture(p_Stages[index]->GetStageFinalFramebuffer(), 1);
}

bgfx::ViewId harmony::Pipeline::GetFirstViewID()
{
	if (p_Stages.size() == 0)
	{
		return bgfx::ViewId();
	}
	return p_Stages[0]->m_ViewId;
}

uint32_t harmony::Pipeline::NumPipelineStages()
{
	return p_Stages.size();
}

bool harmony::Pipeline::HasDepth()
{
	for (Ref<PipelineStage> pipeline : p_Stages)
	{
		if (pipeline->m_HasDepthAttachment)
		{
			return true;
		}
	}
	return false;
}

harmony::PipelineHandle harmony::PipelineHandle::New(const std::string& name)
{
	PipelineHandle handle{ p_Counter, name };
	p_Counter++;
	return handle;
}
