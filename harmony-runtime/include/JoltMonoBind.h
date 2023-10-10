//
// Created by liam_ on 10/10/2023.
//
#pragma once

#include "MonoProgramComponent.h"
namespace harmony {
    class JoltMonoInternalMethodProvider : public MonoInternalMethodProvider
    {
    public:
        JoltMonoInternalMethodProvider();

        virtual void BindInternalMethods() override;
    };
}