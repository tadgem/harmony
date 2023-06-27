#include <optick.h>
#include "Rendering/Views/RuntimeView.h"
#include "ECS/CameraComponent.h"
#include "Core/Program.h"

#if HARMONY_DEBUG

#include "ImGui/imgui_bgfx.h"
#include "ImGui/icons_font_awesome.h"
#include "Rendering/GPUResourceManager.h"

#endif

harmony::RuntimeView::RuntimeView(Program &prog) : View("RuntimeView"), p_Program(prog), p_Renderer(prog.m_Renderer) {
    OPTICK_EVENT();
    CameraEntity = (entt::entity) UINT32_MAX;
}

void harmony::RuntimeView::OnPreUpdate(entt::registry &registry) {
    OPTICK_EVENT();
    if (!registry.valid(CameraEntity)) {
        return;
    }
    if (registry.any_of<CameraComponent>(CameraEntity)) {
        CameraComponent &component = registry.get<CameraComponent>(CameraEntity);
        m_View = component.Cam.View;
        m_Projection = component.Cam.Projection;
        component.Cam.Type = Camera::Perspective;
    }
}

void harmony::RuntimeView::OnResized(uint32_t w, uint32_t h) {
    OPTICK_EVENT();
    if (p_Program.GetActiveScene().expired()) {
        harmony::log::warn("RuntimeView : Cannot resize view, no active scene!");
        return;
    }

    View::OnResized(w, h);
    Ref<Scene> scene = p_Program.GetActiveScene().lock();
    if (!scene->m_Registry.valid(CameraEntity)) {
        harmony::log::warn("RuntimeView : Cannot find camera on entity {}", static_cast<uint32_t>(CameraEntity));
        return;
    }
    if (scene->m_Registry.any_of<CameraComponent>(CameraEntity)) {
        CameraComponent &c = scene->m_Registry.get<CameraComponent>(CameraEntity);
        if (m_ProjectionType == ProjectionType::Perspective) {
            c.Cam.Projection = glm::mat4(1.0);
            c.Cam.Projection = glm::perspectiveFov(glm::radians(c.Cam.FOV), static_cast<float>(m_Width),
                                                   static_cast<float>(m_Height), c.Cam.NearClipPlane,
                                                   c.Cam.FarClipPlane);
            c.Cam.Width = w;
            c.Cam.Height = h;
        }
    }
}


#if HARMONY_DEBUG

void harmony::RuntimeView::OnImGui() {
    OPTICK_EVENT();
    if (p_Program.GetActiveScene().expired()) {
        return;
    }

    Ref<Scene> scene = p_Program.GetActiveScene().lock();

    const std::string runtimeViewTitle = std::string(ICON_FA_PLAY_CIRCLE) + " Runtime";
    glm::mat4 mat = glm::mat4(1.0);
    auto pipeline = p_Renderer.GetViewPipeline("RuntimeView").lock();
    if (ImGui::Begin(runtimeViewTitle.c_str(), (bool *) 0, ImGuiWindowFlags_NoScrollbar)) {
        View::OnImGui();

        if (!pipeline->HasOutputFramebuffer()) {
            ImGui::End();
            return;
        }

        bgfx::TextureHandle finalImageHandle = pipeline->GetOutputFramebuffer().lock()->m_Attachments[0].m_Handle;
        if (!bgfx::isValid(finalImageHandle)) {
            ImGui::End();
            return;
        }

        ImVec2 texUvs{(float) m_Width / (float) GPUResourceManager::GetMaxFramebufferWidth(),
                      (float) m_Height / (float) GPUResourceManager::GetMaxFramebufferHeight()};

        ImGui::Image(
                finalImageHandle,
                ImGui::GetContentRegionAvail(),
                ImVec2{0.0f, 0.0f},
                texUvs
        );

        auto dim = ImGui::GetWindowSize();
    }
    ImGui::End();
}


void harmony::RuntimeView::OnImGuiOptions() {
    OPTICK_EVENT();
    if (p_Program.GetActiveScene().expired()) {
        return;
    }

    Ref<Scene> scene = p_Program.GetActiveScene().lock();
    std::string currentName = "Entity " + std::to_string(static_cast<uint32_t>(CameraEntity));
    if (ImGui::BeginCombo("Camera Entity", currentName.c_str())) {
        auto view = scene->m_Registry.view<CameraComponent>();

        for (auto [entity, camera]: view.each()) {
            std::string name = "Entity " + std::to_string(static_cast<uint32_t>(entity));
            if (ImGui::Selectable(name.c_str())) {
                CameraEntity = entity;
            }
        }

        ImGui::EndCombo();
    }
}

nlohmann::json harmony::RuntimeView::Serialize() {
    OPTICK_EVENT();
    nlohmann::json j = View::Serialize();
    j["entity"] = CameraEntity;
    return j;
}

void harmony::RuntimeView::Deserialize(nlohmann::json &json) {
    OPTICK_EVENT();
    View::Deserialize(json);
    CameraEntity = json["entity"];

}

#endif