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
        float Speed;
        bool Focussed = true;

        void UpdateProjection(glm::mat4 projection);
        void Update();
    };

	class EditorView : public View
	{
	public:

        EditorView(Program& program, Ref<ScenePanel> scenePanel );
		virtual void OnPreUpdate(entt::registry& registry) override;
        virtual void OnResized(uint32_t w, uint32_t h) override;
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