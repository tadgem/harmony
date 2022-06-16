#pragma once
#include "bgfx/bgfx.h"
#include "Core/Memory.h"
#include "Rendering/PipelineStage.h"
namespace harmony
{
    class Pipeline
    {
    public:
        Pipeline();

        template<typename T, typename ... Args>
        WeakRef<T> AddPipelineStage(Args&& ... args)
        {
            HARMONY_PROFILE_FUNCTION()
            static_assert(std::is_base_of<PipelineStage, T>());

            Ref<T> stage = CreateRef<T>(std::forward<Args>(args..));
            
            if (std::find(p_Stages.begin(), p_Stages.end(), stage) != p_Stages.end())
            {
                harmony::log::warn("Pipeline already contains this stage...");
                return 
            }
            p_Stages.emplace_back(stage);
            return GetWeakRef<T>(stage);

        }

        virtual void Init(entt::registry& registry);
        virtual void Render(entt::registry& registry);
        virtual void Cleanup(entt::registry& registry);

    protected:
        std::vector<Ref<PipelineStage>> p_Stages;
    };
};