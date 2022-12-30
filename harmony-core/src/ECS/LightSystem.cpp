#include "Core/Memory.h"
#include "ECS/LightSystem.h"
#include "ECS/LightComponents.h"

harmony::LightSystem::LightSystem() : System(GetTypeHash<LightSystem>())
{

}

void harmony::LightSystem::Init(entt::registry& registry)
{
}

void harmony::LightSystem::Update(entt::registry& registry)
{
}

void harmony::LightSystem::Render(entt::registry& registry)
{
}

void harmony::LightSystem::Cleanup(entt::registry& registry)
{
}

nlohmann::json harmony::LightSystem::SerializeSystem(entt::registry& registry)
{
    nlohmann::json j;

    auto dlView = registry.view<DirectionalLight>();
    auto plView = registry.view<PointLight>();
    auto slView = registry.view<SpotLight>();

    nlohmann::json dlj;
    nlohmann::json plj;
    nlohmann::json slj;

    for (auto [e, dl] : dlView.each())
    {
        dlj[GetEntityKey(e)] = dl;
    }

    for (auto [e, pl] : plView.each())
    {
        plj[GetEntityKey(e)] = pl;
    }

    for (auto [e, sl] : slView.each())
    {
        slj[GetEntityKey(e)] = sl;
    }

    j["DirectionalLight"]   = dlj;
    j["PointLight"]         = plj;
    j["SpotLight"]          = slj;

    return j;
}

void harmony::LightSystem::DeserializeSystem(entt::registry& registry, nlohmann::json systemJson)
{

    nlohmann::json dlj = systemJson["DirectionalLight"];
    nlohmann::json plj = systemJson["PointLight"];
    nlohmann::json slj = systemJson["SpotLight"];

    for (auto entry = dlj.begin(); entry != dlj.end(); entry++)
    {
        entt::entity e = GetEntityFromKey(entry.key());
        nlohmann::json transformJson = entry.value();

        DirectionalLight dl;
        transformJson.get_to<DirectionalLight>(dl);
        registry.emplace<DirectionalLight>(e, dl);
    }

    for (auto entry = plj.begin(); entry != plj.end(); entry++)
    {
        entt::entity e = GetEntityFromKey(entry.key());
        nlohmann::json transformJson = entry.value();

        PointLight dl;
        transformJson.get_to<PointLight>(dl);
        registry.emplace<PointLight>(e, dl);
    }

    for (auto entry = slj.begin(); entry != slj.end(); entry++)
    {
        entt::entity e = GetEntityFromKey(entry.key());
        nlohmann::json transformJson = entry.value();

        SpotLight dl;
        transformJson.get_to<SpotLight>(dl);
        registry.emplace<SpotLight>(e, dl);
    }
}

void harmony::LightSystem::Refresh()
{
}
