#ifndef HARMONY_CORE_RENDERING_PIPELINES_PIPELINEV2_H
#define HARMONY_CORE_RENDERING_PIPELINES_PIPELINEV2_H

#include "Core/Alias.h"
#include "Core/Memory.h"
#include "Rendering/TypeDef.h"
#include "ThirdParty/entt.hpp"

namespace harmony
{
	class Framebuffer;
	class View;
	class PipelineStage;
	class PipelineV2
	{
	public:
		explicit PipelineV2(const String &name);

		template<typename T, typename... Args>
		WeakRef<T> AddPipelineStage(WeakRef<Framebuffer> fb, Args &&...args)
		{
			static_assert(std::is_base_of<PipelineStage, T>());

			Ref<T> stage = CreateRef<T>(std::forward<Args>(args)...);
			if (AddPipelineStage(fb, stage))
			{
				return GetWeakRef<T>(stage);
			}
			return WeakRef<T>();
		}

		bool AddPipelineStage(WeakRef<Framebuffer> fb, Ref<PipelineStage> stage);
		WeakRef<Framebuffer> AddFramebuffer(const String &name,
											Vector<AttachmentType> attachments,
											Resolution::Type resolutionType);
		virtual void PreUpdate(entt::registry &registry, WeakRef<View> view);
		virtual void PostUpdate(entt::registry &registry, WeakRef<View> view);

		virtual WeakRef<Framebuffer> TryGetFramebuffer(const String& name);

		virtual bool HasOutputFramebuffer();
		virtual WeakRef<Framebuffer> GetOutputFramebuffer();
		virtual void SetOutputFramebuffer(WeakRef<Framebuffer> framebuffer);
		const String m_Name;

	protected:
		friend class Renderer;
		Ref<Framebuffer> CreateFrambufferInternal(const String &name,
												  Vector<AttachmentType> attachments,
												  Resolution::Type resolutionType);
		bool IsViewValid(WeakRef<View> view);
		Map<Ref<Framebuffer>, Vector<Ref<PipelineStage>>> p_Stages;
		WeakRef<Framebuffer> p_OutputFramebuffer;
	};
} // namespace harmony

#endif