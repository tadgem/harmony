#pragma once

#include "Core/Memory.h"
#include "ThirdParty/entt.hpp"
#include "ThirdParty/json.hpp"
#include "Rendering/Attachment.h"
#include "PipelineHandle.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/ShaderDataSource.h"

namespace harmony {
    class View;

    class PipelineStageRenderer;

    class PipelineStage {
    public:
        enum Type : char {
            Unknown,
            PrimaryDraw,
            SecondaryDraw,
            PostProcess,
            Compute
        };

        struct Data {
            bgfx::FrameBufferHandle m_FramebufferHandle;
            std::map<AttachmentType, Attachment> m_Attachments;

            void Clear();

            AttachmentType GetDepthType();

            AttachmentType GetColorType();
        };

        PipelineStage(
                const std::string &name,
                Type pipelineStageType,
                AttachmentType attachments,
                WeakRef<ShaderProgram> shader,
                WeakRef<PipelineStageRenderer> stageRenderer);


        NLOHMANN_JSON_SERIALIZE_ENUM(Type, {
            { Unknown, "unknown" },
            { PrimaryDraw, "primaryDraw" },
            { SecondaryDraw, "secondaryDraw" },
            { PostProcess, "postProcess" },
            { Compute, "compute" }
        })

        virtual Data Init(entt::registry &registry, WeakRef<View> view, bgfx::ViewId viewId);

        virtual void Cleanup(WeakRef<View> view, bgfx::ViewId viewId);

        virtual void AddShaderDataSource(WeakRef<ShaderDataSource> source);

        virtual nlohmann::json Serialize();

        virtual void Deserialize(nlohmann::json json);

        bool m_HasHDRAttachment;
        bool m_HasDepthAttachment;

        Type m_StageType;
        AttachmentType m_Attachments;
        std::string m_Name;
        WeakRef<ShaderProgram> p_Shader;
        WeakRef<PipelineStageRenderer> p_Renderer;

    protected:
        std::vector<WeakRef<ShaderDataSource>> p_DataSources;
    };
}