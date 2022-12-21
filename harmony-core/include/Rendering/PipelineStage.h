#pragma once
#include "ThirdParty/entt.hpp"
#include "ThirdParty/json.hpp"
#include "Core/Memory.h"
#include "Rendering/ShaderDataContainer.h"
namespace harmony
{

    struct Attachment 
    {
        enum Type
        {
            Unknown = 1,
            RGBA8F = 2,
            RGBA16F = 4,
            RGBA32F = 8,
            Depth16F = 16,
            Depth24F = 32,
            Depth32F = 64,

        };

        friend Type operator|(Type a, Type b)
        {
            return static_cast<Type>(static_cast<int>(a) | static_cast<int>(b));
        }
        friend Type operator&(Type a, Type b)
        {
            return static_cast<Type>(static_cast<int>(a) & static_cast<int>(b));
        }
        friend Type operator^(Type a, Type b)
        {
            return static_cast<Type>(static_cast<int>(a) ^ static_cast<int>(b));
        }
        friend Type& operator|=(Type& a, Type b)
        {
            return (Type&)((int&)a |= (int)b);
        }
        friend Type& operator&=(Type& a, Type b)
        {
            return (Type&)((int&)a &= (int)b);
        }
        friend Type& operator^=(Type& a, Type b)
        {
            return (Type&)((int&)a ^= (int)b);
        }
        friend Type operator~(Type a)
        {
            return static_cast<Type>(~static_cast<int>(a));
        }


        NLOHMANN_JSON_SERIALIZE_ENUM(Type, {
            {Unknown, "unknown"},
            {RGBA8F, "rgba8"},
            {RGBA16F, "rgba16"},
            {RGBA32F, "rgba32"},
            {Depth16F, "d16"},
            {Depth24F, "d24"},
            {Depth32F, "d32"}
            })

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
        uint32_t Index;

        bool operator==(const PipelineHandle& other) const;
        bool operator!=(const PipelineHandle& other) const;
        bool operator< (const PipelineHandle& other) const;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(PipelineHandle, Name)
    private:
        inline static uint32_t s_InstanceCounter = 0;
        friend class Pipeline;
    };

    class View;
    class PipelineStageRenderer;
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

        NLOHMANN_JSON_SERIALIZE_ENUM(Type, {
            {Unknown, "unknown"},
            {PrimaryDraw, "primaryDraw"},
            {SecondaryDraw, "secondaryDraw"},
            {PostProcess, "postProcess"},
            {Compute, "compute"}
            })

            PipelineStage(
            const std::string& name,
            Type stageType,
            WeakRef<ShaderProgram> shader,
            WeakRef<PipelineStageRenderer> stageRenderer,
            Attachment::Type attachments = (Attachment::Type)(Attachment::Type::RGBA8F | Attachment::Type::Depth32F));

        virtual Data Init(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId);
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view , bgfx::ViewId viewId);
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId);
        virtual void Cleanup(WeakRef<View> view, bgfx::ViewId viewId);


        bool m_HasHDRAttachment;
        bool m_HasDepthAttachment;

        Type                m_StageType;
        Attachment::Type    m_Attachments;
        std::string         m_Name;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(PipelineStage, m_Name, m_StageType, p_Shader, m_Attachments, p_PipelineStageData)
    protected:
        friend class Renderer;
        WeakRef<ShaderProgram>          p_Shader;
        WeakRef<PipelineStageRenderer>  p_Renderer;
        ShaderDataContainer             p_PipelineStageData;
    };
} 