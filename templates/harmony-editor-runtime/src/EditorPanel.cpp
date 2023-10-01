#include "EditorPanel.h"
#include "EditorUtils.h"
#include "ECS/TransformComponent.h"
#include "ECS/MeshComponent.h"
#include "ECS/MaterialComponent.h"
#include "ECS/LightComponents.h"
#include "Rendering/Model.h"
#include "ImGui/icons_font_awesome.h"
#include "ImGui/ImGuiFileDialog.h"
#include "Assets/ShaderSourceAsset.h"
#include "Assets/FontAsset.h"
#include "ECS/CameraComponent.h"
#include "Script/Lua/LuaComponent.h"
#include "JoltComponents.h"
#include "Assets/AssetManager.h"
#include "Core/Input.h"
#include "ECS/SkyComponent.h"
#include "Script/Lua/LuaProgramComponent.h"
#include "MonoAssembly.h"
#include "MonoProgramComponent.h"
#include "MonoSystem.h"

harmony::ScenePanel::ScenePanel(Program &program) : p_Prog(program) {
}

void harmony::ScenePanel::OnImGui() {
    p_FrameHandledEntities.clear();
    const std::string scenePanelTitle = std::string(ICON_FA_GLOBE) + " Scene";
    if (ImGui::Begin(scenePanelTitle.c_str())) {
        auto activeSceneWr = p_Prog.GetActiveScene();

        if (activeSceneWr.expired()) {
            ImGui::End();
            return;
        }
        RefCntPtr<Scene> activeScene = activeSceneWr.lock();
        if (ImGui::BeginDragDropTarget()) {
            if (const ImGuiPayload *payload = ImGui::AcceptDragDropPayload("ENTITY")) {
                IM_ASSERT(payload->DataSize == sizeof(entt::entity));
                entt::entity payloadEntity = *(entt::entity *) payload->Data;

                EntityData &payloadData = activeScene->m_Registry.get<EntityData>(payloadEntity);
                payloadData.m_Parent = (entt::entity) UINT32_MAX;
            }
            ImGui::EndDragDropTarget();
        }
        ImGui::BeginChild("SceneChildID", ImGui::GetWindowContentRegionMax(), true, ImGuiWindowFlags_ChildWindow);


        if (ImGui::Button("Add Entity")) {
            activeScene->AddEntity();
        }
        ImGui::Separator();
        activeScene->m_Registry.each([&](entt::entity e) { EntityImGui(e, activeScene->m_Registry, true); });
        ImGui::EndChild();

    }
    ImGui::End();
}

void harmony::ScenePanel::EntityImGui(entt::entity e, entt::registry &reg, bool topLevel) {
    if (std::find(p_FrameHandledEntities.begin(), p_FrameHandledEntities.end(), e) != p_FrameHandledEntities.end()) {
        return;
    }

    if (!reg.any_of<EntityData>(e)) {
        reg.emplace<EntityData>(e);
    }
    auto &data = reg.get<EntityData>(e);

    if ((uint32_t) data.m_Parent != UINT32_MAX && topLevel) {
        return;
    }
    p_FrameHandledEntities.emplace_back(e);

    ImGui::PushID((uint32_t) e);
    if (p_RenamingSelectedEntity && e == m_SelectedEntity) {
        ImGui::InputText("##rename", data.m_Name.data(), data.m_Name.capacity());
        p_RenamingSelectedEntity = !ImGui::IsKeyDown(ImGuiKey_Enter);
    } else {
        if (ImGui::TreeNodeEx("##id", ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_AllowItemOverlap)) {
            ImGui::SameLine();
            EntityNameRename(e, data);
            EntityDragDrop(e, reg);
            reg.each([&](entt::entity compare) {
                         auto data = reg.get<EntityData>(compare);
                         if (data.m_Parent == e) {
                             EntityImGui(compare, reg, false);
                         }
                     }
            );
            ImGui::TreePop();
        } else {
            reg.each([&](entt::entity compare) {
                auto data = reg.get<EntityData>(compare);
                if (data.m_Parent == e) {
                    p_FrameHandledEntities.emplace_back(compare);
                }
            });
            ImGui::SameLine();
            EntityNameRename(e, data);
            EntityDragDrop(e, reg);
        }


    }
    ImGui::PopID();
}

