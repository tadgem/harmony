#pragma once
#include "entt.hpp"
#include "Core/Memory.h"
#include "Rendering/Shader.h"
#include "Rendering/View.h"
namespace harmony
{
    class PipelineStage
    {
    public:
        enum class Type
        {
            Draw,
            PostProcess
        };

        PipelineStage(Type stageType, WeakRef<ShaderProgram> shader);

        virtual void Init(entt::registry& registry, WeakRef<View> view);
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view);
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view);
        virtual void Cleanup() = 0;

        virtual bgfx::FrameBufferHandle GetStageFinalFramebuffer();

        const bgfx::ViewId m_ViewId;
        Type m_StageType;
    protected:
        bgfx::FrameBufferHandle p_FrameBufferHandle;
        WeakRef<ShaderProgram> p_Shader;
    };
} 