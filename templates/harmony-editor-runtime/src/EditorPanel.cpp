#include "EditorPanel.h"
#include "EditorUtils.h"
#include "ECS/TransformComponent.h";
#include "ECS/MeshComponent.h";
#include "ECS/MaterialComponent.h";
#include "ECS/LightComponents.h";
#include "Rendering/Model.h"
#include "ImGui/icons_font_awesome.h"
#include "ImGui/ImGuiFileDialog.h"
#include "Assets/ShaderSourceAsset.h"
#include "Assets/FontAsset.h"
#include "ECS/CameraComponent.h"
#include "Script/Lua/LuaComponent.h"
#include "ECS/SimpleCollisionSystem.h"
#include "ECS/SimpleCollisionComponent.h"
#include "JoltComponents.h"
#include "Assets/AssetManager.h"

harmony::ScenePanel::ScenePanel(Program &program) : p_Prog(program) {
}

void harmony::ScenePanel::OnImGui() {
    const std::string scenePanelTitle = std::string(ICON_FA_GLOBE) + " Scene";
    if (ImGui::Begin(scenePanelTitle.c_str())) {
        auto activeSceneWr = p_Prog.GetActiveScene();

        if (activeSceneWr.expired()) {
            ImGui::End();
            return;
        }

        Ref<Scene> activeScene = activeSceneWr.lock();

        if (ImGui::Button("Add Entity")) {
            activeScene->AddEntity();
        }
        const std::string entityNamePrefix = "Entity ";
        ImGui::Separator();
        const static int maxEntities = 50;
        int counter = 0;
        activeScene->m_Registry.each([&](entt::entity e) {
            if (counter > maxEntities) {
                return;
            }
            std::string entityName = entityNamePrefix + std::to_string(static_cast<uint32_t>(e));
            if (ImGui::Selectable(entityName.c_str())) {
                m_SelectedEntity = e;
            }
            counter++;
        });

    }
    ImGui::End();
}

harmony::EntityInspectorPanel::EntityInspectorPanel(Program &prog, Ref<ScenePanel> scenePanel) : p_Prog(prog),
                                                                                                 p_ScenePanel(
                                                                                                         scenePanel) {
}

void harmony::EntityInspectorPanel::OnImGui() {
    const std::string entityInspectorTitle = std::string(ICON_FA_INFO_CIRCLE) + " Inspector";
    if (ImGui::Begin(entityInspectorTitle.c_str())) {
        auto activeSceneWr = p_Prog.GetActiveScene();

        if (activeSceneWr.expired()) {
            ImGui::End();
            return;
        }

        Ref<Scene> activeScene = activeSceneWr.lock();

        if (activeScene->m_Registry.valid(p_ScenePanel->m_SelectedEntity) == false) {
            ImGui::End();
            return;
        }

        if (p_ComponentUIProviders.size() == 0) {
            ImGui::End();
            return;
        }

        for (int i = 0; i < p_ComponentUIProviders.size(); i++) {
            if (!p_ComponentUIProviders[i]->HasComponent(activeScene->m_Registry, p_ScenePanel->m_SelectedEntity)) {
                continue;
            }
            if (ImGui::TreeNode(p_ComponentUIProviders[i]->GetComponentName().c_str())) {
                ImGui::SameLine();
                std::string buttonText = std::string(ICON_FA_BOMB) + "##" + std::to_string(i);

                if (ImGui::Button(buttonText.c_str())) {
                    p_ComponentUIProviders[i]->RemoveComponent(activeScene->m_Registry, p_ScenePanel->m_SelectedEntity);
                    ImGui::TreePop();
                    ImGui::Separator();
                    continue;
                }

                p_ComponentUIProviders[i]->OnComponentImGui(activeScene->m_Registry, p_ScenePanel->m_SelectedEntity);
                ImGui::TreePop();
            }

            ImGui::Separator();
        }
        ImGui::Separator();
        if (ImGui::BeginCombo("Add Component", ICON_FA_PLUS_CIRCLE)) {
            for (int i = 0; i < p_ComponentUIProviders.size(); i++) {
                //p_ComponentUIProviders[i]->OnComponentImGui(activeScene->m_Registry, p_ScenePanel->m_SelectedEntity);
                if (p_ComponentUIProviders[i]->HasComponent(activeScene->m_Registry,
                                                            p_ScenePanel->m_SelectedEntity))
                    continue;
                if (ImGui::Selectable(p_ComponentUIProviders[i]->GetComponentName().c_str())) {
                    p_ComponentUIProviders[i]->AddComponent(activeScene->m_Registry, p_ScenePanel->m_SelectedEntity);
                }
            }
            ImGui::EndCombo();
        }
        ImGui::Separator();
        ImGui::PushID((uint32_t) p_ScenePanel->m_SelectedEntity);
        if (ImGui::Button("Duplicate")) {
            entt::entity dupe = activeScene->AddEntity().m_Handle;
            for (int i = 0; i < p_ComponentUIProviders.size(); i++) {
                if (p_ComponentUIProviders[i]->HasComponent(activeScene->m_Registry, p_ScenePanel->m_SelectedEntity)) {
                    p_ComponentUIProviders[i]->Duplicate(activeScene->m_Registry, p_ScenePanel->m_SelectedEntity, dupe);
                }
            }
        }
        ImGui::PopID();

    }
    ImGui::End();
}

