#pragma once

#include "ECS/TileMapSystem.h"

namespace harmony {
    class TileMapSystemImGui : public System {
    public:
        TileMapSystemImGui(Ref<TileMapSystem> tileMapSystem);

        virtual void Init(entt::registry &registry) override;

        virtual void Update(entt::registry &registry) override;

        virtual void Render(entt::registry &registry) override;

        virtual void Cleanup(entt::registry &registry) override;

        virtual nlohmann::json SerializeSystem(entt::registry &registry) override;

        virtual void DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) override;

        virtual void Refresh() override;

    protected:
        Ref<TileMapSystem> p_TileMapSystem;
        WeakRef<TextureAsset> p_SelectedTexture;
        entt::entity p_SelectedTileMapEntity;
        std::vector<WeakRef<TextureAsset>> p_AvailableTextures;
    };
};