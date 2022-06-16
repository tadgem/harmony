#pragma once
#include "bgfx/bgfx.h"
#include "Core/Memory.h"
#include "Rendering/PipelineStage.h"
#include "Core/Profile.hpp"
namespace harmony
{
    struct PipelineHandle
    {
        uint16_t Index;
    };

    class Pipeline
    {
    public:
        Pipeline(const PipelineHandle& handle);

        template<typename T, typename ... Args>
        WeakRef<T> AddPipelineStage(Args&& ... args)
        {
            HARMONY_PROFILE_FUNCTION()
            static_assert(std::is_base_of<PipelineStage, T>());

            Ref<T> stage = CreateRef<T>(std::forward<Args>(args)...);

            p_Stages.emplace_back(stage);
            return GetWeakRef<T>(stage);

        }

        virtual void Init(entt::registry& registry);
        virtual void Render(entt::registry& registry);
        virtual void Cleanup(entt::registry& registry);
        const PipelineHandle m_Handle;

    protected:
        std::vector<Ref<PipelineStage>> p_Stages;
    };
};