using Harmony;
using System;
using System.Numerics;
using System.Runtime.CompilerServices;

namespace HarmonyJoltSharp
{


    public readonly struct NativeJoltBodyComponent
    {
        public readonly IntPtr Handle;
    }

    public struct ContactManifoldData
    {
        Vector3 BaseOffset;
        Vector3 WorldSpaceNormal;
        float PenetrationDepth;
        Vector3 CenterPoint;
    };

    // NB: Not yet implemented
    public struct ContactManifoldExtendedData
    {
        Vector3 BaseOffset;
        Vector3 WorldSpaceNormal;
        float PenetrationDepth;
        Vector3[] ContactPointsA;
        Vector3[] ContactPointsB;
    };

    public struct ContactSettings
    {
        float CombinedFriction;
        float CombinedRestitution;
        float InvMassScale1;
        float InvIntertiaScale1;
        float InvMassScale2;
        float InvIntertiaScale2;
        bool IsSensor;
        Vector3 RelativeLinearSurfaceVelocity;
        Vector3 RelativeAngularSurfaceVelocity;
    };


    public delegate void ContactCallback(Body a, Body b, ContactManifoldData manifold, ContactSettings settings);

    public static class ECS
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static NativeJoltBodyComponent GetEntityJoltBodyComponent(this Scene scene, Entity entity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static IntPtr GetJoltBodyFromComponent(this NativeJoltBodyComponent joltBody);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static bool AddContactCallback(this Body b, ContactCallback callback);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static bool RemoveContactCallback(this Body b, ContactCallback callback);


        // Managed impls
        public static IntPtr GetJoltBodyFromEntity(this Scene scene, Entity entity)
        {
            NativeJoltBodyComponent component = scene.GetEntityJoltBodyComponent(entity);
            return GetJoltBodyFromComponent(component);
        }
    }
}