harmony::TransformComponentUI::TransformComponentUI() : ComponentUI("Transform") {
}

void harmony::TransformComponentUI::OnComponentImGui(entt::registry &registry, entt::entity entity) {
    if (registry.valid(entity) == false) {
        return;
    }
    if (RegistryHasComponent<TransformComponent>(registry, entity) == false) {
        return;
    }
    const int _MAX = 1000;
    TransformComponent &t = registry.get<TransformComponent>(entity);
    ImGui::DragFloat3("Position", &t.Position[0]);
    ImGui::DragFloat3("Rotation", &t.Euler[0]);
    ImGui::DragFloat3("Scale", &t.Scale[0]);
}

void harmony::TransformComponentUI::AddComponent(entt::registry &registry, entt::entity entity) {
    registry.emplace<TransformComponent>(entity);
}

bool harmony::TransformComponentUI::HasComponent(entt::registry &registry, entt::entity entity) {
    return RegistryHasComponent<TransformComponent>(registry, entity);
}

void harmony::TransformComponentUI::RemoveComponent(entt::registry &registry, entt::entity entity) {
    if (HasComponent(registry, entity)) {
        registry.remove<TransformComponent>(entity);
    }
}

void harmony::TransformComponentUI::Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) {
    if (HasComponent(registry, original)) {
        TransformComponent t = registry.get<TransformComponent>(original);
        registry.emplace<TransformComponent>(newCopy, t);
    }
}

harmony::ComponentUI::ComponentUI(const std::string name) : p_ComponentName(name) {
}

const std::string &harmony::ComponentUI::GetComponentName() {
    return p_ComponentName;
}

harmony::MeshComponentUI::MeshComponentUI(AssetManager &am) : ComponentUI("Mesh"), p_AssetManager(am) {
}

void harmony::MeshComponentUI::OnComponentImGui(entt::registry &registry, entt::entity entity) {
    if (registry.valid(entity) == false) {
        return;
    }
    if (RegistryHasComponent<MeshComponent>(registry, entity) == false) {
        return;
    }
    AssetHandle ah;
    MeshComponent &mc = registry.get<MeshComponent>(entity);
    std::string meshPath = "Mesh Asset: " + mc.MeshAsset.Path;
    ImGui::Text(meshPath.c_str());
    if (p_AssetManager.AssetTypeSelector<Mesh>("Mesh", ah)) {
        mc.MeshAsset = ah;
        harmony::log::info("Entity {} updated mesh to handle at path : {}", static_cast<uint32_t>(entity),
                           mc.MeshAsset.Path);
    }

    if (ImGui::RadioButton("Cast Shadow", &mc.CastShadow)) {
        mc.CastShadow = !mc.CastShadow;
    }
}

