#include <optick.h>
#include "Core/Memory.h"
#include "ECS/LightSystem.h"
#include "ECS/LightComponents.h"
#include "ECS/SkyComponent.h"

#if HARMONY_DEBUG

#include "ECS/TransformComponent.h"
#include "Rendering/Debug/GfxDebug.h"

#endif

harmony::LightSystem::LightSystem() : System(GetTypeHash<LightSystem>()) {
    OPTICK_EVENT();
}

void harmony::LightSystem::Init(entt::registry &registry) {
    OPTICK_EVENT();
}

void harmony::LightSystem::Update(entt::registry &registry) {
    OPTICK_EVENT();

#if HARMONY_DEBUG
    auto dlView = registry.view<DirectionalLight, TransformComponent>();
    auto plView = registry.view<PointLight, TransformComponent>();
    auto slView = registry.view<SpotLight, TransformComponent>();
    GfxDebug::Get()->setWireframe(GfxDebug::Editor, true);
    GfxDebug::Get()->setColor(GfxDebug::Editor, 0x44FFFFFF);
    for (auto [e, dl, t]: dlView.each()) {
        auto b = bx::Vec3(0.0f, 0.0f, 0.0f);
        auto end = bx::Vec3(b.x + t.Forward.x, b.y + t.Forward.y, b.z + t.Forward.z);
        GfxDebug::Get()->drawCylinder(GfxDebug::Editor, b, end, 1.0f);
    }
    for (auto [e, p, t]: plView.each()) {
        bx::Sphere s;
        s.center = bx::Vec3(t.Position.x, t.Position.y, t.Position.z);
        s.radius = p.Radius;
        GfxDebug::Get()->draw(GfxDebug::Editor, s);
    }

    for (auto [e, s, t]: slView.each()) {
        bx::Vec3 from(t.Position.x, t.Position.y, t.Position.z);
        glm::vec3 _to = t.Position + (t.Forward * s.Radius);
        bx::Vec3 to(_to.x, _to.y, _to.z);
        GfxDebug::Get()->drawCone(GfxDebug::Editor, to, from, s.Angle * s.Radius * 1.25f);
    }
#endif
}

void harmony::LightSystem::Render(entt::registry &registry) {
    OPTICK_EVENT();
}

void harmony::LightSystem::Cleanup(entt::registry &registry) {
    OPTICK_EVENT();
}

harmony::Json harmony::LightSystem::SerializeSystem(entt::registry &registry) {
    OPTICK_EVENT();
    Json j;
    auto dlView = registry.view<DirectionalLight>();
    auto plView = registry.view<PointLight>();
    auto slView = registry.view<SpotLight>();
    auto skyView = registry.view<SkyComponent>();
    Json dlj;
    Json plj;
    Json slj;
    Json skyj;

    for (auto [e, dl]: dlView.each()) {
        dlj[GetEntityKey(e)] = dl;
    }

    for (auto [e, pl]: plView.each()) {
        plj[GetEntityKey(e)] = pl;
    }

    for (auto [e, sl]: slView.each()) {
        slj[GetEntityKey(e)] = sl;
    }
    for (auto [e, sky]: skyView.each()) {
        skyj[GetEntityKey(e)] = sky;
    }

    j[p_DirectionalLightKey] = dlj;
    j[p_PointLightKey] = plj;
    j[p_SpotLightKey] = slj;
    j[p_SkyKey] = skyj;

    return j;
}

void harmony::LightSystem::DeserializeSystem(entt::registry &registry, Json systemJson) {
    OPTICK_EVENT();

    Json dlj = systemJson[p_DirectionalLightKey];
    Json plj = systemJson[p_PointLightKey];
    Json slj = systemJson[p_SpotLightKey];
    Json skyj = systemJson[p_SkyKey];

    for (auto entry = dlj.begin(); entry != dlj.end(); entry++) {
        entt::entity e = GetEntityFromKey(entry.key());
        Json transformJson = entry.value();
        DirectionalLight dl;
        transformJson.get_to<DirectionalLight>(dl);
        registry.emplace<DirectionalLight>(e, dl);
    }

    for (auto entry = plj.begin(); entry != plj.end(); entry++) {
        entt::entity e = GetEntityFromKey(entry.key());
        Json transformJson = entry.value();
        PointLight dl;
        transformJson.get_to<PointLight>(dl);
        registry.emplace<PointLight>(e, dl);
    }

    for (auto entry = slj.begin(); entry != slj.end(); entry++) {
        entt::entity e = GetEntityFromKey(entry.key());
        Json transformJson = entry.value();
        SpotLight dl;
        transformJson.get_to<SpotLight>(dl);
        registry.emplace<SpotLight>(e, dl);
    }

    for (auto entry = skyj.begin(); entry != skyj.end(); entry++) {
        entt::entity e = GetEntityFromKey(entry.key());
        Json skyJson = entry.value();
        SkyComponent sky;
        skyJson.get_to<SkyComponent>(sky);
        registry.emplace<SkyComponent>(e, sky);
    }
}

harmony::Json harmony::LightSystem::SerializeEntity(entt::registry& registry, entt::entity e)
{
    OPTICK_EVENT();
    Json j;

    if(registry.any_of<DirectionalLight>(e))
    {
        DirectionalLight& dl = registry.get<DirectionalLight>(e);
        j[p_DirectionalLightKey] = dl;
    }

    if(registry.any_of<PointLight>(e))
    {
        PointLight& pl = registry.get<PointLight>(e);
        j[p_PointLightKey] = pl;
    }

    if(registry.any_of<SpotLight>(e))
    {
        SpotLight& sl = registry.get<SpotLight>(e);
        j[p_SpotLightKey] = sl;
    }

    if(registry.any_of<SkyComponent>(e))
    {
        SkyComponent& sc = registry.get<SkyComponent>(e);
        j[p_SkyKey] = sc;
    }

    return j;
}

void harmony::LightSystem::DeserializeEntity(entt::registry& registry, entt::entity e, Json entityJson)
{
    OPTICK_EVENT();
    if(entityJson.contains(p_DirectionalLightKey))
    {
        DirectionalLight dl;
        entityJson[p_DirectionalLightKey].get_to<DirectionalLight>(dl);
        registry.emplace<DirectionalLight>(e, dl);
    }

    if(entityJson.contains(p_PointLightKey))
    {
        PointLight dl;
        entityJson[p_PointLightKey].get_to<PointLight>(dl);
        registry.emplace<PointLight>(e, dl);
    }

    if(entityJson.contains(p_SpotLightKey))
    {
        SpotLight sl;
        entityJson[p_SpotLightKey].get_to<SpotLight>(sl);
        registry.emplace<SpotLight>(e, sl);
    }

    if(entityJson.contains(p_SkyKey))
    {
        SkyComponent sc;
        entityJson[p_SkyKey].get_to<SkyComponent>(sc);
        registry.emplace<SkyComponent>(e, sc);
    }
}

void harmony::LightSystem::Refresh() {
    OPTICK_EVENT();
}
