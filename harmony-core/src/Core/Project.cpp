#include "Core/Project.h"
#include <filesystem>
#include "ImGui/imgui.h"

#include "Rendering/Renderer.h"

harmony::Project::Project(std::string name) : m_ProjectName(name) {

}

void
harmony::Project::UpdateProjectComponentSerializationAttributes(std::vector<Ref<ProgramComponent>> &programComponents) {

    p_ProgramComponentSerializationAttributes.clear();

    for (int i = 0; i < programComponents.size(); i++) {
        auto pcRef = programComponents[i];
        p_ProgramComponentSerializationAttributes.emplace(pcRef->m_TypeHash, pcRef->ToJson());
    }
}

void harmony::Project::UpdateProjectAssetsSerializationAttributes(AssetManager &assetManager) {
    m_AssetManagerSerializationAttributes = assetManager.Serialize();
}

void harmony::Project::UpdateRendererSerializationAttributes(Renderer &renderer) {
    m_RendererSerializationAttributes = renderer.Serialize();
}
