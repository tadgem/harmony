

using Harmony;

namespace GameTest
{
    public class TestModule : Module.IOnInit
    {
        public void Init()
        {
            Log.Info("Hello from C# Module");
        }
    }
}
