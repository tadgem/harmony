#pragma once

#include "Rendering/Pipeline.h"
#include "Rendering/Camera.h"
#include "Rendering/Debug/DebugDraw.h"
namespace harmony
{
    class DebugCamera : public Camera
    {
    public:
        DebugCamera();
        glm::vec3 Position;
        glm::vec3 Euler;
        float FOV;
        float Near, Far;

        bool Active = true;

        void Update();

        virtual glm::mat4 GetViewMatrix() override;
        virtual glm::mat4 GetProjectionMatrix(uint32_t width, uint32_t height) override;
    };

    class DebugDrawStage : public PipelineStage
    {
    public:
        DebugDrawStage();
        virtual void Init(entt::registry& registry, WeakRef<View> view) override;
        virtual void PreUpdate(entt::registry& registry, WeakRef<View> view) override;
        virtual void PostUpdate(entt::registry& registry, WeakRef<View> view) override;
        virtual void Cleanup() override;

        bx::DefaultAllocator p_Allocator;
        DebugCamera Camera;
        DebugDrawEncoder DebugDraw;
        bool Active;
    };

    class DebugDrawPipeline : public Pipeline
    {
    public:
        DebugDrawPipeline();
    };
};
