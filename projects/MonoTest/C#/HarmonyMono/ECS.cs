using System;
using System.Runtime.CompilerServices;
using Harmony.Math;
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

    public readonly struct NativeTransformComponent
    {
        public readonly IntPtr Handle;
    }

    public static class ECSMethods
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static NativeTransformComponent GetEntityTransform(this Scene scene, Entity entity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Vector3 GetTransformPosition(this NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Vector3 GetTransformEuler(this NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Vector3 GetTransformScale(this NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void SetTransformPosition(this NativeTransformComponent t, Vector3 pos);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void SetTransformEuler(this NativeTransformComponent t, Vector3 euler);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void SetTransformScale(this NativeTransformComponent t, Vector3 scale);
    }
}
