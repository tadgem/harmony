#ifndef HARMONY_CORE_RENDERING_PIPELINES_PIPELINEV2_H
#define HARMONY_CORE_RENDERING_PIPELINES_PIPELINEV2_H
#include "Core/Alias.h"
#include "Core/Memory.h"
#include "Rendering/Attachment.h"
#include "ThirdParty/entt.hpp"

namespace harmony
{
    class Framebuffer;
    class View;
    class PipelineStage;

    class PipelineV2
    {
    public:
        PipelineV2(std::string&& name);

        template<typename T, typename ... Args>
        WeakRef<T> AddPipelineStage(Args &&... args) {
            static_assert(std::is_base_of<PipelineStage, T>());

            Ref<T> stage = CreateRef<T>(std::forward<Args>(args)...);
            p_Stages.emplace_back(stage);

            return GetWeakRef<T>(stage);
        }

        WeakRef<Framebuffer> AddFramebuffer(Vector<AttachmentType> attachments);

        void AddPipelineStage(Ref<PipelineStage> stage);

        virtual void PreUpdate(entt::registry &registry, WeakRef<View> view);
        virtual void PostUpdate(entt::registry &registry, WeakRef<View> view);

        const String m_Name;

    protected:
        friend class Renderer;

        Vector<Ref<PipelineStage>>  p_Stages;
        Vector<Ref<Framebuffer>>    p_PipelineFramebuffers;
        Unique<Framebuffer>         p_FinalImageFramebuffer;
    };
}

#endif