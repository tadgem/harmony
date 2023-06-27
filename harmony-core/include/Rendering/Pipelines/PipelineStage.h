#pragma once

#include "Core/Alias.h"
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

    class Framebuffer;

    class PipelineStage {
    public:
        enum Type : char {
            Unknown,
            PrimaryDraw,
            SecondaryDraw,
            PostProcess,
            Compute
        };

        PipelineStage(
                const std::string &name,
                Type pipelineStageType,
                Vector<AttachmentType> requiredAttachments,
                WeakRef<ShaderProgram> shader,
                WeakRef<PipelineStageRenderer> stageRenderer);


        NLOHMANN_JSON_SERIALIZE_ENUM(Type, {
            { Unknown, "unknown" },
            { PrimaryDraw, "primaryDraw" },
            { SecondaryDraw, "secondaryDraw" },
            { PostProcess, "postProcess" },
            { Compute, "compute" }
        })

        virtual void PreUpdate(entt::registry &registry, WeakRef<View> view, bgfx::ViewId viewId) = 0;

        virtual void PostUpdate(entt::registry &registry, WeakRef<View> view, bgfx::ViewId viewId) = 0;

        virtual void Cleanup(WeakRef<View> view, bgfx::ViewId viewId);

        virtual void AddShaderDataSource(WeakRef<ShaderDataSource> source);

        virtual nlohmann::json Serialize();

        virtual void Deserialize(nlohmann::json json);

        bool m_HasHDRAttachment;
        bool m_HasDepthAttachment;

        Type m_StageType;
        Vector<AttachmentType> m_Attachments;
        String m_Name;
        WeakRef<ShaderProgram> p_Shader;
        Ref<PipelineStageRenderer> p_Renderer;

    protected:
        std::vector<WeakRef<ShaderDataSource>> p_DataSources;
    };
}