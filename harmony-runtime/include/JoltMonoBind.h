//
// Created by liam_ on 10/10/2023.
//
#pragma once
#include "MonoAPI.h"
#include "MonoProgramComponent.h"
#include "HarmonyContactListener.h"

extern "C"
{
    struct jolt_contact_manifold_simple
    {
        glm_vec3    base_offset;
        glm_vec3    world_space_normal;
        float       penetration_depth;
        glm_vec3    center_point;
    };

    // N.B. This will be expensive to pass between script + code
    // where possible, use jolt_contact_manifold_simple
    struct jolt_contact_manifold_extended
    {
        glm_vec3    base_offset;
        glm_vec3    world_space_normal;
        float       penetration_depth;
        glm_vec3    contact_points_b1[64];
        glm_vec3    contact_points_b2[64];
    };

    struct jolt_contact_settings
    {
        float                   combined_friction;
        float					combined_restitution;
        float					inv_mass_scale_1 = 1.0f;
        float					inv_inertia_scale_1 = 1.0f;
        float					inv_mass_scale_2 = 1.0f;
        float					inv_inertia_scale_2 = 1.0f;
        bool					is_sensor;
        glm_vec3				relative_linear_surface_velocity;
        glm_vec3				relative_angular_surface_velocity;
    };

    typedef void (*contact_callback_t) (JPH::Body* a, JPH::Body* b ,
        jolt_contact_manifold_simple manifold, jolt_contact_settings settings);

}
namespace harmony {
    class JoltMonoInternalMethodProvider : public MonoInternalMethodProvider
    {
    public:
        JoltMonoInternalMethodProvider();

        virtual void BindInternalMethods() override;
    };

    struct JoltMonoContactListenerData
    {
        contact_callback_t m_ContactCallback;

        bool operator== (const JoltMonoContactListenerData& c2) const;
        bool operator!= (const JoltMonoContactListenerData& c2) const;

    };

    class JoltMonoContactListenerCallback : public HarmonyContactListenerCallback
    {
    public:

        JoltMonoContactListenerCallback();
        void OnContactAdded(const JPH::Body &inBody1, const JPH::Body &inBody2, const JPH::ContactManifold &inManifold,
                            JPH::ContactSettings &ioSettings) override;

        void
        OnContactPersisted(const JPH::Body &inBody1, const JPH::Body &inBody2, const JPH::ContactManifold &inManifold,
                           JPH::ContactSettings &ioSettings) override;

        void
        OnContactRemoved(const JPH::SubShapeIDPair &inSubShapePair) override;

        bool AddCallback(JPH::Body* body, contact_callback_t callback);
        bool RemoveCallback(JPH::Body* body, contact_callback_t callback);

    protected:
        HashMap<const JPH::Body*, Vector<JoltMonoContactListenerData>> p_MonoCallbacks;

    };
}