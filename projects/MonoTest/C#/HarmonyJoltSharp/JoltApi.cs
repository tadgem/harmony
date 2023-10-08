// Copyright © Amer Koleci and Contributors.
// Licensed under the MIT License (MIT). See LICENSE in the repository root for more information.

using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace HarmonyJoltSharp
{

    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    public delegate Bool32 AssertFailedDelegate(string inExpression, string inMessage, string inFile, uint inLine);

    internal static unsafe partial class JoltApi
    {
        private const string LibName = "joltc";
        private const string LibDoubleName = "joltc_double";

        public static bool DoublePrecision { get; set; }


        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern Bool32 JPH_Init();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Shutdown();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_SetAssertFailureHandler(AssertFailedDelegate handler);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_TempAllocatorMalloc_Create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_TempAllocator_Create(uint size);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_TempAllocator_Destroy(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_JobSystemThreadPool_Create(uint maxJobs, uint maxBarriers, int inNumThreads);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_JobSystemSingleThreaded_Create(uint maxJobs);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_JobSystem_Destroy(IntPtr handle);

        //  BroadPhaseLayerInterface
        //public struct JPH_BroadPhaseLayerInterface_Procs
        //{
        //    public delegate* unmanaged<IntPtr, uint> GetNumBroadPhaseLayers;
        //    public delegate* unmanaged<IntPtr, ObjectLayer, BroadPhaseLayer> GetBroadPhaseLayer;
        //    public delegate* unmanaged<IntPtr, BroadPhaseLayer, IntPtr> GetBroadPhaseLayerName;
        //}
        //[MethodImpl(MethodImplOptions.InternalCall)]
        //public static extern void JPH_BroadPhaseLayerInterface_SetProcs(JPH_BroadPhaseLayerInterface_Procs procs);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_BroadPhaseLayerInterface_Create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BroadPhaseLayerInterface_Destroy(IntPtr handle);

        //  ObjectVsBroadPhaseLayerFilter
        //public struct JPH_ObjectVsBroadPhaseLayerFilter_Procs
        //{
        //    public delegate* unmanaged<IntPtr, ObjectLayer, BroadPhaseLayer, Bool32> ShouldCollide;
        //}

        //[MethodImpl(MethodImplOptions.InternalCall)]
        //public static extern void JPH_ObjectVsBroadPhaseLayerFilter_SetProcs(JPH_ObjectVsBroadPhaseLayerFilter_Procs procs);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_ObjectVsBroadPhaseLayerFilter_Create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_ObjectVsBroadPhaseLayerFilter_Destroy(IntPtr handle);

        //  ObjectLayerPairFilter
        //public struct JPH_ObjectLayerPairFilter_Procs
        //{
        //    public delegate* unmanaged<IntPtr, ObjectLayer, ObjectLayer, Bool32> ShouldCollide;
        //}

        //[MethodImpl(MethodImplOptions.InternalCall)]
        //public static extern void JPH_ObjectLayerPairFilter_SetProcs(JPH_ObjectLayerPairFilter_Procs procs);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_ObjectLayerPairFilter_Create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_ObjectLayerPairFilter_Destroy(IntPtr handle);

        //  BroadPhaseLayerFilter
        //public struct JPH_BroadPhaseLayerFilter_Procs
        //{
        //    public delegate* unmanaged<int, BroadPhaseLayer, Bool32> ShouldCollide;
        //}

        //[MethodImpl(MethodImplOptions.InternalCall)]
        //public static extern void JPH_BroadPhaseLayerFilter_SetProcs(JPH_BroadPhaseLayerFilter_Procs procs);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_BroadPhaseLayerFilter_Create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BroadPhaseLayerFilter_Destroy(IntPtr handle);

        //  ObjectLayerFilter
        //public struct JPH_ObjectLayerFilter_Procs
        //{
        //    public delegate* unmanaged<IntPtr, ObjectLayer, Bool32> ShouldCollide;
        //}

        //[MethodImpl(MethodImplOptions.InternalCall)]
        //public static extern void JPH_ObjectLayerFilter_SetProcs(JPH_ObjectLayerFilter_Procs procs);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_ObjectLayerFilter_Create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_ObjectLayerFilter_Destroy(IntPtr handle);

        //  BodyFilter
        //public struct JPH_BodyFilter_Procs
        //{
        //    public delegate* unmanaged<IntPtr, BodyID, Bool32> ShouldCollide;
        //    public delegate* unmanaged<IntPtr, IntPtr, Bool32> ShouldCollideLocked;
        //}

        //[MethodImpl(MethodImplOptions.InternalCall)]
        //public static extern void JPH_BodyFilter_SetProcs(JPH_BodyFilter_Procs procs);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_BodyFilter_Create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyFilter_Destroy(IntPtr handle);

        /* ShapeSettings */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_ShapeSettings_Destroy(IntPtr shape);

        /* ConvexShape */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_ConvexShapeSettings_GetDensity(IntPtr shape);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_ConvexShapeSettings_SetDensity(IntPtr shape, float value);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_ConvexShape_GetDensity(IntPtr shape);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_ConvexShape_SetDensity(IntPtr shape, float value);

        /* BoxShapeSettings */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_BoxShapeSettings_Create(in Vector3 halfExtent, float convexRadius);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_BoxShapeSettings_CreateShape(IntPtr settings);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_BoxShape_Create(in Vector3 halfExtent, float convexRadius);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BoxShape_GetHalfExtent(IntPtr handle, out Vector3 halfExtent);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_BoxShape_GetVolume(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_BoxShape_GetConvexRadius(IntPtr handle);

        /* SphereShapeSettings */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_SphereShapeSettings_Create(float radius);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_SphereShapeSettings_CreateShape(IntPtr settings);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_SphereShapeSettings_GetRadius(IntPtr shape);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_SphereShapeSettings_SetRadius(IntPtr shape, float radius);

        /* TriangleShapeSettings */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_TriangleShapeSettings_Create(in Vector3 v1, in Vector3 v2, in Vector3 v3, float convexRadius);

        /* CapsuleShape */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_CapsuleShapeSettings_Create(float halfHeightOfCylinder, float radius);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_CapsuleShape_Create(float halfHeightOfCylinder, float radius);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_CapsuleShape_GetRadius(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_CapsuleShape_GetHalfHeightOfCylinder(IntPtr handle);

        /* CylinderShape */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_CylinderShapeSettings_Create(float halfHeight, float radius, float convexRadius);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_CylinderShape_Create(float halfHeight, float radius);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_CylinderShape_GetRadius(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_CylinderShape_GetHalfHeight(IntPtr handle);

        /* ConvexHullShape */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_ConvexHullShapeSettings_CreateShape(IntPtr settings);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_ConvexHullShapeSettings_Create(Vector3* points, int pointsCount, float maxConvexRadius);

        /* MeshShape  */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_MeshShapeSettings_Create(Triangle* triangle, int triangleCount);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_MeshShapeSettings_Create2(Vector3* vertices, int verticesCount, IndexedTriangle* triangles, int triangleCount);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_MeshShapeSettings_Sanitize(IntPtr shape);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_MeshShapeSettings_CreateShape(IntPtr settings);

        /* HeightFieldShape  */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_HeightFieldShapeSettings_Create(float* samples, in Vector3 offset, in Vector3 scale, int sampleCount);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_MeshShapeSettings_DetermineMinAndMaxSample(IntPtr settings, out float outMinValue, out float outMaxValue, out float outQuantizationScale);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern uint JPH_MeshShapeSettings_CalculateBitsPerSampleForError(IntPtr settings, float maxError);

        /* TaperedCapsuleShapeSettings */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_TaperedCapsuleShapeSettings_Create(float halfHeightOfTaperedCylinder, float topRadius, float bottomRadius);

        /* CompoundShape */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_CompoundShapeSettings_AddShape(IntPtr handle, in Vector3 position, in Quaternion rotation, IntPtr shapeSettings, uint userData);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_CompoundShapeSettings_AddShape2(IntPtr handle, in Vector3 position, in Quaternion rotation, IntPtr shape, uint userData);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_StaticCompoundShapeSettings_Create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_MutableCompoundShapeSettings_Create();

        /* Shape */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Shape_Destroy(IntPtr shape);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Shape_GetLocalBounds(IntPtr shape, BoundingBox* box);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Shape_GetMassProperties(IntPtr shape, out MassProperties properties);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Shape_GetCenterOfMass(IntPtr handle, out Vector3 result);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_Shape_GetInnerRadius(IntPtr handle);

        /* SphereShape */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_SphereShape_Create(float radius);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_SphereShape_GetRadius(IntPtr shape);

        /* BodyCreationSettings */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_BodyCreationSettings_Create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_BodyCreationSettings_Create2(IntPtr shapeSettings, in Double3 position, in Quaternion rotation, MotionType motionType, ushort objectLayer);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_BodyCreationSettings_Create3(IntPtr shape, in Double3 position, in Quaternion rotation, MotionType motionType, ushort objectLayer);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyCreationSettings_Destroy(IntPtr settings);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyCreationSettings_GetLinearVelocity(IntPtr settings, out Vector3 velocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyCreationSettings_SetLinearVelocity(IntPtr settings, in Vector3 velocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyCreationSettings_GetAngularVelocity(IntPtr settings, out Vector3 velocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyCreationSettings_SetAngularVelocity(IntPtr settings, in Vector3 velocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern MotionType JPH_BodyCreationSettings_GetMotionType(IntPtr settings);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyCreationSettings_SetMotionType(IntPtr settings, MotionType value);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern AllowedDOFs JPH_BodyCreationSettings_GetAllowedDOFs(IntPtr settings);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyCreationSettings_SetAllowedDOFs(IntPtr settings, AllowedDOFs value);

        /* SoftBodyCreationSettings */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_SoftBodyCreationSettings_Create();

        //[MethodImpl(MethodImplOptions.InternalCall)]
        //public static extern void JPH_SoftBodyCreationSettings_Destroy(IntPtr settings);

        #region JPH_Constraint
        /* JPH_Constraint */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_ConstraintSettings_Destroy(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Constraint_Destroy(IntPtr constraint);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_Constraint_GetConstraintSettings(IntPtr constraint);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern Bool32 JPH_Constraint_GetEnabled(IntPtr constraint);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Constraint_SetEnabled(IntPtr constraint, Bool32 value);
        #endregion

        #region JPH_TwoBodyConstraint
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_TwoBodyConstraint_GetBody1(IntPtr constraint);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_TwoBodyConstraint_GetBody2(IntPtr constraint);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_TwoBodyConstraint_GetConstraintToBody1Matrix(IntPtr constraint, out Matrix4x4 result);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_TwoBodyConstraint_GetConstraintToBody2Matrix(IntPtr constraint, out Matrix4x4 result);
        #endregion

        #region JPH_PointConstraint
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_PointConstraintSettings_Create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern ConstraintSpace JPH_PointConstraintSettings_GetSpace(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PointConstraintSettings_SetSpace(IntPtr handle, ConstraintSpace value);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PointConstraintSettings_GetPoint1(IntPtr handle, out Double3 result);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PointConstraintSettings_SetPoint1(IntPtr handle, in Double3 value);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PointConstraintSettings_GetPoint2(IntPtr handle, out Double3 result);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PointConstraintSettings_SetPoint2(IntPtr handle, in Double3 value);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_PointConstraintSettings_CreateConstraint(IntPtr handle, IntPtr body1, IntPtr body2);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PointConstraint_SetPoint1(IntPtr handle, ConstraintSpace space, in Double3 value);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PointConstraint_SetPoint2(IntPtr handle, ConstraintSpace space, in Double3 value);
        #endregion

        #region JPH_DistanceConstraint
        /* JPH_DistanceConstraint */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_DistanceConstraintSettings_Create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_DistanceConstraintSettings_GetPoint1(IntPtr handle, out Vector3 result);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_DistanceConstraintSettings_SetPoint1(IntPtr handle, in Vector3 value);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_DistanceConstraintSettings_GetPoint2(IntPtr handle, out Vector3 result);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_DistanceConstraintSettings_SetPoint2(IntPtr handle, in Vector3 value);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_DistanceConstraintSettings_CreateConstraint(IntPtr handle, IntPtr body1, IntPtr body2);
        #endregion

        #region JPH_HingeConstraint
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_HingeConstraintSettings_Create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_HingeConstraintSettings_GetPoint1(IntPtr handle, out Double3 result);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_HingeConstraintSettings_SetPoint1(IntPtr handle, in Double3 value);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_HingeConstraintSettings_GetPoint2(IntPtr handle, out Double3 result);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_HingeConstraintSettings_SetPoint2(IntPtr handle, in Double3 value);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_HingeConstraintSettings_CreateConstraint(IntPtr handle, IntPtr body1, IntPtr body2);
        #endregion

        #region JPH_SliderConstraint
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_SliderConstraintSettings_Create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_SliderConstraintSettings_SetSliderAxis(IntPtr handle, in Vector3 value);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_SliderConstraintSettings_CreateConstraint(IntPtr handle, IntPtr body1, IntPtr body2);
        #endregion

        /* PhysicsSystem */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_PhysicsSystem_Create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PhysicsSystem_Destroy(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PhysicsSystem_Init(IntPtr handle,
            uint inMaxBodies, uint numBodyMutexes, uint maxBodyPairs, uint maxContactConstraints,
            IntPtr layer,
            IntPtr inObjectVsBroadPhaseLayerFilter,
            IntPtr inObjectLayerPairFilter);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PhysicsSystem_OptimizeBroadPhase(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern PhysicsUpdateError JPH_PhysicsSystem_Update(IntPtr handle, float deltaTime, int collisionSteps, IntPtr tempAlocator, IntPtr jobSystem);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PhysicsSystem_SetContactListener(IntPtr system, IntPtr listener);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PhysicsSystem_SetBodyActivationListener(IntPtr system, IntPtr listener);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern uint JPH_PhysicsSystem_GetNumBodies(IntPtr system);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern uint JPH_PhysicsSystem_GetNumActiveBodies(IntPtr system, BodyType type);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern uint JPH_PhysicsSystem_GetMaxBodies(IntPtr system);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PhysicsSystem_GetGravity(IntPtr handle, out Vector3 velocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PhysicsSystem_SetGravity(IntPtr handle, in Vector3 velocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PhysicsSystem_AddConstraint(IntPtr handle, IntPtr constraint);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PhysicsSystem_RemoveConstraint(IntPtr handle, IntPtr constraint);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PhysicsSystem_AddConstraints(IntPtr handle, IntPtr* constraints, uint count);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_PhysicsSystem_RemoveConstraints(IntPtr handle, IntPtr* constraints, uint count);


        /* BodyInterface */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_PhysicsSystem_GetBodyInterface(IntPtr system);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_PhysicsSystem_GetBodyInterfaceNoLock(IntPtr system);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_BodyInterface_CreateBody(IntPtr handle, IntPtr settings);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_BodyInterface_CreateSoftBody(IntPtr handle, IntPtr settings);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern uint JPH_BodyInterface_CreateAndAddBody(IntPtr handle, IntPtr bodyID, Activation activation);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_BodyInterface_CreateBodyWithID(IntPtr handle, uint bodyID, IntPtr settings);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_BodyInterface_CreateBodyWithoutID(IntPtr handle, IntPtr settings);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_DestroyBody(IntPtr handle, uint bodyID);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_DestroyBodyWithoutID(IntPtr handle, IntPtr body);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern Bool32 JPH_BodyInterface_AssignBodyID(IntPtr handle, IntPtr body);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern Bool32 JPH_BodyInterface_AssignBodyID2(IntPtr handle, IntPtr body, uint bodyID);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_BodyInterface_UnassignBodyID(IntPtr handle, uint bodyID);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_AddBody(IntPtr handle, uint bodyID, Activation activationMode);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_RemoveBody(IntPtr handle, uint bodyID);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_GetLinearVelocity(IntPtr handle, uint bodyID, out Vector3 velocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_SetLinearVelocity(IntPtr handle, uint bodyID, in Vector3 velocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_GetCenterOfMassPosition(IntPtr handle, uint bodyID, out Double3 position);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern Bool32 JPH_BodyInterface_IsActive(IntPtr handle, uint bodyID);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern Bool32 JPH_BodyInterface_IsAdded(IntPtr handle, uint bodyID);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern BodyType JPH_BodyInterface_GetBodyType(IntPtr handle, uint bodyID);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern MotionType JPH_BodyInterface_GetMotionType(IntPtr handle, uint bodyID);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_SetMotionType(IntPtr handle, uint bodyID, MotionType motionType, Activation activationMode);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern MotionQuality JPH_BodyInterface_GetMotionQuality(IntPtr handle, uint bodyID);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_SetMotionQuality(IntPtr handle, uint bodyID, MotionQuality quality);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_BodyInterface_GetRestitution(IntPtr handle, uint bodyID);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_SetRestitution(IntPtr handle, uint bodyID, float value);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_BodyInterface_GetFriction(IntPtr handle, uint bodyID);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_SetFriction(IntPtr handle, uint bodyID, float value);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_SetPosition(IntPtr handle, uint bodyId, in Double3 position, Activation activationMode);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_GetPosition(IntPtr handle, uint bodyId, out Double3 position);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_SetRotation(IntPtr handle, uint bodyId, in Quaternion rotation, Activation activationMode);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_GetRotation(IntPtr handle, uint bodyId, out Quaternion rotation);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_SetPositionAndRotation(IntPtr handle, uint bodyID, in Double3 position, in Quaternion rotation, Activation activationMode);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_SetPositionAndRotationWhenChanged(IntPtr handle, uint bodyID, in Double3 position, in Quaternion rotation, Activation activationMode);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_SetPositionRotationAndVelocity(IntPtr handle, uint bodyID, in Double3 position, in Quaternion rotation, in Vector3 linearVelocity, in Vector3 angularVelocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_SetShape(IntPtr handle, uint bodyId, IntPtr shape, Bool32 updateMassProperties, Activation activationMode);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_NotifyShapeChanged(IntPtr handle, uint bodyId, in Vector3 previousCenterOfMass, Bool32 updateMassProperties, Activation activationMode);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_ActivateBody(IntPtr handle, uint bodyId);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_DeactivateBody(IntPtr handle, uint bodyId);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_SetObjectLayer(IntPtr handle, uint bodyId, ushort layer);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern ushort JPH_BodyInterface_GetObjectLayer(IntPtr handle, uint bodyId);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_GetWorldTransform(IntPtr handle, uint bodyId, out Matrix4x4 result); // RMatrix4x4

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_GetCenterOfMassTransform(IntPtr handle, uint bodyId, out Matrix4x4 result); // RMatrix4x4

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_MoveKinematic(IntPtr handle, uint bodyId, in Double3 targetPosition, in Quaternion targetRotation, float deltaTime);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_SetLinearAndAngularVelocity(IntPtr handle, uint bodyId, in Vector3 linearVelocity, in Vector3 angularVelocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_GetLinearAndAngularVelocity(IntPtr handle, uint bodyId, out Vector3 linearVelocity, out Vector3 angularVelocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_AddLinearVelocity(IntPtr handle, uint bodyId, in Vector3 linearVelocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_AddLinearAndAngularVelocity(IntPtr handle, uint bodyId, in Vector3 linearVelocity, in Vector3 angularVelocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_SetAngularVelocity(IntPtr handle, uint bodyId, in Vector3 angularVelocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_GetAngularVelocity(IntPtr handle, uint bodyId, out Vector3 angularVelocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_GetPointVelocity(IntPtr handle, uint bodyId, in Double3 point, out Vector3 velocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_AddForce(IntPtr handle, uint bodyId, in Vector3 force);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_AddForce2(IntPtr handle, uint bodyId, in Vector3 force, in Double3 point);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_AddTorque(IntPtr handle, uint bodyId, in Vector3 torque);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_AddForceAndTorque(IntPtr handle, uint bodyId, in Vector3 force, in Vector3 torque);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_AddImpulse(IntPtr handle, uint bodyId, in Vector3 impulse);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_AddImpulse2(IntPtr handle, uint bodyId, in Vector3 impulse, in Double3 point);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_AddAngularImpulse(IntPtr handle, uint bodyId, in Vector3 angularImpulse);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_GetInverseInertia(IntPtr handle, uint bodyId, out Matrix4x4 result);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_SetGravityFactor(IntPtr handle, uint bodyId, float gravityFactor);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_BodyInterface_GetGravityFactor(IntPtr handle, uint bodyId);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_InvalidateContactCache(IntPtr handle, uint bodyId);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyInterface_SetUserData(IntPtr handle, uint bodyId, ulong userData);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern ulong JPH_BodyInterface_GetUserData(IntPtr handle, uint bodyId);

        /* BodyLockInterface */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPC_PhysicsSystem_GetBodyLockInterface(IntPtr system);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPC_PhysicsSystem_GetBodyLockInterfaceNoLock(IntPtr system);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyLockInterface_LockRead(IntPtr lockInterface, uint bodyID, out BodyLockRead @lock);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyLockInterface_UnlockRead(IntPtr lockInterface, in BodyLockRead @lock);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyLockInterface_LockWrite(IntPtr lockInterface, uint bodyID, out BodyLockWrite @lock);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyLockInterface_UnlockWrite(IntPtr lockInterface, in BodyLockWrite @lock);

        /* JPH_MotionProperties */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_MotionProperties_SetLinearDamping(IntPtr properties, float damping);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_MotionProperties_GetLinearDamping(IntPtr properties);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_MotionProperties_SetAngularDamping(IntPtr properties, float damping);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_MotionProperties_GetAngularDamping(IntPtr properties);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_MotionProperties_GetInverseMassUnchecked(IntPtr properties);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_MotionProperties_SetMassProperties(IntPtr properties, AllowedDOFs allowedDOFs, in MassProperties massProperties);

        /* BodyLockInterface */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPC_PhysicsSystem_GetNarrowPhaseQuery(IntPtr system);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPC_PhysicsSystem_GetNarrowPhaseQueryNoLock(IntPtr system);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern Bool32 JPH_NarrowPhaseQuery_CastRay(IntPtr system,
            in Double3 origin, in Vector3 direction,
            ref RayCastResult hit,
            IntPtr broadPhaseLayerFilter,
            IntPtr objectLayerFilter,
            IntPtr bodyFilter);

        /* Body */
        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern uint JPH_Body_GetID(IntPtr body);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern BodyType JPH_Body_GetBodyType(IntPtr body);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_GetWorldSpaceBounds(IntPtr body, BoundingBox* box);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern Bool32 JPH_Body_IsActive(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern Bool32 JPH_Body_IsStatic(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern Bool32 JPH_Body_IsKinematic(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern Bool32 JPH_Body_IsDynamic(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern Bool32 JPH_Body_IsSensor(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_SetIsSensor(IntPtr handle, Bool32 value);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_Body_GetMotionProperties(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern MotionType JPH_Body_GetMotionType(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_SetMotionType(IntPtr handle, MotionType motionType);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern Bool32 JPH_Body_GetAllowSleeping(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_SetAllowSleeping(IntPtr handle, Bool32 motionType);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_Body_GetFriction(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_SetFriction(IntPtr handle, float value);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern float JPH_Body_GetRestitution(IntPtr handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_SetRestitution(IntPtr handle, float value);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_GetPosition(IntPtr handle, out Double3 result);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_GetRotation(IntPtr handle, out Quaternion result);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_GetCenterOfMassPosition(IntPtr handle, out Double3 result);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_GetWorldTransform(IntPtr handle, out Matrix4x4 result);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_GetCenterOfMassTransform(IntPtr handle, out Matrix4x4 result);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_GetLinearVelocity(IntPtr handle, out Vector3 result);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_SetLinearVelocity(IntPtr handle, in Vector3 velocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_GetAngularVelocity(IntPtr handle, out Vector3 velocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_SetAngularVelocity(IntPtr handle, in Vector3 velocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_AddForce(IntPtr handle, in Vector3 velocity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_AddForceAtPosition(IntPtr handle, in Vector3 velocity, in Double3 position);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_AddTorque(IntPtr handle, in Vector3 value);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_GetAccumulatedForce(IntPtr handle, out Vector3 force);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_GetAccumulatedTorque(IntPtr handle, out Vector3 force);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_AddImpulse(IntPtr handle, in Vector3 impulse);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_AddImpulseAtPosition(IntPtr handle, in Vector3 impulse, in Double3 position);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_AddAngularImpulse(IntPtr handle, in Vector3 angularImpulse);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_Body_SetUserData(IntPtr handle, ulong userData);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern ulong JPH_Body_GetUserData(IntPtr handle);

        // ContactListener
        //public struct JPH_ContactListener_Procs
        //{
        //    public delegate* unmanaged<IntPtr, IntPtr, IntPtr, Double3*, IntPtr, uint> OnContactValidate;
        //    public delegate* unmanaged<IntPtr, IntPtr, IntPtr, void> OnContactAdded;
        //    public delegate* unmanaged<IntPtr, IntPtr, IntPtr, void> OnContactPersisted;
        //    public delegate* unmanaged<IntPtr, SubShapeIDPair*, void> OnContactRemoved;
        //}
        //[MethodImpl(MethodImplOptions.InternalCall)]
        //public static extern void JPH_ContactListener_SetProcs(JPH_ContactListener_Procs procs);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_ContactListener_Create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_ContactListener_Destroy(IntPtr handle);

        // BodyActivationListener
        //public struct JPH_BodyActivationListener_Procs
        //{
        //    public delegate* unmanaged<IntPtr, uint, ulong, void> OnBodyActivated;
        //    public delegate* unmanaged<IntPtr, uint, ulong, void> OnBodyDeactivated;
        //}

        //[MethodImpl(MethodImplOptions.InternalCall)]
        //public static extern void JPH_BodyActivationListener_SetProcs(JPH_BodyActivationListener_Procs procs);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern IntPtr JPH_BodyActivationListener_Create();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern void JPH_BodyActivationListener_Destroy(IntPtr handle);
    }
}