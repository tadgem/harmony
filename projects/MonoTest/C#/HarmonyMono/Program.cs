
using System;
using System.Runtime.CompilerServices;

namespace Harmony
{
    
    public class ProgramMethods
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static IntPtr GetProgram();
    }
}
