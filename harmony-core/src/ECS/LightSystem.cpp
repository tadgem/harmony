#include "Core/Memory.h"
#include "ECS/LightSystem.h"
#include "ECS/LightComponents.h"

#if HARMONY_DEBUG
#include "ECS/TransformComponent.h"
#include "Rendering/Debug/GfxDebug.h"
#endif

harmony::LightSystem::LightSystem() : System(GetTypeHash<LightSystem>())
{

}

void harmony::LightSystem::Init(entt::registry& registry)
{
}

void harmony::LightSystem::Update(entt::registry& registry)
{
#if HARMONY_DEBUG
    auto dlView = registry.view<DirectionalLight, TransformComponent>();
    auto plView = registry.view<PointLight, TransformComponent>();
    auto slView = registry.view<SpotLight, TransformComponent>();
    GfxDebug::Get()->setWireframe(GfxDebug::Editor, true);
    
    for (auto& [e, dl, t] : dlView.each())
    {
        auto b = bx::Vec3(0.0f, 0.0f, 0.0f);
        auto end = bx::Vec3(b.x + t.Forward.x, b.y + t.Forward.y, b.z + t.Forward.z);
        GfxDebug::Get()->drawCylinder(GfxDebug::Editor, b, end, 1.0f);
    }
    for (auto& [e, p, t] : plView.each())
    {
        GfxDebug::Get()->drawOrb(GfxDebug::Editor, t.Position.x, t.Position.y, t.Position.z, p.Radius);
    }

    for (auto& [e, s, t] : slView.each())
    {
        bx::Vec3 from(t.Position.x, t.Position.y, t.Position.z);
        glm::vec3 _to = t.Position + (t.Forward * s.Radius);
        bx::Vec3 to(_to.x, _to.y, _to.z);
        GfxDebug::Get()->drawCone(GfxDebug::Editor, to, from, s.Angle * s.Radius * 1.25);
    }
#endif
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
