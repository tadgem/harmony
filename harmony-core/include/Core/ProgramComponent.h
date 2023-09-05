#pragma once

#include "ThirdParty/json.hpp"
#include "Core/TypeDef.h"
namespace harmony {
    class ProgramComponent {
    public:


        virtual ~ProgramComponent() {};

        virtual void Init() = 0;

        virtual void Update() = 0;

        virtual void Render() = 0;

        virtual void Cleanup() = 0;

        virtual nlohmann::json ToJson() = 0;

        virtual void FromJson(const nlohmann::json &json) = 0;

        HashString m_TypeHash;
    protected:
        friend class Program;

        ProgramComponent(const HashString& typeHash);
        virtual void Refresh() {};
    };
};