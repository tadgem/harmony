#include "ECS/TileMapSystemImGui.h"
#include "ECS/TileMapComponent.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_bgfx.h"
harmony::TileMapSystemImGui::TileMapSystemImGui(Ref<TileMapSystem> tileMapSystem) : p_TileMapSystem(tileMapSystem)
{

}

void harmony::TileMapSystemImGui::Init(entt::registry& registry)
{
}

void harmony::TileMapSystemImGui::Update(entt::registry& registry)
{
    auto view = registry.view<TileMapComponent>();
    if (ImGui::Begin("TileMapSystem : ImGui"))
    {
        if (ImGui::Button("Add TileMap Entity"))
        {
            const auto entity = registry.create();
            registry.emplace<TileMapComponent>(entity);
            p_SelectedTileMapEntity = entity;
        }
        if (ImGui::Button("Refresh Available Textures"))
        {
            p_AvailableTextures = p_TileMapSystem->p_AssetManager.GetLoadedAssets<Texture>();
        }
        ImGui::Separator();
        if (view.size() == 0)
        {
            ImGui::End();
            return;
        }

        std::string selectedEntityName = "Entity " + std::to_string(static_cast<uint32_t>(p_SelectedTileMapEntity));

        if (ImGui::BeginCombo("TileMap : ", selectedEntityName.c_str()))
        {
            for (auto& [entity, tileMap] : view.each())
            {
                std::string entityName = "Entity " + std::to_string(static_cast<uint32_t>(entity));
                if (ImGui::Selectable(entityName.c_str()))
                {
                    p_SelectedTileMapEntity = entity;
                }
            }
            ImGui::EndCombo();
        }
        ImGui::Separator();

        TileMapComponent& tileMap = registry.get<TileMapComponent>(p_SelectedTileMapEntity);

        ImGui::SliderInt("Tile Map Width (Cells)", &tileMap.TileMapWidth, 0, 32768);
        ImGui::SliderInt("Tile Map Height (Cells)", &tileMap.TileMapHeight, 0, 32768);
        ImGui::Separator();
        ImGui::SliderInt("Tile Width", &tileMap.TileWidth,0, 32768);
        ImGui::SliderInt("Tile Height", &tileMap.TileHeight, 0 , 32768);
        ImGui::Separator();
        ImGui::SliderInt("Padding Width", &tileMap.PaddingWidth, 0, 32768);
        ImGui::SliderInt("Padding Height", &tileMap.PaddingHeight, 0, 32768);
        ImGui::Separator();

        if (p_AvailableTextures.size() == 0)
        {
            ImGui::End();
            return;
        }

        std::string currentTexture = "";
        Ref<Texture> texture = nullptr;
        if (!p_SelectedTexture.expired())
        {
            texture = p_SelectedTexture.lock();
            currentTexture = texture->m_AssetPath;
        }
                
        if (ImGui::BeginCombo("Tile Map Texture", currentTexture.c_str()))
        {
            for (int i = 0; i < p_AvailableTextures.size(); i++)
            {
                std::string textureText = p_AvailableTextures[i].lock()->m_AssetPath;
                if (ImGui::Selectable(textureText.c_str()))
                {
                    p_SelectedTexture = p_AvailableTextures[i];
                }
            }
            ImGui::EndCombo();
        }

        if (texture == nullptr)
        {
            ImGui::End();
            return;
        }

        ImGui::Image(texture->m_Handle.m_Handle, ImVec2(texture->m_Handle.m_Info.width, texture->m_Handle.m_Info.height));
    }
    ImGui::End();
}

void harmony::TileMapSystemImGui::Render(entt::registry& registry)
{
}

void harmony::TileMapSystemImGui::Cleanup(entt::registry& registry)
{
}

nlohmann::json harmony::TileMapSystemImGui::SerializeSystem(entt::registry& registry)
{
    return nlohmann::json();
}

void harmony::TileMapSystemImGui::DeserializeSystem(entt::registry registry)
{
}

void harmony::TileMapSystemImGui::Refresh()
{
}
