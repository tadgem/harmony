using Harmony;
using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace HarmonyJoltSharp
{


    public readonly struct NativeJoltBodyComponent
    {
        public readonly IntPtr Handle;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct ContactManifoldData
    {
        Vector3 BaseOffset;
        Vector3 WorldSpaceNormal;
        float PenetrationDepth;
        Vector3 CenterPoint;
    };

    // NB: Not yet implemented
    [StructLayout(LayoutKind.Sequential)]
    public struct ContactManifoldExtendedData
    {
        Vector3 BaseOffset;
        Vector3 WorldSpaceNormal;
        float PenetrationDepth;
        Vector3[] ContactPointsA;
        Vector3[] ContactPointsB;
    };

    [StructLayout(LayoutKind.Sequential)]
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

    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    public delegate void ContactCallback(IntPtr a, IntPtr b,IntPtr manifold, IntPtr settings);

    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    public delegate void ContactRemovedCallback(Body a, Body b);

    public static class ECS
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static NativeJoltBodyComponent GetEntityJoltBodyComponent(this Scene scene, Entity entity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static IntPtr GetJoltBodyFromComponent(this NativeJoltBodyComponent joltBody);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static bool AddContactAddedCallback(this Body b, ContactCallback callback);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static bool RemoveContactAddedCallback(this Body b, ContactCallback callback);
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static bool AddContactPersistedCallback(this Body b, ContactCallback callback);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static bool RemoveContactPersistedCallback(this Body b, ContactCallback callback);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static bool AddContactRemovedCallback(this Body b, ContactRemovedCallback callback);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static bool RemoveContactRemovedCallback(this Body b, ContactRemovedCallback callback);


        // Managed impls
        public static IntPtr GetJoltBodyFromEntity(this Scene scene, Entity entity)
        {
            NativeJoltBodyComponent component = scene.GetEntityJoltBodyComponent(entity);
            return GetJoltBodyFromComponent(component);
        }
    }
}
