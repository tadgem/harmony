//
// Created by liam_ on 10/10/2023.
//
#include "JoltMonoBind.h"
#include "Core/Log.hpp"
#include "JoltAPI.h"
#include "JoltComponents.h"
#include "JoltPhysicsSystem.h"
#include "Core/Program.h"
#include "Core/Scene.h"

static harmony::JoltMonoContactListenerCallback* s_CallbackManager = nullptr;

extern "C"
{

    harmony::JoltBodyComponent* harmony_mono_get_jolt_body_component(harmony::Scene* scene, entt_entity entity)
    {
        if(!scene) return nullptr;

        entt::entity& e = (entt::entity&)entity;

        if(!scene->m_Registry.any_of<harmony::JoltBodyComponent>(e))
        {
            return nullptr;
        }

        return &scene->m_Registry.get<harmony::JoltBodyComponent>(e);
    }

    JPH::Body* harmony_mono_get_jolt_body_from_component(harmony::JoltBodyComponent* body)
    {
        if(!body) return nullptr;
        return body->Body;
    }

    void GetContactCallbackStaticInstance() {
        auto* base = harmony::Program::Get()->
            GetSystem<harmony::JoltPhysicsSystem>().lock()->
            GetContactListener()->
            GetContactCallback<harmony::JoltMonoContactListenerCallback>().get();

        s_CallbackManager = static_cast<harmony::JoltMonoContactListenerCallback*>(base);
    }

    bool harmony_mono_add_contact_added_callback(JPH::Body* body, MonoObject* callback)
    {
        if(s_CallbackManager == nullptr) {
            GetContactCallbackStaticInstance();
        }

        return s_CallbackManager->AddContactAddedCallback(body, callback);
    }

    bool harmony_mono_remove_contact_added_callback(JPH::Body* body, MonoObject* callback)
    {
        if(s_CallbackManager == nullptr) {
            GetContactCallbackStaticInstance();
        }

        return s_CallbackManager->RemoveContactAddedCallback(body, callback);
    }

    bool harmony_mono_add_contact_persisted_callback(JPH::Body* body, MonoObject* callback)
    {
        if(s_CallbackManager == nullptr) {
            GetContactCallbackStaticInstance();
        }

        return s_CallbackManager->AddContactPersistedCallback(body, callback);
    }

    bool harmony_mono_remove_contact_persisted_callback(JPH::Body* body, MonoObject* callback)
    {
        if(s_CallbackManager == nullptr) {
            GetContactCallbackStaticInstance();
        }

        return s_CallbackManager->RemoveContactPersistedCallback(body, callback);
    }

    bool harmony_mono_add_contact_removed_callback(JPH::Body* body, MonoObject* callback)
    {
        if(s_CallbackManager == nullptr) {
            GetContactCallbackStaticInstance();
        }

        return s_CallbackManager->AddContactRemovedCallback(body, callback);
    }

    bool harmony_mono_remove_contact_removed_callback(JPH::Body* body, MonoObject* callback)
    {
        if(s_CallbackManager == nullptr) {
            GetContactCallbackStaticInstance();
        }

        return s_CallbackManager->RemoveContactRemovedCallback(body, callback);
    }

}

