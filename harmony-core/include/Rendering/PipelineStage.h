#pragma once
#include "Core/Memory.h"
#include "ThirdParty/entt.hpp"
#include "ThirdParty/json.hpp"
#include "Rendering/Attachment.h"
#include "Rendering/PipelineHandle.h"
#include "Rendering/Shader.h"
#include "Rendering/ShaderDataSource.h"
namespace harmony
{
    class PipelineStage
    {
    public:
        enum Type : char
        {
            Unknown,
            PrimaryDraw,
            SecondaryDraw,
            PostProcess,
            Compute
        };

        struct Data
        {
            bgfx::FrameBufferHandle m_FramebufferHandle;
            std::map<Attachment::Type, Attachment> m_Attachments;

            Attachment::Type GetDepthType();
        };


        template<typename T, typename ... Args>
        WeakRef<T> AddDataSource(Args&& ... args)
        {
            HARMONY_PROFILE_FUNCTION()
                static_assert(std::is_base_of<ShaderDataSource, T>());

            Ref<T> source = CreateRef<T>(std::forward<Args>(args)...);

            p_DataSources.emplace_back(source);
            return GetWeakRef<T>(source);

        }

        NLOHMANN_JSON_SERIALIZE_ENUM(Type, {
            {Unknown, "unknown"},
            {PrimaryDraw, "primaryDraw"},
            {SecondaryDraw, "secondaryDraw"},
            {PostProcess, "postProcess"},
            {Compute, "compute"}
            })

    protected:
        std::vector<Ref<ShaderDataSource>>  p_DataSources;
    };
}