void harmony::MeshComponentUI::AddComponent(entt::registry &registry, entt::entity entity) {
    registry.emplace<MeshComponent>(entity);
}

void harmony::MeshComponentUI::RemoveComponent(entt::registry &registry, entt::entity entity) {
    if (HasComponent(registry, entity)) {
        registry.remove<MeshComponent>(entity);
    }
}

bool harmony::MeshComponentUI::HasComponent(entt::registry &registry, entt::entity entity) {
    return RegistryHasComponent<MeshComponent>(registry, entity);
}

void harmony::MeshComponentUI::Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) {
    if (HasComponent(registry, original)) {
        MeshComponent t = registry.get<MeshComponent>(original);
        registry.emplace<MeshComponent>(newCopy, t);
    }
}

harmony::MaterialComponentUI::MaterialComponentUI(Renderer &r, AssetManager &am) : ComponentUI("Material"),
                                                                                   p_Renderer(r), p_AssetManager(am) {
}

void harmony::MaterialComponentUI::OnComponentImGui(entt::registry &registry, entt::entity entity) {
    if (registry.valid(entity) == false) {
        return;
    }
    if (RegistryHasComponent<MaterialComponent>(registry, entity) == false) {
        return;
    }
    MaterialComponent &mc = registry.get<MaterialComponent>(entity);
    WeakRef<ShaderProgram> shaderWr = p_Renderer.GetShader(mc.Data.m_ShaderName);
    std::string sn = "Shader Name : ";

    if (shaderWr.expired() == false) {
        Ref<ShaderProgram> shader = shaderWr.lock();
        sn += shader->m_Name;
    }

    ImGui::Text(sn.c_str());
    ImGui::Separator();
    if (p_Renderer.ShaderSelector("Select Shader", shaderWr)) {
        mc.Data.UpdateOverrides(shaderWr, p_AssetManager);
    }
    ImGui::Text("Shader Variables");
    if (ImGui::TreeNode("Data")) {
        if (ImGui::TreeNode("Available Overrides")) {
            for (ShaderUniform &uniform: mc.Data.m_AvailableOverrides) {
                ImGui::Text(uniform.Name.c_str());
                ImGui::SameLine();
                std::string overrideText = "Override" + std::string("##") + std::to_string(uniform.BgfxHandle.idx);
                if (ImGui::Button(overrideText.c_str())) {
                    if (uniform.Type == bgfx::UniformType::Vec4) {
                        mc.Data.AddVec4Override(uniform, glm::vec4(0.0));
                    }

                    if (uniform.Type == bgfx::UniformType::Mat3) {
                        mc.Data.AddMat3Override(uniform, glm::mat3(0.0));
                    }

                    if (uniform.Type == bgfx::UniformType::Mat4) {
                        mc.Data.AddMat4Override(uniform, glm::mat4(0.0));
                    }

                    if (uniform.Type == bgfx::UniformType::Sampler) {
                        mc.Data.AddTextureOverride(uniform, BGFXTextureHandle());
                    }
                }
            }
            ImGui::TreePop();

        }

        ImGui::Text("Vec4");
        for (auto &[key, v]: mc.Data.m_Vec4Overrides) {
            ImGui::DragFloat4(key.Name.c_str(), &v[0]);
        }
        ImGui::Separator();
        ImGui::Text("Textures");
        for (auto &[key, handle]: mc.Data.m_TextureOverrides) {
            std::string textureName = "Tex : " + handle.Handle.Path;
            ImGui::Text(textureName.c_str());
            if (p_AssetManager.AssetTypeSelector<Texture>(key.Name, handle.Handle)) {
                WeakRef<Texture> texWr = p_AssetManager.GetAsset<Texture>(handle.Handle);
                Ref<Texture> tex = texWr.lock();
                handle.BgfxHandle = tex->m_TextureHandle.BgfxHandle;
                handle.Handle = tex->m_TextureHandle.Handle;
                handle.Info = tex->m_TextureHandle.Info;

            }
        }
        ImGui::Separator();
        ImGui::Text("Mat3");
        for (auto &[key, v]: mc.Data.m_Mat3Overrides) {
            ImGui::Text(key.Name.c_str());
        }
        ImGui::Separator();
        ImGui::Text("Mat4");
        for (auto &[key, v]: mc.Data.m_Mat4Overrides) {
            ImGui::Text(key.Name.c_str());
        }
        ImGui::Separator();

        ImGui::TreePop();
    }
}

