//
// Created by liam_ on 9/24/2023.
//

#pragma once

#include "Core/Memory.h"
#include "ECS/System.h"

namespace harmony {
    class MonoProgramComponent;

    class MonoSystem : public System {
    public:
        MonoSystem(WeakRef<MonoProgramComponent> mono);

        virtual void Init(entt::registry &registry) override;

        virtual void Update(entt::registry &registry) override;

        virtual void Render(entt::registry &registry) override;

        virtual void Cleanup(entt::registry &registry) override;

        virtual nlohmann::json SerializeSystem(entt::registry &registry) override;

        virtual void DeserializeSystem(entt::registry &registry, nlohmann::json systemJson) override;

        virtual void Refresh() override;

    protected:
        WeakRef<MonoProgramComponent> p_Mono;
    };
}