void harmony::JoltMonoInternalMethodProvider::BindInternalMethods()
{
    mono_add_internal_call("HarmonyJoltSharp.ECS::GetEntityJoltBodyComponent", harmony_mono_get_jolt_body_component);
    mono_add_internal_call("HarmonyJoltSharp.ECS::GetJoltBodyFromComponent", harmony_mono_get_jolt_body_from_component);
    mono_add_internal_call("HarmonyJoltSharp.ECS::AddContactAddedCallback", harmony_mono_add_contact_added_callback);
    mono_add_internal_call("HarmonyJoltSharp.ECS::RemoveContactAddedCallback", harmony_mono_remove_contact_added_callback);
    mono_add_internal_call("HarmonyJoltSharp.ECS::AddContactPersistedCallback", harmony_mono_add_contact_persisted_callback);
    mono_add_internal_call("HarmonyJoltSharp.ECS::RemoveContactPersistedCallback", harmony_mono_remove_contact_persisted_callback);
    mono_add_internal_call("HarmonyJoltSharp.ECS::AddContactRemovedCallback", harmony_mono_add_contact_removed_callback);
    mono_add_internal_call("HarmonyJoltSharp.ECS::RemoveContactRemovedCallback", harmony_mono_remove_contact_removed_callback);

    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Init", JPH_Init);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Shutdown", JPH_Shutdown);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_SetAssertFailureHandler", JPH_SetAssertFailureHandler);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_TempAllocatorMalloc_Create", JPH_TempAllocatorMalloc_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_TempAllocator_Create", JPH_TempAllocator_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_TempAllocator_Destroy", JPH_TempAllocator_Destroy);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_JobSystemThreadPool_Create", JPH_JobSystemThreadPool_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_JobSystemSingleThreaded_Create", JPH_JobSystemSingleThreaded_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_JobSystem_Destroy", JPH_JobSystem_Destroy);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BroadPhaseLayerInterface_Create", JPH_BroadPhaseLayerInterface_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BroadPhaseLayerInterface_Destroy", JPH_BroadPhaseLayerInterface_Destroy);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_ObjectVsBroadPhaseLayerFilter_Create", JPH_ObjectVsBroadPhaseLayerFilter_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_ObjectVsBroadPhaseLayerFilter_Destroy", JPH_ObjectVsBroadPhaseLayerFilter_Destroy);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_ObjectLayerPairFilter_Create", JPH_ObjectLayerPairFilter_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_ObjectLayerPairFilter_Destroy", JPH_ObjectLayerPairFilter_Destroy);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BroadPhaseLayerFilter_Create", JPH_BroadPhaseLayerFilter_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BroadPhaseLayerFilter_Destroy", JPH_BroadPhaseLayerFilter_Destroy);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_ObjectLayerFilter_Create", JPH_ObjectLayerFilter_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_ObjectLayerFilter_Destroy", JPH_ObjectLayerFilter_Destroy);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyFilter_Create", JPH_BodyFilter_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyFilter_Destroy", JPH_BodyFilter_Destroy);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_ShapeSettings_Destroy", JPH_ShapeSettings_Destroy);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_ConvexShapeSettings_GetDensity", JPH_ConvexShapeSettings_GetDensity);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_ConvexShapeSettings_SetDensity", JPH_ConvexShapeSettings_SetDensity);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_ConvexShape_GetDensity", JPH_ConvexShape_GetDensity);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_ConvexShape_SetDensity", JPH_ConvexShape_SetDensity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BoxShapeSettings_Create", JPH_BoxShapeSettings_Create);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BoxShapeSettings_CreateShape", JPH_BoxShapeSettings_CreateShape);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BoxShape_Create", JPH_BoxShape_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BoxShape_GetHalfExtent", JPH_BoxShape_GetHalfExtent);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BoxShape_GetVolume", JPH_BoxShape_GetVolume);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BoxShape_GetConvexRadius", JPH_BoxShape_GetConvexRadius);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_SphereShapeSettings_Create", JPH_SphereShapeSettings_Create);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_SphereShapeSettings_CreateShape", JPH_SphereShapeSettings_CreateShape);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_SphereShapeSettings_GetRadius", JPH_SphereShapeSettings_GetRadius);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_SphereShapeSettings_SetRadius", JPH_SphereShapeSettings_SetRadius);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_TriangleShapeSettings_Create", JPH_TriangleShapeSettings_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_CapsuleShapeSettings_Create", JPH_CapsuleShapeSettings_Create);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_CapsuleShape_Create", JPH_CapsuleShape_Create);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_CapsuleShape_GetRadius", JPH_CapsuleShape_GetRadius);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_CapsuleShape_GetHalfHeightOfCylinder", JPH_CapsuleShape_GetHalfHeightOfCylinder);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_CylinderShapeSettings_Create", JPH_CylinderShapeSettings_Create);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_CylinderShape_Create", JPH_CylinderShape_Create);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_CylinderShape_GetRadius", JPH_CylinderShape_GetRadius);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_CylinderShape_GetHalfHeight", JPH_CylinderShape_GetHalfHeight);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_ConvexHullShapeSettings_CreateShape", JPH_ConvexHullShapeSettings_CreateShape);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_ConvexHullShapeSettings_Create", JPH_ConvexHullShapeSettings_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_MeshShapeSettings_Create", JPH_MeshShapeSettings_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_MeshShapeSettings_Create2", JPH_MeshShapeSettings_Create2);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_MeshShapeSettings_Sanitize", JPH_MeshShapeSettings_Sanitize);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_MeshShapeSettings_CreateShape", JPH_MeshShapeSettings_CreateShape);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_HeightFieldShapeSettings_Create", JPH_HeightFieldShapeSettings_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_MeshShapeSettings_DetermineMinAndMaxSample", JPH_MeshShapeSettings_DetermineMinAndMaxSample);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_MeshShapeSettings_CalculateBitsPerSampleForError", JPH_MeshShapeSettings_CalculateBitsPerSampleForError);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_TaperedCapsuleShapeSettings_Create", JPH_TaperedCapsuleShapeSettings_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_CompoundShapeSettings_AddShape", JPH_CompoundShapeSettings_AddShape);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_CompoundShapeSettings_AddShape2", JPH_CompoundShapeSettings_AddShape2);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_StaticCompoundShapeSettings_Create", JPH_StaticCompoundShapeSettings_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_MutableCompoundShapeSettings_Create", JPH_MutableCompoundShapeSettings_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Shape_Destroy", JPH_Shape_Destroy);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Shape_GetLocalBounds", JPH_Shape_GetLocalBounds);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Shape_GetMassProperties", JPH_Shape_GetMassProperties);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Shape_GetCenterOfMass", JPH_Shape_GetCenterOfMass);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Shape_GetInnerRadius", JPH_Shape_GetInnerRadius);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_SphereShape_Create", JPH_SphereShape_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_SphereShape_GetRadius", JPH_SphereShape_GetRadius);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyCreationSettings_Create", JPH_BodyCreationSettings_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyCreationSettings_Create2", JPH_BodyCreationSettings_Create2);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyCreationSettings_Create3", JPH_BodyCreationSettings_Create3);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyCreationSettings_Destroy", JPH_BodyCreationSettings_Destroy);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyCreationSettings_GetLinearVelocity", JPH_BodyCreationSettings_GetLinearVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyCreationSettings_SetLinearVelocity", JPH_BodyCreationSettings_SetLinearVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyCreationSettings_GetAngularVelocity", JPH_BodyCreationSettings_GetAngularVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyCreationSettings_SetAngularVelocity", JPH_BodyCreationSettings_SetAngularVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyCreationSettings_GetMotionType", JPH_BodyCreationSettings_GetMotionType);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyCreationSettings_SetMotionType", JPH_BodyCreationSettings_SetMotionType);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyCreationSettings_GetAllowedDOFs", JPH_BodyCreationSettings_GetAllowedDOFs);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyCreationSettings_SetAllowedDOFs", JPH_BodyCreationSettings_SetAllowedDOFs);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_SoftBodyCreationSettings_Create", JPH_SoftBodyCreationSettings_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_ConstraintSettings_Destroy", JPH_ConstraintSettings_Destroy);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Constraint_Destroy", JPH_Constraint_Destroy);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Constraint_GetConstraintSettings", JPH_Constraint_GetConstraintSettings);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Constraint_GetEnabled", JPH_Constraint_GetEnabled);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Constraint_SetEnabled", JPH_Constraint_SetEnabled);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_TwoBodyConstraint_GetBody1", JPH_TwoBodyConstraint_GetBody1);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_TwoBodyConstraint_GetBody2", JPH_TwoBodyConstraint_GetBody2);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_TwoBodyConstraint_GetConstraintToBody1Matrix", JPH_TwoBodyConstraint_GetConstraintToBody1Matrix);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_TwoBodyConstraint_GetConstraintToBody2Matrix", JPH_TwoBodyConstraint_GetConstraintToBody2Matrix);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PointConstraintSettings_Create", JPH_PointConstraintSettings_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PointConstraintSettings_GetSpace", JPH_PointConstraintSettings_GetSpace);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PointConstraintSettings_SetSpace", JPH_PointConstraintSettings_SetSpace);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PointConstraintSettings_GetPoint1", JPH_PointConstraintSettings_GetPoint1);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PointConstraintSettings_SetPoint1", JPH_PointConstraintSettings_SetPoint1);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PointConstraintSettings_GetPoint2", JPH_PointConstraintSettings_GetPoint2);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PointConstraintSettings_SetPoint2", JPH_PointConstraintSettings_SetPoint2);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PointConstraintSettings_CreateConstraint", JPH_PointConstraintSettings_CreateConstraint);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PointConstraint_SetPoint1", JPH_PointConstraint_SetPoint1);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PointConstraint_SetPoint2", JPH_PointConstraint_SetPoint2);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_DistanceConstraintSettings_Create", JPH_DistanceConstraintSettings_Create);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_DistanceConstraintSettings_GetPoint1", JPH_DistanceConstraintSettings_GetPoint1);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_DistanceConstraintSettings_SetPoint1", JPH_DistanceConstraintSettings_SetPoint1);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_DistanceConstraintSettings_GetPoint2", JPH_DistanceConstraintSettings_GetPoint2);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_DistanceConstraintSettings_SetPoint2", JPH_DistanceConstraintSettings_SetPoint2);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_DistanceConstraintSettings_CreateConstraint", JPH_DistanceConstraintSettings_CreateConstraint);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_HingeConstraintSettings_Create", JPH_HingeConstraintSettings_Create);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_HingeConstraintSettings_GetPoint1", JPH_HingeConstraintSettings_GetPoint1);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_HingeConstraintSettings_SetPoint1", JPH_HingeConstraintSettings_SetPoint1);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_HingeConstraintSettings_GetPoint2", JPH_HingeConstraintSettings_GetPoint2);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_HingeConstraintSettings_SetPoint2", JPH_HingeConstraintSettings_SetPoint2);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_HingeConstraintSettings_CreateConstraint", JPH_HingeConstraintSettings_CreateConstraint);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_SliderConstraintSettings_Create", JPH_SliderConstraintSettings_Create);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_SliderConstraintSettings_SetSliderAxis", JPH_SliderConstraintSettings_SetSliderAxis);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_SliderConstraintSettings_CreateConstraint", JPH_SliderConstraintSettings_CreateConstraint);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_Create", JPH_PhysicsSystem_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_Destroy", JPH_PhysicsSystem_Destroy);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_Init", JPH_PhysicsSystem_Init);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_OptimizeBroadPhase", JPH_PhysicsSystem_OptimizeBroadPhase);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_Update", JPH_PhysicsSystem_Update);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_SetContactListener", JPH_PhysicsSystem_SetContactListener);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_SetBodyActivationListener", JPH_PhysicsSystem_SetBodyActivationListener);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_GetNumBodies", JPH_PhysicsSystem_GetNumBodies);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_GetNumActiveBodies", JPH_PhysicsSystem_GetNumActiveBodies);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_GetMaxBodies", JPH_PhysicsSystem_GetMaxBodies);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_GetGravity", JPH_PhysicsSystem_GetGravity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_SetGravity", JPH_PhysicsSystem_SetGravity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_AddConstraint", JPH_PhysicsSystem_AddConstraint);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_RemoveConstraint", JPH_PhysicsSystem_RemoveConstraint);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_AddConstraints", JPH_PhysicsSystem_AddConstraints);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_RemoveConstraints", JPH_PhysicsSystem_RemoveConstraints);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_GetBodyInterface", JPH_PhysicsSystem_GetBodyInterface);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_PhysicsSystem_GetBodyInterfaceNoLock", JPH_PhysicsSystem_GetBodyInterfaceNoLock);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_CreateBody", JPH_BodyInterface_CreateBody);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_CreateSoftBody", JPH_BodyInterface_CreateSoftBody);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_CreateAndAddBody", JPH_BodyInterface_CreateAndAddBody);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_CreateBodyWithID", JPH_BodyInterface_CreateBodyWithID);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_CreateBodyWithoutID", JPH_BodyInterface_CreateBodyWithoutID);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_DestroyBody", JPH_BodyInterface_DestroyBody);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_DestroyBodyWithoutID", JPH_BodyInterface_DestroyBodyWithoutID);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_AssignBodyID", JPH_BodyInterface_AssignBodyID);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_AssignBodyID2", JPH_BodyInterface_AssignBodyID2);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_UnassignBodyID", JPH_BodyInterface_UnassignBodyID);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_AddBody", JPH_BodyInterface_AddBody);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_RemoveBody", JPH_BodyInterface_RemoveBody);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetLinearVelocity", JPH_BodyInterface_GetLinearVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_SetLinearVelocity", JPH_BodyInterface_SetLinearVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetCenterOfMassPosition", JPH_BodyInterface_GetCenterOfMassPosition);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_IsActive", JPH_BodyInterface_IsActive);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_IsAdded", JPH_BodyInterface_IsAdded);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetBodyType", JPH_BodyInterface_GetBodyType);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetMotionType", JPH_BodyInterface_GetMotionType);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_SetMotionType", JPH_BodyInterface_SetMotionType);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetMotionQuality", JPH_BodyInterface_GetMotionQuality);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_SetMotionQuality", JPH_BodyInterface_SetMotionQuality);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetRestitution", JPH_BodyInterface_GetRestitution);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_SetRestitution", JPH_BodyInterface_SetRestitution);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetFriction", JPH_BodyInterface_GetFriction);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_SetFriction", JPH_BodyInterface_SetFriction);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_SetPosition", JPH_BodyInterface_SetPosition);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetPosition", JPH_BodyInterface_GetPosition);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_SetRotation", JPH_BodyInterface_SetRotation);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetRotation", JPH_BodyInterface_GetRotation);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_SetPositionAndRotation", JPH_BodyInterface_SetPositionAndRotation);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_SetPositionAndRotationWhenChanged", JPH_BodyInterface_SetPositionAndRotationWhenChanged);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_SetPositionRotationAndVelocity", JPH_BodyInterface_SetPositionRotationAndVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_SetShape", JPH_BodyInterface_SetShape);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_NotifyShapeChanged", JPH_BodyInterface_NotifyShapeChanged);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_ActivateBody", JPH_BodyInterface_ActivateBody);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_DeactivateBody", JPH_BodyInterface_DeactivateBody);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_SetObjectLayer", JPH_BodyInterface_SetObjectLayer);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetObjectLayer", JPH_BodyInterface_GetObjectLayer);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetWorldTransform", JPH_BodyInterface_GetWorldTransform); // RMatrix4x4
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetCenterOfMassTransform", JPH_BodyInterface_GetCenterOfMassTransform); // RMatrix4x4
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_MoveKinematic", JPH_BodyInterface_MoveKinematic);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_SetLinearAndAngularVelocity", JPH_BodyInterface_SetLinearAndAngularVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetLinearAndAngularVelocity", JPH_BodyInterface_GetLinearAndAngularVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_AddLinearVelocity", JPH_BodyInterface_AddLinearVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_AddLinearAndAngularVelocity", JPH_BodyInterface_AddLinearAndAngularVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_SetAngularVelocity", JPH_BodyInterface_SetAngularVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetAngularVelocity", JPH_BodyInterface_GetAngularVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetPointVelocity", JPH_BodyInterface_GetPointVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_AddForce", JPH_BodyInterface_AddForce);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_AddForce2", JPH_BodyInterface_AddForce2);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_AddTorque", JPH_BodyInterface_AddTorque);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_AddForceAndTorque", JPH_BodyInterface_AddForceAndTorque);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_AddImpulse", JPH_BodyInterface_AddImpulse);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_AddImpulse2", JPH_BodyInterface_AddImpulse2);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_AddAngularImpulse", JPH_BodyInterface_AddAngularImpulse);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetInverseInertia", JPH_BodyInterface_GetInverseInertia);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_SetGravityFactor", JPH_BodyInterface_SetGravityFactor);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetGravityFactor", JPH_BodyInterface_GetGravityFactor);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_InvalidateContactCache", JPH_BodyInterface_InvalidateContactCache);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_SetUserData", JPH_BodyInterface_SetUserData);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyInterface_GetUserData", JPH_BodyInterface_GetUserData);
    mono_add_internal_call("JPC_PhysicsSystem_GetBodyLockInterface", JPC_PhysicsSystem_GetBodyLockInterface);
    mono_add_internal_call("JPC_PhysicsSystem_GetBodyLockInterfaceNoLock", JPC_PhysicsSystem_GetBodyLockInterfaceNoLock);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyLockInterface_LockRead", JPH_BodyLockInterface_LockRead);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyLockInterface_UnlockRead", JPH_BodyLockInterface_UnlockRead);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyLockInterface_LockWrite", JPH_BodyLockInterface_LockWrite);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyLockInterface_UnlockWrite", JPH_BodyLockInterface_UnlockWrite);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_MotionProperties_SetLinearDamping", JPH_MotionProperties_SetLinearDamping);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_MotionProperties_GetLinearDamping", JPH_MotionProperties_GetLinearDamping);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_MotionProperties_SetAngularDamping", JPH_MotionProperties_SetAngularDamping);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_MotionProperties_GetAngularDamping", JPH_MotionProperties_GetAngularDamping);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_MotionProperties_GetInverseMassUnchecked", JPH_MotionProperties_GetInverseMassUnchecked);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_MotionProperties_SetMassProperties", JPH_MotionProperties_SetMassProperties);
    mono_add_internal_call("JPC_PhysicsSystem_GetNarrowPhaseQuery", JPC_PhysicsSystem_GetNarrowPhaseQuery);
    mono_add_internal_call("JPC_PhysicsSystem_GetNarrowPhaseQueryNoLock", JPC_PhysicsSystem_GetNarrowPhaseQueryNoLock);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_NarrowPhaseQuery_CastRay", JPH_NarrowPhaseQuery_CastRay);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetID", JPH_Body_GetID);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetBodyType", JPH_Body_GetBodyType);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetWorldSpaceBounds", JPH_Body_GetWorldSpaceBounds);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_IsActive", JPH_Body_IsActive);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_IsStatic", JPH_Body_IsStatic);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_IsKinematic", JPH_Body_IsKinematic);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_IsDynamic", JPH_Body_IsDynamic);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_IsSensor", JPH_Body_IsSensor);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_SetIsSensor", JPH_Body_SetIsSensor);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetMotionProperties", JPH_Body_GetMotionProperties);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetMotionType", JPH_Body_GetMotionType);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_SetMotionType", JPH_Body_SetMotionType);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetAllowSleeping", JPH_Body_GetAllowSleeping);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_SetAllowSleeping", JPH_Body_SetAllowSleeping);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetFriction", JPH_Body_GetFriction);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_SetFriction", JPH_Body_SetFriction);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetRestitution", JPH_Body_GetRestitution);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_SetRestitution", JPH_Body_SetRestitution);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetPosition", JPH_Body_GetPosition);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetRotation", JPH_Body_GetRotation);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetCenterOfMassPosition", JPH_Body_GetCenterOfMassPosition);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetWorldTransform", JPH_Body_GetWorldTransform);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetCenterOfMassTransform", JPH_Body_GetCenterOfMassTransform);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetLinearVelocity", JPH_Body_GetLinearVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_SetLinearVelocity", JPH_Body_SetLinearVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetAngularVelocity", JPH_Body_GetAngularVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_SetAngularVelocity", JPH_Body_SetAngularVelocity);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_AddForce", JPH_Body_AddForce);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_AddForceAtPosition", JPH_Body_AddForceAtPosition);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_AddTorque", JPH_Body_AddTorque);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetAccumulatedForce", JPH_Body_GetAccumulatedForce);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetAccumulatedTorque", JPH_Body_GetAccumulatedTorque);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_AddImpulse", JPH_Body_AddImpulse);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_AddImpulseAtPosition", JPH_Body_AddImpulseAtPosition);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_AddAngularImpulse", JPH_Body_AddAngularImpulse);
