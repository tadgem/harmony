using Harmony;

namespace GameTest
{
    public class TestBehaviour : Behaviour
    {
        public override void Init()
        {
            Log.Info($"I am entity : {Self}");
        }
        public override void Update()
        {

        }

    }
}
