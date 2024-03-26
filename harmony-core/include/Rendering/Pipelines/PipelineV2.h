#ifndef HARMONY_CORE_RENDERING_PIPELINES_PIPELINEV2_H
#define HARMONY_CORE_RENDERING_PIPELINES_PIPELINEV2_H

#include "STL/Thread.h"
#include "Core/Memory.h"
#include "Rendering/TypeDef.h"
#include "ThirdParty/entt.hpp"
#include "STL/Vector.h"
#include "STL/String.h"
#include "STL/Map.h"

namespace harmony {
    class Framebuffer;

    class View;

    class PipelineStage;

    class PipelineV2 {
    public:
        explicit PipelineV2(const String &name);

        template<typename T, typename... Args>
        WeakPtr<T> AddPipelineStage(WeakPtr<Framebuffer> fb, Args &&...args) {
            static_assert(IsBaseOf<PipelineStage, T>());

            RefCntPtr<T> stage = CreateRef<T>(Forward<Args>(args)...);
            if (AddPipelineStage(fb, stage)) {
                return GetWeakRef<T>(stage);
            }
            return WeakPtr<T>();
        }

        bool AddPipelineStage(WeakPtr<Framebuffer> fb, RefCntPtr<PipelineStage> stage);

        WeakPtr<Framebuffer> AddFramebuffer(const String &name,
                                            Vector<AttachmentType> attachments,
                                            Resolution::Type resolutionType);

        WeakPtr<Framebuffer> GetFramebuffer(const String& name);

        virtual void PreUpdate(entt::registry &registry, WeakPtr<View> view);

        virtual void PostUpdate(entt::registry &registry, WeakPtr<View> view);

        virtual void Resize(entt::registry &registry, WeakPtr<View> view);

        virtual WeakPtr<Framebuffer> TryGetFramebuffer(const String &name);

        virtual bool HasOutputFramebuffer();

        virtual WeakPtr<Framebuffer> GetOutputFramebuffer();

        virtual void SetOutputFramebuffer(WeakPtr<Framebuffer> framebuffer);

        const String m_Name;

    protected:
        friend class Renderer;

        RefCntPtr<Framebuffer> CreateFrambufferInternal(const String &name,
                                                        Vector<AttachmentType> attachments,
                                                        Resolution::Type resolutionType);

        bool IsViewValid(WeakPtr<View> view);

        Map<RefCntPtr<Framebuffer>, Vector<RefCntPtr<PipelineStage>>> p_Stages;
        WeakPtr<Framebuffer> p_OutputFramebuffer;
    };
} // namespace harmony

#endif