
using System.Runtime.CompilerServices;

namespace Harmony
{
    public static class Log
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void Trace(string message);
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void Info(string message);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void Warn(string message);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void Error(string message);
    }
}
