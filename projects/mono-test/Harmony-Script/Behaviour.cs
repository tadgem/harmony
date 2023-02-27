
namespace Harmony
{
    public interface Behaviour
    {
        public Entity ThisEntity { get; }

        void Init();
        void Update();
        void Render();
        void Cleanup();
    }
}