//    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_SetUserData", JPH_Body_SetUserData);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_Body_GetUserData", JPH_Body_GetUserData);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_ContactListener_Create", JPH_ContactListener_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_ContactListener_Destroy", JPH_ContactListener_Destroy);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyActivationListener_Create", JPH_BodyActivationListener_Create);
    mono_add_internal_call("HarmonyJoltSharp.JoltApi::JPH_BodyActivationListener_Destroy", JPH_BodyActivationListener_Destroy);

}

harmony::JoltMonoInternalMethodProvider::JoltMonoInternalMethodProvider() {

}

glm_vec3 jolt_to_glm_rvec3(const JPH::RVec3& v)
{
    return glm_vec3 { v.GetX(), v.GetY(), v.GetZ()};
}

glm_vec3 jolt_to_glm_vec3(const JPH::Vec3& v)
{
    return glm_vec3 { v.GetX(), v.GetY(), v.GetZ()};
}

jolt_contact_manifold_simple get_simple_manifold(const JPH::ContactManifold& inManifold)
{
    jolt_contact_manifold_simple mf {};

    mf.base_offset = jolt_to_glm_rvec3(inManifold.mBaseOffset);
    mf.penetration_depth = inManifold.mPenetrationDepth;
    mf.world_space_normal = jolt_to_glm_vec3(inManifold.mWorldSpaceNormal);
    // TODO: Might be sus -_-
    mf.center_point = jolt_to_glm_vec3(inManifold.mBaseOffset);


    return mf;
}

