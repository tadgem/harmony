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

    /// <summary>
    /// Any module is automatically added to the engine when loading an assembly
    /// </summary>
    public class Module
    {
        public interface IOnInit
        {
            void Init();
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

    public static class NativeComponentProvider<T> where T : INativeComponent, new()
    {
        private static T _template = new T();

        public static IntPtr GetNativeHandle(Scene scene, Entity entity)
        {
            return _template.GetNativeHandle(scene, entity);
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
