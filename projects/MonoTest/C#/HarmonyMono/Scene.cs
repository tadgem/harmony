using System.Runtime.CompilerServices;
using System;

namespace Harmony
{
    public struct Scene
    {
        public readonly IntPtr Handle;
    }

    public class SceneMethods
    {
        // N.B: This will all change when introducing async scene loading + foreground / background scenes.
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Scene GetActiveScene();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void CloseActiveScene();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void LoadScene(string path);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void SaveScene(string path);
    }
}
