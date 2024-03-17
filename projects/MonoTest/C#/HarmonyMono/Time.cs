
using System.Runtime.CompilerServices;

namespace Harmony
{
    public static class Time
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static double GetFrameTime();
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static double GetFrameTimeUnscaled();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static double GetTimeScale();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static double SetTimeScale(float newTimeScale);
    }
}
