using Harmony;
using Harmony.Math;

namespace GameTest
{
    public class TestBehaviour : Behaviour
    {
        private Scene _scene;
        private NativeTransformComponent _transform;
        public float Speed = 3.0f;

        public override void Init()
        {
            _scene = SceneMethods.GetActiveScene();
            _transform = _scene.GetEntityTransform(Self);
            Vector3 v = _transform.GetTransformPosition();
            Log.Info($"I am entity : {Self} : Pos : {v}");
        }
        public override void Update()
        {
            float delta = (float) Time.GetFrameTime();
            Vector3 v = _transform.GetTransformEuler();
            v.x += delta * Speed;
            _transform.SetTransformEuler(v);
        }

    }
}
