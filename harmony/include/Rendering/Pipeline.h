#pragma once
#include "bgfx/bgfx.h"
#include "Core/Memory.h"
#include "Rendering/PipelineStage.h"
#include "Core/Profile.hpp"
#include "json.hpp"
namespace harmony
{
    class View;
    class Pipeline
    {
    public:

        enum Type
        {
            Compute,
            ScreenSpace,
            Surface,
            PostProcess
        };

        Pipeline(const PipelineHandle& handle, Type pipelineType);

        template<typename T, typename ... Args>
        WeakRef<T> AddPipelineStage(Args&& ... args)
        {
            HARMONY_PROFILE_FUNCTION()
            static_assert(std::is_base_of<PipelineStage, T>());

            Ref<T> stage = CreateRef<T>(std::forward<Args>(args)...);

            p_Stages.emplace_back(stage);
            return GetWeakRef<T>(stage);

        }

        virtual std::vector<PipelineStage::Data> Init(entt::registry& registry, WeakRef<View> view, std::vector<bgfx::ViewId> viewIds);
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view, std::vector<bgfx::ViewId> viewIds);
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view, std::vector<bgfx::ViewId> viewIds);
        virtual void Cleanup(entt::registry& registry, WeakRef<View> view, std::vector<bgfx::ViewId> viewIds);
                
        uint32_t    NumPipelineStages();
        bool        HasDepth();

        nlohmann::json  Serialize();
        void            Deserialize(nlohmann::json& json);

        PipelineHandle      m_Handle;
        std::string         m_Name;
        Type          m_Type;

    protected:
        std::vector<Ref<PipelineStage>> p_Stages;
    };
};