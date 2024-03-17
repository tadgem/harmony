
using Harmony.Support;
using System;
using System.Runtime.CompilerServices;

namespace Harmony
{
    
    public class ProgramMethods
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static IntPtr GetProgram();

        
        public static IntPtr GetProgramComponentPtr<T>()
        {
            // Get type hash
            HashString typeName = new HashString(typeof(T).Name);
            // Request pointer to program component with matching hash
            // return intptr
            return IntPtr.Zero;
        }
    }
}
