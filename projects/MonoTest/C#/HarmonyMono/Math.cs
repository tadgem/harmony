
using System.Runtime.InteropServices;

namespace Harmony
{
    namespace Math
    {

        [StructLayout(LayoutKind.Sequential)]
        public struct Vector3
        {
            public float x;
            public float y;
            public float z;

            public override string ToString()
            {
                return $"({x},{y},{z})";
            }
        }
    }
}
