
namespace Harmony
{
    public interface System
    {
        void Init(Scene scene);
        void Update(Scene scene);
        void Render(Scene scene);
        void Cleanup(Scene scene);
    }
}
