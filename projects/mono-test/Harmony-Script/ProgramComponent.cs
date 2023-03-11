namespace Harmony
{
    public interface ProgramComponent
    {
        void Init();
        void Update();
        void Render();
        void Cleanup();
    }
}
