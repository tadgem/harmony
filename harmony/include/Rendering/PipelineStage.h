#pragma once
#include "entt.hpp"
#include "Core/Memory.h"
#include "Rendering/Shader.h"
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

        virtual void Init(entt::registry& registry, WeakRef<View> view) = 0;
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view)= 0;
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view) = 0;
        virtual void Cleanup() = 0;

        virtual bgfx::FrameBufferHandle GetStageFinalFramebuffer()  = 0;

        const bgfx::ViewId m_ViewId;
        Type m_StageType;
    protected:
        WeakRef<ShaderProgram> p_Shader;
    };
} 