void harmony::MaterialComponentUI::AddComponent(entt::registry &registry, entt::entity entity) {
    registry.emplace<MaterialComponent>(entity);
}

void harmony::MaterialComponentUI::RemoveComponent(entt::registry &registry, entt::entity entity) {
    if (HasComponent(registry, entity)) {
        registry.remove<MaterialComponent>(entity);
    }
}

bool harmony::MaterialComponentUI::HasComponent(entt::registry &registry, entt::entity entity) {
    return RegistryHasComponent<MaterialComponent>(registry, entity);
}

void harmony::MaterialComponentUI::Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) {
    if (HasComponent(registry, original)) {
        MaterialComponent t = registry.get<MaterialComponent>(original);
        registry.emplace<MaterialComponent>(newCopy, t);
    }
}

harmony::AssetManagerPanel::AssetManagerPanel(Program &program) : p_Prog(program),
                                                                  p_AssetManager(program.m_AssetManager) {
}

void harmony::AssetManagerPanel::OnImGui() {
    const std::string assetPanelTitle = std::string(ICON_FA_FOLDER) + " Assets";

    if (ImGui::Begin(assetPanelTitle.c_str())) {
        ImGui::Indent();
        const std::string textureAssetTitle = std::string(ICON_FA_FILE_IMAGE_O) + " Textures";
        ImGui::Text(textureAssetTitle.c_str());
        std::vector<AssetHandle> texHandles = p_AssetManager.GetLoadedAssets<Texture>();
        if (ImGui::TreeNode("Textures")) {
            for (int i = 0; i < texHandles.size(); i++) {
                ImGui::Text(texHandles[i].Path.c_str());
            }
            ImGui::TreePop();

            if (ImGui::Button("Load Texture")) {
                ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenAsset", "Choose Asset", ".png,.jpg", ".");
                p_SelectedTypeHash = GetTypeHash<Texture>();
            }
        }

        ImGui::Separator();
        const std::string meshAssetTitle = std::string(ICON_FA_CUBE) + " Meshes";
        ImGui::Text(meshAssetTitle.c_str());
        std::vector<AssetHandle> meshHandles = p_AssetManager.GetLoadedAssets<Mesh>();
        if (ImGui::TreeNode("Meshes")) {
            for (int i = 0; i < meshHandles.size(); i++) {
                ImGui::Text(meshHandles[i].Path.c_str());
            }
            ImGui::TreePop();
            if (ImGui::Button("Load Mesh/Model")) {
                ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenAsset", "Choose Model",
                                                        ".fbx,.obj,.dae,.gltf,.blend", ".");
                p_SelectedTypeHash = GetTypeHash<Model>();
            }
        }

        ImGui::Separator();
        const std::string shaderSouceAssetTitle = std::string(ICON_FA_FILE_TEXT_O) + " Shader Source";
        ImGui::Text(shaderSouceAssetTitle.c_str());
        std::vector<AssetHandle> sourceHandles = p_AssetManager.GetLoadedAssets<ShaderSourceAsset>();
        if (ImGui::TreeNode("Shader Sources")) {
            for (int i = 0; i < sourceHandles.size(); i++) {
                ImGui::Text(sourceHandles[i].Path.c_str());
            }
            ImGui::TreePop();
            if (ImGui::Button("Load Shader Source")) {
                ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenAsset", "Choose Source", ".sc,.sh", ".");
                p_SelectedTypeHash = GetTypeHash<ShaderSourceAsset>();
            }
        }

        ImGui::Separator();
        const std::string shaderBinariesAssetTitle = std::string(ICON_FA_FILE_ARCHIVE_O) + " Shader Binaries";
        ImGui::Text(shaderBinariesAssetTitle.c_str());
        std::vector<AssetHandle> stageHandles = p_AssetManager.GetLoadedAssets<ShaderStage>();
        if (ImGui::TreeNode("Shader Binaries")) {
            for (int i = 0; i < stageHandles.size(); i++) {
                ImGui::Text(stageHandles[i].Path.c_str());
            }
            ImGui::TreePop();
        }

        ImGui::Separator();
        const std::string fontAssetTitle = std::string(ICON_FA_FONT) + " Fonts";
        ImGui::Text(fontAssetTitle.c_str());
        std::vector<AssetHandle> fontHandles = p_AssetManager.GetLoadedAssets<FontAsset>();
        if (ImGui::TreeNode("Fonts")) {
            for (int i = 0; i < fontHandles.size(); i++) {
                ImGui::Text(fontHandles[i].Path.c_str());
            }
            ImGui::TreePop();
            if (ImGui::Button("Load Font")) {
                ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenAsset", "Choose Source", ".ttf", ".");
                p_SelectedTypeHash = GetTypeHash<FontAsset>();
            }
        }

        ImGui::Separator();
        const std::string luaScriptAssetTitle = std::string(ICON_FA_FILE_TEXT_O) + " Lua Scripts";
        ImGui::Text(luaScriptAssetTitle.c_str());
        std::vector<AssetHandle> luaHandles = p_AssetManager.GetLoadedAssets<LuaScriptAsset>();
        if (ImGui::TreeNode("Lua Scripts")) {
            for (int i = 0; i < luaHandles.size(); i++) {
                ImGui::Text(luaHandles[i].Path.c_str());
            }
            ImGui::TreePop();
            if (ImGui::Button("Load Script")) {
                ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenAsset", "Choose Script", ".lua", ".");
                p_SelectedTypeHash = GetTypeHash<LuaScriptAsset>();
            }
        }
        ImGui::Unindent();
    }
    ImGui::End();

    if (ImGuiFileDialog::Instance()->Display("HarmonyOpenAsset")) {
        // action if OK
        if (ImGuiFileDialog::Instance()->IsOk()) {
            std::string filepath = ImGuiFileDialog::Instance()->GetFilePathName();
            p_AssetManager.LoadAsset(filepath, p_SelectedTypeHash);
        }
        ImGuiFileDialog::Instance()->Close();
    }
}

