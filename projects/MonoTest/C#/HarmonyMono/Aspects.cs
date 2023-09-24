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
