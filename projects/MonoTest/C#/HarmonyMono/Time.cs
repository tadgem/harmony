
using System.Runtime.CompilerServices;

namespace Harmony
{
    public static class Time
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static float GetFrameTime();
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static float GetFrameTimeUnscaled();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static float GetTimeScale();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void SetTimeScale(float newTimeScale);
    }
}