void harmony::ScenePanel::EntityNameRename(entt::entity e, harmony::EntityData &data) {
    if (ImGui::Selectable(data.m_Name.c_str(), false, ImGuiSelectableFlags_AllowItemOverlap)) {
        m_SelectedEntity = e;
    }
    if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)) {
        p_RenamingSelectedEntity = true;
    }

}

void harmony::ScenePanel::EntityDragDrop(entt::entity e, entt::registry &reg) {
    EntityData &data = reg.get<EntityData>(e);
    if (ImGui::BeginDragDropSource()) {
        ImGui::SetDragDropPayload("ENTITY", &e, sizeof(entt::entity));
        ImGui::TextWrapped(data.m_Name.c_str());
        ImGui::EndDragDropSource();
    }
    if (ImGui::BeginDragDropTarget()) {
        if (const ImGuiPayload *payload = ImGui::AcceptDragDropPayload("ENTITY")) {
            IM_ASSERT(payload->DataSize == sizeof(entt::entity));
            entt::entity *payloadEntity = (entt::entity *) payload->Data;

            if ((uint32_t) *payloadEntity != UINT32_MAX) {
                auto &payloadData = reg.get<EntityData>(*payloadEntity);
                payloadData.m_Parent = e;

                *payloadEntity = (entt::entity) UINT32_MAX;

            }

        }
        ImGui::EndDragDropTarget();
    }

}

