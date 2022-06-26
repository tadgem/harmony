#pragma once
#include "entt.hpp"
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
    private:
        inline static uint16_t p_Counter = 0;
    };


    class PipelineStage
    {
    public:
        enum Type
        {
            PrimaryDraw,
            SecondaryDraw,
            PostProcess
        };

        PipelineStage(Type stageType, WeakRef<ShaderProgram> shader);

        virtual void Init(entt::registry& registry, WeakRef<View> view, PipelineHandle handle);
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle);
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view, PipelineHandle handle);
        virtual void Cleanup() = 0;

        virtual bgfx::FrameBufferHandle GetStageFinalFramebuffer();

        const bgfx::ViewId m_ViewId;

        Type m_StageType;
    protected:
        bgfx::FrameBufferHandle p_FrameBufferHandle;
        WeakRef<ShaderProgram> p_Shader;
    };
} 