jolt_contact_manifold_extended get_extended_manifold(const JPH::ContactManifold& inManifold)
{
    jolt_contact_manifold_extended mf {};

    mf.base_offset = jolt_to_glm_rvec3(inManifold.mBaseOffset);
    mf.penetration_depth = inManifold.mPenetrationDepth;
    mf.world_space_normal = jolt_to_glm_vec3(inManifold.mWorldSpaceNormal);

    for(int i = 0; i< inManifold.mRelativeContactPointsOn1.size(); i++)
    {
        mf.contact_points_b1[i] = jolt_to_glm_vec3(inManifold.mRelativeContactPointsOn1[i]);
    }

    for(int i = 0; i< inManifold.mRelativeContactPointsOn2.size(); i++)
    {
        mf.contact_points_b2[i] = jolt_to_glm_vec3(inManifold.mRelativeContactPointsOn2[i]);
    }
    return mf;
}

jolt_contact_settings get_contact_settings(const JPH::ContactSettings& settings)
{
    jolt_contact_settings s {};

    return s;
}

static harmony::Mutex s_ContactAddedMutex;

void harmony::JoltMonoContactListenerCallback::OnContactAdded(const JPH::Body &inBody1, const JPH::Body &inBody2,
                                                              const JPH::ContactManifold &inManifold,
                                                              JPH::ContactSettings &ioSettings) {
    JPH::Body* b1ptr = (JPH::Body*)&inBody1;
    JPH::Body* b2ptr = (JPH::Body*)&inBody2;
    jolt_contact_manifold_simple manifold = get_simple_manifold(inManifold);
    jolt_contact_settings contact_settings = get_contact_settings(ioSettings);
    auto id1 = inBody1.GetID();
    auto id2 = inBody2.GetID();
    if(p_MonoContactAddedCallbacks.find(id1) != p_MonoContactAddedCallbacks.end())
    {
        for(const auto cb : p_MonoContactAddedCallbacks[id1])
        {
            if(cb == nullptr) {
                continue;
            }

            MutexLock lock(s_ContactAddedMutex);
            DelegateContactData data
            {
                cb,
                inBody1.GetID(),
                inBody2.GetID(),
                manifold,
                contact_settings
            };

            p_ContactAddedDelegateBuffer.emplace_back(data);
        }
    }

    if(p_MonoContactAddedCallbacks.find(id2) != p_MonoContactAddedCallbacks.end())
    {
        for(const auto cb : p_MonoContactAddedCallbacks[id2])
        {
            if(cb == nullptr) {
                continue;
            }

            MutexLock lock(s_ContactAddedMutex);
            DelegateContactData data
            {
                cb,
                inBody1.GetID(),
                inBody2.GetID(),
                manifold,
                contact_settings
            };

            p_ContactAddedDelegateBuffer.emplace_back(data);
        }
    }

}