harmony::EntityInspectorPanel::EntityInspectorPanel(Program &prog, RefCntPtr<ScenePanel> scenePanel) : p_Prog(prog),
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

        RefCntPtr<Scene> activeScene = activeSceneWr.lock();

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

            if (p_ComponentUIProviders[i]->m_UiType == ComponentUI::ImGuiParentType::Custom) {
                p_ComponentUIProviders[i]->OnComponentImGui(activeScene->m_Registry, p_ScenePanel->m_SelectedEntity);
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

harmony::ComponentUI::ComponentUI(const std::string name, const ImGuiParentType uiType) : p_ComponentName(name),
                                                                                          m_UiType(uiType) {
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
    ImGui::TextWrapped(meshPath.c_str());
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
    WeakPtr<ShaderProgram> shaderWr = p_Renderer.GetShader(mc.Data.m_ShaderName);
    std::string sn = "Shader Name : ";

    if (shaderWr.expired() == false) {
        RefCntPtr<ShaderProgram> shader = shaderWr.lock();
        sn += shader->m_Name;
    }

    ImGui::TextWrapped(sn.c_str());
    ImGui::Separator();
    if (p_Renderer.ShaderSelector("Select Shader", shaderWr)) {
        mc.Data.UpdateOverrides(shaderWr, p_AssetManager);
    }
    ImGui::TextWrapped("Shader Variables");
    if (ImGui::TreeNode("Data")) {
        if (ImGui::TreeNode("Available Overrides")) {
            for (ShaderUniform &uniform: mc.Data.m_AvailableOverrides) {
                ImGui::TextWrapped(uniform.Name.c_str());
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

        ImGui::TextWrapped("Vec4");
        for (auto &[key, v]: mc.Data.m_Vec4Overrides) {
            ImGui::DragFloat4(key.Name.c_str(), &v[0]);
        }
        ImGui::Separator();
        ImGui::TextWrapped("Textures");
        for (auto &[key, handle]: mc.Data.m_TextureOverrides) {
            std::string textureName = "Tex : " + handle.Handle.Path;
            ImGui::TextWrapped(textureName.c_str());
            if (p_AssetManager.AssetTypeSelector<TextureAsset>(key.Name, handle.Handle)) {
                auto texWr = p_AssetManager.GetAsset<TextureAsset>(handle.Handle);
                auto tex = texWr.lock();
                handle.BgfxHandle = tex->m_TextureHandle.BgfxHandle;
                handle.Handle = tex->m_TextureHandle.Handle;
                handle.Info = tex->m_TextureHandle.Info;

            }
        }
        ImGui::Separator();
        ImGui::TextWrapped("Mat3");
        for (auto &[key, v]: mc.Data.m_Mat3Overrides) {
            ImGui::TextWrapped(key.Name.c_str());
        }
        ImGui::Separator();
        ImGui::TextWrapped("Mat4");
        for (auto &[key, v]: mc.Data.m_Mat4Overrides) {
            ImGui::TextWrapped(key.Name.c_str());
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
        ImGui::TextWrapped(textureAssetTitle.c_str());
        std::vector<AssetHandle> texHandles = p_AssetManager.GetLoadedAssets<TextureAsset>();
        if (ImGui::TreeNode("Textures")) {
            for (int i = 0; i < texHandles.size(); i++) {
                ImGui::TextWrapped(texHandles[i].Path.c_str());
            }
            ImGui::TreePop();

            if (ImGui::Button("Load Texture")) {
                ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenAsset", "Choose Asset", ".png,.jpg", ".");
                p_SelectedTypeHash = GetTypeHash<TextureAsset>();
            }
        }

        ImGui::Separator();
        const std::string meshAssetTitle = std::string(ICON_FA_CUBE) + " Meshes";
        ImGui::TextWrapped(meshAssetTitle.c_str());
        std::vector<AssetHandle> meshHandles = p_AssetManager.GetLoadedAssets<Mesh>();
        if (ImGui::TreeNode("Meshes")) {
            for (int i = 0; i < meshHandles.size(); i++) {
                ImGui::TextWrapped(meshHandles[i].Path.c_str());
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
        ImGui::TextWrapped(shaderSouceAssetTitle.c_str());
        std::vector<AssetHandle> sourceHandles = p_AssetManager.GetLoadedAssets<ShaderSourceAsset>();
        if (ImGui::TreeNode("Shader Sources")) {
            for (int i = 0; i < sourceHandles.size(); i++) {
                ImGui::TextWrapped(sourceHandles[i].Path.c_str());
            }
            ImGui::TreePop();
            if (ImGui::Button("Load Shader Source")) {
                ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenAsset", "Choose Source", ".sc,.sh", ".");
                p_SelectedTypeHash = GetTypeHash<ShaderSourceAsset>();
            }
        }

        ImGui::Separator();
        const std::string shaderBinariesAssetTitle = std::string(ICON_FA_FILE_ARCHIVE_O) + " Shader Binaries";
        ImGui::TextWrapped(shaderBinariesAssetTitle.c_str());
        std::vector<AssetHandle> stageHandles = p_AssetManager.GetLoadedAssets<ShaderStage>();
        if (ImGui::TreeNode("Shader Binaries")) {
            for (int i = 0; i < stageHandles.size(); i++) {
                ImGui::TextWrapped(stageHandles[i].Path.c_str());
            }
            ImGui::TreePop();
        }

        ImGui::Separator();
        const std::string fontAssetTitle = std::string(ICON_FA_FONT) + " Fonts";
        ImGui::TextWrapped(fontAssetTitle.c_str());
        std::vector<AssetHandle> fontHandles = p_AssetManager.GetLoadedAssets<FontAsset>();
        if (ImGui::TreeNode("Fonts")) {
            for (int i = 0; i < fontHandles.size(); i++) {
                ImGui::TextWrapped(fontHandles[i].Path.c_str());
            }
            ImGui::TreePop();
            if (ImGui::Button("Load Font")) {
                ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenAsset", "Choose Source", ".ttf", ".");
                p_SelectedTypeHash = GetTypeHash<FontAsset>();
            }
        }

        ImGui::Separator();
        const std::string luaScriptAssetTitle = std::string(ICON_FA_FILE_TEXT_O) + " Lua Scripts";
        ImGui::TextWrapped(luaScriptAssetTitle.c_str());
        std::vector<AssetHandle> luaHandles = p_AssetManager.GetLoadedAssets<LuaScriptAsset>();
        if (ImGui::TreeNode("Lua Scripts")) {
            for (int i = 0; i < luaHandles.size(); i++) {
                ImGui::TextWrapped(luaHandles[i].Path.c_str());
            }
            ImGui::TreePop();
            if (ImGui::Button("Load Script")) {
                ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenAsset", "Choose Script", ".lua", ".");
                p_SelectedTypeHash = GetTypeHash<LuaScriptAsset>();
            }
        }

        const std::string monoAssemblyAssetTitle = std::string(ICON_FA_FILE_ARCHIVE_O) + " Mono Assemblies";
        ImGui::TextWrapped(monoAssemblyAssetTitle.c_str());
        std::vector<AssetHandle> assemblyHandles = p_AssetManager.GetLoadedAssets<MonoAssemblyAsset>();
        if (ImGui::TreeNode("Mono Assemblies")) {
            for (int i = 0; i < assemblyHandles.size(); i++) {
                ImGui::TextWrapped(assemblyHandles[i].Path.c_str());
            }
            ImGui::TreePop();
            if (ImGui::Button("Load Assembly")) {
                ImGuiFileDialog::Instance()->OpenDialog("HarmonyOpenAsset", "Choose Script", ".dll", ".");
                p_SelectedTypeHash = GetTypeHash<MonoAssemblyAsset>();
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

harmony::LuaScriptPanel::LuaScriptPanel(Program &prog) : p_Program(prog), p_AssetManager(prog.m_AssetManager),
                                                         p_Lua(prog.GetProgramComponent<LuaProgramComponent>()) {
}


void harmony::LuaScriptPanel::OnImGui() {
    auto lua = p_Lua.lock();
    if (ImGui::Begin("LuaScript")) {

        if (!lua) {
            p_Lua = p_Program.GetProgramComponent<LuaProgramComponent>();
            ImGui::End();
            return;
        }
        AssetHandle ah;
        if (p_AssetManager.AssetTypeSelector<LuaScriptAsset>("Add Progam Script", ah)) {
            if (std::find(lua->m_LuaProgramScripts.begin(), lua->m_LuaProgramScripts.end(), ah) !=
                lua->m_LuaProgramScripts.end()) {
                harmony::log::warn("LuaScript : Script : {} is already a program script", ah.Path);
            } else {
                lua->m_LuaProgramScripts.emplace_back(ah);
            }
        }

        ImGui::TextWrapped("Running Program Scripts");
        ImGui::Indent();
        for (int i = 0; i < lua->m_LuaProgramScripts.size(); i++) {
            ImGui::TextWrapped(lua->m_LuaProgramScripts[i].Path.c_str());
        }
        ImGui::Unindent();

    }
    ImGui::End();
}


harmony::MonoPanel::MonoPanel(harmony::Program &prog) : p_Program(prog), p_AssetManager(prog.m_AssetManager),
                                                        p_Mono(prog.GetProgramComponent<MonoProgramComponent>()){

}

void harmony::MonoPanel::OnImGui() {
    auto mono = p_Mono.lock();
    if (ImGui::Begin("Mono")) {

        if (!mono) {
            p_Mono = p_Program.GetProgramComponent<MonoProgramComponent>();
            ImGui::End();
            return;
        }

        if(ImGui::Button("Reload Mono Assemblies"))
        {
            mono->Cleanup();
            mono->Init();
            p_AssetManager.ReloadAllAssetsOfType<MonoAssemblyAsset>();
            mono->FromJson(p_Program.m_Project->p_ProgramComponentSerializationAttributes[GetTypeHash<MonoProgramComponent>().m_Value]);
        }

        auto assemblyHandles = p_Program.m_AssetManager.GetLoadedAssets<MonoAssemblyAsset>();
        if(ImGui::TreeNode("Assemblies")) {
            for (AssetHandle h: assemblyHandles) {
                RefCntPtr<MonoAssemblyAsset> a = p_Program.m_AssetManager.GetAsset<MonoAssemblyAsset>(h).lock();
                if (!a) continue;

                if (ImGui::TreeNode(h.Path.c_str())) {
                    if(ImGui::TreeNode("Assembly Info")) {
                        if (ImGui::TreeNode("Type Infos")) {
                            for (auto typeInfo: a->m_TypeInfos) {
                                ImGui::TextWrapped("%s.%s", typeInfo.m_TypeNamespace.c_str(),
                                                   typeInfo.m_TypeName.c_str());
                                ImGui::Separator();
                            }
                            ImGui::TreePop();
                        }

                        if (ImGui::TreeNode("Derived Type Infos")) {
                            for (auto typeInfo: a->m_DerivedTypeInfos) {
                                ImGui::TextWrapped("%s.%s : %s.%s",
                                                   typeInfo.m_ChildTypeNamespace.c_str(),
                                                   typeInfo.m_ChildTypeName.c_str(),
                                                   typeInfo.m_ParentTypeNamespace.c_str(),
                                                   typeInfo.m_ParentTypeName.c_str());
                                ImGui::Separator();
                            }
                            ImGui::TreePop();
                        }

                        if (ImGui::TreeNode("Type Spec Infos")) {
                            for (auto typeSpecInfo: a->m_TypeSpecInfos) {
                                ImGui::TextWrapped("%s", typeSpecInfo.m_Signature.c_str());
                                ImGui::Separator();
                            }
                            ImGui::TreePop();
                        }

                        if (ImGui::TreeNode("Interface Impl Infos")) {
                            for (auto info: a->m_InterfaceImplInfos) {
                                ImGui::TextWrapped("%s.%s [%d] : %s.%s [%d] : Type : %d", info.m_ClassNamespace.c_str(),
                                                   info.m_ClassName.c_str(), info.m_ClassIndex,
                                                   info.m_InterfaceNamespace.c_str(), info.m_InterfaceName.c_str(),
                                                   info.m_InterfaceIndex, info.m_ParentType);
                                ImGui::Separator();
                            }
                            ImGui::TreePop();
                        }

                        if (ImGui::TreeNode("Method Impl Infos")) {
                            for (auto info: a->m_MethodImplInfos) {
                                ImGui::TextWrapped("%s : %s : %s", info.m_ClassName.c_str(), info.m_Declaration.c_str(),
                                                   info.m_Body.c_str());
                                ImGui::Separator();
                            }
                            ImGui::TreePop();
                        }

                        if (ImGui::TreeNode("Type RefCntPtr Infos")) {
                            for (auto info: a->m_TypeRefInfos) {
                                ImGui::TextWrapped("%s : %s : Scope = %s", info.m_Namespace.c_str(),
                                                   info.m_Name.c_str(),
                                                   info.m_Scope.c_str());
                                ImGui::Separator();
                            }
                            ImGui::TreePop();
                        }

                        if (ImGui::TreeNode("Assembly RefCntPtr Infos")) {
                            for (auto info: a->m_AssemblyRefInfos) {
                                ImGui::TextWrapped("%s : %d.%d", info.m_Name.c_str(), info.m_Major, info.m_Minor);
                                ImGui::Separator();
                            }
                            ImGui::TreePop();
                        }
                        ImGui::TreePop();
                    }
                    if(ImGui::TreeNode("Program Components"))
                    {
                        if(ImGui::TreeNode("Add ProgramComponents")) {
                            Vector<MonoUtils::CsTypeInfo> typeInfos;
                            for (MonoUtils::CsInterfaceImplInfo info: a->m_InterfaceImplInfos) {
                                if (std::find(typeInfos.begin(), typeInfos.end(), a->m_TypeInfos[info.m_ClassIndex]) !=
                                    typeInfos.end()) {
                                    continue;
                                }
                                if (info.m_InterfaceNamespace == "Harmony.ProgramComponent") {
                                    ImGui::PushID(info.m_InterfaceIndex & info.m_ClassIndex);
                                    ImGui::TextWrapped(info.m_ClassName.c_str());
                                    ImGui::SameLine();
                                    if (ImGui::Button("Add Program Component")) {
                                        mono->AddMonoImplementedProgramComponent(a, a->m_TypeInfos[info.m_ClassIndex]);
                                    }
                                    typeInfos.emplace_back(a->m_TypeInfos[info.m_ClassIndex]);
                                    ImGui::PopID();
                                }
                            }
                            ImGui::TreePop();
                        }

                        if(ImGui::TreeNode("Running ProgramComponents"))
                        {
                            for(auto mpc : mono->p_MonoProgramComponents)
                            {
                                ImGui::TextWrapped("%s.%s", mpc.m_TypeInfo.m_TypeNamespace.c_str(),
                                                                  mpc.m_TypeInfo.m_TypeName.c_str());
                                ImGui::Separator();
                            }
                            ImGui::TreePop();
                        }

                        ImGui::TreePop();
                    }
                    ImGui::TreePop();
                }

            }
            ImGui::TreePop();
        }
        ImGui::Separator();
    }
    ImGui::End();
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
    ImGui::DragFloat("Range", &pl.Radius, 1.0f, 0.0f, 1000.0f);
    ImGui::DragFloat("Intensity", &pl.Intensity, 1.0f, 0.0f, 1000.0f);
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
    ImGui::DragFloat("Range", &sl.Radius, 1.0f, 0.0f, 100.0f);
    ImGui::DragFloat("Angle", &sl.Angle, 1.0f, 0.0f, 3.14f);
    ImGui::DragFloat("Intensity", &sl.Intensity, 1.0f, 0.0f, 1000.0f);
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
    ImGui::TextWrapped(luaPath.c_str());
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

harmony::EntityDataComponentUI::EntityDataComponentUI() : ComponentUI("Entity Data",
                                                                      ComponentUI::ImGuiParentType::Custom) {

}

void harmony::EntityDataComponentUI::OnComponentImGui(entt::registry &registry, entt::entity entity) {
    if (registry.valid(entity) == false) {
        return;
    }
    if (!HasComponent(registry, entity)) {
        return;
    }
    EntityData &data = registry.get<EntityData>(entity);
    ImGui::PushID((uint32_t) entity);
    ImGui::TextWrapped(data.m_Name.c_str());
    ImGui::SameLine();
    ImGui::Checkbox("Enabled", &data.m_Enabled);
    ImGui::SameLine();
    ImGui::Checkbox("Static", &data.m_Static);
    ImGui::TextWrapped("ID : %u", entity);
    ImGui::SameLine();
    ImGui::TextWrapped("Parent : %u", (uint32_t) data.m_Parent);

    ImGui::PopID();

}

void harmony::EntityDataComponentUI::AddComponent(entt::registry &registry, entt::entity entity) {

}

void harmony::EntityDataComponentUI::RemoveComponent(entt::registry &registry, entt::entity entity) {

}

bool harmony::EntityDataComponentUI::HasComponent(entt::registry &registry, entt::entity entity) {
    return registry.any_of<EntityData>(entity);
}

void harmony::EntityDataComponentUI::Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) {
    if (HasComponent(registry, original)) {
        EntityData t = registry.get<EntityData>(original);
        registry.emplace<EntityData>(newCopy, t);
    }
}

harmony::SkyComponentUI::SkyComponentUI() : ComponentUI("Sky") {

}

void harmony::SkyComponentUI::OnComponentImGui(entt::registry &registry, entt::entity entity) {
    if (registry.valid(entity) == false) {
        return;
    }
    if (!HasComponent(registry, entity)) {
        return;
    }
    ImGui::PushID((uint32_t) entity);
    SkyComponent &sky = registry.get<SkyComponent>(entity);
    ImGui::SliderFloat("Sun Bloom", &sky.SunBloom, 0.0f, 100.0f);
    ImGui::SliderFloat("Sun Size", &sky.SunSize, 0.0f, 0.2f);
    ImGui::SliderFloat("Exposition", &sky.Exposition, 0.0f, 1.0f);
    ImGui::SliderFloat("Turbidity", &sky.Turbidity, 1.95f, 10.0f);
    ImGui::PopID();

}

void harmony::SkyComponentUI::AddComponent(entt::registry &registry, entt::entity entity) {
    registry.emplace<SkyComponent>(entity);
}

void harmony::SkyComponentUI::RemoveComponent(entt::registry &registry, entt::entity entity) {
    if (HasComponent(registry, entity)) {
        registry.remove<SkyComponent>(entity);
    }
}

bool harmony::SkyComponentUI::HasComponent(entt::registry &registry, entt::entity entity) {
    return registry.any_of<SkyComponent>(entity);
}

void harmony::SkyComponentUI::Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy) {
    if (HasComponent(registry, original)) {
        SkyComponent t = registry.get<SkyComponent>(original);
        registry.emplace<SkyComponent>(newCopy, t);
    }
}



harmony::MonoBehaviourComponentUI::MonoBehaviourComponentUI(harmony::WeakPtr<harmony::MonoSystem> monoSystem, harmony::AssetManager &am) : ComponentUI("Mono Behaviour",
                                                                                                                                                       ComponentUI::ImGuiParentType::TreeNode), p_AssetManager(am) , p_MonoSystem(monoSystem){

}

void harmony::MonoBehaviourComponentUI::OnComponentImGui(entt::registry &registry, entt::entity entity)
{
    if (registry.valid(entity) == false) {
        return;
    }
    if (!HasComponent(registry, entity)) {
        return;
    }

    auto mono = p_MonoSystem.lock();
    if(!mono)
    {
        return;
    }
    ImGui::PushID((uint32_t) entity);
    MonoBehaviourComponent &serializedBehaviourComponent = registry.get<MonoBehaviourComponent>(entity);
    ImGui::Indent();
    for(auto& b : serializedBehaviourComponent.m_Behaviours)
    {
        ImGui::TextWrapped(b.m_TypeInfo.m_TypeName.c_str());
        ImGui::Separator();
    }
    auto assemblyHandles= p_AssetManager.GetLoadedAssets<MonoAssemblyAsset>();
    ImGui::BeginCombo("Add Mono Behaviour", "Choose Mono Behaviour");
    for(AssetHandle ah : assemblyHandles)
    {
        auto assembly = p_AssetManager.GetAsset<MonoAssemblyAsset>(ah).lock();
        if(!assembly)
        {
            continue;
        }
        // for each type in assembly
        // if type is derived from Behaviour,
        // ImGui selectable ...
    }
    ImGui::EndCombo();
    ImGui::Unindent();
    ImGui::PopID();
}
void harmony::MonoBehaviourComponentUI::AddComponent(entt::registry &registry, entt::entity entity)
{
    registry.emplace<MonoBehaviourComponent>(entity);
}
void harmony::MonoBehaviourComponentUI::RemoveComponent(entt::registry &registry, entt::entity entity)
{
    if (HasComponent(registry, entity)) {
        // TODO: Likely leaking memory here, GC wont collect objects weve allocated
        registry.remove<MonoBehaviourComponent>(entity);
    }
}
bool harmony::MonoBehaviourComponentUI::HasComponent(entt::registry &registry, entt::entity entity)
{
    return registry.any_of<MonoBehaviourComponent>(entity);
}
void harmony::MonoBehaviourComponentUI::Duplicate(entt::registry &registry, entt::entity original, entt::entity newCopy)
{

}