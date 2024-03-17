#include "Core/Project.h"
#include <filesystem>
#include <optick.h>
#include "ImGui/imgui.h"

#include "Rendering/Renderer.h"

harmony::Project::Project(std::string name) : m_ProjectName(name) {
    OPTICK_EVENT();
}

void
harmony::Project::UpdateProjectComponentSerializationAttributes(std::vector<RefCntPtr<ProgramComponent>> &programComponents) {
    OPTICK_EVENT();
    p_ProgramComponentSerializationAttributes.clear();

    for (int i = 0; i < programComponents.size(); i++) {
        auto pcRef = programComponents[i];
        p_ProgramComponentSerializationAttributes.emplace(pcRef->m_TypeHash, pcRef->ToJson());
    }
}

void harmony::Project::UpdateProjectAssetsSerializationAttributes(AssetManager &assetManager) {
    OPTICK_EVENT();
    m_AssetManagerSerializationAttributes = assetManager.Serialize();
}

void harmony::Project::UpdateRendererSerializationAttributes(Renderer &renderer) {
    OPTICK_EVENT();
    m_RendererSerializationAttributes = renderer.Serialize();
}
