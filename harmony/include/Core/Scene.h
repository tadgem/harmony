#pragma once
#include "entt.hpp"
#include "json.hpp"
#include "ECS/Entity.h"
#include "ECS/System.h"
#include "Core/Memory.h"
namespace harmony
{
    class Scene
    {
        public:
        Scene();

        entt::registry m_Registry;
    protected:
        void UpdateSceneSystemSerializationAttributes(std::vector<Ref<System>>& systems);
        std::map<size_t, nlohmann::json>    p_SystemSerializationAttributes;
        friend class Program;
    };
};