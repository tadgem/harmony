#pragma once

#include "Core/ProgramComponent.h"
#include "sol.hpp"

namespace harmony {
    class LuaProgramComponent : public ProgramComponent {
    public:
        LuaProgramComponent();

        virtual void Init() override;

        virtual void Update() override;

        virtual void Render() override;

        virtual void Cleanup() override;

        virtual nlohmann::json ToJson() override;

        virtual void FromJson(const nlohmann::json &json) override;

    protected:
        sol::state p_State;

        friend class LuaSystem;
    };
}