harmony::CameraComponentUI::CameraComponentUI(Renderer &r) : ComponentUI("Camera"), p_Renderer(r) {
}

void harmony::CameraComponentUI::OnComponentImGui(entt::registry &registry, entt::entity entity) {
    if (registry.valid(entity) == false) {
        return;
    }
    if (RegistryHasComponent<CameraComponent>(registry, entity) == false) {
        return;
    }

    CameraComponent &c = registry.get<CameraComponent>(entity);
    ImGui::DragFloat("Aspect", &c.Cam.Aspect);
    ImGui::DragFloat("FOV", &c.Cam.FOV);
    ImGui::DragFloat("Near Clip Plane", &c.Cam.NearClipPlane);
    ImGui::DragFloat("Far Clip Plane", &c.Cam.FarClipPlane);
}

void harmony::CameraComponentUI::AddComponent(entt::registry &registry, entt::entity entity) {
    CameraComponent &c = registry.emplace<CameraComponent>(entity);
    c.Cam.Width = 1280;
    c.Cam.Height = 720;
    c.Cam.Type = Camera::Perspective;
    c.Cam.FOV = 75.0f;
    c.Cam.Aspect = 1.333f;
    c.Cam.NearClipPlane = 0.01f;
    c.Cam.FarClipPlane = 30.0f;
}

void harmony::CameraComponentUI::RemoveComponent(entt::registry &registry, entt::entity entity) {
    if (HasComponent(registry, entity)) {
        registry.remove<CameraComponent>(entity);
    }
}

