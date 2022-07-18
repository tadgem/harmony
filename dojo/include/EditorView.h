#pragma once
#include "Rendering/View.h"
#include "Rendering/Camera.h"
#include "Rendering/Renderer.h"
#include "EditorPanel.h"
#include "ImGui/ImGuizmo.h"
namespace harmony
{
    class DebugCamera : public Camera
    {
    public:
        DebugCamera();
        glm::vec3 Position;
        glm::vec3 Euler;
        glm::quat Rotation;
        float FOV;
        float Near, Far;
        float Speed;
        bool Focussed = true;

        void Update();

        virtual glm::mat4 GetViewMatrix() override;
        virtual glm::mat4 GetProjectionMatrix(uint32_t width, uint32_t height) override;
    };

	class EditorView : public View
	{
	public:

        EditorView(Program& program, Ref<ScenePanel> scenePanel );
		virtual void OnPreUpdate(entt::registry& registry) override;
#if HARMONY_DEBUG
        virtual void OnImGui() override;
        virtual void OnImGuiOptions() override;
#endif
        DebugCamera Camera;

    protected:
        ImGuizmo::OPERATION p_Op;
        Program& p_Program;
        Renderer& p_Renderer;
        Ref<ScenePanel> p_ScenePanel;

	};
}