//
// Created by liam_ on 10/10/2023.
//
#pragma once

#include "MonoProgramComponent.h"
#include "HarmonyContactListener.h"
namespace harmony {
    class JoltMonoInternalMethodProvider : public MonoInternalMethodProvider
    {
    public:
        JoltMonoInternalMethodProvider();

        virtual void BindInternalMethods() override;
    };

    class JoltMonoContactListenerCallback : public HarmonyContactListenerCallback
    {
    public:
        void OnContactAdded(const JPH::Body &inBody1, const JPH::Body &inBody2, const JPH::ContactManifold &inManifold,
                            JPH::ContactSettings &ioSettings) override;

        void
        OnContactPersisted(const JPH::Body &inBody1, const JPH::Body &inBody2, const JPH::ContactManifold &inManifold,
                           JPH::ContactSettings &ioSettings) override;

        void
        OnContactRemoved(const JPH::Body &inBody1, const JPH::Body &inBody2, const JPH::ContactManifold &inManifold,
                         JPH::ContactSettings &ioSettings) override;

    };
}