bool harmony::CameraComponentUI::HasComponent(entt::registry &registry, entt::entity entity) {
    return RegistryHasComponent<CameraComponent>(registry, entity);
}

void harmony::CameraComponentUI::Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) {
    if (HasComponent(registry, original)) {
        CameraComponent t = registry.get<CameraComponent>(original);
        registry.emplace<CameraComponent>(newCopy, t);
    }
}

harmony::DirectionalLightComponentUI::DirectionalLightComponentUI() : ComponentUI("Directional Light") {
}

void harmony::DirectionalLightComponentUI::OnComponentImGui(entt::registry &registry, entt::entity entity) {
    if (registry.valid(entity) == false) {
        return;
    }
    if (RegistryHasComponent<DirectionalLight>(registry, entity) == false) {
        return;
    }

    DirectionalLight &dl = registry.get<DirectionalLight>(entity);

    ImGui::ColorEdit4("Diffuse", &dl.Diffuse[0]);
    ImGui::ColorEdit4("Ambient", &dl.Ambient[0]);
}

void harmony::DirectionalLightComponentUI::AddComponent(entt::registry &registry, entt::entity entity) {
    registry.emplace<DirectionalLight>(entity);
}

void harmony::DirectionalLightComponentUI::RemoveComponent(entt::registry &registry, entt::entity entity) {
    if (HasComponent(registry, entity)) {
        registry.remove<DirectionalLight>(entity);
    }
}

bool harmony::DirectionalLightComponentUI::HasComponent(entt::registry &registry, entt::entity entity) {
    return registry.any_of<DirectionalLight>(entity);
}

void
harmony::DirectionalLightComponentUI::Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) {

}

harmony::PointLightComponentUI::PointLightComponentUI() : ComponentUI("Point Light") {
}

void harmony::PointLightComponentUI::OnComponentImGui(entt::registry &registry, entt::entity entity) {
    if (registry.valid(entity) == false) {
        return;
    }
    if (RegistryHasComponent<PointLight>(registry, entity) == false) {
        return;
    }

    PointLight &pl = registry.get<PointLight>(entity);

    ImGui::ColorEdit4("Diffuse", &pl.Diffuse[0]);
    ImGui::ColorEdit4("Ambient", &pl.Ambient[0]);
    ImGui::SliderFloat("Range", &pl.Radius, 0.0f, 500.0f);
    ImGui::SliderFloat("Intensity", &pl.Intensity, 0.0f, 1000.0f);
}

void harmony::PointLightComponentUI::AddComponent(entt::registry &registry, entt::entity entity) {
    registry.emplace<PointLight>(entity);
}

void harmony::PointLightComponentUI::RemoveComponent(entt::registry &registry, entt::entity entity) {
    if (HasComponent(registry, entity)) {
        registry.remove<PointLight>(entity);
    }
}

bool harmony::PointLightComponentUI::HasComponent(entt::registry &registry, entt::entity entity) {
    return registry.any_of<PointLight>(entity);
}

void harmony::PointLightComponentUI::Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) {
    if (HasComponent(registry, original)) {
        PointLight t = registry.get<PointLight>(original);
        registry.emplace<PointLight>(newCopy, t);
    }
}

harmony::SpotLightComponentUI::SpotLightComponentUI() : ComponentUI("Spot Light") {
}

void harmony::SpotLightComponentUI::OnComponentImGui(entt::registry &registry, entt::entity entity) {
    if (registry.valid(entity) == false) {
        return;
    }
    if (HasComponent(registry, entity) == false) {
        return;
    }

    SpotLight &sl = registry.get<SpotLight>(entity);

    ImGui::ColorEdit4("Diffuse", &sl.Diffuse[0]);
    ImGui::ColorEdit4("Ambient", &sl.Ambient[0]);
    ImGui::SliderFloat("Range", &sl.Radius, 0.0f, 100.0f);
    ImGui::SliderFloat("Angle", &sl.Angle, 0.0f, 3.14f);
    ImGui::SliderFloat("Intensity", &sl.Intensity, 0.0f, 1000.0f);
}

