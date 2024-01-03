using System.Runtime.CompilerServices;
using System;

namespace Harmony
{
    public struct Scene
    {
        public readonly IntPtr Handle;
    }

    public static class SceneMethods
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

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Entity CreateEntity(this Scene scene);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static void DestroyEntity(this Scene scene, Entity entity);

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static object[] GetEntityScriptBehaviours(this Scene scene, Entity entity);

        public static T GetScriptComponent<T>(this Scene scene, Entity entity) where T : IScriptComponent
        {
            object[] scriptBehaviours = GetEntityScriptBehaviours(scene, entity);

            if(scriptBehaviours == null) 
            {
                return default;
            }

            foreach (object behaviour in scriptBehaviours)
            {
                if (behaviour is T derivedType)
                {
                    return derivedType;
                }
            }

            return default;
        }

        public static T GetNativeComponent<T>(this Scene scene, Entity entity) where T : INativeComponent, new()
        {
            T nativeComponent = new T();
            nativeComponent.Handle = NativeComponentProvider<T>.GetNativeHandle(scene, entity);
            return nativeComponent;
        }

    }
}
