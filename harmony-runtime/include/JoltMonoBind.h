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

}
namespace harmony {
    class JoltMonoInternalMethodProvider : public MonoInternalMethodProvider
    {
    public:
        JoltMonoInternalMethodProvider();

        virtual void BindInternalMethods() override;
    };

     class JoltMonoContactListenerCallback final :
    public HarmonyContactListenerCallback,
    public MonoDelegateInvokeProvider
    {
    public:

        JoltMonoContactListenerCallback(JPH::PhysicsSystem* bodyLockInterface);
        void OnContactAdded(const JPH::Body &inBody1, const JPH::Body &inBody2, const JPH::ContactManifold &inManifold,
                            JPH::ContactSettings &ioSettings) override;

        void OnContactPersisted(const JPH::Body &inBody1, const JPH::Body &inBody2, const JPH::ContactManifold &inManifold,
                           JPH::ContactSettings &ioSettings) override;

        void OnContactRemoved(JPH::Body* inBody1, JPH::Body* inBody2) override;


        bool AddContactAddedCallback(JPH::Body* body, MonoObject* callback);
        bool RemoveContactAddedCallback(JPH::Body* body, MonoObject* callback);

         bool AddContactPersistedCallback(JPH::Body* body, MonoObject* callback);
         bool RemoveContactPersistedCallback(JPH::Body* body, MonoObject* callback);

         bool AddContactRemovedCallback(JPH::Body* body, MonoObject* callback);
         bool RemoveContactRemovedCallback(JPH::Body* body, MonoObject* callback);

        virtual void ProcessDelegates() override;
    protected:
         JPH::PhysicsSystem* p_PhysicsSystem;
         HashMap<JPH::BodyID, Vector<MonoObject*>> p_MonoContactAddedCallbacks;
         HashMap<JPH::BodyID, Vector<MonoObject*>> p_MonoContactPersistedCallbacks;
         HashMap<JPH::BodyID, Vector<MonoObject*>> p_MonoContactRemovedCallbacks;

         struct DelegateContactData
         {
             MonoObject*    m_Callback;
             JPH::Body*     m_Body1;
             JPH::Body*     m_Body2;
             jolt_contact_manifold_simple   m_ManifoldSimple;
             jolt_contact_settings          m_ContactSettings;
         };

         struct DelegateContactRemovedData
         {
             MonoObject*    m_Callback;
             JPH::Body*     m_Body1;
             JPH::Body*     m_Body2;
         };

         Vector<DelegateContactData>        p_ContactAddedDelegateBuffer;
         Vector<DelegateContactData>        p_ContactPersistedDelegateBuffer;
         Vector<DelegateContactRemovedData> p_ContactRemovedDelegateBuffer;
    };
}