void harmony::SpotLightComponentUI::AddComponent(entt::registry &registry, entt::entity entity) {
    registry.emplace<SpotLight>(entity);
}

void harmony::SpotLightComponentUI::RemoveComponent(entt::registry &registry, entt::entity entity) {
    if (HasComponent(registry, entity)) {
        registry.remove<SpotLight>(entity);
    }
}

bool harmony::SpotLightComponentUI::HasComponent(entt::registry &registry, entt::entity entity) {
    return registry.any_of<SpotLight>(entity);
}

void harmony::SpotLightComponentUI::Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) {
    if (HasComponent(registry, original)) {
        SpotLight t = registry.get<SpotLight>(original);
        registry.emplace<SpotLight>(newCopy, t);
    }
}

harmony::LuaScriptComponentUI::LuaScriptComponentUI(AssetManager &am) : ComponentUI("Lua Scripts"), p_AssetManager(am) {
}

void harmony::LuaScriptComponentUI::OnComponentImGui(entt::registry &registry, entt::entity entity) {
    if (registry.valid(entity) == false) {
        return;
    }
    if (HasComponent(registry, entity) == false) {
        return;
    }
    AssetHandle ah;
    LuaComponent &lc = registry.get<LuaComponent>(entity);

    std::string luaPath = "Lua Script Asset: " + lc.m_LuaScriptAsset.m_Handle.Path;
    ImGui::Text(luaPath.c_str());
    if (p_AssetManager.AssetTypeSelector<LuaScriptAsset>("Lua Script", ah)) {
        // oh lord please help me no
        lc.m_LuaScriptAsset = *p_AssetManager.GetAsset<LuaScriptAsset>(ah).lock();
        lc.m_LuaScriptAsset.m_Handle = ah;
    }
}

void harmony::LuaScriptComponentUI::AddComponent(entt::registry &registry, entt::entity entity) {
    registry.emplace<LuaComponent>(entity);
}

void harmony::LuaScriptComponentUI::RemoveComponent(entt::registry &registry, entt::entity entity) {
    if (HasComponent(registry, entity)) {
        registry.remove<LuaComponent>(entity);
    }
}

bool harmony::LuaScriptComponentUI::HasComponent(entt::registry &registry, entt::entity entity) {
    return registry.any_of<LuaComponent>(entity);
}

void harmony::LuaScriptComponentUI::Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) {
    if (HasComponent(registry, original)) {
        LuaComponent t = registry.get<LuaComponent>(original);
        registry.emplace<LuaComponent>(newCopy, t);
    }
}


harmony::AABBComponentUI::AABBComponentUI(AssetManager &am) : ComponentUI("AABB Collider"), p_AssetManager(am) {
}

void harmony::AABBComponentUI::OnComponentImGui(entt::registry &registry, entt::entity entity) {
    if (registry.valid(entity) == false) {
        return;
    }
    if (HasComponent(registry, entity) == false) {
        return;
    }

    AABBColliderComponent &aabb = registry.get<AABBColliderComponent>(entity);

    AssetHandle ah;
    if (p_AssetManager.AssetTypeSelector<Mesh>("Mesh Asset", ah, aabb.m_MeshHandle.Path)) {
        aabb.m_MeshHandle = ah;
    }
}

void harmony::AABBComponentUI::AddComponent(entt::registry &registry, entt::entity entity) {
    registry.emplace<AABBColliderComponent>(entity);
}

void harmony::AABBComponentUI::RemoveComponent(entt::registry &registry, entt::entity entity) {
    if (HasComponent(registry, entity)) {
        registry.remove<AABBColliderComponent>(entity);
    }
}

bool harmony::AABBComponentUI::HasComponent(entt::registry &registry, entt::entity entity) {
    return registry.any_of<AABBColliderComponent>(entity);
}

void harmony::AABBComponentUI::Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) {
    if (HasComponent(registry, original)) {
        AABBColliderComponent t = registry.get<AABBColliderComponent>(original);
        registry.emplace<AABBColliderComponent>(newCopy, t);
    }
}

