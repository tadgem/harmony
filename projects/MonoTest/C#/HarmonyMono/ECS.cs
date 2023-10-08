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
        public extern static NativeTransformComponent GetEntityTransform(Scene scene, Entity entity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Vector3 GetTransformPosition(NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Vector3 GetTransformEuler(NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Vector3 GetTransformScale(NativeTransformComponent t);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void SetTransformPosition(NativeTransformComponent t, Vector3 pos);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void SetTransformEuler(NativeTransformComponent t, Vector3 euler);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void SetTransformScale(NativeTransformComponent t, Vector3 scale);
    }
}
