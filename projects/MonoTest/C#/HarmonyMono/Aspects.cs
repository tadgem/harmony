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

    public interface IBehaviour { };

    public class Behaviour : IBehaviour
    {
        public Entity Self { get; private set; }

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
}