harmony::SphereComponentUI::SphereComponentUI() : ComponentUI("Sphere Collider") {
}

void harmony::SphereComponentUI::OnComponentImGui(entt::registry &registry, entt::entity entity) {
    if (registry.valid(entity) == false) {
        return;
    }
    if (HasComponent(registry, entity) == false) {
        return;
    }
    SphereColliderComponent &s = registry.get<SphereColliderComponent>(entity);

    ImGui::DragFloat("Radius", &s.m_Radius, 1.0f, 0.0, 5000.0f);
}

void harmony::SphereComponentUI::AddComponent(entt::registry &registry, entt::entity entity) {
    registry.emplace<SphereColliderComponent>(entity);
}

void harmony::SphereComponentUI::RemoveComponent(entt::registry &registry, entt::entity entity) {
    if (HasComponent(registry, entity)) {
        registry.remove<SphereColliderComponent>(entity);
    }
}

bool harmony::SphereComponentUI::HasComponent(entt::registry &registry, entt::entity entity) {
    return registry.any_of<SphereColliderComponent>(entity);
}

void harmony::SphereComponentUI::Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) {
    if (HasComponent(registry, original)) {
        SphereColliderComponent t = registry.get<SphereColliderComponent>(original);
        registry.emplace<SphereColliderComponent>(newCopy, t);
    }
}

harmony::SimpleCollisionSystemPanel::SimpleCollisionSystemPanel(Program &program) : p_Prog(program) {
    p_CollisionSystem = p_Prog.GetSystem<SimpleCollisionSystem>().lock();
}

void harmony::SimpleCollisionSystemPanel::OnImGui() {
    const std::string collisionTitle = std::string(ICON_FA_MAP) + " Collision System";

    if (ImGui::Begin(collisionTitle.c_str())) {
        if (ImGui::RadioButton("Draw Debug", p_CollisionSystem->m_DebugDraw)) {
            p_CollisionSystem->m_DebugDraw = !p_CollisionSystem->m_DebugDraw;
        }
    }
    ImGui::End();
}

harmony::JoltBodyComponentUI::JoltBodyComponentUI() : ComponentUI("Jolt Body") {
}

void harmony::JoltBodyComponentUI::OnComponentImGui(entt::registry &registry, entt::entity entity) {
    if (registry.valid(entity) == false) {
        return;
    }
    if (HasComponent(registry, entity) == false) {
        return;
    }
    JoltBodyComponent &b = registry.get<JoltBodyComponent>(entity);

    const char *motionTypeNames[3] = {"Static", "Kinematic", "Dynamic"};
    const char *shapeNames[6] = {"Box", "Sphere", "Capsule", "Cylinder", "MeshShape", "Compound"};


    if (ImGui::ListBox("Motion Type", (int *) &b.MotionType, motionTypeNames, 3)) {
        b.RequiresUpdate = true;
    }
    if (ImGui::ListBox("Shape", (int *) &b.Shape, shapeNames, 6)) {
        b.RequiresUpdate = true;
    }

    ImGui::SliderFloat("Friction", &b.Friction, 0.0f, 1.0f);
    ImGui::SliderFloat("Restitution", &b.Restitution, 0.0f, 1.0f);
}

void harmony::JoltBodyComponentUI::AddComponent(entt::registry &registry, entt::entity entity) {
    registry.emplace<JoltBodyComponent>(entity);
}

void harmony::JoltBodyComponentUI::RemoveComponent(entt::registry &registry, entt::entity entity) {
    if (HasComponent(registry, entity)) {
        registry.remove<JoltBodyComponent>(entity);
    }
}

bool harmony::JoltBodyComponentUI::HasComponent(entt::registry &registry, entt::entity entity) {
    return registry.any_of<JoltBodyComponent>(entity);
}

void harmony::JoltBodyComponentUI::Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) {
    if (HasComponent(registry, original)) {
        JoltBodyComponent t = registry.get<JoltBodyComponent>(original);
        registry.emplace<JoltBodyComponent>(newCopy, t);
    }
}
