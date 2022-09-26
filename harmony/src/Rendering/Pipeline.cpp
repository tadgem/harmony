#include "Rendering/Pipeline.h"
#include "Core/Log.hpp"
harmony::Pipeline::Pipeline(const PipelineHandle& handle) : m_Handle(handle), m_Name(handle.Name)
{
}

void harmony::Pipeline::Init(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	if (p_Stages.size() == 0)
	{
		return;
	}
	for (int i = 0; i < p_Stages.size(); i++)
	{
		p_Stages[i]->Init(registry, view, viewId);
	}
}

void harmony::Pipeline::PreUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	Ref<View> _v = view.lock();
	if (p_Stages.size() == 0)
	{
		return;
	}
	for (int i = 0; i < p_Stages.size(); i++)
	{
		bgfx::setViewClear(viewId, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x00000000, 1.0f);
	}
	for (int i = 0; i < p_Stages.size(); i++)
	{
		p_Stages[i]->PreUpdate(registry, view, viewId);
	}
}

void harmony::Pipeline::PostUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	if (p_Stages.size() == 0)
	{
		return;
	}
	for (int i = 0; i < p_Stages.size(); i++)
	{
		p_Stages[i]->PostUpdate(registry, view, viewId);
	}
}

void harmony::Pipeline::Cleanup(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
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

nlohmann::json harmony::Pipeline::Serialize()
{
	auto json = nlohmann::json();

	json["pipeline"] = nlohmann::json();
	json["pipeline"]["name"] = m_Name;
	json["pipeline"]["stages"] = nlohmann::json::array();
	for (int i = 0; i < p_Stages.size(); i++)
	{
		json["pipeline"]["stages"][i] = *p_Stages[i];
	}
	json["pipeline"]["handle"] = m_Handle;

	return json;
}

void harmony::Pipeline::Deserialize(nlohmann::json& json)
{
	m_Name = json["pipeline"]["name"];
	m_Handle = json["pipeline"]["handle"] = m_Handle;

	if (PipelineHandle::p_Counter < m_Handle.Index)
	{
		PipelineHandle::p_Counter = m_Handle.Index + 1;
	}

	auto pipelinesJson = json["pipeline"]["stages"];

	for (int i = 0; i < pipelinesJson.size(); i++)
	{
		Ref<PipelineStage> stage = CreateRef<PipelineStage>(pipelinesJson[i]);
		p_Stages.emplace_back(stage);
	}
}

harmony::PipelineHandle harmony::PipelineHandle::New(const std::string& name)
{
	PipelineHandle handle{ p_Counter, name };
	p_Counter++;
	return handle;
}

