using Harmony;
using System;
using System.Runtime.CompilerServices;

namespace HarmonyJoltSharp
{
    public readonly struct NativeJoltBodyComponent
    {
        public readonly IntPtr Handle;
    }

    public static class ECS
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static NativeJoltBodyComponent GetEntityJoltBodyComponent(this Scene scene, Entity entity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static IntPtr GetJoltBodyFromComponent(this NativeJoltBodyComponent joltBody);
    }
}
