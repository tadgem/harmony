#pragma once
#include "bgfx/bgfx.h"
#include "Core/Memory.h"
#include "Rendering/PipelineStage.h"
#include "Rendering/View.h"
#include "Core/Profile.hpp"
namespace harmony
{
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

        virtual void Init(entt::registry& registry, WeakRef<View> view);
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view);
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view);
        virtual void Cleanup(entt::registry& registry, WeakRef<View> view);

        virtual bgfx::TextureHandle GetFinalImage();
        
        virtual Ref<Pipeline> Clone();
        
        bgfx::TextureHandle GetInitialDepth();
        bgfx::TextureHandle GetFinalDepth();
        bgfx::ViewId GetFirstViewID();
        uint32_t NumPipelineStages();
        PipelineHandle m_Handle;
        std::string m_Name;

        bool HasDepth();

    protected:
        std::vector<Ref<PipelineStage>> p_Stages;
        bgfx::TextureHandle p_FinalImage;
    };
};