static harmony::Mutex s_ContactPersistedMutex;
void harmony::JoltMonoContactListenerCallback::OnContactPersisted(const JPH::Body &inBody1, const JPH::Body &inBody2,
                                                                  const JPH::ContactManifold &inManifold,
                                                                  JPH::ContactSettings &ioSettings) {
    JPH::Body* b1ptr = (JPH::Body*)&inBody1;
    JPH::Body* b2ptr = (JPH::Body*)&inBody2;
    jolt_contact_manifold_simple manifold = get_simple_manifold(inManifold);
    jolt_contact_settings contact_settings = get_contact_settings(ioSettings);
    auto id1 = inBody1.GetID();
    auto id2 = inBody2.GetID();
    if(p_MonoContactPersistedCallbacks.find(id1) != p_MonoContactPersistedCallbacks.end())
    {
        for(const auto cb : p_MonoContactPersistedCallbacks[id1])
        {
            if(cb == nullptr) {
                continue;
            }

            MutexLock lock(s_ContactPersistedMutex);
            DelegateContactData data
            {
                cb,
                inBody1.GetID(),
                inBody2.GetID(),
                manifold,
                contact_settings
            };

            p_ContactPersistedDelegateBuffer.emplace_back(data);
        }
    }

    if(p_MonoContactPersistedCallbacks.find(id2) != p_MonoContactPersistedCallbacks.end())
    {
        for(const auto cb : p_MonoContactPersistedCallbacks[id2])
        {
            if(cb == nullptr) {
                continue;
            }

            MutexLock lock(s_ContactPersistedMutex);
            DelegateContactData data
            {
                cb,
                inBody1.GetID(),
                inBody2.GetID(),
                manifold,
                contact_settings
            };

            p_ContactPersistedDelegateBuffer.emplace_back(data);
        }
    }


}

