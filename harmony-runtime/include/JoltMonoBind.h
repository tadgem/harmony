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

    struct JoltMonoContactListenerData
    {
        MonoMethod* m_CallbackMethod;
        MonoObject* m_Object;

        friend bool operator== (const JoltMonoContactListenerData& c1, const JoltMonoContactListenerData& c2);
        friend bool operator!= (const JoltMonoContactListenerData& c1, const JoltMonoContactListenerData& c2);

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
        OnContactRemoved(const JPH::SubShapeIDPair &inSubShapePair) override;

        bool AddCallback(JPH::Body* body, MonoObject* obj, MonoMethod* callback);
        bool RemoveCallback(JPH::Body* body, MonoObject* obj, MonoMethod* callback);

    protected:
        HashMap<JPH::Body*, Vector<JoltMonoContactListenerData>> p_MonoCallbacks;

    };
}