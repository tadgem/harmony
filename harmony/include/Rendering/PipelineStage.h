#pragma once
#include "entt.hpp"
#include "json.hpp"
#include "Core/Memory.h"
#include "Rendering/Shader.h"
#include "Rendering/View.h"
namespace harmony
{
    struct PipelineHandle
    {
        uint16_t Index;
        std::string Name;

        static PipelineHandle New(const std::string& name);

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(PipelineHandle, Index, Name)
    private:
        friend class Pipeline;
        inline static uint16_t p_Counter = 0;
    };


    class PipelineStage
    {
    public:
        enum Type : char
        {
            PrimaryDraw,
            SecondaryDraw,
            PostProcess
        };

        NLOHMANN_JSON_SERIALIZE_ENUM(Type, {
            {PrimaryDraw, "primaryDraw"},
            {SecondaryDraw, "secondaryDraw"},
            {PostProcess, "postProcess"},
            })

        PipelineStage(const std::string& name, Type stageType, WeakRef<ShaderProgram> shader);
        PipelineStage();

        virtual void Init(entt::registry& registry, WeakRef<View> view, PipelineHandle handle);
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle);
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle);
        virtual void Cleanup();

        virtual bgfx::FrameBufferHandle GetStageFinalFramebuffer();
        virtual bgfx::TextureHandle GetStageDepthTexture();

        bgfx::ViewId m_ViewId;

        bool m_HasHDRAttachment;
        bool m_HasDepthAttachment;

        Type m_StageType;
        std::string m_Name;
        virtual Ref<PipelineStage> Clone();

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(PipelineStage, m_Name, m_StageType, p_Shader)
    protected:


        bgfx::FrameBufferHandle p_FrameBufferHandle;
        std::vector<bgfx::TextureHandle> p_Attachments;
        WeakRef<ShaderProgram> p_Shader;

        bool p_RunPreFrame;
    };
} 