static harmony::Mutex s_ContactRemovedMutex;
void harmony::JoltMonoContactListenerCallback::OnContactRemoved(JPH::Body* inBody1, JPH::Body* inBody2)
{
    auto id1 = inBody1->GetID();
    if(p_MonoContactPersistedCallbacks.find(id1) != p_MonoContactPersistedCallbacks.end())
    {
        for(const auto cb : p_MonoContactPersistedCallbacks[id1])
        {
            if(cb == nullptr) {
                continue;
            }

            MutexLock lock(s_ContactRemovedMutex);
            DelegateContactRemovedData data
            {
                cb,
                inBody1->GetID(),
                inBody2->GetID(),
            };

            p_ContactRemovedDelegateBuffer.emplace_back(data);
        }
    }

    if(p_MonoContactPersistedCallbacks.find(inBody2->GetID()) != p_MonoContactPersistedCallbacks.end())
    {
        for(const auto cb : p_MonoContactPersistedCallbacks[id1])
        {
            if(cb == nullptr) {
                continue;
            }

            MutexLock lock(s_ContactRemovedMutex);
            DelegateContactRemovedData data
            {
                cb,
                inBody1->GetID(),
                inBody2->GetID(),
            };

            p_ContactRemovedDelegateBuffer.emplace_back(data);
        }
    }

}


