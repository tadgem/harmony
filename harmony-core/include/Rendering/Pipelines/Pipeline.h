#pragma once

#include "bgfx/bgfx.h"
#include "Core/Memory.h"
#include "Rendering/Pipelines/PipelineStages/PipelineDrawStage.h"

#include "ThirdParty/json.hpp"

namespace harmony {
    class View;
    class Framebuffer;
    class Pipeline {
    public:

        enum Type {
            Unknown,
            Compute,
            ScreenSpace,
            Surface,
            PostProcess
        };

        NLOHMANN_JSON_SERIALIZE_ENUM(Type, {
            { Unknown, "unknown" },
            { ScreenSpace, "screenSpace" },
            { Surface, "surface" },
            { PostProcess, "postProcess" },
            { Compute, "compute" }
        })

        Pipeline(const PipelineHandle &handle, Type pipelineType);

        template<typename T, typename ... Args>
        WeakRef<T> AddPipelineStage(Args &&... args) {

            static_assert(std::is_base_of<PipelineDrawStage, T>());

            Ref<T> stage = CreateRef<T>(std::forward<Args>(args)...);

            p_Stages.emplace_back(stage);
            return GetWeakRef<T>(stage);

        }

        virtual void AddPipelineStage(Ref<PipelineDrawStage> stage);

        virtual std::vector<Ref<Framebuffer>>
        Init(entt::registry &registry, WeakRef<View> view, std::vector<bgfx::ViewId> viewIds);

        virtual void PreUpdate(entt::registry &registry, WeakRef<View> view, std::vector<bgfx::ViewId> viewIds,
                               std::vector<Ref<Framebuffer>> data);

        virtual void PostUpdate(entt::registry &registry, WeakRef<View> view, std::vector<bgfx::ViewId> viewIds,
                                std::vector<Ref<Framebuffer>> data);

        virtual void Cleanup(entt::registry &registry, WeakRef<View> view, std::vector<bgfx::ViewId> viewIds);

        uint32_t NumPipelineStages();

        bool HasDepth();

        nlohmann::json Serialize();

        void Deserialize(nlohmann::json &json);

        PipelineHandle m_Handle;
        std::string m_Name;
        Type m_Type;
        bool m_PostProcess;

    protected:
        friend class Renderer;

        std::vector<Ref<PipelineDrawStage>> p_Stages;
    };
};