#include <algorithm>
#include "Rendering/Pipeline.h"
#include "Rendering/PipelineDrawStage.h"
#include "Rendering/View.h"
#include "Core/Log.hpp"
#include "Core/Profile.hpp"
harmony::Pipeline::Pipeline(const PipelineHandle& handle, Pipeline::Type pipelineType) : m_Handle(handle), m_Name(handle.Name), m_Type(pipelineType), m_PostProcess(true)
{
}

std::vector<harmony::PipelineDrawStage::Data> harmony::Pipeline::Init(entt::registry& registry, WeakRef<View> view, std::vector<bgfx::ViewId> viewIds)
{
	HARMONY_PROFILE_FUNCTION()
	std::vector<PipelineDrawStage::Data> datas = std::vector<PipelineDrawStage::Data>();
	if (p_Stages.size() == 0)
	{
		return datas;
	}
	for (int i = 0; i < p_Stages.size(); i++)
	{
		datas.emplace_back(p_Stages[i]->Init(registry, view, viewIds[i]));
	}
	return datas;
}

void harmony::Pipeline::AddPipelineStage(Ref<PipelineDrawStage> stage)
{
	HARMONY_PROFILE_FUNCTION()
	if (std::find(p_Stages.begin(), p_Stages.end(), stage) != p_Stages.end())
	{
		harmony::log::warn("Pipeline : {} : already contains stage : {}", m_Name, stage->m_Name);
		return;
	}

	p_Stages.emplace_back(stage);
}

void harmony::Pipeline::PreUpdate(entt::registry& registry, WeakRef<View> view, std::vector<bgfx::ViewId> viewIds, std::vector<PipelineDrawStage::Data> data)
{
	HARMONY_PROFILE_FUNCTION()
	Ref<View> _v = view.lock();
	if (p_Stages.size() == 0)
	{
		return;
	}
	for (int i = 0; i < p_Stages.size(); i++)
	{
		bgfx::setViewClear(viewIds[i], BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x00000000, 1.0f);
	}

	for (int i = 0; i < p_Stages.size(); i++)
	{
		p_Stages[i]->PreUpdate(registry, view, viewIds[i]);

		int nextIndex = i + 1;
		if (nextIndex >= p_Stages.size())
		{
			continue;
		}

		if (!p_Stages[nextIndex]->m_HasDepthAttachment)
		{
			continue;
		}

		auto srcData = data[i];
		auto dstData = data[nextIndex];
		Attachment::Type srcDepthType = srcData.GetDepthType();
		if (!srcDepthType == dstData.GetDepthType())
		{
			continue;
		}
		// Get first view id of next pipeline
		bgfx::ViewId nextViewId = viewIds[nextIndex];
		// Get tex handles for this stage final depth & next stage initial depth texture
		bgfx::TextureHandle srcTexture = srcData.m_Attachments[srcDepthType].m_Handle;
		bgfx::TextureHandle destTexture = dstData.m_Attachments[srcDepthType].m_Handle;
		// this is blasphemy. Burn
		if (srcTexture.idx >= 4096 || destTexture.idx >= 4096)
		{
			continue;
		}
		bgfx::blit(
			nextViewId,
			destTexture,
			0,
			0,
			srcTexture
		);
	}
}

void harmony::Pipeline::PostUpdate(entt::registry& registry, WeakRef<View> view, std::vector<bgfx::ViewId> viewIds, std::vector<PipelineDrawStage::Data> data)
{
	HARMONY_PROFILE_FUNCTION()
	if (p_Stages.size() == 0)
	{
		return;
	}
	for (int i = 0; i < p_Stages.size(); i++)
	{
		p_Stages[i]->PostUpdate(registry, view, viewIds[i]);
	}
}

void harmony::Pipeline::Cleanup(entt::registry& registry, WeakRef<View> view, std::vector<bgfx::ViewId> viewIds)
{
	HARMONY_PROFILE_FUNCTION()
	if (p_Stages.size() == 0)
	{
		return;
	}
	for (int i = 0; i < p_Stages.size(); i++)
	{
		p_Stages[i]->Cleanup(view, viewIds[i]);
	}
}


uint32_t harmony::Pipeline::NumPipelineStages()
{
	return p_Stages.size();
}

bool harmony::Pipeline::HasDepth()
{
	HARMONY_PROFILE_FUNCTION()
	for (Ref<PipelineDrawStage> pipeline : p_Stages)
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
	json["pipeline"]["type"] = m_Type;
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
	m_Handle = json["pipeline"]["handle"];
	m_Type = json["pipeline"]["type"];
	auto pipelinesJson = json["pipeline"]["stages"];
}
