#pragma once

#include "Rendering/Debug/GfxDebug.h"
#include "Rendering/Pipelines/PipelineStages/PipelineDrawStage.h"

namespace harmony
{
	class Framebuffer;
	class DebugDrawStage : public PipelineDrawStage
	{
	public:
		DebugDrawStage(GfxDebug::Channel channel);
		virtual void PreUpdate(entt::registry &registry, WeakRef<View> view,
							   bgfx::ViewId viewId) override;
		virtual void PostUpdate(entt::registry &registry, WeakRef<View> view,
								bgfx::ViewId viewId) override;
		virtual void Cleanup(WeakRef<View> view, bgfx::ViewId viewId) override;
		GfxDebug::Channel m_Channel;
		bool Active;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(DebugDrawStage, m_Name, p_Shader, m_StageType,
									   m_Channel)

	protected:
		std::map<std::string, DebugDrawEncoder *> p_DebugRenderers;
	};
}; // namespace harmony
