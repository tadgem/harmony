using Harmony;
using System;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace HarmonyJoltSharp
{
    public class JoltBodyComponent : INativeComponent
    {
        private NativeJoltBodyComponent _native;
        public IntPtr Handle { get => _native.Handle; set => _native.Handle = value; }

        public Body Body
        {
            get
            {
                IntPtr handle = Physics.GetJoltBodyFromComponent(_native);
                return new Body(handle);
            }
        }

        public IntPtr GetNativeHandle(Scene scene, Entity entity)
        {
            return Physics.GetEntityJoltBodyComponent(scene, entity).Handle;
        }
    }

    internal struct NativeJoltBodyComponent
    {
        public IntPtr Handle;
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

    [StructLayout(LayoutKind.Sequential)]
    public struct RaycastResult
    {
        public bool DidHit;
        public Body Body;
        public Vector3 HitPoint;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct ShapecastResultSimple
    {
        public Body Body;
    }

    public delegate void ContactCallback(Body a, Body b, ContactManifoldData manifold, ContactSettings settings);

    public delegate void ContactRemovedCallback(Body a, Body b);

    public static class Physics
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static NativeJoltBodyComponent GetEntityJoltBodyComponent(this Scene scene, Entity entity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static IntPtr GetJoltBodyFromComponent(this NativeJoltBodyComponent joltBody);

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

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern RaycastResult Raycast(Vector3 origin, Vector3 direction);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern RaycastResult[] RaycastMulti(Vector3 origin, Vector3 direction);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern ShapecastResultSimple[] CollideSphere(Vector3 center, float radius);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public static extern ShapecastResultSimple[] Spherecast(Vector3 center, Vector3 direction, float radius);


        // Managed impls
        public static IntPtr GetJoltBodyFromEntity(this Scene scene, Entity entity)
        {
            NativeJoltBodyComponent component = scene.GetEntityJoltBodyComponent(entity);
            return GetJoltBodyFromComponent(component);
        }
    }
}
