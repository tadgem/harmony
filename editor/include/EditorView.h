#pragma once
#include "Rendering/View.h"
#include "Rendering/Camera.h"
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

	class EditorView : public View
	{
	public:

        EditorView();
		virtual void OnPreUpdate(entt::registry& registry) override;
        virtual void OnImGui() override;
        DebugCamera Camera;

	};
}