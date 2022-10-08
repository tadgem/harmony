#pragma once
#include "entt.hpp"
#include "json.hpp"
#include "Core/Memory.h"
#include "Rendering/Shader.h"
namespace harmony
{

    struct Attachment 
    {
        enum Type
        {
            Unknown = 0,
            RGBA8F = 1,
            RGBA16F = 2,
            RGBA32F = 4,
            Depth16F = 8,
            Depth24F = 16,
            Depth32F = 32,

        };

        bgfx::TextureHandle m_Handle;
        Type                m_Type;
    };

    // TODO: do we need this
    struct PipelineHandle
    {
    public:
        PipelineHandle(std::string name);
        PipelineHandle();
        std::string Name;

        bool operator==(const PipelineHandle& other) const;
        bool operator!=(const PipelineHandle& other) const;
        bool operator< (const PipelineHandle& other) const;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(PipelineHandle, Name)
    private:
        friend class Pipeline;
    };

    class View;

    class PipelineStage
    {
    public:
        enum Type : char
        {
            PrimaryDraw,
            SecondaryDraw,
            PostProcess, 
            Compute
        };

        struct Data
        {
            bgfx::FrameBufferHandle m_FramebufferHandle;
            std::map<Attachment::Type, Attachment> m_Attachments;

        };

        NLOHMANN_JSON_SERIALIZE_ENUM(Type, {
            {PrimaryDraw, "primaryDraw"},
            {SecondaryDraw, "secondaryDraw"},
            {PostProcess, "postProcess"},
            {Compute, "compute"}
            })

        PipelineStage(
            const std::string& name, 
            Type stageType,
            WeakRef<ShaderProgram> shader, 
            Attachment::Type attachments = (Attachment::Type)(Attachment::Type::RGBA8F | Attachment::Type::Depth16F));
        PipelineStage();

        virtual Data Init(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId);
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view , bgfx::ViewId viewId);
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId);
        virtual void Cleanup();     


        bool m_HasHDRAttachment;
        bool m_HasDepthAttachment;

        Type                m_StageType;
        Attachment::Type    m_Attachments;
        std::string         m_Name;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(PipelineStage, m_Name, m_StageType, p_Shader)
    protected:
        WeakRef<ShaderProgram> p_Shader;
    };
} 