//
// Created by Admin on 6/12/2023.
//

#ifndef HARMONY_DOJO_ENTITYDATASYSTEM_H
#define HARMONY_DOJO_ENTITYDATASYSTEM_H
#include "ECS/System.h"
namespace harmony
{
    class EntityDataSystem : public System
    {
    public:
        EntityDataSystem();

        void Init(entt::registry &registry) override;

        void Update(entt::registry &registry) override;

        void Render(entt::registry &registry) override;

        void Cleanup(entt::registry &registry) override;

        nlohmann::json SerializeSystem(entt::registry &registry) override;

        void DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) override;

    protected:
        void Refresh() override;

    public:
    };
}

#endif //HARMONY_DOJO_ENTITYDATASYSTEM_H
