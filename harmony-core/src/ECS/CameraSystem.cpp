#include "ECS/CameraSystem.h"
#include "ECS/CameraComponent.h"
#include "ECS/TransformComponent.h"
#include "Core/Memory.h"
#include "Core/MathsUtils.h"
#include "Core/Program.h"
#ifdef HARMONY_DEBUG
#include "Rendering/Debug/GfxDebug.h"
#endif

harmony::CameraSystem::CameraSystem() : System(GetTypeHash<CameraSystem>())
{
}

void harmony::CameraSystem::Init(entt::registry& registry)
{
}

void harmony::CameraSystem::Update(entt::registry& registry)
{
    auto view = registry.view<TransformComponent, CameraComponent>();

    for (auto [entity, t,  c] : view.each())
    {
        glm::quat qPitch    = glm::angleAxis(glm::radians(-t.Euler.x), glm::vec3(1, 0, 0));
        glm::quat qYaw      = glm::angleAxis(glm::radians( t.Euler.y), glm::vec3(0, 1, 0));
        glm::quat rot       = glm::normalize(qPitch * qYaw);
        
        glm::mat4 rotate    = glm::mat4_cast(rot);
        glm::mat4 translate = glm::mat4(1.0f);
        translate           = glm::translate(translate, -t.Position);

        c.Cam.View = rotate * translate;

#ifdef  HARMONY_DEBUG
        glm::mat4 viewProj  = c.Cam.Projection * c.Cam.View;
        GfxDebug::Get()->setColor(GfxDebug::Channel::Editor, 0xaaffffff);
        GfxDebug::Get()->drawFrustum(GfxDebug::Channel::Editor, &viewProj[0]);
#endif 

    }
}

void harmony::CameraSystem::Render(entt::registry& registry)
{
}

void harmony::CameraSystem::Cleanup(entt::registry& registry)
{
}

nlohmann::json harmony::CameraSystem::SerializeSystem(entt::registry& registry)
{
    nlohmann::json j;

    auto view = registry.view<CameraComponent>();

    for (auto [e, c] : view.each())
    {
        j[GetEntityKey(e)] = c;
    }

    return j;
}

void harmony::CameraSystem::DeserializeSystem(entt::registry& registry, nlohmann::json systemJson)
{
    for (auto entry = systemJson.begin(); entry != systemJson.end(); entry++)
    {
        entt::entity e = GetEntityFromKey(entry.key());
        nlohmann::json transformJson = entry.value();
        CameraComponent cc;
        transformJson.get_to<CameraComponent>(cc);

        registry.emplace<CameraComponent>(e, cc);
    }
}

void harmony::CameraSystem::Refresh()
{
}