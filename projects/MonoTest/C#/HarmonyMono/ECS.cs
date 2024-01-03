using System;
using System.Numerics;
using System.Runtime.CompilerServices;
namespace Harmony
{
    /// <summary>
    /// ID must match entt entity index.
    /// </summary>
    public readonly struct Entity
    {
        public Entity(uint id)
        {
            ID = id;
        }

        public readonly uint ID;
        public static implicit operator uint (Entity entity) { return entity.ID; }

        public override string ToString()
        {
            return $"{ID}";
        }
    }

    public class TransformComponent : INativeComponent
    {
        private NativeTransformComponent _native;
        
        IntPtr INativeComponent.Handle { get => _native.Handle; set => _native.Handle = value; }

        public Vector3 Position
        {
            get => ECSMethods.GetTransformPosition(_native);
            set => ECSMethods.SetTransformPosition(_native, value);
        }

        public Vector3 Euler
        {
            get => ECSMethods.GetTransformEuler(_native);
            set => ECSMethods.SetTransformEuler(_native, value);
        }

        public Vector3 Scale
        {
            get => ECSMethods.GetTransformScale(_native);
            set => ECSMethods.SetTransformScale(_native, value);
        }

        public Vector3 Up
        {
            get => ECSMethods.GetTransformUp(_native);
        }

        public Vector3 Forward
        {
            get => ECSMethods.GetTransformForward(_native);
        }

        public Vector3 Right
        {
            get => ECSMethods.GetTransformRight(_native);
        }
        
        public IntPtr GetNativeHandle(Scene scene, Entity entity)
        {
            return scene.GetEntityTransform(entity).Handle;

        }
    }

    internal struct NativeTransformComponent
    {
        public IntPtr Handle;
    }

    internal static class ECSMethods
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static NativeTransformComponent GetEntityTransform(this Scene scene, Entity entity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector3 GetTransformPosition(this NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector3 GetTransformEuler(this NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector3 GetTransformScale(this NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector3 GetTransformForward(this NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector3 GetTransformRight(this NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Vector3 GetTransformUp(this NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetTransformPosition(this NativeTransformComponent t, Vector3 pos);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetTransformEuler(this NativeTransformComponent t, Vector3 euler);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static void SetTransformScale(this NativeTransformComponent t, Vector3 scale);
    }
}