bool harmony::JoltMonoContactListenerCallback::AddContactAddedCallback(JPH::Body* body, MonoObject* callback)
{
    auto id = body->GetID();
    if(p_MonoContactAddedCallbacks.find(id) != p_MonoContactAddedCallbacks.end()) {
        auto& callbacks  = p_MonoContactAddedCallbacks[id];
        auto it = std::find(callbacks.begin(), callbacks.end(), callback);
        if(it != callbacks.end())
        {
            log::warn("JoltMonoContactListenerCallback : AddContactAddedCallback : already added this callback");
            return false;
        }
        callbacks.emplace_back(callback);
        return true;
    }

    p_MonoContactAddedCallbacks.emplace(id, Vector<MonoObject*>());
    p_MonoContactAddedCallbacks[id].emplace_back(callback);
    return true;
}

bool harmony::JoltMonoContactListenerCallback::RemoveContactAddedCallback(JPH::Body* body, MonoObject* callback)
{
    auto id = body->GetID();
    if(p_MonoContactAddedCallbacks.find(id) != p_MonoContactAddedCallbacks.end())
    {
        auto& callbacks = p_MonoContactAddedCallbacks[id];
        auto it = std::find(callbacks.begin(), callbacks.end(), callback);

        if(it != callbacks.end())
        {
            callbacks.erase(it);
            return true;
        }
    }
    return false;

}


bool harmony::JoltMonoContactListenerCallback::AddContactPersistedCallback(JPH::Body* body, MonoObject* callback)
{
    auto id = body->GetID();
    if(p_MonoContactPersistedCallbacks.find(id) != p_MonoContactPersistedCallbacks.end()) {
        auto& callbacks  = p_MonoContactPersistedCallbacks[id];
        auto it = std::find(callbacks.begin(), callbacks.end(), callback);
        if(it != callbacks.end())
        {
            log::warn("JoltMonoContactListenerCallback : AddContactPersistedCallback : already added this callback");
            return false;
        }
        callbacks.emplace_back(callback);
        return true;
    }

    p_MonoContactPersistedCallbacks.emplace(id, Vector<MonoObject*>());
    p_MonoContactPersistedCallbacks[id].emplace_back(callback);
    return true;
}

