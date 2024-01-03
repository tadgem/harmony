using System;

namespace Harmony
{
    public class ProgramComponent
    {
        public interface IOnInit
        {
            void Init();
        }
        public interface IOnUpdate
        {
            void Update();
        }
        public interface IOnCleanup
        {
            void Cleanup();
        }

    }

    public interface IScriptComponent
    {

    }

    public interface INativeComponent  {

        IntPtr Handle { get; set; }
        // Pretend this is static, its not nice but we need it for now
        IntPtr GetNativeHandle(Scene scene, Entity entity);
    }

    public class NativeComponentProvider<T> where T : INativeComponent, new()
    {
        public static IntPtr GetNativeHandle(Scene scene, Entity entity)
        {
            T temp = new T();

            return temp.GetNativeHandle(scene, entity);
        }
    }
    

    public class Behaviour : IScriptComponent
    {
        public readonly Entity Self;

        public virtual void Init() { }
        public virtual void Update() { }
        public virtual void Cleanup() { }
    }
}
