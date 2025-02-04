#pragma once

#include "STL/Thread.h"
#include "Core/Memory.h"
#include "PipelineHandle.h"
#include "Rendering/Attachment.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/ShaderDataSource.h"
#include "ThirdParty/entt.hpp"
#include "STL/Json.hpp"

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

        PipelineStage(const String &name, Type pipelineStageType,
                      Vector<AttachmentType> requiredAttachments,
                      WeakPtr<ShaderProgram> shader,
                      WeakPtr<PipelineStageRenderer> stageRenderer);

        NLOHMANN_JSON_SERIALIZE_ENUM(Type, {
            { Unknown, "unknown" },
            { PrimaryDraw, "primaryDraw" },
            { SecondaryDraw, "secondaryDraw" },
            { PostProcess, "postProcess" },
            { Compute, "compute" }
        })

        virtual void PreUpdate(entt::registry &registry, WeakPtr<View> view,
                               bgfx::ViewId viewId) = 0;

        virtual void PostUpdate(entt::registry &registry, WeakPtr<View> view,
                                bgfx::ViewId viewId) = 0;

        virtual void Cleanup(WeakPtr<View> view, bgfx::ViewId viewId);

        virtual void AddShaderDataSource(WeakPtr<ShaderDataSource> source);

        virtual Json Serialize();

        virtual void Deserialize(Json json);

        bool m_HasHDRAttachment;
        bool m_HasDepthAttachment;
        Type m_StageType;
        Vector<AttachmentType> m_Attachments;
        String m_Name;
        WeakPtr<ShaderProgram> p_Shader;
        RefCntPtr<PipelineStageRenderer> p_Renderer;

    protected:
        Vector<WeakPtr<ShaderDataSource>> p_DataSources;
    };
} // namespace harmony