bool harmony::JoltMonoContactListenerCallback::RemoveContactPersistedCallback(JPH::Body* body, MonoObject* callback)
{
    auto id = body->GetID();
    if(p_MonoContactPersistedCallbacks.find(id) != p_MonoContactPersistedCallbacks.end())
    {
        auto& callbacks = p_MonoContactPersistedCallbacks[id];
        auto it = std::find(callbacks.begin(), callbacks.end(), callback);

        if(it != callbacks.end())
        {
            callbacks.erase(it);
            return true;
        }
    }
    return false;

}

bool harmony::JoltMonoContactListenerCallback::AddContactRemovedCallback(JPH::Body* body, MonoObject* callback)
{
    auto id = body->GetID();
    if(p_MonoContactRemovedCallbacks.find(id) != p_MonoContactRemovedCallbacks.end()) {
        auto& callbacks  = p_MonoContactRemovedCallbacks[id];
        auto it = std::find(callbacks.begin(), callbacks.end(), callback);
        if(it != callbacks.end())
        {
            log::warn("JoltMonoContactListenerCallback : AddContactRemovedCallback : already added this callback");
            return false;
        }
        callbacks.emplace_back(callback);
        return true;
    }

    p_MonoContactRemovedCallbacks.emplace(id, Vector<MonoObject*>());
    p_MonoContactRemovedCallbacks[id].emplace_back(callback);
    return true;
}

bool harmony::JoltMonoContactListenerCallback::RemoveContactRemovedCallback(JPH::Body* body, MonoObject* callback)
{
    auto id = body->GetID();
    if(p_MonoContactRemovedCallbacks.find(id) != p_MonoContactRemovedCallbacks.end())
    {
        auto& callbacks = p_MonoContactRemovedCallbacks[id];
        auto it = std::find(callbacks.begin(), callbacks.end(), callback);

        if(it != callbacks.end())
        {
            callbacks.erase(it);
            return true;
        }
    }
    return false;

}

void harmony::JoltMonoContactListenerCallback::ProcessDelegates() {
    auto& bodyLockInterface = p_PhysicsSystem->GetBodyLockInterface();
    {
        MutexLock contact_added_lock(s_ContactAddedMutex);
        for(DelegateContactData data : p_ContactAddedDelegateBuffer) {
            JPH::Body* b1 = nullptr, *b2 = nullptr;

            while(!b1 || !b2)
            {
                b1 = bodyLockInterface.TryGetBody(data.m_Body1);
                b2 = bodyLockInterface.TryGetBody(data.m_Body2);
            }

            void* args[]
            {
                b1, b2, &data.m_ManifoldSimple, &data.m_ContactSettings
            };

            mono_runtime_delegate_invoke(data.m_Callback, args, NULL);
        }
        p_ContactAddedDelegateBuffer.clear();
    }

    {
        MutexLock contact_persisted_lock(s_ContactPersistedMutex);
        for(DelegateContactData data : p_ContactPersistedDelegateBuffer) {
            JPH::Body* b1 = nullptr, *b2 = nullptr;

            while(!b1 || !b2)
            {
                b1 = bodyLockInterface.TryGetBody(data.m_Body1);
                b2 = bodyLockInterface.TryGetBody(data.m_Body2);
            }

            void* args[]
            {
                b1, b2, &data.m_ManifoldSimple, &data.m_ContactSettings
            };
            mono_runtime_delegate_invoke(data.m_Callback, args, NULL);
        }
        p_ContactPersistedDelegateBuffer.clear();
    }

    {
        MutexLock contact_removed_lock(s_ContactRemovedMutex);
        for(DelegateContactRemovedData data : p_ContactRemovedDelegateBuffer) {
            JPH::Body* b1 = nullptr, *b2 = nullptr;

            while(!b1 || !b2)
            {
                b1 = bodyLockInterface.TryGetBody(data.m_Body1);
                b2 = bodyLockInterface.TryGetBody(data.m_Body2);
            }

            void* args[]
            {
                b1, b2
            };
            mono_runtime_delegate_invoke(data.m_Callback, args, NULL);
        }
        p_ContactRemovedDelegateBuffer.clear();
    }

}

harmony::JoltMonoContactListenerCallback::JoltMonoContactListenerCallback(JPH::PhysicsSystem* physicsSystem) :
HarmonyContactListenerCallback(GetTypeHash<JoltMonoContactListenerCallback>()),
p_PhysicsSystem(physicsSystem)
{
}
