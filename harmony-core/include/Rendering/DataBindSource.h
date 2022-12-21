#pragma once
#include "ThirdParty/entt.hpp"

namespace harmony 
{
    class DataBindSource
    {
        public:
        DataBindSource() {}

        virtual void Bind(entt::registry& scene) = 0;
    };
}