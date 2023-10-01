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

    public class Behaviour
    {
        public Entity Self { get; set; }

        public virtual void Init() { }
        public virtual void Update() { }
        public virtual void Cleanup() { }
    }
}
